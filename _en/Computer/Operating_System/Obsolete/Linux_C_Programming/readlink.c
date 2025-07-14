/* readlink.c
Author: BSS9395
Update: 2023-09-15T14:40:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: readlink
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/*
#include <unistd.h>
ssize_t readlink(const char *restrict path, char *restrict buf, size_t bufsize);

#include <fcntl.h>
ssize_t readlinkat(int fd, const char *restrict path, char *restrict buf, size_t bufsize);
*/

char * readlink_malloc (const char *filename) {
    int size = 100;
    char *buffer = NULL;
    while (true) {
        buffer = (char *) realloc (buffer, size);
        int nchars = readlink (filename, buffer, size);
        if (nchars < 0) {
            free (buffer);
            return NULL;
        } else if (nchars < size) {
            return buffer;
        }
        size *= 2;
    }
}

int main(int argc, char *argv[]) {
    system("touch tmp.txt");
    system("ln -s tmp.txt link.txt");
    char *ret = readlink_malloc("link.txt");
    fprintf(stdout, "%s\n", ret);
    return 0;
}