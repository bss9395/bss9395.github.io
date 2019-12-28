/*Wrapper.cpp
* Author: BSS9395
* Update: 2019-12-29T04:10:00+08@ShenZhen
* Design: Adapter
*/

#ifndef Wrapper_hpp
#define Wrapper_hpp

#include <iostream>
using std::cin;
using std::cout;
using std::clog;
using std::cerr;
using std::flush;
using std::endl;

template<typename Ret, typename ...Args> class Wrapper;
template<typename Ret, typename ...Args> class Wrapper<Ret(Args...)>;

template<typename Ret, typename ...Args>
class Wrapper;

template<typename Ret, typename ...Args>
class Wrapper<Ret(Args...)> {
	typedef Ret(*WrapType)(Args...);

public:
	Wrapper(WrapType wrap)
		: _wrap(wrap) {
		cerr << __FUNCTION__ << endl;
	}

	Wrapper(const Wrapper &wrapper)
		: _wrap(wrapper._wrap) {
		cerr << __FUNCTION__ << endl;
	}

	Wrapper &operator=(const Wrapper &wrapper) {
		if (this != &wrapper) {
			_wrap = wrapper._wrap;
		}
		cerr << __FUNCTION__ << endl;
		return *this;
	}

	virtual ~Wrapper() {
		cerr << __FUNCTION__ << endl;
	}

public:
	Ret operator()(Args... args) const {
		return _wrap(args...);
	}

public:
	WrapType _wrap;
};

#endif // Wrapper_hpp

////////////////////////////////////////////////////////////////////////////////

#define Main
#ifdef Main

static char buf[128] = "0123456789";
static long len = sizeof(buf);

long func(long len, char buf[]) {
	long ret = fprintf(stdout, "%*s\n", len - 1, buf);
	return ret;
}

class Test {
public:
	long readFile(FILE *file) {
		_len = fread(_buf, sizeof(char), 5, file);
		_buf[_len] = '\0';
		cerr << _buf << endl;
		return _len;
	}

public:
	char _buf[128];
	long _len;
};

#include <functional>
using std::function;

void testWrapper() {
	Wrapper<long(long, char[])> wrap1(func);
	wrap1(len, buf);

	auto lambda = [](FILE *file) -> long {
		long len = fread(buf, sizeof(char), 5, file);
		buf[len] = '\0';
		cerr << buf << endl;
		return len;
	};
	Wrapper<long(FILE *)> wrap2(lambda);
	wrap2(stdin);
}

void testFunction() {
	Test test;
	auto f = [&test](FILE *file) -> long {
		return test.readFile(file);
	};
	function<long(FILE*)> wrap3(f);
	wrap3(stdin);
}

int main(int argc, char *argv[]) {
	// testWrapper();
	testFunction();

	return 0;
}

#endif // Main
