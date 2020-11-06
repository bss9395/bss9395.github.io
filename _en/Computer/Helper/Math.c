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
	Test_Abso_Outer_Cover_Round_Inner_Under();

	return 0;
}

