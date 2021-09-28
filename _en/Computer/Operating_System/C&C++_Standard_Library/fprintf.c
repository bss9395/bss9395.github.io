/* fprintf.c
Author: BSS9395
Update: 2021-09-28T22:58:00+08@China-Guangdong-Shenzhen+08
Design: C Standard Library fprintf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
    char c = 'c';
    short s = 1;
    int i = 2;
    long l = 3L;
    long long ll = 4LL;
    float f = 5.0F;
    double d = 6.0;
    long double ld = 7.0;
    char *str = (char *)"string";
    void *ptr = str;

    fprintf(stdout, "%c, %hi, %i, %li, %lli, %f, %lf, %Lf, %s, %p""\n", c, s, i, l, ll, f, d, ld, str, ptr);

    ////////////////////////////////////

    // warning: format double to int 
    fprintf(stderr, "%lf, %d, %lf""\n", d, d, d);  // wrong output: 6.000000, 0, 0.000000

    return 0;
}
