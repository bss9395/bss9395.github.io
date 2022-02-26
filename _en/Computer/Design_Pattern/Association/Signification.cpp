/* Signify.cpp
Author: BSS9395
Update: 2022-02-26T14:30:00+08@China-Guangdong-Zhanjiang+08
Design: Signification
Encode: UTF-8
*/

#include <iostream>
#include <string>

typedef intptr_t iptr;

struct Format {
    static const char* Signify(const char* sign) {
        return sign;
    }
#define Signifying(sign)    Signify(""#sign)
};

int main(int argc, char* argv[]) {
    iptr GL_VERTEX_SHADER = 123;
    const char* sign = Format::Signifying(GL_VERTEX_SHADER);

    fprintf(stderr, "%td, %s""\n", GL_VERTEX_SHADER, sign);

    return 0;
}
