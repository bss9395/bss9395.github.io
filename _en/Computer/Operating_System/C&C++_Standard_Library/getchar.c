/* getchar.c
Author: BSS9395
Update: 2022-01-22T16:02:00+08@China-Guangdong-Zhanjiang+08
Design: C Standard Library: getchar
Encode: UTF-8
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char arr[100][100];
    int idx = 0;
    int ch = 0;
    while (1 == fscanf(stdin, "%[^,\n]", &arr[idx])) { // note: exclude [,\n]
        idx += 1;

        if (getchar() == '\n') {
            qsort(arr, idx, sizeof(*arr), strcmp);
            for (int i = 0; i < idx; i += 1) {
                if (i == 0) {
                    fprintf(stdout, "%s", arr[i]);
                } else {
                    fprintf(stdout, ",%s", arr[i]);
                }
            }
            fprintf(stdout, "\n");
            idx = 0;
        }
    }

    return 0;
}
