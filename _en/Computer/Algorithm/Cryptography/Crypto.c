/* Math.c
Author: BSS9395
Update: 2020-11-15T03:42:00+08@China-Guangdong-Zhanjiang+08
Design: Math Library
*/

#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define Sqrt sqrt

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

/*
Prime  ¡Ô 1 ¡Á Prime
Number ¡Ô Prime1^exp1 ¡Á Prime2^exp2 ¡Á ...
Number ¡Ô Number1 ¡Á Number2
Number1 <= Root <= Number2         # Square ¡Ô Root ¡Á Root

6¡¤K + 0 ¡Ô 2 ¡Á (3¡¤K + 0)
6¡¤K + 1 ¡Ö Pseudo Prime
6¡¤K + 2 ¡Ô 2 ¡Á (3¡¤K + 1)
6¡¤K + 3 ¡Ô 3 ¡Á (2¡¤K + 1£©
6¡¤K + 4 ¡Ô 2 ¡Á (3¡¤K + 2)
6¡¤K + 5 ¡Ö Pseudo Prime
*/
bool Check_Prime(long number) {
	(number < 0) ? (number = -number) : number;
	if (number <= 3) {
		return (1 <= number);
	}

	if (number % 6 == 1 || number % 6 == 5) {
		long root = (long)Sqrt(number);
		long pseudo = 1;
		long step = 4;
		while (pseudo += step, pseudo <= root) {
			if (number % pseudo == 0) {
				return false;
			}
			step = (step == 4) ? 2 : 4;
		}
		return true;
	}
	return false;
}

bool Check_Prime_Classic(long number) {
	(number < 0) ? (number = -number) : number;
	if (number <= 3) {
		return (1 <= number);
	}

	long root = (long)sqrt(number);
	for (long num = 2; num <= root; num += 1) {
		if (number % num == 0) {
			return false;
		}
	}
	return true;
}

