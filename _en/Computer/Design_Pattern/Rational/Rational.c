/* Rational.c
Author: BSS9395
Update: 2020-06-05T17:26:00+08@China-Guangdong-Zhanjiang+08
Design: Rational Number
*/

/* Representation of Integer
Unit  Representation
== B_{EXPO - 1} * BASE^{EXPO - 1} + B_{EXPO - 2} * BASE^{EXPO - 2} + ... + B_{1} * BASE^{1} + B_{0} * BASE^{0}  // BASE == 2^{16}
== b_{expo - 1} * base^(expo - 1) + b_{expo - 2} * base^(expo - 2) + ... + b_{1} * base^(1) + B_{0} * base^(0)  // base <= 16
Digit Representation

=> 1 * BASE^EXPO >= 1 * base^expo                                               // Boundary Condition
=> expo * Log2(base) / Log2(BASE) <= EXPO
=> expo * Log2(base) / Log2(BASE) <  Floor(expo * Log2(base) / Log2(BASE)) + 1  // Absolute Assurance

=> expo <= EXPO * (Log2(BASE) / Log2(base)) = EXPO / (Log2(base) / Log2(BASE))
=> Ceil(expo) <= Floor(EXPO / (Log2(BASE) * Log2(base))) + 1                    // Absolute Assurance
*/

