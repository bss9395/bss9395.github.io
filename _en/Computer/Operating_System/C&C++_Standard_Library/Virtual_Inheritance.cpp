/* Virtual_Inheritance.cpp
Author: BSS9395
Update: 2022-06-16T17:03:00+08@China-Shanghai+08
Design: C++ Language Feature: Virtual Inheritance
*/

#include <iostream>
typedef unsigned int uint;
typedef intptr_t iptr;
typedef size_t uptr;

class Parent {
public:
	double _value = 123.456;

public:
	Parent() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}
};

class Male : virtual public Parent {

};

class Female : virtual public Parent {

};

class Child : public Male, public Female {

};

void Test_Virtual_Inheritance() {
	fprintf(stdout, "sizeof(int) = %td\n", (iptr)sizeof(int));
	fprintf(stdout, "sizeof(long) = %td\n", (iptr)sizeof(long long));


	fprintf(stdout, "sizeof(Parent) = %td\n", (iptr)sizeof(Parent));
	fprintf(stdout, "sizeof(Male) = %td\n", (iptr)sizeof(Male));
	fprintf(stdout, "sizeof(Female) = %td\n", (iptr)sizeof(Female));
	fprintf(stdout, "sizeof(Child) = %td\n", (iptr)sizeof(Child));


	Male male = Male();
	uint offset = *((uint *)*(uptr *)&male + 1);
	double value = ((Parent*)((char *)&male + offset))->_value;
	fprintf(stdout, "offset = %td\n", (iptr)offset);
	fprintf(stdout, "parent->_value = %lf\n", value);
}

int main(int argc, char* argv[]) {
	Test_Virtual_Inheritance();

	return 0;
}
