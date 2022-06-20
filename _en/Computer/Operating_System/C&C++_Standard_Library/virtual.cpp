/* virtual.cpp
Author: BSS9395
Update: 2022-06-20T16:20:00+08@China-Shanghai+08
Design: C++ keyword: virtual
*/

#include <iostream>
typedef intptr_t iptr;

class Base {
public:
	virtual void _Print() {
	
	}

	virtual void _Func() {
	
	}
};

class Derived : public Base {

};

int main(int argc, char *argv[]) {
	fprintf(stderr, "sizeof(Base) = %td\n", (iptr)sizeof(Base));
	fprintf(stderr, "sizeof(Derived) = %td\n", (iptr)sizeof(Derived));
	return 0;
}
