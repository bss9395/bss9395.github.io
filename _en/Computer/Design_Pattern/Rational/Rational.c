/* Rational.c
Author: BSS9395
Update: 2020-06-02T17:04:00+08@China-Guangdong-Zhanjiang+08
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
// #include <stdbool.h>
#include <stdint.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef int8_t    bool;
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

#define true    1
#define false   0
#define Log2    log2
#define Memset  memset
#define Memcpy  memcpy
#define Malloc  malloc
#define Realloc realloc

////////////////////////////////////////

/* Representation of Integer
Unit  Representation
== B_{EXPO - 1} * BASE^{EXPO - 1} + B_{EXPO - 2} * BASE^{EXPO - 2} + ... + B_{1} * BASE^{1} + B_{0} * BASE^{0}  // BASE == 2^{16}
== b_{expo - 1} * base^(expo - 1) + b_{expo - 2} * base^(expo - 2) + ... + b_{1} * base^(1) + B_{0} * base^(0)  // base == 10 or 2 or 8 or 16 ...
Digit Representation

=> 1 * BASE^EXPO >= 1 * base^expo                                                         // Boundary Condition
=> Floor(expo * Log2(base) / Log2(BASE)) <= EXPO <= Ceil(expo * Log2(base) / Log2(BASE))  // Absolute Assurance
=> EXPO <= Floor(expo * Log2(base) / Log2(BASE)) + 1                                      // Allocate Enough Space
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
Integer *DiviRema(Integer *quot, Integer *rema_lhop, Integer rhop);

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
	._Log2_Base = {
		0.0, 0.0,
	},
};

////////////////////////////////////////

bool Check(const bool failed, const ui08 *function, const Level level, const ui08 *record, const ui08 *extra) {
	if (failed) {
		fprintf(stderr, "[%s#%s] %s%s; ""\n", function, level, record, extra == NULL ? (const ui08 *)"" : extra);
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
		._expo = 1,
		._lsu = NULL,
	};
	Integer ret = inte;
	ret._lsu = (unit *)Malloc(1 * sizeof(unit));
	return ret;
}

Integer *ReInteger(Integer *inte, iptr expo) {
	if (inte == NULL) {
		inte = (Integer *)Malloc(1 * sizeof(Integer));
		inte->_sign = 0;
		inte->_make = false;
		inte->_expo = expo;
		inte->_lsu = (unit *)Malloc(expo * sizeof(unit));
	}
	else if (inte->_expo < expo) {
		inte->_expo = expo;
		inte->_lsu = (unit *)Realloc(inte->_lsu, expo * sizeof(unit));
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

/*Parse Integer
	   b_{expo - 1} % BASE = R
	   b_{expo - 1} / BASE = Q
=> b_{expo - 1} = Q * BASE + R
														   // b_{expo - 2} is now to be dealed with
=>   (b_{expo - 1} * base + b_{expo - 2}) % BASE
== ((Q * BASE + R) * base + b_{expo - 2}) % BASE
==              (R * base + b_{expo - 2}) % BASE

				(R * base + b_{expo - 2}) / BASE == Carry  // yield Carry
=>   (b_{expo - 1} * base + b_{expo - 2}) / BASE
== ((Q * BASE + R) * base + b_{expo - 2}) / BASE
==                      (Q * BASE * base) / BASE +  Carry
==                                      Q * base +  Carry  // accumulate recursively
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

	Memset(inte->_lsu, 0, _expo);
	dual carry = 0;
	_expo = 1;
	while (data < digit) {
		if (data[0] == '_' || data[0] == ',') {
			data += 1;
		}
		else {
			carry = EData._Digit[data[0]];                   // fetch b_{n - 2}
			data += 1;

			for (iptr i = 0; i < _expo; i += 1) {
				carry = inte->_lsu[i] * base + carry;        // yield (divisor)
				inte->_lsu[i] = (unit)(carry & EData._Mask); // yield (divisor % BASE)
				carry >>= EData._Shift;                      // yield (divisor / BASE)
			}
			inte->_lsu[_expo] = (unit)(carry);
			if (carry != 0) {
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

/*Absolution of Integer
*/
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

