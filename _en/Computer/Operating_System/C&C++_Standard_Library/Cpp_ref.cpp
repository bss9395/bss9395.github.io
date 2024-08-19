/* Cpp_ref.cpp
Author: bss9395
Update: 2024-07-24T23:18:23+08@China-Beijing+08
Design: C++ Standard Library
*/

#include <iostream>
#include <functional>

void _Func(int& a, int& b) {
	std::cout << "&a = " << (&a) << ", a = " << a << ", &b = " << (&b) << ", b = " << b << std::endl;
	a += 1;
	b += 10;
}

int main(int argc, char* argv[]) {
	int a = 1;
	int b = 10;
	int& ra = a;
	std::function<void()> func = std::bind(_Func, ra, std::ref(b));
	func();
	std::cout << "&a = " << (&a) << ", a = " << a << ", &b = " << (&b) << ", b = " << b << std::endl;
	func();
	std::cout << "&a = " << (&a) << ", a = " << a << ", &b = " << (&b) << ", b = " << b << std::endl;

	return 0;
}
