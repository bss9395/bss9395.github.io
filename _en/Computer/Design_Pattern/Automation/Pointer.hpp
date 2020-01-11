/*Pointer.hpp
* Author: BSS9395
* Update: 2020-01-01T16:39:00+08@ShenZhen
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
#include <functional>
#include <typeinfo>
using std::cout;
using std::cerr;
using std::flush;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::stringstream;
using std::exception;
using std::function;

////////////////////////////////////////////////////////////////////////////////

typedef const char *Tag;
typedef const char *Method;
typedef const char *Level;

namespace EType {
	static const Tag Debug = "Debug";
	static const Tag Release = "Release";
	static const Tag Beta = "Beta";
	static const Tag Stable = "Stable";

	static const Method Free = "Free";
	static const Method Delete = "Delete";

	static const Level Information = "Information";
	static const Level Incompleted = "Incompleted";
	static const Level Obsolete = "Obsolete";
	static const Level Warning = "Warning";
	static const Level Error = "Error";
	static const Level Fatal = "Fatal";
};

////////////////////////////////////////////////////////////////////////////////

template<typename Rep = string>        int Check(bool failed, const string &file, const long &line, const string &function, const int &error, const Rep &report);
template<typename Rep, typename Sln> class Anomaly;
typedef class Anomaly<string, string>      Exception;

class Cleanup;

template<typename ...>               class Pointer;
template<>                           class Pointer<char>;
template<typename T>                 class Pointer<T>;
template<typename T, typename ...Ts> class Pointer<T, Ts...>;
template<typename T>                 decltype(auto) GetPointer(T *pointer, long size = 1);
template<typename T, typename ...Ts> decltype(auto) GetPointer(T *pointer, Ts *...pointers);

template<typename ...>               class Assembly;
template<typename T>                 class Assembly<T>;
template<typename T, typename ...Ts> class Assembly<T, Ts...>;

////////////////////////////////////////////////////////////////////////////////

template<typename Rep>
int Check(bool failed, const string &file, const long &line, const string &function, const int &error, const Rep &report) {
	// cerr << __FUNCTION__ << endl;
	if (failed) {
		cerr << file << "##" << line << "##" << function << "##[" << error << "]" << report << endl;
		if (!(0 == errno && 0 == error)) {
			cerr << "[" << errno << "]" << strerror(errno) << endl;
			throw errno;
		}
	}
	errno = 0;
	return 0;
}

////////////////////////////////////////////////////////////////////////////////

template<typename Rep, typename Sln>
class Anomaly
	: public exception {
public:
	friend ostream &operator<<(ostream &os, const Anomaly &anomaly) {
		cerr << __FUNCTION__ << endl;
		os << anomaly.issue() << flush;
		return os;
	}

public:
	Anomaly(bool failed, const string &file, const long &line, const string &function, const Level &level = EType::Information, const Rep &report = Rep(), const Sln &solution = Sln())
		: _failed(failed), _file(file), _line(line), _function(function), _errorID(errno), _level(level), _report(report), _solution(solution) {
		errno = 0;
		// cerr << __FUNCTION__ << endl;
	}

	Anomaly(const Anomaly &anomaly) {
		_failed = anomaly._failed;
		_file = anomaly._file;
		_line = anomaly._line;
		_function = anomaly._function;
		_errorID = anomaly._errorID;
		_level = anomaly._level;
		_report = anomaly._report;
		_solution = anomaly._solution;
		// cerr << __FUNCTION__ << endl;
	}

	Anomaly &operator=(const Anomaly &anomaly) {
		if (this != &anomaly) {
			this->~Anomaly();
			_failed = anomaly._failed;
			_file = anomaly._file;
			_line = anomaly._line;
			_function = anomaly._function;
			_errorID = anomaly._errorID;
			_level = anomaly._level;
			_report = anomaly._report;
			_solution = anomaly._solution;
		}
		// cerr << __FUNCTION__ << endl;
		return *this;
	}

	virtual ~Anomaly() {
		// cerr << __FUNCTION__ << endl;
	}

public:
	virtual int check() const {
		// cerr << __FUNCTION__ << endl;
		if (_failed) {
			cerr << issue() << endl;
			if (!(_errorID == 0 && _level == EType::Information)) {
				throw *this;
			}
		}
		return _errorID;
	}

	virtual const char *what() const noexcept {
		// cerr << __FUNCTION__ << endl;
		cerr << "Obsolete function what(), Use issue() Instead." << endl;
		static char buf[1024] = "0123456789";
		snprintf(buf, sizeof(buf), "%s", issue().c_str());
		return buf;
	}

	virtual string issue() const noexcept {
		// cerr << __FUNCTION__ << endl;
		stringstream ss;
		ss << _file << "##" << _line << "##" << _function << "##[" << _level << "]" << _report << flush;
		if (_errorID) {
			ss << endl << "[" << _errorID << "]" << strerror(_errorID) << flush;
		}
		return ss.str();
	}

	virtual Rep &report() {
		// cerr << __FUNCTION__ << endl;
		return _report;
	}

	virtual Sln &solution() {
		// cerr << __FUNCTION__ << endl;
		return _solution;
	}

public:
	bool _failed;
	string _file;
	long _line;
	string _function;
	int _errorID;
	Level _level;
	Rep _report;
	Sln _solution;
};

////////////////////////////////////////////////////////////////////////////////

class Cleanup {
	typedef function<void(void)> Function;

public:
	template<typename Func, typename ...Args>
	Cleanup(Func func, Args ...args) {
		cerr << __FUNCTION__ << "(Func func, Args ...args)" << endl;
		auto lamb = [func, args...]() -> void {
			func(args...);
		};
		_function = lamb;
	}

	template<typename T, typename ...Ts>
	Cleanup(Method method, T *t, Ts *...ts) {
		cerr << __FUNCTION__ << "(Method method, T *t, Ts *...ts)" << endl;
		auto lamb = [method, t, ts...]() -> void {
			if (method == EType::Delete) {
				Cleanup::Deleted(t, ts...);
			}
			else if (method == EType::Free) {
				Cleanup::Freed(t, ts...);
			}
		};
		_function = lamb;
	}

	template<typename Ptr>
	static void Deleted(Ptr *ptr) {
		delete ptr;
	}

	template<typename Ptr, typename ...Ptrs>
	static void Deleted(Ptr *ptr, Ptrs *...ptrs) {
		Deleted(ptr);
		Deleted(ptrs...);
	}

	template<typename Ptr>
	static void Freed(Ptr *ptr) {
		free(ptr);
	}

	template<typename Ptr, typename ...Ptrs>
	static void Freed(Ptr *ptr, Ptrs *...ptrs) {
		Freed(ptr);
		Freed(ptrs...);
	}

	virtual ~Cleanup() {
		cerr << __FUNCTION__ << endl;
		_function();
	}

public:
	Function _function;
};

////////////////////////////////////////////////////////////////////////////////

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
	template<const long I, typename ...Ts>
	struct GetType;

	template<typename T, typename ...Ts>
	struct GetType<0, T, Ts...> {
		typedef T Type;
		static const long _OFFSET = 0;
	};

	template<const long I, typename T, typename ...Ts>
	struct GetType<I, T, Ts...> {
		typedef typename GetType<I - 1, Ts...>::Type Type;
		static const long _OFFSET = sizeof(T) + GetType<I - 1, Ts...>::_OFFSET;
	};
};

template<>
class Pointer<char> {
	friend bool operator==(const Pointer &lhs, const Pointer &rhs) {
		// cerr << __FUNCTION__ << " rhs: " << rhs._pointer << " " << *rhs._count << " " << rhs._size << endl;
		if (lhs._pointer == rhs._pointer) {
			return true;
		}
		return false;
	}

	friend bool operator!=(const Pointer &lhs, const Pointer &rhs) {
		// cerr << __FUNCTION__ << " rhs: " << rhs._pointer << " " << *rhs._count << " " << rhs._size << endl;
		return !operator==(lhs, rhs);
	}

public:
	typedef class Pointer<char> Type;
	static const long _ARGC = 1;
	static const long _SIZE = sizeof(char);

public:
	Pointer(nullptr_t null = nullptr)
		: _pointer(nullptr), _count(new long(0)), _size(0) {
		// cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
	}

	Pointer(char *pointer, long size = 1)
		:_pointer(pointer), _count(new long(1)), _size(size) {
		// cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
	}

	Pointer(char *pointer, long *count, long size)
		: _pointer(pointer), _count(count), _size(size) {
		*_count += 1;
		// cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
	}

	Pointer(const Pointer &pointer) {
		_pointer = pointer._pointer;
		_count = pointer._count;
		_size = pointer._size;
		*_count += 1;
		// cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
	}

	Pointer &operator=(const Pointer &pointer) {
		if (this != &pointer) {
			this->~Pointer();
			_pointer = pointer._pointer;
			_count = pointer._count;
			_size = pointer._size;
			*_count += 1;
		}
		// cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
		return *this;
	}

	virtual ~Pointer() {
		// cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
		*_count -= 1;
		if (*_count <= 0) {
			_size <= 1 ? delete _pointer : delete[] _pointer;
			_pointer = nullptr;
			delete _count;
			_count = nullptr;
		}
	}

public:
	template<const long I = 0>
	Pointer<char> setLength(const long size = 2) {
		// cerr << __FUNCTION__ << endl;
		_size = size;
		return *this;
	}

	template<const long I = 0>
	Pointer<char> at() const {
		// cerr << __FUNCTION__ << endl;
		return *this;
	}

public:
	operator char *() const {
		// cerr << __FUNCTION__ << endl;
		Check(_pointer == nullptr, __FILE__, __LINE__, __FUNCTION__, errno, "_pointer == nullptr");
		return (char *)_pointer;
	}

	operator void *() const {
		// cerr << __FUNCTION__ << endl;
		Check(_pointer == nullptr, __FILE__, __LINE__, __FUNCTION__, errno, "_pointer == nullptr");
		return (void *)_pointer;
	}

public:
	char *_pointer;
	long *_count;
	long _size;
};

template<typename T>
class Pointer<T> {
	friend bool operator==(const Pointer &lhs, const Pointer &rhs) {
		// cerr << __FUNCTION__ << " rhs: " << rhs._pointer << " " << *rhs._count << " " << rhs._size << endl;
		if (lhs._pointer == rhs._pointer) {
			return true;
		}
		return false;
	}

	friend bool operator!=(const Pointer &lhs, const Pointer &rhs) {
		// cerr << __FUNCTION__ << " rhs: " << rhs._pointer << " " << *rhs._count << " " << rhs._size << endl;
		return !operator==(lhs, rhs);
	}

public:
	typedef class Pointer<T> Type;
	static const long _ARGC = 1;
	static const long _SIZE = sizeof(T);

public:
	Pointer(nullptr_t null = nullptr)
		: _pointer(nullptr), _count(new long(0)), _size(0) {
		// cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
	}

	Pointer(T *pointer, long size = 1)
		: _pointer(pointer), _count(new long(1)), _size(size) {
		// cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
	}

	Pointer(T *pointer, long *count, long size)
		: _pointer(pointer), _count(count), _size(size) {
		*_count += 1;
		// cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
	}

	Pointer(const Pointer &pointer) {
		_pointer = pointer._pointer;
		_count = pointer._count;
		_size = pointer._size;
		*_count += 1;
		// cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
	}

	Pointer &operator=(const Pointer &pointer) {
		if (this != &pointer) {
			this->~Pointer();
			_pointer = pointer._pointer;
			_count = pointer._count;
			_size = pointer._size;
			*_count += 1;
		}
		// cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
		return *this;
	}

	virtual ~Pointer() {
		// cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
		*_count -= 1;
		if (*_count <= 0) {
			_size <= 1 ? delete _pointer : delete[] _pointer;
			_pointer = nullptr;
			delete _count;
			_count = nullptr;
			_size = 0;
		}
	}

public:
	template<const long I = 0>
	Pointer<T> &setLength(const long size = 2) {
		// cerr << __FUNCTION__ << endl;
		_size = size;
		return *this;
	}

	template<const long I = 0>
	Pointer<T> at() const {
		// cerr << __FUNCTION__ << endl;
		return *this;
	}

public:
	T &operator*() const {
		// cerr << __FUNCTION__ << endl;
		Check(_pointer == nullptr, __FILE__, __LINE__, __FUNCTION__, errno, "_pointer == nullptr");
		return *_pointer;
	}

	T *operator->() const {
		//cerr << __FUNCTION__ << " " << _pointer << " " << *_count << " " << _size << endl;
		Check(_pointer == nullptr, __FILE__, __LINE__, __FUNCTION__, errno, "_pointer == nullptr");
		return &(*_pointer);
	}

	operator void *() const {
		// cerr << __FUNCTION__ << endl;
		Check(_pointer == nullptr, __FILE__, __LINE__, __FUNCTION__, errno, "_pointer == nullptr");
		return (void *)_pointer;
	}

public:
	T *_pointer;
	long *_count;
	long _size;
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
		: _pointers{ { pointer, new long(1), 1 }, { pointers, new long(1), 1 }... }, _count(new long(1)) {
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
		// cerr << *_pointers[i]._count << ":" << _pointers[i]._size << ":" << *(B*)(_pointers[i]._pointer) << " ";
		if (i == _ARGC - 1) {
			// cerr << endl;
		}
		*(_pointers[i]._count) -= 1;
		if (*(_pointers[i]._count) <= 0) {
			_pointers[i]._size <= 1 ? delete (B*)(_pointers[i]._pointer) : delete[](B*)(_pointers[i]._pointer);
			_pointers[i]._pointer = nullptr;
			delete _pointers[i]._count;
			_pointers[i]._count = nullptr;
		}
	}

public:
	template<const long I>
	decltype(auto) setLength(const long size = 2) {
		_pointers[I]._size = size;
		// cerr << __FUNCTION__ << endl;
		return *this;
	}

	template<const long I>
	decltype(auto) at() const {
		typedef typename Pointer<>::GetType<I, T, Ts...>::Type Base;
		// cerr << __FUNCTION__ << "<" << I << ">()#" << typeid(Base).name() << endl;
		return Pointer<Base>((Base*)(_pointers[I]._pointer), _pointers[I]._count, _pointers[I]._size);
	}

public:
	struct {
		void *_pointer;
		long *_count;
		long _size;
	} _pointers[_ARGC];
	long *_count;
};

template<typename T>
decltype(auto) GetPointer(T *pointer, long size) {
	// cerr << __FUNCTION__ << "(const T *pointer)" << endl;
	return Pointer<T>(pointer, size);
}

template<typename T, typename ...Ts>
decltype(auto) GetPointer(T *pointer, Ts*...pointers) {
	// cerr << __FUNCTION__ << "(const Ts *...pointers)" << endl;
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
		typedef typename Pointer<>::GetType<I, T, Ts...>::Type Base;
		return *((Base*)_pointers[I]);
	}

public:
	char *_pointer;
	char _elements[_SIZE];
	void *_pointers[_ARGC + 1];
};

#endif // Pointer_hpp

////////////////////////////////////////////////////////////////////////////////

// #define Main
#ifdef Main
void TestAnomaly() {
	auto anomaly = Anomaly<string, string>(true, __FILE__, __LINE__, __FUNCTION__, EType::Information, "An abnomal exception.", "Leave me alone.");
	anomaly.check();
	cerr << anomaly.issue() << endl;
	cerr << anomaly.report() << endl;
	cerr << anomaly.solution() << endl;

	Exception(true, __FILE__, __LINE__, __FUNCTION__, EType::Incompleted, "To be implemented.", "Pick up me later.").check();
	// throw Exception(true, __FILE__, __LINE__, __FUNCTION__, EType::Incompleted, "To be implemented.", "Pick up me later.");
}

void TestCleanup() {
	char *ptr = new char[10];
	auto lamb = [](char *ptr) -> long {
		delete[] ptr;
		return 1;
	};
	Cleanup clean_lamb(lamb, ptr);

	long *l = new long(12);
	double *d = new double(23.0);
	Cleanup clean_ptr(EType::Delete, l, d);
}


decltype(auto) TestPointer() {
	long *l = new long(11);
	char *s = new char[12]{ 'a', 'b', 'c' };
	Pointer<long, double, char> ptr(l, new double(11.12), s);
	ptr.setLength<2>(12);
	return ptr.at<2>();
}

decltype(auto) TestAssembly() {
	Assembly<long, double, const char*> assembly(11, 12, "ass");
	return assembly.at<1>();
}


int main(int argc, char *argv[]) {
	// TestAnomaly();

	TestCleanup();

	// auto str = TestPointer();
	// cout << str << endl;

	// auto ass = TestAssembly();
	// cout << ass << endl;

	return 0;
}

#endif // Main
