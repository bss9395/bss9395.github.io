/* Matrix_Multiplication.c
Author: BSS9395
Update: 2021-09-03T16:40:00+08@China-Guangdong-Zhanjiang+08
Design: Matrix Multiplication
Platform: Linux
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Matrix Multiplication
C[i][k] = ¦²_{j=0}^{y-1} A[i][j] * B[j][k]
*/
void Matrix_Multiplication(int x, int y, int z, double C[x][z], double A[x][y], double B[y][z]) {
    for (int i = 0; i < x; i += 1) {
        for (int k = 0; k < z; k += 1) {
            C[i][k] = 0.0;
            for (int j = 0; j < y; j += 1) {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }
}

/*
[1 2 3]   [ 7  8  9 10]   [ 74  80  86  92]
[4 5 6] ¡Á [11 12 13 14] = [173 188 203 218]
          [15 16 17 18]
*/
int main(int argc, char *argv[]) {
    char data[] =
        "2 3 4""\n"
        "\n"
        "1.0 2.0 3.0""\n"
        "4.0 5.0 6.0""\n"
        "\n"
        " 7.0  8.0  9.0 10.0""\n"
        "11.0 12.0 13.0 14.0""\n"
        "15.0 16.0 17.0 18.0""\n";
    FILE *data_in = fopen("in.txt", "wt");
    fprintf(data_in, "%s", data);
    fclose(data_in);

    ////////////////////////////////////

    FILE *in = fopen("in.txt", "rt");
    FILE *out = fopen("out.txt", "wt");

    while (true) {
        int x = 0;
        int y = 0;
        int z = 0;
        if (3 != fscanf(in, "%d %d %d", &x, &y, &z)) {
            break;
        }

        double A[x][y];
        double B[y][z];
        double C[x][z];
        for (int i = 0; i < x; i += 1) {
            for (int j = 0; j < y; j += 1) {
                fscanf(in, "%lf", &A[i][j]);
            }
        }
        for (int j = 0; j < y; j += 1) {
            for (int k = 0; k < z; k += 1) {
                fscanf(in, "%lf", &B[j][k]);
            }
        }

        Matrix_Multiplication(x, y, z, C, A, B);
        for (int i = 0; i < x; i += 1) {
            for (int k = 0; k < z; k += 1) {
                fprintf(out, "%lf ", C[i][k]);
            }
            fprintf(out, "\n");
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}
