/*IOMultiplexing.c
* Author: BSS939
* Update: 2019-12-27T23:36:00+08@ShenZhen
* Design: Multiplexing
*/

#ifndef Kernel_h
#define Kernel_h

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <poll.h>

#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef unsigned Mode;
static const struct {
	const Mode In;
	const Mode Out;
	const Mode Append;
	const Mode Block;
	const Mode Nonblock;
} EType = {
	(1U << 0), (1U << 1), (1U << 2), (1U << 3), (1U << 4)
};

int Check(bool failed, const char *file, const long line, const char *function, const char *message);

////////////////////////////////////////////////////////////////////////////////

#define _BUFFER_SIZE  (1024 * 8)
#define _POLLFD_MAX   (1000)
#define _UPDATE_MAX   (1000)
#define _POLL_TIMEOUT (-1)

typedef long(*IOHook)(int fd);
typedef void(*UpdateHook)(void);
typedef struct pollfd PollFD;

typedef struct {
	int(*AddIOHook)(int fd, const IOHook ioHook, const Mode mode);
	int(*DelIOHook)(int fd, const IOHook ioHook, const Mode mode);
	void(*Run)();
	void(*Update)();
} Kernel;

Kernel GetKernel();

#endif // Kernel_h

////////////////////////////////////////////////////////////////////////////////

#ifndef Kernel_c
#define Kernel_c

int Check(bool failed, const char *file, const long line, const char *function, const int error, const char *message) {
	if (failed) {
		fprintf(stderr, "\33[33m""%s##%ld##%s##[%d]%s\n""\33[0m", file, line, function, error, message);
		if (!(0 == errno && 0 == error)) {
			fprintf(stderr, "[%d]%s\n", errno, strerror(errno));
			exit(errno);
		}
	}
	errno = 0;
	return 0;
}

static int addIOHook(int fd, const IOHook ioHook, const Mode mode);
static int delIOHook(int fd, const IOHook ioHook, const Mode mode);
static void run();
static void update();

Kernel GetKernel() {
	static Kernel kernel = {
		.AddIOHook = addIOHook,
		.DelIOHook = delIOHook,
		.Run = run,
		.Update = update
	};
	return kernel;
}

static PollFD _fds[_POLLFD_MAX];
static IOHook _ios[_POLLFD_MAX];
static long _fds_num;
static UpdateHook _updates[_UPDATE_MAX];
static long _updates_num;

static int addIOHook(int fd, const IOHook ioHook, const Mode mode) {
	int ret = 0;

	int ctrl = fcntl(fd, F_GETFL);
	if (0 != (mode & EType.Nonblock)) {
		ctrl |= O_NONBLOCK;
	}
	else if (0 != (mode & EType.Block)) {
		ctrl &= ~O_NONBLOCK;
	}
	fcntl(fd, F_SETFL, ctrl);
	// fprintf(stderr, "%s##ctrl = %d\n", __FUNCTION__, ctrl);

	if (ioHook != NULL) {
		short inout = 0;
		if (0 != (mode & EType.In)) {
			inout |= POLLIN;
		}
		if (0 != (mode & EType.Out)) {
			inout |= POLLOUT;
		}
		// fprintf(stderr, "%s##inout = %d\n", __FUNCTION__, inout);

		long idx = _fds_num;
		long i = _fds_num - 1;
		for (; 0 <= i; i -= 1) {
			if (0 > _fds[i].fd) {
				idx = i;
			}
			else if (fd == _fds[i].fd && 0 != (_fds[i].events & inout)) {
				const char *message = "(fd == _fds[i].fd && 0 != (_fds[i].events & inout))";
				errno = -1, Check(true, __FILE__, __LINE__, __FUNCTION__, message);
				i = _fds_num;
				break;
			}
		}

		const char *message = "(idx == _fds_num && _fds_num >= _POLLFD_MAX)";
		errno = -1, Check(idx == _fds_num && _fds_num >= _POLLFD_MAX, __FILE__, __LINE__, __FUNCTION__, message);
		if (i != _fds_num && _fds_num < _POLLFD_MAX) {
			// fprintf(stderr, "%s##idx = %ld\n", __FUNCTION__, idx);
			_ios[idx] = ioHook;
			_fds[idx].events = inout;
			_fds[idx].fd = fd;
			_fds_num += 1;
			ret += 1;
		}
	}
	return ret;
}

