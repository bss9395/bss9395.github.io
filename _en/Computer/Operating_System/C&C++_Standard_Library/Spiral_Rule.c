/* Spiral_Rule.c
Author: BSS9395
Update: 2021-09-29T20:52:00+08@China-Guangdong-Shenzhen+08
Design: C/C++ Clockwise Rule
Credit: http://c-faq.com/decl/spiral.anderson.html
*/

#include <stdio.h>

typedef char *(*Type)(char *);

char *Return(char *param) {
    return param;
}

char *(*Function(char *(*param)(char *)))(char *) {
    fprintf(stdout, "%p""\n", param);

    return param;
}

int main(int argc, char *argv[]) {
    Type param = Return;
    Function(param);

    return 0;
}
