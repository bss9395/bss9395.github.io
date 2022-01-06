/* lambda.cpp
Author: BSS9395
Update: 2022-01-06T16:48:00+08@China-Guangdong-Shenzhen+08
Design: C++ Standard Expression: Generic Lambda
Format: UTF-8
System: G++
Notice: Bug on Visual Studio 2017
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <list>

typedef intptr_t iptr;

#ifdef QT_VERSION_STR
typedef QString String;
#else
typedef std::string String;
#endif

namespace Format { // note: struct Format, bug on Visual Studio 2017.
    template<typename TBuffer = String>
    static TBuffer &Buffer(const iptr capacity = 1024, const iptr shrink = 2048) {
        fprintf(stderr, "%s""\n", __FUNCTION__);
        static TBuffer buffer = "";
        if ((iptr)buffer.capacity() < capacity) {
            if ((iptr)buffer.capacity() > shrink) {
                buffer.shrink_to_fit();
            }
            buffer.reserve(capacity);
        }
        return buffer;
    }

#define TBUFFER auto /* String or auto */
#define MEMBER
#define Lambda_Print(MEMBER, TBUFFER)                                                                                            \
    [](const auto &container, TBUFFER &buffer = Format::Buffer<String>(), const TBUFFER &sepa = String(", ")) -> TBUFFER & { \
        /* fprintf(stderr, "%s""\n", __FUNCTION__); */                                                                       \
        buffer.clear();                                                                                                      \
        if (0 < container.size()) {                                                                                          \
            auto beg = container.begin(), end = container.end();                                                             \
            for (buffer += (*beg)MEMBER, beg++; beg != end; buffer += sepa, buffer += (*beg)MEMBER, beg++);                  \
        }                                                                                                                    \
        return buffer;                                                                                                       \
    }                                                                                                                        \
// Leave Blank Space

    static inline const auto &Print = []() -> auto {
        static const auto lambda = Lambda_Print(, String);  // note: struct Format, bug on Visual Studio 2017.
        return lambda;
    }();
#undef MEMBER
#undef TBUFFER
}; // note: struct Format

int main(int argc, char *argv[]) {
    std::list<std::string> container;
    container.push_back(std::string("a1"));
    container.push_back(std::string("b2"));
    container.push_back(std::string("c3"));

    auto lambda = Lambda_Print([0], auto);       // String or auto
    std::wstring buffer = std::wstring(1024, 0);
    fprintf(stderr, "%ls""\n", lambda(container, buffer, std::wstring(L", ")).data());  // note: std::wstring() + 'a';
    fprintf(stderr, "%s""\n", Format::Print(container).data());

    return 0;
}
