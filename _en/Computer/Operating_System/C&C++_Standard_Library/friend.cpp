/* friend.cpp
Author: BSS9395
Update: 2022-06-15T23:21:00+08@China-Shanghai+08
Design: C++ Keyword: friend
*/

#include <iostream>

class Access;
class Friend_Function {
public:
	Friend_Function() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}

	virtual ~Friend_Function() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}

public:
	void _Print_Access(Access& access);         // note: friend class member function needs forward declaration.
};

class Access {
	friend class Friend_Class;
	friend void Friend_Function::_Print_Access(Access &);

private:
	double _value = 0.0;

public:
	Access() {
		fprintf(stderr, "%s\n", __FUNCTION__);
		_value = 123.456;
	}

	virtual ~Access() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}
};

class Friend_Class {
public:
	Friend_Class() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}

	virtual ~Friend_Class() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}

public:
	void _Print_Access(Access &access) {
		fprintf(stderr, "%s\n", __FUNCTION__);
		fprintf(stdout, "access._value == %lf\n", access._value);
	}
};

void Friend_Function::_Print_Access(Access& access) {
	fprintf(stderr, "%s\n", __FUNCTION__);
	fprintf(stdout, "access._value == %lf\n", access._value);
}

int main(int argc, char* argv[]) {
	Access access = Access();
	Friend_Class()._Print_Access(access);
	Friend_Function()._Print_Access(access);

	return 0;
}