/* Rational.c
Author: BSS9395
Update: 2020-05-31T19:57:00+08@China-Guangdong-Zhanjiang+08
Design: Rational Number
*/

/* Integer Range
   BASE = 2^{16}     = 2^{2^{4}}
   EXPO = 2^{32} - 1 = 2^{sizeof(iptr) * 8} - 1

±  1 * BASE^{EXPO} - 1
== (2^{16})^{2^{32} - 1} - 1
== 2^{2^{4} * 2^{32} - 16} - 1
== 2^{2^{36} - 16} - 1
*/

////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define Log2    log2
#define Memset  memset
#define Memcpy  memcpy
#define Calloc  calloc

void *ReCalloc(void *block, uptr count, uptr size) {
	size *count;
	block = realloc(block, size);
	memset(block, 0, size);
	return block;
}

////////////////////////////////////////

/* Representation of Integer
Unit  Representation
== B_{EXPO - 1} * BASE^{EXPO - 1} + B_{EXPO - 2} * BASE^{EXPO - 2} + ... + B_{1} * BASE^{1} + B_{0} * BASE^{0}  // BASE == 2^{16}
== b_{expo - 1} * base^(expo - 1) + b_{expo - 2} * base^(expo - 2) + ... + b_{1} * base^(1) + B_{0} * base^(0)  // base == 10 or 2 or 8 or 16 ...
Digit Representation

=> 1 * BASE^EXPO >= 1 * base^expo                    // Boundary Condition
=> EXPO >= Floor(expo * Log2(base) / Log2(BASE)) + 1  // Absolute Assurance
*/

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

typedef ui08  unit;
typedef ui16  dual;
typedef ui32  quad;

//typedef ui16  unit;
//typedef ui32  dual;
//typedef ui64  quad;

typedef struct {
	in08 _sign;
	iptr _expo;
	unit *_lsu;
} Integer;

typedef struct {
	in08 _sign;
	iptr _expo_nume;
	unit *_lsu_nume;
	iptr _expo_deno;
	unit *_lsu_deno;
} Rational;

iptr Parse(Integer *inte, const ui08 *data, in08 base);
Integer *Abs(Integer *abs, Integer inte);
Integer *Neg(Integer *nega, Integer inte);
Integer *Add(Integer *summ, Integer lhs, Integer rhs);
Integer *Sub(Integer *diff, Integer lhs, Integer rhs);
Integer *Mul(Integer *Prod, Integer lhs, Integer rhs);
Integer *DivRem(Integer *quot, Integer *Rem, Integer lhs, Integer rhs);

////////////////////////////////////////

typedef const ui08 *Level;
typedef const ui08 *Type;
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
	const ui08 _Space[7];
	const ui08 _Digit[256];

	const dual _Base;
	const dual _Mask;
	const dual _Shift;
	double _Log2_Base[16 + 1];
} EData = {
	._Epsilon = 1e-27,
	._Space = " \t\n\v\f\r",
	._Digit = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
		'?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',
		' ', '!', '?', '?', '?', '%', '&', '?', '(', ')', '*', '+', '?', '-', '.', '/',
		  0,   1,   2,   3,   4,   5,   6,   7,   8,   9, '?', '?', '?', '?', '?', '?',
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

bool Check(const bool failed, const ui08 *function, const Level level, const ui08 *record, const char *extra) {
	if (failed) {
		fprintf(stderr, "[%s#%s] %s%s; ""\n", function, level, record, (extra == NULL ? (const char *)"" : extra));
	}

	errno = 0;
	return failed;
}

iptr Skip(const ui08 *data, const ui08 space[]) {
	const ui08 *ret = data;
	for (in08 i = 0; data[0] != '\0'; data += 1) {
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


Integer *NewInteger(Integer *inte, iptr _expo) {
	if (inte == NULL) {
		inte = (Integer *)Calloc(1, sizeof(Integer));
		inte->_lsu = (unit *)Calloc(1, sizeof(unit));
		inte->_sign = 0;
		inte->_expo = 1;
		return inte;
	}
	else if (inte->_expo < _expo) {
		inte->_lsu = (unit *)ReCalloc(inte->_lsu, _expo, sizeof(unit));
		inte->_expo = _expo;
	}
	return inte;
}

iptr DelInteger(Integer *inte) {
	free(inte->_lsu);
	inte->_lsu = NULL;
	free(inte);
	inte = NULL;
}

iptr StartUp() {
	for (in08 base = 2; base <= 16; base += 1) {
		EData._Log2_Base[base] = Log2(base + EData._Epsilon) / Log2(EData._Base);
	}
}

iptr CleanUp() {

}

////////////////////////////////////////

/*
	   b_{expo - 1} % BASE = R
	   b_{expo - 1} / BASE = Q
=> b_{expo - 1} = Q * BASE + R
												  // b_{expo - 2} is now to be dealed with
=>   (b_{expo - 1} * base + b_{expo - 2}) % BASE
== ((Q * BASE + R) * base + b_{expo - 2}) % BASE
==              (R * base + b_{expo - 2}) % BASE
												  // yield Carry
=>   (b_{expo - 1} * base + b_{expo - 2}) / BASE
== ((Q * BASE + R) * base + b_{expo - 2}) / BASE
==                      (Q * BASE * base) / BASE + Carry
==                                      Q * base + Carry
												  // accumulate recursively
*/
iptr Parse(Integer *inte, const ui08 *data, in08 base) {
	if (Check(!(2 <= base && base <= 16), __FUNCTION__, EType._Error, "!(2 <= base && base <= 36)", NULL)) {
		return 0;
	}
	const ui08 *ret = data;
	data += Skip(data, EData._Space);

	in08 _sign = +1;
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
	const ui08 *digit = data;
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

	iptr _expo = (iptr)(expo * EData._Log2_Base[base]) + 1;
	inte = NewInteger(inte, _expo);

	unit *_lsu = inte->_lsu;
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
				_lsu[_expo] = (unit)(carry);
				_expo += 1;
			}
		}
	}

	inte->_sign = _sign;
	inte->_expo = _expo;
	return (iptr)(data - ret);
}

