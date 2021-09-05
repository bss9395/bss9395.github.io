/* Number_of_Unique_Paths.c
Author: BSS9395
Update: 2021-08-31T18:56:00+08@China-Guangdong-Zhanjiang+08
Design: Number of Unique Paths
Original: https://leetcode-cn.com/problems/unique-paths/solution/bu-tong-lu-jing-by-leetcode-solution-hzjf/
*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Combinatorics
downward  move: m - 1 times
rightward move: n - 1 times
Combination(m + n - 2, m - 1) = (m + n + 2)! / (m - 1)! / (n - 1)!
Combination(m + n - 2, m - 1) = (m + n - 2) ¡¤¡¤¡¤ (n) / (m - 1)!
*/
int Number_of_Unique_Paths_Combinatorics(int m, int n) {
    int numb = 1;
    // for (int x = n, y = 1; y <= m - 1; x += 1, y += 1) {
    for (int x = n, y = 1; y < m; x += 1, y += 1) {
        numb = numb * x / y;
    }
    return numb;
}

////////////////////////////////////////////////////////////////////////////////


/* Dynamic Equation
   n 1  2  3  4  5  6  7
   j 0  1  2  3  4  5  6
m i+--------------------+ m=3,n=7
1 0|01 01 01 01 01 01 01|
2 1|01 02 03 04 05 06 07|
3 2|01 03 06 10 15 21 28|
   +--------------------+ path=28
case 1: i == 0 || j == 0
        numb[i][j] = 1
case 2: 0 < i && 0 < j
        numb[i][j] = numb[i-1][j] + numb[i][j-1]
*/
int Number_of_Unique_Paths(int m, int n) {
    int numb[100][100];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || j == 0) {
                numb[i][j] = 1;
            }
            else {
                numb[i][j] = numb[i - 1][j] + numb[i][j - 1];
            }
        }
    }
    return numb[m - 1][n - 1];
}

int main(int argc, char *argv[]) {
    // int path = Number_of_Unique_Paths_Combinatorics(3, 7);
    int path = Number_of_Unique_Paths(3, 7);
    fprintf(stdout, "%d""\n", path);

    return 0;
}