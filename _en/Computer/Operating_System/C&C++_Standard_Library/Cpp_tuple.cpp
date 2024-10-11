/* Cpp_tuple.cpp
Author: BSS9395
Update: 2023-10-05T10:44:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: tuple
*/

#include <iostream>
#include <tuple>
#include <string>

std::tuple<int, double, std::string> _Func() {
	return std::make_tuple(1, 2.3, "456");
}

int main() {
	int x = 0;
	double y = 0.0;
	std::string z = "";
	std::tie(x, y, z) = _Func();
	std::cout << x << ", " << y << ", " << z << std::endl;
	return 0;
}
