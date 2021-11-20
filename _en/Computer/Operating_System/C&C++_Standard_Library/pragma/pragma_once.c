/* pragma_once.c
Author: BSS9395
Update: 2021-11-21T00:05:00+08@China-Guangdong-Shenzhen+08
Design: C Standard Pragma: #pragma once
*/

#define Pragma_Once_c
#include "Pragma_Once.h"

int main(int argc, char *argv[]) {
    if (argc < 2 && Check(true, ELevel._Error, "argc < 2", NULL)) {
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "argc = %d, argv[1] = %s""\n", argc, argv[1]);

    return 0;
}
