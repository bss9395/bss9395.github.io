/* operator_Dereference.cpp
Author: BSS9395
Update: 2022-06-16T15:09:00+08@China-Shanghai+08
Design: C++ Language Feature: operator*() and operator->()
*/

#include <iostream>

class Dereference {
public:
	Dereference() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}

	virtual ~Dereference() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}

public:
	void _Print() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}
};

class Operator_Dereference {
public:
	Dereference _reference = Dereference();

public:
	Operator_Dereference() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}

	virtual ~Operator_Dereference() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}

public:
	Dereference& operator *() {
		fprintf(stderr, "%s\n", __FUNCTION__);
		return _reference;
	}

	Dereference* operator->() {
		fprintf(stderr, "%s\n", __FUNCTION__);
		return &_reference;
	}
};

void Test_Operator_Dereference() {
	Operator_Dereference operator_dereference = Operator_Dereference();
	(*operator_dereference)._Print();
	operator_dereference->_Print();
}

void Test_Dereference() {
	Operator_Dereference* operator_dereference = new Operator_Dereference();
	(**operator_dereference)._Print();
	(*operator_dereference)->_Print();
	delete operator_dereference;
}

int main(int argc, char* argv[]) {
	// Test_Operator_Dereference();
	Test_Dereference();

	return 0;
}
