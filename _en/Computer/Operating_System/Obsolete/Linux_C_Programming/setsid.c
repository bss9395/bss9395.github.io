/* setsid.c
Author: BSS9395
Update: 2023-09-18T17:37:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: setsid
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>

/*
#include <unistd.h>
pid_t setsid(void);
*/

void _Log_Time(int sig) {
    time_t time_raw;
    time(&time_raw);

    struct tm *time_now = localtime(&time_raw);
    char *time_current = asctime(time_now);
    // char *time_current = ctime(time_raw);

    int fd = open("/tmp/log_time.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
    if(fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    write(fd, time_current, strlen(time_current));
    close(fd);
}

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if(pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if(pid == 0) {
        setsid();
        chdir("/home/brilliant");
        umask(0022);
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        signal(SIGALRM, _Log_Time);

        struct itimerval timer;
        timer.it_value.tv_sec = 2;
        timer.it_value.tv_usec = 0;
        timer.it_interval.tv_sec = 2;
        timer.it_interval.tv_usec = 0;
        setitimer(ITIMER_REAL, &timer, NULL);

        while(true);
    } else if(0 < pid) {
        exit(EXIT_SUCCESS);
    }

    return 0;
}
