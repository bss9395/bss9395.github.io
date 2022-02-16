/* Reverse_Sentence.c
Author: Bss9395
Update: 2021-08-28T16:39:00+08@China-Guangdong-Zhanjiang+08
Design: Reverse Sentence by word decomposition.
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
    int len = (int)strlen(str);

    String stack[1024];
    int top = 0;

    int fore = 0;
    int back = 0;
    for (fore = 0; fore < len && str[fore] == ' '; fore += 1);
    while (fore < len) {
        for (back = fore + 1; back < len && str[back] != ' '; back += 1);
        stack[top] = (String) {
            &str[fore], back - fore
        };
        top += 1;
        for (fore = back + 1; fore < len && str[fore] == ' '; fore += 1);
    }

    ////////////////////////////////////

    char *reversed = (char *)malloc((len + 1) * sizeof(char));
    char *beg = reversed;
    while (0 < top) {
        top -= 1;
        for (int i = 0; i < stack[top]._leng; i += 1) {
            beg[0] = stack[top]._head[i];
            beg += 1;
        }
        beg[0] = (0 < top) ? ' ' : '\0';
        beg += 1;
    }
    return reversed;
}

int main(int argc, char *argv[]) {
    char *str = (char *)"I am a student.";
    char *rev = Reverse_Sentence(str);
    fprintf(stdout, "%s""\n", rev);

    return 0;
}
