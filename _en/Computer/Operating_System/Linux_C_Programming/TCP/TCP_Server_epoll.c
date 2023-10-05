/* TCP_Server_epoll.c
Author: BSS9395
Update: 2023-09-30T10:30:00+08@China-Guangdong-Zhanjiang+08
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <stdbool.h>

static const int _buffer_size = 512;
static const char *_server_addr = "127.0.0.1";
static const int _server_port = 9395;

int main(int argc, char *argv[]) {
    int fd_listen = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr_server;
    memset(&addr_server, 0, sizeof(addr_server));
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(_server_port);
    addr_server.sin_addr.s_addr = INADDR_ANY;

    bind(fd_listen, (struct sockaddr *)&addr_server, sizeof(addr_server));
    listen(fd_listen, 10);

    int fd_epoll = epoll_create(1024);
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = fd_listen;
    epoll_ctl(fd_epoll, EPOLL_CTL_ADD, fd_listen, &event);

    struct epoll_event revents[1024];
    while(true) {
        int ready = epoll_wait(fd_epoll, revents, 1024, 3000);
        if(ready < 0) {
            perror("epoll_wait");
            continue;
        } else if(ready == 0) {
            // fprintf(stdout, "epoll_wait timeout\n");
            continue;
        }
        for(int i = 0; i < ready; i += 1) {
            if(revents[i].events & EPOLLIN) {
                if(fd_listen == revents[i].data.fd) {
                    struct sockaddr_in addr_client;
                    socklen_t len_client = sizeof(addr_client);
                    int fd_client = accept(fd_listen, (struct sockaddr *)&addr_client, &len_client);
                    fprintf(stdout, "accept %s:%d\n", inet_ntoa(addr_client.sin_addr), ntohs(addr_client.sin_port));

                    struct epoll_event event;
                    event.events = EPOLLIN;
                    event.data.fd = fd_client;
                    epoll_ctl(fd_epoll, EPOLL_CTL_ADD, fd_client, &event);                    
                } else {
                    int fd_client = revents[i].data.fd;
                    char buffer[_buffer_size];
                    int len = read(fd_client, buffer, _buffer_size);
                    if(len <= 0) {
                        perror("read");
                        epoll_ctl(fd_epoll, EPOLL_CTL_DEL, fd_client, NULL);
                        continue;
                    }
                    buffer[len] = '\0';
                    fprintf(stdout, "%s\n", buffer);
                    write(fd_client, buffer, strlen(buffer));
                }
            }
        }
    }

    close(fd_listen);
    return 0;
}