static int delIOHook(int fd, const IOHook ioHook, const Mode mode) {
	int ret = 0;

	short inout = 0;
	if (0 != (mode & EType.In)) {
		inout |= POLLIN;
	}
	if (0 != (mode & EType.Out)) {
		inout |= POLLOUT;
	}
	// fprintf(stderr, "%s##inout = %d\n", __FUNCTION__, inout);

	for (long i = _fds_num - 1; 0 <= i; i -= 1) {
		if (fd == _fds[i].fd) {
			if (ioHook == NULL) {
				_fds[i].fd = -1;
				ret += 1;
			}
			else if (ioHook == _ios[i]) {
				_fds[i].events &= (short)~inout;
				if (0 == _fds[i].events) {
					// fprintf(stderr, "%s##%s\n", __FUNCTION__, "0 == _fds[i].events");
					_fds[i].fd = -1;
				}
				ret += 1;
				break;
			}
		}
	}

	while (0 < _fds_num && _fds[_fds_num - 1].fd < 0) {
		_fds_num -= 1;
	}
	return ret;
}

static void run() {
	while (true) {
		int num = poll(_fds, (unsigned long)_fds_num, (int)_POLL_TIMEOUT);
		Check(num < 0, __FILE__, __LINE__, __FUNCTION__, "poll");

		// fprintf(stderr, "%s##num = %d, fds_num = %ld\n", __FUNCTION__, num, _fds_num);
		// usleep(500 * 1000);

		if (num == 0) {
			// fprintf(stderr, "%s##%s\n", __FUNCTION__, "poll timeout...");
			continue;
		}
		for (long i = 0; 0 < num && i < _fds_num; ++i) {
			if (_fds[i].fd < 0 || _fds[i].revents == 0) {
				continue;
			}
			num -= 1;

			if (0 != (_fds[i].revents & POLLIN)) {
				// fprintf(stderr, "%s##%s\n", __FUNCTION__, "POLLIN");
				(*_ios[i])(_fds[i].fd);
			}
			else if (0 != (_fds[i].revents & POLLOUT)) {
				// fprintf(stderr, "%s##%s\n", __FUNCTION__, "POLLOUT");
				(*_ios[i])(_fds[i].fd);
			}
			else if (0 != (_fds[i].revents & POLLRDHUP)) {
				// "Stream socket peer closed connection, or shut down writing half of connection."
				// fprintf(stderr, "%s##%s\n", __FUNCTION__, "POLLRDHUP");
				exit(POLLRDHUP);
			}
			else {
				// bool cond1 = (0 != (_fds[i].revents & POLLPRI));
				// bool cond2 = (0 != (_fds[i].revents & POLLERR));
				// bool cond3 = (0 != (_fds[i].revents & POLLHUP));
				// bool cond4 = (0 != (_fds[i].revents & POLLNVAL));
				// fprintf(stderr, "%s##_fds[i].revents = %d\n", __FUNCTION__, _fds[i].revents);
				exit(_fds[i].revents);
			}
		}
	}
}

static void update() {
	_updates_num = 0;
	_updates[_updates_num] = NULL;
	exit(EXIT_FAILURE);
}

#endif // Kernel_c

////////////////////////////////////////////////////////////////////////////////

#ifndef Main
#define Main

static char buffer[_BUFFER_SIZE];
static ssize_t readLen = 0;
static ssize_t writeLen = 0;

long writeFD(int fd);

long readFD(int fd) {
	// fprintf(stderr, "%s\n", __FUNCTION__);
	readLen = read(fd, buffer, (size_t)sizeof(buffer));
	buffer[readLen] = '\0';
	Check(readLen <= 0, __FILE__, __LINE__, __FUNCTION__, "read");

	fprintf(stderr,
		">>----------------------------------->>\n"
		"readLen = %ld\n"
		"%s"
		">>----------------------------------->>\n"
		, readLen, buffer
	);

	for (int i = 0; i < readLen; ++i) {
		buffer[i] = (char)toupper(buffer[i]);
	}

	GetKernel().AddIOHook(STDOUT_FILENO, writeFD, EType.Out);
	return readLen;
}

long writeFD(int fd) {
	// fprintf(stderr, "%s\n", __FUNCTION__);
	writeLen = write(fd, buffer, (size_t)readLen);
	Check(writeLen != readLen, __FILE__, __LINE__, __FUNCTION__, "write");

	fprintf(stderr,
		"<<-----------------------------------<<\n"
		"writeLen = %ld\n"
		"%s"
		"<<-----------------------------------<<\n"
		, writeLen, buffer
	);

	GetKernel().DelIOHook(STDOUT_FILENO, writeFD, EType.Out);
	return writeLen;
}

int main(int argc, char *argv[]) {
	GetKernel().AddIOHook(STDIN_FILENO, readFD, EType.In);
	GetKernel().Run();

	return 0;
}

#endif // Main
