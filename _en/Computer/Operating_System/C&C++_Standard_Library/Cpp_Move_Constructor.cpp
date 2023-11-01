/* Cpp_Move_Constructor.cpp
Author: BSS9395
Update: 2023-10-05T15:55:00+08@China-Guangdong-Zhanjiang+08
*/

#include <iostream>
class Datum {
public:
    int* pointer;
    Datum()
        : pointer(new int(1)) {
        std::cout << "construct" << pointer << std::endl;
    }
    Datum(Datum& a)
        : pointer(new int(*a.pointer)) {
        std::cout << "copy" << pointer << std::endl;
    }

    Datum(Datum&& a) noexcept
        : pointer(a.pointer) {
        a.pointer = nullptr;
        std::cout << "move" << pointer << std::endl;
    }
    ~Datum() {
        std::cout << "destruct" << pointer << std::endl;
        delete pointer;
    }
};

// note: avoid compiler optimization
Datum _Return_Rvalue(bool test) {
    Datum a;
    Datum b;
    if (test) {
        return a;  // note: equal to static_cast<A&&>(a);
    }
    else {
        return b;  // note: equal to static_cast<A&&>(b);
    }
}
int main() {
    Datum obj = _Return_Rvalue(false);
    std::cout << " obj.pointer" << obj.pointer << std::endl;
    std::cout << "*obj.pointer" << *obj.pointer << std::endl;
    return 0;
}