/* Notation.c
Author: BSS9395
Update: 2020-01-12T16:15:00+08@China-Guangdong-Zhanjiang+08
Design: Data Transfer Format
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

////////////////////////////////////////////////////////////////////////////////

typedef  intptr_t  iptr;
typedef  unsigned  char   unch;
typedef  int8_t    in08;  typedef  int16_t   in16;  typedef  int32_t   in32;  typedef  int64_t   in64;
typedef  uint8_t   ui08;  typedef  uint16_t  ui16;  typedef  uint32_t  ui32;  typedef  uint64_t  ui64;
typedef  float     fl32;  typedef  double    fl64;

typedef const unch *Type;
struct _EType {
    Type _UnKnown;
    Type _Logic;
    Type _Number;
    Type _Fixed;
    Type _Float;
    Type _String;
    Type _Binary;
    Type _TimeStamp;
    Type _SiteStamp;
} EType = {
    ._UnKnown = "UnKnown",._Logic = "Logic",
    ._Number = "Number",._Fixed = "Fixed",._Float = "Float",
    ._String = "String",._Binary = "Binary",
    ._TimeStamp = "TimeStamp",._SiteStamp = "SiteStamp"
};

typedef const unch *Level;
struct _ELevel {
    Level _ToDo;
    Level _Info;
    Level _Warn;
    Level _Error;
    Level _Fatal;
} ELevel = {
    ._ToDo = "ToDo",._Info = "Info",._Warn = "Warn",._Error = "Error",._Fatal = "Fatal"
};

typedef struct _Buffer {
    unch *_buff;
    iptr _leng;
    iptr _size;
} Buffer;

typedef struct _Attri {
    unch *_attri;
    Type _type;
    iptr _leng;
    unch *_value;
    struct _Attri *_link;
} Attri;

typedef struct _Entry {
    unch *_entry;
    ui32 _xhash;
    struct _Attri **_list;  // the head of circular list
    struct _Entry *_nest;
    struct _Entry *_link;
} Entry;

static unch _Alpha[256] = {
#define PHD -1
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD
};

static in08 _Digit[256] = {
#define PHD -1
   '\0', PHD, PHD, PHD, PHD, PHD, PHD,'\a','\b','\t','\n','\v','\f','\r', PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    ' ', '!', '"', '#', '$', '%', '&','\'', '(', ')', '*', '+', ',', '-', '.', '/',
      0,   1,   2,   3,   4,   5,   6,   7,   8,   9, ':', ';', '<', '=', '>', '?',
    '@',  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,
     25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35, '[','\\', ']', '^', '_',
    '`',  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,
     51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61, '{', '|', '}', '~', PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD
};

static in08 _Delim[256] = {
#define PHD -1
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    ' ', '!', '"', PHD, '$', '%', '&','\'', '(', ')', '*', '+', ',', '-', '.', '/',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', PHD, PHD, '<', PHD, '>', '?',
    '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[','\\', ']', '^', '_',
    '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', PHD, '}', '~', PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD
};

static unch *_Delimiter = {
    "#"     // Comment ≡ ##Comment                     // ## From here to the end of this line, is a comment.
    ":"     // Entry   ≡ unary Entry with multi Attri  // person: name=`BSS9395`; ID=+19930905193000;

    // Prefix
    "?"     // Logic   ≡ None  | Posi  | Nega          // ?None    ?Posi    ?Nega
    "-+"    // Number  ≡ Fixed | Float                 // -#D0.02  +#D0.98  -#D1_000_000_000
    "`"     // String  ≡ ASCII | Unicode               // comment=`This's a string.`          // ``, Self-Escaped if doubles
    "^"     // Binary  ≡ ^Length^Anything              // ^#H5^HA-HA
    "@"     // Stamp   ≡ Time  | Site                  // @1993-09-05T19:30:00.000000+0800    // @@China~Guangdong~Zhanjian~Street~Building~No+0800

    // Infix
    "="     // Atrri Assignment          // name=`BSS9395`;
    "|"     // Array in Attri            // credit=-#D0.02|+#D0.98;

    // Suffix
    ";"     // Attri Delimiter
    "\n"    // Entry Delimiter
    "\r\n"  // Entry Delimiter
};

/* Pritable ASCII
 !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
*/

////////////////////////////////////////////////////////////////////////////////

#define  Fseek   fseek
#define  Ftell   ftell
#define  Fread   fread
#define  Fwrite  fwrite
#define  Malloc  malloc
#define  Realloc realloc
#define  Strcmp  strcmp
#define  Pow     pow

unch *Parse_Addi_Subt(unch *data, fl64 *number, in32 base, bool fixed);
unch *Parse_Mult_Divi(unch *data, fl64 *number, in32 base, bool fixed);
unch *Parse_Number(unch *data, fl64 *number, in32 base, bool fixed);

////////////////////////////////////////////////////////////////////////////////

bool Check(bool failed, Level level, unch *function, unch *record, unch *extra) {
    if (failed) {
        fprintf(stderr, "[%s] %s: %s%s""\n", level, function, record, (extra == NULL) ? "" : extra);
    }
    return failed;
}

iptr Length(unch *data) {
    iptr leng = -1;
    if (data != NULL) {
        while (leng += 1, data[leng] != '\0');
    }
    return leng;
}

ui32 XHash(unch *data, iptr leng) {
    ui32 xhash = 9395;
    if (leng == 0) {
        // The ending '\0' is also included.
        do {
            xhash = (xhash << 7) | (xhash >> 25);
            xhash ^= data[leng];
        } while (data[leng++] != '\0');
    }
    else if (leng > 0) {
        for (iptr i = 0; i < leng; i += 1) {
            xhash = (xhash << 7) | (xhash >> 25);
            xhash ^= data[leng];
        }
    }
    xhash += leng;
    return (ui32)xhash;
}

