/* _mkdir.c
Author: BSS9395
Update: 2021-10-29T22:47:00+08@China-Guangdong-Shenzhen+08
Design: Windows C Library: _mkdir
*/

/* Windows API
#include <direct.h>
int _mkdir(const char *dirname);
int _rmdir(const char *dirname);
int _chdir(const char *dirname);
char *_getcwd(char *buffer, int maxlen);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <direct.h>  // Windows API

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char dir[] = "E:/temp/test/";
    if (_mkdir(dir) != 0) {
        fprintf(stderr, "%s [%d] %s""\n", "_mkdir(dir) != 0", errno, strerror(errno));
        if (_rmdir(dir) != 0) {
            fprintf(stderr, "%s [%d] %s""\n", "_rmdir(dir) != 0", errno, strerror(errno));
        }
    }
    else if (_chdir(dir) != 0) {
        fprintf(stderr, "%s [%d] %s""\n", "_chdir(dir) != 0", errno, strerror(errno));
    }

    fprintf(stderr, "%s""\n", _getcwd(NULL, 0));

    return 0;
}
