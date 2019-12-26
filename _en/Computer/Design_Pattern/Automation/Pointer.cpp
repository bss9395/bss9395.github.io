/*Pointer.cpp
* Author: BSS9395
* Update: 2019-12-27T04:07:00+08@ShenZhen
* Design: Automation
*/

#ifndef Pointer_hpp
#define Pointer_hpp

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using ::fprintf;
using ::free;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <typeinfo>
using std::cout;
using std::cerr;
using std::ends;
using std::endl;
using std::string;
using std::fstream;
using std::stringstream;
using std::exception;

////////////////////////////////////////////////////////////////////////////////

typedef const char *Anomaly;
namespace EType {
	static const Anomaly Info = "Info";
	static const Anomaly Error = "Error";
	static const Anomaly Fatal = "Fatal";
};

////////////////////////////////////////////////////////////////////////////////

void Check(bool failed, const string &file, const long line, const string &function, const string &message);
void Freed(const long num, ...);

template<typename T>                 void Deleted(T *pointer);
template<typename T, typename ...Ts> void Deleted(T *pointer, Ts *...pointers);

template<typename Msg = string, typename Sln = string> class Exception;

template<typename ...>               class Pointer;
template<>                           class Pointer<char>;
template<typename T>                 class Pointer<T>;
template<typename T, typename ...Ts> class Pointer<T, Ts...>;
template<typename T>                 decltype(auto) GetPointer(T *pointer, long length = 1);
template<typename T, typename ...Ts> decltype(auto) GetPointer(T *pointer, Ts *...pointers);

template<typename ...>               class Assembly;
template<typename T>                 class Assembly<T>;
template<typename T, typename ...Ts> class Assembly<T, Ts...>;

////////////////////////////////////////////////////////////////////////////////

template<typename T>
void Deleted(T *pointer) {
	// cout << __FUNCTION__ << endl;
	delete pointer;
}

template<typename T, typename ...Ts>
void Deleted(T *pointer, Ts*...pointers) {
	Deleted(pointer);
	Deleted(pointers...);
}

template<typename Msg, typename Sln>
class Exception
	: public exception {
public:
	typedef Msg MsgType;
	typedef Sln SlnType;

public:
	Exception(bool failed, const string file, const long line, const string function, const Msg message = Msg(), const Anomaly anomaly = EType::Info, const Sln solution = Sln())
		: _failed(failed), _file(file), _line(line), _function(function), _errorID(errno), _anomaly(anomaly), _message(message), _solution(solution) {
		errno = 0;
		// cerr << __FUNCTION__ << endl;
	}

	Exception(const Exception &exception) {
		_failed = exception._failed;
		_file = exception._file;
		_line = exception._line;
		_function = exception._function;
		_errorID = exception._errorID;
		_anomaly = exception._anomaly;
		_message = exception._message;
		_solution = exception._solution;
		// cerr << __FUNCTION__ << endl;
	}

	Exception &operator=(const Exception &exception) {
		if (this != &exception) {
			this->~Exception();
			_failed = exception._failed;
			_file = exception._file;
			_line = exception._line;
			_function = exception._function;
			_errorID = exception._errorID;
			_anomaly = exception._anomaly;
			_message = exception._message;
			_solution = exception._solution;
		}
		// cerr << __FUNCTION__ << endl;
		return *this;
	}

	virtual ~Exception() {
		// cerr << __FUNCTION__ << endl;
	}

public:
	virtual int check() {
		if (_failed) {
			cerr << what() << endl;
			if (!(_errorID == 0 || _anomaly == EType::Info)) {
				throw *this;
			}
		}
		return _errorID;
	}

	virtual string what() {
		stringstream ss;
		ss << "\33[33m";
		ss << _file << "##" << _line << "##" << _function;
		if (_errorID) {
			ss << "##[" << _errorID << "]" << strerror(_errorID) << endl;
		}
		ss << "##[" << _anomaly << "]" << _message;
		ss << "\33[0m" << ends;
		return ss.str();
	}

	virtual string how() {
		stringstream ss;
		ss << _solution << ends;
		return ss.str();
	}

public:
	bool _failed;
	string _file;
	long _line;
	string _function;
	long _errorID;
	Anomaly _anomaly;
	Msg _message;
	Sln _solution;
};

