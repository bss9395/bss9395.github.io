/* operator,.cpp
Author: BSS9395
Update: 2022-02-23T18:25:00+08@China-Guangdong-Zhanjiang+08
Design: C++ operator,
Encode: UTF-8
Credit: https://www.cnblogs.com/dishengAndziyu/p/10913855.html
*/

#include <iostream>
#include <string>

struct Seed {
    int _value;

    Seed(int Value) {
        _value = Value;
    }

    Seed &operator,(const Seed &seed) {
        Seed &ret = (Seed &)seed;
        ret._value += _value;
        return ret;
    }
};

//// note: (lhs, rhs)  equals  operator,(lhs, rhs);
//Seed& operator,(const Seed& lhs, const Seed& rhs) {
//    Seed &ret = (Seed &)rhs;
//    ret._value += lhs._value;
//    return ret;
//}

Seed &Call(Seed& seed) {
    std::cout << "seed._value = " << seed._value << std::endl;
    return seed;
}


int main(int argc, char *argv[]) {
    Seed seed1(1);
    Seed seed2(2);
    Seed seed3(3);

    // note: the calling order of function parameters depends on compiler.
    // note: the evaluation order of operator, is from left to right.
    Seed seed = (Call(seed1), Call(seed2), Call(seed3));
    std::cout << seed._value << std::endl;

    return 0;
}