unch *Make_Data(unch *data, iptr leng, bool peel) {
    if (data != NULL && 0 <= leng) {
        if (leng == 0) {
            leng = Length(data);
        }
        if (peel == true) {
            // leave out white spaces at the ending.
            for (; 0 < leng && data[leng - 1] == ' ' || data[leng - 1] == '\t'; leng -= 1);
        }

        unch *make = Malloc((leng + 1) * sizeof(unch));
        for (iptr i = 0; i < leng; i += 1) {
            make[i] = data[i];
        }
        make[leng] = '\0';    // No matter if data has an ending '\0'.
        return make;
    }
    return NULL;
}

unch *Join_Data(unch *data, iptr leng_data, unch *join, iptr leng_join) {
    if (leng_join == 0) {
        leng_join = Length(join);
    }
    data = Realloc(data, leng_data + leng_join + 1);
    unch *retu = data;

    data += leng_data;
    for (iptr i = 0; i < leng_join; i += 1) {
        data[i] = join[i];
    }
    data[leng_join] = '\0';   // No matter if join has an ending '\0'.
    return retu;
}

unch *Copy_Data(unch *buff, unch *data, iptr leng) {
    if (leng == 0) {
        for (; data[leng] != '\0'; leng += 1) {
            buff[leng] = data[leng];
        }
    }
    else if (leng > 0) {
        for (iptr i = 0; i < leng; i += 1) {
            buff[i] = data[i];
        }
    }
    buff[leng] = '\0';        // no matter if data has an ending '\0'.
    return &buff[leng];
}

unch *Print_Number(unch *buff, fl64 number, in32 base, fl64 prec) {
    bool plus = (prec < 0) ? (prec = -prec, true) : false;
    bool wave = (base < 0) ? (base = -base, true) : false;

    if (number < 0) {
        number = -number;
        buff[0] = '-';
        buff += 1;
    }
    else if (plus == true) {
        buff[0] = '+';
        buff += 1;
    }
    if (wave) {
        if (base == 10) {
            buff[0] = '#', buff[1] = 'D';
        }
        else if (base == 2) {
            buff[0] = '#', buff[1] = 'B';
        }
        else if (base == 8) {
            buff[0] = '#', buff[1] = 'O';
        }
        else if (base == 16) {
            buff[0] = '#', buff[1] = 'H';
        }
        buff += 2;
    }

    in64 integer = (in64)prec;
    prec -= integer, number += prec / base;     // round-off
    number -= (integer < number) ? (integer = (in64)number) : (in64)number;

    unch ch = 0;
    unch *fore = buff;
    do {
        ch = (unch)(integer % base);
        // buffer[0] = (ch < 10) ? (ch + '0') : (ch + 'A' - 10);
        buff[0] = _Alpha[ch];
        buff += 1;
        integer /= base;
    } while (0 < integer);
    for (unch *back = buff - 1; fore < back; fore += 1, back -= 1) {
        fore[0] = fore[0] ^ back[0];
        back[0] = fore[0] ^ back[0];
        fore[0] = fore[0] ^ back[0];
    }

    if (number != 0.0 && prec != 0.0) {
        buff[0] = '.';
        buff += 1;

        while (prec *= base, prec <= 1) {
            number *= base;
            ch = (unch)number;
            buff[0] = _Alpha[ch];
            buff += 1;
            number -= ch;
        }
    }

    buff[0] = '\0';
    return buff;
}

unch *Print_TimeStamp(unch *buff, in32 YYYY, in32 MM, in32 DD, in32 hh, in32 mm, in32 ss, in32 tttttt, in32 ZZzz) {
    // TimeStamp ≡ YYYY-MM-DDThh:mm:ss.ttttttZZZzz
    unch ch = 0;
    buff += 4;
    for (iptr i = 1; i <= 4; i += 1) {
        ch = (unch)(YYYY % 10);
        if (_Alpha[ch] == PHD && Check(true, ELevel._Error, __FUNCTION__, "_Alpha[ch] == PHD", NULL)) {
            return NULL;
        }
        buff[-i] = _Alpha[ch];
        YYYY = YYYY / 10;
    }

    buff[0] = '-';
    buff += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (unch)(MM % 10);
        if (_Alpha[ch] == PHD && Check(true, ELevel._Error, __FUNCTION__, "_Alpha[ch] == PHD", NULL)) {
            return NULL;
        }
        buff[-i] = _Alpha[ch];
        MM = MM / 10;
    }

    buff[0] = '-';
    buff += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (unch)(DD % 10);
        if (_Alpha[ch] == PHD && Check(true, ELevel._Error, __FUNCTION__, "_Alpha[ch] == PHD", NULL)) {
            return NULL;
        }
        buff[-i] = _Alpha[ch];
        DD = DD / 10;
    }

    buff[0] = 'T';
    buff += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (unch)(hh % 10);
        if (_Alpha[ch] == PHD && Check(true, ELevel._Error, __FUNCTION__, "_Alpha[ch] == PHD", NULL)) {
            return NULL;
        }
        buff[-i] = _Alpha[ch];
        hh = hh / 10;
    }

    buff[0] = ':';
    buff += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (unch)(mm % 10);
        if (_Alpha[ch] == PHD && Check(true, ELevel._Error, __FUNCTION__, "_Alpha[ch] == PHD", NULL)) {
            return NULL;
        }
        buff[-i] = _Alpha[ch];
        mm = mm / 10;
    }

    buff[0] = ':';
    buff += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (unch)(ss % 10);
        if (_Alpha[ch] == PHD && Check(true, ELevel._Error, __FUNCTION__, "_Alpha[ch] == PHD", NULL)) {
            return NULL;
        }
        buff[-i] = _Alpha[ch];
        ss = ss / 10;
    }

    buff[0] = '.';
    buff += 7;
    if (tttttt == 0) {
        buff[-1] = '0', buff[-2] = '0', buff[-3] = '0', buff[-4] = '0', buff[-5] = '0', buff[-6] = '0';
    }
    else {
        for (iptr i = 1; i <= 6; i += 1) {
            ch = (unch)(tttttt % 10);
            if (_Alpha[ch] == PHD && Check(true, ELevel._Error, __FUNCTION__, "_Alpha[ch] == PHD", NULL)) {
                return NULL;
            }
            buff[-i] = _Alpha[ch];
            tttttt = tttttt / 10;
        }
    }

    buff[0] = (ZZzz < 0) ? (ZZzz = -ZZzz, '-') : '+';
    buff += 5;
    for (iptr i = 1; i <= 4; i += 1) {
        ch = (unch)(ZZzz % 10);
        if (_Alpha[ch] == PHD && Check(true, ELevel._Error, __FUNCTION__, "_Alpha[ch] == PHD", NULL)) {
            return NULL;
        }
        buff[-i] = _Alpha[ch];
        ZZzz = ZZzz / 10;
    }

    buff[0] = '\0';
    return buff;
}

