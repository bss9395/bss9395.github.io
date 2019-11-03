/* Utilities.c
Author: BSS9395
Update: 2019-11-03T22:24 +08 @ ShenZhen +08
Design: HTTP Server
*/

#define _GNU_SOURCE

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
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

int   checkError(char *msg, bool failed);
bool  checkInitialWord(char *text, char *word, long len);
long  getLine(int sock_fd, char *buf, long size);
char *getMimeType(char *filename);
int   HexDigitToDec(char c);
void  UriEncode(char *uri, char *path);
void  UriDecode(char *uri, char *path);
void  parseUri(char *uri, char *root, char *path);

#ifndef Utilities_c
#define Utilities_c

int checkError(char *msg, bool failed) {
    if(failed) {
        perror(msg);
        return errno;
    }

    return 0;
}

bool checkInitialWord(char *text, char *word, long len) {
    long i = 0;
    for(; i < len && text[i] != '\0' && word[i] != '\0'; ++i) {
        if(toupper(*text) != toupper(*word)){
            return false;
        }
    }
    return (i == len);
}

long getLine(int sock_fd, char *buf, long size) {
    long len = 0;
    while(len < size - 1 && 1 == recv(sock_fd, &buf[len], 1, 0)) {
        if(buf[len] == '\n' || buf[len] == '\0') {
            if(0 < len && buf[len - 1] == '\r') {
                len = len - 1;
            }
            break;
        }
        len += 1;
    }
    buf[len] = '\0';
    return len;
}

char *getMimeType(char *filename) {
    char *ret = NULL;
    char *dot = strrchr(filename, '.');

    if(NULL == dot) {
        ret = "text/plain";
    }
    else if(0 == strcmp(dot, ".html") || 0 == strcmp(dot, ".htm")) {
        ret = "text/html; charset=utf-8";
    }
    else if(0 == strcmp(dot, ".jpeg") || 0 == strcmp(dot, ".jpg")) {
        ret = "image/jpeg";
    }
    else if(0 == strcmp(dot, ".gif")) {
        ret = "image/gif";
    }
    else if(0 == strcmp(dot, ".png")) {
        ret = "image/png";
    }
    else if(0 == strcmp(dot, ".css")) {
        ret = "text/css; charset=utf-8";
    }
    else if(0 == strcmp(dot, ".au")) {
        ret = "audio/basic";
    }
    else if(0 == strcmp(dot, ".wav")) {
        ret = "audio/wav";
    }
    else if(0 == strcmp(dot, ".midi") || 0 == strcmp(dot, ".mid")) {
        ret = "audio/midi";
    }
    else if(0 == strcmp(dot, ".mp3")) {
        ret = "audio/mpeg";
    }
    else if(0 == strcmp(dot, ".avi")) {
        ret = "video/x-msvideo";
    }
    else if(0 == strcmp(dot, ".mov") || 0 == strcmp(dot, ".qt")) {
        ret = "video/quicktime";
    }
    else if(0 == strcmp(dot, ".mpeg") || 0 == strcmp(dot, ".mpe")) {
        ret = "video/mpeg";
    }
    else if(0 == strcmp(dot, ".vrml") || 0 == strcmp(dot, ".wrl")) {
    	ret = "model/vrml";
    }
    else if(0 == strcmp(dot, ".ogg")) {
        ret = "application/ogg";
    }
    else if(0 == strcmp(dot, ".pac")) {
        ret = "application/x-ns-proxy-autoconfig";
    } else {
    	ret = "text/plain";
    }

    return ret;
}

int HexDigitToDec(char c) {
    int ret = 0;
    if('0' <= c && c <= '9') {
        ret = c - '0';
    }
    else if('a' <= c && c <= 'f') {
        ret = c - 'a' + 10;
    }
    else if('A' <= c && c <= 'F') {
        ret = c - 'A' + 10;
    }
    return ret;
}

void UriEncode(char *uri, char *path) {
    if(uri == path) {
        fprintf(stderr, "\e[33mwarning: UriEncode: uri == path\e[0m\n");
    }

    static char unreserverd[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_.~";
    static char reserved[]    = "!*'();:@&=+$,/?#[]";

    while(path[0] != '\0') {
        if(NULL != strchr(unreserverd, path[0]) || NULL != strchr(reserved, path[0])) {
            uri[0] = path[0];
            uri += 1;
            path += 1;
        }
        else {
        	sprintf(uri, "%%%02x", path[0] & 0xff);
            uri += 3;
            path += 1;
        }
    }
    uri[0] = '\0';
}

void UriDecode(char *uri, char *path) {
    while(uri[0] != '\0') {
        if(uri[0] == '%' && isxdigit(uri[1]) && isxdigit(uri[2])) {
            path[0] = HexDigitToDec(uri[1]) * 16 + HexDigitToDec(uri[2]);
            path += 1;
            uri += 3;
        }
        else {
            path[0] = uri[0];
            path += 1;
            uri += 1;
        }
    }
    path[0] = '\0';
}

void parseUri(char *uri, char *root, char *path) {
    char *slash = strchr(uri, '/');

    if(uri != slash) {
        while(uri != slash){
            root[0] = uri[0];
            uri += 1;
        }
        root[0] = '\0';
    }
    if(root[0] == '\0') {
        sprintf(root, "%s", getenv("HOME"));
    }

    UriDecode(slash + 1, path);
    if(path[0] == '\0') {
        sprintf(path, "%s", ".");
    }

// printf("\e[33m%s\e[0m\n", root);
// printf("\e[33m%s\e[0m\n", path);
}

#endif // Utilities_c