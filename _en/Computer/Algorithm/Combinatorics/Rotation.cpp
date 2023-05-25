/* Rotation.cpp
Author: BSS9395
Update: 2023-05-22T00:11:00+08@China-Guangdong-Zhanjiang+08
Design: Rotation
*/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Rotation {
public:
	static auto _Spin_Left(wstring& data, int offset) -> void {
		auto size = (int)data.size();
		data.resize(data.size() + offset);
		for (auto i = 0; i < offset; i += 1) {
			data[size + i] = data[i];
		}
		for (auto i = 0; i < size; i += 1) {
			data[i] = data[i + offset];
		}
		data.resize(size);
	}
	static auto _Spin_Right(wstring& data, int offset) -> void {
		_Spin_Left(data, (int)data.size() - offset);
	}
	static auto _Test_Spin() {
		auto data_left = wstring(L"1234567890");
		Rotation::_Spin_Left(data_left, 2);
		fwprintf(stdout, L"%ls\n", &data_left[0]);

		auto data_right = wstring(L"1234567890");
		Rotation::_Spin_Right(data_right, 2);
		fwprintf(stdout, L"%ls\n", &data_right[0]);
	}
};


int main(int argc, char* argv[]) {
	Rotation::_Test_Spin();

	return 0;
}
