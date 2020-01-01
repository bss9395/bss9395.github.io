/*Kernel.hpp
* Author: BSS9395
* Update: 2019-12-30T15:47:00+08@ShenZhen
* Design: Multiplexing_with_Turning
*/

#if 0 // errno
#include <errno-base.h>
#define	EPERM       1  /* Operation not permitted */
#define	ENOENT      2  /* No such file or directory */
#define	ESRCH       3  /* No such process */
#define	EINTR       4  /* Interrupted system call */
#define	EIO         5  /* I/O error */
#define	ENXIO       6  /* No such device or address */
#define	E2BIG       7  /* Argument list too long */
#define ENOEXEC     8 /* Exec format error */
#define EBADF       9 /* Bad file number */
#define ECHILD     10 /* No child processes */
#define EAGAIN     11 /* Try again */
#define ENOMEM     12 /* Out of memory */
#define EACCES     13 /* Permission denied */
#define EFAULT     14 /* Bad address */
#define ENOTBLK    15 /* Block device required */
#define EBUSY      16 /* Device or resource busy */
#define EEXIST     17 /* File exists */
#define EXDEV      18 /* Cross-device link */
#define ENODEV     19 /* No such device */
#define ENOTDIR    20 /* Not a directory */
#define EISDIR     21 /* Is a directory */
#define EINVAL     22 /* Invalid argument */
#define ENFILE     23 /* File table overflow */
#define EMFILE     24 /* Too many open files */
#define ENOTTY     25 /* Not a typewriter */
#define ETXTBSY    26 /* Text file busy */
#define EFBIG      27 /* File too large */
#define ENOSPC     28 /* No space left on device */
#define ESPIPE     29 /* Illegal seek */
#define EROFS      30 /* Read-only file system */
#define EMLINK     31 /* Too many links */
#define EPIPE      32 /* Broken pipe */
#define EDOM       33 /* Math argument out of domain of func */
#define ERANGE     34 /* Math result not representable */
#endif // 

#if 0 // PROCESS STATE CODES
Here are the different values that the s, stat and state output specifiers(header "STAT" or "S") will display to describe the state of a process :
D    uninterruptible sleep(usually IO)
R    running or runnable(on run queue)
S    interruptible sleep(waiting for an event to complete)
T    stopped by job control signal
t    stopped by debugger during the tracing
W    paging(not valid since the 2.6.xx kernel)
X    dead(should never be seen)
Z    defunct("zombie") process, terminated but not reaped by its parent

For BSD formats and when the stat keyword is used, additional characters may be displayed :
< high - priority(not nice to other users)
	N    low - priority(nice to other users)
	L    has pages locked into memory(for real - time and custom IO)
	s    is a session leader
	l    is multi - threaded(using CLONE_THREAD, like NPTL pthreads do)
	+ is in the foreground process group
#endif

#ifndef Kernel_hpp
#define Kernel_hpp

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <poll.h>

#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
	using ::memset;
using ::toupper;
using ::clock;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <memory>
#include <exception>
#include <functional>
#include <thread>
#include <chrono>

using std::boolalpha;
using std::cin;
using std::cout;
using std::clog;
using std::cerr;
using std::endl;
using std::flush;
using std::fstream;
using std::stringstream;
using std::string;
using std::vector;
using std::queue;
using std::map;
using std::exception;
using std::function;
using std::thread;
namespace chrono = std::chrono;
namespace this_thread = std::this_thread;

#include "Config.hpp"


#ifndef CLOCKS_PER_SEC
#error "undefined CLOCKS_PER_SEC"
#endif 
#define CLOCKS_PER_SECOND      (CLOCKS_PER_SEC)
#define CLOCKS_PER_MILLISECOND (CLOCKS_PER_SEC / 1000)

class Kernel {
public:
	typedef struct pollfd PollFD;

	struct IOHook {
		// typedef long(*IOFunc) (int fd);
		typedef function<long(int)> IOFunc;

		IOHook()
			: _ioFunc(nullptr) {
			// cerr << __FUNCTION__ << endl;
		}

		IOHook(IOFunc ioFunc)
			: _ioFunc(ioFunc) {
			// cerr << __FUNCTION__ << "##" << (nullptr == _ioFunc) << endl;
		}

