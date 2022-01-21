/* Param_Arg.c
Author: BSS9395
Update: 2022-01-22T02:45:00+08@China-Guangdong-Zhanjiang+08
Encode: UTF-8
Design: Variadic Function Parameters
*/

/*
#define Param_Para(type)         Param_Para((void *)&type, sizeof(type))
#define Param_Arg(params, Type)  ((Type *)(Param_Numb(params), params->_params += sizeof(Type)))[-1]
#define Param_Set(params)        params->_copy = params->_numb, params->_params = NULL
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef intptr_t iptr;
#define Incr(type) ((sizeof(type) + sizeof(iptr) - 1) & ~(sizeof(iptr) - 1)

////////////////////////////////////////////////////////////////////////////////

typedef struct Params {
    char *_buffer;
    iptr _numb;
    char *_params;
    iptr _copy;
    struct Params *(*Param_Para)(void *, iptr);
} Params;

Params *Param_Para(void *type, iptr size) {
    static char buffer[1024];
    static Params params = {
        ._buffer = buffer,
        ._numb = 0,
        ._params = NULL,
        ._copy = 0,
        .Param_Para = &Param_Para
    };
    if (params._copy == params._numb) {
        params._numb = 0;
        params._params = params._buffer;
        params._copy = 0;
    }
    memcpy((void *)params._params, (void *)type, size);
    params._params += size;
    params._numb += 1;
    return &params;
}

void Param_Numb(Params *params) {
    if (params->_copy <= 0 || params->_params == NULL) {
        params->_params = params->_buffer;
        params->_copy = 0;
    } else if (params->_numb <= params->_copy) {
        // throw std::string("[" + std::to_string(__LINE__) + "] params->_numb <= params->_copy");
        fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, "params->_numb <= params->_copy");
        exit(EXIT_FAILURE);
    }
    params->_copy += 1;
}

#define Param_Para(type)         Param_Para((void *)&type, sizeof(type))
#define Param_Arg(params, Type)  ((Type *)(Param_Numb(params), params->_params += sizeof(Type)))[-1]
#define Param_Set(params)        params->_copy = params->_numb, params->_params = NULL

////////////////////////////////////////////////////////////////////////////////

void Function(Params *params) {
    int i = Param_Arg(params, int);
    double d = Param_Arg(params, double);
    const char *p = Param_Arg(params, const char *);
    // Param_Set(params);
    fprintf(stderr, "i = %td, d = %lf, p = %s""\n", (iptr)i, d, p);
}

int main(int argc, char *argv[]) {
    int i = 123;
    double d = 456.123;
    const char *p = "string";
    Function(Param_Para(i)->Param_Para(d)->Param_Para(p));

    return 0;
}
