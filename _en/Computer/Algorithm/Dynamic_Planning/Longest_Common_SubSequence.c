/* Longest_Common_SubSequence.c
Author: BSS9395
Update: 2020-08-30T18:27:00+08@China-Guangdong-Zhanjiang+08
Design: Longest Common SubSequence, Longest Common SubString
Original: https://zhuanlan.zhihu.com/p/68409952
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[1024][1024];

typedef struct _Char {
    char _stri[64];
    int _leng;
} Char;

typedef struct _Trace {
    Char _trace[64];
    int _numb;
} Trace;
Trace trace = { ._numb = 0 };

////////////////////////////////////////////////////////////////////////////////

int Longest_Common_SebSequence_Recursion(char *strX, int i, char *strY, int j) {
    if (i == 0 || j == 0) {
        return 0;
    }
    if (strX[i - 1] == strY[j - 1]) {
        return Longest_Common_SebSequence_Recursion(strX, i - 1, strY, j - 1) + 1;
    }
    else {
        return max(Longest_Common_SebSequence_Recursion(strX, i - 1, strY, j), Longest_Common_SebSequence_Recursion(strX, i, strY, j - 1));
    }
}

////////////////////////////////////////////////////////////////////////////////

/* state transition equation: Longest Common SubSequence
dp[i][j] represents the length of longest sequence of strX[0..i-1] and strY[0..j-1]
case 1: i == 0 || j == 0
        dp[i][j] = 0
case 2: strX[i-1] == strY[j-1]
        dp[i][j] = dp[i-1][j-1] + 1
case 3: strX[i-1] != strY[j-1]
        dp[i][j] = max(dp[i-1][j], dp[i][j-1])
*/
int Longest_Common_SubSequence(char *strX, int lenX, char *strY, int lenY) {
    // table has (1 + lenX) rows and (1 + lenY) columns.
    for (int i = 0; i <= lenX; i += 1) {
        for (int j = 0; j <= lenY; j += 1) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            }
            else if (strX[i - 1] == strY[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    return table[lenX][lenY];
}

/* table: Longest Common SubSequence
        strY        |  strY
      0 1 2 3 4 5 6 |0 1 2 3 4 5 6
        b d c a b a |  b d c a b a
     +--------------+--------------+
  0  |0 0 0 0 0 0 0 |0 0 0 0 0 0 0 |
s 1 a|0 0 0 0[1]1 1 |0 0 0 0[1]1 1 |
t 2 b|0[1]1 1 1[2]2 |0[b]1 1 1[2]2 | bcba
r 3 c|0 1 1[2]2 2 2 |0 1 1[c]2 2 2 | bcab
X 4 b|0 1 1 2 2[3]3 |0 1 1 2 2[b]3 | bdab
  5 d|0 1[2]2 2 3 3 |0 1[d]2 2 3 3 |
  6 a|0 1 2 2[3]3[4]|0 1 2 2[a]3[a]|
  7 b|0 1 2 2 3[4]4 |0 1 2 2 3[b]4 |
     +--------------+--------------+ longest=4
*/
void Traceback_SubSequence_Recursion(Char lcs, int len, char *strX, int i, char *strY, int j) {
    while (0 < i && 0 < j) {
        if (strX[i - 1] == strY[j - 1]) {
            lcs._stri[lcs._leng] = strX[i - 1];
            lcs._leng += 1;
            i -= 1;
            j -= 1;
        }
        else {
            if (table[i - 1][j] > table[i][j - 1]) {
                i -= 1;
            }
            else if (table[i - 1][j] < table[i][j - 1]) {
                j -= 1;
            }
            else {
                Traceback_SubSequence_Recursion(lcs, len, strX, i - 1, strY, j);
                Traceback_SubSequence_Recursion(lcs, len, strX, i, strY, j - 1);
                return;
            }
        }
    }

    if (lcs._leng == len) {
        char *rev = trace._trace[trace._numb]._stri;
        for (int i = lcs._leng - 1; 0 <= i; i -= 1) {
            rev[0] = lcs._stri[i];
            rev += 1;
        }
        rev[0] = '\0';
        trace._numb += 1;
    }
}

////////////////////////////////////////////////////////////////////////////////

/* state transition equation: Longest Common SubString
dp[i][j] represents the length of longest sequence of strX[0..i-1] and strY[0..j-1]
case 1: i == 0 || j == 0
        dp[i][j] = 0
case 2: strX[i-1] == strY[j-1]
        dp[i][j] = dp[i-1][j-1] + 1
case 3: strX[i-1] != strY[j-1]
        dp[i][j] = 0
*/
int Longest_Common_SubString(char *strX, int lenX, char *strY, int lenY) {
    int longest = 0;
    for (int i = 0; i <= lenX; i += 1) {
        for (int j = 0; j <= lenY; j += 1) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            }
            else if (strX[i - 1] == strY[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                if (table[i][j] > longest) {
                    longest = table[i][j];
                }
            }
            else {
                table[i][j] = 0;
            }
        }
    }
    return longest;
}

/* table: Longest Common SubString
        strY        |  strY
      0 1 2 3 4 5 6 |0 1 2 3 4 5 6
        b d c a b a |  b d c a b a
     +--------------+--------------+
  0  |0 0 0 0 0 0 0 |0 0 0 0 0 0 0 |
s 1 a|0 0 0 0[1]0 1 |0 0 0 0[a]0 1 | ab
t 2 b|0 1 0 0 0[2]0 |0 1 0 0 0[b]0 |
r 3 c|0 0 0 1 0 0 0 |0 0 0 1 0 0 0 |
X 4 b|0[1]0 0 0 1 0 |0[b]0 0 0 1 0 | bd
  5 d|0 0[2]0 0 0 0 |0 0[d]0 0 0 0 |
  6 a|0 0 0 0[1]0 1 |0 0 0 0[a]0 1 | ab
  7 b|0 1 0 0 0[2]0 |0 1 0 0 0[b]0 |
     +--------------+--------------+ longest=2
*/
void Traceback_SubString(int len, char *strX, int lenX, char *strY, int lenY) {
    for (int i = 0; i <= lenX; i += 1) {
        for (int j = 0; j <= lenY; j += 1) {
            if (table[i][j] == len) {
                char *beg = trace._trace[trace._numb]._stri;
                char *str = &strX[i - len];
                for (int i = 0; i < len; i += 1) {
                    beg[i] = str[i];
                }
                beg[len] = '\0';
                trace._numb += 1;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
    char *strX = (char *)"abcbdab";
    char *strY = (char *)"bdcaba";
    int lenX = strlen(strX);
    int lenY = strlen(strY);
    int longest = 0;

    ////////////////////////////////////

    longest = Longest_Common_SebSequence_Recursion(strX, lenX, strY, lenY);
    fprintf(stdout, "%d""\n", longest);

    ////////////////////////////////////

    longest = Longest_Common_SubSequence(strX, lenX, strY, lenY);
    fprintf(stdout, "%d""\n", longest);

    Char lcs = { ._leng = 0 };
    trace._numb = 0;
    Traceback_SubSequence_Recursion(lcs, longest, strX, lenX, strY, lenY);
    for (int i = 0; i < trace._numb; i += 1) {
        fprintf(stdout, "%s""\n", trace._trace[i]._stri);
    }

    ////////////////////////////////////

    longest = Longest_Common_SubString(strX, lenX, strY, lenY);
    fprintf(stdout, "%d""\n", longest);

    trace._numb = 0;
    Traceback_SubString(longest, strX, lenX, strY, lenY);
    for (int i = 0; i < trace._numb; i += 1) {
        fprintf(stdout, "%s""\n", trace._trace[i]._stri);
    }

    return 0;
}
