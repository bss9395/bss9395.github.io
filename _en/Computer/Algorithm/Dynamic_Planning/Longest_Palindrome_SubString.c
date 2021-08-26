/* Longest_Palindrome_SubString.c
Author: BSS9395
Update: 2020-08-26T18:43:00+08@China-Guangdong-Zhanjiang+08
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

char *Brute_Force(const char *str) {
    String palindrome = (String) { NULL, 1 };
    for (char *beg1 = str; beg1[0] != '\0'; beg1 += 1) {
        for (char *beg2 = str; beg2[0] != '\0'; beg2 += 1) {
            char *left = beg1;
            char *right = beg2;
            while (left < right && left[0] == right[0]) {
                left += 1; right -= 1;
            }
            if (left >= right && beg2 - beg1 + 1 > palindrome._leng) {
                palindrome._head = beg1;
                palindrome._leng = beg2 - beg1 + 1;
            }
        }
    }

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

char *Axial_Symmetry(const char *str) {
    String palindrome = (String) { NULL, 1 };
    char *left = NULL;
    char *right = NULL;
    for (char *axis = str; axis[0] != '\0'; axis += 1) {
        // case Odd
        left = axis; right = axis;
        while (str <= left && right[0] != '\0' && left[0] == right[0]) {
            left -= 1; right += 1;
        }
        if (right - left - 1 > palindrome._leng) {
            palindrome = (String) { left + 1, right - (left + 1) };  // ._leng = (right - 1) - (left + 1) + 1 
        }

        // case Even
        left = axis; right = axis + 1;
        while (str <= left && right[0] != '\0' && left[0] == right[0]) {
            left -= 1; right += 1;
        }
        if (right - left - 1 > palindrome._leng) {
            palindrome = (String) { left + 1, right - (left + 1) };  // ._leng = (right - 1) - (left + 1) + 1 
        }
    }

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

char *Dynamic_Planning_1_Dimension(const char *str) {
    int len = strlen(str);
    int *head = (int *)malloc(len * sizeof(int));
    head[0] = 0;

    String palindrome = (String) { NULL, 1 };
    for (int tail = 1; str[tail] != '\0'; tail += 1) {
        if (0 < head[tail - 1] && str[tail] == str[head[tail - 1] - 1]) {
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
            palindrome = (String) { (char *)&str[head[tail]], tail - head[tail] + 1 };
        }
    }

    if (1 < palindrome._leng) {
        char *ret = (char *)malloc(palindrome._leng * sizeof(char));
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

char *Dynamic_Planning_2_Dimension(const char *str) {
    int str_len = strlen(str);
    bool **state = (bool **)malloc(str_len * sizeof(bool *));
    for (int i = 0; i < str_len; i += 1) {
        state[i] = (bool *)malloc(str_len * sizeof(bool));
    }

    String palindrome = (String) { NULL, 1 };
    state[0][0] = true;
    for (int i = 1; i < str_len; i += 1) {
        state[i][i] = true;
        if (str[i - 1] == str[i]) {
            state[i - 1][i] = true;
            if (2 > palindrome._leng) {
                palindrome = (String) { (char *)&str[i - 1], 2 };
            }
        }
    }
    for (int len = 3; len <= str_len; len += 1) {
        for (int i = 0, j = 0; (j = i + len - 1) < str_len; i += 1) {
            if (state[i + 1][j - 1] == true && str[i] == str[j]) {
                state[i][j] = true;
                if (len > palindrome._leng) {
                    palindrome = (String) { (char *)&str[i], len };
                }
            }
        }
    }

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

    fprintf(stdout, "%s""\n", ext);

    ////////////////////////////////////

    int *radius = (int *)malloc(ext_len * sizeof(int));
    radius[0] = 0;
    for (int axis = 1, semi = 0, incr = 0; axis < ext_len; axis += incr) {
        while (semi < axis && ext[axis - semi - 1] == ext[axis + semi + 1]) {
            semi += 1;
        }
        radius[axis] = semi;
        for (incr = 1; incr <= semi && radius[axis - incr] != radius[axis] - incr; incr += 1) {
            radius[axis + incr] = min(radius[axis - incr], radius[axis] - incr);
        }
        semi = max(semi - incr, 0);
    }

    String palindrome = { NULL, 2 * 1 + 1 };
    for (int axis = 0; axis < ext_len; axis += 1) {
        if (2 * radius[axis] + 1 > palindrome._leng) {
            palindrome = (String) { (char *)&ext[axis - radius[axis]], 2 * radius[axis] + 1 };
        }
    }

    ////////////////////////////////////

    if (3 < palindrome._leng) {
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


int main(int argc, char *argv[]) {
    const char *str = "Iamagibbiggirl";
    //char *ret = Brute_Force(str);
    char *ret = Axial_Symmetry(str);
    //char *ret = Dynamic_Planning_1_Dimension(str);
    //char *ret = Dynamic_Planning_2_Dimension(str);
    //char *ret = Extended_Palindrome(str);

    fprintf(stdout, "%s""\n", ret);

    return 0;
}
