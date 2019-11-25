#include "fcgi_stdio.h"

#include <unistd.h>
#include <stdlib.h>

extern char **environ;

static const struct {
    const int Long;
    const int String;
} Type = { 0, 1 };

void *getEnv(char *env, int type) {
    void *ret = NULL;

    if(type == Type.Long) {
        char *ptr = getenv(env);
        if(ptr) {
            ret = (void *)strtol(ptr, NULL, 10);
        }
    }
    else if(type == Type.String) {
        ret = getenv(env);
    }

    return ret;
}

static void printLines(char *label, char *lines[]) {
    printf("<h3>%s</h3>\n", label);
    printf("<pre>\n");
    while(lines[0] != NULL) {
        printf("%s\n", lines[0]);
        lines += 1;
    }
    printf("</pre>\n\n");
}

static long getLine(char *buf, FILE *file, long length, char del) {
    if(!buf) {
        buf = (char *)malloc(sizeof(char) * length);
    }

    long ret = 0;
    while(ret < length && !feof(file)) {
        buf[ret] = fgetc(file);
        if(buf[ret] == del) {
            break;
        }
        ret += 1;
    }
    buf[ret] = '\0';

    return ret;
}

static char buf[BUFSIZ] = "01234567890";

int main(int argc, char *argv[]) {
    char **context = environ;

    while(0 <= FCGI_Accept()) {
        printf(""
               "Status: 200 OK\r\n"
               "Content-Type: text/html\r\n"
               "\r\n");

        long CONTENT_LENGTH = (long)getEnv("CONTENT_LENGTH", Type.Long);
        getLine(buf, stdin, CONTENT_LENGTH, EOF);

        char *post[2] = { buf, NULL };
        printLines("form method=post", post);
        printLines("initial environ", context);
        printLines("request environ", environ);
    }

    return 0;
}