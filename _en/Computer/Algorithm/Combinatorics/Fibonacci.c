/* Fibonacci.c
Author: BSS9395
Update: 2020-11-01T07:18:00+08@China-Guangdong-Zhanjiang+08
Design: Fibonacci Sequence
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

long Fibonacci(long n) {
	long fib0 = 0;
	long fib1 = 1;
	long temp = 0;

	while (n -= 1, 0 <= n) {
		temp = fib1;
		fib1 = fib0 + fib1;
		fib0 = temp;
	}

	return fib0;
}

long Fibonacci_Iteration(long n) {
	long fib0 = 0;
	long fib1 = 1;

	while (n -= 1, 0 <= n) {
		fib1 = fib0 + fib1;
		fib0 = fib1 - fib0;
	}

	return fib0;
}

long Fibonacci_Recursion(long sequence[], int n) {
	if (n <= 0) {
		sequence[0] = 0;
		return sequence[0];
	}
	else if (n == 1) {
		sequence[1] = 1;
		return sequence[1];
	}

	sequence[n] = Fibonacci_Recursion(sequence, n - 1) + Fibonacci_Recursion(sequence, n - 2);
	return sequence[n];
}

long Fibonacci_Circulation(long sequence[], int n) {
	int i = 0;
	while (true) {
		if (i >= n) {
			break;
		}

		if (i <= 0) {
			sequence[0] = 0;
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

void Test_Fibonacci() {
	long sequence[50] = { 0 };
	Fibonacci_Circulation(sequence, 11);

	for (int i = 0; i < 10; i += 1) {
		fprintf(stdout, "%ld, ", sequence[i]);
	}
	fprintf(stdout, "\n");
}

int main(int argc, char *argv[]) {
	Test_Fibonacci();

	return 0;
}