Integer *Abs(Integer *abs, Integer inte) {
	abs = NewInteger(abs, inte._expo);

	if (abs->_lsu == inte._lsu) {
		abs->_sign = +1;
	}
	else {
		Memcpy(abs->_lsu, inte._lsu, inte._expo);
		abs->_sign = +1;
		abs->_expo = inte._expo;
	}
	return abs;
}

Integer *Neg(Integer *nega, Integer inte) {
	nega = NewInteger(nega, inte._expo);

	if (nega->_lsu == inte._lsu) {
		nega->_sign *= -1;
	}
	else {
		Memcpy(nega->_lsu, inte._lsu, inte._expo);
		nega->_sign = -1 * inte._sign;
		nega->_expo = inte._expo;
	}
	return nega;
}

/* Assume [lhs._expo >= rhs._expo]
  *BASE^{EXPO}               *BASE^{EXPO - 1}                                       *BASE^{1}                           *BASE^{0}
								 B_{EXPO - 1} +                          ... +          B_{1}                               B_{0}
+                                C_{EXPO - 1} +                          ... +          C_{1}                             + C_{0}                     // yield Carry
= Carry_{EXPO} + (B_{EXPO - 1} + C_{EXPO - 1} + Carry_{EXPO - 1})%BASE + ... + (B_{1} + C_{1} + Carry_{1})%BASE  + (B_{0} + C_{0} + Carry_{0}) %BASE  // accumulate recursively
*/
Integer *Add(Integer *summ, Integer lhs, Integer rhs) {
	// lhs and rhs have opposite signs
	if ((lhs._sign ^ rhs._sign) < 0) {
		/*
				(+)   (-)    (+)   (  + )
		case 1: lhs + rhs == lhs - (-rhs)
		case 2: lhs + rhs == lhs - (-rhs)
				(-)   (+)    (-)   (  - )
		*/
		return Sub(summ, lhs, *Neg(&rhs, rhs));
	}

	in08 _sign = lhs._sign;
	if (lhs._expo < rhs._expo) {
		Integer swap = lhs; lhs = rhs; rhs = swap;
		_sign *= +1;
	}

	iptr _expo = lhs._expo + 1;
	summ = NewInteger(summ, _expo);

	unit *_lsu = summ->_lsu;
	dual carry = 0;
	for (iptr i = 0; i < rhs._expo; i += 1) {
		carry = lhs._lsu[i] + rhs._lsu[i] + carry;
		_lsu[i] = (unit)(carry & EData._Mask);
		carry >>= EData._Shift;
	}
	for (iptr j = rhs._expo; j < lhs._expo; j += 1) {
		carry = lhs._lsu[j] + carry;
		_lsu[j] = (unit)(carry & EData._Mask);
		carry >>= EData._Shift;
	}
	_lsu[lhs._expo] = (unit)(carry);

	summ->_sign = _sign;
	summ->_expo = (carry != 0 ? _expo + 1 : _expo);
	return summ;
}

