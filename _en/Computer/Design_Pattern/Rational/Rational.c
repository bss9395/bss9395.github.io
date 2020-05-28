/* Rational.c
Author: BSS9395
Update: 2020-05-28T17:47:00+08@China-Guangdong-Zhanjiang+08
*/

#define _CRT_SECURE_NO_WARNINGS
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef unsigned char  uchar;
typedef unsigned short ushort;
typedef unsigned int   uint;

typedef void *(*CALLOC)(size_t _Count, size_t _Size);
typedef void *(*READLLOC)(void *_Block, size_t _Size);
typedef double(*LOG)(double x);
struct {
	CALLOC Calloc;
	READLLOC Realloc;
	LOG Log2;
} CStd = {
	.Calloc = calloc,
	.Realloc = realloc,
	.Log2 = log2,
};

////////////////////////////////////////

typedef const uchar *Level;
typedef const uchar *Type;
const struct {
	Level _Info;
	Level _ToDo;
	Level _Warn;
	Level _Error;
	Level _Fatal;

	Type _Integer;
	Type _Rational;
	Type _String;
} EType = {
	._Info = "Info",
	._ToDo = "ToDo",
	._Warn = "Warn",
	._Error = "Error",
	._Fatal = "Fatal",

	._Integer = "Integer",
	._Rational = "Rational",
	._String = "String",
};

typedef long iptr;
typedef ushort unit;
typedef uint   dual;
typedef struct {
	iptr _expo;
	unit *_lsu;
} Integer;

struct {
	const double _Epsilon;
	const uchar _Space[7];
	const uchar _Digit[256];

	const uint _Base;
	const uint _Mask;
	const uint _Shift;
	double _Log2_Base[16 + 1];
} EData = {
	._Epsilon = 1e-27,
	._Space = " \t\n\v\f\r",
	._Digit = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
		'?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',
		' ', '!', '?', '?', '?', '%', '&', '?',	'(', ')', '*', '+', '?', '-', '.', '/',
		  0,   1,	2,   3,   4,   5,   6,   7,   8,   9, '?', '?',	'?', '?', '?', '?',
		'?',  10,  11,  12,  13,  14,  15, '?', '?', '?', '?', '?', '?', '?', '?', '?',
		'?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '^', '_',
		'?',  10,  11,  12,  13,  14,  15, '?', '?', '?', '?', '?', '?', '?', '?', '?',
		'?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '|', '?', '~', '?',

		'?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',
		'?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',
		'?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',
		'?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',
		'?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',
		'?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',
		'?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',
		'?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',
	},

	._Base = (1U << (sizeof(unit) * 8 - 1)),
	._Mask = (1U << (sizeof(unit) * 8 - 1)) - 1,
	._Shift = sizeof(unit) * 8 - 1,
};

////////////////////////////////////////

inline bool Check(const bool failed, const uchar *function, const Level level, const uchar *record, const uchar *extra) {
	if (failed) {
		fprintf(stderr, "[%s#%s] %s%s; ""\n", function, level, record, extra == NULL ? "" : extra);
	}

	errno = 0;
	return failed;
}

inline iptr Skip(const uchar *data, const uchar space[]) {
	const uchar *ret = data;
	for (int i = 0; data[0] != '\0'; data += 1) {
		i = 0;
		while (space[i] != '\0' && data[0] != space[i]) {
			i += 1;
		}
		if (space[i] == '\0') {
			break;
		}
	}

	return (iptr)(data - ret);
}

////////////////////////////////////////

/* Representation of Integer
Unit  Representation
== B_{EXPO - 1} * BASE^{EXPO - 1} + B_{EXPO - 2} * BASE^{EXPO - 2} + ... + B_{1} * BASE^{1} + B_{0} * BASE^{0}  // BASE == 2^(16 - 1)
== b_{expo - 1} * base^(expo - 1) + b_{expo - 2} * base^(expo - 2) + ... + b_{1} * base^(1) + B_{0} * base^(0)  // base == 10 or 2 or 8 or 16 ...
Digit Representation

=> 1 * BASE^EXPO >= 1 * base^expo                    // Boundary Condition
=> EXPO >= Ceil(expo * Log2(base) / Log2(BASE)) + 1  // Absolute Assurance
*/

/*
	   b_{n - 1} % BASE = R
	   b_{n - 1} / BASE = Q
=> b_{n - 1} = Q * BASE + R
											   // b_{n - 2} is to be dealed with
=>      (b_{n - 1} * base + b_{n - 2}) % BASE
== ((Q * BASE + R) * base + b_{n - 2}) % BASE
==              (R * base + b_{n - 2}) % BASE
											   // yield Carry
=>      (b_{n - 1} * base + b_{n - 2}) / BASE
== ((Q * BASE + R) * base + b_{n - 2}) / BASE
==                   (Q * BASE * base) / BASE + Carry
==                                   Q * base + Carry
											   // recursively forward
*/
iptr Parse(Integer *inte, const uchar *data, int base) {
	if (Check(!(2 <= base && base <= 16), __FUNCTION__, EType._Error, "!(2 <= base && base <= 36)", NULL)) {
		return 0;
	}
	const uchar *ret = data;
	data += Skip(data, EData._Space);

	char sign = +1;
	if (data[0] == '+') {
		data += 1;
		sign = +1;
	}
	else if (data[0] == '-') {
		data += 1;
		sign = -1;
	}

	if (data[0] == '0') {
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
	data += Skip(data, "0_,");

	iptr expo = 0;
	const uchar *digit = data;
	while (digit[0] != '\0') {
		if (EData._Digit[digit[0]] <= base) {
			digit += 1;
			expo += 1;
		}
		else if (digit[0] == '_' || digit[0] == ',') {
			digit += 1;
		}
		else {
			break;
		}
	}

	if (EData._Log2_Base[base] <= EData._Epsilon) {
		EData._Log2_Base[base] = CStd.Log2(base + EData._Epsilon) / CStd.Log2(EData._Base);
	}

	iptr _expo = (iptr)(expo * EData._Log2_Base[base]) + 1;
	unit *_lsu = (unit *)CStd.Calloc(_expo, sizeof(unit));
	_expo = 1;
	dual carry = 0;
	while (data < digit) {
		if (data[0] == '_' || data[0] == ',') {
			data += 1;
		}
		else {
			carry = EData._Digit[data[0]];             // fetch b_{n - 2}
			data += 1;

			for (iptr i = 0; i < _expo; i += 1) {
				carry = _lsu[i] * base + carry;        // yield (divisor)
				_lsu[i] = (unit)(carry & EData._Mask); // yield (divisor % BASE)
				carry >>= EData._Shift;                // yield (divisor / BASE)
			}
			if (carry != 0) {
				_lsu[_expo] = carry;
				_expo += 1;
			}
		}
	}
	inte->_expo = sign * _expo;
	inte->_lsu = _lsu;

	return (iptr)(data - ret);
}



////////////////////////////////////////

int main(int argc, uchar *argv[]) {

	Integer inte;
	Parse(&inte, "-2163200", 10);

	fprintf(stderr, "%ld, %d, %d \n", inte._expo, inte._lsu[0], inte._lsu[1]);


	return 0;
}