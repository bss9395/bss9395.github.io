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
	sequence[0] = 1;
	sequence[1] = 1;

	long long fib0 = sequence[0];
	long long fib1 = sequence[1];
	long long fibi = fib0 + fib1;
	for (int i = 2; i <= n; i += 1) {
		fibi = fib0 + fib1;
		sequence[i] = fibi;
		fib0 = fib1;
		fib1 = fibi;
	}

	if (n < 0) {
		n = 0;
	}
	return sequence[n];
}


int main(int argc, char *argv[]) {
	long long sequence[50];
	Fibonacci_by_Circulation(sequence, 11);

	for (int i = 0; i < 10; i += 1) {
		cerr << sequence[i] << " ";
	}
	cerr << endl;
	return 0;
}