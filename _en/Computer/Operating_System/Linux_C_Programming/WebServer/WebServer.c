/* WebServer.c
Author: BSS9395
Update: 2019-11-03T22:24 +08 @ ShenZhen +08
Design: HTTP Server
*/

#define _GNU_SOURCE

#define Utilities_c
#include "Utilities.c"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

static char  WEB_ROOT[BUFSIZ] = "ROOT";
//static char *SERVER_ADDR = "127.0.0.1";
static char *SERVER_BIND = "0.0.0.0";
static int   SERVER_PORT = 9395;
static int   SERVER_BACKLOG = 20;

long addField(char *header, char *field, ...) {
    long len = strlen(header);

    va_list args;
    va_start (args, field);
    len += vsprintf (header + len, field, args);
    va_end (args);

    return len;
}

long sendFile(int client_fd, char *header, char *file) {
    send(client_fd, header, strlen(header), 0);
    int fd = open(file, O_RDONLY);

    char buf[BUFSIZ * 8] = "01234567890";
    long send_len = 0;
    for(long len = 0; len = read(fd, buf, sizeof(buf)), 0 < len; send_len += len) {
        if(len != send(client_fd, buf, len, 0)) {
            perror("send");
            break;
        }
    }

    close(fd);
    close(client_fd);
    return send_len;
}

long sendDirectory(int client_fd, char *header, char *directory) {
    send(client_fd, header, strlen(header), 0);
    DIR *dir = opendir(directory);

    static const char FRONT[] = ""
        "<!DOCTYPE html>\r\n"
        "<html>\r\n"
        "<head>\r\n"
        "<meta charset='utf-8'/>\r\n"
        "<meta http-equiv='content-Type' content='text/html'>\r\n"
        "<meta name='viewport' content='width=device-width, initial-scale=1'/>\r\n"
        "<title>Index of %s</title>\r\n"
        "</head>\r\n"
        "<body>\r\n"
        "<ul>\r\n";
    static const char BACK[] = ""
        "</ul>\r\n"
        "</body>\r\n"
        "</html>\r\n"
        "\r\n";

    char buf[BUFSIZ * 8] = "01234567890";
    long send_len = 0;

    send_len += sprintf(buf + send_len, FRONT, directory);
    for(struct dirent *ent = NULL; ent = readdir(dir), ent != NULL; ) {
        switch(ent->d_type) {
        case DT_REG:
            send_len += sprintf(buf + send_len, "<li><a href='%s'>%s</a></li>\n", ent->d_name, ent->d_name);
            break;
        case DT_DIR:
            send_len += sprintf(buf + send_len, "<li><a href='%s/'>%s/</a></li>\n", ent->d_name, ent->d_name);
            break;
        default:
            break;
        }
    }
    send_len += sprintf(buf + send_len, BACK, "");

    if(send_len != send(client_fd, buf, send_len, 0)) {
        perror("send");
    }

    closedir(dir);
    close(client_fd);
    return send_len;
}

void http_response(int client_fd, char *header, char *root, char *uri) {
    chdir(root);
    struct stat st;
    stat(uri, &st);
    switch(st.st_mode & S_IFMT) {
    case S_IFREG:
        addField(header,
                 "Content-Type: %s\r\n"
                 "Content-Length: %ld\r\n"
                 "Connection: keep-alive\r\n"
                 "\r\n"
                 , getMimeType(uri), st.st_size);
        sendFile(client_fd, header, uri);
        break;
    case S_IFDIR:
        addField(header,
                 "Content-Type: %s\r\n"
                 "Content-Length: %ld\r\n"
                 "Connection: keep-alive\r\n"
                 "\r\n"
                 , getMimeType("*.html"), (long)-1);
        sendDirectory(client_fd, header, uri);
        break;
    default:
        fprintf(stderr, "\e[33m%s\e[0m\n", "unknown file type.");
        break;
    }
}



void *http_request(void *args) {
    int client_fd = *((int *)args);
    char header[BUFSIZ * 8] = "01234567890";
    char method[BUFSIZ] = "01234567890";
    char uri[BUFSIZ] = "01234567890";
    char version[BUFSIZ] = "01234567890";

    getLine(client_fd, header, sizeof(header));
    sscanf(header, "%[^ ] %[^ ] %[^ ]", method, uri, version);
    parseUri(uri, WEB_ROOT, uri);

    printf("%s\n", header);
    while(0 < getLine(client_fd, header, sizeof(header))) {
        printf("%s\n", header);
    }

    memset(header, 0, sizeof(header));
    chdir(WEB_ROOT);
    if(checkInitialWord("GET", method, 3)) {
        if(0 == access(uri, R_OK)) {
            addField(header,
                     "HTTP/1.1 200 OK\r\n"
                     "Pragma: no-cache\r\n"
                     "Cache-Control: no-cache\r\n"
                    );
            http_response(client_fd, header, WEB_ROOT, uri);
        }
        else {
            addField(header,
                     "HTTP/1.1 404 NOT FOUND\r\n"
                     "Pragma: no-cache\r\n"
                     "Cache-Control: no-cache\r\n"
                     "Connection: close\r\n"
                    );
            http_response(client_fd, header, WEB_ROOT, "404.html");
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    struct sockaddr_in server_in;
    server_in.sin_family = AF_INET;
    server_in.sin_addr.s_addr = inet_addr(SERVER_BIND);
    server_in.sin_port = htons(SERVER_PORT);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    int on = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    int err = bind(server_fd, (struct sockaddr *)&server_in, sizeof(server_in));
    checkError("bind", err == -1);
    err = listen(server_fd, SERVER_BACKLOG);

    while(true) {
        printf("----------------------------------------\n");
        printf("waiting for connection...\n");

        struct sockaddr_in client_in;
        socklen_t client_len = sizeof(client_in);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_in, &client_len);

        pthread_t tid;
        pthread_create(&tid, NULL, http_request, (void *)&client_fd);
        pthread_detach(tid);
    }

    return 0;
}
