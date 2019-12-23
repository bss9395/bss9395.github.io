/* process_monitoring.c
* Author: BSS9395
* Update: 2019-12-23T17:55:00+08@ShenZhen
* Design: Monitoring
*/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void checkError(bool failed, const char *file, long line, const char *func, const char *msg) {
    if(failed) {
        fprintf(stderr, "\e[33m""%s==%ld==%s==[%d]%s""\e[0m", file, line, func, errno, msg);
        if(errno) {
            exit(EXIT_FAILURE);
        }
    }
}

void monitoring(bool daemon){
    int log_fd = open("log.txt", O_WRONLY | O_CREAT, 0664);
    checkError(log_fd < 0, __FILE__, __LINE__, __FUNCTION__, "open");

    int stdout_fd = dup2(log_fd, STDOUT_FILENO);
    checkError(stdout_fd < 0, __FILE__, __LINE__, __FUNCTION__, "dup2");

    if(daemon) {
        pid_t pid = fork();
        checkError(pid < 0, __FILE__, __LINE__, __FUNCTION__, "fork");
        if(pid == 0) {
            pid_t sid = setsid();
            checkError(sid < 0, __FILE__, __LINE__, __FUNCTION__, "setsid");
        }
        else if(pid > 0) {
            exit(EXIT_SUCCESS);
        }
    }

    while(true){
        pid_t pid = fork();
        checkError(pid < 0, __FILE__, __LINE__, __FUNCTION__, "fork");
        if(pid == 0) {
            fprintf(stderr, "child  %s: getpid = %d, getppid = %d\n", __FUNCTION__, getpid(), getppid());
            break;
        }
        else if(pid > 0) {
            fprintf(stderr, "parent %s: getpid = %d, getppid = %d\n", __FUNCTION__, getpid(), getppid());
            int status = 0;
            int child = waitpid(-1, &status, 0);
            if(WEXITSTATUS(status) == 0) {
                exit(EXIT_SUCCESS);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    bool daemon = false;
    for(int i = 1; i < argc; ++i) {
        if(0 == strcmp(argv[i], "daemon")) {
            daemon = true;
        }
    }

    monitoring(daemon);

    int i = 0;
    while(true){
        sleep(1);
        fprintf(stderr, "%s: getpid = %d, getppid = %d\n", __FUNCTION__, getpid(), getppid());
        i += 1;
        if(i == 5) {
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
