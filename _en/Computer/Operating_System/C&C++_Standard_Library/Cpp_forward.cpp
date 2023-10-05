/* Cpp_forward.cpp 
Author: BSS9395
Update: 2023-10-05T09:23:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: forward
*/

#include <utility>    
#include <iostream>     

void _Overloaded(const int& x) {
	std::cout << "[lvalue]"; 
}
void _Overloaded(int&& x) { 
	std::cout << "[rvalue]"; 
}

template <class T> void fn(T&& x) {
	_Overloaded(x);                   // note: always an lvalue
	_Overloaded(std::forward<T>(x));  // note: rvalue if argument is rvalue
}

int main() {
	int a;
	std::cout << "calling fn with lvalue: ";
	fn(a);
	std::cout << '\n';

	std::cout << "calling fn with rvalue: ";
	fn(0);
	std::cout << '\n';

	return 0;
}