#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
#include <sys/time.h>
int getitimer(int which, struct itimerval *curr_value);
int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);
*/

void fun(int signo) {
    static char label[5] = { '\0' };
    static char bar[12] = { '\0' };
    static int i = 0;

    snprintf(label, 5, "%3d%%", (int)(100.0 * i / 10));
    bar[i] = (i == 0)? ' ' : '=';
    i++;

    fprintf(stdout, "\r%s%s", label, bar);
    fflush(stdout);

    if(10 < i) {
        memset(label, 0, 5);
        memset(bar, 0, 12);
        i = 0;
        setitimer(ITIMER_REAL, NULL, NULL);
    }
}

int main(int argc, char *argv[]) {
    signal(SIGALRM, fun);
    struct itimerval timerval;
    timerval.it_value.tv_sec = 0;
    timerval.it_value.tv_usec = 500000;
    timerval.it_interval.tv_sec = 0;
    timerval.it_interval.tv_usec = 200000;
    setitimer(ITIMER_REAL, &timerval, NULL);

    static int i = 0;
    while(true) {
        sleep(10);
        fprintf(stderr, "i = %d, getpid = %d, getppid = %d\n", i, getpid(), getppid()); 
        i += 1;
    }

    return 0;
}