/*Negation of Integer
*/
Integer *Nega(Integer *nega, Integer inte) {
	if (nega->_lsu == inte._lsu) {
		nega->_sign *= -1;
	}
	else {
		nega = ReInteger(nega, inte._expo);
		nega->_sign = -1 * inte._sign;
		nega->_expo = inte._expo;
		Memcpy(nega->_lsu, inte._lsu, inte._expo);
	}
	return nega;
}

/*Addition of Integer
Assume [lhs._expo >= rhs._expo]
   *BASE^{EXPO}               *BASE^{EXPO - 1}                                       *BASE^{1}                           *BASE^{0}
								  B_{EXPO - 1} +                          ... +          B_{1}                               B_{0}
+                                 C_{EXPO - 1} +                          ... +          C_{1}                             + C_{0}                     // yield Carry
== Carry_{EXPO} + (B_{EXPO - 1} + C_{EXPO - 1} + Carry_{EXPO - 1})%BASE + ... + (B_{1} + C_{1} + Carry_{1})%BASE  + (B_{0} + C_{0} + Carry_{0}) %BASE  // accumulate recursively
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
		rhop._sign *= -1;
		return Subt(summ, lhop, rhop);
	}

	in08 _sign = lhop._sign;
	if (lhop._expo < rhop._expo) {
		Integer swap = lhop; lhop = rhop; rhop = swap;
		_sign *= +1;
	}

	iptr _expo = lhop._expo + 1;
	summ = ReInteger(summ, _expo);

	dual carry = 0;
	for (iptr i = 0; i < rhop._expo; i += 1) {
		carry = lhop._lsu[i] + rhop._lsu[i] + carry;  // if SUMM overflows Unit, then Carry 1 to higher Unit;  
		summ->_lsu[i] = (unit)(carry & EData._Mask);  // SUMM in Unit
		carry >>= EData._Shift;                       // yield Carry
	}
	for (iptr j = rhop._expo; j < lhop._expo; j += 1) {
		carry = lhop._lsu[j] + carry;
		summ->_lsu[j] = (unit)(carry & EData._Mask);
		carry >>= EData._Shift;
	}
	summ->_lsu[lhop._expo] = (unit)(carry);

	summ->_sign = _sign;
	summ->_expo = (summ->_lsu[_expo - 1] == 0 ? _expo - 1 : _expo);
	return summ;
}

/*Subtraction of Integer
Assume [|lhs| > |rhs|]
			  *BASE^{EXPO - 1}                                        *BASE^{1}                            *BASE^{0}
				  B_{EXPO - 1} +                           ... +          B_{1}                                B_{0}
-                 C_{EXPO - 1} +                           ... +          C_{1}                              + C_{0}                      // yield Borrow
= (B_{EXPO - 1} + C_{EXPO - 1} + Borrow_{EXPO - 1})%BASE + ... + (B_{1} + C_{1} + Borrow_{1})%BASE  + (B_{0} + C_{0} + Borrow_{0}) %BASE  // attenuate recursively
*/
Integer *Subt(Integer *diff, Integer lhop, Integer rhop) {
	if (lhop._lsu == rhop._lsu) {
		diff = ReInteger(diff, 1);
		diff->_sign = lhop._sign;
		diff->_expo = 1;
		diff->_lsu[0] = (unit)0U;
		return diff;
	}

	// lhs and rhs have opposite signs
	if ((lhop._sign ^ rhop._sign) < 0) {
		/*
				(+)   (-)    (+)   (  + )
		case 3: lhs - rhs == lhs + (-rhs)
		case 4: lhs - rhs == lhs + (-rhs)
				(-)   (+)    (-)   (  - )
		*/
		rhop._sign *= -1;
		return Addi(diff, lhop, rhop);
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
		// [|lhs| == |rhs|]
		if (_expo <= 0) {
			diff = ReInteger(diff, 1);
			diff->_sign = _sign;
			diff->_expo = 1;
			diff->_lsu[0] = (unit)0U;
			return diff;
		}
		// [|lhs| < |rhs|]
		else if (lhop._lsu[_expo - 1] < rhop._lsu[_expo - 1]) {
			Integer swap = lhop; lhop = rhop; rhop = swap;
			_sign *= -1;
		}
	}
	diff = ReInteger(diff, _expo);

	dual borrow = 0;
	for (iptr i = 0; i < rhop._expo; i += 1) {
		borrow = lhop._lsu[i] - borrow - rhop._lsu[i];  // if DIFF underflows Unit, then Borrow 1 from higher Unit
		diff->_lsu[i] = (unit)(borrow & EData._Mask);   // DIFF in Unit
		borrow >>= EData._Shift;                        // yield Borrow
		borrow &= 1U;                                   // Borrow 1 from higher unit
	}
	for (iptr j = rhop._expo; j < _expo; j += 1) {
		borrow = lhop._lsu[j] - borrow;
		diff->_lsu[j] = (unit)(borrow & EData._Mask);
		borrow >>= EData._Shift;
		borrow &= 1U;
	}

	diff->_sign = _sign;
	diff->_expo = (diff->_lsu[_expo - 1] == 0 ? _expo - 1 : _expo);
	return diff;
}


