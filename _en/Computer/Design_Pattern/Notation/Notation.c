/* Notation.c
Author: BSS9395
Update: 2020-01-11T12:33:00+08@China-Guangdong-Zhanjiang+08
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

typedef struct _Buffer {
    char *_buff;
    iptr _leng;
    iptr _size;
} Buffer;

typedef struct _Attri {
    char *_attri;
    char *_value;
    iptr _leng;
    Type _type;
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

/* Simple Syntax Tree of Notation
Notation ≡ [Line]<\0>
Line     ≡ [Blank|Entry]<\n>
Blank    ≡ [white]
Entry    ≡ <indent><entry:>[Attri]
Attri    ≡ [white]<attri=value;>[white]
*/

static char *_Prefix = {
    "#"     // Comment ≡ ##Line_Indentation_Comment    // ## This is a comment at the first level.
    ":"     // Entry   ≡ unary Entry with multi Attri  // person: name=`BSS9395`; ID=+19930905193000;
    "?"     // Logic   ≡ None  | Posi  | Nega          // ?None    ?Posi    ?Nega
    "-+"    // Number  ≡ Fixed | Float                 // -#D0.02  +#D0.98  -#D1_000_000_000
    "`"     // String  ≡ Printable ASCII               // comment=`This's a string.`          // ``, Self-Escaped if doubles
    "^"     // Binary  ≡ ^Length^Anything              // ^#H5^HA-HA
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

#define  Fseek   fseek
#define  Ftell   ftell
#define  Fread   fread
#define  Fwrite  fwrite
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

//char *Be(const char *stri) {
//    // special design for literal C string.
//    iptr leng = Leng(stri);
//    char *make = (char *)Malloc((leng + 1) * sizeof(char));
//    for (iptr i = 0; i < leng; i += 1) {
//        make[i] = stri[i];
//    }
//    make[leng] = '\0';
//    return make;
//}

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
            for (; 0 < leng && data[leng - 1] == ' ' || ('\t' <= data[leng - 1] && data[leng - 1] <= '\r'); leng -= 1);
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

char *Copy_Data(char *buff, char *data, iptr leng) {
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

char *Print_Number(char *buff, fl64 number, in32 base, fl64 prec) {
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

    char ch = 0;
    char *fore = buff;
    do {
        ch = (char)(integer % base);
        // buffer[0] = (ch < 10) ? (ch + '0') : (ch + 'A' - 10);
        buff[0] = _Alpha[ch];
        buff += 1;
        integer /= base;
    } while (0 < integer);
    for (char *back = buff - 1; fore < back; fore += 1, back -= 1) {
        fore[0] = fore[0] ^ back[0];
        back[0] = fore[0] ^ back[0];
        fore[0] = fore[0] ^ back[0];
    }

    if (number != 0.0 && prec != 0.0) {
        buff[0] = '.';
        buff += 1;

        while (prec *= base, prec <= 1) {
            number *= base;
            ch = (char)number;
            buff[0] = _Alpha[ch];
            buff += 1;
            number -= ch;
        }
    }

    buff[0] = '\0';
    return buff;
}

char *Print_TimeStamp(char *buff, in32 YYYY, in32 MM, in32 DD, in32 hh, in32 mm, in32 ss, in32 tttttt, in32 ZZzz) {
    // TimeStamp ≡ YYYY-MM-DDThh:mm:ss.ttttttZZZzz

    char ch = 0;
    buff += 4;
    for (iptr i = 1; i <= 4; i += 1) {
        ch = (char)(YYYY % 10);
        buff[-i] = _Alpha[ch];
        YYYY = YYYY / 10;
    }

    buff[0] = '-';
    buff += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (char)(MM % 10);
        buff[-i] = _Alpha[ch];
        MM = MM / 10;
    }

    buff[0] = '-';
    buff += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (char)(DD % 10);
        buff[-i] = _Alpha[ch];
        DD = DD / 10;
    }

    buff[0] = 'T';
    buff += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (char)(hh % 10);
        buff[-i] = _Alpha[ch];
        hh = hh / 10;
    }

    buff[0] = ':';
    buff += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (char)(mm % 10);
        buff[-i] = _Alpha[ch];
        mm = mm / 10;
    }

    buff[0] = ':';
    buff += 3;
    for (iptr i = 1; i <= 2; i += 1) {
        ch = (char)(ss % 10);
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
            ch = (char)(tttttt % 10);
            buff[-i] = _Alpha[ch];
            tttttt = tttttt / 10;
        }
    }

    buff[0] = (ZZzz < 0) ? (ZZzz = -ZZzz, '-') : '+';
    buff += 5;
    for (iptr i = 1; i <= 4; i += 1) {
        ch = (char)(ZZzz % 10);
        buff[-i] = _Alpha[ch];
        ZZzz = ZZzz / 10;
    }

    buff[0] = '\0';
    return buff;
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

    for (; data[0] == ' '; data += 1);  // leave out the ending spaces.
    (*number) = sign * value;
    return data;
}

