/* enum.cpp
Author: BSS9395
Update: 2021-10-23T18:12:00+08@China-Guangdong-Shenzhen+08
Design: C++ enum keyward
*/

#include <cstdint>
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    enum Forward : unsigned long long;  // enum forward declaration.
    enum class Declaration;             // enum class forward declaration.

    // anonymous enum
    enum {
        _Anonymity_0,
        _Anonymity_1,
        _Anonymity_2
    };

    // unscoped enum
    enum Unscoped {
        _Unscoped_0 = 0,
        _Unscoped_1 = 1,
        _Unscoped_2 = 2
    };

    // scoped enum class
    enum class Scoped {
        _Scoped_0 = 0x0001,
        _Scoped_1 = 0x0004,
        _Scoped_2 = 0x0008
    };

    // typed enum class
    enum class Typed : unsigned long long {
        _Typed_0 = 0x00000001LL,
        _Typed_1 = 0x00000004LL,
        _Typed_2 = 0x00000008LL
    };

    int anonymity = _Anonymity_2;
    int unscoped_0 = _Unscoped_0;
    Unscoped unscoped_1 = _Unscoped_1;
    Unscoped unscoped_2 = Unscoped::_Unscoped_2;
    Scoped scoped = Scoped::_Scoped_2;
    int scoped_int = (int)Scoped::_Scoped_2;
    unsigned long long typed = (unsigned long long) Typed::_Typed_2;

    return 0;
}