/* Range of Integer
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

#define true    1
#define false   0
#define Log2    log2
#define Memset  memset
#define Memcpy  memcpy
#define Malloc  malloc
#define Realloc realloc

////////////////////////////////////////

typedef ui08  unit;
typedef ui16  dual;
typedef ui32  quad;
//typedef ui16  unit;
//typedef ui32  dual;
//typedef ui64  quad;

typedef struct {
	in08 _make : 2;
	in08 _move : 2;
	ui08 *_init;
	ui08 *_head;
} String;

typedef struct {
	in08 _sign : 2;
	in08 _make : 2;
	iptr _expo;
	unit *_lsu;
} Integer;

typedef struct {
	in08 _sign : 2;
	in08 _make : 2;
	iptr _expo_nume;
	unit *_lsu_nume;
	iptr _expo_deno;
	unit *_lsu_deno;
} Rational;

typedef struct {
	Integer _inte;
	Rational _frac;
} Fraction;

Integer *Parse(Integer *inte, String *data, ui08 base);
String *Print(String *stri, Integer inte, ui08 base);
Integer *Abso(Integer *abso, Integer inte);
Integer *Nega(Integer *nega, Integer inte);
Integer *Tran(Integer *tran, Integer inte, iptr bits);
Integer *Addi(Integer *summ, Integer lhop, Integer rhop);
Integer *Subt(Integer *diff, Integer lhop, Integer rhop);
Integer *Mult(Integer *Prod, Integer lhop, Integer rhop);
Integer *DiviRema(Integer *quot, Integer *rema_lhop, Integer rhop);
Integer *DiviModu(Integer *quot, Integer *modu_lhop, Integer rhop);

////////////////////////////////////////

typedef const ui08 *Level;
typedef const ui08 *Type;
typedef const ui08 *Shift;
struct {
	const Level _Info;
	const Level _ToDo;
	const Level _Warn;
	const Level _Error;
	const Level _Fatal;

	const Type _String;
	const Type _Integer;
	const Type _Rational;
	const Type _Fraction;

	const Shift _Left;
	const Shift _Center;
	const Shift _Right;

	const double _Epsilon;
	const ui08 _Space[7];
	const ui08 _Digit[256];

	const dual _Base;
	const dual _Mask;
	const dual _Bits;
	double _Log2_base_BASE[16 + 1];
} ESpace = {
	._Info = "Info",
	._ToDo = "ToDo",
	._Warn = "Warn",
	._Error = "Error",
	._Fatal = "Fatal",

	._String = "String",
	._Integer = "Integer",
	._Rational = "Rational",
	._Fraction = "Fraction",
	._Left = "Left",
	._Center = "Center",
	._Right = "Right",

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
	._Bits = sizeof(unit) * 8,
	._Log2_base_BASE = {
		0.0, 0.0,
	},
};

iptr StartUp() {
	for (iptr base = 2; base <= 16; base += 1) {
		ESpace._Log2_base_BASE[base] = Log2(base) / Log2(ESpace._Base);
	}

	return 0;
}

iptr CleanUp() {
	iptr ret = 0;
	return ret;
}

String BeString(ui08 *init) {
	static String _stri = {
		._make = true,
		._move = false,
		._init = NULL,
		._head = NULL,
	};
	_stri._init = init;
	_stri._head = _stri._init;
	return _stri;
}

String *ReString(String *stri, iptr size) {
	if (stri == NULL) {
		stri = (String *)Malloc(1 * sizeof(String));
		stri->_init = (ui08 *)Malloc(size * sizeof(ui08));
		stri->_make = false;
		stri->_move = true;
		stri->_head = stri->_init;
	}
	else if ((stri->_head - stri->_init) < size) {
		if (stri->_move == true) {
			stri->_init = (ui08 *)Realloc(stri->_init, size * sizeof(ui08));
		}
		else {
			stri->_init = (ui08 *)Malloc(size * sizeof(ui08));
			stri->_move = true;
		}
		stri->_head = stri->_init;
	}
	else if (size <= 0) {
		size = (iptr)strlen(stri->_head) + 1;
		String *repl = (String *)Malloc(1 * sizeof(String));
		repl->_init = (ui08 *)Malloc(size * sizeof(ui08));
		repl->_make = false;
		repl->_move = true;
		repl->_head = repl->_init;
		Memcpy(repl->_head, stri->_head, size);
		stri = repl;
	}
	return stri;
}

String *DeString(String *stri) {
	if (stri != NULL) {
		if (stri->_move == true) {
			free(stri->_init);
			stri->_init = NULL;
		}
		if (stri->_make == false) {
			free(stri);
			stri = NULL;
		}
	}
	return stri;
}

Integer BeInteger() {
	static Integer _inte = {
		._sign = 0,
		._make = true,
		._expo = 1,
		._lsu = NULL,
	};
	_inte._lsu = (unit *)Malloc(1 * sizeof(unit));
	return _inte;
}

Integer *ReInteger(Integer *inte, iptr expo) {
	if (inte == NULL) {
		inte = (Integer *)Malloc(1 * sizeof(Integer));
		inte->_lsu = (unit *)Malloc(expo * sizeof(unit));
		inte->_sign = 0;
		inte->_make = false;
		inte->_expo = expo;
	}
	else if (inte->_expo < expo) {
		inte->_lsu = (unit *)Realloc(inte->_lsu, expo * sizeof(unit));
		inte->_expo = expo;
	}
	else if (expo <= 0) {
		expo = inte->_expo - expo;
		Integer *repl = (Integer *)Malloc(1 * sizeof(Integer));
		repl->_lsu = (unit *)Malloc(expo * sizeof(unit));
		repl->_sign = inte->_sign;
		repl->_make = false;
		repl->_expo = inte->_expo;
		Memcpy(repl->_lsu, inte->_lsu, inte->_expo);
		inte = repl;
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

////////////////////////////////////////

bool Check(bool failed, const ui08 *function, Level level, const ui08 *record, const ui08 *extra) {
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
Integer *Parse(Integer *inte, String *data, ui08 base) {
	if (Check(!(2 <= base && base <= 16), __FUNCTION__, ESpace._Error, "!(2 <= base && base <= 36)", NULL)) {
		return 0;
	}
	data->_head += Skip(data->_head, ESpace._Space);

	in08 _sign = +1;
	if (data->_head[0] == '+') {
		data->_head += 1;
		_sign = +1;
	}
	else if (data->_head[0] == '-') {
		data->_head += 1;
		_sign = -1;
	}

	if (data->_head[0] == '0') {
		data += 1;
		if (data->_head[0] == 'b' || data->_head[0] == 'B') {
			data->_head += 1;
			base = 2;
		}
		else if (data->_head[0] == 'o' || data->_head[0] == 'O') {
			data->_head += 1;
			base = 8;
		}
		else if (data->_head[0] == 'x' || data->_head[0] == 'X') {
			data->_head += 1;
			base = 16;
		}
	}
	data->_head += Skip(data->_head, "0_,");

	iptr expo = 0;
	const ui08 *digit = data->_head;
	while (digit[0] != '\0') {
		if (ESpace._Digit[digit[0]] <= base) {
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

	iptr _expo = (iptr)(expo * ESpace._Log2_base_BASE[base]) + 1;
	inte = ReInteger(inte, _expo);

	// base == 2^{n}
	if ((ui08)(base & (base - 1))) {

	}

	Memset(inte->_lsu, 0, _expo * sizeof(unit));
	dual carry = 0;
	_expo = 1;
	while (data->_head < digit) {
		if (data->_head[0] == '_' || data->_head[0] == ',') {
			data->_head += 1;
		}
		else {
			carry = ESpace._Digit[data->_head[0]];             // fetch b_{n - 2}
			data->_head += 1;

			for (iptr i = 0; i < _expo; i += 1) {
				carry = inte->_lsu[i] * base + carry;          // yield (divisor)
				inte->_lsu[i] = (unit)(carry & ESpace._Mask);  // yield (divisor % BASE)
				carry >>= ESpace._Bits;                        // yield (divisor / BASE)
			}
			inte->_lsu[_expo] = (unit)(carry);
			if (carry != 0) {
				_expo += 1;
			}
		}
	}

	inte->_sign = _sign;
	inte->_expo = _expo;
	return inte;
}

String *Print(String *stri, Integer inte, ui08 base) {
	if (base == 1 || base == 0) {
		iptr expo = (iptr)(inte._expo / ESpace._Log2_base_BASE[10]) + 1;
		stri = ReString(stri, 4 + 2 * expo + 2);

		stri->_head += sprintf(stri->_head, "[%d, %d]", inte._sign, inte._expo);
		while (0 < inte._expo) {
			stri->_head += sprintf(stri->_head, " %d", inte._lsu[inte._expo - 1]);
			inte._expo -= 1;
		}

		stri->_head = stri->_init;
		return stri;
	}

	if (Check(!(2 <= base && base <= 16), __FUNCTION__, ESpace._Error, "!(2 <= base && base <= 16)", NULL)) {
		return NULL;
	}
	iptr expo = (iptr)(inte._expo / ESpace._Log2_base_BASE[base]) + 1;
	stri = ReString(stri, expo + 2);
	stri->_head += expo - 1;
	stri->_head[0] = '\0';
	stri->_head -= 1;

	// base == 2^{n}
	if ((base & (base - 1)) == 0U) {
		/*
					  rema|  rema%=base
		+--------+--------+                     _rema == (dual)(inte._lsu[0] >> 2 * 3)
		|      <<|!!!!!>>>|  shift == 2,        _rema |= (dual)(inte._lsu[1] << shift)
		2--------1--------0
				 |     &&&|  base == 8, bits = 3
				 +--------+
					  mask|
		*/

		unit mask = base - 1;
		iptr bits = -1;
		while (base != 0) {
			bits += 1;
			base >>= 1;
		}

		unit *_lsu_inte = inte._lsu;
		unit *_msu_inte = inte._lsu + inte._expo - 1;
		dual _rema = _lsu_inte[0];
		iptr shift = ESpace._Bits;
		while (_lsu_inte <= _msu_inte) {
			if (bits <= shift) {
				stri->_head[0] = ESpace._Digit[_rema & mask];
				stri->_head -= 1;
				_rema >>= bits;
				shift -= bits;
			}
			else {
				_lsu_inte += 1;
				_rema |= (dual)(_lsu_inte[0] << shift);
				shift += ESpace._Bits;
			}
		}

		while (stri->_head[1] == '0') {
			stri->_head += 1;
		}

	}
	// base != 2^{n}
	else {
		Integer *lhop = ReInteger(&inte, 0);
		Integer *quot = ReInteger(NULL, inte._expo);

		unit _rhop = (unit)base;
		unit *_msu_lhop = lhop->_lsu + lhop->_expo - 1;
		unit *_msu_quot = quot->_lsu + quot->_expo - 1;
		unit *_tmp_lhop = _msu_lhop;
		unit *_tmp_quot = _msu_quot;

		unit *_lsu_lhop = NULL;
		while (0 < lhop->_expo) {
			_lsu_lhop = (_msu_lhop + 1) - lhop->_expo;

			_msu_quot[0] = (unit)(_msu_lhop[0] / _rhop);
			if (_msu_quot[0] == 0U) {
				lhop->_expo -= 1;
			}
			else {
				_msu_lhop[0] = (unit)(_msu_lhop[0] - _rhop * _msu_quot[0]);
				_msu_quot -= 1;
			}
			_msu_lhop -= 1;

			while (_lsu_lhop <= _msu_lhop) {
				_msu_quot[0] = (unit)(((dual *)_msu_lhop)[0] / _rhop);
				if (_msu_quot[0] != 0) {
					((dual *)_msu_lhop)[0] -= (dual)(_rhop *_msu_quot[0]);
				}
				_msu_lhop -= 1;
				_msu_quot -= 1;
			}
			stri->_head[0] = ESpace._Digit[_lsu_lhop[0]];
			stri->_head -= 1;

			unit *swap = _tmp_lhop; _tmp_lhop = _tmp_quot; _tmp_quot = swap;
			_msu_lhop = _tmp_lhop;
			_msu_quot = _tmp_quot;
		}

		DeInteger(quot);
		DeInteger(lhop);
	}

	stri->_head[0] = (inte._sign < 0 ? '-' : '+');
	return stri;
}