unch *Parse_Addi_Subt(unch *data, fl64 *number, in32 base, bool fixed) {
    data = Parse_Mult_Divi(data, number, base, fixed);
    for (unch op = data[0]; op == '+' || op == '-'; op = data[0]) {
        data += 1;

        fl64 remain = 0.0;
        data = Parse_Mult_Divi(data, &remain, base, fixed);
        if (op == '+') {
            (*number) += remain;
        }
        else if (op == '-') {
            (*number) -= remain;
        }
    }
    return data;
}

unch *Parse_Mult_Divi(unch *data, fl64 *number, in32 base, bool fixed) {
    data = Parse_Number(data, number, base, fixed);
    for (unch op = data[0]; op == '*' || op == '/' || op == '%'; op = data[0]) {
        data += 1;

        fl64 remain = 0.0;
        data = Parse_Number(data, &remain, base, fixed);
        if (op == '*') {
            (*number) *= remain;
        }
        else if (op == '/') {
            (*number) /= remain;
        }
        else if (op == '%') {
            in64 quot = (iptr)((*number) / remain);
            (*number) -= quot * remain;
        }
    }
    return data;
}

/* Operator Precedence: from Low to High          Operator Associativity:
          v Entrance
AddiSubt   ≡ <MultDivi>[± MultDivi]               from Left to Right
MultDivi   ≡ <Number>[⋇ Number]                   from Left to Right
Number     ≡ [±]<Digit|(AddiSubt)>[{AddiSubt}]    from Right to Left     Digit{Expression} ≡ Pow(Digit, Expression)
Digit      ≡ <0-9>[.0-9]

Expression ≡ Term   |   Term ± Term
Term       ≡ Factor | Factor ⋇ Factor
Factor     ≡ Digit  | ±Digit | (Expression) | ±(Expression) | Digit{Expression} | ±Digit{Expression} | (Expression){Expression} | ±(Expression){Expression}
Digit      ≡ <0-9>[.0-9]
*/
unch *Parse_Number(unch *data, fl64 *number, in32 base, bool fixed) {
    unch *_retu = data;
    in08 sign = +1;
    fl64 value = 0.0;
    for (; data[0] == ' '; data += 1);  // leave out the leading spaces.

    if (data[0] == '+') {
        data += 1;
        sign = +1;
    }
    else if (data[0] == '-') {
        data += 1;
        sign = -1;
    }
    if (data[0] == '#') {
        if (data[1] == 'D') {
            base = 10;
        }
        else if (data[1] == 'B') {
            base = 2;
        }
        else if (data[1] == 'O') {
            base = 8;
        }
        else if (data[1] == 'H') {
            base = 16;
        }
        else {
            Check(true, ELevel._Error, __FUNCTION__, "unknown base", NULL);
            return _retu;
        }
        data += 2;
    }

    if (data[0] == '(') {
        data += 1;
        data = Parse_Addi_Subt(data, &value, base, fixed);
        if (data[0] != ')') {
            Check(true, ELevel._Error, __FUNCTION__, "data[0] != ')", NULL);
            // (*number) = sign * value;
            return _retu;
        }
        data += 1;
    }
    else {
        unch ch = -1;
        unch *_data = data;
        while (ch = _Digit[data[0]], 0 <= ch && ch < base) {
            data += 1;
            value = value * base + ch;
        }
        if (data == _data) {
            // parse unsuccessfully 
            Check(true, ELevel._Error, __FUNCTION__, "parse unsuccessfully", NULL);
            return _retu;
        }
        if (fixed == false && data[0] == '.') {
            data += 1;
            fl64 fact = 1.0;
            while (ch = _Digit[data[0]], 0 <= ch && ch < base) {
                data += 1;
                fact /= base;
                value += ch * fact;
            }
        }
    }

    if (data[0] == '{') {
        data += 1;
        fl64 expo = 0.0;
        data = Parse_Addi_Subt(data, &expo, base, fixed);
        value = Pow(value, expo);
        if (data[0] != '}') {
            Check(true, ELevel._Error, __FUNCTION__, "data[0] != '}'", NULL);
            // (*number) = sign * value;
            return _retu;
        }
        data += 1;
    }

    for (; data[0] == ' '; data += 1);  // leave out ending spaces.
    (*number) = sign * value;
    return data;
}

////////////////////////////////////////////////////////////////////////////////

