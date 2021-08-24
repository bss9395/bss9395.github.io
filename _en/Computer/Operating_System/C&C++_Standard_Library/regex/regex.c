/* Regex.c
Author: BSS9395
Update: 2020-08-24T09:12:00+08@China-Guangdong-Zhanjiang+08
Desgin: Regular Expression
System: Linux
*/


/* Example
./a.out "^[a-zA-Z0-9]+@[a-zA-Z0-9]+.[a-zA-Z0-9]+$" "brilliantstarrysky9395@gmail.com"
*/

#if 0
#include <sys/types.h>
#include <regex.h>
int regcomp(regex_t *preg, const char *regex, int cflags);
int regexec(const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[], int eflags);
size_t regerror(int errcode, const regex_t *preg, char *errbuf, size_t errbuf_size);
void regfree(regex_t *preg);
#endif

#define _GNU_SOURCE
#include <sys/types.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <regex.h>

typedef const char *Level;
struct {
    const Level _Info;
    const Level _ToDo;
    const Level _Warn;
    const Level _Error;
    const Level _Fatal;
} ELevel = {
    ._Info = "Info",
    ._ToDo = "ToDo",
    ._Warn = "Warn",
    ._Error = "Error",
    ._Fatal = "Fatal"
};

bool Check(bool failed, Level level, const char *function, const char *record, const char *extra) {
    if (failed) {
        (extra == NULL) ? extra = (const char *)"" : extra;
        fprintf(stderr, "[%s] %s: %s%s; ""\n", level, function, record, extra);
    }
    return failed;
}

int main(int argc, char *argv[]) {
    argc = 3;
    argv[1] = "^[a-zA-Z0-9]+@[a-zA-Z0-9]+.[a-zA-Z0-9]+$";
    argv[2] = "brilliantstarrysky9395@gmail.com";

    ////////////////////////////////////

    if (argc != 3) {
        fprintf(stdout, "Usage: %s Regex Text""\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *pattern = argv[1];
    const char *text = argv[2];
    int err = 0;
    regex_t regex;
    char buffer[1024];
    size_t errlen = 0;

    // REG_NOSUB disables nmatch and pmatch arguments in regexec.
    err = regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB);
    if (err != 0 && Check(true, ELevel._Error, "regcomp", "err != 0", "")) {
        errlen = regerror(err, &regex, buffer, sizeof(buffer));
        (errlen < sizeof(buffer)) ? errlen : (errlen = sizeof(buffer) - 1);
        buffer[errlen] = '\0';
        fprintf(stderr, "%s""\n", buffer);
    }

    err = regexec(&regex, text, 0, NULL, 0);
    if (err != 0 && Check(true, ELevel._Error, "regexec", "err != 0", "")) {
        fprintf(stdout, "unmatched""\n");
    }
    else {
        fprintf(stdout, "matched""\n");
    }

    regfree(&regex);
    return 0;
}