/* Multiplication of Integer
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
	// prod may overwrite lhop or rhop
	if (Check(prod != NULL && (prod->_lsu == lhop._lsu || prod->_lsu == rhop._lsu), __FUNCTION__, EType._Fatal, "prod->_lsu == lhop._lsu || prod->_lsu == rhop._lsu", NULL)) {
		exit(EXIT_FAILURE);
	}

	in08 _sign = lhop._sign * rhop._sign;
	iptr _expo = lhop._expo + rhop._expo;
	prod = ReInteger(prod, _expo);

	/* Constraint Assurance
	BASE * BASE - 1                                          // Dual Unit
	==  (BASE - 1) +  (BASE - 1) * (BASE - 1)  + (BASE - 1)  // Unit
	>= _lsu[i + 1] + lhs._lsu[i] * rhs._lsu[j] + Carry       // Unit
	*/
	Memset(prod->_lsu, 0, prod->_expo);
	dual carry = 0;
	// [|lhop| == |rhop|]
	if (lhop._lsu == rhop._lsu) {
		/* Θ(n) = EXPO^2 -->> Θ(n) = (EXPO * (EXPO + 1)) / 2
		   Square(Sum_{i = 0, j = 0}^{EXPO - 1} B_{i, j} * BASE^{i + j})
		== Sum_{i = 0}^{EXPO - 1} B_{i}^2 * BASE^{2 * i}
		  + Sum_{i = 0}^{EXPO - 1} Sum_{j = i + 1}^{EXPO - 1} (2 * B_{i}) * B_{j} * BASE^{i + j}
		*/
		dual twice = 0;
		for (iptr i = 0; i < lhop._expo; i += 1) {
			carry = prod->_lsu[i + i] + lhop._lsu[i] * lhop._lsu[i];       // outer loop starts at P_{2 * i}*BASE^{2 * i}
			prod->_lsu[i + i] = (unit)(carry & EData._Mask);               // PROD in Unit
			carry >>= EData._Shift;                                        // yield Carry

			twice = 2 * rhop._lsu[i];
			for (iptr j = i + 1; j < rhop._expo; j += 1) {
				carry = prod->_lsu[i + j] + twice * rhop._lsu[j] + carry;  // inner loop starts at P_{2 * i + 1}*BASE^{2 * i + 1}
				prod->_lsu[i + j] = (unit)(carry & EData._Mask);
				carry >>= EData._Shift;
			}
			prod->_lsu[i + rhop._expo] = (unit)(carry);
		}
	}
	else {
		for (iptr i = 0; i < lhop._expo; i += 1) {                                // outer loop starts at B_{0}^BASE^{0}
			carry = 0;
			for (iptr j = 0; j < rhop._expo; j += 1) {                            // inner loop starts at C_{0}^BASE^{0}
				carry = prod->_lsu[i + j] + lhop._lsu[i] * rhop._lsu[j] + carry;  // if SUMM overflows Unit, then Carry 1 to higher Unit
				prod->_lsu[i + j] = (unit)(carry & EData._Mask);                  // SUMM in Unit
				carry >>= EData._Shift;                                           // yield Carry

			}
			prod->_lsu[i + rhop._expo] = (unit)(carry);
		}
	}

	prod->_sign = _sign;
	prod->_expo = (prod->_lsu[_expo - 1] == 0 ? _expo - 1 : _expo);
	return prod;
}

