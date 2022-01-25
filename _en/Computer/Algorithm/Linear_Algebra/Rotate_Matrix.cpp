/* Rotate_Matrix.cpp
Author: BSS9395
Update: 2022-01-25T17:00:00+08@China-Guangdong-Zhanjiang+08
Design: Rotate Matrix
Encode: UTF-8
Credit: https://leetcode-cn.com/problems/rotate-image/solution/xuan-zhuan-tu-xiang-by-leetcode-solution-vu3m/
*/

#include <iostream>
#include <string>
#include <vector>
typedef intptr_t iptr;

struct EMark {
    typedef const char *Mode;
    static inline Mode _Matrix = "Matrix";
    static inline Mode _Sheet = "Sheet";
    static inline Mode _CCW_90 = "CCW_90";
    static inline Mode _CW_90 = "CW_90";
};

void Print_Array(std::vector<std::vector<iptr>>& array, EMark::Mode mode = EMark::_Sheet) {
    if (mode == EMark::_Sheet) {
        for (iptr row = 0, rows = array.size(); row < rows; row += 1) {
            for (iptr col = 0, cols = array[0].size(); col < cols; col += 1) {
                fprintf(stderr, "%2td, ", (iptr)array[row][col]);
            }
            fprintf(stderr, "\n");
        }
    } else if (mode == EMark::_Matrix) {
        // note: optimization should be on the level of operating system.
        for (iptr row = array.size() - 1; 0 <= row; row -= 1) {
            for (iptr col = 0, cols = array[0].size(); col < cols; col += 1) {
                fprintf(stderr, "%2td, ", (iptr)array[row][col]);
            }
            fprintf(stderr, "\n");
        }
    }
    fprintf(stderr, "========================================\n");
}

////////////////////////////////////////////////////////////////////////////////

/* method: Mapping
// definition of sheet
00, 01, 02,
10, 11, 12,
20, 21, 22,
30, 31, 32.

// CCW rotate 90
02, 12, 22, 32,
01, 11, 21, 31,
00, 10, 20, 30.
rotated[cols - 1 - col][row] = matrix[row][col];

// CW  rotate 90
30, 20, 10, 00,
31, 21, 11, 01,
32, 22, 12, 02.
rotated[col][rows - 1 - row] = matrix[row][col];
================================================================================
// definition of matrix
30, 31, 32.
20, 21, 22,
10, 11, 12,
00, 01, 02,

// CCW rotate 90
32, 22, 12, 02.
31, 21, 11, 01,
30, 20, 10, 00,
rotated[col][rows - 1 - row] = matrix[row][col];
rotated[rows - 1 - row][cols - 1 - col] = matrix[col][rows - 1 - row];
rotated[cols - 1 - col][row] = matrix[rows - 1 - row][cols - 1 - col];
rotated[row][col] = matrix[cols - 1 - col][row];

// CW  rotate 90
00, 10, 20, 30.
01, 11, 21, 31,
02, 12, 22, 32,
rotated[cols - 1 - col][row] = matrix[row][col];
*/
// method: Mapping
std::vector<std::vector<iptr>> Rotate_Sheet(std::vector<std::vector<iptr>>& matrix, EMark::Mode mode = EMark::_CCW_90) {
    iptr rows = matrix.size();
    iptr cols = matrix[0].size();
    std::vector<std::vector<iptr>> rotated(cols, std::vector<iptr>(rows, 0));
    if (mode == EMark::_CCW_90) {
        for (iptr row = 0; row < rows; row += 1) {
            for (iptr col = 0; col < cols; col += 1) {
                rotated[cols - 1 - col][row] = matrix[row][col]; // CCW rotate 90.
            }
        }
    } else if (mode = EMark::_CW_90) {
        for (iptr row = 0; row < rows; row += 1) {
            for (iptr col = 0; col < cols; col += 1) {
                rotated[col][rows - 1 - row] = matrix[row][col]; // CW  rotate 90.
            }
        }
    }
    return rotated;
}

// method: Mapping
std::vector<std::vector<iptr>> Rotate_Matrix(std::vector<std::vector<iptr>>& matrix, EMark::Mode mode = EMark::_CCW_90) {
    iptr rows = matrix.size();
    iptr cols = matrix[0].size();
    std::vector<std::vector<iptr>> rotated(cols, std::vector<iptr>(rows, 0));
    if (mode = EMark::_CCW_90) {
        for (iptr row = 0; row < rows; row += 1) {
            for (iptr col = 0; col < cols; col += 1) {
                rotated[col][rows - 1 - row] = matrix[row][col]; // CCW rotate 90.
            }
        }
    } else if (mode = EMark::_CW_90) {
        for (iptr row = 0; row < rows; row += 1) {
            for (iptr col = 0; col < cols; col += 1) {
                rotated[cols - 1 - col][row] = matrix[row][col]; // CW  rotate 90.
            }
        }
    }
    return rotated;
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
    std::vector<std::vector<iptr>> matrix = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {9, 10, 11}
    };

    Print_Array(matrix, EMark::_Matrix);
    auto rotated = Rotate_Matrix(matrix, EMark::_CCW_90);
    Print_Array(rotated, EMark::_Matrix);

    return 0;
}
