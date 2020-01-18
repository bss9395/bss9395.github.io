/*Fibonacci_Sequence.cpp
*/

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

long long Fibonacci_by_Recursion(long long sequence[], int n) {
	if (n <= 0) {
		sequence[0] = 1;
		return sequence[0];
	}
	else if (n == 1) {
		sequence[1] = 1;
		return sequence[1];
	}

	sequence[n] = Fibonacci_by_Recursion(sequence, n - 1) + Fibonacci_by_Recursion(sequence, n - 2);
	return sequence[n];
}

long long Fibonacci_by_Circulation(long long sequence[], int n) {
	int i = 0;
	while (true) {
		if (i >= n) {
			break;
		}

		if (i <= 0) {
			sequence[0] = 1;
		}
		else if (i == 1) {
			sequence[1] = 1;
		}
		else {
			sequence[i] = sequence[i - 1] + sequence[i - 2];
		}

		i += 1;
	}
	return sequence[n];
}

int main(int argc, char *argv[]) {
	long long sequence[50] = { 0 };
	Fibonacci_by_Circulation(sequence, 11);

	for (int i = 0; i < 10; i += 1) {
		cerr << sequence[i] << " ";
	}
	cerr << endl;
	return 0;
}