/* AutoPtr_cpp
* Author: bss9395
* Update: 2019-11-30T00:37:00+08@ShenZhen
* Design: Auto Pointer
*/

#ifndef AutoPtr_hpp
#define AutoPtr_hpp

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <iostream>
#include <string>
#include <typeinfo>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

void freed(long num, ...);

template<typename T>
void deleted(T* t);

template<typename T, typename ...Ts>
void deleted(T* t, Ts* ...ts);

template<typename ...Ts>
class AutoPtr;

template<typename ...Ts>
decltype(auto) getPtr(Ts* ...ts);

template<const long I, typename ...Ts>
decltype(auto) getPtr(const AutoPtr<Ts...>& ptr);

////////////////////////////////////////////////////////////////////////////////

template<typename T>
void deleted(T* t) {
	cerr << __FUNCTION__ << endl;
	delete(t);
}

template<typename T, typename ...Ts>
void deleted(T* t, Ts* ...ts) {
	deleted(t);
	deleted(ts...);
}

template<typename ...Ts>
class AutoPtr;

template<>
class AutoPtr<> {
public:
	AutoPtr() {}
	AutoPtr(const AutoPtr&) = delete;
	AutoPtr& operator=(const AutoPtr&) = delete;
	virtual ~AutoPtr() {}

public:
	template<long N, typename ...Ts>
	struct GetType;

	template<typename T, typename ...Ts>
	struct GetType<0, T, Ts...> {
		typedef T Type;
	};

	template<long N, typename T, typename ...Ts>
	struct GetType<N, T, Ts...> {
		typedef typename GetType<N - 1, Ts...>::Type Type;
	};
};

template<>
class AutoPtr<char> {
public:
	static const long Argc = 1;
	typedef class AutoPtr<char> Type;

public:
	AutoPtr(void* base, long* count)
		: _base((char*)base), _count(count) {
		*_count += 1;
		cerr << __FUNCTION__ << *_count << "#" << endl;
	}
	AutoPtr(char* base)
		: _base(base), _count(new long(1)) {
		cerr << __FUNCTION__ << *_count << "#" << endl;
	}

	AutoPtr(const AutoPtr& ptr) {
		_base = ptr._base;
		_count = ptr._count;
		*_count += 1;
		cerr << __FUNCTION__ << *_count << "#" << endl;
	}

	AutoPtr& operator=(const AutoPtr& ptr) {
		if (this != &ptr) {
			this->~AutoPtr();
			_base = ptr._base;
			_count = ptr._count;
			*_count += 1;
		}
		cerr << __FUNCTION__ << *_count << "#" << endl;
		return *this;
	}

	virtual ~AutoPtr() {
		cerr << __FUNCTION__ << *_count << "#" << endl;
		*_count -= 1;
		if (*_count <= 0) {
			delete _base;
			delete _count;

			_base = nullptr;
			_count = nullptr;
		}
	}

public:
	operator char* () {
		return _base;
	}

public:
	struct {
		char* _base;
		long* _count;
	};
};

template<typename T>
class AutoPtr<T> {
public:
	static const long Argc = 1;
	typedef class AutoPtr<T> Type;

public:
	AutoPtr(void* base, long* count)
		: _base((T*)base), _count(count) {
		*_count += 1;
		cerr << __FUNCTION__ << *_count << "#" << endl;
	}
	AutoPtr(T* base)
		: _base(base), _count(new long(1)) {
		cerr << __FUNCTION__ << *_count << "#" << endl;
	}

	AutoPtr(const AutoPtr& ptr) {
		_base = ptr._base;
		_count = ptr._count;
		*_count += 1;
		cerr << __FUNCTION__ << *_count << "#" << endl;
	}

	AutoPtr& operator=(const AutoPtr& ptr) {
		if (this != &ptr) {
			this->~AutoPtr();
			_base = ptr._base;
			_count = ptr._count;
			*_count += 1;
		}
		cerr << __FUNCTION__ << *_count << "#" << endl;
		return *this;
	}

	virtual ~AutoPtr() {
		cerr << __FUNCTION__ << *_count << "#" << endl;
		*_count -= 1;
		if (*_count <= 0) {
			delete _base;
			delete _count;

			_base = nullptr;
			_count = nullptr;
		}
	}

public:
	T& operator*() {
		return *_base;
	}

	T* operator->() {
		return _base;
	}

public:
	struct {
		T* _base;
		long* _count;
	};
};

