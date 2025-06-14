/* BinarySearch.cpp
Author: BSS9395
Update: 2025-05-27T10:56:00+08@China-ShangHai+08
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int _BinarySearch_Circulation(vector<int>& nums, int target) {
		int fore = 0;
		int back = nums.size();
		while (fore < back) {
			int midd = (fore + back) / 2;
			if (nums[midd] == target) {
				return midd;
			} else if (nums[midd] < target) {
				fore = midd + 1;
			} else {
				back = midd;
			}
		}
		return -1;
	}

	int _BinarySearch_Recursion(vector<int>& nums, int target) {
		return _BinarySearch_Recursion_Entry(nums, target, 0, nums.size());
	}

	int _BinarySearch_Recursion_Entry(vector<int>& nums, int target, int fore, int back) {
		if (fore < back) {
			int midd = (fore + back) / 2;
			if (nums[midd] == target) {
				return midd;
			} else if (nums[midd] < target) {
				return _BinarySearch_Recursion_Entry(nums, target, midd + 1, back);
			} else {
				return _BinarySearch_Recursion_Entry(nums, target, fore, midd);
			}
		}
		return -1;
	}
};

void _Test_BinarySearch_Circulation() {
	vector<int> nums{
		-1, 0, 3, 4, 6, 10, 13, 14
	};
	Solution solution;
	int index = solution._BinarySearch_Circulation(nums, 13);
	cout << index << endl;
}

void _Test_BinarySearch_Recursion() {
	vector<int> nums{
		-1, 0, 3, 4, 6, 10, 13, 14
	};
	Solution solution;
	int index = solution._BinarySearch_Recursion(nums, 13);
	cout << index << endl;
}

int main() {
	_Test_BinarySearch_Circulation();
	_Test_BinarySearch_Recursion();
	return 0;
}