/* Assume [lhs._expo >= rhs._expo]
			  *BASE^{EXPO - 1}                                        *BASE^{1}                            *BASE^{0}
				  B_{EXPO - 1} +                           ... +          B_{1}                                B_{0}
-                 C_{EXPO - 1} +                           ... +          C_{1}                              + C_{0}                      // yield Borrow
= (B_{EXPO - 1} + C_{EXPO - 1} + Borrow_{EXPO - 1})%BASE + ... + (B_{1} + C_{1} + Borrow_{1})%BASE  + (B_{0} + C_{0} + Borrow_{0}) %BASE  // attenuate recursively
*/
Integer *Sub(Integer *diff, Integer lhs, Integer rhs) {
	// lhs and rhs have opposite signs
	if ((lhs._sign ^ rhs._sign) < 0) {
		/*
				(+)   (-)    (+)   (  + )
		case 3: lhs - rhs == lhs + (-rhs)
		case 4: lhs - rhs == lhs + (-rhs)
				(-)   (+)    (-)   (  - )
		*/
		return Add(diff, lhs, *Neg(&rhs, rhs));
	}

	in08 _sign = lhs._sign;
	if (lhs._expo < rhs._expo) {
		Integer swap = lhs; lhs = rhs; rhs = swap;
		_sign *= -1;
	}

	iptr _expo = lhs._expo;
	if (lhs._expo == rhs._expo) {
		while (0 < _expo && lhs._lsu[_expo - 1] == rhs._lsu[_expo - 1]) {
			_expo -= 1;
		}
		if (_expo <= 0) {
			diff = NewInteger(diff, 1);

			diff->_sign = +1;
			diff->_expo = 1;
			diff->_lsu[0] = (unit)0U;
			return diff;
		}
		else if (lhs._lsu[_expo - 1] < rhs._lsu[_expo - 1]) {
			Integer swap = lhs; lhs = rhs; rhs = swap;
			_sign *= -1;
		}
	}
	diff = NewInteger(diff, _expo);
	unit *_lsu = diff->_lsu;

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

	diff->_sign = _sign;
	diff->_expo = i;
	return diff;
}


/*
   *BASE^{2*EXPO-1} ... *BASE^{EXPO+1}                  *BASE^{EXPO}          *BASE^{EXPO-1}                *BASE^{1}                *BASE^{0}
																				  B_{EXPO-1}     + ... +        B_{1}        +           B_{0}
×                                                                                 C_{EXPO-1}     + ... +        C_{1}        +           C_{0}
==
++                                                         Carry_{0}     (B_{0} * C_{EXPO-1})%BASE ...（B_{0} * C_{1})%BASE     (B_{0} * C_{0})%BASE
++                           Carry_{1}     (B_{1} * C_{EXPO-1})%BASE ...      (B_{1} * C_{1})%BASE     (B_{1} * C_{0})%BASE
++                  ...
++ Carry_{EXPO - 1}     (B_{EXPO - 1} * C_{EXPO - 1})%BASE ... (B_{EXPO - 1} * C_{1})%BASE    (B_{EXPO-1} * C_{0})%BASE
*/
Integer *Mul(Integer *prod, Integer lhs, Integer rhs) {
	in08 _sign = lhs._sign * rhs._sign;
	iptr _expo = lhs._expo + rhs._expo;

	prod = NewInteger(prod, _expo);
	unit *_lsu = prod->_lsu;

	/* constraint assurance
	BASE * BASE - 1                                          // Dual Unit
	==  (BASE - 1) +  (BASE - 1) * (BASE - 1)  + (BASE - 1)  // Unit
	>= _lsu[i + 1] + lhs._lsu[i] * rhs._lsu[j] + Carry       // Unit
	*/
	dual carry = 0;
	if (lhs._lsu == rhs._lsu) {
		/* Θ(n) = EXPO^2 -> Θ(n) = EXPO * (EXPO + 1) / 2
		   Square(Sum_{i = 0, j = 0}^{EXPO - 1} B_{i, j} * BASE^{i + j})
		== Sum_{i = 0}^{EXPO - 1} B_{i}^2 * BASE^{2 * i}
		  + Sum_{i = 0}^{EXPO - 1} Sum_{j = i + 1}^{EXPO - 1} (2 * B_{i}) * B_{j} * BASE^{i + j}
		*/
		dual twice = 0;
		for (iptr i = 0; i < rhs._expo; i += 1) {
			carry = _lsu[i + i] + rhs._lsu[i] * rhs._lsu[i];
			_lsu[i + i] = (unit)(carry & EData._Mask);
			carry >>= EData._Shift;

			twice = 2 * rhs._lsu[i];
			for (iptr j = i + 1; j < rhs._expo; j += 1) {
				carry = _lsu[i + j] + twice * rhs._lsu[j] + carry;
				_lsu[i + j] = (unit)(carry & EData._Mask);
				carry >>= EData._Shift;
			}
			_lsu[i + rhs._expo] = (unit)(carry);
		}
	}
	else {
		for (iptr i = 0; i < lhs._expo; i += 1) {
			carry = 0;
			for (iptr j = 0; j < rhs._expo; j += 1) {
				carry = _lsu[i + j] + lhs._lsu[i] * rhs._lsu[j] + carry;
				_lsu[i + j] = (unit)(carry & EData._Mask);
				carry >>= EData._Shift;

			}
			_lsu[i + rhs._expo] = (unit)(carry);
		}
	}

	prod->_sign = _sign;
	prod->_expo = (carry != 0 ? _expo : _expo - 1);
	return prod;
}

