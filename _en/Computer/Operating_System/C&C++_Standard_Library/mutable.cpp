/* mutable.cpp
Author: BSS9395
Update: 2022-06-15T22:51:00+08@China-Shanghai+08
Design: C++ Keyword: mutable
*/

#include <iostream>

class Mutable {
public:
	double _value = 0.0;
	mutable double _mutable = 0.0;

public:
	Mutable() {
		fprintf(stderr, "%s\n", __FUNCTION__);
		_value = 0.1;
		_mutable = 1.0;
	}

	virtual ~Mutable() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}

public:
	void _Print() {
		fprintf(stderr, "%s\n", "void _Print() {");
		_value = 0.2;
		_mutable = 2.0;
	}

	void _Print() const {
		fprintf(stderr, "%s\n", "void _Print() const {");
		// _value = 0.3;                                   // note: can't change regular object in const member function.
		_mutable = 3.0;
	}
};

void Test_Mutable() {
	Mutable muta = Mutable();
	muta._value = 0.4;
	muta._mutable = 4.0;
	muta._Print();

	/// ////////////////////////////////

	const Mutable cons = Mutable();
	// cons._value = 0.5;            // note: can't change regulat object in const object.
	cons._mutable = 5.0;
	cons._Print();
}

int main(int argc, char* argv[]) {
	Test_Mutable();

	return 0;
}