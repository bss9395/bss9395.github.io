/* String_SubSequence.c
Author: BSS9395
Update: 2021-09-05T16:24:00+08@China-Guangdong-Zhanjiang+08
Design: Pattern Matching
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int String_SubSequence_Brute_Force(char *strX, int lenX, char *strY, int lenY) {
    int index = -1;
    if (lenX <= 0 || lenY <= 0 || lenX > lenY) {
        return index;
    }

    for (int iX = 0, iY = 0, i = 0; true; iY += 1) {
        for (; iY <= lenY - lenX && strX[0] != strY[iY]; iY += 1);
        if (iY > lenY - lenX) {
            break;
        }

        for (iX = 1, i = iY + 1; iX < lenX && i < lenY; i += 1) {
            if (strX[iX] == strY[i]) {
                iX += 1;
            }
        }
        if (iX >= lenX) {
            index = iY;
        }
    }
    return index;
}

/*
strX is the subsequence of strY.
*/
int main(int argc, char *argv[]) {
    char *strX = (char *)"abc";
    char *strY = (char *)"abcaybec";
    int lenX = strlen(strX);
    int lenY = strlen(strY);

    int last = String_SubSequence_Brute_Force(strX, lenX, strY, lenY);
    fprintf(stdout, "%d""\n", last);

    return 0;
}