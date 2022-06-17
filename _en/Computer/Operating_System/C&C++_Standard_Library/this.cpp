/* this.cpp
Author: BSS9395
Update: 2022-06-15T21:56:00+08@China-Shanghai+08
Design: C++ Keyword: this
*/

#include <iostream>
#include <string>

class This {
public:
	double _value = 0.0;

public:
	This() {
		_value = 123.456;
	}

public:
	void _Print() {
		fprintf(stderr, "%s\n", __FUNCTION__);
		if (this == nullptr) {
			fprintf(stderr, "if (this == nullptr) {""\n");
			return;
		}
		fprintf(stdout, "_value == %lf\n", _value);
	}
};

int main(int argc, char* argv[]) {
	This()._Print();
	((This*)nullptr)->_Print();

	return 0;
}
