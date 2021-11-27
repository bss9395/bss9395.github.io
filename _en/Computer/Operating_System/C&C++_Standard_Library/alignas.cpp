/* alignas.cpp
Author: BSS9395
Update: 2021-11-27T21:02:00+08@China-Guangdong-Shenzhen+08
Design: C++ Standard Keyword: alignas
*/

#include <iostream>

typedef intptr_t iptr;

struct Type {
    char _char;     //  0:1+3
    int _int;       //  4:4+0
    iptr _iptr;     //  8:8+0; 64bit
    float _float;   // 16:4+0
    double _double; // 24:8+0
};                  // 32:0+0

// alignas(2^N) >= alignas()
struct alignas(16) Aligned { /* affect the memory layout of Aligned as a whole */
    alignas(4) char _char;     //  0:1+3
    alignas(4) int _int;       //  4:4+0
    alignas(8) iptr _iptr;     //  8:8+0; 64bit
    alignas(4) float _float;   // 16:4+0
    alignas(8) double _double; // 24:8+0
};                  // 32:0+0

// #pragma pack(2^N)
#pragma pack(2)              /* affect the memory layout of inside and outside Pack */
struct Pack {
    char _char;     //  0:1+1
    int _int;       //  2:4+0
    iptr _iptr;     //  6:8+0; 64bit
    float _float;   // 14:4+0
    double _double; // 18:8+0
};                  // 26:0+0
#pragma pack()               /* restore default memory layout */

FILE* Print(FILE *file, const Type& type) {
    // alignof(Type) == std::alignment_of<Type>::value
    fprintf(file, "sizeof(Type) = %td, alignof(Type) = %td""\n", sizeof(Type), alignof(Type));
    fprintf(file, "addressof(type) %% alignof(Type) = %td""\n", ((iptr)std::addressof(type) % alignof(Type)));
    fprintf(file, "offsetof(Type, _char) = %td, sizoef(char) = %td, alignof(char) = %td""\n", offsetof(Type, _char), sizeof(char), alignof(char));
    fprintf(file, "offsetof(Type, _int) = %td, sizoef(int) = %td, alignof(int) = %td""\n", offsetof(Type, _int), sizeof(int), alignof(int));
    fprintf(file, "offsetof(Type, _iptr) = %td, sizoef(iptr) = %td, alignof(iptr) = %td""\n", offsetof(Type, _iptr), sizeof(iptr), alignof(iptr));
    fprintf(file, "offsetof(Type, _float) = %td, sizoef(float) = %td, alignof(float) = %td""\n", offsetof(Type, _float), sizeof(float), alignof(float));
    fprintf(file, "offsetof(Type, _double) = %td, sizoef(double) = %td, alignof(double) = %td""\n", offsetof(Type, _double), sizeof(double), alignof(double));
    return file;
}

FILE* Print(FILE *file, const Aligned& aligned) {
    fprintf(file, "sizeof(Aligned) = %td, alignof(Aligned) = %td""\n", sizeof(Aligned), alignof(Aligned));
    fprintf(file, "addressof(aligned) %% alignof(Aligned) = %td""\n", ((iptr)std::addressof(aligned) % alignof(Aligned)));
    fprintf(file, "offsetof(Aligned, _char) = %td, sizoef(char) = %td, alignof(char) = %td""\n", offsetof(Aligned, _char), sizeof(char), alignof(char));
    fprintf(file, "offsetof(Aligned, _int) = %td, sizoef(int) = %td, alignof(int) = %td""\n", offsetof(Aligned, _int), sizeof(int), alignof(int));
    fprintf(file, "offsetof(Aligned, _iptr) = %td, sizoef(iptr) = %td, alignof(iptr) = %td""\n", offsetof(Aligned, _iptr), sizeof(iptr), alignof(iptr));
    fprintf(file, "offsetof(Aligned, _float) = %td, sizoef(float) = %td, alignof(float) = %td""\n", offsetof(Aligned, _float), sizeof(float), alignof(float));
    fprintf(file, "offsetof(Aligned, _double) = %td, sizoef(double) = %td, alignof(double) = %td""\n", offsetof(Aligned, _double), sizeof(double), alignof(double));
    return file;
}

FILE* Print(FILE *file, const Pack& pack) {
    fprintf(file, "sizeof(Pack) = %td, alignof(Pack) = %td""\n", sizeof(Pack), alignof(Pack));
    fprintf(file, "addressof(pack) %% alignof(Pack) = %td""\n", ((iptr)std::addressof(pack) % alignof(Pack)));
    fprintf(file, "offsetof(Pack, _char) = %td, sizoef(char) = %td, alignof(char) = %td""\n", offsetof(Pack, _char), sizeof(char), alignof(char));
    fprintf(file, "offsetof(Pack, _int) = %td, sizoef(int) = %td, alignof(int) = %td""\n", offsetof(Pack, _int), sizeof(int), alignof(int));
    fprintf(file, "offsetof(Pack, _iptr) = %td, sizoef(iptr) = %td, alignof(iptr) = %td""\n", offsetof(Pack, _iptr), sizeof(iptr), alignof(iptr));
    fprintf(file, "offsetof(Pack, _float) = %td, sizoef(float) = %td, alignof(float) = %td""\n", offsetof(Pack, _float), sizeof(float), alignof(float));
    fprintf(file, "offsetof(Pack, _double) = %td, sizoef(double) = %td, alignof(double) = %td""\n", offsetof(Pack, _double), sizeof(double), alignof(double));
    return file;
}

int main(int argc, char *argv[]) {
    Type type;
    Aligned aligned;
    Pack pack;

    fprintf(Print(stdout, type), "\n");
    fprintf(Print(stdout, aligned), "\n");
    fprintf(Print(stdout, pack), "\n");

    return 0;
}
