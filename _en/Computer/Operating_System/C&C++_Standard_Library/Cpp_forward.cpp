/* Cpp_forward.cpp
Author: BSS9395
Update: 2023-10-05T16:30:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: forward
*/

#include <iostream>
#include <utility>

void _Reference(int& v) {
    std::cout << "lvalue reference" << std::endl;
}

void _Reference(int&& v) {
    std::cout << "rvalue reference" << std::endl;
}

template <typename T>
void _Pass(T&& v) {
    std::cout << "          normal param passing: ";
    _Reference(v);
    std::cout << "       std::move param passing: ";
    _Reference(std::move(v));
    std::cout << "    std::forward param passing: ";
    _Reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> param passing: ";
    _Reference(static_cast<T&&>(v));
}

int main() {
    std::cout << "rvalue pass:" << std::endl;
    _Pass(1);

    std::cout << "lvalue pass:" << std::endl;
    int lvalue = 1;
    _Pass(lvalue);

    return 0;
}