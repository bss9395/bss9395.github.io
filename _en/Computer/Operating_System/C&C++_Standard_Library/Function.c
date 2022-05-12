/* Function.c
Author: BSS9395
Update: 2022-05-03T12:30:00+08@China-Shanghai+08
Design: C Language Feature: Function
*/

#include <stdio.h>
#include <stdint.h>

typedef intptr_t iptr;

void function(iptr param) {
    fprintf(stdout, "param = %td""\n", (iptr)param);
}

int main(int argc, char* argv[]) {
    function(123);
    (*function)(234);
    (&function)(345);

    fprintf(stdout, "function = %p, *function = %p, &function = %p""\n", function, *function, &function);

    return 0;
}
