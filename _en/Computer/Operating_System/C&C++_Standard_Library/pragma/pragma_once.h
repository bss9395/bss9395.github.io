/* pragma_once.h
Author: BSS9395
Update: 2021-11-21T00:05:00+08@China-Guangdong-Shenzhen+08
Design: C Standard Pragma: #pragma once
*/

#pragma once
#ifndef Pragma_Once_h
#define Pragma_Once_h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef const char *Level;
static struct {
    Level _Info;
    Level _Warn;
    Level _Debug;
    Level _Error;
    Level _Fatal;
} ELevel = {
    "Info",
    "Warn",
    "Debug",
    "Error",
    "Fatal"
};

typedef intptr_t iptr;
bool Check_(const bool failed, const Level level, const char *file, const iptr line, const char *function, const char *record, const char *extra);
#define Check(failed, level, record, extra) Check_(failed, level, __FILE__, __LINE__, __FUNCTION__, record, extra)

////////////////////////////////////////////////////////////////////////////////

#ifdef Pragma_Once_c

bool Check_(const bool failed, const Level level, const char *file, const iptr line, const char *function, const char *record, const char *extra) {
    if (failed) {
        const char *filename = NULL;
        (filename = strrchr(file, '/')) || (filename = strrchr(file, '\\'));
        fprintf(stderr, "[%s : %s : %Id] %s : %s %s""\n", level, (filename == NULL) ? file : (filename + 1), line, function, record, (extra == NULL) ? "" : extra);
    }
    return failed;
}

#endif // Pragma_Once_c
#endif // Pragma_Once_h
