/* epoll_wait.c
Author: BSS9395
Update: 2023-09-29T11:03:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: epoll_wait
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <stdbool.h>

/*
#include <sys/epoll.h>
int epoll_create(int size);
int epoll_create1(int flags);
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
int epoll_pwait(int epfd, struct epoll_event *events, int maxevents, int timeout, const sigset_t *sigmask);
*/

int main(int argc, char *argv[]) {
    int fd_epoll = epoll_create(1024);

    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = STDIN_FILENO;
    epoll_ctl(fd_epoll, EPOLL_CTL_ADD, STDIN_FILENO, &event);

    struct epoll_event revent[1];
    while(true) {
        int ready = epoll_wait(fd_epoll, revent, 1, 3000);
        if(ready < 0) {
            perror("epoll_wait");
            continue;
        } else if(ready == 0) {
            fprintf(stdout, "epoll_wait timeout\n");
            continue;
        }
        if(revent[0].events & EPOLLIN) {
            char buffer[1024];
            fgets(buffer, 1024, stdin);
            if(buffer[strlen(buffer) - 1] == '\n') {
                buffer[strlen(buffer) - 1] = '\0';
            }
            fprintf(stdout, "%s\n", buffer);
        }

    }

    close(fd_epoll);
    return 0;
}
