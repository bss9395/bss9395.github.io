/* Cpp_Compare_Version.cpp
Author: bss9395
Update: 2025/10/01T18:46:00+08@China-GuangDong-ZhanJiang+08
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int _Compare_Version(string &version1, string &version2) {
		bool flag1 = false;
		bool flag2 = false;
		for (int i = 0, j = 0, n1 = version1.size(), n2 = version2.size(); (i < n1 || j < n2) && flag1 == false && flag2 == false; ) {
			long long num1 = 0;
			while (i < n1) {
				if ('0' <= version1[i] && version1[i] <= '9') {
					num1 = num1 * 10 + (version1[i] - '0');
					i += 1;
				} else {
					if (version1[i] == '.') {
						i += 1;
					} else {
						flag1 = true;
					}
					break;
				}
			}
			long long num2 = 0;
			while (j < n2) {
				if ('0' <= version2[j] && version2[j] <= '9') {
					num2 = num2 * 10 + (version2[j] - '0');
					j += 1;
				} else  {
					if (version2[j] == '.') {
						j += 1;
					} else {
						flag2 = true;
					}
					break;
				}
			}
			if (num1 < num2) {
				return -1;
			} else if (num1 > num2) {
				return +1;
			}
		}
		return 0;
	}
};

int main() {
	string version1 = "11.8.12";
	string version2 = "11.8.12.34";
	int compare = Solution()._Compare_Version(version1, version2);
	std::cout << compare << std::endl;

	return 0;
}
