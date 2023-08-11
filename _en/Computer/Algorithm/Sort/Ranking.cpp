/* Ranking.cpp
Author: BSS9395
Update: 2023-08-09T15:17:00+08@China-Guangdong-Zhanjiang+08
Design: Ranking
*/

#include <functional>
using namespace std;

class Ranking {
public:
	static auto _Ascending_Nth(vector<int>& data, int Nth) -> int {
		auto rank = vector<int>();
		rank.resize(Nth + 1);

		int leng = 0;
		for (int i = 0, size = (int)data.size(); i < size; i += 1) {
			int idx = leng;
			while (0 < idx && data[i] < rank[idx - 1]) {
				idx -= 1;
			}

			for (int j = leng; idx < j; j -= 1) {
				rank[j] = rank[j - 1];
			}
			rank[idx] = data[i];

			(leng < Nth) ? (leng += 1) : leng;
		}

		return rank[Nth - 1];
	}

	static auto _Descending_Nth(vector<int>& data, int Nth) -> int {
		auto rank = vector<int>();
		rank.resize(Nth + 1);

		int leng = 0;
		for (int i = 0, size = (int)data.size(); i < size; i += 1) {
			int idx = leng;
			while (0 < idx && data[i] > rank[idx - 1]) {
				idx -= 1;
			}

			for (int j = leng; idx < j; j -= 1) {
				rank[j] = rank[j - 1];
			}
			rank[idx] = data[i];

			(leng < Nth) ? (leng += 1) : leng;
		}

		return rank[Nth - 1];
	}

public:
	static auto _Test_Ascending_Nth() -> void {
		auto data = vector<int>{
			// 5, 13, 21, 32, 32, 41, 45, 67, 68, 71, 99, 100
			5, 100, 32, 45, 21, 67, 32, 68, 41, 99, 13, 71
		};
		auto nth = _Ascending_Nth(data, 3);
		fwprintf(stdout, L"ascending 3th = %d\n", nth);
	}

	static auto _Test_Descending_Nth() -> void {
		auto data = vector<int>{
			// 5, 13, 21, 32, 32, 41, 45, 67, 68, 71, 99, 100
			5, 100, 32, 45, 21, 67, 32, 68, 41, 99, 13, 71
		};
		auto nth = _Descending_Nth(data, 3);
		fwprintf(stdout, L"ascending 3th = %d\n", nth);
	}
};

int main(int argc, char* argv[]) {
	// Sorted_Nth::_Test_Ascending_Nth();
	Sorted_Nth::_Test_Descending_Nth();

	return 0;
}