/*Assume [lhs._expo >= rhs._expo]
Step 1:  [B_8 > 0] and [C_5 > 0]
		*BASE^8  *BASE^7  *BASE^6  *BASE^5         |  *BASE^4  *BASE^3  *BASE^2  *BASE^1  *BASE^0
  (quad)  B_8      B_7      B_6      B_5           |    B_4      B_3      B_2      B_1      B_0
÷ (quad)	       C_5      C_4      C_3           |                      C_2      C_1      C_0
==(quad)  				    Q_3      Q_{Discard}  // [Q_3 >= 0]

	B_8*BASE^8 + B_7*BASE^7 + B_6*BASE^6 + B_5*BASE^5
>= (C_5*BASE^5 + C_4*BASE^4 + C_3*BASE^3) * (Q_3*BASE^3 + Q_{Discard}*BASE^2)
==  C_5*Q_3*BASE^8 + (C_4*Q_3 + C_5*Q_{Discard})*BASE^7 + (C_3*Q_3 + C_4*Q_{Discard})*BASE^6 + C_3*Q_{Discard}*BASE^5
>=  C_5*Q_3*BASE^8 + C_4*Q_3*BASE^7 + C_3*Q_3*BASE^6

Step 2: Leave Out Q_{Discard}
		  B_8      B_7      B_6  |      B_5      B_4      B_3      B_2      B_1      B_0
-     C_5*Q_3  C_4*Q_3  C_3*Q_3  |  C_2*Q_3  C_1*Q_3  C_0*Q_3
==                              SUB

Step 3:
Case 0: [Q_3 == 0] => [Q ==                    Q_{Tail}]  // Shift Dividend One Unit
Case 1: [SUB  > 0] => [Q ==       Q_3*BASE^3 + Q_{Tail}]  // Absolute Assurance
Case 2: [SUB  < 0] => [Q == (Q_3 - 1)*BASE^3 + Q_{Tail}]  // Absolute Assurance
Case 3: [sub == 0] => [Q ==       Q_3*BASE^3]             // Absolute Assurance
*/



