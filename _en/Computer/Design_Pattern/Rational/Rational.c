/* Rational.c
Author: BSS9395
Update: 2020-05-29T18:34:00+08@China-Guangdong-Zhanjiang+08
Design: Rational Number
*/

/* Integer Range
   BASE = 2^{16}     = 2^{2^{4}}
   EXPO = 2^{29} - 1 = 2^{sizeof(iptr) * 8 - 3} - 1

±  1 * BASE^{EXPO} - 1
== 1 * (2^{16})^{2^{29} - 1} - 1
== (2^{2^{4} * 2^{29}}) / (2^{16}) - 1
== (2^{2^{33}}) / (2^{16}) - 1
== (2^{2^{4 + sizeof(iptr) * 8 - 3} - 1
*/

////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define Calloc  calloc
#define Realloc realloc
#define Memset  memset
#define Log2    log2

////////////////////////////////////////

typedef long iptr;
typedef unsigned char  uchar;
typedef unsigned short ushort;
typedef unsigned int   uint;

typedef uchar  unit;
// typedef ushort unit;
typedef uint   dual;
typedef struct {
	iptr _sign : 2;
	iptr _expo : (sizeof(iptr) * 8 - 2);
	unit *_lsu;
} Integer;

iptr Parse(Integer *integer, const uchar *data, int base);
Integer Add(Integer lhs, Integer rhs);
Integer Sub(Integer lhs, Integer rhs);

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

	._Base = (1U << (sizeof(unit) * 8)),
	._Mask = (1U << (sizeof(unit) * 8)) - 1,
	._Shift = sizeof(unit) * 8,
};

////////////////////////////////////////

inline iptr Absolute(iptr value) {
	return (value < 0 ? -value : value);
}

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
== B_{EXPO - 1} * BASE^{EXPO - 1} + B_{EXPO - 2} * BASE^{EXPO - 2} + ... + B_{1} * BASE^{1} + B_{0} * BASE^{0}  // BASE == 2^{16}
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
											   // accumulate recursively
*/
iptr Parse(Integer *integer, const uchar *data, int base) {
	if (Check(!(2 <= base && base <= 16), __FUNCTION__, EType._Error, "!(2 <= base && base <= 36)", NULL)) {
		return 0;
	}
	const uchar *ret = data;
	data += Skip(data, EData._Space);

	char _sign = +1;
	if (data[0] == '+') {
		data += 1;
		_sign = +1;
	}
	else if (data[0] == '-') {
		data += 1;
		_sign = -1;
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
		EData._Log2_Base[base] = Log2(base + EData._Epsilon) / Log2(EData._Base);
	}

	iptr _expo = (iptr)(expo * EData._Log2_Base[base]) + 1;
	unit *_lsu = (unit *)Calloc(_expo, sizeof(unit));
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
	integer->_sign = _sign;
	integer->_expo = _expo;
	integer->_lsu = _lsu;

	return (iptr)(data - ret);
}

Integer Neg(Integer integer) {
	integer._sign *= -1;
	return integer;
}

