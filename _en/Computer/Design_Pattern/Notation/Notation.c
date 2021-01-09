/* Notation.c
Author: BSS9395
Update: 2020-01-10T06:47:00+08@China-Guangdong-Zhanjiang+08
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

typedef intptr_t  iptr;
typedef int8_t    in08;  typedef int16_t   in16;  typedef int32_t   in32;  typedef int64_t   in64;
typedef uint8_t   ui08;  typedef uint16_t  ui16;  typedef uint32_t  ui32;  typedef uint64_t  ui64;
typedef float     fl32;  typedef double    fl64;

typedef const char *Type;
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

typedef const char *Level;
struct _ELevel {
    Level _ToDo;
    Level _Info;
    Level _Warn;
    Level _Error;
    Level _Fatal;
} ELevel = {
    ._ToDo = "ToDo",._Info = "Info",._Warn = "Warn",._Error = "Error",._Fatal = "Fatal"
};

typedef struct _Attri {
    char *_attri;
    Type _type;
    iptr _leng;
    char *_value;
    struct _Attri *_link;
} Attri;

typedef struct _Entry {
    char *_entry;
    ui32 _xhash;
    struct _Attri **_list;  // the head of circular list
    struct _Entry *_nest;
    struct _Entry *_link;
} Entry;

static char _Alpha[62] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
    'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'
};

static in08 _Digit[128] = {
#define PHD '?'
   '\0', PHD, PHD, PHD, PHD, PHD, PHD,'\a','\b','\t','\n','\v','\f','\r', PHD, PHD,
    PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
    ' ', '!', '"', '#', '$', '%', '&','\'', '(', ')', '*', '+', ',', '-', '.', '/',
      0,   1,   2,   3,   4,   5,   6,   7,   8,   9, ':', ';', '<', '=', '>', '?',
    '@',  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,
     25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35, '[','\\', ']', '^', '_',
    '`',  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,
     52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62, '{', '|', '}', '~', PHD
};

static char *_Prefix = {
    "#"     // Comment ≡ Line_Indentation_Annotation   // # This is a comment at the first level.
    ":"     // Entry   ≡ unary Entry with multi Attri  // person: name=`BSS9395`; ID=+19930905193000;
    "?"     // Logic   ≡ None  | Posi  | Nega          // ?None    ?Posi    ?Nega
    "-+"    // Number  ≡ Fixed | Float                 // -~D0.02  +~D0.98  -~D1_000_000_000
    "`"     // String  ≡ Printable ASCII               // comment=`This's a string.`          // ``, Self-Escaped if doubles
    "^"     // Binary  ≡ ^Length^Anything              // ^5_H^HA-HA
    "@"     // Stamp   ≡ Time  | Site                  // @1993-09-05T19:30:00.000000+0800    // @@China~Guangdong~Zhanjian~Street~Building~No+0800
};

static char *_Infix = {
    "="     // Atrri Assignment          // name=`BSS9395`;
    "|"     // Array in Attri            // credit=-0.02_D|+0.98_D;
};

static char *_Suffix = {
    ";"     // Attri Delimiter
    "\n"    // Entry Delimiter
    "\r\n"  // Entry Delimiter
};

/* Pritable ASCII
   !"#$%&'
()*+,-./01
23456789:;
<=>?@ABCDE
FGHIJKLMNO
PQRSTUVWXY
Z[\]^_`abc
defghijklm
nopqrstuvw
xyz{|}~
*/

////////////////////////////////////////////////////////////////////////////////

#define  Malloc  malloc
#define  Realloc realloc
#define  Strcmp  strcmp
#define  Pow     pow

char *Parse_Addi_Subt(char *data, fl64 *number, in32 base);
char *Parse_Mult_Divi(char *data, fl64 *number, in32 base);
char *Parse_Number(char *data, fl64 *number, in32 base);

////////////////////////////////////////////////////////////////////////////////

bool Check(bool failed, Level level, char *function, char *record, char *extra) {
    if (failed) {
        fprintf(stderr, "[%s] %s: %s%s""\n", level, function, record, (extra == NULL) ? "" : extra);
    }
    return failed;
}

