/*Config.hpp
* Author: BSS9395
* Update: 2019-12-30T15:47:00+08@ShenZhen
* Design: Multiplexing_with_Turning
*/

#ifndef Config_hpp
#define Config_hpp

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
using ::memset;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <exception>
using std::cin;
using std::cout;
using std::clog;
using std::cerr;
using std::endl;
using std::flush;
using std::flush;
using std::string;
using std::ostream;
using std::fstream;
using std::stringstream;
using std::exception;

#include "Pointer.hpp"

typedef void *Return;
typedef void *Param;

typedef const char *Origin;
typedef const char *State;
typedef unsigned Mode;
namespace EType {
	static const Origin Stack = "Stack";
	static const Origin Heap = "Heap";

	static const State None = "None";
	static const State Initialize = "Initialize";
	static const State Terminate = "Terminate";
	static const State Read = "Read";
	static const State Write = "Write";
	static const State Receive = "Receive";
	static const State Send = "Send";
	static const State Connect = "Connect";
	static const State Disconnect = "Disconnect";
	static const State Listen = "Listen";
	static const State Accept = "Accept";
	static const State Join = "Join";
	static const State Detach = "Detach";
	static const State Exit = "Exit";

	static const Mode In = (1U << 0);
	static const Mode Out = (1U << 1);
	static const Mode Append = (1U << 2);
	static const Mode Block = (1U << 3);
	static const Mode Nonblock = (1U << 4);
};

namespace Config {
	static const long _BUFFER_SIZE = 1024 * 8;
	static const long _THREAD_MAX = 10;

	static const long _POLLFD_MAX = 1000;
	static const long _UPDATE_MAX = 1000;
	static const int _POLL_TIMEOUT = -1;

	// static const char *_SERVER_ADDRESS = "127.0.0.1";
	static const char *_SERVER_BIND = "0.0.0.0";
	static const int _SERVER_PORT = 9395;
	static const int _SERVER_REUSEADDR = 1;
	static const long _SERVER_BACKLOG = 1000;
	static const long _SERVER_SOCKET_MAX = 1000;
};

#endif // Config_hpp
