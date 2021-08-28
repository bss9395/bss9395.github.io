/* Reverse_Sentence.c
Author: Bss9395
Update: 2020-08-28T16:39:00+08@China-Guangdong-Zhanjiang+08
Design: Reverse Sentence
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _String {
    char *_head;
    int _leng;
} String;

char *Reverse_Sentence(char *str) {
    int len = strlen(str);

    String stack[1024];
    int top = 0;

    int back = 0;
    int fore = back;
    while (true) {
        for (fore = back; fore < len && str[fore] == ' '; fore += 1);
        if (fore < len) {
            for (back = fore; back < len && str[back] != ' '; back += 1);
            stack[top] = (String) { &str[fore], back - fore };
            top += 1;
            continue;
        }
        break;
    }

    ////////////////////////////////////

    char *ret = (char *)malloc((len + 1) * sizeof(char));
    char *beg = ret;
    while (0 < top) {
        top -= 1;
        for (int i = 0; i < stack[top]._leng; i += 1) {
            beg[0] = stack[top]._head[i];
            beg += 1;
        }
        beg[0] = (0 < top) ? ' ' : '\0';
        beg += 1;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    char *str = "I am a student.";
    char *rev = Reverse_Sentence(str);
    fprintf(stdout, "%s""\n", rev);

    return 0;
}