Buffer Make_Buffer(iptr size) {
    static Buffer _buffer = {
        ._buff = NULL,
        ._leng = 0,
        ._size = 0
    };
    _buffer._buff = (unch *)Malloc(size * sizeof(unch));
    _buffer._size = size;
    return _buffer;
}

iptr Free_Buffer(Buffer buffer) {
    iptr retu = 0;
    free(buffer._buff);
    retu += 1;
    return retu;
}

Entry *Make_Entry(unch *entry, ui32 xhash) {
    Entry *make = Malloc(sizeof(Entry));
    make->_entry = entry;
    make->_xhash = xhash;
    make->_list = NULL;
    make->_nest = NULL;
    make->_link = NULL;
    return make;
}

Attri *Make_Attri(unch *attri) {
    Attri *make = Malloc(sizeof(Attri));
    make->_attri = attri;
    make->_value = NULL;
    make->_type = EType._UnKnown;
    make->_leng = 0;
    make->_link = NULL;
    return make;
}

iptr Free_Attri(Attri *attri) {
    iptr retu = 0;
    if (attri != NULL) {
        free(attri->_attri);
        free(attri->_value);
        free(attri);
        retu += 3;
    }
    return retu;
}

iptr Free_Entry(Entry *entry) {
    iptr retu = 0;
    if (entry != NULL) {
        if (entry->_list != NULL) {
            Attri *node = NULL;
            Attri *list = *(entry->_list);
            Attri *iter = list;
            do {
                node = iter;
                iter = iter->_link;
                Free_Attri(node);
                retu += 1;
            } while (iter != list);
        }
        free(entry->_entry);
        free(entry);
        retu += 2;
    }
    return retu;
}

////////////////////////////////////////////////////////////////////////////////

Entry *Handle_Entry(Entry *super, unch *entry, bool sole) {
    ui32 xhash = XHash(entry, 0);
    Entry **last = &(super->_nest);
    Entry **iter = last;
    while ((*iter) != NULL && (*iter)->_xhash <= xhash) {
        last = iter;
        iter = &((*iter)->_link);
    }
    if (sole == true && (*last) != NULL && Strcmp((*last)->_entry, entry) == 0) {
        return (*last);
    }

    entry = Make_Data(entry, 0, true);
    Entry *node = Make_Entry(entry, xhash);
    node->_link = (*iter);
    (*iter) = node;
    return node;
}

Attri *Handle_Attri(Entry *entry, unch *attri, bool sole) {
    if (sole == true && entry->_list != NULL) {
        Attri *list = *(entry->_list);
        Attri *iter = list;
        do {
            if (Strcmp(iter->_attri, attri) == 0) {
                return iter;
            }
            iter = iter->_link;
        } while (iter != list);
    }

    attri = Make_Data(attri, 0, true);
    Attri *node = Make_Attri(attri);
    if (entry->_list == NULL) {
        // circular list
        node->_link = node;
        entry->_list = &(node->_link);
    }
    else {
        node->_link = *(entry->_list);
        *(entry->_list) = node;
        entry->_list = &(node->_link);
    }
    return node;
}

Entry *Detach_Entry(Entry *super, Entry *entry, bool wipe) {
    Entry **iter = &(super->_nest);
    while ((*iter) != NULL && (*iter) != entry) {
        iter = &((*iter)->_link);
    }
    if ((*iter) != NULL) {
        (*iter) = (*iter)->_link;
        if (wipe == true) {
            Free_Entry(entry);
            entry = NULL;
        }
        return entry;
    }
    return NULL;
}

Entry *Detach_Entry_Many(Entry *super, unch *entry, bool wipe) {
    ui32 xhash = XHash(entry, 0);

    Entry *node = NULL;
    Entry **many = NULL;
    Entry **iter = &(super->_nest);
    while ((*iter) != NULL && (*iter)->_xhash != xhash) {
        iter = &((*iter)->_link);
    }
    many = iter;
    while ((*iter) != NULL && Strcmp((*iter)->_entry, entry) == 0) {
        if (wipe == true) {
            node = (*iter);
            (*iter) = (*iter)->_link;  // many == iter
            Free_Entry(node);
        }
        else {
            iter = &((*iter)->_link);  // many != iter
        }
    }
    if (many != iter) {
        node = (*many);
        (*many) = (*iter);
        (*iter) = NULL;
        return node;
    }
    return NULL;
}

Attri *Detach_Attri(Entry *entry, Attri *attri, bool wipe) {
    Attri *many = NULL;
    if (entry->_list != NULL) {
        Attri **list = entry->_list;
        Attri **iter = list;
        bool goon = true;
        for (; goon == true; ) {
            if (&((*iter)->_link) == list) {
                goon = false;     // the loop break is in schedule.           
            }

            if ((*iter) == attri) {
                if ((*iter)->_link == (*iter)) {
                    // the only Attri
                    entry->_list = NULL;
                }
                else {
                    (*iter) = (*iter)->_link;
                }

                if (wipe == true) {
                    Free_Attri(attri);
                }
                else {
                    many = attri;
                }
                break;
            }
            iter = &((*iter)->_link);
        }
        if (goon == false && entry->_list != NULL) {
            entry->_list = iter;
        }
    }
    return many;
}

Attri *Detach_Attri_Many(Entry *entry, unch *attri, bool wipe) {
    Attri *many = NULL;
    if (entry->_list != NULL) {
        Attri *node = NULL;
        Attri **list = entry->_list;
        Attri **iter = list;
        for (bool goon = true; goon == true;) {
            if (&((*iter)->_link) == list) {
                goon = false;     // the loop break is in schedule.
            }

            if (Strcmp((*iter)->_attri, attri) == 0) {
                node = (*iter);
                if (node->_link == node) {
                    // the only Attri
                    entry->_list = NULL;
                }
                else {
                    (*iter) = (*iter)->_link;
                }

                if (wipe == true) {
                    Free_Attri(node);
                }
                else {
                    node->_link = many;
                    many = node;
                }
                continue;
            }
            iter = &((*iter)->_link);
        }
        if (entry->_list != NULL) {
            entry->_list = iter;
        }
    }
    return many;
}

