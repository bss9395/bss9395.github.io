/* addressof.cpp
Author: BSS9395
Update: 2021-11-27T21:29:00+08China-Guangdong-Shenzhen+08
Design: C++ Standary Library: addressof
Credit: https://www.cplusplus.com/reference/memory/addressof/
*/

/*
#include <memory>
template<class T>
T* addressof(T& ref) noexcept;
*/

#include <iostream>
#include <memory>

class Unrefer {
public:
    int _value;

public:
    Unrefer* operator&() {
        std::cout << __FUNCTION__ << std::endl;
        return nullptr;
    }
};

void Print(Unrefer* unrefer) {
    if (unrefer == nullptr) {
        std::cout << "unrefer = nullptr" << std::endl;
        return;
    }
    std::cout << "unrefer->_value = " << unrefer->_value << std::endl;
}

int main(int argc, char *argv[]) {
    void(*function)(Unrefer*) = std::addressof(Print);

    Unrefer value{ 10 };
    Unrefer* unrefer = &value;
    Unrefer* refer = std::addressof(value);

    (*function)(unrefer);
    (*function)(refer);

    return 0;
}
