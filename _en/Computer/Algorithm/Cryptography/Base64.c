/* Base64.c
Author: BSS9395
Update: 2020-01-13T00:00:00+08@China-Guangdong-Zhanjiang+08
Design: Base64 Codec
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define  Malloc   malloc
#define  Realloc  realloc
#define  Free     free

typedef  intptr_t  iptr;
typedef  unsigned  char   unch;
typedef  int8_t    in08;  typedef  int16_t   in16;  typedef  int32_t   in32;  typedef  int64_t   in64;
typedef  uint8_t   ui08;  typedef  uint16_t  ui16;  typedef  uint32_t  ui32;  typedef  uint64_t  ui64;

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

////////////////////////////////////////////////////////////////////////////////

bool Check(bool failed, Level level, unch *function, unch *record, unch *extra) {
    if (failed) {
        fprintf(stderr, "[%s] %s: %s%s""\n", level, function, record, (extra == NULL) ? "" : extra);
    }
    return failed;
}

Buffer Make_Buffer(iptr size) {
    return (Buffer) {
        ._buff = (unch *)Malloc(size * sizeof(unch)), ._leng = size, ._size = size
    };
}

iptr Free_Buffer(Buffer buffer) {
    iptr retu = 0;
    free(buffer._buff);
    retu += 1;
    return retu;
}

Buffer Be(unch *stri) {
    iptr leng = 0;
    for (; stri[leng] != '\0'; leng += 1);
    unch *buff = (unch *)Malloc(leng + 1);
    for (iptr i = 0; i < leng; i += 1) {
        buff[i] = stri[i];
    }
    buff[leng] = '\0';

    return (Buffer) {
        ._buff = buff, ._leng = leng, ._size = leng + 1
    };
}

////////////////////////////////////////////////////////////////////////////////

unch *Base64_Encode(Buffer *_code, Buffer _data) {
    static unch _Base64[64] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
        'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
        'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '+', '*'
    };
    typedef unch Code[4];
    typedef unch Data[3];

    // leng ≤ ⌈_data._leng / 3⌉ * 4
    iptr leng = (_data._leng + 2) / 3 * 4;
    if (_code->_size < leng + 1) {
        _code->_size = leng + 1;
        _code->_buff = (unch *)Realloc(_code->_buff, _code->_size * sizeof(unch));
    }
    Code *code = (Code *)_code->_buff;
    Data *data = (Data *)_data._buff;
    Data *over = data + (_data._leng / 3);

    /*
    index:        [3]      [2]      [1]      [0]
    data : |        |87654321|!!!!!!!!|87654321|
    code : |  876543|  21!!!!|  !!!!87|  654321|
    0x3F :                            |00111111|
    */
    for (; data < over; code += 1, data += 1) {
        (*code)[0] = _Base64[0x3F & ((*data)[0] >> 0)];
        (*code)[1] = _Base64[0x3F & ((*data)[0] >> 6 | (*data)[1] << 2)];
        (*code)[2] = _Base64[0x3F & ((*data)[1] >> 4 | (*data)[2] << 4)];
        (*code)[3] = _Base64[0x3F & ((*data)[2] >> 2)];
    }

    _code->_leng = (unch *)code - (unch *)_code->_buff;
    leng = _data._leng % 3;
    if (leng == 1) {
        (*code)[0] = _Base64[0x3F & ((*data)[0] >> 0)];
        (*code)[1] = _Base64[0x03 & ((*data)[0] >> 6)];
        _code->_leng += 2;
    }
    else if (leng == 2) {
        (*code)[0] = _Base64[0x3F & ((*data)[0] >> 0)];
        (*code)[1] = _Base64[0x3F & ((*data)[0] >> 6 | (*data)[1] << 2)];
        (*code)[2] = _Base64[0x0F & ((*data)[1] >> 4)];
        _code->_leng += 3;
    }
    _code->_buff[_code->_leng] = '\0';
    return _code->_buff;
}

