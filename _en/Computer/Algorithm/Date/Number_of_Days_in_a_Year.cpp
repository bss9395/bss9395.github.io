/* Number_of_Days_in_a_Year.cpp
Author: bss9395
Update: 2020-09-30T16:08:00+08@China-Guangdong-Zhanjiang+08
Design: Number of Days in a Year
*/

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
	int year = 0;
	int month = 0;
	int day = 0;
	cin >> year;
	cin >> month;
	cin >> day;

	int date[] = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	int sum = 0;
	for (int i = 0; i < month - 1; i += 1) {
		sum += date[i];
	}
	sum += day;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		if (2 < month) {
			sum += 1;
		}
	}
	cout << sum;

	return 0;
}
