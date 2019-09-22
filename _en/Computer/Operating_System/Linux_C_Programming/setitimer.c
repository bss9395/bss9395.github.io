#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
int getitimer(int which, struct itimerval *curr_value);
int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);
#endif // 0

void func(int sig) {
	printf("func: signal = %d, getpid = %d, getppid = %d\n", sig, getpid(), getppid());
}

int main(int argc, char *argv[]) {
	struct itimerval timerval;
    timerval.it_interval.tv_sec = 1;
    timerval.it_interval.tv_usec = 0;
    timerval.it_value.tv_sec = 2;
    timerval.it_value.tv_usec = 0;

    signal(SIGALRM, func);
    setitimer(ITIMER_REAL, &timerval, NULL);

    int ch = '\0';
    if(ch = getchar()) {
    	alarm(0);
    }

    while(true) {
        printf("main: getpid = %d, getppid = %d\n", getpid(), getppid());
        sleep(1);
    }

	return 0;
}
