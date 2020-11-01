/* Math.c
Author: BSS9395
Update: 2020-11-02T00:47:00+08@China-Guangdong-Zhanjiang+08
Design: Math Library
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Greatest Common Divisor and Least Common Multiple
GCD(lhs, rhs) = GCD(rhs, lhs)
LCM(lhs, rhs) = LCM(rhs, lhs)

GCD(lhs, mid, rhs) = GCD(GCD(lhs, mid), rhs) = GCD(lhs, GCD(mid, rhs))
LCM(lhs, mid, rhs) = LCM(LCM(lhs, mid), rhs) = LCM(lhs, LCM(mid, rhs))

GCD(lhs, LCM(mid, rhs)) = LCM(GCD(lhs, mid), GCD(lhs, rhs))
LCM(lhs, GCD(mid, rhs)) = GCD(LCM(lhs, mid), LCM(lhs, rhs))

lhs * rhs = GCD(lhs, rhs) * LCM(lhs, rhs)
0 <= GCD(lhs, rhs) <= Min(|lhs|, |rhs|) <= Max(|lhs|, |rhs|) <= LCM(|lhs|, |rhs|) == |LCM(lhs, rhs)|

# 0 <= lhs && 0 <= rhs
GCD(lhs, 0) = 0                      # rhs == 0
GCD(lhs, lhs) = lhs                  # lhs == rhs
GCD(lhs, rhs) = GCD(lhs - rhs, rhs)  # lhs >= rhs
GCD(lhs, rhs) = GCD(lhs, rhs - lhs)  # lhs <= rhs
*/

/*
rema = lhs - rhs * quot
lhs * rhs = gcd * lcm

lhs  rhs  quot  rema  gcd  lcm
 12   10     1     2    2   60
-12   10    -1    -2    2  -60
 12  -10    -1     2    2  -60
-12  -10     1    -2    2   60

 10   12     0    10    2   60
-10   12     0   -10    2  -60
 10  -12     0    10    2  -60
-10  -12     0   -10    2   60

  0   10     0     0    0   10
 10    0     ?     ?    0   10
  0  -10     0     0    0  -10
-10    0     ?     ?    0  -10

  0    0     ?     ?    0    0
*/
long GCD(long x, long y) {
	if (x == 0 || y == 0) {
		return 0;
	}
	(x < 0) ? (x = -x) : (x);
	(y < 0) ? (y = -y) : (y);

	while ((x %= y) && (y %= x));

	return (x + y);
}

long GCD_Classic(long x, long y) {
	if (x == 0 || y == 0) {
		return 0;
	}
	(x < 0) ? (x = -x) : (x);
	(y < 0) ? (y = -y) : (y);

	long gcd = y;
	while (y = x % gcd) {
		x = gcd;
		gcd = y;
	}

	return gcd;
}

long GCD_Recursion(long x, long y) {
	static bool check = true;
	if (check) {
		if (x == 0 || y == 0) {
			return 0;
		}
		(x < 0) ? (x = -x) : (x);
		(y < 0) ? (y = -y) : (y);
		check = false;
	}

	if (y == 0) {
		check = true;
		return x;
	}
	return GCD_Recursion(y, x % y);
}

long GCD_Reduction(long x, long y) {
	if (x == 0 || y == 0) {
		return 0;
	}
	(x < 0) ? (x = -x) : (x);
	(y < 0) ? (y = -y) : (y);

	while (x != y) {
		if (x > y) {
			x = x - y;
		}
		else if (x < y) {
			y = y - x;
		}
	}

	return x;
}

long LCM(long x, long y) {
	if (x == 0 || y == 0) {
		return (x + y);
	}

	return ((x * y) / GCD(x, y));
}

void Test_GCD_LCM() {
	// #define GCD GCD_Reduction
	fprintf(stdout, "(%ld, %ld) ", GCD(12, 10), LCM(12, 10));
	fprintf(stdout, "(%ld, %ld) ", GCD(12, -10), LCM(12, -10));
	fprintf(stdout, "(%ld, %ld) ", GCD(-12, 10), LCM(-12, 10));
	fprintf(stdout, "(%ld, %ld) ", GCD(-12, -10), LCM(-12, -10));
	fprintf(stdout, "\n");

	fprintf(stdout, "(%ld, %ld) ", GCD(10, 12), LCM(10, 12));
	fprintf(stdout, "(%ld, %ld) ", GCD(10, -12), LCM(10, -12));
	fprintf(stdout, "(%ld, %ld) ", GCD(-10, 12), LCM(-10, 12));
	fprintf(stdout, "(%ld, %ld) ", GCD(-10, -12), LCM(-10, -12));
	fprintf(stdout, "\n");

	fprintf(stdout, "(%ld, %ld) ", GCD(0, 10), LCM(0, 10));
	fprintf(stdout, "(%ld, %ld) ", GCD(10, 0), LCM(10, 0));
	fprintf(stdout, "(%ld, %ld) ", GCD(0, -10), LCM(0, -10));
	fprintf(stdout, "(%ld, %ld) ", GCD(-10, 0), LCM(-10, 0));
	fprintf(stdout, "(%ld, %ld) ", GCD(0, 0), LCM(0, 0));
	fprintf(stdout, "\n");
}
////////////////////////////////////////////////////////////////////////////////


int main(int argc, char *argv[]) {
	Test_GCD_LCM();

	return 0;
}