////////////////////////////////////////////////////////////////////////////////

Entry *Attach_EType(Entry *entry, unch *attri, unch *value, iptr leng, Type type) {
    Attri *hand = Handle_Attri(entry, attri, false);
    if (!(hand->_type == EType._UnKnown || hand->_type == type)) {
        Check(true, type, __FUNCTION__, "!(hand->_type == EType._UnKnown || hand->_type == type)", NULL);
    }
    hand->_value = Join_Data(hand->_value, hand->_leng, value, leng);
    hand->_leng += leng;
    hand->_type = type;
    return entry;
}

Entry *Attach_Logic(Entry *entry, unch *attri, bool logi, bool many) {
    static bool *_value = NULL;
    static iptr _many = 0;
    static iptr _numb = 0;

    static Entry *_entry = NULL;
    static unch *_attri = NULL;

    if (_numb == 0) {
        _entry = entry;
        _attri = attri;
    }
    if (_entry == entry && _attri == attri) {
        if (_many <= _numb) {
            _many = 2 * _many + 1;
            _value = Realloc(_value, _many * sizeof(bool));
        }
        _value[_numb] = logi;
        _numb += 1;
        if (many == false && _numb >= 1) {
            Attach_EType(entry, attri, (unch *)_value, _numb * sizeof(bool), EType._Logic);
            _numb = 0;
        }
    }
    return entry;
}

Entry *Attach_Number(Entry *entry, unch *attri, fl64 frac, bool many) {
    static fl64 *_value = NULL;
    static iptr _many = 0;
    static iptr _numb = 0;

    static Entry *_entry = NULL;
    static unch *_attri = NULL;

    if (_numb == 0) {
        _entry = entry;
        _attri = attri;
    }
    if (_entry == entry && _attri == attri) {
        if (_many <= _numb) {
            _many = 2 * _many + 1;
            _value = Realloc(_value, _many * sizeof(fl64));
        }
        _value[_numb] = frac;
        _numb += 1;
        if (many == false && _numb >= 1) {
            Attach_EType(entry, attri, (unch *)_value, _numb * sizeof(fl64), EType._Number);
            _numb = 0;
        }
    }
    return entry;
}

Entry *Attach_String(Entry *entry, unch *attri, unch *stri, iptr leng) {
    leng = (0 < leng) ? leng : Length(stri);
    Attach_EType(entry, attri, stri, leng, EType._String);
    return entry;
}

Entry *Attach_Binary(Entry *entry, unch *attri, unch *bina, iptr leng) {
    Attach_EType(entry, attri, bina, leng, EType._Binary);
    return entry;
}

Entry *Attach_TimeStamp(Entry *entry, unch *attri, in32 YYYY, in32 MM, in32 DD, in32 hh, in32 mm, in32 ss, in32 tttttt, in32 ZZzz) {
    static unch _buffer[4096];
    unch *buffer = Print_TimeStamp(_buffer, YYYY, MM, DD, hh, mm, ss, tttttt, ZZzz);
    Attach_EType(entry, attri, _buffer, buffer - _buffer, EType._TimeStamp);
    return entry;
}

////////////////////////////////////////////////////////////////////////////////

unch *Obtain_EType(Entry *entry, unch *attri, iptr *leng, Type type) {
    if (entry->_list != NULL) {
        Attri *list = *(entry->_list);
        Attri *iter = list;
        do {
            if (Strcmp(iter->_attri, attri) == 0) {
                if (iter->_type != type) {
                    Check(true, ELevel._Warn, __FUNCTION__, "iter ->_type != type", NULL);
                }
                (*leng) = iter->_leng;
                entry->_list = &(iter->_link);
                return (unch *)(iter->_value);
            }
            iter = iter->_link;
        } while (iter != list);
    }
    return NULL;
}

bool *Obtain_Logic(Entry *entry, unch *attri, iptr *leng) {
    return (bool *)Obtain_EType(entry, attri, leng, EType._Logic);
}

fl64 *Obtain_Number(Entry *entry, unch *attri, iptr *leng) {
    return (fl64 *)Obtain_EType(entry, attri, leng, EType._Number);
}

unch *Obtain_String(Entry *entry, unch *attri, iptr *leng) {
    return (unch *)Obtain_EType(entry, attri, leng, EType._String);
}

unch *Obtain_Binary(Entry *entry, unch *attri, iptr *leng) {
    return (unch *)Obtain_EType(entry, attri, leng, EType._Binary);
}

unch *Obtain_TimeStamp(Entry *entry, unch *attri, iptr *leng) {
    return (unch *)Obtain_EType(entry, attri, leng, EType._TimeStamp);
}

////////////////////////////////////////////////////////////////////////////////

