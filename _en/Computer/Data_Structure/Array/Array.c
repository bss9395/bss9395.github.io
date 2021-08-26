/* Array.c
Author: BSS9395
Update: 2020-08-26T09:37:00+08@China-Guangdong-Zhanjiang+08
Design: Multi-Dimensional Array
*/

#include <stdio.h>
#include <stdlib.h>

void Array_2_Dimension() {
    int row = 5;
    int col = 7;

    int *(*arr) = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i += 1) {
        arr[i] = (int *)malloc(col * sizeof(int));
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            arr[i][j] = i * col + j;
        }
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            fprintf(stdout, "%02d  ", arr[i][j]);
        }
        fprintf(stdout, "\n");
    }

    for (int i = 0; i < row; i += 1) {
        free(arr[i]);
    }
    free(arr);
}

int main(int argc, char *argv[]) {
    Array_2_Dimension();

    return 0;
}