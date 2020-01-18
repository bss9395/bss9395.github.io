/* Sprial_Matrix.cpp
*/

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
using namespace std;

static const int RANK = 6;

void SpiralMatrix(long long matrix[RANK][RANK], int begI, int begJ, long long number, int rank) {
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
	SpiralMatrix(matrix, begI + 1, begJ + 1, number, rank - 2);
}


void SpiralMatrix(long long matrix[RANK][RANK], int rank) {
	int begI = 0;
	int begJ = 0;
	long long number = 1;

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


int main(int argc, char *argv[]) {
	long long matrix[RANK][RANK];
	// SpiralMatrix(matrix, 0, 0, 1, RANK);
	SpiralMatrix(matrix, RANK);

	for (int i = 0; i < RANK; i += 1) {
		for (int j = 0; j < RANK; j += 1) {
			cerr << matrix[i][j] << "\t";
		}
		cerr << endl;
	}
	cerr << endl;

	return 0;
}
