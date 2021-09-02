/* Segement_Command_Line.c
Author: BSS9395
Update: 2020-09-02T16:47:00+08@China-Guangdong-Zhanjiang+08
Design: Command Line Segmentation
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Char {
    char _stri[100];
} Char;

typedef struct _Argu {
    Char _argu[100];
    int _numb;
} Argu;

void Segment_Command_Line(Argu *argu, char *str) {
    int len = strlen(str);
    int head = 0;
    int tail = head;

    for (; head < len && str[head] == ' '; head += 1);
    while (head < len) {
        if (str[head] == '\"') {
            head += 1;
            for (tail = head; tail < len && str[tail] != '\"'; tail += 1);
            if (tail >= len) {
                fprintf(stderr, "Error.""\n");
                return;
            }
        }
        else {
            for (tail = head; tail < len && str[tail] != ' '; tail += 1);
        }

        char *cpy = argu->_argu[argu->_numb]._stri;
        while (head < tail) {
            cpy[0] = str[head];
            cpy += 1, head += 1;
        }
        cpy[0] = '\0';
        argu->_numb += 1;

        for (head = tail + 1; head < len && str[head] == ' '; head += 1);
    }

}

int main(int argc, char *argv[]) {
    char str[100];
    fscanf(stdin, "%[^\n]", &str);

    // char *str = (char *)"xcopy /s \"C:\\program files\" \"d:\\\"";
    // fprintf(stdout, "%s", str);

    Argu argu = { ._numb = 0 };
    Segment_Command_Line(&argu, str);

    fprintf(stdout, "%d""\n", argu._numb);
    for (int i = 0; i < argu._numb; i += 1) {
        fprintf(stdout, "%s""\n", argu._argu[i]._stri);
    }

    return 0;
}
