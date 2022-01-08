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

typedef intptr_t iptr;
typedef wchar_t wide;

#ifdef QT_VERSION_STR
typedef QString String;
#else
typedef std::string String;
#endif

////////////////////////////////////////////////////////////////////////////////

struct Format { // note: struct Format, bug on Visual Studio 2017.
    template<typename TBuffer = String>
    static TBuffer &Buffer(const iptr capacity = 1024, const iptr shrink = 2048) {
        // fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);
        static TBuffer buffer = TBuffer(capacity, 0);
        if ((iptr)buffer.capacity() > shrink) {
            buffer.shrink_to_fit();
        }
        if ((iptr)buffer.capacity() < capacity) {
            buffer.reserve(capacity);
        }
        return buffer;
    }

#define Lambda_Print(Member, TBuffer)                                                                                        \
    [](const auto &container, TBuffer &buffer = Format::Buffer<String>(1024, 2048), const TBuffer &sepa = String(", ")) -> TBuffer & { \
        /* fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__); */                                                 \
        buffer.clear();                                                                                                      \
        if (0 < container.size()) {                                                                                          \
            auto beg = container.begin(), end = container.end();                                                             \
            for (buffer += (*beg)Member, beg++; beg != end; buffer += sepa, buffer += (*beg)Member, beg++);                  \
        }                                                                                                                    \
        return buffer;                                                                                                       \
    }                                                                                                                        \
// Leave Blank Space

    static inline const auto &Print = Lambda_Print(, String);  // note: struct Format, bug on Visual Studio 2017.
};

#endif // Format_h
