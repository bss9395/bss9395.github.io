/*TCPHandler.cpp
* Author: BSS9395
* Update: 2020-01-01T18:27:00+08@ShenZhen+08
* Design: Turning
*/

#ifndef TCPHandler_hpp
#define TCPHandler_hpp

#include "Kernel.hpp"

class TCPSocket
	: public Kernel::UpdateHook {
	typedef struct sockaddr_in sockaddr_in;

public:
	TCPSocket(int socketFD, Origin origin = EType::Heap)
		: _socket_fd(socketFD), _origin(origin) {
		Kernel::CtrlFD(_socket_fd, EType::Nonblock);
		_state = EType::None;
		Kernel::AddUpdateHook(this);
		cerr << __FUNCTION__ << endl;
	}

	TCPSocket(const TCPSocket &socket) = delete;
	TCPSocket &operator=(const TCPSocket &socket) = delete;

	virtual ~TCPSocket() {
		_state = EType::Terminate;
		Kernel::DelUpdateHook(this);
		if (_socket_fd >= 0) {
			close(_socket_fd);
		}
		while (!_read_queue.empty()) {
			_read_queue.pop();
		}
		while (!_write_queue.empty()) {
			_write_queue.pop();
		}
		cerr << __FUNCTION__ << endl;
	}

public:
	virtual Return update(Param param) override {
		cerr << __FUNCTION__ << "##" << "override" << endl;
		onRead();
		//onProcess();
		//onWrite();
		return Return();
	}

	void onRead() {
		try {
			// cerr << __FUNCTION__ << "_updates_num : " << Kernel::GetKernel()._updates_num << endl;
			_state = EType::Read;
			long readLen = 0;
			while (readLen = recv(_socket_fd, _buffer, sizeof(_buffer), 0), readLen > 0) {
				_buffer[readLen] = '\0';
				Pointer<string> readData(new string());
				readData->append(_buffer, readLen);
				_read_queue.push(readData);
				_state = EType::Receive;
			}
			if (_state == EType::Receive) {
				cerr << ">>------------------------------------>>" << endl;
				cerr << "readLen = " << readLen << endl;
				cerr << represent(_buffer) << endl;
				cerr << ">>------------------------------------>>" << endl;
			}

			bool cond1 = (readLen < 0 && errno == EAGAIN);
			bool cond2 = (readLen < 0 && errno == 0);
			if (cond1 || cond2) {
				errno = 0;
				return;
			}
			Check(readLen < 0, __FILE__, __LINE__, __FUNCTION__, errno, "recv");
		}
		catch (int err) {
			cerr << __FUNCTION__ << "##" << err << endl;
			if (_origin == EType::Heap) {
				delete this;
			}
		}
	}

	void onProcess() {
		while (!_read_queue.empty()) {
			Pointer<string> data = _read_queue.front();
			_read_queue.pop();

			for (long i = 0; i < (long)data->length(); i += 1) {
				(*data)[i] = (char)toupper((*data)[i]);
			}

			_write_queue.push(data);
		}
	}

	void onWrite() {
		try {
			long writeLen = 0;
			while (!_write_queue.empty()) {
				Pointer<string> data = _write_queue.front();
				writeLen = send(_socket_fd, data->c_str(), data->length(), MSG_DONTWAIT);
				Check(writeLen <= 0, __FILE__, __LINE__, __FUNCTION__, errno, "send");
				_write_queue.pop();

				cerr << ">>------------------------------------>>" << endl;
				cerr << represent(*data) << endl;
				cerr << ">>------------------------------------>>" << endl;

				_state = EType::Send;
			}
		}
		catch (int err) {
			cerr << __FUNCTION__ << "##" << err << endl;
		}
	}

public:
	Pointer<char> represent(const string &data) {
		char *buf = new char[data.size() * 3 + 1];
		Pointer<char> ptr(buf, data.size() * 3 + 1);

		for (long i = 0; i < (long)data.size(); i += 1) {
			buf += snprintf(buf, 3 + 1, "%02X ", (unsigned)data[i]);
		}
		buf[0] = '\0';
		return ptr;
	}

public:
	int _socket_fd;
	Origin _origin;
	State _state;
	char _buffer[Config::_BUFFER_SIZE];
	queue<Pointer<string>> _read_queue;
	queue<Pointer<string>> _write_queue;
};

////////////////////////////////////////////////////////////////////////////////

class TCPServer
	: public Kernel::UpdateHook {
	typedef struct sockaddr_in sockaddr_in;
public:
	TCPServer() {
		try {
			_server_addr.sin_family = AF_INET;
			_server_addr.sin_addr.s_addr = inet_addr(Config::_SERVER_BIND);
			_server_addr.sin_port = htons(Config::_SERVER_PORT);

			_server_fd = socket(AF_INET, SOCK_STREAM, 0);
			Check(_server_fd < 0, __FILE__, __LINE__, __FUNCTION__, errno, "socket");

			Kernel::CtrlFD(_server_fd, EType::Nonblock);
			setsockopt(_server_fd, SOL_SOCKET, SO_REUSEADDR, &Config::_SERVER_REUSEADDR, sizeof(Config::_SERVER_REUSEADDR));

			_state = EType::None;
			Kernel::AddUpdateHook(this);
		}
		catch (int err) {
			cerr << __FUNCTION__ << "##" << "err = " << err << endl;
		}
		cerr << __FUNCTION__ << endl;
	}

	TCPServer(const TCPServer &server) = delete;
	TCPServer &operator=(const TCPServer &server) = delete;

	virtual ~TCPServer() {
		if (0 <= _server_fd) {
			close(_server_fd);
		}
		_state = EType::Terminate;
		cerr << __FUNCTION__ << endl;
	}

public:
	virtual Return update(Param param) override {
		if (_state == EType::None) {
			static long count = 0;
			count += 1;
			cerr << __FUNCTION__ << "##" << "get_id() = " << this_thread::get_id() << "##" << "count = " << count << endl;
			onInitialize();
		}
		else {
			onAccept();
		}

		return Return();
	}

	void onInitialize() {
		try {
			int err = bind(_server_fd, (struct sockaddr *)&_server_addr, sizeof(_server_addr));
			Check(err < 0, __FILE__, __LINE__, __FUNCTION__, errno, "bind");

			err = listen(_server_fd, Config::_SERVER_BACKLOG);
			Check(err < 0, __FILE__, __LINE__, __FUNCTION__, errno, "listen");

			Kernel::CtrlFD(_server_fd, EType::Nonblock);
			_state = EType::Initialize;
		}
		catch (int err) {
			cerr << __FUNCTION__ << "##" << "err = " << err << endl;
		}
		cerr << __FUNCTION__ << endl;
	}

	void onAccept() {
		try {
			_state = EType::Listen;
			int clientFD = accept(_server_fd, (struct sockaddr *)&_socket_addr, &_socket_len);
			if (clientFD < 0 && errno == EAGAIN) {
				errno = 0;
				return;
			}
			Check(clientFD < 0, __FILE__, __LINE__, __FUNCTION__, errno, "accept");
			if (clientFD >= 0) {
				new TCPSocket(clientFD, EType::Heap);
				cerr << __FUNCTION__ << endl;
				_state = EType::Accept;
			}
		}
		catch (int err) {
			cerr << __FUNCTION__ << "##" << "err = " << err << endl;
		}
	}

public:
	State _state;
	int _server_fd;
	sockaddr_in _server_addr;
	// socklen_t _server_len;
	sockaddr_in _socket_addr;
	socklen_t _socket_len;
};

#endif // TCPHandler_hpp
