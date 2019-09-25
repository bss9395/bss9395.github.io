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

#if 0
int daemon(int nochdir, int noclose);
#endif // 0

void handler(int signo) {
    time_t rawtime;
    struct tm *timeinfo;
    char buf[BUFSIZ] = { '\0' };

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buf, BUFSIZ, "%Y-%m-%dT%H:%M:%S\n", timeinfo);
    // fprintf(stderr, "%s", buf);

    int fd = open("/tmp/timelog.txt", O_RDWR | O_CREAT | O_APPEND, 0664);
    if(-1 == fd) {
        perror("open file");
        exit(1);
    }

    int len = write(fd, buf, strlen(buf));
    if(-1 == len) {
        perror("write");
        exit(1);
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    // int ret = daemon(0, 0);
    int ret = daemon(0, 1);
    if(-1 == ret) {
        perror("daemon");
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

    while(true) {
        fprintf(stderr, "getpid = %d, getppid = %d, getpgid = %d, getsid = %d\n", getpid(), getppid(), getpgid(getpid()), getsid(0));
        sleep(1);
    }

    return 0;
}
