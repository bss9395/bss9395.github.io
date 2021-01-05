/* Notation.c
Author: BSS9395
Update: 2020-01-05T10:45:00+08@China-Guangdong-Zhanjiang+08
Design: Data Transfer Format
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define  Malloc  malloc
#define  Realloc realloc
#define  Strcmp  strcmp

typedef intptr_t  iptr;
typedef int8_t    in08;  typedef int16_t   in16;  typedef int32_t   in32;  typedef int64_t   in64;
typedef uint8_t   ui08;  typedef uint16_t  ui16;  typedef uint32_t  ui32;  typedef uint64_t  ui64;
typedef float     fl32;  typedef double    fl64;

typedef const char *Type;
struct _EType {
    Type _UnKnown;
    Type _String;
    Type _Binary;
    Type _Fixed;
    Type _Float;
} EType = {
    ._UnKnown = "UnKnown",._String = "String",._Binary = "Binary",._Fixed = "Fixed",._Float = "Float"
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
    char *_value;
    Type _type;
    iptr _leng;
    struct _Attri *_link;
} Attri;

typedef struct _Entry {
    char *_entry;
    ui32 _xhash;
    struct _Attri *_list;
    struct _Entry *_nest;
    struct _Entry *_link;
} Entry;

static char _Digit[62] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
    'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'
};

////////////////////////////////////////////////////////////////////////////////

bool Check(bool failed, Level level, char *function, char *record, char *extra) {
    if (failed) {
        fprintf(stderr, "[%s] %s: %s%s;""\n", level, function, record, (extra == NULL) ? "" : extra);
    }
    return failed;
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

char *Make_Data(char *data, iptr leng) {
    if (data != NULL) {
        if (leng == 0) {
            leng = Length(data);
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
    char *retu = data;
    if (leng_join == 0) {
        leng_join = Length(join);
    }

    data = Realloc(data, leng_data + leng_join + 1);
    data += leng_data;
    for (iptr i = 0; i < leng_join; i += 1) {
        data[i] = join[i];
    }
    data[leng_join] = '\0';   // No matter if join has an ending '\0'.
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

////////////////////////////////////////////////////////////////////////////////

Entry *Handle_Entry(Entry *super, char *entry, bool sole) {
    ui32 xhash = XHash(entry, 0);
    Entry **iter = &(super->_nest);
    while ((*iter) != NULL && (*iter)->_xhash < xhash) {
        iter = &((*iter)->_link);
    }
    if (sole == true && (*iter) != NULL && (*iter)->_xhash == xhash) {
        if (Strcmp((*iter)->_entry, entry) == 0) {
            return (*iter);
        }
    }

    entry = Make_Data(entry, 0);
    Entry *node = Make_Entry(entry, xhash);
    node->_link = (*iter);
    (*iter) = node;
    return node;
}

Attri *Handle_Attri(Entry *entry, char *attri, bool sole) {
    if (sole == true && entry->_list != NULL) {
        Attri *tail = entry->_list;
        Attri *iter = tail;
        do {
            iter = iter->_link;
            if (Strcmp(iter->_attri, attri) == 0) {
                return iter;
            }
        } while (iter != tail);
    }

    attri = Make_Data(attri, 0);
    Attri *node = Make_Attri(attri);
    if (entry->_list == NULL) {
        // circular list
        node->_link = node;
        entry->_list = node;
    }
    else {
        Attri *tail = entry->_list;
        node->_link = tail->_link;
        tail->_link = node;
        entry->_list = node;
    }
    return node;
}

Entry *Attach_String(Entry *entry, char *attri, char *stri, iptr leng) {
    Attri *hand = Handle_Attri(entry, attri, false);
    hand->_value = Make_Data(stri, leng);
    hand->_type = EType._String;
    hand->_leng = (0 < leng) ? leng : Length(stri);
    return entry;
}

Entry *Attach_Binary(Entry *entry, char *attri, char *bina, iptr leng) {
    Attri *hand = Handle_Attri(entry, attri, false);
    hand->_value = Make_Data(bina, leng);
    hand->_type = EType._Binary;
    hand->_leng = leng;
    return entry;
}

char *Print_Fixed(char *buffer, in64 number, in08 base) {
    bool suffix = (base < 0) ? (base = -base, true) : false;
    if (number < 0) {
        number = -number;
        buffer[0] = '-';
        buffer += 1;
    }
    else if (suffix == true) {
        buffer[0] = '+';
        buffer += 1;
    }
    char *fore = buffer;

    char ch = 0;
    do {
        ch = (char)(number % base);
        // buffer[0] = (ch < 10) ? (ch + '0') : (ch + 'A' - 10);
        buffer[0] = _Digit[ch];
        buffer += 1;
        number = number / base;
    } while (0 < number);

    for (char *back = buffer - 1; fore < back; fore += 1, back -= 1) {
        fore[0] = fore[0] ^ back[0];
        back[0] = fore[0] ^ back[0];
        fore[0] = fore[0] ^ back[0];
    }

    if (suffix) {
        if (base == 10) {
            buffer[0] = '_', buffer[1] = 'D';
        }
        else if (base == 2) {
            buffer[0] = '_', buffer[1] = 'B';
        }
        else if (base == 8) {
            buffer[0] = '_', buffer[1] = 'O';
        }
        else if (base == 16) {
            buffer[0] = '_', buffer[1] = 'H';
        }
        buffer += 2;
    }
    buffer[0] = '\0';
    return buffer;
}

char *Print_Float(char *buffer, fl64 number, in08 base, in08 prec) {
    bool suffix = (base < 0) ? (base = -base, true) : false;
    in64 integer = (in64)number;
    number -= integer;

    if (suffix == true && integer >= 0) {
        buffer[0] = '+';
        buffer += 1;
    }
    buffer = Print_Fixed(buffer, integer, base);
    buffer[0] = '.';
    buffer += 1;

    // number = number + 0.5 * pow(1.0 / base, prec);
    char ch = 0;
    do {
        // no round-off
        number = number * base;
        ch = (char)number;
        buffer[0] = _Digit[ch];
        buffer += 1;
        number = number - ch;
    } while (prec -= 1, 0 < prec);

    if (suffix == true) {
        if (base == 10) {
            buffer[0] = '_', buffer[1] = 'D';
        }
        else if (base == 2) {
            buffer[0] = '_', buffer[1] = 'B';
        }
        else if (base == 8) {
            buffer[0] = '_', buffer[1] = 'O';
        }
        else if (base == 16) {
            buffer[0] = '_', buffer[1] = 'H';
        }
        buffer += 2;
    }
    buffer[0] = '\0';
    return buffer;
}

Entry *Attach_Fixed(Entry *entry, char *attri, in64 inte, bool many) {
    static char _buffer[1024];
    static char *buffer = _buffer;

    static Entry *_entry = NULL;
    static char *_attri = NULL;
    static Attri *hand = NULL;

    if (entry != NULL) {
        if (hand == NULL) {
            _entry = entry;
            _attri = attri;
            hand = Handle_Attri(entry, attri, false);
            if (hand->_value != NULL) {
                buffer[0] = ' ', buffer[1] = '|', buffer[2] = ' ';
                buffer += 3;
            }
            buffer = Print_Float(buffer, inte, 10, 6);
        }
        else if (_entry == entry && _attri == attri) {
            buffer[0] = ' ', buffer[1] = '|', buffer[2] = ' ';
            buffer += 3;
            buffer = Print_Float(buffer, inte, 10, 6);
        }
    }

    if (many == false && hand != NULL) {
        if (hand->_value == NULL) {
            hand->_value = Make_Data(_buffer, buffer - _buffer);
            hand->_type = EType._Fixed;
            hand->_leng = buffer - _buffer;
        }
        else {
            Check(hand->_type != EType._Fixed, ELevel._Warn, __FUNCTION__, "attri->_type != EType._Fixed", NULL);
            hand->_value = Join_Data(hand->_value, hand->_leng, _buffer, buffer - _buffer);
            hand->_type = EType._Fixed;
            hand->_leng += buffer - _buffer;
        }

        buffer = _buffer;
        hand = NULL;
    }
    return entry;
}

Entry *Attach_Float(Entry *entry, char *attri, fl64 frac, bool many) {
    static char _buffer[1024];
    static char *buffer = _buffer;

    static Entry *_entry = NULL;
    static char *_attri = NULL;
    static Attri *hand = NULL;

    if (entry != NULL) {
        if (hand == NULL) {
            _entry = entry;
            _attri = attri;
            hand = Handle_Attri(entry, attri, false);
            if (hand->_value != NULL) {
                buffer[0] = ' ', buffer[1] = '|', buffer[2] = ' ';
                buffer += 3;
            }
            buffer = Print_Float(buffer, frac, 10, 6);
        }
        else if (_entry == entry && _attri == attri) {
            buffer[0] = ' ', buffer[1] = '|', buffer[2] = ' ';
            buffer += 3;
            buffer = Print_Float(buffer, frac, 10, 6);
        }
    }

    if (many == false && hand != NULL) {
        if (hand->_value == NULL) {
            hand->_value = Make_Data(_buffer, buffer - _buffer);
            hand->_type = EType._Float;
            hand->_leng = buffer - _buffer;
        }
        else {
            Check(hand->_type != EType._Float, ELevel._Warn, __FUNCTION__, "attri->_type != EType._Fixed", NULL);
            hand->_value = Join_Data(hand->_value, hand->_leng, _buffer, buffer - _buffer);
            hand->_type = EType._Float;
            hand->_leng += buffer - _buffer;
        }

        buffer = _buffer;
        hand = NULL;
    }
    return entry;
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

iptr BackPack(char *buffer, Entry *note) {
    static iptr indent = 2;
    static Entry *_stack[128];
    static iptr _top = 0;

    char *retu = buffer;
    iptr deep = 0;
    _top = 0;

    _stack[_top] = note->_nest;
    _top += 1;
    deep += indent;
    while (_top >= 1) {
        _top -= 1;
        Entry *head = _stack[_top];
        deep -= indent;

        while (head != NULL) {
            for (iptr i = 0; i < deep; buffer[i++] = ' ');
            buffer += deep;

            buffer = Copy_Data(buffer, head->_entry, 0);
            buffer[0] = ' ', buffer[1] = '#';
            buffer += 2;
            if (head->_list != NULL) {
                Attri *tail = head->_list;
                Attri *list = tail;
                do {
                    list = list->_link;

                    buffer[0] = ' ';
                    buffer += 1;
                    buffer = Copy_Data(buffer, list->_attri, 0);

                    buffer[0] = ' ', buffer[1] = '=', buffer[2] = ' ';
                    buffer += 3;

                    buffer = Copy_Data(buffer, list->_value, list->_leng);
                    buffer[0] = ';';
                    buffer += 1;
                } while (list != tail);
                buffer[0] = '\n';
                buffer += 1;
            }

            _stack[_top] = head->_link;
            _top += 1;
            deep += indent;
            head = head->_nest;
        }
    }
    buffer[0] = '\0';
    return (buffer - retu);
}

iptr Dump_File(char *filename, char *buffer, iptr leng) {
    FILE *file = fopen(filename, "wb+");
    if (Check(file == NULL, ELevel._Error, __FUNCTION__, "file == NULL", NULL)) {
        return 0;
    }

    iptr count = fwrite(buffer, sizeof(char), leng, file);
    Check(count != leng, ELevel._Error, __FUNCTION__, "count != leng", NULL);
    Check(fclose(file) != 0, ELevel._Error, __FUNCTION__, "fclose(file) != 0", NULL);
    return count;
}

void Test_Notation() {
    typedef struct _Person {
        char *_name;        // BSS9395
        ui64 _id;           // 19930905193000
        fl64 _credit[3];    // 0.02, 0.50, 0.98
        struct _Info {
            char *_email;   // brilliantstarrysky9395@gmail.com
            char *_birth;   // 1993-09-05T19:30:00.000+0800    // YYYY-MM-DDThh:mm:ss.ttt+ZZzz
            ui08  _age;     // 27
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
            ._age = 27
        },
        ._desc = "An idiot, then a genius."
    };

    Entry note = *(Entry *)Zero_Data(sizeof(Entry));
    Entry *head = NULL;

    head = Handle_Entry(&note, "person", true);
    Attach_String(head, "name", person._name, 0);
    Attach_Fixed(head, "id", person._id, false);
    for (iptr i = 0; i < 3; i += 1) {
        Attach_Float(head, "credit", person._credit[i], i != 2);
    }
    Attach_Binary(head, "desc", person._desc, Length(person._desc));

    head = Handle_Entry(head, "info", true);
    Attach_String(head, "email", person._info._email, 0);
    Attach_String(head, "birth", person._info._birth, 0);
    Attach_Fixed(head, "age", person._info._age, false);

    ////////////////////////////////////////////////////////////////////////////
    head = Handle_Entry(&note, "person", false);
    Attach_String(head, "name", person._name, 0);
    Attach_Fixed(head, "id", person._id, false);
    for (iptr i = 0; i < 3; i += 1) {
        Attach_Float(head, "credit", person._credit[i] + 0.02, true);
    }
    Attach_Float(NULL, NULL, 0, false);
    Attach_Binary(head, "desc", person._desc, Length(person._desc));

    char buffer[1024];
    iptr leng = BackPack(buffer, &note);
    fprintf(stdout, "%s""\n", buffer);
    Dump_File("person.note", buffer, leng);
}

int main(int argc, char *argv[]) {
    Test_Notation();

    return 0;
}
