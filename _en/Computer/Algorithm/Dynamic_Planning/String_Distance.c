/* String_Distance.c
Author: BSS9395
Update: 2021-09-03T14:57:00+08@China-Guangdong-Zhanjiang+08
Design: String Distance
Platform: Linux
Original: https://blog.csdn.net/shizheng163/article/details/50988023
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Dynamic Equation
dp[0][j] represents the Distance from "" to strY[0..j-1]. Insertion.
dp[i][0] represents the Distance from strX[0..i-1] to "". Deletion.
dp[i][j] represents the Distance between strX[0..i-1] and strY[0..j-1].
dp[i][j-1]+1 means inserting strY[i][j-1].
dp[i-1][j]+1 means deleting strX[i-1][j].
dp[i-1][j-1]+1 means revising strX[i-1] or strY[j-1].
----------------------------------------
case 1: i == 0
        dp[0][j] = j
case 2: j == 0
        dp[i][0] = i
case 3: 0 < i && 0 < j
        case 31: strX[i-1] == strY[j-1]      // no need to revise strX[i-1] and strY[j-1].
                 dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]+1, dp[i][j-1]+1)
        case 32: strX[i-1] != strY[j-1]      // have to revise strX[i-1] to strY[j-1].
                 dp[i][j] = min(dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1)
*/
int String_Distance(char *strX, int lenX, char *strY, int lenY) {
    int insert_cost = 1;
    int delete_cost = 1;
    int revise_cost = 1;
    int dp[lenX + 1][lenY + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= lenX; i += 1) {
        dp[i][0] = i * delete_cost;
    }
    for (int j = 1; j <= lenY; j += 1) {
        dp[0][j] = j * insert_cost;
    }

    for (int i = 1; i <= lenX; i += 1) {
        for (int j = 1; j <= lenY; j += 1) {
            if (strX[i - 1] == strY[j - 1]) {
                dp[i][j] = (int)fmin(dp[i - 1][j - 1], (int)fmin(dp[i - 1][j] + delete_cost, dp[i][j - 1] + insert_cost));
            }
            else {
                dp[i][j] = (int)fmin(dp[i - 1][j - 1] + revise_cost, (int)fmin(dp[i - 1][j] + delete_cost, dp[i][j - 1] + insert_cost));
            }
        }
    }
    return dp[lenX][lenY];
}

/* String Distance
       s t r Y
       0 1 2 3 4 5 6
         b e a u t y
     +---------------⇒ Insertion
  0  |[0]1 2 3 4 5 6 |
s 1 b| 1[0|1]2 3 4 5 |  "batyu"   => "beatyu"
t 2 a| 2 1 1[1|2]3 4 |  "beatyu"  => "beautyu"
r 3 t| 3 2 2 2 2[2]3 |
X 4 y| 4 3 3 3 3 3[2]|  "beautyu" => "beauty"
  5 u| 5 4 4 4 3 4[3]|
     ⇓---------------⇘
     Deletion         Revision
*/
int main(int argc, char *argv[]) {
    char *strX = (char *)"batyu";
    char *strY = (char *)"beauty";
    int lenX = (int)strlen(strX);
    int lenY = (int)strlen(strY);

    int dist = String_Distance(strX, lenX, strY, lenY);
    fprintf(stdout, "%d""\n", dist);

    return 0;
}
