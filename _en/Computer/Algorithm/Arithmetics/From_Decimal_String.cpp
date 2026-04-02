/// Record: From_Decimal_String.cpp
/// Author: Brilliant9395
/// Update: 2026/04/02⊥08:40:00&+08$08@China-GuangDong-ZhanJiang
/// Keepin: brilliant9395@yeah.net
/// Verify: [2, 121]

#include <stdio.h>
#include <inttypes.h>

/// uint64_t _From_Decimal_String(int8_t* sign, uint8_t* check, char* decimal)
/// para:
///     sign   : 结果值的正负号
///     check  :
///         0b??01: 字符串起始无效
///         0b??10: 字符串终止无效
///         0b01??: 结果值无符号上溢出
///         0b10??: 结果值有符号下溢出
///         0b0000: 字符串有效且结果值合规
///     decimal: 需转换的字符串
/// exit:
///     value  : 结果值
uint64_t _From_Decimal_String(int8_t* sign, uint8_t* error, char* decimal) {
    static const uint64_t overhead_uin8_mul10 = (~uint64_t{ 0 }) / 10;
    static const uint64_t overhead_uin8 = (~uint64_t{ 0 });
    static const uint64_t overtail_int8 = (uint64_t{ 1 } << 63);

    uint64_t value = 0;
    int8_t ternary = 0;
    uint8_t check = 0b00000000;
    if (decimal == NULL) {
        return value;
    }
    // 字符串起始检查
    while (decimal[0] != '\0' && decimal[0] == ' ') {
        decimal += 1;
    }
    if (decimal[0] != '\0') {
        if (decimal[0] == '+') {
            ternary = +1;
            decimal += 1;
        }
        else if (decimal[0] == '-') {
            ternary = -1;
            decimal += 1;
        }
    }
    if ((decimal[0] != '\0' && ('0' <= decimal[0] && decimal[0] <= '9')) == false) {
        check &= 0b11111100;
        check |= 0b00000001;
        if (error != NULL) {
            (*error) = check;
        }
        return value;
    }
    // 字符串转换为无符号值
    while (decimal[0] != '\0' && ('0' <= decimal[0] && decimal[0] <= '9')) {
        unsigned char digit = decimal[0] - '0';
        decimal += 1;
        if (value <= overhead_uin8_mul10) {
            value *= 10;
            if (value <= overhead_uin8 - digit) {
                value += digit;
            }
            else {
                value = overhead_uin8;
                check &= 0b11110011;
                check |= 0b00000100;
                break;
            }
        }
        else {
            value = overhead_uin8;
            check &= 0b11110011;
            check |= 0b00000100;
            break;
        }
    }  /// away:
    while (decimal[0] != '\0' && ('0' <= decimal[0] && decimal[0] <= '9')) {
        decimal += 1;
    }
    // 结果值有符号检查
    if (check == 0b00000000 && ternary == -1) {
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
    while (decimal[0] != '\0' && decimal[0] == ' ') {
        decimal += 1;
    }
    if (decimal[0] != '\0') {
        check &= 0b11111100;
        check |= 0b00000010;
    }
    // 赋值结果值
    if (sign != NULL) {
        (*sign) = (ternary == -1) ? -1 : +1;
    }
    if (error != NULL) {
        (*error) = check;
    }
    return value;
}

int main(int argc, char* argv[]) {
    char decimal[256] = "-1234567890";
    // char decimal[256] = "+";

    int8_t sign = 0;
    uint8_t error = 0;
    uint64_t value = _From_Decimal_String(&sign, &error, decimal);
    printf("value = 0x%016I64X, value = %I64d, sign = %d, error = %0u, decimal = %s\n", value, value, sign, error, decimal);

    return 0;
}
