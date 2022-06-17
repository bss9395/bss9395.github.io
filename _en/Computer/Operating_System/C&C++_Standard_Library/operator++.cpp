/* operator++.cpp
Author: BSS9395
Update: 2022-06-16T10:51:00+08@China-Shanghai+08
Design: C++ Language Feature: operator++()
*/

#include <iostream>
using namespace std;

class Operator_Plus_Plus {
	friend ostream &operator<<(ostream &os, const Operator_Plus_Plus &oper) {
		os << oper._value;
		return os;
	}

public:
	double _value = 0.0;

public:
	Operator_Plus_Plus() {
		_value = 12.0;
	}

	Operator_Plus_Plus& operator++() {    // pre-increment operator.
		_value += 1.0;
		return (*this);
	}

	Operator_Plus_Plus operator++(int) {  // post-increment operator.
		Operator_Plus_Plus temp = Operator_Plus_Plus(*this);
		_value += 1.0;
		return temp;
	}
};

void Test_Operator_Plus_Plus() {
	Operator_Plus_Plus oper = Operator_Plus_Plus();
	cout << oper++ << endl;
	cout << ++oper << endl;
}

void Test_Double_Plus_Plus() {
	Operator_Plus_Plus oper = Operator_Plus_Plus();
	cout << (oper++)++ << endl;     // note: actually the original object increases by 1 not 2.
	cout << ++(++oper) << endl;
}

int main(int argc, char* argv[]) {
	// Test_Operator_Plus_Plus();
	Test_Double_Plus_Plus();

	return 0;
}
