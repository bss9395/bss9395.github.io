/// Record: Into_Decimal_String.cpp
/// Author: Brilliant9395
/// Update: 2026/04/02⊥08:40:00&+08$08@China-GuangDong-ZhanJiang
/// Keepin: brilliant9395@yeah.net
/// Verify: [4, 89]

#include <stdio.h>
#include <inttypes.h>

uint8_t _Divide10(uint8_t* value, int64_t* bytes) {
    bool nonzero = false;
    uint16_t remainder_dividend = 0;
    for (int64_t ordi = (*bytes) - 1; 0 <= ordi; ) {
        remainder_dividend <<= 8;
        remainder_dividend |= (uint8_t)(value[ordi]);
        uint8_t quotient = (uint8_t)(remainder_dividend / 10);
        remainder_dividend = remainder_dividend % 10;
        if (nonzero == false && quotient != 0) {
            nonzero = true;
            (*bytes) = ordi + 1;
        }
        value[ordi] = quotient;
        ordi -= 1;
    }
    // 若value全为0
    if (nonzero == false) {
        (*bytes) = 0;
    }
    return (uint8_t)remainder_dividend;
}

void _Unsigned_Into_Decimal_String_Circulation(char* buffer, uint8_t* value, int64_t bytes) {
    char reversed[1024] = { 0 };
    char* back = (char*)&reversed;
    for (; 0 < bytes;) {
        back[0] = '0' + _Divide10(value, &bytes);
        back += 1;
    }
    back[0] = '\0';

    for (char* tail = back - 1; (char*)&reversed <= tail; ) {
        buffer[0] = tail[0];
        buffer += 1;
        tail -= 1;
    }
    buffer[back - (char*)&reversed] = '\0';
}

void _Signed_Into_Decimal_String(char* buffer, uint8_t* value, int64_t bytes) {
    int8_t high = ((int8_t*)value)[bytes - 1];
    if (high < 0) {
        buffer[0] = '-';
        buffer += 1;

        uint16_t carry_sum = 1;
        for (int64_t ordi = 0; ordi < bytes; ) {
            carry_sum  += (uint8_t)(~value[ordi]);  // 按位非操作先扩展位再取反位。
            value[ordi] = (uint8_t)carry_sum;
            carry_sum >>= 8;
            ordi += 1;
        }
    }
    _Unsigned_Into_Decimal_String_Circulation(buffer, value, bytes);
}

int main(int argc, char* argv[]) {
    uint8_t origin[1024] = { 0 };
    ((uint64_t*)&origin)[1] = 0x0000000000000000;
    ((uint64_t*)&origin)[0] = 0x00000000C0000001;
    int64_t bytes = 4;

    char buffer[1024] = { 0 };
    uint8_t value[1024] = { 0 };

    ((uint64_t*)&value)[1] = ((uint64_t*)&origin)[1];
    ((uint64_t*)&value)[0] = ((uint64_t*)&origin)[0];
    _Unsigned_Into_Decimal_String_Circulation((char*)&buffer, (uint8_t*)&value, bytes);
    printf("origin = 0x_%016I64X_%016I64X, length = %I64d\n", ((uint64_t*)&origin)[1], ((uint64_t*)&origin)[0], bytes);
    printf("value  = 0u_%0I64u_%0I64u    , buffer = %s!!!\n", ((uint64_t*)&value)[1], ((uint64_t*)&value)[0], (char*)&buffer);

    ((uint64_t*)&value)[1] = ((uint64_t*)&origin)[1];
    ((uint64_t*)&value)[0] = ((uint64_t*)&origin)[0];
    _Signed_Into_Decimal_String((char*)&buffer, (uint8_t*)&value, bytes);
    printf("origin = 0x_%016I64X_%016I64X, length = %I64d\n", ((uint64_t*)&origin)[1], ((uint64_t*)&origin)[0], bytes);
    printf("value  = 0u_%0I64u_%0I64u    , buffer = %s!!!\n", ((uint64_t*)&value)[1] , ((uint64_t*)&value)[0] , (char*)&buffer);

    return 0;
}
