/* Pythagorean_Triple.cpp
Author: BSS9395
Update: 2023-08-14T08:4:00+08@China-Guangdong-Zhanjiang+08
Design: Pythagorean Triple
*/

#include <iostream>
#include <vector>
using namespace std;

typedef      signed __int32    in05;
typedef    unsigned __int32    ui05;
typedef      signed __int64    in06;
typedef    unsigned __int64    ui06;

struct Triple {
	ui06 _a = 0;
	ui06 _b = 0;
	ui06 _c = 0;
	Triple(ui06 a, ui06 b, ui06 c) {
		_a = a;
		_b = b;
		_c = c;
	}
};

class Pythogorean_Triple {
public:
	static auto _Pythogorean_Triple_Range(ui06 range) -> vector<Triple*> {
		vector<Triple *> pytho;
		for (ui06 a = 1; a < range; a += 1) {
			for (ui06 b = a; b < range; b += 1) {
				for (ui06 c = b; c < range; c += 1) {
					if (a * a + b * b == c * c) {
						Triple* triple = new Triple(a, b, c);
						pytho.push_back(triple);
					}
				}
			}
		}
		return pytho;
	}

public:
	static auto _Test_Pythogorean_Triple_Range() -> void {
		vector<Triple*> pytho = _Pythogorean_Triple_Range(20);
		for (int i = 0; i < pytho.size(); i += 1) {
			fwprintf(stdout, L"a == %llu, b == %llu, c == %llu\n", pytho[i]->_a, pytho[i]->_b, pytho[i]->_c);
		}

		for (int i = 0; i < pytho.size(); i += 1) {
			delete pytho[i];
		}
	}
};

int main(int argc, char* argv[]) {
	Pythogorean_Triple::_Test_Pythogorean_Triple_Range();

	return 0;
}