/* Definition of Division
rema = lhs - rhs * Round(lhs / rhs) = lhs - rhs * quot
modu = lhs - rhs * Floor(lhs / rhs)

			   Round Floor                |  Ceil  Edge
lhs  rhs  quot  rema  modu  Round  Floor  |  Rema  Modu  Ceil  Edge
 12   10     1     2     2      1      1  |    -8    -8     2     2
-12   10    -1    -2     8     -1     -2  |    -2     8    -1    -2
 12  -10    -1     2    -8     -1     -2  |     2    -8    -1    -2
-12  -10     1    -2    -2      1      1  |     8     8     2     2
										  |
 10   12     0    10    10      0      0  |    -2    -2     1     1
-10   12     0   -10     2      0     -1  |   -10     2     0    -1
 10  -12     0    10    -2      0     -1  |    10    -2     0    -1
-10  -12     0   -10   -10      0      0  |     2     2     1     1
*/
Integer *DivRem(Integer *quot, Integer *rema, Integer lhs, Integer rhs) {
	// [|rhs| != 0]
	if (Check(rhs._expo == 1 && rhs._lsu[0] == 0, __FUNCTION__, EType._Error, "|rhs| == 0, ", "rhs._expo == 1 && rhs._lsu[0] == 0")) {
		return quot;
	}

	quot = NewInteger(quot, sizeof(quad));
	rema = NewInteger(rema, lhs._expo);
	if (lhs._expo < rhs._expo) {
		/* Case 1: [lhs._expo < rhs._expo]
		   quot = 0
		   rema = lhs
		*/
		quot->_sign = +1;
		quot->_expo = 1;
		quot->_lsu[0] = (unit)0U;

		rema->_sign = lhs._sign;
		rema->_expo = lhs._expo;
		Memcpy(rema->_lsu, lhs._lsu, lhs._expo);
		return quot;
	}
	else if (lhs._expo == rhs._expo) {
		iptr _expo = rhs._expo;
		while (0 < _expo && lhs._lsu[_expo - 1] == rhs._lsu[_expo - 1]) {
			_expo -= 1;
		}
		if (_expo <= 0) {
			/* Case 2: [lhs._expo == rhs._expo] and [|lhs| == |rhs|]
			   quot = lhs._sign * rhs._sign
			   rema = 0
			*/
			quot->_sign = lhs._sign * rhs._sign;
			quot->_expo = 1;
			quot->_lsu[1] = (unit)1U;

			rema->_sign = +1;
			rema->_expo = 1;
			rema->_lsu[0] = (unit)0U;
			return quot;
		}
		else if (lhs._lsu[_expo - 1] < rhs._lsu[_expo - 1]) {
			/* Case 3: [lhs._expo == rhs._expo] and [|lhs| < |rhs|]
			   quot = 0
			   rema = lhs
			*/
			quot->_sign = +1;
			quot->_expo = 1;
			quot->_lsu[0] = (unit)0U;

			rema->_sign = lhs._sign;
			rema->_expo = lhs._expo;
			Memcpy(rema->_lsu, lhs._lsu, rema->_lsu);
			return quot;
		}
		else {
			/* Case 4: [lhs._expo == rhs._expo] and [|lhs| > |rhs|]
			   quot = lhs._lsu[0] / rhs._lsu[0]
			   rema = lhs - rhs * quot
			*/
			quot->_sign = lhs._sign * rhs._sign;
			quot->_expo = 1;
			quot->_lsu[0] = (lhs._lsu[lhs._expo - 1] / rhs._lsu[rhs._expo - 1]);

			rema = Sub(rema, rhs, *Mul(rema, rhs, *quot));
			return quot;
		}
	}

	/* Case 5: |lhs| > |rhs|
	*/
	in08 _sign = lhs._sign * rhs._sign;
	iptr _expo_quot = lhs._expo - rhs._expo + 1;
	unit *_lsu_quot = (unit *)Calloc(_expo_quot, sizeof(unit));
	iptr _expo_rema = rhs._expo;
	unit *_lsu_rema = (unit *)Calloc(_expo_rema, sizeof(unit));

	//quad dividend = 0;
	//quad divisor = 0;
	//quot._sign = +1;
	//quot._expo = sizeof(quad);

	//iptr i = 0;
	//for (i = 0; i < 4 && 0 < lhs._expo; i += 1, lhs._expo -= 1) {
	//	dividend <<= EData._Shift;
	//	dividend = lhs._lsu[lhs._expo - 1];
	//}
	//for (i = 0; i < 3 && 0 < rhs._expo; i += 1, rhs._expo -= 1) {
	//	divisor <<= EData._Shift;
	//	divisor = rhs._lsu[rhs._expo - 1];
	//}

	//if (rhs._expo = 1) {
	//	quot->_sign = +1;
	//	quot->_expo = 1;
	//	quot->_lsu = _lsu_quot;


	//	while (true) {
	//		quot->_lsu[lhs._expo - 1] = (unit)(lhs._lsu[lhs._expo - 1] / rhs._lsu[0]);
	//		if (quot->_lsu[lhs._expo - 1] == 0) {
	//			continue;
	//		}
	//		else {

	//		}
	//	}

	//}


	quot->_sign = _sign;
	quot->_expo = _expo_quot;
	return quot;
}

