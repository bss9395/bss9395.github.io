/* pragma_pack.c
Author: BSS9395
Update: 2021-11-27T21:20:00+08@China-Guangdong-Shenzhen+08
Design: C Standard Pragma: #pragma pack()
*/

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef intptr_t iptr;

// Windows: #pragma pack(2^N)
#pragma pack(2)              /* affect the memory layout of inside and outside Pack */
struct Type {
    char _char;     //  0:1+1
    int _int;       //  2:4+0
    iptr _iptr;     //  6:8+0; 64bit
    float _float;   // 14:4+0
    double _double; // 18:8+0
};                  // 26:0+0
#pragma pack()               /* restore default memory layout */

FILE* Print(FILE *file, const struct Type* type) {
    // alignof(Type) == std::alignment_of<Type>::value
    fprintf(file, "sizeof(Type) = %td""\n", sizeof(struct Type));
    fprintf(file, "addressof type = %p, addressof type = %td""\n", type, (iptr)type);
    fprintf(file, "offsetof(Type, _char) = %td, sizoef(char) = %td""\n", offsetof(struct Type, _char), sizeof(char));
    fprintf(file, "offsetof(Type, _int) = %td, sizoef(int) = %td""\n", offsetof(struct Type, _int), sizeof(int));
    fprintf(file, "offsetof(Type, _iptr) = %td, sizoef(iptr) = %td""\n", offsetof(struct Type, _iptr), sizeof(iptr));
    fprintf(file, "offsetof(Type, _float) = %td, sizoef(float) = %td""\n", offsetof(struct Type, _float), sizeof(float));
    fprintf(file, "offsetof(Type, _double) = %td, sizoef(double) = %td""\n", offsetof(struct Type, _double), sizeof(double));
    return file;
}

int main(int argc, char *argv[]) {
    struct Type type;
    fprintf(Print(stdout, &type), "\n");

    return 0;
}