/*
Abs(lhs->_expo) >= Abs(rhs->_expo)
			  B_{EXPO - 1} * BASE^{EXPO - 1} + ... + B_{1} * BASE^{1} + B_{0} * BASE^{0}
+             C_{EXPO - 1} * BASE^{EXPO - 1} + ... + c_{1} * base^{1} + C_{0} * BASE^{0}            // yield Carry
=  ... + (B_{1} + C_{1} + Carry_{1}) * BASE^{1} + (B_{0} + C_{0} + Carry_{0}) * BASE^{0}            // accumulate recursively
 + Carry_{EXPO} * BASE^{EXPO} + (B_{EXPO - 1} + C_{EXPO - 1} + Carry_{EXPO - 1}) * BASE^{EXPO - 1}
*/
Integer Add(Integer lhs, Integer rhs) {
	// lhs and rhs have opposite signs
	if ((lhs._sign ^ rhs._sign) < 0) {
		/*
				(+)   (-)    (+)   (  + )
		case 1: lhs + rhs == lhs - (-rhs)
		case 2: lhs + rhs == lhs - (-rhs)
				(-)   (+)    (-)   (  - )
		*/
		return Sub(lhs, Neg(rhs));
	}
	Integer ret;
	int _sign = lhs._sign;

	if (lhs._expo < rhs._expo) {
		Integer swap = lhs; lhs = rhs; rhs = swap;
		_sign *= +1;
	}
	unit *_lsu = (unit *)Calloc(lhs._expo + 1, sizeof(unit));

	dual carry = 0;
	iptr i = 0;
	for (; i < rhs._expo; i += 1) {
		carry = lhs._lsu[i] + rhs._lsu[i] + carry;
		_lsu[i] = (unit)(carry & EData._Mask);
		carry >>= EData._Shift;
	}
	for (; i < lhs._expo; i += 1) {
		carry = lhs._lsu[i] + carry;
		_lsu[i] = (unit)(carry & EData._Mask);
		carry >>= EData._Shift;
	}
	if (carry != 0) {
		_lsu[i] = carry;
		i += 1;
	}

	ret._sign = _sign;
	ret._expo = i;
	ret._lsu = _lsu;
	return ret;
}

/*
Abs(lhs->_expo) >= Abs(rhs->_expo)
							  B_{EXPO - 1} * BASE^{EXPO - 1} + ... + B_{1} * BASE^{1} + B_{0} * BASE^{0}
-                             C_{EXPO - 1} * BASE^{EXPO - 1} + ... + C_{1} * BASE^{1} + C_{0} * BASE^{0}            // yield Borrow
=  ... + (B_{1} - C_{1} - Borrow_{1} + BASE)%BASE * BASE^{1} + (B_{0} - C_{0} - Borrow_{0} + BASE)%BASE * BASE^{0}  // attenuate recursively
 + (B_{EXPO - 1} - C_{EXPO - 1} - Borrow_{EXPO - 1} + BASE)%BASE * BASE^{EXPO - 1}
*/
Integer Sub(Integer lhs, Integer rhs) {
	// lhs and rhs have opposite signs
	if ((lhs._sign ^ rhs._sign) < 0) {
		/*
				(+)   (-)    (+)   (  + )
		case 3: lhs - rhs == lhs + (-rhs)
		case 4: lhs - rhs == lhs + (-rhs)
				(-)   (+)    (-)   (  - )
		*/
		return Add(lhs, Neg(rhs));
	}
	Integer ret;
	int _sign = lhs._sign;

	if (lhs._expo < rhs._expo) {
		Integer swap = lhs; lhs = rhs;	rhs = swap;
		_sign *= -1;
	}
	iptr _expo = lhs._expo;
	if (lhs._expo == rhs._expo) {
		while (0 < _expo && lhs._lsu[_expo - 1] == rhs._lsu[_expo - 1]) {
			_expo -= 1;
		}
		if (_expo <= 0) {
			ret._sign = +1;
			ret._expo = 1;
			ret._lsu = (unit *)Calloc(1, sizeof(unit));
			ret._lsu[0] = (unit)0U;
			return ret;
		}
		else if (lhs._lsu[_expo - 1] < rhs._lsu[_expo - 1]) {
			Integer swap = lhs; lhs = rhs;	rhs = swap;
			_sign *= -1;
		}
	}
	unit *_lsu = (unit *)Calloc(_expo, sizeof(unit));

	dual borrow = 0;
	iptr i = 0;
	for (; i < rhs._expo; i += 1) {
		borrow = lhs._lsu[i] - rhs._lsu[i] - borrow;
		_lsu[i] = (unit)(borrow & EData._Mask);
		borrow >>= EData._Shift;
		borrow &= 1U;             // borrow 1 from higher unit
	}
	for (; i < _expo; i += 1) {
		borrow = lhs._lsu[i] - borrow;
		_lsu[i] = (unit)(borrow & EData._Mask);
		borrow >>= EData._Shift;
		borrow &= 1U;             // borrow 1 from higher unit
	}

	ret._sign = _sign;
	ret._expo = i;
	ret._lsu = _lsu;
	return ret;
}


