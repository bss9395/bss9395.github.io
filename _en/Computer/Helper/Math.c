/* Math.c
Author: BSS9395
Update: 2020-11-02T20:44:00+08@China-Guangdong-Zhanjiang+08
Design: Math Library
*/

#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int8_t    in08;
typedef int16_t   in16;
typedef int32_t   in32;
typedef int64_t   in64;
typedef intptr_t  iptr;
typedef uint8_t   ui08;
typedef uint16_t  ui16;
typedef uint32_t  ui32;
typedef uint64_t  ui64;
typedef uintptr_t uptr;

typedef const ui08 *Level;
struct {
	const Level _Info;
	const Level _ToDo;
	const Level _Warn;
	const Level _Error;
	const Level _Fatal;
} ELevel;

bool Check(bool failed, Level level, const ui08 *function, const ui08 *record, const ui08 *extra) {
	if (failed) {
		if (extra == NULL) extra = (const ui08 *)"";
		fprintf(stderr, "[%s] %s: %s%s; ""\n", level, function, record, extra);
	}

	errno = 0;
	return failed;
}

/* Greatest Common Divisor and Least Common Multiple
GCD(lhs, rhs) = GCD(rhs, lhs)
LCM(lhs, rhs) = LCM(rhs, lhs)

k 〜 GCD(lhs, rhs) = GCD(k 〜 lhs, k 〜 rhs)
k 〜 LCM(lhs, rhs) = LCM(k 〜 lhs, k 〜 rhs)

GCD(lhs, LCM(mid, rhs)) = LCM(GCD(lhs, mid), GCD(lhs, rhs))
# lhs == G，L, mid == g，M == G，g/G，M, rhs == g，R == G，g/G，M
# GCD(lhs, LCM(mid, rhs)) == GCD(G，L, g，M，R) == GCD(G，L, G，g/G，M，R) == G
# LCM(GCD(lhs, mid), GCD(lhs, rhs)) == LCM(G, G) == G

LCM(lhs, GCD(mid, rhs)) = GCD(LCM(lhs, mid), LCM(lhs, rhs))
# lhs == g，L, mid == G，M == g，G/g，M, rhs == G，R == g，G/g，R
# LCM(lhs, GCD(mid, rhs)) == LCM(g，L, G) == LCM(g，L, g，G/g) == g，L，G/g == L，G
# GCD(LCM(lhs, mid), LCM(lhs, rhs)) == GCD(g，L，G/g，M, g，L，G/g，R) == g，L，G/g == L，G

GCD(lhs, mid, rhs) = GCD(GCD(lhs, mid), rhs) = GCD(lhs, GCD(mid, rhs))
LCM(lhs, mid, rhs) = LCM(LCM(lhs, mid), rhs) = LCM(lhs, LCM(mid, rhs))

lhs * rhs = GCD(lhs, rhs) * LCM(lhs, rhs)
0 <= GCD(lhs, rhs) <= Min(|lhs|, |rhs|) <= Max(|lhs|, |rhs|) <= LCM(|lhs|, |rhs|) == |LCM(lhs, rhs)|

GCD(|lhs|, 0) = 0                              # |rhs| == 0
GCD(|lhs|, |lhs|) = |lhs|                      # |lhs| == |rhs|
GCD(|lhs|, |rhs|) = GCD(|lhs| - |rhs|, |rhs|)  # |lhs| >= |rhs|
GCD(|lhs|, |rhs|) = GCD(|lhs|, |rhs| - |lhs|)  # |lhs| <= |rhs|
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
long GCD(long lhs, long rhs) {
	if (lhs == 0 || rhs == 0) {
		return 0;
	}
	(lhs < 0) ? (lhs = -lhs) : (lhs);
	(rhs < 0) ? (rhs = -rhs) : (rhs);

	while ((lhs %= rhs) && (rhs %= lhs));

	return (lhs + rhs);
}

long GCD_Classic(long lhs, long rhs) {
	if (lhs == 0 || rhs == 0) {
		return 0;
	}
	(lhs < 0) ? (lhs = -lhs) : (lhs);
	(rhs < 0) ? (rhs = -rhs) : (rhs);

	long gcd = rhs;
	while (rhs = lhs % gcd) {
		lhs = gcd;
		gcd = rhs;
	}

	return gcd;
}

long GCD_Recursion(long lhs, long rhs) {
	static bool check = true;
	if (check) {
		if (lhs == 0 || rhs == 0) {
			return 0;
		}
		(lhs < 0) ? (lhs = -lhs) : (lhs);
		(rhs < 0) ? (rhs = -rhs) : (rhs);
		check = false;
	}

	if (rhs == 0) {
		check = true;
		return lhs;
	}
	return GCD_Recursion(rhs, lhs % rhs);
}

long GCD_Reduction(long lhs, long rhs) {
	if (lhs == 0 || rhs == 0) {
		return 0;
	}
	(lhs < 0) ? (lhs = -lhs) : (lhs);
	(rhs < 0) ? (rhs = -rhs) : (rhs);

	while (lhs != 0) {
		if (lhs >= rhs) {
			lhs = lhs - rhs;
		}
		else if (lhs < rhs) {
			rhs = rhs - lhs;
		}
	}

	return rhs;
}

long LCM(long lhs, long rhs) {
	long gcd = GCD(lhs, rhs);
	if (gcd == 0) {
		return (lhs + rhs);
	}
	return ((lhs * rhs) / gcd);
}

long Multiple_GCD(long inte[], long numb) {
	if (Check(inte == NULL || numb < 2, ELevel._Error, __FUNCTION__, "inte == NULL || numb < 0", NULL)) {
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < numb; i += 1) {
		if (inte[i] == 0) {
			return 0;
		}
	}

	long gcd = inte[0];
	for (int i = 1; i < numb; i += 1) {
		gcd = GCD(gcd, inte[i]);
		if (gcd == 1) {
			break;
		}
	}

	return gcd;
}

long Multiple_LCM(long inte[], long numb) {
	if (Check(inte == NULL || numb < 2, ELevel._Error, __FUNCTION__, "inte == NULL || numb < 0", NULL)) {
		exit(EXIT_FAILURE);
	}

	long mult = 1;
	for (int i = 0; i < numb; i += 1) {
		if (inte[i] != 0) {
			mult *= inte[i];
		}
	}

	long gcd = Multiple_GCD(inte, numb);
	if (gcd == 0) {
		return mult;
	}
	return (mult / gcd);
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
