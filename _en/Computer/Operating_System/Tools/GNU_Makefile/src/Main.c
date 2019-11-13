#include "add.h"
#include "sub.h"
#include <stdio.h>

int main() {
	int lhs = 11;
	int rhs = 12;

	printf("lhs + rhs = %d \n", add(lhs, rhs));
	printf("lhs - rhs = %d \n", sub(lhs, rhs));

	return 0;
}