template<typename T, typename ...Ts>
class AutoPtr<T, Ts...> {
public:
	static const long Argc = 1 + sizeof...(Ts);
	typedef class AutoPtr<T, Ts...> Type;

public:
	AutoPtr(T* base, Ts*... bases)
		: _ptrs{ { base, new long(1) }, { bases, new long(1) }... }, _count(new long(1)) {
		cerr << __FUNCTION__ << *_count << "#" << endl;
	}

	AutoPtr(const AutoPtr& ptr) {
		memcpy(_ptrs, ptr._ptrs, sizeof(_ptrs));
		_count = ptr._count;
		for (long i = 0; i < Argc; ++i) {
			*(_ptrs[i]._count) += 1;
		}
		*_count += 1;
		cerr << __FUNCTION__ << *_count << "#" << endl;
	}

	AutoPtr& operator=(const AutoPtr& ptr) {
		if (this != &ptr) {
			this->~AutoPtr();
			memcpy(_ptrs, ptr._ptrs, sizeof(_ptrs));
			_count = ptr._count;
			for (long i = 0; i < Argc; ++i) {
				*(_ptrs[i]._count) += 1;
			}
			*_count += 1;
		}
		cerr << __FUNCTION__ << *_count << "#" << endl;
		return *this;
	}


	template<const long I>
	void deleted() {
		cerr << "#" << endl;
	}

	template<const long I, typename B, typename ...Bs>
	void deleted() {
		cerr << *(_ptrs[I]._count) << ":" << *(B*)(_ptrs[I]._base) << " ";
		*(_ptrs[I]._count) -= 1;
		if (*(_ptrs[I]._count) <= 0) {
			delete (B*)(_ptrs[I]._base);
			delete _ptrs[I]._count;
		}
		deleted<I + 1, Bs...>();
	}

	virtual ~AutoPtr() {
		cerr << __FUNCTION__ << *_count << "#";
		deleted<0, T, Ts...>();
		cerr << endl;

		*_count -= 1;
		if (*_count <= 0) {
			delete _count;
		}
	}

public:
	template<const long I>
	decltype(auto) at() {
		typedef typename AutoPtr<>::GetType<I, T, Ts...>::Type Base;
		cerr << __FUNCTION__ << "<" << I << ">()#" << typeid(Base).name() << endl;
		return AutoPtr<Base>(_ptrs[I]._base, _ptrs[I]._count);
	}

public:
	struct {
		void* _base;
		long* _count;
	} _ptrs[Argc];
	long* _count;
};

template<typename ...Ts>
decltype(auto) getPtr(Ts* ...ts) {
	cerr << __FUNCTION__ << "(Ts* ...ts)" << "#" << endl;
	return AutoPtr<Ts...>(ts...);
}

template<const long I, typename ...Ts>
decltype(auto) getPtr(const AutoPtr<Ts...>& ptr) {
	typedef typename AutoPtr<>::GetType<I, Ts...>::Type Type;
	cerr << __FUNCTION__ << ": " << typeid(Type).name() << "#" << endl;
	return AutoPtr<Type>(ptr._ptrs[I]._base, ptr._ptrs[I]._count);
}

#endif // AutoPtr_hpp

#ifndef AutoPtr_cpp
#define AutoPtr_cpp

void freed(long num, ...) {
	fprintf(stderr, "%s\n", __FUNCTION__);
	va_list args;
	va_start(args, num);
	for (long i = 0; i != num; ++i) {
		void* ptr = va_arg(args, void*);
		if (ptr == NULL) {
			break;
		}
		free(ptr);
	}
	va_end(args);
}

#endif // AutoPtr_cpp

////////////////////////////////////////////////////////////////////////////////

decltype(auto) func() {
	long* l1 = new long(11);
	char* s1 = (char*)operator new (sizeof(char) * 10);
	strcpy(s1, "abc");

	AutoPtr<long, double, char> ptr(l1, new double(12.0), s1);

	long* l2 = new long(11);
	char* s2 = (char*)operator new(sizeof(char) * 10);
	strcpy(s2, "abc");
	auto ret = getPtr(l2, new double(12.0), s2);

	//return ptr.at<2>();
	return getPtr<2>(ret);
}

int main(int argc, char* argv[]) {

	auto ptr = func();
	char* str = ptr;
	cerr << ptr[1] << "#" << str << endl;

	return 0;
}
