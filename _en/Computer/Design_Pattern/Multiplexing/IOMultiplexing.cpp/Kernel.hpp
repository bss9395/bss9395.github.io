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
using ::memset;
using ::toupper;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <exception>
#include <functional>
#include <thread>
#include <chrono>

using std::cin;
using std::cout;
using std::clog;
using std::cerr;
using std::endl;
using std::flush;
using std::string;
using std::fstream;
using std::stringstream;
using std::exception;
using std::function;
using std::thread;
namespace chrono = std::chrono;
namespace this_thread = std::this_thread;

#include "Config.hpp"

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
		typedef Return(*UpdateFunc)(void);

		UpdateHook()
			: _updateFunc(nullptr) {
			// cerr << __FUNCTION__ << endl;
		}

		UpdateHook(UpdateFunc updateFunc)
			: _updateFunc(updateFunc) {
			// cerr << __FUNCTION__ << endl;
		}

		virtual Return update(void) {
			// cerr << __FUNCTION__ << endl;
			Exception(_updateFunc == nullptr, __FILE__, __LINE__, __FUNCTION__, EType::Incompleted, "Unimplement update.").check();
			return _updateFunc();
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
		bool endless = false;
		do {
			endless = false;
			for (long i = 0; i < _tids_num; i += 1) {
				if (_tids_state[i] != EType::Exit) {
					endless = true;
					break;
				}
			}
		} while (endless);
		cerr << __FUNCTION__ << endl;
	}

	static Kernel &GetKernel() {
		static Kernel kernel;
		return kernel;
	}

	static int AddIOHook(int fd, IOHook *ioHook = nullptr, const Mode &mode = EType::In | EType::Nonblock) {
		return GetKernel().addIOHook(fd, ioHook, mode);
	}

	static int DelIOHook(int fd, IOHook *ioHook = nullptr, const Mode &mode = EType::Out) {
		return GetKernel().delIOHook(fd, ioHook, mode);
	}

	/*PLEASE
	* lambda is NOT lamb.
	*/
	static Return Run(void) {
		cerr << __FUNCTION__ << endl;
		static auto lamb = [](long tid) {
			GetKernel().run();
			GetKernel()._tids_state[tid] = EType::Exit;
		};

		Kernel &kernel = GetKernel();
		kernel._tids_state[kernel._tids_num] = EType::Initialize;
		kernel._tids[kernel._tids_num] = thread(lamb, kernel._tids_num);
		kernel._tids[kernel._tids_num].detach();
		kernel._tids_num += 1;
		return Return();
	}

	static Return Update(void) {
		cerr << __FUNCTION__ << endl;
		static auto lamb = [](long tid) {
			GetKernel().update();
			GetKernel()._tids_state[tid] = EType::Exit;
		};

		Kernel &kernel = GetKernel();
		kernel._tids_state[kernel._tids_num] = EType::Initialize;
		kernel._tids[kernel._tids_num] = thread(lamb, kernel._tids_num);
		kernel._tids[kernel._tids_num].detach();
		kernel._tids_num += 1;
		return Return();
	}

public:
	int addIOHook(int fd, IOHook *ioHook, const Mode &mode) {
		int ret = 0;

		int ctrl = fcntl(fd, F_GETFL);
		if (0 != (mode & EType::Nonblock)) {
			ctrl |= O_NONBLOCK;
		}
		else if (0 != (mode & EType::Block)) {
			ctrl &= ~O_NONBLOCK;
		}
		fcntl(fd, F_SETFL, ctrl);
		cerr << __FUNCTION__ << "##" << "ctrl = " << ctrl << endl;

		if (ioHook != nullptr) {
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

			string report = "(idx >= Config::_POLLFD_MAX)";
			Exception(idx >= Config::_POLLFD_MAX, __FILE__, __LINE__, __FUNCTION__, EType::Fatal, report).check();
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

	Return run(void) {
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

	Return update(void) {
		// Exception(true, __FILE__, __LINE__, __FUNCTION__, EType::Incompleted, "Unimplemented function run().").check();
		cerr << __FUNCTION__ << endl;
		fstream fs = fstream("Kernel.log", fstream::out | fstream::trunc);
		while (true) {
			 this_thread::sleep_for(chrono::seconds(2));
			 cerr << "this_thread::get_id() = " << this_thread::get_id() << endl;
			 fs << "this_thread::get_id() = " << this_thread::get_id() << endl;
		}
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
};
