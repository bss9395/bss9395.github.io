/* Math.c
Author: BSS9395
Update: 2020-11-12T06:52:00+08@China-Guangdong-Zhanjiang+08
Design: Math Library
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/* Definition of Division
rema = lhs - rhs * Inner(lhs / rhs) = lhs - rhs * quot
modu = lhs - rhs * Under(lhs / rhs)
Rema = lhs - rhs * Outer(lhs / rhs)
Modu = lhs - rhs * Cover(lhs / rhs)

			   Inner Under                | Outer Cover
lhs  rhs  quot  rema  modu  Inner  Under  |  Rema  Modu  Outer  Cover
 12   10     1     2     2      1      1  |    -8    -8      2      2
-12   10    -1    -2     8     -1     -2  |     8    -2     -2     -1
 12  -10    -1     2    -8     -1     -2  |    -8     2     -2     -1
-12  -10     1    -2    -2      1      1  |     8     8      2      2
										  |
 10   12     0    10    10      0      0  |    -2    -2      1      1
-10   12     0   -10     2      0     -1  |     2   -10     -1      0
 10  -12     0    10    -2      0     -1  |    -2    10     -1      0
-10  -12     0   -10   -10      0      0  |     2     2      1      1
*/

double Absolute(double number) {
	return ((number < 0) ? -number : number);
}

long Outer(double number) {
	long outer = (long)number;
	if (outer < 0) {
		return (outer == number) ? outer : (outer - 1);
	}
	return (outer == number) ? outer : (outer + 1);
}

long Cover(double number) {
	long over = (long)number;
	if (over < 0) {
		return over;
	}
	return (over == number) ? over : (over + 1);
}

long Round(double number) {
	long round = (long)number;
	if (round < 0) {
		return (number <= round - 0.50) ? (round - 1) : round;
	}
	return (round + 0.50 <= number) ? (round + 1) : round;
}

long Inner(double number) {
	return (long)number;
}

long Under(double number) {
	long under = (long)number;
	if (under < 0) {
		return (under == number) ? under : (under - 1);
	}
	return under;
}

/*
Base^(0B1011) = Base^(2^3) 〜 Base^(2^1) 〜 Base^(2^0)
*/
double Power(double base, long expo) {
	if (base == 0.0 && expo == 0) {
		return NAN;
	}
	bool inver = (expo < 0) ? (expo = -expo, true) : false;
	if (base == 0.0) {
		return (inver ? INFINITY : 0.0);
	}

	double power = 1.0;
	while (0 < expo) {
		(expo & 0X01) ? (power *= base) : power;
		base = base * base;
		expo >>= 1;
	}
	return power;
}

double Power_Classic(double base, long expo) {
	if (base == 0.0 && expo == 0) {
		return NAN;
	}
	bool inver = (expo < 0) ? (expo = -expo, true) : false;
	if (base == 0.0) {
		return (inver ? INFINITY : 0.0);
	}

	double power = 1.0;
	for (long i = 0; i < expo; i += 1) {
		power *= base;
	}
	return (inver ? 1 / power : power);
}

/*
Base^(2 〜 Expo + ?) = (Base^2)^Expo 〜 (Base^?)
*/
double Power_Recursion_Entrance(double base, long expo) {
	if (expo == 0) {
		return 1.0;
	}
	double power = Power_Recursion_Entrance(base * base, expo >> 1);
	return (expo & 0x01) ? (power *= base) : power;
}
double Power_Recursion(double base, long expo) {
	if (base == 0.0 && expo == 0) {
		return NAN;
	}
	bool inver = (expo < 0) ? (expo = -expo, true) : false;
	if (base == 0.0) {
		return (inver ? INFINITY : 0.0);
	}

	double power = Power_Recursion_Entrance(base, expo);
	return (inver ? 1 / power : power);
}

