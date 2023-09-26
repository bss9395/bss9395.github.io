/* sigpending.c
Author: BSS9395
Update: 2023-09-18T10:30:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: sigpending
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

/*
#include <signal.h>
int sigpending(sigset_t *set);
*/


int main() {
    sigset_t set, old;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);
    sigaddset(&set, SIGKILL);
    sigprocmask(SIG_BLOCK, &set, &old);

    sigset_t pend;    
    for (int i = 0; true; i += 1) {
        sigpending(&pend);
        for (int j = 1; j < 32; j += 1) {
            if (sigismember(&pend, j) == true) {
                printf("1");
            }
            else {
                printf("0");
            }
        }
        printf("\n");
        sleep(1);
        if (10 <= i) {
            // sigprocmask(SIG_UNBLOCK, &set, NULL);
            sigprocmask(SIG_SETMASK, &old, NULL);
        }
    }

    return 0;

}