// Absolution of Integer
Integer *Abso(Integer *abso, Integer inte) {
	if (abso->_lsu != inte._lsu) {
		abso = ReInteger(&inte, 0);
	}
	abso->_sign = +1;
	return abso;
}

// Negation of Integer
Integer *Nega(Integer *nega, Integer inte) {
	if (nega->_lsu != inte._lsu) {
		nega = ReInteger(&inte, 0);
	}
	nega->_sign *= -1;
	return nega;
}

// Translate Integer by bits
Integer *Tran(Integer *tran, Integer inte, iptr bits) {
	if (bits == 0) {
		if (tran == NULL || tran->_lsu != inte._lsu) {
			tran = ReInteger(&inte, 0);
		}
		return tran;
	}

	if (bits > 0) {
		unit msu = inte._lsu[inte._expo - 1];
		iptr rhs = 0;
		while (msu != 0) {
			msu >>= 1;
			rhs += 1;   // rhs starts at least significant bit
		}
		iptr units = (bits + rhs) / ESpace._Bits;
		iptr lhs = (bits + rhs) - ESpace._Bits * units;
		iptr _expo = (lhs == 0 ? inte._expo + units - 1 : inte._expo + units);
		tran = ReInteger(tran, _expo);

		/* Case 1: Shift Left, bits == +27, lhs > rhs
				   units == (bits + rhs) / ESpace._Bits         == 30 / 8     == 3
				   lhs   == (bits + rhs) - ESpace._Bits * units == 30 - 8 * 3 == 6
				   _expo == inte._expo + units                  == 3 + 3      == 6
								   _msu_inte|        _lsu_inte|
								   +--------+--------+--------+
								   |     1!!|!!!!!!!!|!!!!!!!!|  rhs == 3
		6--------5--------4--------3--------2--------1--------0
		|  1!!!!!|!!!!!!!!|!!!!!000|00000000|00000000|00000000|  lhs == 6, off == lhs - rhs == 3, inv == ESpace._Bits - off == 5
		+--------+--------+--------+--------+--------+--------+
		_msu_tran|                                   _lsu_tran|
		*/
		if (lhs > rhs) {
			iptr off = lhs - rhs;
			iptr inv = ESpace._Bits - off;

			unit *_msu_inte = inte._lsu + inte._expo - 1;
			unit *_msu_tran = tran->_lsu + _expo - 1;
			_msu_tran[0] = (_msu_inte[0] << off);
			_msu_inte -= 1;
			while (inte._lsu <= _msu_inte) {
				_msu_tran[0] |= (_msu_inte[0] >> inv);
				_msu_tran -= 1;
				_msu_tran[0] = (_msu_inte[0] << off);
				_msu_inte -= 1;
			}
			while (tran->_lsu <= _msu_tran) {
				_msu_tran[0] = (unit)0U;
				_msu_tran -= 1;
			}
		}
		/* Case 2: Shift Left, bits == +21, lhs < rhs
				   units == (bits + rhs) / ESpace._Bits         == 27 / 8     == 3
				   lhs   == (bits + rhs) - ESpace._Bits * units == 27 - 8 * 3 == 3
				   _expo == inte._expo + units                  == 3 + 3      == 6
								   _msu_inte|        _lsu_inte|
								   +--------+--------+--------+
								   |  1!!!!!|!!!!!!!!|!!!!!!!!|  rhs == 6
		6--------5--------4--------3--------2--------1--------0
		|     1!!|!!!!!!!!|!!!!!!!!|!!!00000|00000000|00000000|  lhs == 3, off == rhs - lhs == 3, inv == ESpace._Bits - off == 5
		+--------+--------+--------+--------+--------+--------+
		_msu_tran|                                   _lsu_tran|
		*/
		else if (lhs < rhs) {
			iptr off = rhs - lhs;
			iptr inv = ESpace._Bits - off;

			unit *_msu_inte = inte._lsu + inte._expo - 1;
			unit *_msu_tran = tran->_lsu + _expo - 1;
			_msu_tran[0] = (unit)0U;
			while (inte._lsu <= _msu_inte) {
				_msu_tran[0] |= (_msu_inte[0] >> off);
				_msu_tran -= 1;
				_msu_tran[0] = (_msu_inte[0] << inv);
				_msu_inte -= 1;
			}
			while (tran->_lsu <= _msu_tran) {
				_msu_tran[0] = (unit)0U;
				_msu_tran -= 1;
			}
		}

		tran->_sign = inte._sign;
		tran->_expo = _expo;
	}
	else if (bits < 0) {
		bits = -1 * bits;
		iptr units = bits / ESpace._Bits;
		iptr _expo = inte._expo - units;
		tran = ReInteger(tran, _expo);

		/* Case 3: Shift Right, bits == -30
				   units == |bits| / ESpace._Bits == 30 / 8 == 3
				   _expo == inte._expo - units    == 6 - 3  == 3
		_msu_inte|                                   _lsu_inte|
		+--------+--------+--------+--------+--------+--------+
		|  1!!!!!|!!!!!!!!|!$!!!!!!|!!!!!!!!|!!!!!!!!|!!!!!!!!|  lhs = 6
		6--------5--------4--------3--------2--------1--------0
								   |        |1!!!!!!!|!!!!!!!$|  rhs = 0, off == |bits| - ESpace._Bits * units == 30 - 8 * 3 == 6
								   +--------+--------+--------+
								   _msu_tran|        _lsu_tran|
		*/

		iptr off = bits - ESpace._Bits * units;
		iptr inv = ESpace._Bits - off;

		unit *_lsu_inte = inte._lsu + units;
		unit *_msu_inte = inte._lsu + inte._expo - 1;
		unit *_lsu_tran = tran->_lsu;
		_lsu_tran[0] = (_lsu_inte[0] >> off);
		_lsu_inte += 1;
		while (_lsu_inte <= _msu_inte) {
			_lsu_tran[0] |= (_lsu_inte[0] << inv);
			_lsu_tran += 1;
			_lsu_tran[0] = (_lsu_inte[0] >> off);
			_lsu_inte += 1;
		}

		tran->_sign = inte._sign;
		tran->_expo = (tran->_lsu[_expo - 1] == 0 ? _expo - 1 : _expo);
	}

	return tran;
}