long Generate_Prime(long prime[], long size, long number) {
	if (Check(prime == NULL || size <= 0 || number == 0, ELevel._Error, __FUNCTION__, "prime == NULL || size <= 0 || number == 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	(number < 0) ? (number = -number) : number;

	long init[3] = { 1, 2, 3 };
	long count = 3;
	if (size <= 3 || number <= 3) {
		count = size = (size < number) ? size : number;
	}
	for (long i = 0; i < count; i += 1) {
		prime[i] = init[i];
	}
	if (size <= count) {
		return count;
	}

	long pseudo = 1;
	long step = 4;
	long index = 1;
	while (pseudo += step, count < size && pseudo <= number) {
		for (index = 1; index < count; index += 1) {
			if (pseudo % prime[index] == 0) {
				break;
			}
		}
		if (index >= count) {
			prime[count] = pseudo;
			count += 1;
		}
		step = (step == 4) ? 2 : 4;
	}
	return count;
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

long GCD_Recursion_Entrance(long lhs, long rhs) {
	if (rhs == 0) {
		return lhs;
	}
	return GCD_Recursion_Entrance(rhs, lhs % rhs);
}
long GCD_Recursion(long lhs, long rhs) {
	if (lhs == 0 || rhs == 0) {
		return 0;
	}
	(lhs < 0) ? (lhs = -lhs) : (lhs);
	(rhs < 0) ? (rhs = -rhs) : (rhs);

	return GCD_Recursion_Entrance(lhs, rhs);
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

	for (long i = 0; i < numb; i += 1) {
		if (inte[i] == 0) {
			return 0;
		}
	}

	long gcd = inte[0];
	for (long i = 1; i < numb; i += 1) {
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
		for (long i = 0; i < numb; i += 1) {
			if (inte[i] != 0) {
				(lcm == 0) ? (lcm = inte[i]) : (lcm *= inte[i]);
			}
		}
	}
	else {
		for (long i = 0; i < numb; i += 1) {
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
 M ¡Á lhs + N ¡Á rhs <= 0
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


long Extended_Multiple_GCD(long inte[], long mult[], long numb) {
	if (Check(inte == NULL || mult == NULL || numb < 2, ELevel._Error, __FUNCTION__, "inte == NULL || mult == NULL || size < 0", NULL)) {
		exit(EXIT_FAILURE);
	}



	long gcd = inte[0]; mult[0] = 1;
	long lhs_mult = 0;
	for (long i = 1; i < numb; i += 1) {
		gcd = Extended_GCD(gcd, inte[i], &lhs_mult, &mult[i]);
		for (long j = 0; j < i; j += 1) {
			mult[j] *= lhs_mult;
		}
	}
	return gcd;
}

void Test_Extended_Multiple_GCD() {
	long inte[3] = { 2, 3, 5 };
	long mult[3] = { 0, 0, 0 };
	long numb = 3;

	long gcd = Extended_Multiple_GCD(inte, mult, numb);
	fprintf(stdout, "%ld\n", gcd);

	for (long i = 0; i < numb; i += 1) {
		fprintf(stdout, "(%ld, %ld) ", inte[i], mult[i]);
	}
	fprintf(stdout, "\n");

	gcd = 0;
	for (long i = 0; i < numb; i += 1) {
		gcd += inte[i] * mult[i];
	}
	fprintf(stdout, "%ld\n", gcd);
}

// Modular_Multiplicative_Inverse
long MMI(long lhs, long rhs, long *mmi) {
	if (Check(mmi == NULL, ELevel._Error, __FUNCTION__, "mmi == NULL", NULL)) {
		exit(EXIT_FAILURE);
	}

	long lhs_mul = 0;
	long rhs_mul = 0;
	long gcd = Extended_GCD(lhs, rhs, &lhs_mul, &rhs_mul);
	(*mmi) = (gcd == 1) ? lhs_mul : rhs;
	return gcd;
}

/*
lhs ¡Ô M ¡Á divi + L, rhs ¡Ô N ¡Á divi + R
(lhs + rhs) % divi = ((lhs % divi) + rhs) % divi = ((lhs % divi) + (rhs % divi)) % divi = (L + R) % divi
(lhs - rhs) % divi = ((lhs % divi) - rhs) % divi = ((lhs % divi) - (rhs % divi)) % divi = (L - R) % divi
(lhs ¡Á rhs) % divi = ((lhs % divi) ¡Á rhs) % divi = ((lhs % divi) ¡Á (rhs % divi)) % divi = (L ¡Á R) % divi
(pre ¡Á (lhs ¡À rhs)) % divi = (((pre ¡Á lhs) % divi) + ((pre ¡Á rhs) % divi)) % divi

[Base^(2 ¡Á Expo + ?)] % Divi = [(Base^2)^Expo ¡Á Base^?] % Divi
[Base^(2 ¡Á Expo + ?)] % Divi = [(Base^2)^Expo ¡Á Base^?] % Divi

Base^(0B1011) = Base^(2^3) ¡Á Base^(2^1) ¡Á Base^(2^0)
*/
long Remainder_Power(long base, long expo, long divi) {
	if (Check(divi == 0, ELevel._Error, __FUNCTION__, "divi == 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (base == 0 && expo == 0) {
		// return NAN;
		return divi;
	}
	if (expo == 0) {
		return (1 % divi);
	}
	bool inver = (expo < 0) ? (expo = -expo, true) : false;
	if (base == 0) {
		// return (inver ? INFINITY : 0);
		return (inver ? divi : 0);
	}

	long rema = 1;
	while (0 < expo) {
		(expo & 0X01) ? ((rema = rema * base) % divi) : rema;
		base = (base * base) % divi;
		expo >>= 1;
	}

	if (inver) {
		long mmi = 0;
		MMI(rema, divi, &mmi);
		return (mmi == divi) ? divi : (mmi % divi);
	}
	return rema;
}

/*
Base^(0B1011) = Base^(2^3) ¡Á Base^(2^1) ¡Á Base^(2^0)
*/
long Remainder_Power_Recursion_Entrance(long base, long expo, long divi) {
	if (expo == 0) {
		return 1;
	}

	long rema = Remainder_Power_Recursion_Entrance((base * base) % divi, expo >> 1, divi);
	return ((expo & 0X01) ? ((rema * base) % divi) : rema);
}
long Remainder_Power_Recursion(long base, long expo, long divi) {
	if (Check(divi == 0, ELevel._Error, __FUNCTION__, "divi == 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (base == 0 && expo == 0) {
		// return NAN;
		return divi;
	}
	if (expo == 0) {
		return (1 % divi);
	}
	bool inver = (expo < 0) ? (expo = -expo, true) : false;
	if (base == 0) {
		// return (inver ? INFINITY : 0);
		return (inver ? divi : 0);
	}

	long rema = Remainder_Power_Recursion_Entrance(base, expo, divi);
	if (inver) {
		long mmi = 0;
		MMI(rema, divi, &mmi);
		return (mmi == divi) ? divi : (mmi % divi);
	}
	return rema;
}

long Factorization(long integer, long prime[], long expon[], long size) {
	if (Check(prime == NULL || expon == NULL || size < 3, ELevel._Error, __FUNCTION__, "prime == NULL || expon == NULL || size < 3", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (integer == 0) {
		return 0;
	}

	(integer < 0) ? (prime[0] = -1, integer = -integer) : (prime[0] = +1, integer);
	expon[0] = 1;
	long count = 1;

	if ((integer & 0X01) == 0) {
		prime[count] = 2;
		expon[count] = 1;
		while (integer >>= 1, (integer & 0X01) == 0) {
			expon[count] += 1;
		}
		count += 1;
	}
	if (integer % 3 == 0) {
		prime[count] = 3;
		expon[count] = 1;
		while (integer /= 3, (integer % 3) == 0) {
			expon[count] += 1;
		}
		count += 1;
	}
	if (integer <= 1) {
		return count;
	}

	long root = (long)Sqrt(integer);
	Check(size < root * 2 / 3 + 1, ELevel._Warn, __FUNCTION__, "size < root * 2 / 3 + 1", NULL);

	long pseudo = 1;
	long step = 4;
	while (pseudo += step, pseudo <= integer && pseudo <= root) {
		if (integer % pseudo == 0) {
			prime[count] = pseudo;
			expon[count] = 1;
			while (integer /= pseudo, integer % pseudo == 0) {
				expon[count] += 1;
			}
			count += 1;
		}
		step = (step == 4) ? 2 : 4;
	}
	if (1 < integer) {
		prime[count] = integer;
		expon[count] = 1;
		count += 1;
	}
	return count;
}

/*
  Pri^Exp
= Pri ¡Á [Pri^{Exp-1}]

  MPC(Pri^Exp)
= Pri^Exp - Pri^{Exp-1}
= Pri^{Exp-1} ¡Á (Pri - 1)

  MPC(Pri1 ¡Á Pri2)
= Pri1 ¡Á Pri2 - Pri1 - Pri2 + 1
= (Pri1 - 1) ¡Á (Pri2 - 1)
= MPC(Pri1) ¡Á MPC(Pri2)

  MPC(Pri1^Exp1 ¡Á Pri2^Exp2)
= Pri1^Exp1 ¡Á Pri2^Exp2 - Pri1^{Exp1-1} ¡Á Pri2^Exp2 - Pri1^Exp1 ¡Á Pri2^{Exp2-1} + Pri1^{Exp1-1} ¡Á Pri2^{Exp2-1}
= [Pri1^{Exp1-1} ¡Á Pri2^{Exp2-1}] ¡Á [Pri1 ¡Á Pri2 - Pri1 - Pri2 + 1]
= [Pri1^{Exp1-1} ¡Á Pri2^{Exp2-1}] ¡Á [(Pri1 - 1) ¡Á (Pri2 - 1)]
= [Pri1^{Exp1-1} ¡Á (Pri1 - 1)] ¡Á [Pri2^{Exp2-1} ¡Á (Pri2 - 1)]
= MPC(Pri1^Exp1) ¡Á MPC(Pri2^Exp2)

  MPC(Pri1^Exp1 ¡Á Pri2^Exp2 ¡Á Pri3^Exp3)
= Pri1^Exp1 ¡Á Pri2^Exp2 ¡Á Pri3^Exp3
  - Pri1^{Exp1-1} ¡Á Pri2^Exp2 ¡Á Pri3^Exp3 - Pri1^Exp1 ¡Á Pri2^{Exp2-1} ¡Á Pri3^Exp3 - Pri1^Exp1 ¡Á Pri2^Exp2 ¡Á Pri3^{Exp3-1}
  + Pri1^{Exp1-1} ¡Á Pri2^{Exp2-1} ¡Á Pri3^Exp3 + Pri1^Exp1 ¡Á Pri2^{Exp2-1} ¡Á Pri3^{Exp3-1} + Pri1^{Exp1-1} ¡Á Pri2^Exp2 ¡Á Pri3^{Exp3-1}
  - Pri1^{Exp1-1} ¡Á Pri2^{Exp2-1} ¡Á Pri3^{Exp3-1}
= [Pril^{Exp1-1} ¡Á Pril2^{Exp2-1} ¡Á Pri3^{Exp3-1}]
  ¡Á [Pri1 ¡Á Pri2 ¡Á Pri3 - Pri1 ¡Á Pri2 - Pri2 ¡Á Pri3 - Pri3 ¡Á Pri1 + Pri1 + Pri2 + Pri3 - 1]
= [Pril^{Exp1-1} ¡Á Pril2^{Exp2-1} ¡Á Pri3^{Exp3-1}] ¡Á [(Pri1 - 1) ¡Á (Pri2 - 1) ¡Á (Pri3 - 1)]
= [Pri1^{Exp1-1} ¡Á (Pri1 - 1)] ¡Á [Pri2^{Exp2-1} ¡Á (Pri2 - 1)] ¡Á [Pri3^{Exp3-1} ¡Á (Pri3 - 1)]
= MPC(Pri1^Exp1) ¡Á MPC(Pri2^Exp2) ¡Á MPC(Pri3^Exp3)

  MPC(Pri1^Exp1 ¡Á Pri2^Exp2 ¡Á ... ¡Á PriN^ExpN)
= MPC(Pri1^Exp1) ¡Á MPC(Pri2^EXP2) ¡Á ... ¡Á MPC(PriN^ExpN)
= ¡Ç[Pri^{Exp-1} ¡Á (Pri - 1)]
= ¡Ç[Pri^Exp ¡Á (Pri - 1)/Pri]
= [Pri1^Exp1 ¡Á Pri2^Exp2 ¡Á ... ¡Á PriN^ExpN] ¡Á ¡Ç[1 - 1/Pri]
*/
long Mutual_Prime_Counting(long integer) {
	if (integer == 0) {
		return 0;
	}
	(integer < 0) ? (integer = -integer) : integer;

	double mpc = integer;
	if (integer % 2 == 0) {
		mpc = mpc * (2 - 1) / 2;
		while (integer /= 2, integer % 2 == 0);
	}
	if (integer % 3 == 0) {
		mpc = mpc * (3 - 1) / 3;
		while (integer /= 3, integer % 3 == 0);
	}
	if (integer <= 1) {
		return (long)mpc;
	}

	long root = (long)Sqrt(integer);
	long pseudo = 1;
	long step = 4;
	while (pseudo += step, pseudo <= integer && pseudo <= root) {
		if (integer % pseudo == 0) {
			mpc = mpc * (pseudo - 1) / pseudo;
			while (integer /= pseudo, integer % pseudo == 0);
		}
	}
	if (1 < integer) {
		mpc = mpc * (integer - 1) / integer;
	}
	return (long)mpc;
}

void Test_Mutual_Prime_Counting() {
	long integer = 12;
	long mpc = Mutual_Prime_Counting(integer);
	fprintf(stdout, "%ld\n", mpc);
}

////////////////////////////////////////////////////////////////////////////////

void Test_Check_Prime() {
	long number = -1;
	bool is = Check_Prime(number);
	fprintf(stdout, "%ld %s""\n", number, is ? "is prime" : "isn't prime");


	long prime[123];
	long size = sizeof(prime) / sizeof(prime[0]);
	long ceil = -123;
	long count = Generate_Prime(prime, size, ceil);

	for (long i = 0; i < count; i += 1) {
		fprintf(stdout, "%ld, ", prime[i]);
	}
	fprintf(stdout, "\n");
}

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

void Test_Factorization() {
	long integer = -60;
	long prime[10];
	long expon[10];

	long count = Factorization(integer, prime, expon, 10);
	for (long i = 0; i < count; i += 1) {
		fprintf(stdout, "(%ld, %ld) ", prime[i], expon[i]);
	}

}

void Test_Remainder_Power() {
	long base = 2;
	long expo = -5;
	long divi = 5;
	// long rema = Remainder_Power_Recursion(base, expo, divi);
	long rema = Remainder_Power(base, expo, divi);
	fprintf(stdout, "%ld\n", rema);
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	// Test_GCD_LCM();
	// Test_Multiple_GCD_LCM();
	// Test_Check_Prime();
	// Test_Factorization();
	// Test_Remainder_Power();
	// Test_Mutual_Prime_Counting();
	Test_Extended_Multiple_GCD();

	return 0;
}


