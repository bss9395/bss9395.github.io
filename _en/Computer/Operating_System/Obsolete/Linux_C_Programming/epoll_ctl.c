/* epoll_ctl.c
Author: BSS9395
Update: 2023-09-29T10:51:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: epoll_ctl
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>

/*
#include <sys/epoll.h>
int epoll_create(int size);
int epoll_create1(int flags);
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
int epoll_pwait(int epfd, struct epoll_event *events, int maxevents, int timeout, const sigset_t *sigmask);
*/

int main(int argc, char *argv[]) {
    struct epoll_event event;
    int fd_epoll = epoll_create(1024);
    fprintf(stdout, "fd_epoll = %d\n", fd_epoll);

    event.events = EPOLLIN;
    event.data.fd = STDIN_FILENO;

    int ret = epoll_ctl(fd_epoll, EPOLL_CTL_ADD, STDIN_FILENO, &event);
    if(ret == -1) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "EPOLL_CTL_ADD success\n");

    ret = epoll_ctl(fd_epoll, EPOLL_CTL_MOD, STDIN_FILENO, &event);
    if(ret == -1) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "EPOLL_CTL_MOD success\n");

    ret = epoll_ctl(fd_epoll, EPOLL_CTL_DEL, STDIN_FILENO, NULL);
    if(ret == -1) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "EPOLL_CTL_DEL success\n");

    close(fd_epoll);
    return 0;
}