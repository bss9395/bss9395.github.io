/// Record: From_Hexadecimal_String.cpp
/// Author: Brilliant9395
/// Update: 2026/04/02T08:40:00&+00@China-GuangDong-ZhanJiang
/// Keepin: brilliant9395@yeah.net

#include <stdio.h>
#include <inttypes.h>

/// Exit _From_Hexadecimal_String(char* hexadecimal)
/// hexadecimal: 需转换的字符串
/// value: 结果值
/// sign : 结果值的正负号
/// check:
//      0b??01: 字符串起始无效
//      0b??10: 字符串终止无效
//      0b01??: 结果值无符号上溢出
//      0b10??: 结果值有符号下溢出
//      0b0000: 字符串有效且结果值合规
struct Exit {
    uint64_t value;
    int8_t   sign;
    uint8_t  check;
};
Exit _From_Hexadecimal_String(char* hexadecimal) {
    static const uint64_t overhead_uin8_mul16 = (~uint64_t{ 0 }) / 16;  // 0x0FFFFFFFFFFFFFFF
    static const uint64_t overhead_uin8       = (~uint64_t{ 0 });       // 0xFFFFFFFFFFFFFFFF
    static const uint64_t overtail_int8       = (uint64_t{ 1 } << 63);  // 0X8000000000000000

    uint64_t value = 0;
    int8_t   sign  = 0;
    uint8_t  check = 0b00000000;
    if (hexadecimal == NULL) {
        check &= 0b11111100;
        check |= 0b00000001;
        return Exit{value, sign, check};
    }
    // 字符串起始检查
    while (hexadecimal[0] != '\0' && hexadecimal[0] == ' ') {
        hexadecimal += 1;
    }
    if (hexadecimal[0] != '\0') {
        if (hexadecimal[0] == '+') {
            sign = +1;
            hexadecimal += 1;
        }
        else if (hexadecimal[0] == '-') {
            sign = -1;
            hexadecimal += 1;
        }
    }
    if ((hexadecimal[0] != '\0' && ('0' <= hexadecimal[0] && hexadecimal[0] <= '9' || 'A' <= hexadecimal[0] && hexadecimal[0] <= 'F')) == false) {
        check &= 0b11111100;
        check |= 0b00000001;
        return Exit{ value, sign, check };
    }
    // 字符串转换为无符号值
    while (hexadecimal[0] != '\0') {
        uint8_t digit = 0;
        if ('0' <= hexadecimal[0] && hexadecimal[0] <= '9') {
            digit = hexadecimal[0] - '0';
            hexadecimal += 1;
        }
        else if ('A' <= hexadecimal[0] && hexadecimal[0] <= 'F') {
            digit = hexadecimal[0] - 'A' + 10;
            hexadecimal += 1;
        }
        else {
            break;
        }

        if (value <= overhead_uin8_mul16) {
            value *= 16;
            if (value <= overhead_uin8 - digit) {
                value += digit;
            }
            else {
                check &= 0b11110011;
                check |= 0b00000100;
                break;
            }
        }
        else {
            check &= 0b11110011;
            check |= 0b00000100;
            break;
        }
    }  /// away:
    while (hexadecimal[0] != '\0' && ('0' <= hexadecimal[0] && hexadecimal[0] <= '9' || 'A' <= hexadecimal[0] && hexadecimal[0] <= 'F')) {
        hexadecimal += 1;
    }
    // 结果值有符号检查
    if (sign == -1) {
        if (value <= overtail_int8) {
            value = ~value + 1;
        }
        else {
            value = ~overtail_int8 + 1;
            check &= 0b11110011;
            check |= 0b00001000;
        }
    }
    // 字符串终止检查
    while (hexadecimal[0] != '\0' && hexadecimal[0] == ' ') {
        hexadecimal += 1;
    }
    if (hexadecimal[0] != '\0') {
        check &= 0b11111100;
        check |= 0b00000010;
    }
    return Exit{ value, sign, check };
}

int main(int argc, char* argv[]) {
    char hexadecimal[256] = "-1234567890ABCDEF";   // hexadecimal = -1311768467294899695

    Exit exit = _From_Hexadecimal_String(hexadecimal);
    printf("value = 0x%016I64X, value = %I64d, sign = %d, error = %02X, decimal = %s\n", exit.value, exit.value, exit.sign, exit.check, hexadecimal);

    return 0;
}
