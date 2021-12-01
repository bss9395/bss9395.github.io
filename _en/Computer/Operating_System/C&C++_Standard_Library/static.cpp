/* static.cpp
Author: BSS9395
Update: 2021-11-30T22:03:00+08@China-Guangdong-Shenzhen+08
Design: C++ Standard Keyword: static
*/

#include <cstdint>
#include <iostream>

typedef intptr_t iptr;

class Count {
public:
    static constexpr char _Type[] = "Count";
    static Count _Count;

public:
    const char *_type = NULL;

public:
    Count(const char *type = _Type) {
        std::cerr << __FUNCTION__ << std::endl;
        _type = type;
        if ((Count::Increment() += 1) <= 1) {
            std::cout << "type = " << _type << std::endl;
        }
    }

    virtual ~Count() {
        std::cerr << __FUNCTION__ << std::endl;
        if ((Count::Increment() -= 1) <= 0) {
            std::cout << "type = " << _type << std::endl;
        }
    }

public:
    static iptr& Increment() {
        static iptr incr = 0;
        return incr;
    }
};
Count Count::_Count = Count{};


int main(int argc, char *argv[]) {
    Count count1{ "count1" };
    Count count2{ "count2" };
    Count count3{ "count3" };

    return 0;
}
