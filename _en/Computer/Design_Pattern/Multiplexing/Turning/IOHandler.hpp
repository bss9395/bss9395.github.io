/*IOHandler.hpp
* Author: BSS9395
* Update: 2019-12-30T15:47:00+08@ShenZhen
* Design: Multiplexing
*/

#ifndef IOHandler_hpp
#define IOHandler_hpp

#include "Kernel.hpp"

class IOHandler
	: public Kernel::IOHook {
public:
	IOHandler() {
		_read_len = 0;
		_write_len = 0;

		Kernel::AddIOHook(STDIN_FILENO, this, EType::In);
		cerr << __FUNCTION__ << endl;
	}

	IOHandler(const IOHandler &handler) = delete;
	IOHandler &operator=(const IOHandler &handler) = delete;

	virtual ~IOHandler() {
		cerr << __FUNCTION__ << endl;
	}

public:
	virtual long readFD(int fd) override {
		// cerr << __FUNCTION__ << endl;
		_read_len = read(fd, _buffer, sizeof(_buffer));
		_buffer[_read_len] = '\0';
		Check(_read_len <= 0, __FILE__, __LINE__, __FUNCTION__, errno, "read");

		cerr << ">>------------------------------------>>" << endl;
		cerr << "readLen = " << _read_len << endl;
		cerr << _buffer << flush;
		cerr << ">>------------------------------------>>" << endl;

		for (long i = 0; i < _read_len; i += 1) {
			_buffer[i] = (char)toupper(_buffer[i]);
		}
		// Kernel::GetKernel().addIOHook(STDOUT_FILENO, this, EType::Out);
		writeFD(STDOUT_FILENO);
		return _read_len;
	}

	virtual long writeFD(int fd) override {
		// cerr << __FUNCTION__ << endl;
		_write_len = write(fd, _buffer, _read_len);
		Check(_write_len != _read_len, __FILE__, __LINE__, __FUNCTION__, errno, "write");

		cerr << "<<------------------------------------<<" << endl;
		cerr << "writeLen = " << _write_len << endl;
		cerr << _buffer << flush;
		cerr << "<<------------------------------------<<" << endl;
		// Kernel::GetKernel().delIOHook(STDOUT_FILENO, this, EType::Out);
		return _write_len;
	}

	char _buffer[Config::_BUFFER_SIZE];
	long _read_len;
	long _write_len;
};

#endif // IOHandler_hpp