iptr Base64_Decode(Buffer *_data, Buffer _code) {
    static unch _Base46[256] = {
    #define PHD -1
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,  63,  62, PHD, PHD, PHD, PHD,
          0,   1,   2,   3,   4,   5,   6,   7,   8,   9, PHD, PHD, PHD, PHD, PHD, PHD,
        PHD,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,
         25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35, PHD, PHD, PHD, PHD, PHD,
        PHD,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,
         51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61, PHD, PHD, PHD, PHD, PHD,
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD
    };
    typedef unch Data[3];
    typedef unch Code[4];

    if (_code._leng % 4 == 1 && Check(true, ELevel._Error, __FUNCTION__, "_code._leng % 4 == 1", NULL)) {
        _data->_leng = 0;
        return 0;
    }

    // leng ≤ ⌈_code._leng / 4⌉ * 3
    iptr leng = (_code._leng + 3) / 4 * 3;
    if (_data->_size < leng + 1) {
        _data->_size = leng + 1;
        _data->_buff = (unch *)Realloc(_data->_buff, _data->_size);
    }

    Data *data = (Data *)_data->_buff;
    Code *code = (Code *)_code._buff;
    Code *over = code + (_code._leng / 4);

    /*
    index:        [3]      [2]      [1]      [0]
    data : |        |87654321|!!!!!!!!|87654321|
    code : |  876543|  21!!!!|  !!!!87|  654321|
    0x3F :                            |00111111|
    */
    for (; code < over; data += 1, code += 1) {
        if (_Base46[(*code)[0]] == PHD || _Base46[(*code)[1]] == PHD || _Base46[(*code)[2]] == PHD || _Base46[(*code)[3]] == PHD) {
            Check(true, ELevel._Error, __FUNCTION__, "_Base46[(*code)[?]] == PHD", NULL);
            return ((unch *)code - (unch *)_code._buff);
        }
        (*data)[0] = _Base46[(*code)[0]] >> 0 | _Base46[(*code)[1]] << 6;
        (*data)[1] = _Base46[(*code)[1]] >> 2 | _Base46[(*code)[2]] << 4;
        (*data)[2] = _Base46[(*code)[2]] >> 4 | _Base46[(*code)[3]] << 2;
    }

    _data->_leng = (unch *)data - (unch *)_data->_buff;
    leng = _code._leng % 4;
    if (leng == 2) {
        if (_Base46[(*code)[0]] == PHD && Check(true, ELevel._Error, __FUNCTION__, "_Base46[(*code)[?]] == PHD", NULL)) {
            _data->_leng = 0;
            return (unch *)code - (unch *)_code._buff;
        }
        (*data)[0] = _Base46[(*code)[0]] >> 0 | _Base46[(*code)[1]] << 6;
        _data->_leng += 1;
    }
    else if (leng == 3) {
        if (_Base46[(*code)[0]] == PHD && _Base46[(*code)[1]] == PHD && Check(true, ELevel._Error, __FUNCTION__, "_Base46[(*code)[?]] == PHD", NULL)) {
            _data->_leng = 0;
            return (unch *)code - (unch *)_code._buff;
        }
        (*data)[0] = _Base46[(*code)[0]] >> 0 | _Base46[(*code)[1]] << 6;
        (*data)[1] = _Base46[(*code)[1]] >> 2 | _Base46[(*code)[2]] << 4;
        _data->_leng += 2;
    }
    _data->_buff[_data->_leng] = '\0';
    return 0;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Base64() {
    Buffer bina = Be("BSS9395@Github");
    Buffer code = Make_Buffer(4096);
    Base64_Encode(&code, bina);
    fprintf(stdout, "%s\n", code._buff);

    Buffer data = Make_Buffer(4096);
    Base64_Decode(&data, code);
    fprintf(stdout, "%s\n", data._buff);
}

in08 main(in08 argc, unch *argv[]) {
    Test_Base64();

    return 0;
}
