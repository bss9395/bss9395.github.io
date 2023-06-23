/* C++_dynamic_cast.cpp
Author: BSS9395
Update: 2023-06-18T17:17:00+08@China-Beijing+08
Design: C++ dynamic_cast
*/

#include <iostream>
using namespace std;

struct Base0 {
	void _Func0() {
		fprintf(stdout, "%s\n", __FUNCTION__);
	}
	virtual void _Virt0(char* i) = 0;
	virtual void _Virt1() = 0;
};

struct Base1 {
	virtual void _Virt() = 0;
};

struct Derived: public Base0, public Base1 {
	void _Func() {
		fprintf(stdout, "%s\n", __FUNCTION__);
	}
	virtual void _Virt0(char* i) {
		fprintf(stdout, "%s\n", __FUNCTION__);
	}
	virtual void _Virt1() {
		fprintf(stdout, "%s\n", __FUNCTION__);
	}
	virtual void _Virt() {
		fprintf(stdout, "%s\n", __FUNCTION__);
	}
};

int main(int argc, char *argv[]) {
	Derived* derived = new Derived();
	Base1* base1 = (Base1*)derived;
	base1->_Virt();
	base1 = (Base1*)(Base0*)derived;
	base1->_Virt();
	base1 = dynamic_cast<Base1*>(derived);
	base1->_Virt();
	return 0;
}