		virtual long readFD(int fd) {
			// cerr << __FUNCTION__ << endl;
			Exception(_ioFunc == nullptr, __FILE__, __LINE__, __FUNCTION__, EType::Incompleted, "Unimplement readFD.").check();
			return _ioFunc(fd);
		}
		virtual long writeFD(int fd) {
			// cerr << __FUNCTION__ << endl;
			Exception(_ioFunc == nullptr, __FILE__, __LINE__, __FUNCTION__, EType::Incompleted, "Unimplement writeFD.").check();
			return _ioFunc(fd);
		}

		IOFunc _ioFunc;
	};

	struct UpdateHook {
		typedef Return(*UpdateFunc)(Param param);

		UpdateHook()
			: _updateFunc(nullptr) {
			// cerr << __FUNCTION__ << endl;
		}

		UpdateHook(UpdateFunc updateFunc)
			: _updateFunc(updateFunc) {
			// cerr << __FUNCTION__ << endl;
		}

		virtual Return update(Param param = Param()) {
			// cerr << __FUNCTION__ << endl;
			Exception(_updateFunc == nullptr, __FILE__, __LINE__, __FUNCTION__, EType::Incompleted, "Unimplement update.").check();
			return _updateFunc(param);
		}

		UpdateFunc _updateFunc;
	};

public:
	Kernel() {
		_fds_num = 0;
		_updates_num = 0;
		_tids_num = 0;

		cerr << __FUNCTION__ << endl;
	}

	Kernel(const Kernel &kernel) = delete;
	Kernel &operator=(const Kernel &kernel) = delete;

	virtual ~Kernel() {
		cerr << __FUNCTION__ << endl;
	}

	static Kernel &GetKernel() {
		static Kernel kernel;
		return kernel;
	}

	static int CtrlFD(int fd, const Mode &mode = EType::Nonblock) {
		return GetKernel().ctrlFD(fd, mode);
	}

	static int AddIOHook(int fd, IOHook *ioHook = nullptr, const Mode &mode = EType::In) {
		return GetKernel().addIOHook(fd, ioHook, mode);
	}

	static int DelIOHook(int fd, IOHook *ioHook = nullptr, const Mode &mode = EType::Out) {
		return GetKernel().delIOHook(fd, ioHook, mode);
	}

	static int AddUpdateHook(UpdateHook *hook) {
		return GetKernel().addUpdateHook(hook);
	}

	static int DelUpdateHook(UpdateHook *hook) {
		return GetKernel().delUpdateHook(hook);
	}

	static Return Run(Param param = Param()) {
		Kernel &kernel = GetKernel();
		kernel.run(param);
		kernel.mainThreading(param);
		return Return();
	}

	static Return Update(Param param = Param()) {
		Kernel &kernel = GetKernel();
		kernel.update(param);
		kernel.mainThreading(param);
		return Return();
	}

	template<typename Func, typename ...Args>
	static Return MultiThreading(Func func, Args ...args) {
		Kernel &kernel = GetKernel();
		kernel.multiThreading(func, args...);
		kernel.mainThreading(Param());
		return Return();
	}

public:
	int ctrlFD(int fd, const Mode &mode) {
		int ret = 0;
		int getfl = fcntl(fd, F_GETFL);
		int setfl = getfl;

		if (0 != (mode & EType::Nonblock)) {
			setfl |= O_NONBLOCK;
		}
		else if (0 != (mode & EType::Block)) {
			setfl &= ~O_NONBLOCK;
		}

		if (setfl != getfl) {
			fcntl(fd, F_SETFL, setfl);
			ret += 1;
		}
		cerr << __FUNCTION__ << "##" << "ctrl = " << setfl << endl;
		return ret;
	}