/*
									 B_{EXPO-1}*BASE^{EXPO-1} + ... + B_{1}*BASE^{1} + B_{0}*BASE^{0}
×                                    C_{EXPO-1}*BASE^{EXPO-1} + ... + C_{1}*BASE^{1} + C_{0}*BASE^{0}
==

|| *BASE^{2*EXPO-1}    *BASE^{EXPO+1}                *BASE^{EXPO}		       *BASE^{EXPO-1}		       *BASE^{1}		      *BASE^{0}
++                                                      Carry_{0}     (B_{0}*C_{EXPO-1})%BASE ...（B_{0}*C_{1})%BASE     (B_{0}*C_{0})%BASE
++  				        Carry_{1}     (B_{1}*C_{EXPO-1})%BASE ...      (B_{1}*C_{1})%BASE     (B_{1}*C_{0})%BASE
++				    ...
++   Carry_{EXPO-1}     (B_{EXPO-1}*C_{EXPO-1})%BASE ... (B_{EXPO-1}*C_{1})%BASE   (B_{EXPO-1}*C_{0})%BASE
==
*/
Integer Mul(Integer lhs, Integer rhs) {
	Integer ret;

	int _sign = lhs._sign * rhs._sign;
	iptr _expo = lhs._expo + rhs._expo;
	unit *_lsu = (unit *)Calloc(_expo, sizeof(unit));

	/* constraint assurance
	BASE * BASE - 1                                          // Dual Unit
	==  (BASE - 1) +  (BASE - 1) * (BASE - 1)  + (BASE - 1)
	>= _lsu[i + 1] + lhs._lsu[i] * rhs._lsu[j] + Carry
	*/
	dual carry = 0;
	for (iptr i = 0; i < lhs._expo; i += 1) {
		carry = 0;
		for (iptr j = 0; j < rhs._expo; j += 1) {
			carry = _lsu[i + j] + lhs._lsu[i] * rhs._lsu[j] + carry;
			_lsu[i + j] = (unit)(carry & EData._Mask);
			carry >>= EData._Shift;

		}
		_lsu[i + rhs._expo] = carry;
	}

	ret._sign = _sign;
	ret._expo = (carry != 0 ? _expo : _expo - 1);
	ret._lsu = _lsu;
	return ret;
}

////////////////////////////////////////

void Test_Integer() {
	Integer inte;
	Parse(&inte, "-2,5_6", 10);
	Parse(&inte, "131072", 10);
	Parse(&inte, "0x0000", 10);

	fprintf(stderr, "[%d, %ld] ", inte._sign, inte._expo);
	iptr _expo = inte._expo;
	for (_expo -= 1; 0 <= _expo; _expo -= 1) {
		fprintf(stderr, "%d ", inte._lsu[_expo]);
	}
	fprintf(stderr, "\n");
}

void TestAdd() {
	Integer inte1;
	Integer inte2;
	Parse(&inte1, "-128", 10);
	Parse(&inte2, "-256", 10);

	// Integer inte3 = Add(inte1, inte2);
	Integer inte3 = Sub(inte1, inte2);

	fprintf(stderr, "[%d, %ld] ", inte3._sign, inte3._expo);
	iptr _expo = inte3._expo;
	for (_expo -= 1; 0 <= _expo; _expo -= 1) {
		fprintf(stderr, "%d ", inte3._lsu[_expo]);
	}
	fprintf(stderr, "\n");
}

void TestMul() {
	Integer inte1;
	Integer inte2;
	Parse(&inte1, "-256", 10);
	Parse(&inte2, "+256", 10);

	Integer inte3 = Mul(inte1, inte2);

	fprintf(stderr, "[%d, %ld] ", inte3._sign, inte3._expo);
	iptr _expo = inte3._expo;
	for (_expo -= 1; 0 <= _expo; _expo -= 1) {
		fprintf(stderr, "%d ", inte3._lsu[_expo]);
	}
	fprintf(stderr, "\n");
}

int main(int argc, uchar *argv[]) {

	// TestInteger();
	// TestAdd();
	TestMul();

	return 0;
}