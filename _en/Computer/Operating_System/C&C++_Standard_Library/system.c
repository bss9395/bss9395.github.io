/* system.c
Author: BSS9395
Update: 2021-10-30T11:33:00+08@China-Guangdong-Shenzhen+08
Design: C Standard Library: system
*/

/* C Standard Library
#include <stdlib.h>
int system (const char* command);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (system(NULL) != 0) {
        fprintf(stderr, "%s""\n", "command processor is available.");
    }

    int err = system("dir");
    fprintf(stderr, "%d, %s""\n", err, strerror(errno));

    return 0;
}
