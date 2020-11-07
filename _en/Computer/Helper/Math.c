/* Math.c
Author: BSS9395
Update: 2020-11-08T01:08:00+08@China-Guangdong-Zhanjiang+08
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

			   Inner Under                | Outer  Cover
lhs  rhs  quot  rema  modu  Inner  Under  |  Modu  Rema  Outer  Cover
 12   10     1     2     2      1      1  |    -8    -8      2     2
-12   10    -1    -2     8     -1     -2  |     8    -2     -2    -1
 12  -10    -1     2    -8     -1     -2  |    -8     2     -2    -1
-12  -10     1    -2    -2      1      1  |     8     8      2     2
										  |
 10   12     0    10    10      0      0  |    -2    -2      1     1
-10   12     0   -10     2      0     -1  |     2   -10     -1     0
 10  -12     0    10    -2      0     -1  |    -2    10     -1     0
-10  -12     0   -10   -10      0      0  |     2     2      1     1
*/

double Absolute(double value) {
	return ((value < 0) ? -value : value);
}

long Outer(double value) {
	long outer = (long)value;
	if (outer < 0) {
		return (outer == value) ? outer : (outer - 1);
	}
	return (outer == value) ? outer : (outer + 1);
}

long Cover(double value) {
	long over = (long)value;
	if (over < 0) {
		return over;
	}
	return (over == value) ? over : (over + 1);
}

long Round(double value) {
	long round = (long)value;
	if (round < 0) {
		return (value <= round - 0.50) ? (round - 1) : round;
	}
	return (round + 0.50 <= value) ? (round + 1) : round;
}

long Inner(double value) {
	return (long)value;
}

long Under(double value) {
	long under = (long)value;
	if (under < 0) {
		return (under == value) ? under : (under - 1);
	}
	return under;
}

#define Power Power_Classic
double Power_Classic(double value, long expon) {
	bool inve = (expon < 0) ? (expon = -expon, true) : false;
	in08 sign = (value < 0.0) ? (value = -value, -1) : +1;
	if (expon == 1 || value == 0.0) {
		return sign * (inve ? 1 / value : value);
	}

	double power = 1;
	for (long i = 0; i < expon; i += 1) {
		power *= value;
	}
	return sign * (inve ? 1 / power : power);
}