////////////////////////////////////////////////////////////////////////////////

Buffer *Make_Buffer(iptr size, bool heap) {
    static Buffer _buffer = {
        ._buff = NULL,
        ._leng = 0,
        ._size = 0
    };
    Buffer *make = &_buffer;
    if (heap == true) {
        make = (Buffer *)Malloc(sizeof(Buffer));
    }
    make->_buff = (char *)Malloc(size * sizeof(char));
    make->_size = size;
    return make;
}

iptr Free_Buffer(Buffer *buffer) {
    iptr retu = 0;
    if (buffer != NULL) {
        free(buffer->_buff);
        free(buffer);
        retu += 2;
    }
    return retu;
}

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

Entry *Attach_EType(Entry *entry, char *attri, char *value, iptr leng, Type type) {
    Attri *hand = Handle_Attri(entry, attri, false);
    Check(!(hand->_type == EType._UnKnown || hand->_type == type), type, __FUNCTION__, "!(hand->_type == EType._UnKnown || hand->_type == type)", NULL);
    hand->_value = Join_Data(hand->_value, hand->_leng, value, leng);
    hand->_leng += leng;
    hand->_type = type;
    return entry;
}

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
            Attach_EType(entry, attri, (char *)_value, _numb * sizeof(bool), EType._Logic);
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
            Attach_EType(entry, attri, (char *)_value, _numb * sizeof(fl64), EType._Number);
            _numb = 0;
        }
    }
    return entry;
}

Entry *Attach_String(Entry *entry, char *attri, char *stri, iptr leng) {
    leng = (0 < leng) ? leng : Length(stri);
    Attach_EType(entry, attri, stri, leng, EType._String);
    return entry;
}

Entry *Attach_Binary(Entry *entry, char *attri, char *bina, iptr leng) {
    Attach_EType(entry, attri, bina, leng, EType._Binary);
    return entry;
}

Entry *Attach_TimeStamp(Entry *entry, char *attri, in32 YYYY, in32 MM, in32 DD, in32 hh, in32 mm, in32 ss, in32 tttttt, in32 ZZzz) {
    static char _buffer[4096];
    char *buffer = Print_TimeStamp(_buffer, YYYY, MM, DD, hh, mm, ss, tttttt, ZZzz);
    Attach_EType(entry, attri, _buffer, buffer - _buffer, EType._TimeStamp);
    return entry;
}

////////////////////////////////////////////////////////////////////////////////

char *Obtain_EType(Entry *entry, char *attri, iptr *leng, Type type) {
    if (entry->_list != NULL) {
        Attri *list = *(entry->_list);
        Attri *iter = list;
        do {
            if (Strcmp(iter->_attri, attri) == 0) {
                Check(iter->_type != type, ELevel._Warn, __FUNCTION__, "iter ->_type != type", NULL);
                (*leng) = iter->_leng;
                entry->_list = &(iter->_link);
                return (char *)(iter->_value);
            }
            iter = iter->_link;
        } while (iter != list);
    }
    return NULL;
}