unch *Backpack(Buffer *buffer, Entry *note) {
    static Entry *_entry[256];
    iptr _top = 0;
    iptr space = 4;
    iptr white = 0;
    unch *buff = buffer->_buff;

    _entry[_top] = note->_nest;
    _top += 1;
    white += space;
    while (_top >= 1) {
        _top -= 1;
        Entry *head = _entry[_top];
        white -= space;

        while (head != NULL) {
            for (iptr i = 0; i < white; buff[i] = ' ', i += 1);
            buff += white;

            buff = Copy_Data(buff, head->_entry, 0);
            buff[0] = ':';
            buff += 1;
            if (head->_list != NULL) {
                Attri *list = *(head->_list);
                Attri *iter = list;
                do {
                    buff[0] = ' ';
                    buff += 1;

                    buff = Copy_Data(buff, iter->_attri, 0);
                    buff[0] = '=';
                    buff += 1;

                    if (iter->_type == EType._Logic) {
                        bool *value = (bool *)iter->_value;
                        iptr numb = iter->_leng / sizeof(bool);
                        for (iptr i = 0; i < numb; i += 1) {
                            if (i >= 1) {
                                buff[0] = '|';
                                buff += 1;
                            }
                            buff[0] = '?', (value[i] == true)
                                ? (buff[1] = 'P', buff[2] = 'o', buff[3] = 's', buff[4] = 'i')
                                : (buff[1] = 'N', buff[2] = 'e', buff[3] = 'g', buff[5] = 'a');
                            buff += 5;
                        }
                    }
                    else if (iter->_type == EType._Number || iter->_type == EType._Fixed || iter->_type == EType._Float) {
                        fl64 *value = (fl64 *)iter->_value;
                        iptr numb = iter->_leng / sizeof(fl64);
                        for (iptr i = 0; i < numb; i += 1) {
                            if (i >= 1) {
                                buff[0] = '|';
                                buff += 1;
                            }
                            buff = Print_Number(buff, value[i], 10, -0.000001);
                        }
                    }
                    else if (iter->_type == EType._String) {
                        buff[0] = '`';
                        buff += 1;
                        buff = Copy_Data(buff, iter->_value, iter->_leng);
                        buff[0] = '`';
                        buff += 1;
                    }
                    else if (iter->_type == EType._Binary) {
                        buff[0] = '^';
                        buff += 1;
                        buff = Print_Number(buff, iter->_leng, -16, 0.0);
                        buff[0] = '^';
                        buff += 1;
                        buff = Copy_Data(buff, iter->_value, iter->_leng);
                    }
                    else if (iter->_type == EType._TimeStamp) {
                        buff[0] = '@';
                        buff += 1;
                        buff = Copy_Data(buff, iter->_value, iter->_leng);
                    }
                    else if (iter->_type == EType._UnKnown) {
                        Check(true, ELevel._Warn, __FUNCTION__, "iter->_type == EType._UnKnown", NULL);
                    }
                    else {
                        Check(true, ELevel._ToDo, __FUNCTION__, "iter->_type is to be handled.", NULL);
                    }

                    buff[0] = ';';
                    buff += 1;
                } while (iter = iter->_link, iter != list);
                buff[0] = '\n';
                buff += 1;
            }

            _entry[_top] = head->_link;
            _top += 1;
            white += space;
            head = head->_nest;
        }
    }
    buff[0] = '\0';
    buffer->_leng = buff - buffer->_buff;
    return buffer->_buff;
}

