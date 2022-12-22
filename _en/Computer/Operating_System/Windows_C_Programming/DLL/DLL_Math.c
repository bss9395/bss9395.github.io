/* Math.c
Author: BSS9395
Update: 2022-12-10T21:18:00+08@China-Shanghai+08
Design: DLL Library: Math
*/

/* Usage:
cl /LDd Math.c    // Debug Version
cl /LD  Math.c    // Release Version
*/

__declspec(dllexport) double Add(double a, double b) {
	return (a + b);
}

__declspec(dllexport) double Sub(double a, double b) {
	return (a - b);
}

__declspec(dllexport) double Mul(double a, double b) {
	return (a * b);
}
