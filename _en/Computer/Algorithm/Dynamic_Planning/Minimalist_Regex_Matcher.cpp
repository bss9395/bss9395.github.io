/* Minimalist_Regex_Matcher.cpp
Author: BSS9395
Update: 2022-01-23T00:53:00+08@China-Guangdong-Zhanjiang+08
Design: Minimalist Regex Matcher
Encode：UTF-8
Credit: https://leetcode.com/problems/regular-expression-matching/discuss/5684/9-lines-16ms-c-dp-solutions-with-explanations
Credit: https://leetcode.com/problems/regular-expression-matching/solution/
*/

#include <iostream>
#include <string>
#include <vector>
#include <functional>

typedef intptr_t iptr;

void Print_Plan(std::vector<std::vector<bool>> &plan, iptr rows, iptr cols, iptr row, iptr col) {
    fprintf(stderr, "row = %td, col = %td""\n", row, col);
    for (int i = 0; i <= rows; i += 1) {
        for (int j = 0; j <= cols; j += 1) {
            fprintf(stderr, "%s, ", (plan[i][j] == true) ? "true " : "false");
        }
        fprintf(stderr, "\n");
    }
}

////////////////////////////////////////////////////////////////////////////////

// method: tape recursion.
bool Match_Recursion(const std::string &literal, const std::string &pattern) {
    std::function<bool(const char *, const char *)> lambda = [&lambda](const char *lite, const char *patt) {
        if (patt[0] == '\0') {
            return (lite[0] == '\0');
        }

        bool prob = (lite[0] != '\0') && (lite[0] == patt[0] || patt[0] == '.');
        if (patt[1] != '\0' && patt[1] == '*') {
            return lambda(lite, patt += 2) || (prob && lambda(lite += 1, patt));
        } else {
            return (prob && lambda(lite += 1, patt += 1));
        }
    };
    return lambda(literal.data(), pattern.data());
}

// method: tape recursion.
bool Match_Recursion_Tracing(const std::string &literal, const std::string &pattern) {
    const char *lite = literal.data(), *patt = pattern.data();
    iptr rows = literal.size(), cols = pattern.size();
    std::vector<std::vector<bool>> trace(rows + 1, std::vector<bool>(cols + 1, false));
    std::function<bool(iptr, iptr)> lambda = [&lambda, &trace, lite, patt, rows, cols](iptr row, iptr col) -> bool {
        if (col == cols) {
            trace[row][col] = (row == rows);
            return trace[row][col];
        }

        bool prob = (row < rows) && (lite[row] == patt[col] || patt[col] == '.');
        if (col + 1 < cols && patt[col + 1] == '*') {
            trace[row][col] = lambda(row, col + 2) || (prob && lambda(row + 1, col));
        } else {
            trace[row][col] = (prob && lambda(row + 1, col + 1));
        }
        return trace[row][col];
    };
    lambda(0, 0);

    if (trace[0][0] != trace[rows][cols]) {
        throw std::string("[" + std::to_string(__LINE__) + "] trace[0][0] != trace[rows][cols]");
    }
    Print_Plan(trace, rows, cols, rows, cols);
    return trace[0][0];
}

////////////////////////////////////////////////////////////////////////////////

/* method: dynamic planning.
We define dp[i][j] to be true if s[1..i] matches p[1..j] and false otherwise. The state equations will be:
dp[i][j] = dp[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');      if p[j] != '*'.
dp[i][j] = dp[i][j - 2];                                           if p[j] == '*' and the pattern repeats 0 time.
dp[i][j] = dp[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.');  if p[j] == '*' and the pattern repeats at least 1 time.
*/
// method: dynamic planning
bool Match_Planning(const std::string &literal, const std::string &pattern) {
    const char *lite = literal.data() - 1, *patt = pattern.data() - 1;
    iptr rows = literal.size(), cols = pattern.size();
    std::vector<std::vector<bool>> plan(rows + 1, std::vector<bool>(cols + 1, false));
    plan[0][0] = true;
    for (iptr row = 0; row <= rows; row += 1) {
        for (iptr col = 1; col <= cols; col += 1) {
            if (patt[col] == '*') {
                plan[row][col] = plan[row][col - 2] || ((0 < row) && plan[row - 1][col] && (lite[row] == patt[col - 1] || patt[col - 1] == '.'));
            } else {
                plan[row][col] = (0 < row) && plan[row - 1][col - 1] && (lite[row] == patt[col] || patt[col] == '.');
            }
        }
    }
    Print_Plan(plan, rows, cols, rows, cols);
    return plan[rows][cols];
}

// method: dynamic planning
bool Match_Planning_Optimized(const std::string &literal, const std::string &pattern) {
    const char *lite = literal.data() - 1, *patt = pattern.data() - 1;
    iptr rows = literal.size(), cols = pattern.size();
    std::vector<bool> curr(cols + 1, false);
    for (iptr row = 0; row <= rows; row += 1) {
        bool prev = curr[0];
        curr[0] = (row == 0);
        for (iptr col = 1; col <= cols; col += 1) {
            bool temp = curr[col];
            if (patt[col] == '*') {
                curr[col] = curr[col - 2] || (curr[col] && (lite[row] == patt[col - 1] || patt[col - 1] == '.'));
            } else {
                curr[col] = prev && (lite[row] == patt[col] || patt[col] == '.');
            }
            prev = temp;
        }
    }
    return curr[cols];
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
    std::string literal = "aab";
    std::string pattern = "a*aab";
    bool matched = Match_Recursion(literal, pattern);
    // bool matched = Match_Recursion_Tracing(literal, pattern);
    // bool matched = Match_Planning(literal, pattern);
    // bool matched = Match_Planning_Optimized(literal, pattern);
    fprintf(stderr, "%s""\n", (matched == true) ? "matched" : "unmatched");

    return 0;
}
