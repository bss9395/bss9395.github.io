#include <iostream>
#include <string>
typedef unsigned int uint;
typedef intptr_t iptr;
typedef size_t uptr;

class Person {
public:
	double _value = 0.0;

public:
	Person(double value) {
		fprintf(stderr, "%s, value == %lf\n", __FUNCTION__, value);
		_value = value;
	}

public:
	void _Print() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}
};

class virtual_Male : virtual public Person {
public:
	virtual_Male() : Person(1) {
		fprintf(stderr, "%s\n", __FUNCTION__);
	} 
};
class virtual_Female : virtual public Person {
public:
	virtual_Female() : Person(2) {
		fprintf(stderr, "%s\n", __FUNCTION__);
	} 
};
class virtual_Child : public virtual_Male, public virtual_Female {
public:
	virtual_Child() : Person(3) {
		fprintf(stderr, "%s\n", __FUNCTION__);
	} 
};

void Test_Constructor() {
	auto child = virtual_Child();
}

void Test_Virtual_Inheritance() {
	fprintf(stdout, "sizeof(int) = %td\n", (iptr)sizeof(int));
	fprintf(stdout, "sizeof(long) = %td\n", (iptr)sizeof(long long));


	fprintf(stdout, "sizeof(Person) = %td\n", (iptr)sizeof(Person));
	fprintf(stdout, "sizeof(virtual_Male) = %td\n", (iptr)sizeof(virtual_Male));
	fprintf(stdout, "sizeof(virtual_Female) = %td\n", (iptr)sizeof(virtual_Female));
	fprintf(stdout, "sizeof(virtual_Child) = %td\n", (iptr)sizeof(virtual_Child));

	fprintf(stderr, "========================================\n");

	auto male = virtual_Male();
	uint offset = *((uint*)*(uptr*)&male + 1);
	double value = ((Person*)((char*)&male + offset))->_value;
	fprintf(stdout, "offset = %td\n", (iptr)offset);
	fprintf(stdout, "parent->_value = %lf\n", value);
}

int main(int argc, char *argv[]) {
	// Test_Constructor();
	Test_Virtual_Inheritance();

	return 0;
}
