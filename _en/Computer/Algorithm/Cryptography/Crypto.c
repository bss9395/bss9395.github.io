/* Math.c
Author: BSS9395
Update: 2020-11-06T06:32:00+08@China-Guangdong-Zhanjiang+08
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
		(extra == NULL) ? extra = (const ui08 *)"" : extra;
		fprintf(stderr, "[%s] %s: %s%s; ""\n", level, function, record, extra);
	}

	errno = 0;
	return failed;
}

/* Greatest Common Divisor and Least Common Multiple
GCD(lhs, rhs) = GCD(rhs, lhs)
LCM(lhs, rhs) = LCM(rhs, lhs)

k ¡Á GCD(lhs, rhs) = GCD(k ¡Á lhs, k ¡Á rhs)
k ¡Á LCM(lhs, rhs) = LCM(k ¡Á lhs, k ¡Á rhs)

GCD(lhs, LCM(mid, rhs)) = LCM(GCD(lhs, mid), GCD(lhs, rhs))
# lhs == G¡¤L, mid == g¡¤M == G¡¤g/G¡¤M, rhs == g¡¤R == G¡¤g/G¡¤M
# GCD(lhs, LCM(mid, rhs)) == GCD(G¡¤L, g¡¤M¡¤R) == GCD(G¡¤L, G¡¤g/G¡¤M¡¤R) == G
# LCM(GCD(lhs, mid), GCD(lhs, rhs)) == LCM(G, G) == G

LCM(lhs, GCD(mid, rhs)) = GCD(LCM(lhs, mid), LCM(lhs, rhs))
# lhs == g¡¤L, mid == G¡¤M == g¡¤G/g¡¤M, rhs == G¡¤R == g¡¤G/g¡¤R
# LCM(lhs, GCD(mid, rhs)) == LCM(g¡¤L, G) == LCM(g¡¤L, g¡¤G/g) == g¡¤L¡¤G/g == L¡¤G
# GCD(LCM(lhs, mid), LCM(lhs, rhs)) == GCD(g¡¤L¡¤G/g¡¤M, g¡¤L¡¤G/g¡¤R) == g¡¤L¡¤G/g == L¡¤G

GCD(lhs, mid, rhs) = GCD(GCD(lhs, mid), rhs) = GCD(lhs, GCD(mid, rhs))
LCM(lhs, mid, rhs) = LCM(LCM(lhs, mid), rhs) = LCM(lhs, LCM(mid, rhs))

lhs * rhs = GCD(lhs, rhs) * LCM(lhs, rhs)
0 <= GCD(lhs, rhs) == GCD(|lhs|, |rhs|) <= Min(|lhs|, |rhs|) <= Max(|lhs|, |rhs|) <= LCM(|lhs|, |rhs|) == |LCM(lhs, rhs)|

GCD(|lhs|, 0) = 0                              # |rhs| == 0
GCD(|lhs|, |lhs|) = |lhs|                      # |rhs| == |lhs|
GCD(|lhs|, |rhs|) = GCD(|lhs| - |rhs|, |rhs|)  # |lhs| >= |rhs|
GCD(|lhs|, |rhs|) = GCD(|lhs|, |rhs| - |lhs|)  # |lhs| <= |rhs|

LCM(lhs, 0) = lhs                # rhs == 0
LCM(lhs, lhs) = lhs              # rhs == lhs
LCM(lhs, -rhs) = -LCM(lhs, rhs)  # rhs == -lhs
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
	long lcm = (gcd == 0) ? (lhs + rhs) : ((lhs * rhs) / gcd);
	return lcm;
}

long Multiple_GCD(long inte[], long numb) {
	if (Check(inte == NULL || numb < 2, ELevel._Error, __FUNCTION__, "inte == NULL || numb < 2", NULL)) {
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
	if (Check(inte == NULL || numb < 2, ELevel._Error, __FUNCTION__, "inte == NULL || numb < 2", NULL)) {
		exit(EXIT_FAILURE);
	}

	long gcd = Multiple_GCD(inte, numb);
	long lcm = gcd;
	if (gcd == 0) {
		for (int i = 0; i < numb; i += 1) {
			if (inte[i] != 0) {
				(lcm == 0) ? (lcm = inte[i]) : (lcm *= inte[i]);
			}
		}
	}
	else {
		for (int i = 0; i < numb; i += 1) {
			lcm *= inte[i] / gcd;
		}
	}
	return lcm;
}

long Extended_GCD(long lhs, long rhs, long *lhs_mul, long *rhs_mul) {
	if (Check(lhs_mul == NULL || rhs_mul == NULL, ELevel._Error, __FUNCTION__, "lhs_mul == NULL || rhs_mul == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	if (lhs == 0 || rhs == 0) {
		*lhs_mul = -rhs;
		*rhs_mul = -lhs;
		return 0;
	}
	long r0 = (lhs < 0) ? -lhs : lhs;
	long r1 = (rhs < 0) ? -rhs : rhs;
	long m0 = 1, m1 = 0;

	long mul = m1;
	long gcd = r1;
	long q1 = r0 / r1;
	while (r1 = r0 - r1 * q1) {
		m1 = m0 - m1 * q1;
		m0 = mul;
		mul = m1;

		r0 = gcd;
		gcd = r1;
		q1 = r0 / r1;
	}
	(*lhs_mul) = (lhs < 0) ? -mul : mul;
	(*rhs_mul) = (gcd - (*lhs_mul) * lhs) / rhs;
	return gcd;
}


/* GCD(lhs, rhs) ¡Ô GCD(rhs, lhs % rhs)
lhs = rhs ¡Á Q + R         # lhs > rhs
R0 = R1 ¡Á Q1 + R2

R0 ¡Ô lhs  R1 ¡Ô rhs             M0 ¡Ô 1     N0 ¡Ô 0               M1 ¡Ô 0     N1 ¡Ô 1
R2 = R0 - R1 ¡Á Q1         R0 ¡Ô M0 ¡Á lhs + N0 ¡Á rhs        R1 ¡Ô M1 ¡Á lhs + N1 ¡Á rhs
R2 = R0 % R1    		  M2 = M0 - M1 ¡Á Q1               N2 = N0 - N1 ¡Á Q1

R2 = (M0 ¡Á lhs + N0 ¡Á rhs) - (M1 ¡Á lhs + N1 ¡Á rhs) ¡Á Q1
R2 = (M0 - M1 ¡Á Q1) ¡Á lhs + (N0 - N1 ¡Á Q1) ¡Á rhs
R2 = M2 ¡Á lhs + N2 ¡Á rhs
Ri = Mi ¡Á lhs + Ni ¡Á rhs
*/

