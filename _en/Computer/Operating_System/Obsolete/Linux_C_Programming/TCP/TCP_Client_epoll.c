/* TCP_Client_epoll.c
Author: BSS9395
Update: 2023-09-30T10:30:00+08@China-Guangdong-Zhanjiang+08
*/#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
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

    int fd_epoll = epoll_create(1024);
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = STDIN_FILENO;
    epoll_ctl(fd_epoll, EPOLL_CTL_ADD, STDIN_FILENO, &event);
    event.events = EPOLLIN;
    event.data.fd = fd_client;
    epoll_ctl(fd_epoll, EPOLL_CTL_ADD, fd_client, &event);

    struct epoll_event revents[2];
    while(true) {
        int ready = epoll_wait(fd_epoll, revents, 2, 3000);
        if(ready < 0) {
            perror("epoll_wait");
            continue;
        } else if(ready == 0) {
            // fprintf(stdout, "epoll_wait timeout\n");
            continue;
        }
        for(int i = 0; i < ready; i += 1) {
            if(revents[i].events * EPOLLIN) {
                if(revents[i].data.fd == STDIN_FILENO) {
                    char buffer[_buffer_size];
                    fgets(buffer, _buffer_size, stdin);
                    if(buffer[strlen(buffer) - 1] == '\n') {
                        buffer[strlen(buffer) - 1] = '\0';
                    }
                    write(fd_client, buffer, strlen(buffer));
                } else if(revents[i].data.fd == fd_client) {
                    char buffer[_buffer_size];
                    int len = read(fd_client, buffer, _buffer_size);
                    if(len <= 0) {
                        perror("read");
                        epoll_ctl(fd_epoll, EPOLL_CTL_DEL, fd_client, NULL);
                        continue;
                    } 
                    buffer[len] = '\0';
                    fprintf(stdout, "%s\n", buffer);
                }
            } 
            
        }

    }

    return 0;
}
