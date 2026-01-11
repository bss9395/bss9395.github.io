/// Record: Cpp_Literals.cpp
/// Author: bss9395
/// Update: 2025/12/18T00:13:00&+08$+08@China-BeiJing
/// Keepin: bss9395@yeah.net

#include <iostream>
#include <string>

long double operator"" _km(long double km) {
	return km * 1000.0;
}

long double operator"" _m(long double m) {
	return m;
}

long double operator"" _cm(long double cm) {
	return cm / 100.0;
}

void _Test_Literals() {
	auto distance = 42.0_km;  // distance = 42000.0 米
	std::cout << "distance = " << distance << std::endl;
}

int main(int argc, char *argv[]) {
	_Test_Literals();

	return 0;
}