/* Division and Remainer of Integer
Assume [lhs._expo >= rhs._expo]
Step 1:  [B_8 > 0] and [C_5 > 0]
		*BASE^8  *BASE^7  *BASE^6  *BASE^5         |  *BASE^4  *BASE^3  *BASE^2  *BASE^1  *BASE^0
  (quad)  B_8      B_7      B_6      B_5           |    B_4      B_3      B_2      B_1      B_0
÷ (quad)	       C_5      C_4      C_3           |                      C_2      C_1      C_0
==(quad)  				    Q_3      Q_{Discard}  // Q_3 >= 0

	B_8*BASE^8 + B_7*BASE^7 + B_6*BASE^6 + B_5*BASE^5
>= (C_5*BASE^5 + C_4*BASE^4 + C_3*BASE^3) * (Q_3*BASE^3 + Q_{Discard}*BASE^2)
== (C_5*Q_3)*BASE^8 + (C_4*Q_3 + C_5*Q_{Discard})*BASE^7 + (C_3*Q_3 + C_4*Q_{Discard})*BASE^6 + (C_3*Q_{Discard})*BASE^5
>= (C_5*Q_3)*BASE^8 + (C_4*Q_3)*BASE^7 + (C_3*Q_3)*BASE^6

Step 2: Leave Out Q_{Discard}, or Q_{Discard} == 0
		  B_8      B_7      B_6  |      B_5      B_4      B_3      B_2      B_1      B_0
-     C_5*Q_3  C_4*Q_3  C_3*Q_3  |  C_2*Q_3  C_1*Q_3  C_0*Q_3   // Don't Forget Carry
==                              SUB

Step 3:
Case 0: [Q_3 == 0] => [Q ==                    Q_{Tail}]  // do shifting
Case 1: [SUB >  0] => [Q ==       Q_3*BASE^3 + Q_{Tail}]  // Absolute Assurance
Case 2: [SUB <  0] => [Q == (Q_3 - 1)*BASE^3 + Q_{Tail}]  // Absolute Assurance
Case 3: [sub == 0] => [Q ==       Q_3*BASE^3           ]  // Absolute Assurance
*/

