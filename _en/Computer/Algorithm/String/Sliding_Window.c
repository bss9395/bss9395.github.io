/* Sliding_Window.c
Author: BSS9395
Update: 2021-09-03T18:01:00+08@China-Guangdong-Zhanjiang+08
Design: Sliding Window
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Sliding_Window_GC_Ratio(char *DNA, int slide) {
    int len = (int)strlen(DNA);
    if (len < slide) {
        return NULL;
    }

    char *GC_pos = NULL;
    int GC_max = 0;
    int GC_cnt = 0;
    int fore = 0;
    int back = fore;
    while (back < slide) {
        if (DNA[back] == 'G' || DNA[back] == 'C') {
            GC_cnt += 1;
        }
        back += 1;
    }
    GC_max = GC_cnt;
    GC_pos = &DNA[fore];

    while (back < len) {
        if (DNA[fore] == 'G' || DNA[fore] == 'C') {
            GC_cnt -= 1;
        }
        if (DNA[back] == 'G' || DNA[back] == 'C') {
            GC_cnt += 1;
        }
        fore += 1;
        back += 1;

        if (GC_cnt > GC_max) {
            GC_max = GC_cnt;
            GC_pos = &DNA[fore];
        }
    }
    return GC_pos;
}


int main(int argc, char *argv[]) {
    char *DNA = (char *)"AACTGTGCACGACCTGA";
    int slide = 5;

    char *GC_pos = Sliding_Window_GC_Ratio(DNA, slide);
    for (int i = 0; i < slide; i += 1) {
        fprintf(stdout, "%c", GC_pos[i]);
    }
    fprintf(stdout, "\n");

    return 0;
}
