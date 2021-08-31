/* qsort.c
Author: BSS9395
Update: 2020-08-31T10:30:00+08@China-Guangdong-Zhanjiang+08
Design: qsort
Original: https://cplusplus.com/reference/cstdlib/qsort/?kw=qsort
*/

/* qsort
#include <stdlib.h>
void qsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *lhs, const void *rhs) {
    return (*((int *)lhs) - *((int *)rhs));
}

int main(int argc, char *argv[]) {
    long arr[] = {
        9, 0, 8, 2, 6, 1, 3, 4, 5, 7
    };
    int m = sizeof(arr) / sizeof(*arr);

    qsort(arr, m, sizeof(*arr), compare);
    for (int i = 0; i < m; i += 1) {
        fprintf(stdout, "%d ", arr[i]);
    }
    fprintf(stdout, "\n");

    ////////////////////////////////////

    char str[][1024] = {
        "abc",
        "cba",
        "adb",
        "bbgg"
    };
    int n = sizeof(str) / sizeof(*str);

    qsort(str, n, sizeof(*str), strcmp);
    for (int i = 0; i < n; i++) {
        printf("%s""\n", str[i]);
    }
    fprintf(stdout, "\n");

    return 0;
}
