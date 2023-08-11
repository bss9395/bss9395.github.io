/* Narcissistic_Number.cpp
Author: BSS9395
Update: 2023-08-09T12:10:00+08@China-Guangdong-Zhanjiang+08
Design: Narcissistic Number
*/

#include <functional>
using namespace std;

class Narcissistic_Number {
public:
	/* Narcissistic Number
	153г╜1**3гл5**3гл3**3
	*/
	static auto _Narcissistic_Number_Decompose() -> vector<unsigned int> {
		auto narcissistic = vector<unsigned int>();
		for (int number = 100; number < 1000; number += 1) {
			auto i = number / 100 % 10;
			auto j = number / 10 % 10;
			auto k = number / 1 % 10;
			if (number == i * i * i + j * j * j + k * k * k) {
				narcissistic.push_back(number);
			}
		}
		return narcissistic;
	}

	static auto _Narcissistic_Number_Bits() -> vector<unsigned int> {
		auto narcissistic = vector<unsigned int>();
		for (int i = 1; i < 10; i += 1) {
			for (int j = 0; j < 10; j += 1) {
				for (int k = 0; k < 10; k += 1) {
					auto number = i * 100 + j * 10 + k;
					if (number == i * i * i + j * j * j + k * k * k) {
						narcissistic.push_back(number);
					}
				}
			}
		}
		return narcissistic;
	}

public:
	static auto _Test_Narcissistic_Number_Decompose() -> void {
		auto narcissistic = _Narcissistic_Number_Decompose();
		for (int i = 0; i < narcissistic.size(); i += 1) {
			(i == 0) ? fwprintf(stdout, L"%lu", narcissistic[i]) : fwprintf(stdout, L", %lu", narcissistic[i]);
		}
	}

	static auto _Test_Narcissistic_Number_Bits() -> void {
		auto narcissistic = _Narcissistic_Number_Bits();
		for (int i = 0; i < narcissistic.size(); i += 1) {
			(i == 0) ? fwprintf(stdout, L"%lu", narcissistic[i]) : fwprintf(stdout, L", %lu", narcissistic[i]);
		}
	}
};

int main(int argc, char* argv[]) {
	Narcissistic_Number::_Test_Narcissistic_Number_Decompose();
	// Narcissistic_Number::_Test_Narcissistic_Number_Bits();

	return 0;
}
