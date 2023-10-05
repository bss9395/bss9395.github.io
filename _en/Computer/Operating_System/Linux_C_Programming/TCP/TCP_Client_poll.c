/* TCP_Client_poll.c
Author: BSS9395
Update: 2023-09-29T10:00:00+08@China-Guangdong-Zhanjiang+08
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <poll.h>
#include <unistd.h>
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

    struct pollfd fds[2];
    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;
    fds[1].fd = fd_client;
    fds[1].events = POLLIN;

    while(true) {
        int ready = poll(fds, 2, 3000);
        if(ready < 0) {
            perror("poll");
            continue;
        } else if(ready == 0) {
            // fprintf(stdout, "poll timeout\n");
            continue;
        }
        if(fds[0].revents & POLLIN) {
            char buffer[_buffer_size];
            fgets(buffer, _buffer_size, stdin);
            if(buffer[strlen(buffer) - 1] == '\n') {
                buffer[strlen(buffer) - 1] = '\0';
            }
            write(fd_client, buffer, strlen(buffer));
        }
        if(fds[1].revents & POLLIN) {
            char buffer[_buffer_size];
            int len = read(fd_client, buffer, _buffer_size);
            if(len <= 0) {
                perror("read");
                break;
            }
            buffer[len] = '\0';
            fprintf(stdout, "%s\n", buffer);
        }
    }

    close(fd_client);

    return 0;
}