/* Addition of Integer
Assume [lhs._expo >= rhs._expo]
   *BASE^{EXPO}               *BASE^{EXPO - 1}                                       *BASE^{1}                           *BASE^{0}
								  B_{EXPO - 1} +                          ... +          B_{1}                               B_{0}
+                                 C_{EXPO - 1} +                          ... +          C_{1}                             + C_{0}                     // yield Carry
== Carry_{EXPO} + (B_{EXPO - 1} + C_{EXPO - 1} + Carry_{EXPO - 1})%BASE + ... + (B_{1} + C_{1} + Carry_{1})%BASE  + (B_{0} + C_{0} + Carry_{0}) %BASE  // accumulate recursively
*/
Integer *Addi(Integer *summ, Integer lhop, Integer rhop) {
	// lhs and rhs have opposite signs
	if ((lhop._sign * rhop._sign) < 0) {
		/*
				(+)   (-)    (+)   (  + )
		case 1: lhs + rhs == lhs - (-rhs)
		case 2: lhs + rhs == lhs - (-rhs)
				(-)   (+)    (-)   (  - )
		*/
		rhop._sign *= -1;
		return Subt(summ, lhop, rhop);
	}

	if (lhop._lsu == rhop._lsu) {
		return Tran(summ, lhop, 1);
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
		carry = lhop._lsu[i] + rhop._lsu[i] + carry;   // if SUMM overflows Unit, then Carry 1 to higher Unit;  
		summ->_lsu[i] = (unit)(carry & ESpace._Mask);  // SUMM in Unit
		carry >>= ESpace._Bits;                       // yield Carry
	}
	for (iptr j = rhop._expo; j < lhop._expo; j += 1) {
		carry = lhop._lsu[j] + carry;
		summ->_lsu[j] = (unit)(carry & ESpace._Mask);
		carry >>= ESpace._Bits;
	}
	summ->_lsu[lhop._expo] = (unit)(carry);

	summ->_sign = _sign;
	summ->_expo = (summ->_lsu[_expo - 1] == 0 ? _expo - 1 : _expo);
	return summ;
}

