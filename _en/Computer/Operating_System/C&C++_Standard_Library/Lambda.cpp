/* lambda.cpp
Author: BSS9395
Update: 2022-01-06T04:28:00+08@China-Guangdong-Shenzhen+08
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

class Format {
public:
    template<typename TBuffer>
    static TBuffer &Buffer(iptr capacity = 1024, iptr shrink = 2048) {
        static TBuffer buffer = "";
        if ((iptr)buffer.capacity() < capacity) {
            if ((iptr)buffer.capacity() > shrink) {
                buffer.shrink_to_fit();
            }
            buffer.reserve(capacity);
        }
        return buffer;
    }

public:
    template<typename TBuffer, typename TContainer>
    static TBuffer &Print(const TContainer &container, TBuffer &buffer = Buffer<TBuffer>(), const TBuffer &sepa = ", ") {
        buffer = "";
        if (0 < container.size()) {
            auto beg = container.begin(), end = container.end();
            for (buffer += (*beg), beg++; beg != end; buffer += sepa, buffer += (*beg), beg++);
        }
        return buffer;
    }

    static inline auto lambda = [](auto &container, std::string &buffer = "", const std::string &sepa = ", ") -> std::string & {
        if (0 < container.size()) {
            auto beg = container.begin(), end = container.end();
            for (buffer += (*beg)[0], beg++; beg != end; beg++) {
                buffer += sepa;
                buffer += (*beg)[0];
            }
        }
        return buffer;
    };

#define MEMBER
#define TBUFFER std::string
#define Print(MEMBER, TBUFFER)                                                                                        \
    [](const auto &container, TBUFFER &buffer = Format::Buffer<TBUFFER>(), const TBUFFER &sepa = ", ") -> TBUFFER & { \
        buffer = "";                                                                                                  \
        if (0 < container.size()) {                                                                                   \
            auto beg = container.begin(), end = container.end();                                                      \
            for (buffer += (*beg)MEMBER, beg++; beg != end; buffer += sepa, buffer += (*beg)MEMBER, beg++);           \
        }                                                                                                             \
        return buffer;                                                                                                \
    }

    static inline auto Print_ = Print(MEMBER, TBUFFER);
#undef MEMBER
#undef TBUFFER
};


int main(int argc, char *argv[]) {
    std::list<std::string> container;
    container.push_back(std::string("a1"));
    container.push_back(std::string("b2"));
    container.push_back(std::string("c3"));

    auto lambda = Print([0], std::string);
    fprintf(stderr, "%s""\n", lambda(container).data());
    fprintf(stderr, "%s""\n", Format::Print_(container).data());

    return 0;
}
