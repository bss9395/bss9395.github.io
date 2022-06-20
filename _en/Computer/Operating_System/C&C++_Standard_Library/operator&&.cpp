/* operator&&.cpp
Author: BSS9395
Update: 2022-06-20T00:32:00+08@China-Shanghai+08
Design: C++ Language Feature: operator&&()
*/

#include <iostream>
#include <string>

class Complex {
public:
	double _real = 0.0;
	double _imag = 0.0;

public:
	Complex(double real, double imag) {
		_real = real;
		_imag = imag;
	}

	Complex& operator+=(const Complex& complex) {
		_real += complex._real;
		_imag += complex._imag;
		return (*this);
	}

	bool operator&&(Complex& complex) {
		return (_real != 0.0 && _imag != 0.0);
	}
};

void Test_operator_and() {
	auto lhs = Complex(0, 1);
	auto rhs = Complex(1, 2);
	bool result = lhs && (lhs += rhs);  // note: lhs.operator&&(lhs.operator+=(rhs))
	if (result == true) {
		fprintf(stdout, "lhs && (lhs += rhs) == true\n");
	}
	else {
		fprintf(stdout, "lhs && (lhs += rhs) == false\n");
	}
}

int main(int argc, char* argv[]) {
	Test_operator_and();

	return 0;
}