/* Simple Syntax Tree of Notation
Notation ≡ <Line>[Line]\0
Line     ≡ indent<Blank|Entry>[Blank|Entry]
Blank    ≡ [\t\v\f\r ][##Comment]\n
Entry    ≡ entry[]:[]<Attri>[Attri][##Comment]\n
Attri    ≡ attri[]=[]value[];[]
*/
iptr Assemble(Entry *note, Buffer buffer) {
    static unch _buffer[4096];
    static Entry *_entry[256];
    static iptr _white[256];
    iptr _top = 0;
    iptr space = -4;
    iptr white = 0;
    unch *data = buffer._buff;
    unch *over = buffer._buff + buffer._leng;
    unch *_data = data;

    Entry *tail = note;
    unch *stri = NULL;
    Entry *entry = NULL;
    Attri *attri = NULL;
    for (; data[0] != '\0';) {
        // deal with indent
        for (_data = data; data[0] == ' '; data += 1);
        white = data - _data;

        if (data[0] == '\n') {
            data += 1;
        }
        else if (_Delim[data[0]] == PHD) {
            // leave out blank line
            for (; data[0] == ' ' || data[0] == '\t' || data[0] == '\v' || data[0] == '\f' || data[0] == '\r'; data += 1);
            if (data[0] == '#') {
                if (data[1] != '#') {
                    Check(true, ELevel._Error, __FUNCTION__, "double # to comment", NULL);
                    return (data - buffer._buff);
                }
                for (data += 2; data[0] != '\n'; data += 1);
            }
            else if (data[0] != '\n') {
                Check(true, ELevel._Error, __FUNCTION__, "data[0] != ' ' && data[0] != '\t' && data[0] != '\v' && data[0] != '\f' && data[0] != '\r'", NULL);
                return (data - buffer._buff);
            }
            data += 1;
        }
        else {
            // deal with Entry
            // Delimiter is excluded in Entry name 
            for (_data = data; data[0] != ':' && _Delim[data[0]] != PHD; data += 1);
            if (data[0] != ':' && Check(true, ELevel._Error, __FUNCTION__, "data[0] != ':'", NULL)) {
                return (data - buffer._buff);
            }
            stri = Make_Data(_data, data - _data, true);
            entry = Make_Entry(stri, XHash(stri, 0));
            data += 1;
            if (white > space) {
                if (space >= 0) {
                    _entry[_top] = tail;
                    _white[_top] = white;
                    _top += 1;
                }
                else if (white != 0 && Check(true, ELevel._Error, __FUNCTION__, "white != 0", NULL)) {
                    Free_Entry(entry);
                    return (_data - buffer._buff);
                }
                space = white;
                tail->_nest = entry;
                tail = entry;
            }
            else {
                while (white < space && 1 <= _top) {
                    _top -= 1;
                    tail = _entry[_top];
                    space = _white[_top];
                }
                if (white != space && Check(true, ELevel._Error, __FUNCTION__, "white != space", NULL)) {
                    Free_Entry(entry);
                    return (_data - buffer._buff);
                }
                tail->_link = entry;
                tail = entry;
            }

            // deal with leading spaces
            for (; data[0] == ' ' || data[0] == '\t'; data += 1);

            for (; data[0] != '\n';) {
                // deal with Attri
                // Delimiter is excluded in Attri name
                for (_data = data; data[0] != '=' && _Delim[data[0]] != PHD; data += 1);
                if (data[0] != '=' && Check(true, ELevel._Error, __FUNCTION__, "data[0] != '='", NULL)) {
                    return (data - buffer._buff);
                }
                stri = Make_Data(_data, data - _data, true);
                attri = Make_Attri(stri);
                data += 1;

                for (; data[0] == ' ' || data[0] == '\t'; data += 1);
                if (data[0] == '?') {
                    // Logic  ≡ None | Posi | Nega
                    bool *logi = (bool *)_buffer;
                    while (data[0] != ';') {
                        if (data[0] == '?' && data[1] == 'P' && data[2] == 'o' && data[3] == 's' && data[4] == 'i') {
                            if (logi != NULL) {
                                logi[0] = true;
                                logi += 1;
                            }
                            data += 5;
                        }
                        else if (data[0] == '?' && data[1] == 'N' && data[2] == 'e' && data[3] == 'g' && data[4] == 'a') {
                            if (logi != NULL) {
                                logi[0] = false;
                                logi += 1;
                            }
                            data += 5;
                        }
                        else if (data[0] == '?' && data[1] == 'N' && data[2] == 'o' && data[3] == 'n' && data[4] == 'e') {
                            logi = NULL;
                            data += 5;
                        }
                        else {
                            Check(true, ELevel._Error, __FUNCTION__, "parse error in Logic; ", "Logic  ≡ None | Posi | Nega");
                            Free_Attri(attri);
                            return (data - buffer._buff);
                        }
                        for (; data[0] == '|' || data[0] == ' ' || data[0] == '\t'; data += 1);
                    }
                    attri->_type = EType._Logic;
                    if (logi == NULL) {
                        attri->_leng = -1;
                        attri->_value = NULL;
                    }
                    else {
                        attri->_leng = (unch *)logi - (unch *)_buffer;
                        attri->_value = Make_Data(_buffer, attri->_leng, false);
                    }
                }
                else if (data[0] == '-' || data[0] == '+') {
                    // Number ≡ Fixed | Float
                    fl64 *number = (fl64 *)_buffer;
                    while (data[0] != ';') {
                        _data = data;
                        data = Parse_Number(data, &number[0], 10, false);
                        number += 1;
                        if (data == _data && Check(true, ELevel._Error, __FUNCTION__, "parse error in Number; ", "Number ≡ Fixed | Float")) {
                            Free_Attri(attri);
                            return (_data - buffer._buff);
                        }
                        for (; data[0] == '|' || data[0] == ' ' || data[0] == '\t'; data += 1);
                    }
                    attri->_type = EType._Number;
                    attri->_leng = (unch *)number - (unch *)_buffer;
                    attri->_value = Make_Data(_buffer, attri->_leng, false);
                }
                else if (data[0] == '`') {
                    // String ≡ ASCII | Unicode
                    data += 1;
                    for (_data = data; data < over; ) {
                        if (data[0] == '`') {
                            if (data[1] == '`') {
                                data += 2;
                                continue;
                            }
                            break;
                        }
                        data += 1;
                    }
                    if (data >= over || data[0] != '`') {
                        Check(true, ELevel._Error, __FUNCTION__, "parse error in String; ", "data[0] != '`'");
                        Free_Attri(attri);
                        return (data - buffer._buff);
                    }
                    attri->_value = (unch *)Malloc((data - _data + 1) * sizeof(unch));
                    data += 1;
                    unch *value = attri->_value;
                    while (true) {
                        if (_data[0] == '`') {
                            if (_data[1] == '`') {
                                value[0] = '`';
                                value += 1, _data += 2;
                                continue;
                            }
                            break;
                        }
                        value[0] = _data[0];
                        value += 1, _data += 1;
                    }
                    value[0] = '\0';
                    attri->_type = EType._String;
                    attri->_leng = (unch *)value - (unch *)attri->_value;
                }
                else if (data[0] == '^') {
                    // Binary ≡ ^Length^Anything
                    data += 1;
                    fl64 *leng = (fl64 *)_buffer;
                    _data = data;
                    data = Parse_Number(data, leng, 10, true);
                    if (data == _data || data[0] != '^' || (*leng) <= 0.0 || (data + 1 + (iptr)(*leng)) >= over) {
                        Check(true, ELevel._Error, __FUNCTION__, "parse error in Binary; ", "incorrect data length");
                        Free_Attri(attri);
                        return (_data - buffer._buff);
                    }
                    data += 1;
                    attri->_type = EType._Binary;
                    attri->_leng = (iptr)(*leng);
                    attri->_value = Make_Data(data, attri->_leng, false);
                    data += attri->_leng;
                }
                else if (data[0] == '@') {
                    // Stamp ≡ Time  | Site
                    data += 1;
                    for (_data = data; data[0] != ';' && data < over; data += 1);
                    if (data[0] != ';' && Check(true, ELevel._Error, __FUNCTION__, "parse error in TimeStamp; ", "")) {
                        Free_Attri(attri);
                        return (_data - buffer._buff);
                    }
                    iptr leng = data - _data;
                    for (; _data[leng - 1] == ' ' || _data[leng - 1] == '\t'; leng -= 1);

                    attri->_type = EType._TimeStamp;
                    attri->_leng = leng;
                    attri->_value = Make_Data(_data, attri->_leng, false);
                }
                else {
                    Check(true, ELevel._Error, __FUNCTION__, "UnKnown Type", NULL);
                    Free_Attri(attri);
                    return (data - buffer._buff);
                }

                // deal with ending spaces
                for (; data[0] == ' ' || data[0] == '\t'; data += 1);
                if (data[0] != ';' &&Check(true, ELevel._Error, __FUNCTION__, "data[0] != ';'", NULL)) {
                    Free_Attri(attri);
                    return (data - buffer._buff);
                }
                for (data += 1; data[0] == ';' || data[0] == ' ' || data[0] == '\t'; data += 1);

                if (entry->_list == NULL) {
                    attri->_link = attri;
                }
                else {
                    attri->_link = *(entry->_list);
                    *(entry->_list) = attri;
                }
                entry->_list = &(attri->_link);

                // deal with Comment
                if (data[0] == '#') {
                    if (data[1] != '#') {
                        Check(true, ELevel._Error, __FUNCTION__, "double # to comment", NULL);
                        return (data - buffer._buff);
                    }
                    for (data += 2; data[0] != '\n' && data < over; data += 1);
                }
            }  // the ending '\n' of Entry
            data += 1;
        }
    }  // the ending '\0' of Notation
    if (data[0] != '\0' && data != over) {
        Check(true, ELevel._Error, __FUNCTION__, "data[0] != '\0' && data != over", NULL);
        return (data - buffer._buff);
    }
    return 0;
}

