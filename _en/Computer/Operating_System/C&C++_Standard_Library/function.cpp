#if 0
#include <functional>
using std::function;
#endif

#include <iostream>     
#include <functional> 

using std::cout;
using std::endl;
using std::function;
using std::negate;

int Func(int x) {
	return x;
}

struct Obj {
	int operator()(int x) {
		return x;
	}
};

struct Cls {
	int _val;
	int func(int x) {
		return x + _val;
	}
};

int main(int argc, char *argv[]) {
	function<int(int)> fn1 = Func;                         // function
	function<int(int)> fn2 = &Func;                        // function pointer
	function<int(int)> fn3 = Obj();                        // function object
	function<int(int)> fn4 = [](int x) { return x / 4; };  // lambda expression
	function<int(int)> fn5 = negate<int>();                // standard function object

	cout << "fn1(60): " << fn1(60) << endl;
	cout << "fn2(60): " << fn2(60) << endl;
	cout << "fn3(60): " << fn3(60) << endl;
	cout << "fn4(60): " << fn4(60) << endl;
	cout << "fn5(60): " << fn5(60) << endl;


	function<int(Cls&)> data = &Cls::_val;  // pointer to data member
	function<int(Cls&, int)> func = &Cls::func;  // pointer to member function

	Cls sixty{ 60 };
	cout << "value(sixty): " << data(sixty) << endl;
	cout << "fifth(sixty): " << func(sixty, 12) << endl;

	return 0;
}