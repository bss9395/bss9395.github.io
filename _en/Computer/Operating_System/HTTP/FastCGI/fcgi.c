#include <unistd.h>
#include "fcgi_stdio.h"

extern char **environ;

typedef const void* EType;
static const struct {
    EType Null;
    EType Long;
    EType String;
} ETYPE = { (EType)"Null", (EType)"Long", (EType)"String" };

void *getEnv(const char *env, EType type) {
    void *ret = NULL;

    if(type == ETYPE.Long) {
        char *ptr = getenv(env);
        if(ptr) {
            ret = (void *)strtol(ptr, NULL, 10);
        }
    }
    else if(type == ETYPE.String) {
        ret = getenv(env);
    }

    return ret;
}

static void printLines(const char *label, char *lines[]) {
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

    long len = 0;
    while(len < length && !feof(file)) {
        buf[len] = fgetc(file);
        if(buf[len] == del) {
            break;
        }
        len += 1;
    }
    buf[len] = '\0';

    return len;
}

static char buf[BUFSIZ] = "01234567890";

int main(int argc, char *argv[]) {
    char **context = environ;

    for(long count = 0; 0 <= FCGI_Accept(); count += 1) {
        printf(""
               "Status: 200 OK\r\n"
               "Content-Type: text/html\r\n"
               "\r\n");
        printf(""
               "<title>FastCGI echo</title>"
               "<h3>FastCGI echo</h3>"
               "request count = %ld, process ID = %ld",
               count, getpid());

        long CONTENT_LENGTH = (long)getEnv("CONTENT_LENGTH", ETYPE.Long);
        getLine(buf, stdin, CONTENT_LENGTH, EOF);

        char *post[2] = { buf, NULL};
        printLines("form method=post", post);
        printLines("initial environ", context);
        printLines("request environ", environ);
    }

    return 0;
}
