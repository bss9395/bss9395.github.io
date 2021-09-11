/* Simple_Regex.c
Author: BSS9395
Update: 2021-09-11T16:12:00+08@China-Guangdong-Zhanjiang+08
Design: Simple Regex Format
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Regex Format
Regex: [Paren]\0
Paren: [Alpha]|[(Paren){number}]
*/

char buf[1024];
char *str = buf;
char *Parse_Regex(char *reg) {
    while (reg[0] != '\0') {
        if (reg[0] == '(') {
            char *ret = reg;
            reg += 1;
            char *fore = str;
            reg = Parse_Regex(reg);
            char *back = str;
            if (reg[0] != ')') {
                fprintf(stderr, "Regex Format Error.""\n");
                fore[0] = '\0';
                return ret;
            }
            reg += 1;

            if (reg[0] == '{') {
                char *ret = reg;
                reg += 1;
                int num = 0;
                reg += sscanf(reg, "%d", &num);
                if (reg[0] != '}') {
                    fprintf(stderr, "Regex Format Error.""\n");
                    back[0] = '\0';
                    return ret;
                }
                reg += 1;

                for (int i = 0; i < num - 1; i += 1) {
                    for (char *beg = fore; beg < back; beg += 1) {
                        str[0] = beg[0];
                        str += 1;
                    }
                }
            }
        }
        else if (reg[0] != '(' && reg[0] != ')' && reg[0] != '{' && reg[0] != '}') {
            str[0] = reg[0];
            str += 1;
            reg += 1;
        }
        else {
            return reg;
        }
    }
    str[0] = '\0';
    return reg;
}

int main(int argc, char *argv[]) {
    char *reg = (char *)"abc(d){2}e";
    // char *reg = (char *)"a(b(c){3}d){2}e";
    // char *reg = (char *)"(a(b(c){2}d){3}e){2}";
    Parse_Regex(reg);
    fprintf(stdout, "%s""\n", buf);

    return 0;
}
