/* Math.c
Author: BSS9395
Update: 2020-11-07T23:36:00+08@China-Guangdong-Zhanjiang+08
Design: Math Library
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

double Absol(double value) {
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

bool Accuracy(double lhs, double rhs, double preci) {
	double absol = (lhs >= rhs) ? (lhs - rhs) : (rhs - lhs);
	return (absol <= preci);
}

#define Power Power_Integer_Classic
double Power_Integer_Classic(double value, long expon) {
	bool inver = (expon < 0) ? (expon = -expon, true) : false;
	double power = 1;
	for (long i = 0; i < expon; i += 1) {
		power *= value;
	}
	if (inver) {
		power = 1 / power;
	}
	return power;
}

/*
 F(X) 「 F(Xn) + F'(Xn)，(X - Xn)
	X = Xn - F(Xn)/F'(Xn)       # F(X) 《 0
 Xn+1 = Xn - F(Xn)/F'(Xn)

  val = X^2
 F(X) = X^2 - val
F'(X) = 2，X
 Xn+1 = Xn - (Xn^2 - val)/(2，Xn)
 Xn+1 = 1/2，(Xn + val/Xn)

  val = X^exp
 F(X) = X^exp - val
F'(X) = exp，X^(exp - 1)
 Xn+1 = Xn - (Xn^exp - val)/[exp，Xn^(exp - 1)]
 Xn+1 = [(exp - 1)，Xn + val/Xn^(exp - 1)]/exp
*/
double Radix_Tangent(double value, long expon, double preci) {
	if (Check(value < 0 || preci < 0, ELevel._Warn, __FUNCTION__, "value < 0 || preci < 0", NULL)) {
		return NAN;
	}
	long count = 0;
	double x0 = value;
	// double x1 = 0.50 * (x0 + value / x0);
	double x1 = ((expon - 1) * x0 + value / Power(x0, expon - 1)) / expon;
	while (!Accuracy(x1, x0, preci)) {
		x0 = x1;
		// x1 = 0.50 * (x0 + value / x0);
		x1 = ((expon - 1) * x0 + value / Power(x0, expon - 1)) / expon;
		count += 1;
	}
	fprintf(stdout, "%ld\n", count);
	return x1;
}

/*
  F(X) 「 F(Xn) + F'(Xn)，(X - Xn)
	 X = Xn - F(Xn)/F'(Xn)       # F(X) 《 0
  Xn+1 = Xn - F(Xn)/F'(Xn)

   val = X^2
  F(X) = X^2 - val
F'(Xn) 「 [F(Xn) - F(Xn-1)]/(Xn - Xn-1)
F'(Xn) 「 [(Xn^2 - val) - (Xn-1^2 - val)]/(Xn - Xn-1)
F'(Xn) 「 Xn + Xn-1
  Xn+1 = Xn - (Xn^2 - val)/(Xn + Xn-1)
  Xn+1 = (Xn，Xn-1 + val)/(Xn + Xn-1)

   val = X^exp
  F(X) = X^exp - val
F'(Xn) 「 [F(Xn) - F(Xn-1)]/(Xn - Xn-1)
  Xn+1 = Xn - F(Xn)/F'(Xn)
  Xn+1 = Xn - F(Xn)/[F(Xn) - F(Xn-1)]*(Xn - Xn-1)
  Xn+1 = Xn - (Xn - Xn-1) *
*/
double Radix_Secant(double value, long expon, double preci) {
	if (Check(value < 0 || preci < 0, ELevel._Warn, __FUNCTION__, "value < 0 || preci < 0", NULL)) {
		return NAN;
	}
	long count = 0;
	double x0 = value / 2;
	double x1 = value;
	//double x2 = (x1 * x0 + value) / (x1 + x0);
	double x2 = x1 - (x1 - x0) * (Power(x1, expon) - value) / (Power(x1, expon) - Power(x0, expon));
	while (!Accuracy(x2, x1, preci)) {
		x0 = x1;
		x1 = x2;
		//x2 = (x1 * x0 + value) / (x1 + x0);
		x2 = x1 - (x1 - x0) * (Power(x1, expon) - value) / (Power(x1, expon) - Power(x0, expon));
		count += 1;
	}
	fprintf(stdout, "%ld\n", count);
	return x2;
}


/*
 val = X^2
Xn+1 = (Xn-1 + Xn)/2
*/
double Radix_Bisection(double value, long expon, double preci) {
	if (Check(value < 0 || preci < 0, ELevel._Warn, __FUNCTION__, "value < 0 || preci < 0", NULL)) {
		return NAN;
	}
	long count = 0;
	double x0 = 0;
	double x1 = value;
	double x2 = (x0 + x1) / 2;
	while (!Accuracy(x0, x1, preci)) {
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
	return x2;
}

void Test_Radix() {
	double value = 1001;
	long expon = 3;
	double preci = 0.000005;
	double root = 0;

	root = Radix_Tangent(value, expon, preci);
	fprintf(stdout, "root = %.10lf, diff = %.10lf""\n", root, Power(root, expon) - value);

	root = Radix_Secant(value, expon, preci);
	//root = Radix_Secant(101, 2, preci);
	fprintf(stdout, "root = %.10lf, diff = %.10lf""\n", root, Power(root, expon) - value);

	root = Radix_Bisection(value, expon, preci);
	fprintf(stdout, "root = %.10lf, diff = %.10lf""\n", root, Power(root, expon) - value);
}

void Test_Abso_Outer_Cover_Round_Inner_Under() {
	fprintf(stdout, "%lf\n", Absol(1.50));
	fprintf(stdout, "%lf\n", Absol(-1.50));

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

