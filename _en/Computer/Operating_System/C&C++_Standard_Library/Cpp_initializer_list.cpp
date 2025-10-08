/* Cpp_initializer_list.cpp
Author: bss9395
Update: 2025/10/08T11:04:00+08@China-GuangDong-ZhanJiang+08
Keepin: bss9395@yeah.net
*/

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

struct Vector {
	std::vector<long> _head;
	Vector(bool flag, const std::initializer_list<long> &data) {
		for (auto iter = data.begin(); iter != data.end(); ++iter) {
			_head.push_back(*iter);
		}
	}
};

void _Test_initializer_list() {
	std::vector<long> vector0{ {
		(long)1.0, 2, 3
	} };

	Vector vector1(true, {
		(long)1.0, 2, 3
	});
}

int main(int argc, char *argv[]) {
	_Test_initializer_list();

	return 0;
}