/* Definition of Division
rema = lhs - rhs * Round(lhs / rhs) = lhs - rhs * quot
modu = lhs - rhs * Floor(lhs / rhs)

			   Round Floor                |  Edge  Ceil
lhs  rhs  quot  rema  modu  Round  Floor  |  Modu  Rema  Edge  Ceil
 12   10     1     2     2      1      1  |    -8    -8     2     2
-12   10    -1    -2     8     -1     -2  |     8    -2    -2    -1
 12  -10    -1     2    -8     -1     -2  |    -8     2    -2    -1
-12  -10     1    -2    -2      1      1  |     8     8     2     2
										  |
 10   12     0    10    10      0      0  |    -2    -2     1     1
-10   12     0   -10     2      0     -1  |     2   -10    -1     0
 10  -12     0    10    -2      0     -1  |    -2    10    -1     0
-10  -12     0   -10   -10      0      0  |     2     2     1     1
*/
Integer *DiviRema(Integer *quot, Integer *rema_lhop, Integer rhop) {
	// divisor must not be 0
	if (Check(rhop._expo == 1 && rhop._lsu[0] == 0, __FUNCTION__, EType._Error, "[|rhop| == 0]", "rhop._expo == 1 && rhop._lsu[0] == 0")) {
		return quot;
	}

	// quot may overwrite rema_lhop or rhop
	if (Check(quot != NULL && (quot->_lsu == rema_lhop->_lsu || quot->_lsu == rhop._lsu), __FUNCTION__, EType._Fatal, "quot->_lsu == rema_lhop->_lsu || quot->_lsu == rhop._lsu", NULL)) {
		exit(EXIT_FAILURE);
	}

	in08 _sign_quot = rema_lhop->_sign * rhop._sign;

	// Case 1: |lhop| < |rhop|
	if (rema_lhop->_expo < rhop._expo) {
		quot = ReInteger(quot, 1);
		quot->_sign = _sign_quot;
		quot->_expo = 1;
		quot->_lsu[0] = (unit)0U;
		return quot;
	}

	iptr _expo_quot = rema_lhop->_expo - rhop._expo + 1;
	quot = ReInteger(quot, _expo_quot);

	// Case 2: [rhop._expo <= rema_lhop->_expo <= 4]
	if (rema_lhop->_expo <= 4) {
		in08 shift_rhop = (4 - rhop._expo) * 8;
		quad _rhop = ((quad *)rhop._lsu)[0];
		_rhop <<= shift_rhop; _rhop >>= shift_rhop;

		in08 shift_lhop = (4 - rema_lhop->_expo) * 8;
		quad _lhop = ((quad *)rema_lhop->_lsu)[0];
		_lhop <<= shift_lhop; _lhop >>= shift_lhop;

		quad _quot = (quad)(_lhop / _rhop);
		((quad *)rema_lhop->_lsu)[0] = (quad)(_lhop - _rhop * _quot);
		for (iptr i = 0; i < _expo_quot; i += 1) {
			((unit *)quot->_lsu)[i] = ((unit *)&_quot)[i];
		}
	}
	// Case 3: [rhop._expo <= 2] and [4 < lhop_rema->_expo]
	else if (rhop._expo <= 2) {
		in08 shift_rhop = (2 - rhop._expo) * 8;
		dual _rhop = ((dual *)rhop._lsu)[0];
		_rhop <<= shift_rhop; _rhop >>= shift_rhop;

		unit *_msu_lhop = rema_lhop->_lsu + rema_lhop->_expo - rhop._expo;
		unit *_msu_quot = quot->_lsu + _expo_quot - rhop._expo;

		_msu_quot[0] = ((dual *)_msu_lhop)[0] / _rhop;
		_msu_lhop -= 1;
		_msu_quot -= 1;
		while (rema_lhop->_lsu <= _msu_lhop) {
			_msu_quot[0] = (unit)(((dual *)_msu_lhop)[0] / _rhop);
			if (_msu_quot[0] != 0) {
				((dual *)_msu_lhop)[0] -= _rhop * _msu_quot[0];
			}
			_msu_lhop -= 1;
			_msu_quot -= 1;
		}
	}
	// Case 4: [2 < rhop._expo] and [4 < rema_lhop->_expo]
	else {
		quad _rhop = ((quad *)(rhop._lsu + rhop._expo - 3))[0];
		_rhop <<= EData._Shift; _rhop >>= EData._Shift;

		unit *_msu_lhop = rema_lhop->_lsu + rema_lhop->_expo - 4;
		unit *_msu_quot = quot->_lsu + _expo_quot - 2;
		unit *_msu_rema = rema_lhop->_lsu + rema_lhop->_expo - (rhop._expo + 1);

		dual borrow_carry = 0;
		while (rema_lhop->_lsu <= _msu_lhop) {
			if (((dual *)_msu_lhop)[1] == 0) {
				((dual *)_msu_quot)[0] = (dual)(((quad *)_msu_lhop)[0] / _rhop);
				if (_msu_quot[1] != 0) {
					borrow_carry = 0;
					for (iptr i = 0; i < rhop._expo; i += 1) {
						borrow_carry = _msu_rema[i] - borrow_carry - rhop._lsu[i] * _msu_quot[i];  // if DIFF overflows Unit, then Borrow 1 from higher Unit
						_msu_rema[i] = (unit)(borrow_carry & EData._Mask);                         // DIFF in Unit
						borrow_carry >>= EData._Shift;                                             // yield Borrow
						borrow_carry &= 1U;                                                        // Borrow 1 from higher Unit
					}

					// DIFF < 0
					if (borrow_carry == 1U) {
						_msu_quot[1] -= 1;
						borrow_carry = 0;
						for (iptr i = 0; i < rhop._expo; i += 1) {
							borrow_carry = _msu_rema[i] + rhop._lsu[i] + borrow_carry;
							_msu_rema[i] = (unit)(borrow_carry & EData._Mask);
							borrow_carry >>= EData._Shift;
						}
					}
				}
			}
			_msu_lhop -= 1;
			_msu_quot -= 1;
			_msu_rema -= 1;
		}
	}

	quot->_sign = _sign_quot;
	quot->_expo = (quot->_lsu[_expo_quot - 1] == 0 ? _expo_quot - 1 : _expo_quot);

	iptr _expo_rema = rhop._expo;
	while (0 < _expo_rema && rema_lhop->_lsu[_expo_rema - 1] == 0) {
		_expo_rema -= 1;
	}
	rema_lhop->_expo = (_expo_rema <= 0 ? 1 : _expo_rema);  // if |rema| == 0, then rema_lhop->_expo = 1; 
	return quot;
}

