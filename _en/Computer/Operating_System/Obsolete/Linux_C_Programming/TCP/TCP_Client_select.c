/* TCP_Server_select.c
Author: BSS9395
Update: 2023-09-28T15:24:00+08@China-Guangdong-Zhanjiang+08
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>

static const int _buffer_size = 512;
static const char *_server_addr = "127.0.0.1";
static const int _server_port = 9395;

int main(int argc, char *argv[]) {
    int fd_client = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr_server;
    memset(&addr_server, 0, sizeof(addr_server));
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(_server_port);
    inet_pton(AF_INET, _server_addr, &addr_server.sin_addr);

    connect(fd_client, (struct sockaddr *)&addr_server, sizeof(addr_server));

    fd_set set_all;
    FD_ZERO(&set_all);
    FD_SET(STDIN_FILENO, &set_all);
    FD_SET(fd_client, &set_all);

    while(true) {
        fd_set set_re = set_all;
        int ready = select(fd_client + 1, &set_re, NULL, NULL, NULL);
        if(ready < 0) {
            perror("ready");
            continue;
        } else if(ready == 0) {
            fprintf(stdout, "select timeout\n");
            continue;
        }
        if(FD_ISSET(STDIN_FILENO, &set_re)) {
            char buffer[_buffer_size];
            fgets(buffer, _buffer_size, stdin);
            if(buffer[strlen(buffer) - 1] == '\n') {
                buffer[strlen(buffer) - 1] = '\0';
            }
            write(fd_client, buffer, strlen(buffer));
        } 
        if(FD_ISSET(fd_client, &set_re)) {
            char buffer[_buffer_size];
            int len = read(fd_client, buffer, _buffer_size);
            if(len <= 0) {
                perror("read");
                continue;
            }
            buffer[len] = '\0';
            fprintf(stdout, "%s\n", buffer);
        }
    }

    close(fd_client);
}
