/* Linear_Equation_Set.cpp
Author: BSS9395
Update: 2023-06-15T17:11:00+08@China-Beijing+08
Design: Linear Equation Set
*/

#define _CRT_SECURE_NO_WARNINGS	
#define _CRT_NON_CONFORMING_SWPRINTFS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Linear_Equation_Set {
public:
	struct Variable {
		int _x = 0;
		int _y = 0;
		int _z = 0;
		Variable(int x, int y, int z) {
			_x = x;
			_y = y;
			_z = z;
		}
		auto _Into_WString() -> wstring {
			wstring buffer = wstring{};
			buffer.resize(64);
			int count = swprintf(&buffer[0], L"[%d, %d, %d]", _x, _y, _z);
			buffer.resize(count);
			return buffer;
		}
	};

public:
	/*
	钢笔3元每支，圆珠笔2元每支，铅笔0.5元每支，现有100元买100支笔，钢笔、圆珠笔、铅笔各可以买几支？
	x       + y       + z       = 100;
	x * 3.0 + y * 2.0 + z * 0.5 = 100; 
	*/
	static auto _Ternary_Linear_Equation(int amount = 100, double money = 100.0, double price_pen = 3.0, double price_ballpen = 2.0, double price_pencil = 0.5) -> vector<Variable*> {
		vector<Variable*> solution = vector<Variable*>{};
		for (int beg_x = 0, end_x = (int)(money / price_pen); beg_x <= end_x; beg_x += 1) {
			for (int beg_y = 0, end_y = (int)(money / price_ballpen); beg_y <= end_y; beg_y += 1) {
				for (int beg_z = 0, end_z = (int)(money / price_pencil); beg_z <= end_z; beg_z += 1) {
					if (beg_x + beg_y + beg_z == amount && beg_x * price_pen + beg_y * price_ballpen + beg_z * price_pencil == money) {
						solution.push_back(new Variable(beg_x, beg_y, beg_z));
					}
				}
			}
		}
		return solution;
	}

public:
	static auto _Test_Ternary_Linear_Equation() -> void {
		auto solution = _Ternary_Linear_Equation();
		for (int i = 0, size = (int)solution.size(); i < size; i += 1) {
			fwprintf(stdout, L"%ls\n", solution[i]->_Into_WString().data());
		}
	}
};

int main(int argc, char* argv[]) {
	Linear_Equation_Set::_Test_Ternary_Linear_Equation();

	return 0;
}