bool *Obtain_Logic(Entry *entry, char *attri, iptr *leng) {
    return (bool *)Obtain_EType(entry, attri, leng, EType._Logic);
}

fl64 *Obtain_Number(Entry *entry, char *attri, iptr *leng) {
    return (fl64 *)Obtain_EType(entry, attri, leng, EType._Number);
}

char *Obtain_String(Entry *entry, char *attri, iptr *leng) {
    return (char *)Obtain_EType(entry, attri, leng, EType._String);
}

char *Obtain_Binary(Entry *entry, char *attri, iptr *leng) {
    return (char *)Obtain_EType(entry, attri, leng, EType._Binary);
}

char *Obtain_TimeStamp(Entry *entry, char *attri, iptr *leng) {
    return (char *)Obtain_EType(entry, attri, leng, EType._TimeStamp);
}

////////////////////////////////////////////////////////////////////////////////

char *Backpack(Buffer *buffer, Entry *note) {
    static Entry *_entry[256];
    iptr _top = 0;
    iptr space = 2;
    iptr white = 0;
    char *buff = buffer->_buff;

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

                    }
                    else {
                        Check(true, ELevel._ToDo, __FUNCTION__, "", "iter->_type is to be handled.");
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

iptr Assemble(Entry *note, Buffer buffer) {
    static char _buffer[4096];
    static Entry *_entry[256];
    static iptr _white[256];
    iptr _top = 0;
    iptr space = -2;
    iptr white = 0;
    char *data = buffer._buff;

    Entry *tail = note;
    char *stri = NULL;
    Entry *entry = NULL;
    Attri *attri = NULL;
    for (iptr numb = 0; data[0] != '\0';) {
        // leave out blank line.
        while (true) {
            for (white = 0; data[white] == ' ' || data[white] == '\t'; white += 1);
            if (data[white] == '\n') {
                data += white + 1;
                continue;
            }
            break;
        }
        if (data[0] == '\0') {
            break;
        }

        // deal with Entry
        // indent
        for (white = 0; data[white] == ' '; white += 1);
        data += white;

        for (numb = 0; data[numb] != ':'; numb += 1);
        stri = Make_Data(data, numb, true);
        data += numb + 1;

        entry = Make_Entry(stri, XHash(stri, 0));
        if (white > space) {
            space = white;
            tail->_nest = entry;
            tail = entry;

            _entry[_top] = tail;
            _white[_top] = white;
            _top += 1;
        }
        else {
            while (white < space && 0 < _top) {
                _top -= 1;
                tail = _entry[_top];
                space = _white[_top];
            }
            if (Check(white != space, ELevel._Error, __FUNCTION__, "white != space", NULL)) {
                break;
            }
            tail->_link = entry;
            tail = entry;
        }

        for (; data[0] != '\n';) {
            for (; data[0] == ' ' || data[0] == '\t'; data += 1);

            // deal with Attri
            for (numb = 0; data[numb] != '='; numb += 1);
            stri = Make_Data(data, numb, true);
            data += numb + 1;

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
            for (; data[0] == ' '; data += 1);
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
                    for (; data[0] == '|' || data[0] == ' '; data += 1);
                }
                for (; data[0] != ';' && logi == NULL; data += 1);
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
                    for (; data[0] == '|' || data[0] == ' '; data += 1);
                }
                attri->_type = EType._Number;
                attri->_leng = (char *)number - (char *)_buffer;
                attri->_value = Make_Data(_buffer, attri->_leng, false);
            }
            else if (data[0] == '`') {
                // String  ≡ Printable ASCII
                data += 1;
                for (numb = 0; data[numb] != '`'; numb += 1);
                attri->_type = EType._String;
                attri->_leng = numb;
                attri->_value = Make_Data(data, attri->_leng, false);
                data += numb + 1;
                for (; data[0] != ';' && (data[0] == ' ' || data[0] == '\t'); data += 1);
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
                for (; data[0] != ';' && (data[0] == ' '); data += 1);
            }
            else if (data[0] == '@') {
                // Stamp   ≡ Time  | Site
                data += 1;
                for (numb = 0; data[numb] != ';'; numb += 1);
                attri->_leng = numb;
                attri->_type = EType._TimeStamp;
                attri->_value = Make_Data(data, attri->_leng, true);
                data += numb;
            }
            else {
                Check(true, ELevel._Error, __FUNCTION__, "", "UnKnown Type");
            }

            if (Check(data[0] != ';', ELevel._Error, __FUNCTION__, "data[0] != ';'", NULL)) {
                break;
            }
            data += 1;  // the ending ';' of Attri.

            for (; data[0] == ' ' || data[0] <= '\t'; data += 1);
        }

        data += 1;    // the ending '\n' of Entry.
    }
    // the ending '\0' of Notation.

    return (data - buffer._buff);
}

