#include "Kernel.hpp"

class IOHandler
	: public Kernel::IOHook {
public:
	IOHandler() {
		_readLen = 0;
		_writeLen = 0;

		// Kernel::AddIOHook(STDIN_FILENO, this, EType::In | EType::Nonblock);
		cerr << __FUNCTION__ << endl;
	}

public:
	long readFD(int fd) {
		// cerr << __FUNCTION__ << endl;
		_readLen = read(fd, _buffer, sizeof(_buffer));
		_buffer[_readLen] = '\0';
		Check(_readLen <= 0, __FILE__, __LINE__, __FUNCTION__, errno, "read");

		cerr << ">>------------------------------------>>" << endl;
		cerr << "readLen = " << _readLen << endl;
		cerr << _buffer << flush;
		cerr << ">>------------------------------------>>" << endl;

		for (long i = 0; i < _readLen; i += 1) {
			_buffer[i] = (char)toupper(_buffer[i]);
		}
		// Kernel::GetKernel().addIOHook(STDOUT_FILENO, this, EType::Out);
		writeFD(STDOUT_FILENO);
		return _readLen;
	}

	long writeFD(int fd) {
		// cerr << __FUNCTION__ << endl;
		_writeLen = write(fd, _buffer, _readLen);
		Check(_writeLen != _readLen, __FILE__, __LINE__, __FUNCTION__, errno, "write");

		cerr << "<<------------------------------------<<" << endl;
		cerr << "writeLen = " << _writeLen << endl;
		cerr << _buffer << flush;
		cerr << "<<------------------------------------<<" << endl;
		// Kernel::GetKernel().delIOHook(STDOUT_FILENO, this, EType::Out);
		return _writeLen;
	}

	char _buffer[Config::_BUFFER_SIZE];
	long _readLen;
	long _writeLen;
};

////////////////////////////////////////////////////////////////////////////////

#define Main
#ifdef Main

int main(int argc, char *argv[]) {
	IOHandler io;
	Kernel::AddIOHook(STDIN_FILENO, &io, EType::In | EType::Nonblock);
	Kernel::Run();
	Kernel::Update();

	return 0;
}

#endif // Main
