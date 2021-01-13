/* Base64.c
Author: BSS9395
Update: 2020-01-13T10:58:00+08@China-Guangdong-Zhanjiang+08
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

unch *Base16_Encode(Buffer *_code, Buffer _data) {
    static unch _Base16[16] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
    };

    unch *code = _code->_buff;
    unch *data = _data._buff;
    unch *over = (unch *)&data[_data._leng];
    // leng = _data._leng * 2
    iptr leng = _data._leng * 2;
    if (_code->_size < leng + 1) {
        _code->_size = leng + 1;
        _code->_buff = (unch *)Realloc(_code->_buff, _code->_size * sizeof(unch));
    }

    /*
    index:        [1]      [0]
    data : |        |87654321|
    code : |    8765|    4321|
    0x0F :          |00001111|
    */
    for (; data < over; code += 2, data += 1) {
        code[0] = _Base16[0x0F & (data[0] >> 0)];
        code[1] = _Base16[0x0F & (data[0] >> 4)];
    }
    _code->_leng = (unch *)code - (unch *)_code->_buff;
    _code->_buff[_code->_leng] = '\0';
    return _code->_buff;
}

iptr Base16_Decode(Buffer *_data, Buffer _code) {
    static unch _Base16[256] = {
    #define PHD ((in32)-1)
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
        PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
          0,   1,   2,   3,   4,   5,   6,   7,   8,   9, PHD, PHD, PHD, PHD, PHD, PHD,
        PHD,  10,  11,  12,  13,  14,  15,  16, PHD, PHD, PHD, PHD, PHD, PHD, PHD, PHD,
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

    unch *data = (unch *)_data->_buff;
    unch *code = (unch *)_code._buff;
    unch *over = (unch *)&code[_code._leng];
    if (_code._leng % 2 == 1 && Check(true, ELevel._Error, __FUNCTION__, "_code._leng % 2 == 1", NULL)) {
        _data->_leng = 0;
        return ((unch *)code - (unch *)_code._buff);
    }
    // leng = _code._leng / 2
    iptr leng = _code._leng / 2;
    if (_data->_size < leng + 1) {
        _data->_size = leng + 1;
        _data->_buff = (unch *)Realloc(_data->_buff, _data->_size * sizeof(unch));
    }

    /*
    index:        [1]      [0]
    data : |        |87654321|
    code : |    8765|    4321|
    0x0F :          |00001111|
    */
    for (; code < over; data += 1, code += 2) {
        if (_Base16[code[0]] == PHD || _Base16[code[1]] == PHD) {
            Check(true, ELevel._Error, __FUNCTION__, "_Base16[code[?]] == PHD", NULL);
            _data->_leng = 0;
            return ((unch *)code - (unch *)_code._buff);
        }
        data[0] = _Base16[code[0]] >> 0 | _Base16[code[1]] << 4;
    }

    _data->_leng = (unch *)data - (unch *)_data->_buff;
    _data->_buff[_data->_leng] = '\0';
    return 0;
}

void Test_Base16() {
    Buffer bina = Be("BSS9395@GitHub");
    Buffer code = Make_Buffer(4096);
    Base16_Encode(&code, bina);
    fprintf(stdout, "\n%s\n", code._buff);

    for (iptr i = 0; i < bina._leng; i += 1) {
        fprintf(stdout, "%2X", bina._buff[i]);
    }

    Buffer data = Make_Buffer(4096);
    Base16_Decode(&data, code);
    fprintf(stdout, "\n%s\n", data._buff);
}

in08 main(in08 argc, unch *argv[]) {
    Test_Base16();

    return 0;
}
