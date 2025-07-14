/* rename.c
Author: BSS9395
Update: 2023-09-15T14:51:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: rename
*/

#include <stdio.h>
#include <stdlib.h>

/*
#include <stdio.h>
int rename(const char *old, const char *new);

#include <fcntl.h>
int renameat(int oldfd, const char *old, int newfd, const char *new);
*/

int main(int argc, char *argv[]) {
    system("touch tmp.txt");
    rename("tmp.txt", "tmp2.txt");

    return 0;
}