template<typename ...>
class Pointer;

template<>
class Pointer<> {
public:
	typedef class Pointer<> Type;

public:
	Pointer() = delete;
	Pointer(const Pointer&) = delete;
	Pointer &operator=(const Pointer&) = delete;
	virtual ~Pointer() = delete;

public:
	template<const long I, typename ...Bs>
	struct GetBase;

	template<typename B, typename ...Bs>
	struct GetBase<0, B, Bs...> {
		typedef B Base;
		static const long _OFFSET = 0;
	};

	template<const long I, typename B, typename ...Bs>
	struct GetBase<I, B, Bs...> {
		typedef typename GetBase<I - 1, Bs...>::Base Base;
		static const long _OFFSET = sizeof(B) + GetBase<I - 1, Bs...>::_OFFSET;
	};
};

template<>
class Pointer<char> {
	friend bool operator==(const Pointer &lhs, const Pointer &rhs) {
		// cerr << __FUNCTION__ << " rhs: " << rhs._pointer << " " << *rhs._count << " " << rhs._length << endl;
		if (lhs._pointer == rhs._pointer) {
			return true;
		}
		return false;
	}

	friend bool operator!=(const Pointer &lhs, const Pointer &rhs) {
		// cerr << __FUNCTION__ << " rhs: " << rhs._pointer << " " << *rhs._count << " " << rhs._length << endl;
		return !operator==(lhs, rhs);
	}

public:
	typedef class Pointer<char> Type;
	static const long _ARGC = 1;
	static const long _SIZE = sizeof(char);

public:
	Pointer(char *pointer, long length = 1)
		:_pointer(pointer), _count(new long(1)), _length(length) {
		// cerr << __FUNCTION__ << " " << *_count << " " << _length << endl;
	}

	Pointer(char *pointer, long *count, long length)
		: _pointer(pointer), _count(count), _length(length) {
		*_count += 1;
		// cerr << __FUNCTION__ << " " << *_count << " " << _length << endl;
	}

	Pointer(const Pointer &pointer) {
		_pointer = pointer._pointer;
		_count = pointer._count;
		_length = pointer._length;
		*_count += 1;
		// cerr << __FUNCTION__ << " " << *_count << " " << _length << endl;
	}

	Pointer &operator=(const Pointer &pointer) {
		if (this != &pointer) {
			this->~Pointer();
			_pointer = pointer._pointer;
			_count = pointer._count;
			_length = pointer._length;
			*_count += 1;
		}
		// cerr << __FUNCTION__ << " " << *_count << " " << _length << endl;
		return *this;
	}

	virtual ~Pointer() {
		// cerr << __FUNCTION__ << " " << *_count << " " << _length << endl;
		*_count -= 1;
		if (*_count <= 0) {
			_length <= 1 ? delete _pointer : delete[] _pointer;
			_pointer = nullptr;
			delete _count;
			_count = nullptr;
		}
	}

public:
	template<const long I = 0>
	Pointer<char> setLength(const long length = 2) {
		// cerr << __FUNCTION__ << endl;
		_length = length;
		return *this;
	}

	template<const long I = 0>
	Pointer<char> at() const {
		// cerr << __FUNCTION__ << endl;
		return *this;
	}

public:
	operator char *() {
		// cerr << __FUNCTION__ << endl;
		errno = (_pointer == nullptr);
		Check(_pointer == nullptr, __FILE__, __LINE__, __FUNCTION__, "_pointer == nullptr");
		return _pointer;
	}

public:
	char *_pointer;
	long *_count;
	long _length;
};