double Radix_Square(double value, double preci) {
	if (Check(preci < 0, ELevel._Error, __FUNCTION__, "preci < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (Check(value < 0, ELevel._Info, __FUNCTION__, "complex number", NULL)) {
		return NAN;
	}
	if (value == 0.0) {
		return 0.0;
	}
	(value < 1.0) ? (preci *= value * value) : preci;

	long count = 0;
	double x0 = value;
	double x1 = 0.50 * (x0 + value / x0);
	while (preci < Absolute(x1 - x0)) {
		x0 = x1;
		x1 = 0.50 * (x0 + value / x0);
		count += 1;
	}
	fprintf(stdout, "%ld\n", count);
	return x1;
}

/* Radix_Tangent
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
double Radix_Tangent(double value, long expon, double preci) {
	if (Check(preci < 0, ELevel._Error, __FUNCTION__, "preci < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (Check(value < 0 && expon % 2 == 0, ELevel._Info, __FUNCTION__, "complex number", NULL)) {
		return NAN;
	}
	if (expon == 0) {
		return NAN;
	}
	bool inve = (expon < 0) ? (expon = -expon, true) : false;
	in08 sign = (value < 0.0) ? (value = -value, -1) : +1;
	if (expon == 1 || value == 0.0) {
		return sign * (inve ? 1 / value : value);
	}
	(value < 1.0) ? (preci *= value * value) : preci;

	long count = 0;
	double x0 = value;
	double x1 = ((expon - 1) * x0 + value / Power(x0, expon - 1)) / expon;
	while (preci < Absolute(x1 - x0)) {
		x0 = x1;
		x1 = ((expon - 1) * x0 + value / Power(x0, expon - 1)) / expon;
		count += 1;
	}
	fprintf(stdout, "%ld\n", count);
	return sign * (inve ? 1 / x1 : x1);
}

/* Radix_Secant
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
double Radix_Secant(double value, long expon, double preci) {
	if (Check(preci < 0, ELevel._Error, __FUNCTION__, "preci < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (Check(value < 0 && expon % 2 == 0, ELevel._Info, __FUNCTION__, "complex number", NULL)) {
		return NAN;
	}
	if (expon == 0) {
		return NAN;
	}
	bool inve = (expon < 0) ? (expon = -expon, true) : false;
	in08 sign = (value < 0.0) ? (value = -value, -1) : +1;
	if (expon == 1 || value == 0.0) {
		return sign * (inve ? 1 / value : value);
	}
	(value < 1.0) ? (preci *= value * value) : preci;

	long count = 0;
	double x0 = value / 2;
	double x1 = value;
	double p0 = Power(x0, expon);
	double p1 = Power(x1, expon);
	double x2 = x1 - (x1 - x0) * (p1 - value) / (p1 - p0);
	while (preci < Absolute(x2 - x0) || preci < Absolute(x2 - x1)) {
		x0 = x1;
		x1 = x2;
		p0 = p1;
		p1 = Power(x1, expon);
		x2 = x1 - (x1 - x0) * (p1 - value) / (p1 - p0);
		count += 1;
	}
	fprintf(stdout, "%ld\n", count);
	return sign * (inve ? 1 / x2 : x2);
}


/* Radix_Secant_Fixed
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
double Radix_Secant_Fixed(double value, long expon, double preci) {
	if (Check(preci < 0, ELevel._Error, __FUNCTION__, "preci < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (Check(value < 0 && expon % 2 == 0, ELevel._Info, __FUNCTION__, "complex number", NULL)) {
		return NAN;
	}
	if (expon == 0) {
		return NAN;
	}
	bool inve = (expon < 0) ? (expon = -expon, true) : false;
	in08 sign = (value < 0.0) ? (value = -value, -1) : +1;
	if (expon == 1 || value == 0.0) {
		return sign * (inve ? 1 / value : value);
	}
	(value < 1.0) ? (preci *= value * value) : preci;

	long count = 0;
	double xx = value;
	double px = Power(xx, expon);
	double x0 = 0.0;
	double p0 = Power(x0, expon);
	double x1 = x0 - (x0 - xx) * (p0 - value) / (p0 - px);
	while (preci < Absolute(x1 - x0)) {
		x0 = x1;
		p0 = Power(x0, expon);
		x1 = x0 - (x0 - xx) * (p0 - value) / (p0 - px);
		count += 1;
	}

	fprintf(stdout, "%ld\n", count);
	return sign * (inve ? 1 / x1 : x1);
}


/* Radix_Bisection
 val = X^2
Xn+1 = (Xn-1 + Xn)/2
*/
double Radix_Bisection(double value, long expon, double preci) {
	if (Check(preci < 0, ELevel._Error, __FUNCTION__, "preci < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (Check(value < 0 && expon % 2 == 0, ELevel._Info, __FUNCTION__, "complex number", NULL)) {
		return NAN;
	}
	if (expon == 0) {
		return NAN;
	}
	bool inve = (expon < 0) ? (expon = -expon, true) : false;
	in08 sign = (value < 0.0) ? (value = -value, -1) : +1;
	if (expon == 1 || value == 0.0) {
		return sign * (inve ? 1 / value : value);
	}
	(value < 1.0) ? (preci *= value * value) : preci;

	long count = 0;
	double x0 = 0.0;
	double x1 = value;
	double x2 = (x0 + x1) / 2;
	while (preci < Absolute(x1 - x0)) {
		if (value <= Power(x2, expon)) {
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

void Test_Radix() {
	double value = -1001;
	long expon = -3;
	double preci = 0.00005;
	double root = 0;

	root = Radix_Tangent(value, expon, preci);
	fprintf(stdout, "root = %.10lf, diff = %.10lf""\n", root, Power(root, expon) - value);

	root = Radix_Secant(value, expon, preci);
	fprintf(stdout, "root = %.10lf, diff = %.10lf""\n", root, Power(root, expon) - value);

	root = Radix_Secant_Fixed(value, expon, preci);
	fprintf(stdout, "root = %.10lf, diff = %.10lf""\n", root, Power(root, expon) - value);

	root = Radix_Bisection(value, expon, preci);
	fprintf(stdout, "root = %.10lf, diff = %.10lf""\n", root, Power(root, expon) - value);
}


void Test_Abso_Outer_Cover_Round_Inner_Under() {
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

int main(int argc, char *argv[]) {
	// Test_Abso_Outer_Cover_Round_Inner_Under();
	Test_Radix();

	return 0;
}

