/* Permutation_of_Number.cpp
Author: BSS9395
Update: 2022-09-30T14:21:00+08@China-Guangdong-Zhanjiang+08
Design: Permutation of Number
*/


/* output
1 3 6 10
2 5 9
4 8
7
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void Permutation_of_Number(int rows) {
	int numb = 1;
	vector<vector<int>> matrix(rows, vector<int>(rows, 0));
	for (int row = 0; row < rows; row += 1) {
		for (int col = 0; col <= row; col += 1) {
			matrix[row - col][col] = numb;
			numb += 1;
		}
	}

	for (int row = 0; row < rows; row += 1) {
		for (int col = 0; col < rows - row; col += 1) {
			fprintf(stdout, "%d ", matrix[row][col]);
		}
		fprintf(stdout, "\n");
	}
}

int main(int argc, char* argv[]) {
	int rows = 4;
	Permutation_of_Number(rows);

	return 0;
}
