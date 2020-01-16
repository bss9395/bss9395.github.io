/*Acended_Nth.cpp
* Author: BSS9395
* Update: 2020-01-17T00:07:00+08@ShenZhen+08
* Algorithm: Insertion_Sort
*/

#include <iostream>
using std::cout;
using std::endl;

template<typename Value>
Value Ascended_Nth(Value data[], int length, int Nth) {
	Value *rank = (Value *)malloc(Nth * sizeof(Value));
	int len = 0;


	for (int i = 0; i < length; i += 1) {
		int idx = len;
		while (0 < idx && rank[idx - 1] > data[i]) {
			idx -= 1;
		}

		if (idx < Nth) {
			for (int j = Nth - 1; idx < j; j -= 1) {
				rank[j] = rank[j - 1];
			}
			rank[idx] = data[i];

			if (len < Nth) {
				len += 1;
			}
		}
	}

	// for (int i = 0; i < Nth; i += 1) {
	// 	cout << rank[i] << "  ";
	// }
	// cout << endl;

	Value ret = rank[Nth - 1];
	free(rank);
	return ret;
}


int main(int argc, char *argv[]) {
	int data[] = { 5, 100, 32, 45, 21, 67, 32, 68, 41, 99, 13, 71 };
	int length = sizeof(data) / sizeof(data[0]);

	int Nth = Ascended_Nth(data, length, 3);
	cout << Nth << endl;
	return 0;
}