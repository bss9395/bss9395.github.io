#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void handler(int signo) {
    time_t rawtime;
    struct tm *timeinfo;
    char buf[BUFSIZ] = { '\0' };

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buf, BUFSIZ, "%Y-%m-%dT%H:%M:%S\n", timeinfo);
    //fprintf(stderr, "%s", buf);

    int fd = open("./timelog.txt", O_RDWR | O_CREAT | O_APPEND, 0664);
    if(-1 == fd) {
        perror("open");
        exit(1);
    }

    int len = write(fd, buf, strlen(buf));
    if(-1 == len) {
        perror("write");
        exit(1);
    }

    close(fd);
}

void setup(char *dir) {
    chdir(dir);
    umask(0022);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    //close(STDERR_FILENO);

    while(true) {
        fprintf(stderr, "child process: getpid = %d, getppid = %d, getpgid = %d, getsid = %d\n", getpid(), getppid(), getpgid(getpid()), getsid(0));
        sleep(1);
    }
}

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if(-1 == pid) {
        perror("fork");
        exit(1);
    }
    else if(0 == pid) {
        pid_t sid = setsid();
        if(-1 == sid) {
            perror("setsid");
            exit(1);
        }

        //signal(SIGALRM, handler);
        struct sigaction sigact;
        sigact.sa_handler = handler;
        sigact.sa_flags = 0;
        sigaction(SIGALRM, &sigact, NULL);

        struct itimerval timerval;
        timerval.it_value.tv_sec = 2;
        timerval.it_value.tv_usec = 0;
        timerval.it_interval.tv_sec = 2;
        timerval.it_interval.tv_usec = 0;
        setitimer(ITIMER_REAL, &timerval, NULL);

        setup("/tmp/");
    }
    else if(0 < pid) {
        sleep(1);
        fprintf(stderr, "parent process: pid = %d, getpid = %d, getppid = %d, getpgid = %d\n", pid, getpid(), getppid(), getpgid(getpid()));
        exit(0);
    }

    return 0;
}
