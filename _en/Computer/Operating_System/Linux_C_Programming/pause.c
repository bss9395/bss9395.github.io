#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>

#if 0
int pause(void);
#endif // 0

void sighandler(int signo) {
    printf("sighandler\n");
}

int timer(int sec) {
    printf("timer begin...\n");
    alarm(sec);
    pause();
    printf("timer end...\n");
}

int main(int argc, char *argv[]) {
    signal(SIGALRM, sighandler);

    while(true) {
        timer(1);
    }

    return 0;
}
