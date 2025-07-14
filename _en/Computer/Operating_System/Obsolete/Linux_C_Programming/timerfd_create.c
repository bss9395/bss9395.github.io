#if 0
#include <sys/timerfd.h>
int timerfd_create(int clockid, int flags);
int timerfd_settime(int fd, int flags, const struct itimerspec *new_value, struct itimerspec *old_value);
int timerfd_gettime(int fd, struct itimerspec *curr_value);
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE

#include <sys/timerfd.h>
#include <unistd.h>

#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>

int checkError(bool failed, const char *file, const long line, const char *function, const char *message) {
	if (failed) {
		fprintf(stderr, "\33[33m""%s==%ld==%s==[%d]%s""\33[0m\n", file, line, function, errno, message);
		if (errno) {
			exit(errno);
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int fd = timerfd_create(CLOCK_MONOTONIC, 0);
	checkError(fd < 0, __FILE__, __LINE__, __FUNCTION__, "CLOCK_MONOTONIC");

	struct itimerspec timeout = { {1, 0}, {1, 0} };
	int err = timerfd_settime(fd, 0, &timeout, NULL);
	checkError(err < 0, __FILE__, __LINE__, __FUNCTION__, "timerfd_settime");

	long tick = 0;
	while (true) {
		long len = read(fd, &tick, sizeof(tick));
		checkError(len != sizeof(tick), __FILE__, __LINE__, __FUNCTION__, "read");
		fprintf(stdout, "%ld\n", tick);
	}

	close(fd);
	return 0;
}

#endif // _GNU_SOURCE
