/* TCP_Server_poll.c
Author: BSS9395
Update: 2023-09-29T10:00:00+08@China-Guangdong-Zhanjiang+08
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <poll.h>
#include <stdbool.h>

static const int   _buffer_size = 512;
static const char *_server_addr = "127.0.0.1";
static const int   _server_port = 9395;

int main(int argc, char *argv[]) {
    int fd_listen = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr_server;
    memset(&addr_server, 0, sizeof(addr_server));
    addr_server.sin_family = AF_INET;
    addr_server.sin_addr.s_addr = INADDR_ANY;
    addr_server.sin_port = htons(_server_port);

    bind(fd_listen, (struct sockaddr *)&addr_server, sizeof(addr_server));
    listen(fd_listen, 10);

    struct pollfd fd_ready[1024];
    for(int i = 0; i < 1024; i += 1) {
        fd_ready[i].fd = -1;
    }
    fd_ready[0].fd = STDIN_FILENO;
    fd_ready[0].events = POLLIN;
    fd_ready[1].fd = fd_listen;
    fd_ready[1].events = POLLIN;
    int fd_ready_maxi = 2;

    while(true) {
        int ready = poll(fd_ready, fd_ready_maxi, 3000);
        if(ready < 0) {
            perror("poll");
            continue;
        } else if(ready == 0) {
            // fprintf(stdout, "poll timeout\n");
            continue;
        }
        if(fd_ready[1].revents & POLLIN) {
            struct sockaddr_in addr_client;
            socklen_t len_client = sizeof(addr_client);
            int fd_client = accept(fd_ready[1].fd, (struct sockaddr *)&addr_client, &len_client);
            char str[INET_ADDRSTRLEN];
            fprintf(stdout, "received %s:%d\n", inet_ntop(AF_INET, &addr_client.sin_addr, str, sizeof(str)), ntohs(addr_client.sin_port));
            int i = 2;
            for(; i < 1024; i += 1) {
                if(fd_ready[i].fd < 0) {
                    fd_ready[i].fd = fd_client;
                    fd_ready[i].events = POLLIN;
                    break;
                }
            }            
            if(fd_ready_maxi < i + 1) {
                fd_ready_maxi = i + 1;
            }
            ready -= 1;
            if(ready <= 0) {
                continue;
            }
        }
        if(fd_ready[0].revents & POLLIN) {
            char buffer[_buffer_size];
            fgets(buffer, _buffer_size, stdin);
            if(buffer[strlen(buffer) - 1] == '\n') {
                buffer[strlen(buffer) - 1] = '\0';
            }
            for(int i = 2; i < fd_ready_maxi; i += 1) {
                if(fd_ready[i].fd < 0) {
                    continue;
                }
                write(fd_ready[i].fd, buffer, strlen(buffer));
            }
            ready -= 1;
            if(ready <= 0) {
                continue;
            }
        }
        for(int i = 2; i < fd_ready_maxi; i += 1) {
            struct pollfd fd_socket = fd_ready[i];
            if(fd_socket.fd < 0) {
                continue;
            } 
            if(fd_socket.revents & POLLIN) {
                char buffer[_buffer_size];
                int len = read(fd_socket.fd, buffer, _buffer_size);
                if(len <= 0) {
                    close(fd_socket.fd);
                    fd_ready[i].fd = -1;
                    continue;
                }
                buffer[len] = '\0';
                for(int i = 2; i < fd_ready_maxi; i += 1) {
                    if(fd_ready[i].fd < 0) {
                        continue;
                    }
                    write(fd_ready[i].fd, buffer, len);
                }
                ready -= 1;
                if(ready <= 0) {
                    break;
                }
            }
        }
    }
    
    close(fd_listen);

    return 0;
}