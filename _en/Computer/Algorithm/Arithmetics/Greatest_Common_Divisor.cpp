/* Greatest_Common_Divisor.cpp
Author: BSS9395
Update: 2023-08-13T21:46:00+08@China-Guangdong-Zhanjiang+08
Design: Greated Common Divisor
*/

#include <iostream>
#include <functional>
using namespace std;

class Common_Divisor {
	typedef      signed __int32    in05;
	typedef    unsigned __int32    ui05;
	typedef      signed __int64    in06;
	typedef    unsigned __int64    ui06;

public:
	static auto _Greatest_Common_Divisor_Brute_Force(ui06 lhs, ui06 rhs) -> ui06 {
		ui06 mini = (lhs < rhs) ? lhs : rhs;
		for (int gcd = mini; 1 <= gcd; gcd -= 1) {
			if (lhs % gcd == 0 && rhs % gcd == 0) {
				return gcd;
			}
		}
		return 1;
	}

	static auto _Greatest_Common_Divisor_Recursion(ui06 lhs, ui06 rhs) -> ui06 {
		static function<ui06(ui06, ui06)> __Greatest_Common_Divisor_Recursion = [](ui06 lhs, ui06 rhs) ->ui06 {
			ui06 mod = lhs % rhs;
			if (mod == 0) {
				return rhs;
			}
			return __Greatest_Common_Divisor_Recursion(rhs, mod);
		};

		return __Greatest_Common_Divisor_Recursion(lhs, rhs);
	}

	static auto _Greatest_Common_Divisor_Cirlation(ui06 lhs, ui06 rhs) -> ui06 {
		ui06 mod = 0;
		while ((mod = lhs % rhs) != 0) {
			lhs = rhs;
			rhs = mod;
		}
		return rhs;
	}

public:
	static auto _Test_Greatest_Common_Divisor_Brute_Force() -> void {
		ui06 lhs = 6;
		ui06 rhs = 15;
		ui06 gcd = _Greatest_Common_Divisor_Brute_Force(lhs, rhs);
		fwprintf(stdout, L"gcd(%llu, %llu) = %llu", lhs, rhs, gcd);
	}

	static auto _Test_Greatest_Common_Divisor_Recursion() -> void {
		ui06 lhs = 6;
		ui06 rhs = 15;
		ui06 gcd = _Greatest_Common_Divisor_Recursion(lhs, rhs);
		fwprintf(stdout, L"gcd(%llu, %llu) = %llu", lhs, rhs, gcd);
	}

	static auto _Test_Greatest_Common_Divisor_Cirlation() -> void {
		ui06 lhs = 6;
		ui06 rhs = 15;
		ui06 gcd = _Greatest_Common_Divisor_Cirlation(lhs, rhs);
		fwprintf(stdout, L"gcd(%llu, %llu) = %llu", lhs, rhs, gcd);
	}
};

int main(int argc, char* argv[]) {
	Common_Divisor::_Test_Greatest_Common_Divisor_Brute_Force();
	// Common_Divisor::_Test_Greatest_Common_Divisor_Recursion();
	// Common_Divisor::_Test_Greatest_Common_Divisor_Cirlation();

	return 0;
}
