/* Longest_No_Repeating_SubString.c
Author: BSS9395
Update: 2020-09-01T19:58:00+08@China-Guangdong-Zhanjiang+08
Design: Longest No Repeating SubString
Original: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-cshi-xian-/
*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _String {
    char *_stri;
    int _leng;
} String;

char *Longest_No_Repeating_SubString(char *str) {
    int len = strlen(str);

    String onefold = { ._stri = NULL,._leng = 0 };
    int full = 0;
    for (int head = 0, tail = head; tail < len; ) {
        char ch = str[tail];
        for (int idx = head; idx < tail; idx += 1) {
            if (ch == str[idx]) {
                head = idx + 1;
                full = tail - head;
                break;
            }
        }
        tail += 1;
        full += 1;
        if (full > onefold._leng) {
            onefold._stri = &str[head];
            onefold._leng = full;
        }
    }

    ////////////////////////////////////

    char *ret = (char *)malloc((onefold._leng + 1) * sizeof(char));
    int i = 0;
    for (; i < onefold._leng; i += 1) {
        ret[i] = onefold._stri[i];
    }
    ret[i] = '\0';
    return ret;
}

////////////////////////////////////////////////////////////////////////////////

char *Longest_No_Repeating_SubString_Map(char *str) {
    int len = strlen(str);

    String onefold = { ._stri = NULL,._leng = 0 };
    int map[256];
    for (int i = 0; i < 256; i += 1) {
        map[i] = -1;
    }

    int full = 0;
    for (int head = 0, tail = head; tail < len;) {
        char ch = str[tail];
        if (map[(int)ch] >= head) {
            head = map[(int)ch] + 1;
            full = tail - head;
        }
        map[(int)ch] = tail;

        tail += 1;
        full += 1;
        if (full > onefold._leng) {
            onefold._stri = &str[head];
            onefold._leng = full;
        }
    }

    ////////////////////////////////////

    char *ret = (char *)malloc((onefold._leng + 1) * sizeof(char));
    int i = 0;
    for (; i < onefold._leng; i += 1) {
        ret[i] = onefold._stri[i];
    }
    ret[i] = '\0';
    return ret;
}


int main(int argc, char *argv[]) {
    // char *str = (char *)"aaa";
    char *str = (char *)"abcabcbb";

    //char *onefold = Longest_No_Repeating_SubString(str);
    char *onefold = Longest_No_Repeating_SubString_Map(str);
    fprintf(stdout, "%s""\n", onefold);

    return 0;
}