iptr Dump_File(char *file, Buffer buffer) {
    FILE *dump = fopen(file, "wb+");
    if (Check(dump == NULL, ELevel._Error, __FUNCTION__, "dump == NULL", NULL)) {
        return 0;
    }

    rewind(dump);
    iptr numb = Fwrite(buffer._buff, sizeof(char), buffer._leng, dump);
    if (Check(numb != buffer._leng, ELevel._Error, __FUNCTION__, "numb != buffer._leng", NULL)) {
        return 0;
    }
    Check(fclose(dump) != 0, ELevel._Error, __FUNCTION__, "fclose(dump) != 0", NULL);
    return buffer._leng;
}

char *Load_File(char *file, Buffer *buffer) {
    FILE *load = fopen(file, "rb+");
    if (Check(load == NULL, ELevel._Error, __FUNCTION__, "load == NULL", NULL)) {
        buffer->_leng = 0;
        return NULL;
    }

    Fseek(load, 0, SEEK_END);
    iptr leng = Ftell(load);
    if (buffer->_size <= leng) {
        buffer->_size = leng + 2;
        buffer->_buff = (char *)Realloc(buffer->_buff, buffer->_size * sizeof(char));
    }

    rewind(load);
    iptr numb = Fread(buffer->_buff, sizeof(char), leng, load);
    if (Check(numb != leng, ELevel._Error, __FUNCTION__, "numb != leng", NULL)) {
        buffer->_leng = 0;
        fclose(load);
        return NULL;
    }

    Check(fclose(load) != 0, ELevel._Error, __FUNCTION__, "fclose(load) != 0", NULL);
    buffer->_buff[leng] = '\n';      // no matter if file has an ending '\n'.
    buffer->_buff[leng + 1] = '\0';  // no matter if file has an ending '\0'.
    buffer->_leng = leng + 1;
    return buffer->_buff;
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

    //head = Handle_Entry(note, "person", true);
    //Attach_String(head, "name", person._name, 0);
    //Attach_Number(head, "id", (fl64)person._id, false);
    //for (iptr i = 0; i < 3; Attach_Number(head, "credit", person._credit[i], i != 2), i += 1);
    //Attach_Binary(head, "desc", person._desc, Length(person._desc));

    //head = Handle_Entry(note->_nest, "info", true);
    //Attach_String(head, "email", person._info._email, 0);
    //Attach_EType(head, "birth", person._info._birth, Length(person._info._birth), EType._TimeStamp);
    //Attach_Logic(head, "valid", person._info._valid, false);

    ////////////////////////////////////////////////////////////////////////////

    Buffer buffer = *Make_Buffer(4096, false);
    Load_File("person.note", &buffer);
    Entry *notation = Make_Entry(NULL, 0);
    Assemble(notation, buffer);

    Buffer buff = *Make_Buffer(4096, false);
    Backpack(&buff, notation);
    fprintf(stdout, "%s\n", buff._buff);
}

int main(int argc, char *argv[]) {
    Test_Notation();

    return 0;
}
