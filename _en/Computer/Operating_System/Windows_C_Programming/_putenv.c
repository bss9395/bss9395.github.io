/* _putenv.c
Author: BSS9395
Update: 2021-10-30T11:42:00+08@China-Guangdong-Shenzhen+08
Design: C Standard Library: _putenv
*/

/*
// C Standard Library
#include <stdlib.h>
char* getenv(const char* name);

// Windows C Library
#include <stdlib.h>
int _putenv(const char *envstring);

// Linux C Library
#include <stdlib.h>
int setenv(const char *name, const char *value, int overwrite);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Set_Environment(const char *name, const char *value, bool overwrite) {
    const char* path = getenv(name);
    if (path != NULL && overwrite == false) {
        return -1;
    }

    static char env[1024] = { 0 };
    int idx = 0;
    for (const char *it = name; it[0] != '\0'; it += 1) {
        env[idx] = it[0];
        idx += 1;
    }
    env[idx] = '=';
    idx += 1;
    for (const char *it = value; it[0] != '\0'; it += 1) {
        env[idx] = it[0];
        idx += 1;
    }
    env[idx] = '\0';
    int err = _putenv(env); // Windows API
    return err;
}

int main(int argc, char *argv[]) {
    Set_Environment("PATH", "C:/bin/", true);
    // setenv("PATH", "/home/bss9395/bin/", true);  // Linux API

    const char* path = getenv("PATH");
    fprintf(stderr, "PATH=%s""\n", path);
    return 0;
}
