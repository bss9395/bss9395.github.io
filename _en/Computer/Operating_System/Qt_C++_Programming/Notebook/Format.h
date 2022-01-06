/* Format.h
Author: BSS9395
Update: 2022-01-06T20:21:00+08@China-Guangdong-Shenzhen+08
Design: Notebook
Encode: UTF-8
System: Qt 5.15.2
Notice: Bug on Visual Studio 2017
*/

#ifndef Format_h
#define Format_h

#include "Common.h"

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

#endif // Format_h