	int addIOHook(int fd, IOHook *ioHook, const Mode &mode) {
		Check(ioHook == nullptr, __FILE__, __LINE__, __FUNCTION__, errno, "(ioHook == nullptr)");

		int ret = 0;
		short inout = 0;
		if (0 != (mode & EType::In)) {
			inout |= POLLIN;
		}
		if (0 != (mode & EType::Out)) {
			inout |= POLLOUT;
		}
		cerr << __FUNCTION__ << "##" << "inout = " << inout << endl;

		long idx = _fds_num;
		for (long i = _fds_num - 1; 0 <= i; i -= 1) {
			if (0 > _fds[i].fd) {
				idx = i;
			}
			else if (fd == _fds[i].fd && 0 != (_fds[i].events & inout)) {
				string report = "(fd == _fds[i].fd && 0 != (_fds[i].events & inout))";
				Exception(true, __FILE__, __LINE__, __FUNCTION__, EType::Error, report).check();
				break;
			}
		}

		Exception(idx >= Config::_POLLFD_MAX, __FILE__, __LINE__, __FUNCTION__, EType::Fatal, "(idx >= Config::_POLLFD_MAX)").check();
		if (idx < Config::_POLLFD_MAX) {
			cerr << __FUNCTION__ << "##" << "idx = " << idx << endl;
			_ios[idx] = ioHook;
			_fds[idx].events = inout;
			_fds[idx].fd = fd;
			if (idx == _fds_num) {
				_fds_num += 1;
			}
			ret += 1;
		}
		return ret;
	}

