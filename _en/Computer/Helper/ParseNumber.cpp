/*ParseNumber.cpp
* Author: BSS9395
* Update: 2020-01-15T23:47:00+08@ShenZhen+08
*/

#include <math.h>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;


double ParseNumber(char *&data, double base = 10.0) {
	int sign = +1;
	double value = 0.0;

	if (data[0] == '(') {
		data += 1;
		value = ParseNumber(data, base);
		if (data[0] != ')') {
			throw ')';
		}
		data += 1;
	}
	else if (data[0] == '+') {
		data += 1;
		sign = +1;
	}
	else if (data[0] == '-') {
		data += 1;
		sign = -1;
	}
	else if (data[0] == '0') {
		data += 1;
		if (data[0] == 'b' || data[0] == 'B') {
			data += 1;
			base = 2;
		}
		else if (data[0] == 'o' || data[0] == 'O') {
			data += 1;
			base = 8;
		}
		else if (data[0] == 'x' || data[0] == 'X') {
			data += 1;
			base = 16;
		}
	}

	if (2.0 <= base && base <= +10.0) {
		char range = (char)('0' + base);
		while ('0' <= data[0] && data[0] < range) {
			value = value * base + (data[0] - '0');
			data += 1;
		}
	}
	else if (+10.0 < base && base <= +36.0) {
		while (true) {
			if ('0' <= data[0] && data[0] <= '9') {
				value = value * base + (data[0] - '0');
			}
			else if ('a' <= data[0] && data[0] <= 'z') {
				value = value * base + (data[0] - 'a');
			}
			else if ('A' <= data[0] && data[0] <= 'Z') {
				value = value * base + (data[0] - 'A');
			}
			else {
				break;
			}
			data += 1;
		}
	}
	if (data[0] == '.') {
		data += 1;
		if (2.0 <= base && base <= +10.0) {
			char range = (char)('0' + base);
			double factor = 1 / base;
			while ('0' <= data[0] && data[0] < range) {
				value = value + (data[0] - '0') * factor;
				data += 1;
				factor *= factor;
			}
		}
		else if (10.0 < base && base <= 36.0) {
			double factor = 1 / base;
			while (true) {
				if ('0' <= data[0] && data[0] <= '9') {
					value = value + (data[0] - '0') * factor;
				}
				else if ('a' <= data[0] && data[0] <= 'z') {
					value = value + (data[0] - 'a') * factor;
				}
				else if ('A' <= data[0] && data[0] <= 'Z') {
					value = value + (data[0] - 'A') * factor;
				}
				else {
					break;
				}
				data += 1;
				factor *= factor;
			}
		}
	}

	if (base == 10 && (data[0] == 'e' || data[0] == 'E')) {
		data += 1;
		double expo = ParseNumber(data, 10);
		value = value * pow(10, expo);
	}
	else if (base == 10 && data[0] == '^') {
		data += 1;
		double expo = ParseNumber(data, 10);
		value = pow(value, expo);
	}

	value *= sign;
	return value;
}


int ParseNumberArray(char *address, char *&data, double base = 10.0) {
	char *pointer = address;
	double value = 0.0;
	while (value = ParseNumber(data, base), value != 0.0) {
		memcpy(pointer, &value, sizeof(value));
		pointer += sizeof(value);

		while (data[0] == ',' || data[0] == ' ') {
			data += 1;
		}
	}
	return (int)(pointer - address);
}

#define Main
#ifdef Main
int main(int argc, char *argv[]) {
	char data1[] = "-10^-2";
	char *ptr1 = data1;
	cerr << ParseNumber(ptr1, 10) << endl;
	cerr << (ptr1 - data1) << endl;

	char data2[] = "-10E-2";
	char *ptr2 = data2;
	cerr << ParseNumber(ptr2, 10) << endl;
	cerr << (ptr2 - data2) << endl;

	char data3[] = "";
	char *ptr3 = data3;
	cerr << ParseNumber(ptr3, 10) << endl;
	cerr << (ptr3 - data3) << endl;

	return 0;
}
#endif // Main