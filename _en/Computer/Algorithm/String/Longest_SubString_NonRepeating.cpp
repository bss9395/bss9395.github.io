/* Longest_SubString_NonRepeating.cpp
Author: BSS9395
Update: 2023-05-23T01:13:00+08@China-Guangdong-Zhanjiang+08
Design: Loggest SubString NonRepeating
Credit: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-cshi-xian-/
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Longest_SubString_NonRepeating {
public:
	struct Cell {
		int _beg = 0;
		int _idx = 0;
		int _end = 0;
		Cell(int beg, int idx, int end) {
			_beg = beg;
			_idx = idx;
			_end = end;
		}
	};

public:
	static auto _Longest_SubString_Segamentation(const wstring &data) -> int {
		auto longest = (int)0;
		auto cells   = queue<Cell*>{};
		auto cell    = new Cell(0, 0, (int)data.size());
		cells.push(cell);
		while (0 < (int)cells.size()) {
			cell = cells.front(), cells.pop();
			if (cell->_idx < cell->_end) {
				auto idx = cell->_idx, end = cell->_end;
				while (true) {
					while (idx += 1, idx < end && data[cell->_idx] != data[idx]);
					if (idx < end) {  // note: segmentation
						cell->_idx += 1;
						cell->_end = idx;
						cells.push(cell);
						cell = new Cell(idx, idx, end);
					}
					else {           
						cell->_idx += 1;
						cells.push(cell);
						break;
					}
				}
			}
			else {
				auto length = cell->_end - cell->_beg;
				(length <= longest) ? longest : (longest = length);
				delete cell, cell = nullptr;
			}
		}
		return longest;
	}

	static auto _Longest_SubString_Sliding_Map(const wstring& data) -> int {
		if (false == (1 <= data.size())) {
			return 0;
		}
		auto longest = (int)1;
		auto slide = map<wchar_t, int>{};
		auto fore = 0, back = fore + 1;
		for (auto iend = (int)data.size(); back < iend; ) {
			auto jump = slide[data[back]];
			if (fore <= jump) {
				auto length = back - fore;
				(length <= longest) ? longest : (longest = length);
				fore = jump + 1;
			}
			slide[data[back]] = back;
			back += 1;
		}
		auto length = back - fore;
		(length <= longest) ? longest : (longest = length);
		return longest;
	}

	static auto _Longest_SubString_Sliding_Window(const wstring &data) -> int {
		if (false == (1 <= data.size())) {
			return 0;
		}
		auto longest = (int)1;
		auto fore = 0, back = fore + 1;
		for (auto iend = (int)data.size(); back < iend; ) {	
			auto iter = fore;
			for ( ; iter < back && data[iter] != data[back]; iter += 1);
			if (iter < back) {
				auto length = back - fore;
				(length <= longest) ? longest : (longest = length);
				fore = iter + 1;
			}
			back += 1;  // note: fore and back both increase at the same time.
		}
		auto length = back - fore;
		(length <= longest) ? longest : (longest = length);
		return longest;
	}

public:
	static void _Test_Longest_SubString_Segamentation() {
		auto data = L"abcabcbb";
		// auto data = L"";
		auto longest = Longest_SubString_NonRepeating::_Longest_SubString_Segamentation(data);
		fprintf(stdout, "longest=%d\n", longest);
	}
	static void _Test_Longest_SubString_Sliding_Map() {
		auto data = L"abcabcbb";
		// auto data = L"";
		auto longest = Longest_SubString_NonRepeating::_Longest_SubString_Sliding_Map(data);
		fprintf(stdout, "longest=%d\n", longest);
	}
	static void _Test_Longest_SubString_Sliding_Window() {
		auto data = L"abcabcbb";
		// auto data = L"";
		auto longest = Longest_SubString_NonRepeating::_Longest_SubString_Sliding_Window(data);
		fprintf(stdout, "longest=%d\n", longest);
	}
};

int main(int argc, char *argv[]) {
	Longest_SubString_NonRepeating::_Test_Longest_SubString_Segamentation();
	Longest_SubString_NonRepeating::_Test_Longest_SubString_Sliding_Map();
	Longest_SubString_NonRepeating::_Test_Longest_SubString_Sliding_Window();
	
	return 0;
}