template<typename T>
class Pointer<T> {
	friend bool operator==(const Pointer &lhs, const Pointer &rhs) {
		// cerr << __FUNCTION__ << " rhs: " << rhs._pointer << " " << *rhs._count << " " << rhs._length << endl;
		if (lhs._pointer == rhs._pointer) {
			return true;
		}
		return false;
	}

	friend bool operator!=(const Pointer &lhs, const Pointer &rhs) {
		// cerr << __FUNCTION__ << " rhs: " << rhs._pointer << " " << *rhs._count << " " << rhs._length << endl;
		return !operator==(lhs, rhs);
	}

public:
	typedef class Pointer<T> Type;
	static const long _ARGC = 1;
	static const long _SIZE = sizeof(T);

public:
	Pointer(T *pointer, long length = 1)
		:_pointer(pointer), _count(new long(1)), _length(length) {
		// cerr << __FUNCTION__ << " " << *_count << " " << _length << endl;
	}

	Pointer(T *pointer, long *count, long length)
		: _pointer(pointer), _count(count), _length(length) {
		*_count += 1;
		// cerr << __FUNCTION__ << " " << *_count << " " << _length << endl;
	}

	Pointer(const Pointer &pointer) {
		_pointer = pointer._pointer;
		_count = pointer._count;
		_length = pointer._length;
		*_count += 1;
		// cerr << __FUNCTION__ << " " << *_count << " " << _length << endl;
	}

	Pointer &operator=(const Pointer &pointer) {
		if (this != &pointer) {
			this->~Pointer();
			_pointer = pointer._pointer;
			_count = pointer._count;
			_length = pointer._length;
			*_count += 1;
		}
		// cerr << __FUNCTION__ << " " << *_count << " " << _length << endl;
		return *this;
	}

	virtual ~Pointer() {
		// cerr << __FUNCTION__ << " " << *_count << " " << _length << endl;
		*_count -= 1;
		if (*_count <= 0) {
			_length <= 1 ? delete _pointer : delete[] _pointer;
			_pointer = nullptr;
			delete _count;
			_count = nullptr;
			_length = 0;
		}
	}

public:
	template<const long I = 0>
	Pointer<T> &setLength(const long length = 2) {
		// cerr << __FUNCTION__ << endl;
		_length = length;
		return *this;
	}

	template<const long I = 0>
	Pointer<T> at() const {
		// cerr << __FUNCTION__ << endl;
		return *this;
	}

public:
	T &operator*() {
		// cerr << __FUNCTION__ << endl;
		errno = (_pointer == nullptr);
		check(_pointer == nullptr, __FILE__, __LINE__, __FUNCTION__, "_pointer == nullptr");
		return *_pointer;
	}

	T *operator->() {
		//cerr << __FUNCTION__ << " " << _pointer << " " << *_count << " " << _length << endl;
		errno = (_pointer == nullptr);
		check(_pointer == nullptr, __FILE__, __LINE__, __FUNCTION__, "_pointer == nullptr");
		return &(*_pointer);
	}

public:
	T *_pointer;
	long *_count;
	long _length;
};

template<typename T, typename ...Ts>
class Pointer<T, Ts...> {
	friend bool operator==(const Pointer &lhs, const Pointer &rhs) {
		// cerr << __FUNCTION__ << " rhs: " << rhs._pointers << " " << *rhs._count << endl;
		if (lhs._count == rhs._count) {
			return true;
		}
		return false;
	}

	friend bool operator!=(const Pointer &lhs, const Pointer &rhs) {
		// cerr << __FUNCTION__ << " rhs: " << rhs._pointers << " " << *rhs._count << endl;
		return !operator==(lhs, rhs);
	}

public:
	typedef class Pointer<T, Ts...> Type;
	static const long _ARGC = 1 + sizeof...(Ts);
	static const long _SIZE = sizeof(T) + Pointer<Ts...>::_SIZE;

public:
	Pointer(T *pointer, Ts*...pointers)
		:_pointers{ { pointer, new long(1), 1 }, { pointers, new long(1), 1 }... }, _count(new long(1)) {
		// cerr << __FUNCTION__ << " " << *_count << endl;
	}

