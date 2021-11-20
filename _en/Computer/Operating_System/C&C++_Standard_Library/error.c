/* error.c
Author: BSS9395
Update: 2021-11-03T23:03:00+08@China-Guangdong-Shenzhen+08
Design: C Standard Pragma: #error
*/

#ifndef _WIN32
#error "Target Windows 32bit or 64bit version."
#endif // _WIN32

#ifndef _WIN64
#error "Target Windows 64bit version."
#endif // _WIN64


#include <stdio.h>

int main(int argc, char *argv[]) {
    fprintf(stderr, "%s""\n", __FUNCTION__);

    return 0;
}
