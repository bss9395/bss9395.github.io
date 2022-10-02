/* Max_Number_of_Continuous_Bits.cpp
Author: bss9395
Update: 2022-09-30T16:40:00+08@China-Guangdong-Zhanjiang+08
Design: Max Number of Continuous Bits
*/

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

void Max_Number_of_Continuous_Bits_Regular() {
	int bits = 7;

	int count = 0;
	int max_count = 0;
	while (bits != 0) {
		if (bits & 0x01) {
			count += 1;
		}
		else {
			if (max_count < count) {
				max_count = count;
			}
			count = 0;
		}
		bits >>= 1;
	}
	if (max_count < count) {
		max_count = count;
	}
	fprintf(stdout, "%d\n", max_count);
}

void Max_Number_of_Continuous_Bits() {
	int bits = 7;

	int count = 0;
	while (bits != 0) {
		count += 1;
		bits &= bits << 1;
	}
	fprintf(stdout, "%d\n", count);
}

int main(int argc, char* argv[]) {
	// Max_Number_of_Continuous_Bits_Regular();
	Max_Number_of_Continuous_Bits();

	return 0;
}