	Pointer(const Pointer &pointer) {
		memcpy(_pointers, pointer._pointers, sizeof(_pointers));
		_count = pointer._count;
		for (long i = 0; i < _ARGC; ++i) {
			*(_pointers[i]._count) += 1;
		}
		*_count += 1;
		// cerr << __FUNCTION__ << " " << *_count << endl;
	}

	Pointer &operator=(const Pointer &pointer) {
		if (this != &pointer) {
			this->~Pointer();
			memcpy(_pointers, pointer._pointers, sizeof(_pointers));
			_count = pointer._count;
			for (long i = 0; i < _ARGC; ++i) {
				*(_pointers[i]._count) += 1;
			}
			*_count += 1;
		}
		// cerr << __FUNCTION__ << " " << *_count << endl;
		return *this;
	}

	virtual ~Pointer() {
		// cerr << __FUNCTION__ << " " << *_count << "#";
		long i = 0;
		long argc[] = {
			(deleted<T>(i), i += 1), (deleted<Ts>(i), i += 1)...
		};
		if (sizeof(argc) / sizeof(*argc) != _ARGC) {
			// cerr << "\033[33m" << __FUNCTION__ << " " << *_count << "#" << "sizeof(argc) != _ARGC" << "\033[0m" << endl;
		}

		*_count -= 1;
		if (*_count <= 0) {
			delete _count;
		}
	}

protected:
	template<typename B>
	void deleted(const long i) {
		// cerr << *_pointers[i]._count << ":" << _pointers[i]._length << ":" << *(B*)(_pointers[i]._pointer) << " ";
		if (i == _ARGC - 1) {
			// cerr << endl;
		}
		*(_pointers[i]._count) -= 1;
		if (*(_pointers[i]._count) <= 0) {
			_pointers[i]._length <= 1 ? delete (B*)(_pointers[i]._pointer) : delete[](B*)(_pointers[i]._pointer);
			_pointers[i]._pointer = nullptr;
			delete _pointers[i]._count;
			_pointers[i]._count = nullptr;
		}
	}

public:
	template<const long I>
	decltype(auto) setLength(const long length = 2) {
		_pointers[I]._length = length;
		// cerr << __FUNCTION__ << endl;
		return *this;
	}

	template<const long I>
	decltype(auto) at() const {
		typedef typename Pointer<>::GetBase<I, T, Ts...>::Base Base;
		// cerr << __FUNCTION__ << "<" << I << ">()#" << typeid(Base).name() << endl;
		return Pointer<Base>((Base*)(_pointers[I]._pointer), _pointers[I]._count, _pointers[I]._length);
	}

public:
	struct {
		void *_pointer;
		long *_count;
		long _length;
	} _pointers[_ARGC];
	long *_count;
};

template<typename T>
decltype(auto) GetPointer(T *pointer, long length) {
	// cerr << __FUNCTION__ << "(const T *pointer)" << endl;
	return Pointer<T>(pointer, length);
}

template<typename T, typename ...Ts>
decltype(auto) GetPointer(T *pointer, Ts*...pointers) {
	// cerr << __FUNCTION__ << "(const Ts*...pointers)" << endl;
	return Pointer<T, Ts...>(pointer, pointers...);
}

////////////////////////////////////////////////////////////////////////////////

template<typename ...>
class Assembly;

template<typename T>
class Assembly<T> {
public:
	typedef class Assembly<T> Type;
	static const long _ARGC = 1;
	static const long _SIZE = sizeof(T);

public:
	Assembly(const T &element)
		:_element(element) {
		// cerr << __FUNCTION__ << endl;
	}

	Assembly(const Assembly &assembly) {
		_element = assembly._element;
		// cerr << __FUNCTION__ << endl;
	}

	Assembly &operator=(const Assembly &assembly) {
		if (this != &assembly) {
			this->~Assembly();
			_element = assembly._element;
		}
		// cerr << __FUNCTION__ << endl;
		return *this;
	}

