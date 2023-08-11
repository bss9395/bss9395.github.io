/* Backspace.cpp
Author: BSS9395
Update: 2023-08-09T09:11:00+08@China-Guangdong-Zhanjiang+08
Design: String Backspace
*/

#include <string>
using namespace std;

class String {
public:
	static auto _Backspace(const wstring& data, wchar_t back = L'\b') -> wstring {
		auto reduce = wstring();
		for (int i = 0; i < data.size(); i += 1) {
			if (data[i] != back) {
				reduce.push_back(data[i]);
			}
			else if (1 <= reduce.size()) {
				reduce.pop_back();
			}
		}
		return reduce;
	}

public:
	static auto _Test_Backspace() -> void {
		auto data = L"ABYYYYCYDDY";
		auto back = L'Y';
		auto reduce = _Backspace(data, back);
		fwprintf(stdout, L"reduce = %s\n", reduce.c_str());
	}
};

int main(int argc, char* argv[]) {
	String::_Test_Backspace();

	return 0;
}
