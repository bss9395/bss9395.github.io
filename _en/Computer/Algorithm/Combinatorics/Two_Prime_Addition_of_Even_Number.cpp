/* Two_Prime_Addition_of_Even_Number.cpp
Author: bss9395
Update: 2020-09-30T15:20:00+08@China-Guangdong-Zhanjiang+08
Design: Two Prime Addition of Even Number
*/

/*
每一个大于2的偶数都可以由2个素数相加而成，
求组成指定偶数的2个素数差值最小的素数对。
*/


#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool Is_Prime(int numb) {
	for (int i = 2, bound = sqrt(numb); i <= bound; i += 1) {
		if (numb % i == 0) {
			return false;
		}
	}
	return true;
}

void Two_Prime_Addition_of_Even_Number(int number) {
	int distance = number;
	tuple<int, int> ret;
	for (int i = 2, bound = number / 2; i <= bound; i += 1) {
		if (Is_Prime(i) && Is_Prime(number - i)) {
			if (abs(number - i - i) < distance) {
				distance = abs(number - i - i);
				ret = tuple<int, int>(i, number - i);
			}
		}
	}

	int prime_0 = 0;
	int prime_1 = 0;
	std::tie(prime_0, prime_1) = ret;
	fprintf(stdout, "%d %d", prime_0, prime_1);
}

int main(int argc, char* argv[]) {
	int number = 20;
	Two_Prime_Addition_of_Even_Number(number);

	return 0;
}