	virtual ~Assembly() {
		// cerr << __FUNCTION__ << endl;
	}

public:
	template<const long I = 0>
	T at() {
		// cerr << __FUNCTION__ << endl;
		return _element;
	}

public:
	T _element;
};

/*PLEASE
* Es is NOT eX, emplace is Not inplace, assembly is NOT ass, B b is NOT Baby.
*/
template<typename T, typename ...Ts>
class Assembly<T, Ts...> {
public:
	typedef class Assembly<T, Ts...> Type;
	static const long _ARGC = 1 + sizeof...(Ts);
	static const long _SIZE = sizeof(T) + Assembly<Ts...>::_SIZE;

public:
	Assembly(const T &element, const Ts &...elements)
		: _pointer(_elements), _pointers{
			(_pointer + 0),
			(emplace(element, _pointer), _pointer += sizeof(T)),
			(emplace(elements, _pointer), _pointer += sizeof(Ts))
			...
	}{
		// cerr << endl;
		// cerr << __FUNCTION__ << endl;
	}

	Assembly(const Assembly &assembly) {
		memcpy(_elements, assembly._elements, sizeof(_elements));
		memcpy(_pointers, assembly._pointers, sizeof(_pointers));
		// cerr << __FUNCTION__ << endl;
	}

	Assembly &operator=(const Assembly &assembly) {
		if (this != &assembly) {
			this->~Assembly();
			memcpy(_elements, assembly._elements, sizeof(_elements));
			memcpy(_pointers, assembly._pointers, sizeof(_pointers));
		}
		// cerr << __FUNCTION__ << endl;
		return *this;
	}

	virtual ~Assembly() {
		// cerr << __FUNCTION__ << endl;
	}

protected:
	template<typename E>
	void emplace(const E &e, char *pointer) {
		if (pointer == _elements) {
			// cerr << __FUNCTION__ << "#";
		}
		// cerr << e << " ";
		*((E*)pointer) = e;
	}

public:
	template<const long I>
	decltype(auto) at() {
		// cerr << __FUNCTION__ << endl;
		typedef typename Pointer<>::GetBase<I, T, Ts...>::Base Base;
		return *((Base*)_pointers[I]);
	}

public:
	char *_pointer;
	char _elements[_SIZE];
	void *_pointers[_ARGC + 1];
};

#endif // Pointer_hpp

#ifndef Pointer_cpp
#define Pointer_cpp

void Check(bool failed, const string &file, const long line, const string &function, const string &message) {
	// cerr << __FUNCTION__ << endl;
	if (failed) {
		cerr << "\33[33m" << file << "##" << line << "##" << function << "##[" << errno << "]" << message << "\33[0m" << endl;
		if (errno) {
			throw errno;
		}
	}
}

void Freed(const long num, ...) {
	fprintf(stderr, "%s\n", __FUNCTION__);
	va_list args;
	va_start(args, num);
	for (long i = 0; i != num; ++i) {
		void *ptr = va_arg(args, void*);
		if (ptr == NULL) {
			break;
		}
		free(ptr);
	}
	va_end(args);
}

#endif // Pointer_cpp

////////////////////////////////////////////////////////////////////////////////

#define Main
#ifdef Main
decltype(auto) testPointer() {
	long *l = new long(11);
	char *s = new char[12]{ 'a', 'b', 'c' };
	Pointer<long, double, char> ptr(l, new double(11.12), s);
	ptr.setLength<2>(12);
	return ptr.at<2>();
}

decltype(auto) testAssembly() {
	Assembly<long, double, const char*> assembly(11, 12, "ass");
	return assembly.at<1>();
}

int main(int argc, char *argv[]) {
	//auto str = testPointer();
	//cout << str << endl;

	//auto ass = testAssembly();
	//cout << ass << endl;

	//throw Exception<>(true, __FILE__, __LINE__, __FUNCTION__, "test");
	Exception<>(true, __FILE__, __LINE__, __FUNCTION__, "test").check();

	return 0;
}

#endif // Main