/* Subtraction of Integer
Assume [|lhs| > |rhs|]
			  *BASE^{EXPO - 1}                                        *BASE^{1}                            *BASE^{0}
				  B_{EXPO - 1} +                           ... +          B_{1}                                B_{0}
-                 C_{EXPO - 1} +                           ... +          C_{1}                              + C_{0}                      // yield Borrow
= (B_{EXPO - 1} + C_{EXPO - 1} + Borrow_{EXPO - 1})%BASE + ... + (B_{1} + C_{1} + Borrow_{1})%BASE  + (B_{0} + C_{0} + Borrow_{0}) %BASE  // attenuate recursively
*/
Integer *Subt(Integer *diff, Integer lhop, Integer rhop) {
	// lhs and rhs have opposite signs
	if ((lhop._sign * rhop._sign) < 0) {
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
		if (lhop._lsu == rhop._lsu) {
			_expo = 0;
		}
		else {
			while (0 < _expo && lhop._lsu[_expo - 1] == rhop._lsu[_expo - 1]) {
				_expo -= 1;
			}
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
		diff->_lsu[i] = (unit)(borrow & ESpace._Mask);   // DIFF in Unit
		borrow >>= ESpace._Bits;                        // yield Borrow
		borrow &= 1U;                                   // Borrow 1 from higher unit
	}
	for (iptr j = rhop._expo; j < _expo; j += 1) {
		borrow = lhop._lsu[j] - borrow;
		diff->_lsu[j] = (unit)(borrow & ESpace._Mask);
		borrow >>= ESpace._Bits;
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
	if (Check(prod != NULL && (prod->_lsu == lhop._lsu || prod->_lsu == rhop._lsu), __FUNCTION__, ESpace._Fatal, "prod->_lsu == lhop._lsu || prod->_lsu == rhop._lsu", NULL)) {
		CleanUp();
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
	Memset(prod->_lsu, 0, prod->_expo * sizeof(unit));
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
			prod->_lsu[i + i] = (unit)(carry & ESpace._Mask);              // PROD in Unit
			carry >>= ESpace._Bits;                                       // yield Carry

			twice = 2 * rhop._lsu[i];
			for (iptr j = i + 1; j < rhop._expo; j += 1) {
				carry = prod->_lsu[i + j] + twice * rhop._lsu[j] + carry;  // inner loop starts at P_{2 * i + 1}*BASE^{2 * i + 1}
				prod->_lsu[i + j] = (unit)(carry & ESpace._Mask);
				carry >>= ESpace._Bits;
			}
			prod->_lsu[i + rhop._expo] = (unit)(carry);
		}
	}
	else {
		for (iptr i = 0; i < lhop._expo; i += 1) {                                // outer loop starts at B_{i}^BASE^{i}
			carry = 0;
			for (iptr j = 0; j < rhop._expo; j += 1) {                            // inner loop starts at C_{j}^BASE^{j}
				carry = prod->_lsu[i + j] + lhop._lsu[i] * rhop._lsu[j] + carry;  // if SUMM overflows Unit, then Carry 1 to higher Unit
				prod->_lsu[i + j] = (unit)(carry & ESpace._Mask);                 // SUMM in Unit
				carry >>= ESpace._Bits;                                          // yield Carry
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
	if (Check(rhop._expo == 1 && rhop._lsu[0] == 0U, __FUNCTION__, ESpace._Error, "[|rhop| == 0]", "rhop._expo == 1 && rhop._lsu[0] == 0")) {
		return quot;
	}

	// quot may overwrite rema_lhop or rhop
	if (Check(quot != NULL && (quot->_lsu == rema_lhop->_lsu || quot->_lsu == rhop._lsu), __FUNCTION__, ESpace._Fatal, "quot->_lsu == rema_lhop->_lsu || quot->_lsu == rhop._lsu", NULL)) {
		CleanUp();
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
		quad _rhop = ((quad *)rhop._lsu)[0] & (quad)((1U << (rhop._expo * sizeof(unit) * 8)) - 1);
		quad _lhop = ((quad *)rema_lhop->_lsu)[0] & (quad)((1U << (rhop._expo * sizeof(unit) * 8)) - 1);
		quad _quot = (quad)(_lhop / _rhop);
		quad _rema = (quad)(_lhop - _rhop * _quot);
		for (iptr i = 0; i < _expo_quot; i += 1) {
			((unit *)quot->_lsu)[i] = ((unit *)&_quot)[i];
		}
		for (iptr i = 0; i < rhop._expo; i += 1) {
			((unit *)rema_lhop->_lsu)[i] = ((unit *)&_rema)[i];
		}
	}
	// Case 3: [rhop._expo <= 2] and [4 < lhop_rema->_expo]
	else if (rhop._expo <= 2) {
		dual _rhop = ((dual *)rhop._lsu)[0] & (dual)((1U << (rhop._expo * sizeof(unit) * 8)) - 1);
		unit *_msu_lhop = rema_lhop->_lsu + rema_lhop->_expo - rhop._expo;
		unit *_msu_quot = quot->_lsu + _expo_quot - rhop._expo;

		if (rhop._expo == 1) {
			((unit *)_msu_quot)[0] = (unit)(((unit *)_msu_lhop)[0] / _rhop);
			((unit *)_msu_lhop)[0] = (unit)(((unit *)_msu_lhop)[0] - _rhop * ((unit *)_msu_quot)[0]);
		}
		else if (rhop._expo == 2) {
			((dual *)_msu_quot)[0] = (dual)(((dual *)_msu_lhop)[0] / _rhop);
			((dual *)_msu_lhop)[0] = (dual)(((dual *)_msu_lhop)[0] - _rhop * ((unit *)_msu_quot)[0]);
		}
		_msu_lhop -= 1;
		_msu_quot -= 1;
		while (rema_lhop->_lsu <= _msu_lhop) {
			_msu_quot[0] = (unit)(((dual *)_msu_lhop)[0] / _rhop);
			if (_msu_quot[0] != 0) {
				((dual *)_msu_lhop)[0] -= (dual)(_rhop * _msu_quot[0]);
			}
			_msu_lhop -= 1;
			_msu_quot -= 1;
		}
	}
	// Case 4: [2 < rhop._expo] and [4 < rema_lhop->_expo]
	else {
		quad _rhop = ((quad *)(rhop._lsu + rhop._expo - 3))[0];
		_rhop <<= ESpace._Bits; _rhop >>= ESpace._Bits;

		unit *_msu_lhop = rema_lhop->_lsu + rema_lhop->_expo - 4;
		unit *_msu_quot = quot->_lsu + _expo_quot - 2;
		unit *_msu_rema = rema_lhop->_lsu + rema_lhop->_expo - rhop._expo;  // Subtration Alignment

		dual borrow_carry = 0;
		while (rema_lhop->_lsu <= _msu_lhop) {
			if (((dual *)_msu_lhop)[1] != (dual)0U) {
				((dual *)_msu_quot)[0] = (dual)(((quad *)_msu_lhop)[0] / _rhop);
				if (_msu_quot[1] != (unit)0U) {
					borrow_carry = 0;
					for (iptr i = 0; i < rhop._expo; i += 1) {
						borrow_carry = _msu_rema[i] - borrow_carry - rhop._lsu[i] * _msu_quot[1];  // if DIFF overflows Unit, then Borrow 1 from higher Unit
						_msu_rema[i] = (unit)(borrow_carry & ESpace._Mask);                        // DIFF in Unit
						borrow_carry >>= ESpace._Bits;                                             // yield Borrow
						borrow_carry &= 1U;                                                        // Borrow 1 from higher Unit
					}

					// DIFF < 0
					if (borrow_carry == 1U) {
						_msu_quot[1] -= 1;
						borrow_carry = 0;
						for (iptr i = 0; i < rhop._expo; i += 1) {
							borrow_carry = _msu_rema[i] + rhop._lsu[i] + borrow_carry;
							_msu_rema[i] = (unit)(borrow_carry & ESpace._Mask);
							borrow_carry >>= ESpace._Bits;
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

Integer *DiviModu(Integer *quot, Integer *modu_lhop, Integer rhop) {
	in08 _sign_modu = rhop._sign;

	quot = DiviRema(quot, modu_lhop, rhop);
	// rema and rhop have opposite signs
	if ((rhop._sign * modu_lhop->_sign) < 0) {
		((Integer *)modu_lhop)[0] = ((Integer *)Addi(modu_lhop, *modu_lhop, rhop))[0];
	}

	return quot;
}

////////////////////////////////////////

void TestDiviRema() {
	// [3, 0, 0, 0, 0, 1]; (3*256^{5} + 1) / 230 = 14341456014        = [3, 86, 209, 64, 142]
	// [1, 0, 1]         ; (3*256^{5} + 1) / (256^{2} + 1) = 50330880 = [2, 255, 253, 0]
	//                   ; (3*256^{5} + 1) % (256^{2} + 1) = 769      = [3, 1]
	String stri = BeString("3298534883329");
	Integer *rema_lhop = Parse(NULL, &stri, 10);
	stri = BeString("50330880");
	Integer *rhop = Parse(NULL, &stri, 10);
	Integer *quot = DiviRema(NULL, rema_lhop, *rhop);

	String *print_quot = Print(NULL, *quot, 10);
	fprintf(stderr, "%s ""\n", print_quot->_head);
	String *print_rema = Print(NULL, *rema_lhop, 10);
	fprintf(stderr, "%s ""\n", print_rema->_head);

	DeString(&stri);
	DeInteger(rema_lhop);
	DeInteger(rhop);
	DeInteger(quot);
	DeString(print_quot);
	DeString(print_rema);
}

iptr main(iptr argc, ui08 *argv[]) {
	StartUp();

	TestDiviRema();

	CleanUp();
	return 0;
}