/* Maximum_Sum_of_SubArrays.c
Author: BSS9395
Update: 2020-09-01T11:10:00+08@China-Guangdong-Zhanjiang+08
Design: Maximum Sum of SubArrays
Original: https://leetcode-cn.com/problems/maximum-subarray/solution/chun-csan-chong-fang-fa-bao-li-po-jie-tan-xin-suan/
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Brute Force
*/
int Maximum_Sum_of_SubArrays_Brute_Force(int arr[], int len) {
    int maxi = arr[0];
    int sum = 0;
    for (int i = 0; i < len; i += 1) {
        sum = 0;
        for (int j = i; j < len; j += 1) {
            sum += arr[j];
            if (sum > maxi) {
                maxi = sum;
            }
        }
    }
    return maxi;
}

/* Dynamic Equation
dp[i] represents the maximum sum of subarrays of arr[0..i].
case 1: i == 0
        dp[0] = arr[0];
case 2: 0 < i
        dp[i] = max(dp[i - 1] + arr[i], arr[i])
*/
int Maximum_Sum_of_SubArrays(int arr[], int len) {
    int maxi = arr[0];
    int sum = arr[0];
    for (int i = 1; i < len; i += 1) {
        sum = max(sum + arr[i], arr[i]);
        if (sum > maxi) {
            maxi = sum;
        }
    }
    return maxi;
}

int main(int argc, char *argv[]) {
    int arr[] = {
        1, -2, 3, 5, -3, 6, -1
    };
    int len = sizeof(arr) / sizeof(*arr);
    //int maxi = Maximum_Sum_of_SubArrays_Brute_Force(arr, len);
    int maxi = Maximum_Sum_of_SubArrays(arr, len);
    fprintf(stdout, "%d""\n", maxi);

    return 0;
}
