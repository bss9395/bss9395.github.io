/*BinaryInsertionSort.cpp
* Author: BSS9395
* Update: 2020-01-17T12:11:00+08@ShenZhen+08
* Algorithom: Binary_Insertion_Sort
*/

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

template<typename Value>
void BinaryInsertionSort_Ascending(Value data[], int length) {
	for (int i = 0; i < length; i += 1) {
		Value tmp = data[i];
		int beg = 0;
		int end = i;
		int mid = beg;

		while (beg < end) {
			mid = (beg + end) / 2;
			if (tmp < data[mid]) {
				end = mid;
			}
			else {
				beg = mid + 1;
			}
		}

		for (int j = i; end < j; j -= 1) {
			data[j] = data[j - 1];
		}
		data[end] = tmp;
	}
}

template<typename Value>
void BinaryInsertionSort_Descending(Value data[], int length) {
	for (int i = 0; i < length; i += 1) {
		Value tmp = data[i];
		int beg = 0;
		int end = i;
		int mid = beg;

		while (beg < end) {
			mid = (beg + end) / 2;
			if (tmp > data[mid]) {
				end = mid;
			}
			else {
				beg = mid + 1;
			}
		}

		for (int j = i; end < j; j -= 1) {
			data[j] = data[j - 1];
		}
		data[end] = tmp;
	}
}

int main(int argc, char *argv[]) {
	int data[] = { 1, 3, 4, 5, 7, 9, 0, 8, 2, 6 };
	int length = sizeof(data) / sizeof(data[0]);
	BinaryInsertionSort_Ascending(data, length);

	for (int i = 0; i < length; i += 1) {
		cout << data[i] << "  ";
	}
	cout << endl;

	getchar();
	return 0;
}