double Base_Square(double number, double preci) {
	if (Check(preci < 0, ELevel._Error, __FUNCTION__, "preci < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (Check(number < 0, ELevel._Info, __FUNCTION__, "complex number", NULL)) {
		return NAN;
	}
	if (number == 0.0) {
		return 0.0;
	}
	(number < 1.0) ? (preci *= number * number) : preci;

	long count = 0;
	double x0 = number;
	double x1 = 0.50 * (x0 + number / x0);
	while (preci < Absolute(x1 - x0)) {
		x0 = x1;
		x1 = 0.50 * (x0 + number / x0);
		count += 1;
	}
	fprintf(stdout, "%ld\n", count);
	return x1;
}

/* Base_Tangent
 F(X) 「 F(Xn) + F'(Xn)，(X - Xn)
	X = Xn - F(Xn)/F'(Xn)       # F(X) 《 0
 Xn+1 = Xn - F(Xn)/F'(Xn)

  val = X^exp
 F(X) = X^exp - val
F'(X) = exp，X^(exp - 1)
 Xn+1 = Xn - F(Xn)/F'(Xn)
 Xn+1 = Xn - (Xn^exp - val)/[exp，Xn^(exp - 1)]
 Xn+1 = [(exp - 1)，Xn + val/Xn^(exp - 1)]/exp

  val = X^2
 Xn+1 = 1/2，(Xn + val/Xn)
*/
double Base_Tangent(double number, long expon, double preci) {
	if (Check(preci < 0, ELevel._Error, __FUNCTION__, "preci < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (expon == 0) {
		return NAN;
	}
	if (Check(number < 0 && (expon & 0X01) == 0, ELevel._Info, __FUNCTION__, "complex number", NULL)) {
		return NAN;
	}
	bool inve = (expon < 0) ? (expon = -expon, true) : false;
	char sign = (number < 0.0) ? (number = -number, -1) : +1;
	if (expon == 1 || number == 0.0) {
		return sign * (inve ? 1 / number : number);
	}
	(number < 1.0) ? (preci *= number * number) : preci;

	long count = 0;
	double x0 = number;
	double x1 = ((expon - 1) * x0 + number / Power(x0, expon - 1)) / expon;
	while (preci < Absolute(x1 - x0)) {
		x0 = x1;
		x1 = ((expon - 1) * x0 + number / Power(x0, expon - 1)) / expon;
		count += 1;
	}
	fprintf(stdout, "%ld\n", count);
	return sign * (inve ? 1 / x1 : x1);
}

/* Base_Secant
  F(X) 「 F(Xn) + F'(Xn)，(X - Xn)
	 X 「 Xn - F(Xn)/F'(Xn)       # F(X) 《 0
  Xn+1 = Xn - F(Xn)/F'(Xn)

   val = X^exp
  F(X) = X^exp - val
F'(Xn) 「 [F(Xn) - F(Xn-1)]/(Xn - Xn-1)
  Xn+1 = Xn - F(Xn)/F'(Xn)
  Xn+1 = Xn - (Xn - Xn-1)，F(Xn)/[F(Xn) - F(Xn-1)]
  Xn+1 = Xn - (Xn - Xn-1)，(Xn^exp - val)/(Xn^exp - Xn-1^exp)

   val = X^2
  Xn+1 = Xn - (Xn - Xn-1)，(Xn^2 - val)/(Xn^2 - Xn-1^2)
  Xn+1 = (Xn，Xn-1 + val)/(Xn + Xn-1)
*/
double Base_Secant(double number, long expon, double preci) {
	if (Check(preci < 0, ELevel._Error, __FUNCTION__, "preci < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (expon == 0) {
		return NAN;
	}
	if (Check(number < 0 && (expon & 0X01) == 0, ELevel._Info, __FUNCTION__, "complex number", NULL)) {
		return NAN;
	}
	bool inve = (expon < 0) ? (expon = -expon, true) : false;
	char sign = (number < 0.0) ? (number = -number, -1) : +1;
	if (expon == 1 || number == 0.0) {
		return sign * (inve ? 1 / number : number);
	}
	(number < 1.0) ? (preci *= number * number) : preci;

	long count = 0;
	double x0 = number / 2;
	double x1 = number;
	double p0 = Power(x0, expon);
	double p1 = Power(x1, expon);
	double x2 = x1 - (x1 - x0) * (p1 - number) / (p1 - p0);
	while (preci < Absolute(x2 - x0) || preci < Absolute(x2 - x1)) {
		x0 = x1;
		x1 = x2;
		p0 = p1;
		p1 = Power(x1, expon);
		x2 = x1 - (x1 - x0) * (p1 - number) / (p1 - p0);
		count += 1;
	}
	fprintf(stdout, "%ld\n", count);
	return sign * (inve ? 1 / x2 : x2);
}


/* Base_Secant_Fixed
  F(X) 「 F(Xn) + F'(Xn)，(X - Xn)
	 X 「 Xn - F(Xn)/F'(Xn)       # F(X) 《 0
  Xn+1 = Xn - F(Xn)/F'(Xn)

   val = X^exp
  F(X) = X^exp - val
F'(Xn) 「 [F(Xn) - F(XX)]/(Xn - XX)
  Xn+1 = Xn - F(Xn)/F'(Xn)
  Xn+1 = Xn - (Xn - XX)，F(Xn)/[F(Xn) - F(XX)]
  Xn+1 = Xn - (Xn - XX)，(Xn^exp - val)/(Xn^exp - XX^exp)

   val = X^2
  Xn+1 = Xn - (Xn - XX)，(Xn^2 - val)/(Xn^2 - XX^2)
  Xn+1 = (Xn，XX + val)/(Xn + XX)
*/
double Base_Secant_Fixed(double number, long expon, double preci) {
	if (Check(preci < 0, ELevel._Error, __FUNCTION__, "preci < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (expon == 0) {
		return NAN;
	}
	if (Check(number < 0 && (expon & 0X01) == 0, ELevel._Info, __FUNCTION__, "complex number", NULL)) {
		return NAN;
	}
	bool inve = (expon < 0) ? (expon = -expon, true) : false;
	char sign = (number < 0.0) ? (number = -number, -1) : +1;
	if (expon == 1 || number == 0.0) {
		return sign * (inve ? 1 / number : number);
	}
	(number < 1.0) ? (preci *= number * number) : preci;

	long count = 0;
	double xx = number;
	double px = Power(xx, expon);
	double x0 = 0.0;
	double p0 = Power(x0, expon);
	double x1 = x0 - (x0 - xx) * (p0 - number) / (p0 - px);
	while (preci < Absolute(x1 - x0)) {
		x0 = x1;
		p0 = Power(x0, expon);
		x1 = x0 - (x0 - xx) * (p0 - number) / (p0 - px);
		count += 1;
	}

	fprintf(stdout, "%ld\n", count);
	return sign * (inve ? 1 / x1 : x1);
}


/* Base_Bisection
 val = X^2
Xn+1 = (Xn-1 + Xn)/2
*/
double Base_Bisection(double number, long expon, double preci) {
	if (Check(preci < 0, ELevel._Error, __FUNCTION__, "preci < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (expon == 0) {
		return NAN;
	}
	if (Check(number < 0 && (expon & 0X01) == 0, ELevel._Info, __FUNCTION__, "complex number", NULL)) {
		return NAN;
	}
	bool inve = (expon < 0) ? (expon = -expon, true) : false;
	char sign = (number < 0.0) ? (number = -number, -1) : +1;
	if (expon == 1 || number == 0.0) {
		return sign * (inve ? 1 / number : number);
	}
	(number < 1.0) ? (preci *= number * number) : preci;

	long count = 0;
	double x0 = 0.0;
	double x1 = number;
	double x2 = (x0 + x1) / 2;
	while (preci < Absolute(x1 - x0)) {
		if (number <= Power(x2, expon)) {
			x1 = x2;
		}
		else {
			x0 = x2;
		}
		x2 = (x0 + x1) / 2;
		count += 1;
	}
	fprintf(stdout, "%ld\n", count);
	return sign * (inve ? 1 / x2 : x2);
}

////////////////////////////////////////////////////////////////////////////////

void Test_Base() {
	double number = -1001;
	long expon = -3;
	double preci = 0.00005;
	double root = 0;

	root = Base_Tangent(number, expon, preci);
	fprintf(stdout, "root = %.10lf, diff = %.10lf""\n", root, Power(root, expon) - number);

	root = Base_Secant(number, expon, preci);
	fprintf(stdout, "root = %.10lf, diff = %.10lf""\n", root, Power(root, expon) - number);

	root = Base_Secant_Fixed(number, expon, preci);
	fprintf(stdout, "root = %.10lf, diff = %.10lf""\n", root, Power(root, expon) - number);

	root = Base_Bisection(number, expon, preci);
	fprintf(stdout, "root = %.10lf, diff = %.10lf""\n", root, Power(root, expon) - number);
}


void Test_Absolute_Outer_Cover_Round_Inner_Under() {
	fprintf(stdout, "%lf\n", Absolute(1.50));
	fprintf(stdout, "%lf\n", Absolute(-1.50));

	fprintf(stdout, "%ld\n", Outer(1.49));
	fprintf(stdout, "%ld\n", Outer(-1.49));

	fprintf(stdout, "%ld\n", Cover(1.49));
	fprintf(stdout, "%ld\n", Cover(-1.49));

	fprintf(stdout, "%ld\n", Round(1.49));
	fprintf(stdout, "%ld\n", Round(-1.49));
	fprintf(stdout, "%ld\n", Round(1.50));
	fprintf(stdout, "%ld\n", Round(-1.50));

	fprintf(stdout, "%ld\n", Inner(1.49));
	fprintf(stdout, "%ld\n", Inner(-1.49));

	fprintf(stdout, "%ld\n", Under(1.49));
	fprintf(stdout, "%ld\n", Under(-1.49));
}


void Test_Power() {
	long number = 3;
	long expo = 3;
	// double power = Power_Recursion(number, expo);
	double power = Power(number, expo);
	fprintf(stdout, "%lf""\n", power);
}

int main(int argc, char *argv[]) {
	// Test_Absolute_Outer_Cover_Round_Inner_Under();
	// Test_Base();
	Test_Power();

	return 0;
}