/*
 M ¡Á lhs ¡Á N ¡Á rhs <= 0
 M ¡Á lhs + N ¡Á rhs ¡Ô GCD(lhs, rhs) ¡Ý 0
-4 ¡Á  5  + 3 ¡Á  7  ¡Ô  1
----------------------------------
 3	  5   -2    7     1
-3	 -5   -2    7     1
 3	  5    2   -7     1
-3	 -5    2   -7     1

-3	  2    1    7     1
 3	 -2    1    7     1
-3	  2   -1   -7     1
 3	 -2   -1   -7     1

-rhs  0    0   rhs    0
 0   lhs  -lhs  0     0
 0    0    0    0     0

 0	  3    1    3     3
 0	 -3    1    3     3
 0	  3   -1   -3     3
 0	 -3   -1   -3     3
*/
long Extended_GCD_Classic(long lhs, long rhs, long *lhs_mul, long *rhs_mul) {
	if (Check(lhs_mul == NULL || rhs_mul == NULL, ELevel._Error, __FUNCTION__, "lhs_mul == NULL || rhs_mul == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	if (lhs == 0 || rhs == 0) {
		*lhs_mul = -rhs;
		*rhs_mul = -lhs;
		return 0;
	}
	long r0 = (lhs < 0) ? ((*lhs_mul) = -1, -lhs) : ((*lhs_mul) = +1, lhs);
	long r1 = (rhs < 0) ? ((*rhs_mul) = -1, -rhs) : ((*rhs_mul) = +1, rhs);
	long m0 = 1, m1 = 0;
	long n0 = 0, n1 = 1;

	long q1 = 0;
	long r2 = 0;
	while (r1 != 0) {
		q1 = r0 / r1;

		r2 = r1;
		r1 = r0 - r1 * q1;
		r0 = r2;

		r2 = m1;
		m1 = m0 - m1 * q1;
		m0 = r2;

		r2 = n1;
		n1 = n0 - n1 * q1;
		n0 = r2;
	}
	(*lhs_mul) *= m0;
	(*rhs_mul) *= n0;
	return r0;
}

// Modular_Multiplicative_Inverse
long MMI(long lhs, long rhs, long *mmi) {
	if (Check(mmi == NULL, ELevel._Error, __FUNCTION__, "mmi == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	long lhs_mul = 0;
	long rhs_mul = 0;
	long gcd = Extended_GCD(lhs, rhs, &lhs_mul, &rhs_mul);
	if (gcd == 1) {
		(*mmi) = lhs_mul;
	}
	return gcd;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Extended_GCD() {
	long m = 0;
	long n = 0;
	long gcd = 0;

	// #define Extended_GCD Extended_GCD_Classic
	gcd = Extended_GCD(5, 7, &m, &n), fprintf(stdout, "gcd = %ld, %ld ¡Á %ld + %ld ¡Á %ld = %ld""\n", gcd, m, 5, n, 7, m * 5 + n * 7);
	gcd = Extended_GCD(-5, 7, &m, &n), fprintf(stdout, "gcd = %ld, %ld ¡Á %ld + %ld ¡Á %ld = %ld""\n", gcd, m, -5, n, 7, m * (-5) + n * 7);
	gcd = Extended_GCD(5, -7, &m, &n), fprintf(stdout, "gcd = %ld, %ld ¡Á %ld + %ld ¡Á %ld = %ld""\n", gcd, m, 5, n, -7, m * 5 + n * (-7));
	gcd = Extended_GCD(-5, -7, &m, &n), fprintf(stdout, "gcd = %ld, %ld ¡Á %ld + %ld ¡Á %ld = %ld""\n", gcd, m, -5, n, -7, m * (-5) + n * (-7));
	fprintf(stdout, "\n");

	gcd = Extended_GCD(0, 7, &m, &n), fprintf(stdout, "gcd = %ld, %ld ¡Á %ld + %ld ¡Á %ld = %ld""\n", gcd, m, 0, n, 7, m * 0 + n * 7);
	gcd = Extended_GCD(2, 0, &m, &n), fprintf(stdout, "gcd = %ld, %ld ¡Á %ld + %ld ¡Á %ld = %ld""\n", gcd, m, 2, n, 0, m * 2 + n * 0);
	gcd = Extended_GCD(0, 0, &m, &n), fprintf(stdout, "gcd = %ld, %ld ¡Á %ld + %ld ¡Á %ld = %ld""\n", gcd, m, 0, n, 0, m * 0 + n * 0);
	fprintf(stdout, "\n");

	gcd = Extended_GCD(3, 3, &m, &n), fprintf(stdout, "gcd = %ld, %ld ¡Á %ld + %ld ¡Á %ld = %ld""\n", gcd, m, 3, n, 3, m * 3 + n * 3);
	gcd = Extended_GCD(-3, 3, &m, &n), fprintf(stdout, "gcd = %ld, %ld ¡Á %ld + %ld ¡Á %ld = %ld""\n", gcd, m, -3, n, 3, m * (-3) + n * 3);
	gcd = Extended_GCD(3, -3, &m, &n), fprintf(stdout, "gcd = %ld, %ld ¡Á %ld + %ld ¡Á %ld = %ld""\n", gcd, m, 3, n, -3, m * 3 + n * (-3));
	gcd = Extended_GCD(-3, -3, &m, &n), fprintf(stdout, "gcd = %ld, %ld ¡Á %ld + %ld ¡Á %ld = %ld""\n", gcd, m, -3, n, -3, m * (-3) + n * (-3));
	fprintf(stdout, "\n");
}

void Test_Multiple_GCD_LCM() {
	long inte[] = { 6, 8, 10 };
	long zero[] = { 0, 0, 2 };

	fprintf(stdout, "%ld ""\n", Multiple_LCM(inte, sizeof(inte) / sizeof(inte[0])));
	fprintf(stdout, "%ld ""\n", Multiple_LCM(zero, sizeof(zero) / sizeof(zero[0])));
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
	// Test_GCD_LCM();
	Test_Multiple_GCD_LCM();
	return 0;
}
