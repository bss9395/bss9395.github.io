/* Rational.c
Author: BSS9395
Update: 2020-06-01T03:27:00+08@China-Guangdong-Zhanjiang+08
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

#define Log2    log2
#define Memset  memset
#define Memcpy  memcpy
#define Calloc  calloc

void *ReCalloc(void *block, uptr count, uptr size) {
	size *= count;
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

typedef ui08  unit;
typedef ui16  dual;
typedef ui32  quad;

//typedef ui16  unit;
//typedef ui32  dual;
//typedef ui64  quad;

typedef struct {
	in08 _sign : 2;
	bool _make : 2;
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

iptr Parse(Integer *inte, const ui08 *data, ui08 base);
Integer *Abso(Integer *abso, Integer inte);
Integer *Nega(Integer *nega, Integer inte);
Integer *Addi(Integer *summ, Integer lhop, Integer rhop);
Integer *Subt(Integer *diff, Integer lhop, Integer rhop);
Integer *Mult(Integer *Prod, Integer lhop, Integer rhop);
Integer *DiviRema(Integer *quot, Integer *Rema, Integer lhop, Integer rhop);

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

bool Check(const bool failed, const ui08 *function, const Level level, const ui08 *record, const ui08 *extra) {
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

Integer BeInteger() {
	static Integer inte = {
		._sign = 0,
		._make = true,
		._expo = 0,
		._lsu = NULL
	};
	return inte;
}

Integer *ReInteger(Integer *inte, iptr expo) {
	if (inte == NULL) {
		inte = (Integer *)Calloc(expo, sizeof(unit));
		inte->_expo = expo;
	}
	else if (inte->_expo < expo) {
		inte->_lsu = (unit *)ReCalloc(inte->_lsu, expo, sizeof(unit));
		inte->_expo = expo;
	}
	return inte;
}

Integer *DeInteger(Integer *inte) {
	if (inte != NULL) {
		free(inte->_lsu);
		inte->_lsu = NULL;

		if (inte->_make == false) {
			free(inte);
			inte = NULL;
		}
	}

	return inte;
}

iptr StartUp() {
	for (in08 base = 2; base <= 16; base += 1) {
		EData._Log2_Base[base] = Log2(base + EData._Epsilon) / Log2(EData._Base);
	}
	return 0;
}

iptr CleanUp() {
	iptr ret = 0;
	return ret;
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
iptr Parse(Integer *inte, const ui08 *data, ui08 base) {
	if (Check(inte == NULL || !(2 <= base && base <= 16), __FUNCTION__, EType._Error, "inte == NULL || !(2 <= base && base <= 36)", NULL)) {
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
	inte = ReInteger(inte, _expo);

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

iptr Print(const Integer inte, ui08 base) {
	if (Check(!(2 <= base && base <= 16), __FUNCTION__, EType._Error, "!(2 <= base && base <= 16)", NULL)) {
		return 0;
	}
	iptr ret = 0;

	//while () {

	//}

	return ret;
}

Integer *Abso(Integer *abso, Integer inte) {
	if (abso->_lsu == inte._lsu) {
		abso->_sign = +1;
	}
	else {
		abso = ReInteger(abso, inte._expo);
		abso->_sign = +1;
		abso->_expo = inte._expo;
		Memcpy(abso->_lsu, inte._lsu, inte._expo);
	}
	return abso;
}

Integer *Nega(Integer *nega, Integer inte) {
	if (nega->_lsu == inte._lsu) {
		nega->_sign *= -1;
	}
	else {
		nega = ReInteger(nega, inte._expo);
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
Integer *Addi(Integer *summ, Integer lhop, Integer rhop) {
	// lhs and rhs have opposite signs
	if ((lhop._sign ^ rhop._sign) < 0) {
		/*
				(+)   (-)    (+)   (  + )
		case 1: lhs + rhs == lhs - (-rhs)
		case 2: lhs + rhs == lhs - (-rhs)
				(-)   (+)    (-)   (  - )
		*/
		return Subt(summ, lhop, *Nega(&rhop, rhop));
	}

	in08 _sign = lhop._sign;
	if (lhop._expo < rhop._expo) {
		Integer swap = lhop; lhop = rhop; rhop = swap;
		_sign *= +1;
	}

	iptr _expo = lhop._expo + 1;
	summ = ReInteger(summ, _expo);

	unit *_lsu = summ->_lsu;
	dual carry = 0;
	for (iptr i = 0; i < rhop._expo; i += 1) {
		carry = lhop._lsu[i] + rhop._lsu[i] + carry;
		_lsu[i] = (unit)(carry & EData._Mask);
		carry >>= EData._Shift;
	}
	for (iptr j = rhop._expo; j < lhop._expo; j += 1) {
		carry = lhop._lsu[j] + carry;
		_lsu[j] = (unit)(carry & EData._Mask);
		carry >>= EData._Shift;
	}
	_lsu[lhop._expo] = (unit)(carry);

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
Integer *Subt(Integer *diff, Integer lhop, Integer rhop) {
	// lhs and rhs have opposite signs
	if ((lhop._sign ^ rhop._sign) < 0) {
		/*
				(+)   (-)    (+)   (  + )
		case 3: lhs - rhs == lhs + (-rhs)
		case 4: lhs - rhs == lhs + (-rhs)
				(-)   (+)    (-)   (  - )
		*/
		return Addi(diff, lhop, *Nega(&rhop, rhop));
	}

	in08 _sign = lhop._sign;
	if (lhop._expo < rhop._expo) {
		Integer swap = lhop; lhop = rhop; rhop = swap;
		_sign *= -1;
	}

	iptr _expo = lhop._expo;
	if (lhop._expo == rhop._expo) {
		while (0 < _expo && lhop._lsu[_expo - 1] == rhop._lsu[_expo - 1]) {
			_expo -= 1;
		}
		if (_expo <= 0) {
			diff = ReInteger(diff, 1);

			diff->_sign = +1;
			diff->_expo = 1;
			diff->_lsu[0] = (unit)0U;
			return diff;
		}
		else if (lhop._lsu[_expo - 1] < rhop._lsu[_expo - 1]) {
			Integer swap = lhop; lhop = rhop; rhop = swap;
			_sign *= -1;
		}
	}
	diff = ReInteger(diff, _expo);
	unit *_lsu = diff->_lsu;

	dual borrow = 0;
	for (iptr i = 0; i < rhop._expo; i += 1) {
		borrow = lhop._lsu[i] - rhop._lsu[i] - borrow;
		_lsu[i] = (unit)(borrow & EData._Mask);
		borrow >>= EData._Shift;
		borrow &= 1U;             // borrow 1 from higher unit
	}
	for (iptr j = 0; j < _expo; j += 1) {
		borrow = lhop._lsu[j] - borrow;
		_lsu[j] = (unit)(borrow & EData._Mask);
		borrow >>= EData._Shift;
		borrow &= 1U;             // borrow 1 from higher unit
	}

	diff->_sign = _sign;
	diff->_expo = _expo;
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
Integer *Mult(Integer *prod, Integer lhop, Integer rhop) {
	in08 _sign = lhop._sign * rhop._sign;
	iptr _expo = lhop._expo + rhop._expo;

	prod = ReInteger(prod, _expo);
	unit *_lsu = prod->_lsu;

	/* constraint assurance
	BASE * BASE - 1                                          // Dual Unit
	==  (BASE - 1) +  (BASE - 1) * (BASE - 1)  + (BASE - 1)  // Unit
	>= _lsu[i + 1] + lhs._lsu[i] * rhs._lsu[j] + Carry       // Unit
	*/
	dual carry = 0;
	if (lhop._lsu == rhop._lsu) {
		/* Θ(n) = EXPO^2 -> Θ(n) = EXPO * (EXPO + 1) / 2
		   Square(Sum_{i = 0, j = 0}^{EXPO - 1} B_{i, j} * BASE^{i + j})
		== Sum_{i = 0}^{EXPO - 1} B_{i}^2 * BASE^{2 * i}
		  + Sum_{i = 0}^{EXPO - 1} Sum_{j = i + 1}^{EXPO - 1} (2 * B_{i}) * B_{j} * BASE^{i + j}
		*/
		dual twice = 0;
		for (iptr i = 0; i < rhop._expo; i += 1) {
			carry = _lsu[i + i] + rhop._lsu[i] * rhop._lsu[i];
			_lsu[i + i] = (unit)(carry & EData._Mask);
			carry >>= EData._Shift;

			twice = 2 * rhop._lsu[i];
			for (iptr j = i + 1; j < rhop._expo; j += 1) {
				carry = _lsu[i + j] + twice * rhop._lsu[j] + carry;
				_lsu[i + j] = (unit)(carry & EData._Mask);
				carry >>= EData._Shift;
			}
			_lsu[i + rhop._expo] = (unit)(carry);
		}
	}
	else {
		for (iptr i = 0; i < lhop._expo; i += 1) {
			carry = 0;
			for (iptr j = 0; j < rhop._expo; j += 1) {
				carry = _lsu[i + j] + lhop._lsu[i] * rhop._lsu[j] + carry;
				_lsu[i + j] = (unit)(carry & EData._Mask);
				carry >>= EData._Shift;

			}
			_lsu[i + rhop._expo] = (unit)(carry);
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
Integer *DiviRema(Integer *quot, Integer *rema, Integer lhop, Integer rhop) {
	// [|rhs| != 0]
	if (Check(rhop._expo == 1 && rhop._lsu[0] == 0, __FUNCTION__, EType._Error, "|rhs| == 0, ", "rhs._expo == 1 && rhs._lsu[0] == 0")) {
		return quot;
	}
	Integer *_rema = rema;


	if (lhop._expo < rhop._expo) {
		/* Case 1: [lhop._expo < rhop._expo]
		   quot = 0
		   rema = lhop
		*/
		quot->_sign = +1;
		quot->_expo = 1;
		quot = ReInteger(quot, quot->_expo);
		quot->_lsu[0] = (unit)0U;

		rema->_sign = lhop._sign;
		rema->_expo = lhop._expo;
		rema = ReInteger(quot, rema->_expo);
		Memcpy(rema->_lsu, lhop._lsu, lhop._expo);
		return quot;
	}
	else if (lhop._expo == rhop._expo) {
		iptr _expo = rhop._expo;
		while (0 < _expo && lhop._lsu[_expo - 1] == rhop._lsu[_expo - 1]) {
			_expo -= 1;
		}
		if (_expo <= 0) {
			/* Case 2: [lhop._expo == rhop._expo] and [|lhs| == |rhs|]
			   quot = lhop._sign * rhs._sign
			   rema = 0
			*/
			quot->_sign = lhop._sign * rhop._sign;
			quot->_expo = 1;
			quot = ReInteger(quot, quot->_expo);
			quot->_lsu[1] = (unit)1U;

			rema->_sign = +1;
			rema->_expo = 1;
			rema = ReInteger(rema, rema->_expo);
			rema->_lsu[0] = (unit)0U;
			return quot;
		}
		else if (lhop._lsu[_expo - 1] < rhop._lsu[_expo - 1]) {
			/* Case 3: [lhs._expo == rhs._expo] and [|lhs| < |rhs|]
			   quot = 0
			   rema = lhs
			*/
			quot->_sign = +1;
			quot->_expo = 1;
			quot = ReInteger(quot, quot->_expo);
			quot->_lsu[0] = (unit)0U;

			rema->_sign = lhop._sign;
			rema->_expo = lhop._expo;
			rema = ReInteger(rema, rema->_expo);
			Memcpy(rema->_lsu, lhop._lsu, (size_t)rema->_lsu);
			return quot;
		}
		else {
			/* Case 4: [lhop._expo == rhop._expo] and [|lhop| > |rhop|]
			   quot = lhop._lsu[0] / rhop._lsu[0]
			   rema = lhop - rhop * quot
			*/
			quot->_sign = lhop._sign * rhop._sign;
			quot->_expo = 1;
			quot = ReInteger(quot, quot->_expo);
			quot->_lsu[0] = (unit)(lhop._lsu[lhop._expo - 1] / rhop._lsu[rhop._expo - 1]);

			rema = Subt(rema, rhop, *Mult(rema, rhop, *quot));
			return quot;
		}
	}

	/* Case 5: |lhs| > |rhs|
	*/
	if (rhop._expo == 1) {
		in08 _sign_quot = lhop._sign * rhop._sign;
		iptr _expo_quot = lhop._expo - rhop._expo + 1;
		quot = ReInteger(quot, _expo_quot);
		unit *_lsu_quot = quot->_lsu;
		quot->_lsu += _expo_quot - 1;

		in08 _sign_rema = lhop._sign;
		iptr _expo_rema = lhop._expo;
		rema = ReInteger(rema, _expo_rema);
		memcpy(rema->_lsu, lhop._lsu, lhop._expo);
		unit *_lsu_rema = rema->_lsu;
		rema->_lsu += _expo_rema - 1;

		if (rema->_lsu[0] < rhop._lsu[0]) {
			_expo_quot -= 1;
			_lsu_quot -= 1;
		}
		rema->_lsu -= 1;

		rhop._sign = +1;
		quot->_sign = +1;
		quot->_expo = 1;
		Integer *prod = NULL;
		while (_lsu_rema <= rema->_lsu) {
			quot->_lsu[0] = (unit)(*(dual *)rema->_lsu / rhop._lsu[0]);
			if (quot->_lsu[0] != 0) {
				prod = Mult(prod, rhop, *quot);
				rema->_expo = 2;
				rema = Subt(rema, *rema, *prod);
			}
			rema->_lsu -= 1;
			quot->_lsu -= 1;
		}


		quot->_sign = _sign_quot;
		quot->_expo = _expo_quot;
		quot->_lsu = _lsu_quot;

		rema->_sign = _sign_rema;

	}

	return quot;
}

////////////////////////////////////////

void TestDiviRema() {
	Integer lhs = BeInteger();
	Integer *rhs = ReInteger(NULL, 1);
	Parse(&lhs, "3298534883329", 10); // 3*256*256*256*256*256 + 1
	Parse(rhs, "230", 10);  // 14341456014 + 108

	Integer *rema = ReInteger(NULL, 1);
	Integer *quot = DiviRema(NULL, rema, lhs, *rhs);

	fprintf(stderr, "%d, %lld ""\n", quot->_sign, quot->_expo);
	iptr _expo_quot = quot->_expo;
	for (; 0 < _expo_quot; _expo_quot -= 1) {
		fprintf(stderr, "%d ", quot->_lsu[_expo_quot]);
	}
	fprintf(stderr, "\n");

	fprintf(stderr, "%d, %lld ""\n", rema->_sign, rema->_expo);
	iptr _expo_rema = rema->_expo;
	for (; 0 < _expo_rema; _expo_rema -= 1) {
		fprintf(stderr, "%d ", rema->_lsu[_expo_rema]);
	}
	fprintf(stderr, "\n");

	DeInteger(&lhs);
	DeInteger(rhs);
}

iptr main(iptr argc, ui08 *argv[]) {
	StartUp();

	// TestInteger();
	// TestAddi();
	// TestMult();
	// TestDiviRema();

	CleanUp();
	return 0;
}

void Test_Integer() {
	Integer *inte = ReInteger(NULL, 1);
	Parse(inte, "-2,5_6", 10);
	Parse(inte, "131072", 10);
	Parse(inte, "0x0000", 10);

	fprintf(stderr, "[%d, %lld] ", inte->_sign, inte->_expo);
	iptr _expo = inte->_expo;
	for (_expo -= 1; 0 <= _expo; _expo -= 1) {
		fprintf(stderr, "%d ", inte->_lsu[_expo]);
	}
	fprintf(stderr, "\n");

	DeInteger(inte);
}

void TestAdd() {
	Integer lhs = BeInteger();
	Integer rhs = BeInteger();
	Parse(&lhs, "-128", 10);
	Parse(&rhs, "-256", 10);

	// Integer *ret = Add(NULL, *lhs, *rhs);
	Integer *ret = Subt(NULL, lhs, rhs);

	fprintf(stderr, "[%d, %lld] ", ret->_sign, ret->_expo);
	iptr _expo = ret->_expo;
	for (_expo -= 1; 0 <= _expo; _expo -= 1) {
		fprintf(stderr, "%d ", ret->_lsu[_expo]);
	}
	fprintf(stderr, "\n");

	DeInteger(&lhs);
	DeInteger(&rhs);
	DeInteger(ret);
}

void TestMul() {
	Integer *lhs = ReInteger(NULL, 1);
	Integer *rhs = ReInteger(NULL, 1);

	Parse(lhs, "-256", 10);
	Parse(rhs, "+256", 10);
	Integer *ret = Mult(NULL, *lhs, *rhs);

	fprintf(stderr, "[%d, %lld] ", ret->_sign, ret->_expo);
	iptr _expo = ret->_expo;
	for (_expo -= 1; 0 <= _expo; _expo -= 1) {
		fprintf(stderr, "%d ", ret->_lsu[_expo]);
	}
	fprintf(stderr, "\n");

	DeInteger(lhs);
	DeInteger(rhs);
	DeInteger(ret);
}

