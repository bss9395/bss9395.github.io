/* Notebook
Author: BSS9395
Update: 2022-01-05T23:10:00+08@China-Guangdong-Shenzhen+08
Design: Format
Encode: UTF-8
*/

#ifndef Format_h
#define Format_h

#include "System.h"

#include <QString>
#include <string>
#include <list>

class Format {
public:
    template<typename TBuffer>
    static TBuffer &Buffer(iptr capacity = 1024, iptr shrink = 2048) {
        static TBuffer buffer = "";
        if (buffer.capacity() < capacity) {
            if (buffer.capacity() > shrink) {
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
            for (buffer += (*beg), beg++; beg != end; buffer += sepa + (*beg), beg++);
        }
        return buffer;
    }
};

#endif // Format_h
