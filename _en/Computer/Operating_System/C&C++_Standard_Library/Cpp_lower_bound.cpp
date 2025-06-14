/* Cpp_lower_bound.cpp
Author: BSS9395
Update: 2025-05-25T18:11:00+08@China-ShangHai+08
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> values = {
		10, 20, 30, 30, 20, 10, 10, 20
	};
	sort(values.begin(), values.end());  // [10, 10, 10, 20, 20, 20, 30, 30]
	auto low = lower_bound(values.begin(), values.end(), 15);
	auto up = upper_bound(values.begin(), values.end(), 25);
	cout << "lower_bound at position: " << (low - values.begin()) << endl;
	cout << "upper_cound at position: " << (up - values.begin()) << endl;

	return 0;
}
