#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int getitimer(int which, struct itimerval *curr_value);
int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);
#endif // 0

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
    struct itimerval timerval;
    signal(SIGALRM, fun);

    timerval.it_value.tv_sec = 0;
    timerval.it_value.tv_usec = 500000;
    timerval.it_interval.tv_sec = 0;
    timerval.it_interval.tv_usec = 200000;
    setitimer(ITIMER_REAL, &timerval, NULL);

    while(true) {
        printf("getpid = %d, getppid = %d\n", getpid(), getppid());
        sleep(1);
    }

    return 0;
}
