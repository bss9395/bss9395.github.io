/* Cpp_bind.cpp
Author: BSS9395
Update: 2023-10-05T14:57:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: bind
*/

#include <functional>
#include <iostream>

int _Func(int a, int b, int c) {
    std::cout << a << ", " << b << ", " << c;
    return 0;
}

int main() {
    auto Bind = std::bind(_Func, 1, std::placeholders::_1, 3);
    Bind(2);
    return 0;
}