////////////////////////////////////////

void Test_Integer() {
	Integer inte;
	Parse(&inte, "-2,5_6", 10);
	Parse(&inte, "131072", 10);
	Parse(&inte, "0x0000", 10);

	fprintf(stderr, "[%d, %lld] ", inte._sign, inte._expo);
	iptr _expo = inte._expo;
	for (_expo -= 1; 0 <= _expo; _expo -= 1) {
		fprintf(stderr, "%d ", inte._lsu[_expo]);
	}
	fprintf(stderr, "\n");
}

void TestAdd() {
	Integer lhs;
	Integer rhs;
	Parse(&lhs, "-128", 10);
	Parse(&rhs, "-256", 10);

	// Integer ret = Add(lhs, rhs);
	Integer ret = Sub(lhs, rhs);

	fprintf(stderr, "[%d, %lld] ", ret._sign, ret._expo);
	iptr _expo = ret._expo;
	for (_expo -= 1; 0 <= _expo; _expo -= 1) {
		fprintf(stderr, "%d ", ret._lsu[_expo]);
	}
	fprintf(stderr, "\n");
}

void TestMul() {
	Integer lhs;
	Integer rhs;
	Parse(&lhs, "-256", 10);
	Parse(&rhs, "+256", 10);

	// Integer ret = Mul(lhs, rhs);
	Integer ret = Mul(lhs, lhs);

	fprintf(stderr, "[%d, %lld] ", ret._sign, ret._expo);
	iptr _expo = ret._expo;
	for (_expo -= 1; 0 <= _expo; _expo -= 1) {
		fprintf(stderr, "%d ", ret._lsu[_expo]);
	}
	fprintf(stderr, "\n");
}

// Only Consider LITTLE-ENDIAN machine
void TestDivRem() {
	Integer lhs;
	Integer rhs;
	//Parse(&lhs, "458752", 10); // lhs == 256*256*7
	//Parse(&rhs, "768", 10);    // rhs == 256*3

	//Integer rema;
	//Integer quot;
	//Integer quot = DivMod(&rema, lhs, rhs);

	//fprintf(stderr, "[%d, %lld] ", quot._sign, quot._expo);
	//iptr _expo_quot = quot._expo;
	//for (_expo_quot -= 1; 0 <= _expo_quot; _expo_quot -= 1) {
	//	fprintf(stderr, "%d ", quot._lsu[_expo_quot]);
	//}
	//fprintf(stderr, "\n");

	//fprintf(stderr, "[%d, %lld] ", rema._sign, rema._expo);
	//iptr _expo_rema = rema._expo;
	//for (_expo_rema -= 1; 0 <= _expo_rema; _expo_rema -= 1) {
	//	fprintf(stderr, "%d ", rema._lsu[_expo_rema]);
	//}
	//fprintf(stderr, "\n");



	dual dividend = 0;
	quad divisor = 0;

	// Parse(&lhs, "458752", 10); // lhs == 256*256*7
	Parse(&rhs, "769", 10);    // rhs == 256*3 + 1 = 769

	divisor = *((quad *)rhs._lsu);

	fprintf(stderr, "%d, %d \n", ((unit *)(&divisor))[1], ((unit *)(&divisor))[0]);



	//fprintf(stderr, "[%d, %lld] ", lhs._sign, lhs._expo);
	//iptr _expo_quot = lhs._expo;
	//for (_expo_quot -= 1; 0 <= _expo_quot; _expo_quot -= 1) {
	//	fprintf(stderr, "%d ", lhs._lsu[_expo_quot]);
	//}
	//fprintf(stderr, "\n");

	//fprintf(stderr, "[%d, %lld] ", rhs._sign, rhs._expo);
	//iptr _expo_rema = rhs._expo;
	//for (_expo_rema -= 1; 0 <= _expo_rema; _expo_rema -= 1) {
	//	fprintf(stderr, "%d ", rhs._lsu[_expo_rema]);
	//}
	//fprintf(stderr, "\n");
}

iptr main(iptr argc, ui08 *argv[]) {
	StartUp();

	// TestInteger();
	// TestAdd();
	// TestMul();
	TestDivRem();

	CleanUp();
	return 0;
}