iptr Dump_File(unch *file, Buffer buffer) {
    FILE *dump = fopen(file, "wb+");
    if (dump == NULL && Check(true, ELevel._Error, __FUNCTION__, "dump == NULL", NULL)) {
        return 0;
    }

    rewind(dump);
    iptr numb = Fwrite(buffer._buff, sizeof(unch), buffer._leng, dump);
    if (numb != buffer._leng && Check(true, ELevel._Error, __FUNCTION__, "numb != buffer._leng", NULL)) {
        return 0;
    }
    if (fclose(dump) != 0) {
        Check(true, ELevel._Error, __FUNCTION__, "fclose(dump) != 0", NULL);
    }
    return buffer._leng;
}

unch *Load_File(unch *file, Buffer *buffer) {
    FILE *load = fopen(file, "rb+");
    if (load == NULL && Check(true, ELevel._Error, __FUNCTION__, "load == NULL", NULL)) {
        buffer->_leng = 0;
        return NULL;
    }

    Fseek(load, 0, SEEK_END);
    iptr leng = Ftell(load);
    if (buffer->_size <= leng) {
        buffer->_size = leng + 2;
        buffer->_buff = (unch *)Realloc(buffer->_buff, buffer->_size * sizeof(unch));
    }

    rewind(load);
    iptr numb = Fread(buffer->_buff, sizeof(unch), leng, load);
    if (numb != leng && Check(true, ELevel._Error, __FUNCTION__, "numb != leng", NULL)) {
        buffer->_leng = 0;
        fclose(load);
        return NULL;
    }

    if (fclose(load) != 0) {
        Check(true, ELevel._Error, __FUNCTION__, "fclose(load) != 0", NULL);
    }
    buffer->_buff[leng] = '\n';      // no matter if file has an ending '\n'.
    buffer->_buff[leng + 1] = '\0';  // no matter if file has an ending '\0'.
    buffer->_leng = leng + 1;
    return buffer->_buff;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Notation() {
    typedef struct _Person {
        unch *_name;        // BSS9395
        ui64 _id;           // 19930905193000
        fl64 _credit[3];    // 0.02, 0.50, 0.98
        struct _Info {
            unch *_email;   // brilliantstarrysky9395@gmail.com
            unch *_birth;   // 1993-09-05T19:30:00.000+0800    // YYYY-MM-DDThh:mm:ss.ttt+ZZzz
            bool _valid;    // true
        } _info;
        unch *_desc;        // An idiot, then a genius.
    } Person;

    Person person = {
        ._name = "BSS9395",
        ._id = 19930905193000,
        ._credit = { 0.02, 0.50, 0.98 },
        ._info = {
            ._email = "brilliantstarrysky9395@gmail.com",
            ._birth = "1993-09-05T19:30:00.000+0800",
            ._valid = true,
        },
        ._desc = "An idiot, then a genius."
    };

    Entry *note = Make_Entry(NULL, 0);
    Entry *head = NULL;

    head = Handle_Entry(note, "person", true);
    Attach_String(head, "name", person._name, 0);
    Attach_Number(head, "id", (fl64)person._id, false);
    for (iptr i = 0; i < 3; Attach_Number(head, "credit", person._credit[i], i != 2), i += 1);
    Attach_Binary(head, "desc", person._desc, Length(person._desc));

    head = Handle_Entry(note->_nest, "info", true);
    Attach_String(head, "email", person._info._email, 0);
    Attach_EType(head, "birth", person._info._birth, Length(person._info._birth), EType._TimeStamp);
    Attach_Logic(head, "valid", person._info._valid, false);

    ////////////////////////////////////////////////////////////////////////////

    Buffer buffer = Make_Buffer(4096);
    Backpack(&buffer, note);
    Dump_File("person.note", buffer);

    Buffer buff = Make_Buffer(4096);
    Entry *notation = Make_Entry(NULL, 0);
    Load_File("person.note", &buff);
    Assemble(notation, buff);

    Backpack(&buff, notation);
    fprintf(stdout, "%s\n", buff._buff);
}

in08 main(in08 argc, unch *argv[]) {
    Test_Notation();

    return 0;
}
