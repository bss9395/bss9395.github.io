/* Quadratic_Sum.cpp
Author: BSS9395
Update: 2023-06-18T10:30:00+08@China-Beijing+08
Design: Quadratic Sum
*/

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Quadratic_Sum {
public:
	static auto _Quadratic_Sum_Two(int inte = 25) -> void {
		int inte_sqrt = (int)sqrt(inte);
		for (int x0 = 1; x0 <= inte_sqrt; x0 += 1) {
			for (int x1 = x0; x1 <= inte_sqrt; x1 += 1) {
				if (x0 * x0 + x1 * x1 == inte) {
					fwprintf(stdout, L"25 = %2d * %2d + %2d * %2d\n", x0, x0, x1, x1);
				}
			}
		}
	}

public:
	static auto _Test_Quadratic_Sum_Two() -> void {
		Quadratic_Sum::_Quadratic_Sum_Two();
	}
};

int main(int argc, char* argv[]) {
	Quadratic_Sum::_Test_Quadratic_Sum_Two();

	return 0;
}