	int delIOHook(int fd, IOHook *ioHook, const Mode &mode) {
		int ret = 0;

		short inout = 0;
		if (0 != (mode & EType::In)) {
			inout |= POLLIN;
		}
		if (0 != (mode & EType::Out)) {
			inout |= POLLOUT;
		}
		cerr << __FUNCTION__ << "##" << "inout = " << inout << endl;

		for (long i = _fds_num - 1; 0 <= i; i -= 1) {
			if (fd == _fds[i].fd) {
				if (ioHook == nullptr) {
					_fds[i].fd = -1;
					ret += 1;
				}
				else if (ioHook == _ios[i]) {
					_fds[i].events &= (short)~inout;
					if (0 == _fds[i].events) {
						cerr << __FUNCTION__ << "##" << "ioHook = _ios[" << i << "]" << endl;
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

	int addUpdateHook(UpdateHook *hook) {
		int ret = 0;
		long idx = _updates_num;
		for (long i = 0; i < _updates_num; i += 1) {
			if (_updates[i] == nullptr) {
				idx = i;
				break;
			}
		}

		string report = "(idx >= Config::_UPDATE_MAX)";
		Exception(idx >= Config::_UPDATE_MAX, __FILE__, __LINE__, __FUNCTION__, EType::Fatal, report).check();
		if (idx < Config::_UPDATE_MAX) {
			cerr << __FUNCTION__ << "##" << idx << endl;
			_updates[idx] = hook;
			if (idx == _updates_num) {
				_updates_num += 1;
			}
			ret += 1;
		}
		return ret;
	}

	int delUpdateHook(UpdateHook *hook) {
		int ret = 0;
		for (long i = _updates_num - 1; 0 <= i; i -= 1) {
			if (_updates[i] == hook) {
				_updates[i] = nullptr;
				ret += 1;
			}
		}

		while (0 < _updates_num && _updates[_updates_num - 1] == nullptr) {
			_updates_num -= 1;
		}
		return ret;
	}

	Return run(Param param = Param()) {
		cerr << __FUNCTION__ << endl;
		try {
			while (true) {
				int num = poll(_fds, _fds_num, Config::_POLL_TIMEOUT);
				Check(num < 0, __FILE__, __LINE__, __FUNCTION__, errno, "poll");
				// cerr << __FUNCTION__ << "##" << "num = " << num << "##" << "_fds_num = " << _fds_num << endl;
				// usleep(500 * 1000);

				if (num == 0) {
					cerr << __FUNCTION__ << "##" << "poll timeout." << endl;
					Exception(Config::_POLL_TIMEOUT > 0, __FILE__, __LINE__, __FUNCTION__, EType::Incompleted, "poll timeout.").check();
				}

				for (long i = 0; 0 < num && i < _fds_num; i += 1) {
					if (_fds[i].fd < 0 || 0 == _fds[i].revents) {
						continue;
					}
					num -= 1;

					if (0 != (_fds[i].revents & POLLIN)) {
						cerr << __FUNCTION__ << "##" << "POLLIN" << endl;
						_ios[i]->readFD(_fds[i].fd);
					}
					else if (0 != (_fds[i].revents & POLLOUT)) {
						cerr << __FUNCTION__ << "##" << "POLLOUT" << endl;
						_ios[i]->writeFD(_fds[i].fd);
					}
					else if (0 != (_fds[i].revents & POLLRDHUP)) {
						// "Stream socket peer closed connection, or shut down writing half of connection."
						cerr << __FUNCTION__ << "##" << "POLLRDHUP" << endl;
						throw POLLRDHUP;
					}
					else {
						// bool cond1 = (0 != (_fds[i].revents & POLLPRI));
						// bool cond2 = (0 != (_fds[i].revents & POLLERR));
						// bool cond3 = (0 != (_fds[i].revents & POLLHUP));
						// bool cond4 = (0 != (_fds[i].revents & POLLNVAL));
						cerr << __FUNCTION__ << "##" << "_fds[i].revents = " << _fds[i].revents << endl;
						throw _fds[i].revents;
					}
				}
			}
		}
		catch (...) {
			// bool cond1 = (errno == EFAULT); // The array given as argument was not contained in the calling program's address space.
			// bool cond2 = (errno == EINTR);  // A signal occurred before any requested event.
			// bool cond3 = (errno == EINVAL); // The nfds value exceeds the RLIMIT_NOFILE value.
			// bool cond4 = (errno == ENOMEM); // There was no space to allocate file descriptor tables.
			cerr << __FUNCTION__ << "##" << "errno = " << errno << endl;
			throw;
		}
		return Return();
	}

	Return update(Param param = Param()) {
		cerr << __FUNCTION__ << endl;
		try {
			while (true) {
				sleep(1);
				for (long i = 0; i < _updates_num; i += 1) {
					_updates[i]->update(param);
				}
			}
		}
		catch (...) {
			cerr << __FUNCTION__ << "##" << "unkown err." << endl;
		}
		return Return();
	}

	/*PLEASE
	* lambda is NOT lamb.
	*/
	template<typename Func, typename ...Args>
	Return multiThreading(Func func, Args ...args) {
		cerr << __FUNCTION__ << "##" << "this_thread::getid() = " << this_thread::get_id() << endl;

		static auto lamb = [this](Func func, Args ...args) {
			cerr << __FUNCTION__ << "##" << "this_thread::getid() = " << this_thread::get_id() << endl;
			func(args...);
			this->_tids_state[this->_tids_num] = EType::Exit;
		};

		_tids_state[_tids_num] = EType::Initialize;
		_tids[_tids_num] = thread(func, args...);
		_tids[_tids_num].detach();
		_tids_num += 1;

		mainThreading();
		cerr << __FUNCTION__ << "##" << "Done" << endl;
		return Return();
	}

	Return mainThreading(Param param = Param()) {
		cerr << __FUNCTION__ << endl;
		static long endless = -1;
		if (endless != -1) {
			return Return();
		}
		cerr << __FUNCTION__ << "##" << boolalpha << endless << "##" << "_tids_num = " << _tids_num << endl;

		Kernel &kernel = GetKernel();
		static clock_t beginning = 0;
		static clock_t preceding = 0;
		static clock_t momenting = 0;
		do {
			momenting = clock();
			kernel._delta_milliseconds = (double)(momenting - preceding) / CLOCKS_PER_MILLISECOND;
			kernel._elapsed_seconds = (double)(momenting - beginning) / CLOCKS_PER_SECOND;
			preceding = momenting;
			cerr << "_delta_milliseconds = " << kernel._delta_milliseconds << ", _elapsed_seconds = " << kernel._elapsed_seconds << endl;

			cerr << __FUNCTION__ << "##" << "this_thread::getid() = " << this_thread::get_id() << endl;
			endless = 0;
			for (long i = 0; i < _tids_num; i += 1) {
				cerr << _tids_state[i] << endl;
				if (_tids_state[i] != EType::Exit) {
					endless += 1;
					break;
				}
			}
		} while (endless > 0);

		return Return();
	}

public:
	PollFD _fds[Config::_POLLFD_MAX];
	IOHook *_ios[Config::_POLLFD_MAX];
	long _fds_num;

	UpdateHook *_updates[Config::_UPDATE_MAX];
	long _updates_num;

	thread _tids[Config::_THREAD_MAX];
	State _tids_state[Config::_THREAD_MAX];
	long _tids_num;

	double _delta_milliseconds;
	double _elapsed_seconds;
};


#endif // Kernel_hpp
