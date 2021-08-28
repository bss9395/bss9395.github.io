/* Sprial_Matrix.cpp
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>

#define _Rank 6

void SpiralMatrix(long matrix[_Rank][_Rank], int rank) {
    int begI = 0;
    int begJ = 0;
    long number = 1;

    while (true) {
        if (rank <= 0) {
            break;
        }
        else if (rank == 1) {
            matrix[begI][begJ] = number;
            break;
        }

        for (int j = begJ; j < begJ + rank - 1; j += 1) {
            matrix[begI][j] = number;
            number += 1;
        }
        for (int i = begI; i < begI + rank - 1; i += 1) {
            matrix[i][begJ + rank - 1] = number;
            number += 1;
        }
        for (int j = begJ + rank - 1; begJ < j; j -= 1) {
            matrix[begI + rank - 1][j] = number;
            number += 1;
        }
        for (int i = begI + rank - 1; begI < i; i -= 1) {
            matrix[i][begJ] = number;
            number += 1;
        }

        begI += 1;
        begJ += 1;
        rank -= 2;
    }
}

void SpiralMatrix_Recursion(long matrix[_Rank][_Rank], int begI, int begJ, long number, int rank) {
    if (rank <= 0) {
        return;
    }
    else if (rank == 1) {
        matrix[begI][begJ] = number;
        return;
    }

    for (int j = begJ; j < begJ + rank - 1; j += 1) {
        matrix[begI][j] = number;
        number += 1;
    }
    for (int i = begI; i < begI + rank - 1; i += 1) {
        matrix[i][begJ + rank - 1] = number;
        number += 1;
    }
    for (int j = begJ + rank - 1; begJ < j; j -= 1) {
        matrix[begI + rank - 1][j] = number;
        number += 1;
    }
    for (int i = begI + rank - 1; begI < i; i -= 1) {
        matrix[i][begJ] = number;
        number += 1;
    }
    SpiralMatrix_Recursion(matrix, begI + 1, begJ + 1, number, rank - 2);
}

int main(int argc, char *argv[]) {
    long matrix[_Rank][_Rank];
    SpiralMatrix_Recursion(matrix, 0, 0, 1, _Rank);
    // SpiralMatrix(matrix, _Rank);

    for (int i = 0; i < _Rank; i += 1) {
        for (int j = 0; j < _Rank; j += 1) {
            fprintf(stdout, "%d\t", matrix[i][j]);
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");

    return 0;
}
