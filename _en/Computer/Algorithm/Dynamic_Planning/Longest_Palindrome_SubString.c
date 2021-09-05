/* Longest_Palindrome_SubString.c
Author: BSS9395
Update: 2021-08-26T18:43:00+08@China-Guangdong-Zhanjiang+08
Design: Longest Palindrome SubString Extraction
Original: https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
Original: https://writings.sh/post/algorithm-longest-palindromic-substring#%E4%B8%AD%E5%BF%83%E6%89%A9%E5%B1%95%E6%96%B9%E6%B3%95
Original: https://www.cnblogs.com/Lyush/p/3221503.html
Original: https://blog.csdn.net/kangroger/article/details/37742639
*/


#if 0
char *Brute_Force(const char *str);
char *Axial_Symmetry(const char *str);
char *Dynamic_Planning_1_Dimension(const char *str);
char *Dynamic_Planning_2_Dimension(const char *str);
char *Extended_Palindrome(char *str);
#endif

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _String {
    char *_head;
    long _leng;
} String;

////////////////////////////////////////////////////////////////////////////////

char *Brute_Force(char *str) {
    int len = strlen(str);

    String palindrome = (String) { ._head = NULL, ._leng = 1 };
    int left = 0;
    int right = 0;
    for (int head = 0; head < len; head += 1) {
        for (int tail = head; tail < len; tail += 1) {
            left = head;
            right = tail;
            while (left < right && str[left] == str[right]) {
                left += 1;
                right -= 1;
            }
            if (left >= right && tail - head + 1 > palindrome._leng) {
                palindrome._head = &str[head];
                palindrome._leng = tail - head + 1;
            }
        }
    }

    ////////////////////////////////////

    if (1 < palindrome._leng) {
        char *ret = (char *)malloc((palindrome._leng + 1) * sizeof(char));
        int i = 0;
        for (; i < palindrome._leng; i += 1) {
            ret[i] = palindrome._head[i];
        }
        ret[i] = '\0';
        return ret;
    }
    return NULL;
}

////////////////////////////////////////////////////////////////////////////////

char *Axial_Symmetry(char *str) {
    int len = strlen(str);

    String palindrome = (String) { ._head = NULL, ._leng = 1 };
    int left = 0;
    int right = 0;
    for (int axis = 0; axis < len; axis += 1) {
        // case Odd
        for (left = axis, right = axis; 0 <= left && right < len && str[left] == str[right]; left -= 1, right += 1);
        if (right - (left + 1) > palindrome._leng) {
            palindrome._head = &str[left + 1];
            palindrome._leng = right - (left + 1);
        }

        // case Even
        for (left = axis, right = axis + 1; 0 <= left && right < len && str[left] == str[right]; left -= 1, right += 1);
        if (right - (left + 1) > palindrome._leng) {
            palindrome._head = &str[left + 1];
            palindrome._leng = right - (left + 1);
        }
    }

    ////////////////////////////////////

    if (1 < palindrome._leng) {
        char *ret = (char *)malloc((palindrome._leng + 1) * sizeof(char));
        int i = 0;
        for (; i < palindrome._leng; i += 1) {
            ret[i] = palindrome._head[i];
        }
        ret[i] = '\0';
        return ret;
    }
    return NULL;
}

////////////////////////////////////////////////////////////////////////////////

/* Dynamic_Planning_1_Dimension
       ¡ýhead[tail-1]  ¡ýtail-1
  ¡ýhead[tail-1]-1          ¡ýtail
  ¡ýhead[tail]              ¡ýtail
----------------------------------------
       i    b    b    i
  g    i    b    b    i    g
*/
char *Dynamic_Planning_1_Dimension(char *str) {
    int len = strlen(str);
    int *head = (int *)malloc(len * sizeof(int));

    String palindrome = (String) { ._head = NULL, ._leng = 1 };
    head[0] = 0;
    for (int tail = 1; tail < len; tail += 1) {
        if (0 < head[tail - 1] && str[tail] == str[head[tail - 1] - 1]) {  // state transition equation.
            head[tail] = head[tail - 1] - 1;
        }
        else {
            int left = head[tail - 1];
            int right = tail;
            int fore = left;
            while (left < right) {
                if (str[left] != str[right]) {
                    left += 1;
                    right = tail;
                    fore = left;
                }
                else {
                    left += 1;
                    right -= 1;
                }
            }
            head[tail] = fore;
        }

        if (tail - head[tail] + 1 > palindrome._leng) {
            palindrome._head = &str[head[tail]];
            palindrome._leng = tail - head[tail] + 1;
        }
    }

    ////////////////////////////////////

    if (1 < palindrome._leng) {
        char *ret = (char *)malloc(palindrome._leng * sizeof(char));
        int i = 0;
        for (; i < palindrome._leng; i += 1) {
            ret[i] = palindrome._head[i];
        }
        ret[i] = '\0';
        return ret;
    }

    free(head);
    return NULL;
}

////////////////////////////////////////////////////////////////////////////////

