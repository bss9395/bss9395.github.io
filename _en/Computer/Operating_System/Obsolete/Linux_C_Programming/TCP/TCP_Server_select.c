/* TCP_Server_select.c
Author: BSS9395
Update: 2023-09-28T15:24:00+08@China-Guangdong-Zhanjiang+08
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

static const int _buffer_size = 512;
static const char *_server_addr = "127.0.0.1";
static const int   _server_port = 9395;

int main(int argc, char *argv[]) {
    int fd_listen = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr_server;
    memset(&addr_server, 0, sizeof(addr_server));
    addr_server.sin_family = AF_INET;
    addr_server.sin_addr.s_addr = htonl(INADDR_ANY);
    addr_server.sin_port = htons(_server_port);

    bind(fd_listen, (struct sockaddr *)&addr_server, sizeof(addr_server));
    listen(fd_listen, 20);

    fd_set set_all;
    FD_ZERO(&set_all);
    FD_SET(fd_listen, &set_all);
    int fd_maxi = fd_listen;
    int fd_ready[FD_SETSIZE];
    for(int i = 0; i < FD_SETSIZE; i += 1) {
        fd_ready[i] = -1;
    }
    int fd_read_maxi = -1;
    while(true) {
        fd_set set_re = set_all;
        int ready = select(fd_maxi + 1, &set_re, NULL, NULL, NULL);
        if(ready < 0) {
            perror("select");
            continue;
        }
        else if(ready == 0) {
            fprintf(stdout, "select timeout\n");
            continue;
        }
        if(FD_ISSET(fd_listen, &set_re)) {
            struct sockaddr_in addr_client;
            socklen_t len_client = sizeof(addr_client);
            int fd_client = accept(fd_listen, (struct sockaddr *)&addr_client, &len_client);
            char str[INET_ADDRSTRLEN];
            fprintf(stdout, "received %s:%d\n", inet_ntop(AF_INET, &addr_client.sin_addr, str, sizeof(str)), ntohs(addr_client.sin_port));
            int i = 0;
            for(; i < FD_SETSIZE; i += 1) {
                if(fd_ready[i] < 0) {
                    fd_ready[i] = fd_client;
                    break;
                }
            }
            if(fd_read_maxi < i) {
                fd_read_maxi = i;
            }

            FD_SET(fd_client, &set_all);
            if(fd_maxi < fd_client) {
                fd_maxi = fd_client;
            }            
            ready -= 1;
            if(ready <= 0) {
                continue;
            }
        }
        for(int i = 0; i <= fd_read_maxi; i += 1) {
            int fd_socket = fd_ready[i];
            if(fd_socket < 0) {
                continue;
            }           
            if(FD_ISSET(fd_socket, &set_re)) {
                char buffer[_buffer_size];
                int len = read(fd_socket, buffer, _buffer_size);
                buffer[len] = '\0';
                fprintf(stdout, "%s\n", buffer);
                if(len <= 0) {
                    close(fd_socket);
                    FD_CLR(fd_socket, &set_all);
                    fd_ready[i] = -1;
                } else {
                    for(int i = 0; i <= fd_read_maxi; i += 1) {
                        if(fd_ready[i] < 0) {
                            continue;
                        }
                        write(fd_ready[i], buffer, len);
                    }
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
