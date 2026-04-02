/* String_Addition.cpp
Author: BSS9395
Update: 2025-04-28T14:56:00+08@China-Guangdong-Zhanjiang+08
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string _Add(string lhs, string rhs) {
		int len1 = lhs.size();
		int len2 = rhs.size();
		while (len1 < len2) {
			lhs = "0" + lhs;
			len1 += 1;
		}
		while (len1 > len2) {
			rhs = "0" + rhs;
			len2 += 1;
		}

		string ans;
		int carry = 0;
		for (int i = len1 - 1; 0 <= i; i -= 1) {
			int temp = (lhs[i] - '0' + rhs[i] - '0' + carry);
			ans += char(temp % 10 + '0');
			carry = temp / 10;
		}
		if (carry) {
			ans += (carry + '0');
		}
		std::reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main(int argc, char *argv[]) {
	Solution solution;
	auto retu = solution._Add("114514", "12345");
	std::cout << retu << std::endl;
	return 0;
}
