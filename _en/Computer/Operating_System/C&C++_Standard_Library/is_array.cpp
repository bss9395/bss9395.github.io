/* is_array.cpp
Author: BSS9395
Update: 2022-02-22T20:22:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: is_array
Encode: UTF-8
Credit: https://www.cplusplus.com/reference/type_traits/is_array/
*/

/*
#include <type_traits>
template<class T>
struct is_array;
*/

#include <iostream>
#include <array>
#include <cstring>
#include <string>
#include <type_traits>
#include <type_traits>

template<typename TType1, typename TType2>
void Name(const TType1 &ttype1, TType2 &&ttype2) {
    // note: char [7], can not be copied, can not be assigned.
    // note: const char (&)[7], can be initialized, but can not be assigned.

    std::cout << "TType1: " << typeid(TType1).name() << ", TType2: " << typeid(TType2).name() << std::endl;
    std::cout << "type1: " << typeid(ttype1).name() << ", type2: " << typeid(ttype2).name() << std::endl;
    std::cout << "sizeof type1: " << sizeof(ttype1) << ", sizeof type2: " << sizeof(ttype2) << std::endl;

    TType1 _type1;                         // note: char [?] type should be initialized.
    memcpy(&_type1, ttype1, sizeof(ttype1));
    std::cout << _type1 << std::endl;

    TType2 _type2(ttype2);                  // note: reference type must be initialized.
    std::cout << _type2 << std::endl;
};

template<typename TType1, typename TType2>
void Trait(const TType1 &ttype1, TType2 &&ttype2) {
    std::cout << std::boolalpha;
    std::cout << "int: " << std::is_array<int>::value << std::endl;
    std::cout << "int[3]: " << std::is_array<int[3]>::value << std::endl;
    std::cout << "array<int,3>: " << std::is_array<std::array<int, 3>>::value << std::endl;
    std::cout << "string: " << std::is_array<std::string>::value << std::endl;
    std::cout << "string[3]: " << std::is_array<std::string[3]>::value << std::endl;

    ////////////////////////////////////

    std::cout << std::boolalpha;
    std::cout << "TType1: " << std::is_array<TType1>::value << std::endl;  // note: array type.
    std::cout << "TType2: " << std::is_array<TType2>::value << std::endl;  // note: reference type.
}

int main() {
    Name("abcdef", "defghi");

    fprintf(stderr, "========================================""\n");

    Trait("abcdef", "defghi");

    return 0;
}