iptr Length(char *data) {
    iptr leng = -1;
    if (data != NULL) {
        while (leng += 1, data[leng] != '\0');
    }
    return leng;
}

ui32 XHash(char *data, iptr leng) {
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

char *Zero_Data(iptr size) {
    static char *zero = NULL;
    static int full = 0;
    if (full < size) {
        free(zero);
        zero = (char *)calloc(size, sizeof(char));
        full = size;
    }
    return zero;
}

char *Make_Data(char *data, iptr leng, bool peel) {
    if (data != NULL && 0 <= leng) {
        if (leng == 0) {
            leng = Length(data);
        }
        if (peel == true) {
            // leave out white spaces at the ending.
            for (; 0 < leng && data[leng - 1] == ' ' || data[leng - 1] == '\t'; leng -= 1);
        }

        char *make = Malloc((leng + 1) * sizeof(char));
        for (iptr i = 0; i < leng; i += 1) {
            make[i] = data[i];
        }
        make[leng] = '\0';    // No matter if data has an ending '\0'.
        return make;
    }
    return NULL;
}

char *Join_Data(char *data, iptr leng_data, char *join, iptr leng_join) {
    if (leng_join == 0) {
        leng_join = Length(join);
    }
    data = Realloc(data, leng_data + leng_join + 1);
    char *retu = data;

    data += leng_data;
    for (iptr i = 0; i < leng_join; i += 1) {
        data[i] = join[i];
    }
    data[leng_join] = '\0';   // No matter if join has an ending '\0'.
    return retu;
}

char *Copy_Data(char *buffer, char *data, iptr leng) {
    if (leng == 0) {
        for (; data[leng] != '\0'; leng += 1) {
            buffer[leng] = data[leng];
        }
    }
    else if (leng > 0) {
        for (iptr i = 0; i < leng; i += 1) {
            buffer[i] = data[i];
        }
    }
    buffer[leng] = '\0';        // no matter if data has an ending '\0'.
    return &buffer[leng];
}

char *Print_Number(char *buffer, fl64 number, in32 base, fl64 prec) {
    bool plus = (prec < 0) ? (prec = -prec, true) : false;
    bool wave = (base < 0) ? (base = -base, true) : false;

    if (number < 0) {
        number = -number;
        buffer[0] = '-';
        buffer += 1;
    }
    else if (plus == true) {
        buffer[0] = '+';
        buffer += 1;
    }
    if (wave) {
        if (base == 10) {
            buffer[0] = '~', buffer[1] = 'D';
        }
        else if (base == 2) {
            buffer[0] = '~', buffer[1] = 'B';
        }
        else if (base == 8) {
            buffer[0] = '~', buffer[1] = 'O';
        }
        else if (base == 16) {
            buffer[0] = '~', buffer[1] = 'H';
        }
        buffer += 2;
    }

    in64 integer = (in64)prec;
    prec -= integer, number += prec / base;     // round-off
    number -= (integer < number) ? (integer = (in64)number) : (in64)number;

    char ch = 0;
    char *fore = buffer;
    do {
        ch = (char)(integer % base);
        // buffer[0] = (ch < 10) ? (ch + '0') : (ch + 'A' - 10);
        buffer[0] = _Alpha[ch];
        buffer += 1;
        integer /= base;
    } while (0 < integer);
    for (char *back = buffer - 1; fore < back; fore += 1, back -= 1) {
        fore[0] = fore[0] ^ back[0];
        back[0] = fore[0] ^ back[0];
        fore[0] = fore[0] ^ back[0];
    }

    if (number != 0.0 && prec != 0.0) {
        buffer[0] = '.';
        buffer += 1;

        while (prec *= base, prec <= 1) {
            number *= base;
            ch = (char)number;
            buffer[0] = _Alpha[ch];
            buffer += 1;
            number -= ch;
        }
    }

    buffer[0] = '\0';
    return buffer;
}

char *Print_TimeStamp(char *buffer, in32 YYYY, in32 MM, in32 DD, in32 hh, in32 mm, in32 ss, in32 tttttt, in32 ZZzz) {
    // TimeStamp ≡ YYYY-MM-DDThh:mm:ss.ttttttZZZzz

    char ch = 0;
    buffer += 4;
    for (iptr i = 1; i <= 4; i += 1) {
        ch = (char)(YYYY % 10);
        buffer[-i] = _Alpha[ch];
        YYYY = YYYY / 10;
    }

    buffer[0] = '-';
    buffer += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (char)(MM % 10);
        buffer[-i] = _Alpha[ch];
        MM = MM / 10;
    }

    buffer[0] = '-';
    buffer += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (char)(DD % 10);
        buffer[-i] = _Alpha[ch];
        DD = DD / 10;
    }

    buffer[0] = 'T';
    buffer += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (char)(hh % 10);
        buffer[-i] = _Alpha[ch];
        hh = hh / 10;
    }

    buffer[0] = ':';
    buffer += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (char)(mm % 10);
        buffer[-i] = _Alpha[ch];
        mm = mm / 10;
    }

    buffer[0] = ':';
    buffer += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (char)(ss % 10);
        buffer[-i] = _Alpha[ch];
        ss = ss / 10;
    }

    buffer[0] = '.';
    buffer += 7;
    if (tttttt == 0) {
        buffer[-1] = '0', buffer[-2] = '0', buffer[-3] = '0', buffer[-4] = '0', buffer[-5] = '0', buffer[-6] = '0';
    }
    else {
        for (iptr i = 1; i <= 6; i += 1) {
            ch = (char)(tttttt % 10);
            buffer[-i] = _Alpha[ch];
            tttttt = tttttt / 10;
        }
    }

    buffer[0] = (ZZzz < 0) ? (ZZzz = -ZZzz, '-') : '+';
    buffer += 5;
    for (iptr i = 1; i <= 4; i += 1) {
        ch = (char)(ZZzz % 10);
        buffer[-i] = _Alpha[ch];
        ZZzz = ZZzz / 10;
    }

    buffer[0] = '\0';
    return buffer;
}

