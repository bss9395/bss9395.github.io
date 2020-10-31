/* Math.c
Author: BSS9395
Update: 2020-11-01T07:18:00+08@China-Guangdong-Zhanjiang+08
Design: Math Library
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The Properties of Greatest Common Divisor
gcd(lhs, rhs) = gcd(rhs, lhs)
gcd(lhs, gcd(mid, rhs)) = gcd(gcd(lhs, mid), rhs)

# 0 <= lhs && 0 <= rhs
gcd(lhs, lhs) = lhs                  # lhs == rhs
gcd(lhs, rhs) = gcd(lhs - rhs, rhs)  # lhs >= rhs
gcd(lhs, rhs) = gcd(lhs, rhs - lhs)  # lhs <= rhs
*/

/* Greatest Common Divisor and Least Common Multiple
rema = lhs - rhs * quot
lhs * rhs = gcd * lcm

lhs  rhs  quot  rema  gcd  lcm
 12   10     1     2    2   60
-12   10    -1    -2    2  -60
 12  -10    -1     2    2  -60
-12  -10     1    -2   -2   60

 10   12     0    10    2   60
-10   12     0   -10    2  -60
 10  -12     0    10    2  -60
-10  -12     0   -10   -2   60

  0   10     0     0   10    0
 10    0     ?     ?   10    0
  0  -10     0     0  -10    0
-10    0     ?     ?  -10    0
*/
long GCD(long x, long y) {
	int sign = (x <= 0 && y <= 0) ? -1 : +1;
	(x < 0) ? (x = -x) : (x);
	(y < 0) ? (y = -y) : (y);

	if (y) {
		while ((x %= y) && (y %= x));
	}
	return sign * (x + y);
}

long GCD_Classic(long x, long y) {
	int sign = (x <= 0 && y <= 0) ? -1 : +1;
	(x < 0) ? (x = -x) : (x);
	(y < 0) ? (y = -y) : (y);

	long gcd = x;
	while (y) {
		gcd = y;
		y = x % y;
		x = gcd;
	}
	return sign * gcd;
}

long GCD_Recursion(long x, long y) {
	static bool check = true;
	static int sign = +1;
	if (check) {
		sign = (x <= 0 && y <= 0) ? -1 : +1;
		(x < 0) ? (x = -x) : (x);
		(y < 0) ? (y = -y) : (y);
		check = false;
	}

	if (y == 0) {
		check = true;
		return sign * x;
	}
	return GCD_Recursion(y, x % y);
}

long GCD_Reduction(long x, long y) {
	static bool check = true;
	static int sign = +1;
	if (check) {
		sign = (x <= 0 && y <= 0) ? -1 : +1;
		(x < 0) ? (x = -x) : (x);
		(y < 0) ? (y = -y) : (y);
		check = false;
	}

	if (x > y) {
		return GCD_Reduction(x - y, y);
	}
	else if (x < y) {
		return GCD_Reduction(x, y - x);
	}
	check = true;
	return sign * x;
}

long LCM(long x, long y) {
	long gcd = GCD(x, y);
	return ((x * y) / gcd);
}

void Test_GCD_LCM() {
#define GCD GCD_Recursion
	fprintf(stdout, "%ld, ", GCD(12, 10));
	fprintf(stdout, "%ld, ", GCD(12, -10));
	fprintf(stdout, "%ld, ", GCD(-12, 10));
	fprintf(stdout, "%ld, ", GCD(-12, -10));
	fprintf(stdout, "\n");

	fprintf(stdout, "%ld, ", GCD(10, 12));
	fprintf(stdout, "%ld, ", GCD(10, -12));
	fprintf(stdout, "%ld, ", GCD(-10, 12));
	fprintf(stdout, "%ld, ", GCD(-10, -12));
	fprintf(stdout, "\n");
}
////////////////////////////////////////////////////////////////////////////////


int main(int argc, char *argv[]) {
	Test_GCD_LCM();

	return 0;
}