char *Dynamic_Planning_2_Dimension(char *str) {
    int len = strlen(str);
    bool **state = (bool **)malloc(len * sizeof(bool *));  // n * n matrix
    for (int i = 0; i < len; i += 1) {
        state[i] = (bool *)malloc(len * sizeof(bool));
    }

    String palindrome = (String) { ._head = NULL, ._leng = 1 };
    state[0][0] = true;
    for (int tail = 1; tail < len; tail += 1) {
        state[tail][tail] = true;
        if (str[tail - 1] == str[tail]) {
            state[tail - 1][tail] = true;
            if (2 > palindrome._leng) {           // palindrome substring length == 2
                palindrome._head = &str[tail - 1];
                palindrome._leng = 2;
            }
        }
    }
    for (int full = 3; full <= len; full += 1) {  // palindrome substring length == full
        for (int head = 0, tail = 0; (tail = head + full - 1) < len; head += 1) {
            if (state[head + 1][tail - 1] == true && str[head] == str[tail]) {  // state transition equation.
                state[head][tail] = true;   // true if str[head..tail] is a palindrome substring.

                if (full > palindrome._leng) {
                    palindrome._head = &str[head];
                    palindrome._leng = full;
                }
            }
        }
    }

    ////////////////////////////////////

    if (1 < palindrome._leng) {
        char *ret = (char *)malloc((palindrome._leng + 1) * sizeof(char));
        int i = 0;
        for (; i < palindrome._leng; i += 1) {
            ret[i] = palindrome._head[i];
        }
        ret[i] = '\0';
        return ret;
    }

    for (int i = 0; i < len; i += 1) {
        free(state[i]);
    }
    free(state);
    return NULL;
}

////////////////////////////////////////////////////////////////////////////////

/* Extended_Palindrome
    ¡û    full   palindrome  ¡ú
    ¡û    semi   ¡ú
      ¡ýaxis-incr¡ýaxis     ¡ýaxis+incr
                ¡û  incr   ¡ú |
----------------------------------------
  a   g   i   b   b   i   g   g         odd or even, str_len=8
# a # g # i # b # b # i # g # g #       always odd , ext_len=str_len*2+1
----------------------------------------
Due to the symmetry of palindrome.
case 1: radius[axis-incr] <  radius[axis]-incr
       (radius[axis+incr] =  radius[axis-incr]) == MIN(radius[axis-incr],radius[axis]-incr)
case 2: radius[axis-incr] >  radius[axis]-incr
       (radius[axis+incr] =  radius[axis]-incr) == MIN(radius[axis-incr],radius[axis]-incr)
case 3: radius[axis-incr] == radius[axis]-incr
        Extend radius[axis+incr].
        semi starts from (radius[axis-incr] == radius[axis]-incr == semi-incr).
*/
char *Extended_Palindrome(char *str) {
    int str_len = strlen(str);
    int ext_len = str_len * 2 + 1;
    char *ext = (char *)malloc((ext_len + 1) * sizeof(char));
    char *beg = ext;
    for (int i = 0; i < str_len; i += 1) {
        beg[0] = '#';
        beg[1] = str[i];
        beg += 2;
    }
    beg[0] = '#';
    beg[1] = '\0';

    ////////////////////////////////////

    int *radius = (int *)malloc(ext_len * sizeof(int));
    radius[0] = 0;
    for (int axis = 1, semi = 0, incr = 0; axis < ext_len; axis += incr) {
        //while (0 <= axis - semi - 1 && axis + semi + 1 < ext_len && ext[axis - semi - 1] == ext[axis + semi + 1]) {  
        while (semi < axis && axis + semi + 1 < ext_len && ext[axis - semi - 1] == ext[axis + semi + 1]) {
            semi += 1;                 // Extend palindrome's semi-diameter.
        }
        radius[axis] = semi;
        for (incr = 1; incr <= semi && radius[axis - incr] != radius[axis] - incr; incr += 1) {
            radius[axis + incr] = min(radius[axis - incr], radius[axis] - incr);
        }
        semi = max(semi - incr, 0);    // radius[axis-incr] == radius[axis]-incr == semi-incr
    }

    String palindrome = (String) { ._head = NULL, ._leng = 1 };
    for (int axis = 0; axis < ext_len; axis += 1) {
        if (radius[axis] > palindrome._leng) {
            palindrome._head = &str[(axis - radius[axis]) / 2];  // ext_len==str_len*2+1
            palindrome._leng = radius[axis];                     // str_len==ext_len/2
        }
    }

    ////////////////////////////////////

    if (1 < palindrome._leng) {
        char *ret = (char *)malloc((palindrome._leng + 1) * sizeof(char));
        int i = 0;
        for (; i < palindrome._leng; i += 1) {
            ret[i] = palindrome._head[i];
        }
        ret[i] = '\0';
        return ret;
    }

    free(ext);
    return NULL;
}

////////////////////////////////////////////////////////////////////////////////


int main(int argc, char *argv[]) {
    char *str = (char *)"Iamagibbiggirl";
    // char *ret = Brute_Force(str);
    // char *ret = Axial_Symmetry(str);
    // char *ret = Dynamic_Planning_1_Dimension(str);
    // char *ret = Dynamic_Planning_2_Dimension(str);
    char *ret = Extended_Palindrome(str);

    fprintf(stdout, "%s""\n", ret);

    return 0;
}
