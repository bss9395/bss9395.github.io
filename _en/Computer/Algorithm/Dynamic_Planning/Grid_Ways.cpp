/* Grid_Ways.cpp
Author: BSS9395
Update: 2023-08-14T15:05:00+08@China-Guangdong-Zhanjiang+08
Design: Ways of Grid
*/

#define _CRT_SECURE_NO_WARNINGS  
#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

class Grid {
public:
    static auto _Ways_Recursion(int m, int n) -> int {
        static function<int(int, int, int, int)> __Ways_Recursion = [](int i, int j, int m, int n) -> int {
            if (m == i || n == j) {
                return 1;
            }
            return __Ways_Recursion(i + 1, j, m, n) + __Ways_Recursion(i, j + 1, m, n);
        };

        return __Ways_Recursion(1, 1, m, n);
    }

    static auto _Ways_Dynamic_Planning(int m, int n) -> int {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i += 1) {
            for (int j = 1; j <= n; j += 1) {
                if (i == 1 && j == 1) {
                    dp[i][j] = 1;
                }
                else if (i == 1) {
                    dp[i][j] = dp[i][j - 1];
                }
                else if (j == 1) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i][j - 1] + dp[j - 1][i];
                }
            }
        }
        return dp[m][n];
    }

    static auto _Ways_Combination(int m, int n) -> int {
        /*
        * C_{m + n}^{m} = (m + n)! / (n! * m!) = [(m + 1) ¡¤¡¤¡¤ (m + n)] / n!
        * ways = C_{m -1 + n - 1}^{m - 1}
        */
        int numerator = 1;
        int denominator = 1;
        for (int i = 1; i <= (n - 1); i += 1) {
            numerator *= ((m - 1) + i);
            denominator *= i;
        }
        return (numerator / denominator);
    }

public:
    static auto _Test_Ways_Recursion() -> void {
        int ways = _Ways_Recursion(2, 2);
        fwprintf(stdout, L"ways = %d\n", ways);
    }

    static auto _Test_Ways_Dynamic_Planning() -> void {
        int ways = _Ways_Dynamic_Planning(2, 2);
        fwprintf(stdout, L"ways = %d\n", ways);
    }

    static auto _Test_Ways_Combination() -> void {
        int ways = _Ways_Combination(2, 2);
        fwprintf(stdout, L"ways = %d\n", ways);
    }
};


int main() {
    // Grid::_Test_Ways_Recursion();
    // Grid::_Test_Ways_Dynamic_Planning();
    Grid::_Test_Ways_Combination();

    return 0;
}
