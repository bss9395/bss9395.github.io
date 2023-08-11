/* Factorial.cpp
Author: BSS9395
Update: 2023-08-09T11:01:00+08@China-Guangdong-Zhanjiang+08
Design: Factorial
*/

#include <functional>
using namespace std;

class Factorial {
	typedef      signed __int32    in05;
	typedef    unsigned __int32    ui05;
	typedef      signed __int64    in06;
	typedef    unsigned __int64    ui06;

public:
	static auto _Factorial_Recursion(ui06 steps) -> ui06 {
		function<ui06(ui06)> __Factorial_Recursion = [&__Factorial_Recursion](ui06 steps) -> ui06 {
			if (steps <= 1) {
				return 1;
			}
			return steps * __Factorial_Recursion(steps - 1);
		};
		return __Factorial_Recursion(steps);
	}

	static auto _Factorial_Circulation(ui06 steps) -> ui06 {
		ui06 factorial = 1;
		for (int step = 1; step <= steps; step += 1) {
			factorial = factorial * step;
		}
		return factorial;
	}

	/*
	f(n) = 1/n! + 1/(n-1)! + ... + 1/1!
	*/
	static auto _Series_Factorial(ui06 steps) -> double {
		double series = 0.0;
		ui06 factorial = 1;
		for (int step = 1; step <= steps; step += 1) {
			factorial = factorial * step;
			series += 1.0 / factorial;
		}
		return series;
	}

public:
	static auto _Test_Factorial_Recursion() -> void {
		auto factorial = _Factorial_Recursion(5);
		fwprintf(stdout, L"factorial = %llu\n", factorial);
	}

	static auto _Test_Factorial_Circulation() -> void {
		auto factorial = _Factorial_Circulation(5);
		fwprintf(stdout, L"factorial = %llu\n", factorial);
	}

	static auto _Test_Series_Factorial() -> void {
		auto series = _Series_Factorial(5);
		fwprintf(stdout, L"factorial = %lf\n", series);
	}
};

int main(int argc, char* argv[]) {
	// Factorial::_Test_Factorial_Recursion();
	// Factorial::_Test_Factorial_Circulation();
	Factorial::_Test_Series_Factorial();

	return 0;
}