char *Parse_Addi_Subt(char *data, fl64 *number, in32 base) {
    data = Parse_Mult_Divi(data, number, base);
    for (char op = data[0]; op == '+' || op == '-'; op = data[0]) {
        data += 1;

        fl64 remain = 0.0;
        data = Parse_Mult_Divi(data, &remain, base);
        if (op == '+') {
            (*number) += remain;
        }
        else if (op == '-') {
            (*number) -= remain;
        }
    }
    return data;
}

char *Parse_Mult_Divi(char *data, fl64 *number, in32 base) {
    data = Parse_Number(data, number, base);
    for (char op = data[0]; op == '*' || op == '/' || op == '%'; op = data[0]) {
        data += 1;

        fl64 remain = 0.0;
        data = Parse_Number(data, &remain, base);
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

/* Operator Precedence: from Low to High                Operator Associativity:
AddiSubt   ≡ <MultDivi>[± MultDivi]                     from Left to Right
MultDivi   ≡ <Number>[⋇ Number]                         from Left to Right
Number     ≡ [+|-][D_]<(AddiSubt)|Digit>[{AddiSubt}]    from Right to Left     Digit{Expression} ≡ Pow(Digit, Expression)
Digit      ≡ [0-9].[0-9]

Expression ≡ Term   |   Term ± Term
Term       ≡ Factor | Factor ⋇ Factor
Factor     ≡ Digit  | ±Digit | (Expression) | ±(Expression) | Digit{Expression} | ±Digit{Expression} | (Expression){Expression} | ±(Expression){Expression}
Digit      ≡ [0-9].[0-9]
*/
char *Parse_Number(char *data, fl64 *number, in32 base) {
    in08 sign = +1;
    fl64 value = 0.0;
    for (; data[0] == ' ' || data[0] == '\t'; data += 1);  // leave out the leading spaces.

    if (data[0] == '+') {
        data += 1;
        sign = +1;
    }
    else if (data[0] == '-') {
        data += 1;
        sign = -1;
    }
    if (data[0] == '~') {
        data += 1;
        if (data[0] == 'D') {
            data += 1;
            base = 10;
        }
        else if (data[0] == 'B') {
            data += 1;
            base = 2;
        }
        else if (data[0] == 'O') {
            data += 1;
            base = 8;
        }
        else if (data[0] == 'H') {
            data += 1;
            base = 16;
        }
    }

    if (data[0] == '(') {
        data += 1;
        data = Parse_Addi_Subt(data, &value, base);
        if (Check(data[0] != ')', ELevel._Error, __FUNCTION__, "data[0] != ')", NULL)) {
            // (*number) = sign * value;
            return data;
        }
        data += 1;
    }
    else {
        char ch = 0;
        while (ch = _Digit[data[0]], 0 < data[0] && 0 <= ch && ch < base) {
            data += 1;
            value = value * base + ch;
        }
        if (data[0] == '.') {
            data += 1;
            fl64 fact = 1.0;
            while (ch = _Digit[data[0]], 0 < data[0] && 0 <= ch && ch < base) {
                data += 1;
                fact /= base;
                value += ch * fact;
            }
        }
    }

    if (data[0] == '{') {
        data += 1;
        fl64 expo = 0.0;
        data = Parse_Addi_Subt(data, &expo, base);
        value = Pow(value, expo);
        if (Check(data[0] != '}', ELevel._Error, __FUNCTION__, "data[0] != '}'", NULL)) {
            // (*number) = sign * value;
            return data;
        }
        data += 1;
    }

    for (; data[0] == ' ' || data[0] == '\t'; data += 1);  // leave out the ending spaces.
    (*number) = sign * value;
    return data;
}

////////////////////////////////////////////////////////////////////////////////

Entry *Make_Entry(char *entry, ui32 xhash) {
    Entry *make = Malloc(sizeof(Entry));
    make->_entry = entry;
    make->_xhash = xhash;
    make->_list = NULL;
    make->_nest = NULL;
    make->_link = NULL;
    return make;
}

Attri *Make_Attri(char *attri) {
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

Entry *Handle_Entry(Entry *super, char *entry, bool sole) {
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

Attri *Handle_Attri(Entry *entry, char *attri, bool sole) {
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

Entry *Detach_Entry_Many(Entry *super, char *entry, bool wipe) {
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
                (*iter) = (*iter)->_link;

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

Attri *Detach_Attri_Many(Entry *entry, char *attri, bool wipe) {
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
                (*iter) = (*iter)->_link;

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

Entry *Attach_Logic(Entry *entry, char *attri, bool logi, bool many) {
    static bool *_value = NULL;
    static iptr _many = 0;
    static iptr _numb = 0;

    static Entry *_entry = NULL;
    static char *_attri = NULL;

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
            Attri *hand = Handle_Attri(entry, attri, false);
            Check(hand->_value != NULL && hand->_attri != EType._Logic, ELevel._Warn, __FUNCTION__, "hand->_value != NULL && hand->_attri != EType._Logic", NULL);

            hand->_type = EType._Logic;
            hand->_value = Join_Data(hand->_value, hand->_leng, (char *)_value, _numb * sizeof(bool));
            hand->_leng += _numb * sizeof(bool);

            _numb = 0;
        }
    }
    return entry;
}

Entry *Attach_Number(Entry *entry, char *attri, fl64 frac, bool many) {
    static fl64 *_value = NULL;
    static iptr _many = 0;
    static iptr _numb = 0;

    static Entry *_entry = NULL;
    static char *_attri = NULL;

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
            Attri *hand = Handle_Attri(entry, attri, false);
            Check(hand->_value != NULL && hand->_attri != EType._Number, ELevel._Warn, __FUNCTION__, "hand->_value != NULL && hand->_attri != EType._Number", NULL);

            hand->_type = EType._Number;
            hand->_value = Join_Data(hand->_value, hand->_leng, (char *)_value, _numb * sizeof(fl64));
            hand->_leng += _numb * sizeof(fl64);

            _numb = 0;
        }
    }
    return entry;
}

Entry *Attach_String(Entry *entry, char *attri, char *stri, iptr leng) {
    Attri *hand = Handle_Attri(entry, attri, false);
    hand->_type = EType._String;
    hand->_leng = (0 < leng) ? leng : Length(stri);
    hand->_value = Make_Data(stri, hand->_leng, false);
    return entry;
}

Entry *Attach_Binary(Entry *entry, char *attri, char *bina, iptr leng) {
    Attri *hand = Handle_Attri(entry, attri, false);
    hand->_type = EType._Binary;
    hand->_leng = leng;
    hand->_value = Make_Data(bina, hand->_leng, false);
    return entry;
}

Entry *Attach_TimeStamp(Entry *entry, char *attri, in32 YYYY, in32 MM, in32 DD, in32 hh, in32 mm, in32 ss, in32 tttttt, in32 ZZzz) {
    static char _buffer[1024];

    char *buffer = Print_TimeStamp(_buffer, YYYY, MM, DD, hh, mm, ss, tttttt, ZZzz);
    Attri *hand = Handle_Attri(entry, attri, false);
    hand->_type = EType._TimeStamp;
    hand->_leng = (char *)buffer - (char *)_buffer;
    hand->_value = Make_Data(_buffer, hand->_leng, true);
    return entry;
}

Entry *Attach_EType(Entry *entry, char *attri, char *value, iptr leng, Type type) {
    Attri *hand = Handle_Attri(entry, attri, false);
    hand->_type = type;
    hand->_leng = leng;
    hand->_value = Make_Data(value, hand->_leng, false);
    return entry;
}

////////////////////////////////////////////////////////////////////////////////

iptr BackPack(char *buffer, Entry *note) {
    static Entry *_entry[128];
    static iptr _top = 0;

    char *retu = buffer;
    iptr space = 2;
    iptr white = 0;
    _top = 0;

    _entry[_top] = note->_nest;
    _top += 1;
    white += space;
    while (_top >= 1) {
        _top -= 1;
        Entry *head = _entry[_top];
        white -= space;

        while (head != NULL) {
            for (iptr i = 0; i < white; buffer[i] = ' ', i += 1);
            buffer += white;

            buffer = Copy_Data(buffer, head->_entry, 0);
            buffer[0] = ':';
            buffer += 1;
            if (head->_list != NULL) {
                Attri *list = *(head->_list);
                Attri *iter = list;
                do {
                    buffer[0] = ' ';
                    buffer += 1;

                    buffer = Copy_Data(buffer, iter->_attri, 0);
                    buffer[0] = '=';
                    buffer += 1;

                    if (iter->_type == EType._Logic) {
                        bool *value = (bool *)iter->_value;
                        iptr numb = iter->_leng / sizeof(bool);
                        for (iptr i = 0; i < numb; i += 1) {
                            if (i >= 1) {
                                buffer[0] = '|';
                                buffer += 1;
                            }
                            buffer[0] = '?', (value[i] == true)
                                ? (buffer[1] = 'P', buffer[2] = 'o', buffer[3] = 's', buffer[4] = 'i')
                                : (buffer[1] = 'N', buffer[2] = 'e', buffer[3] = 'g', buffer[5] = 'a');
                            buffer += 5;
                        }
                    }
                    else if (iter->_type == EType._Number || iter->_type == EType._Fixed || iter->_type == EType._Float) {
                        fl64 *value = (fl64 *)iter->_value;
                        iptr numb = iter->_leng / sizeof(fl64);
                        for (iptr i = 0; i < numb; i += 1) {
                            if (i >= 1) {
                                buffer[0] = '|';
                                buffer += 1;
                            }
                            buffer = Print_Number(buffer, value[i], 10, -0.000001);
                        }
                    }
                    else if (iter->_type == EType._String) {
                        buffer[0] = '`';
                        buffer += 1;
                        buffer = Copy_Data(buffer, iter->_value, iter->_leng);
                        buffer[0] = '`';
                        buffer += 1;
                    }
                    else if (iter->_type == EType._Binary) {
                        buffer[0] = '^';
                        buffer += 1;
                        buffer = Print_Number(buffer, iter->_leng, -16, 0.0);
                        buffer[0] = '^';
                        buffer += 1;
                        buffer = Copy_Data(buffer, iter->_value, iter->_leng);
                    }
                    else if (iter->_type == EType._TimeStamp) {
                        buffer[0] = '@';
                        buffer += 1;
                        buffer = Copy_Data(buffer, iter->_value, iter->_leng);
                    }
                    else if (iter->_type == EType._UnKnown) {

                    }
                    else {
                        Check(true, ELevel._ToDo, __FUNCTION__, "", "iter->_type is to be handled.");
                    }

                    buffer[0] = ';';
                    buffer += 1;
                } while (iter = iter->_link, iter != list);
                buffer[0] = '\n';
                buffer += 1;
            }

            _entry[_top] = head->_link;
            _top += 1;
            white += space;
            head = head->_nest;
        }
    }
    buffer[0] = '\0';
    return (buffer - retu);
}

iptr Dump_File(char *file, char *buffer, iptr leng) {
    FILE *dump = fopen(file, "wb+");
    if (Check(dump == NULL, ELevel._Error, __FUNCTION__, "dump == NULL", NULL)) {
        return 0;
    }

    leng += 1;   // the ending '\0' is also included.
    iptr count = fwrite(buffer, sizeof(char), leng, dump);
    Check(count != leng, ELevel._Error, __FUNCTION__, "count != leng", NULL);
    Check(fclose(dump) != 0, ELevel._Error, __FUNCTION__, "fclose(file) != 0", NULL);
    return count;
}

////////////////////////////////////////////////////////////////////////////////

Entry *Aesemble(char *data) {
    static char _buffer[1024];
    static Entry **_entry[512];
    static iptr _white[512];
    static iptr _top = 0;
    iptr space = 0;
    iptr white = 0;

    Entry *note = Make_Entry(NULL, 0);
    Entry **tail = &(note->_nest);
    char *stri = NULL;
    Entry *entry = NULL;
    Attri *attri = NULL;

    for (char *_data = NULL; data[0] != '\0';) {
        // deal with Entry
        _data = data; for (; data[0] == ' '; data += 1);
        white = data - _data;

        _data = data; for (; data[0] != ':'; data += 1);
        stri = Make_Data(_data, (char *)data - (char *)_data, true);
        data += 1;

        entry = Make_Entry(stri, XHash(stri, 0));
        if (white > space) {
            _entry[_top] = tail;
            _white[_top] = white;
            _top += 1;

            space = white;
            tail = &((*tail)->_nest);
            (*tail) = entry;
        }
        else {
            while (white < space && 0 < _top) {
                _top -= 1;
                tail = _entry[_top];
                space = _white[_top];
            }
            if (Check(white != space, ELevel._Error, __FUNCTION__, "white < space && _top <= 0", NULL)) {
                break;
            }
            if ((*tail) != NULL) {
                tail = &((*tail)->_link);
            }
            (*tail) = entry;
        }

        for (; data[0] != '\n';) {
            // deal with Attri
            for (; data[0] == ' ' || data[0] == '\t'; data += 1);
            _data = data; for (; data[0] != '='; data += 1);
            stri = Make_Data(_data, (char *)data - (char *)_data, true);
            data += 1;

            attri = Make_Attri(stri);
            if (entry->_list == NULL) {
                attri->_link = attri;
                entry->_list = &(attri->_link);
            }
            else {
                attri->_link = *(entry->_list);
                *(entry->_list) = attri;
                entry->_list = &(attri->_link);
            }

            ////////////////////////////////////////////////////////////////////
            for (; data[0] == ' ' || data[0] == '\t'; data += 1);
            if (data[0] == '?') {
                // Logic   ≡ None  | Posi  | Nega
                bool *logi = (bool *)_buffer;

                while (data[0] != ';' && logi != NULL) {
                    if (data[0] == '?' && data[1] == 'P' && data[2] == 'o' && data[3] == 's' && data[4] == 'i') {
                        logi[0] = true;
                        logi += 1;
                        data += 5;
                    }
                    else if (data[0] == '?' && data[1] == 'N' && data[2] == 'e' && data[3] == 'g' && data[4] == 'a') {
                        logi[0] = false;
                        logi += 1;
                        data += 5;
                    }
                    else if (data[0] == '?' && data[1] == 'N' && data[2] == 'o' && data[3] == 'n' && data[4] == 'e') {
                        logi = NULL;
                    }
                    for (; data[0] == '|' || data[0] == ' ' || data[0] == '\t'; data += 1);
                }
                attri->_type = EType._Logic;
                if (logi == NULL) {
                    attri->_leng = -1;
                    attri->_value = NULL;
                }
                else {
                    attri->_leng = (char *)logi - (char *)_buffer;
                    attri->_value = Make_Data(_buffer, attri->_leng, false);
                }
            }
            else if (data[0] == '-' || data[0] == '+') {
                // Number  ≡ Fixed | Float
                fl64 *number = (fl64 *)_buffer;
                while (data[0] != ';') {
                    data = Parse_Number(data, &number[0], 10);
                    number += 1;
                    while (data[0] == '|' || data[0] == ' ' || data[0] == '\t') {
                        data += 1;
                    }
                }
                attri->_type = EType._Number;
                attri->_leng = (char *)number - (char *)_buffer;
                attri->_value = Make_Data(_buffer, attri->_leng, false);
            }
            else if (data[0] == '`') {
                // String  ≡ Printable ASCII
                data += 1;
                _data = data; for (; data[0] != '`'; data += 1);
                attri->_type = EType._String;
                attri->_leng = (char *)data - (char *)_data;
                attri->_value = Make_Data(_data, attri->_leng, false);
                data += 1;
                for (; data[0] != ';' && (data[0] == ' ' || data[0] == 't'); data += 1);
            }
            else if (data[0] == '^') {
                // Binary  ≡ ^Length^Anything
                data += 1;
                fl64 leng = 0.0;
                data = Parse_Number(data, &leng, 10);
                Check(data[0] != '^', ELevel._Error, __FUNCTION__, "data[0] != '^'", NULL);
                data += 1;
                attri->_type = EType._Binary;
                attri->_leng = (iptr)leng;
                attri->_value = Make_Data(data, attri->_leng, false);
                data += (iptr)leng;
                for (; data[0] != ';' && (data[0] == ' ' || data[0] == '\t'); data += 1);
            }
            else if (data[0] == '@') {
                // Stamp   ≡ Time  | Site
                data += 1;
                _data = data; for (; data[0] != ';'; data += 1);
                attri->_leng = (char *)data - (char *)_data;
                attri->_type = EType._TimeStamp;
                attri->_value = Make_Data(_data, attri->_leng, true);
            }
            else {
                Check(true, ELevel._Error, __FUNCTION__, "", "UnKnown Type");
            }

            if (Check(data[0] != ';', ELevel._Error, __FUNCTION__, "data[0] != ';'", NULL)) {
                break;
            }
            data += 1;  // the ending '\;' of Attri.
        }
        data += 1;      // the ending '\n' of Entry.
    }
    // the ending '\0' of Notation.

    return note;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Notation() {
    typedef struct _Person {
        char *_name;        // BSS9395
        ui64 _id;           // 19930905193000
        fl64 _credit[3];    // 0.02, 0.50, 0.98
        struct _Info {
            char *_email;   // brilliantstarrysky9395@gmail.com
            char *_birth;   // 1993-09-05T19:30:00.000+0800    // YYYY-MM-DDThh:mm:ss.ttt+ZZzz
            bool _valid;    // true
        } _info;
        char *_desc;        // An idiot, then a genius.
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


    //Remove_Entry(&note, head, true);
    //Remove_Entry_Many(&note, "people", true);
    //Attri *attri = Handle_Attri(many, "desc", true);
    //Remove_Attri(many, attri, true);
    //Remove_Attri_Many(many, "desc", true);

    ////////////////////////////////////////////////////////////////////////////

    char buffer[1024];
    iptr leng = BackPack(buffer, note);
    fprintf(stdout, "%s""\n", buffer);
    // Dump_File("person.note", buffer, leng);

    Entry *notation = Aesemble(buffer);
    leng = BackPack(buffer, notation);
    fprintf(stdout, "%s\n", buffer);
}

int main(int argc, char *argv[]) {
    Test_Notation();

    return 0;
}