////////////////////////////////////////

void TestDiviRema() {
	Integer lhop_rema = BeInteger();
	Integer *rhop = ReInteger(NULL, 1);
	//Parse(&lhs, "3298534883329", 10); // 3*256*256*256*256*256 + 1
	//Parse(rhs, "230", 10);            // 14341456014 + 108
	Parse(&lhop_rema, "356", 10);       // 1, 122           23, 0, 0 == 23*256*256
	Parse(rhop, "234", 10);             // 0, 234

	Integer *quot = ReInteger(NULL, 5);
	quot = DiviRema(NULL, &lhop_rema, *rhop);

	fprintf(stderr, "%d, %ld ""\n", quot->_sign, quot->_expo);
	iptr _expo_quot = quot->_expo;
	for (; 0 < _expo_quot; _expo_quot -= 1) {
		fprintf(stderr, "%d ", quot->_lsu[_expo_quot - 1]);
	}
	fprintf(stderr, "\n");

	fprintf(stderr, "%d, %ld ""\n", lhop_rema._sign, lhop_rema._expo);
	iptr _expo_rema = lhop_rema._expo;
	for (; 0 < _expo_rema; _expo_rema -= 1) {
		fprintf(stderr, "%d ", lhop_rema._lsu[_expo_rema - 1]);
	}
	fprintf(stderr, "\n");

	//DeInteger(&lhs);
	//DeInteger(rhs);
	//DeInteger(rema);
	//DeInteger(quot);
}

iptr main(iptr argc, ui08 *argv[]) {
	StartUp();

	// TestInteger();
	// TestAddi();
	// TestMult();
	TestDiviRema();

	CleanUp();
	return 0;
}

void Test_Integer() {
	Integer *inte = ReInteger(NULL, 1);
	Parse(inte, "-2,5_6", 10);
	Parse(inte, "131072", 10);
	Parse(inte, "0x0000", 10);

	fprintf(stderr, "[%d, %ld] ", inte->_sign, inte->_expo);
	iptr _expo = inte->_expo;
	for (; 0 <= _expo; _expo -= 1) {
		fprintf(stderr, "%d ", inte->_lsu[_expo - 1]);
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

	fprintf(stderr, "[%d, %ld] ", ret->_sign, ret->_expo);
	iptr _expo = ret->_expo;
	for (; 0 <= _expo; _expo -= 1) {
		fprintf(stderr, "%d ", ret->_lsu[_expo - 1]);
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

	fprintf(stderr, "[%d, %ld] ", ret->_sign, ret->_expo);
	iptr _expo = ret->_expo;
	for (; 0 <= _expo; _expo -= 1) {
		fprintf(stderr, "%d ", ret->_lsu[_expo - 1]);
	}
	fprintf(stderr, "\n");

	DeInteger(lhs);
	DeInteger(rhs);
	DeInteger(ret);
}

