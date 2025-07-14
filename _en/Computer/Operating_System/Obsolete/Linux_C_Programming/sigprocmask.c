/* sigpromask.c
Author: BSS9395
Update: 2023-09-18T10:00:00=08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: sigpromask
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <signal.h>

/*
#include <signal.h>
int sigprocmask(int how, const sigset_t *restrict set, sigset_t *restrict oset);
*/

void fun(int signo) {
    printf("²¶×½µ½ÐÅºÅ: %d\n", signo);
}

int main(void) {
    signal(SIGINT, fun);
    signal(SIGQUIT, fun);

    sigset_t set;
    sigset_t oldset;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);

    sigprocmask(SIG_BLOCK, &set, &oldset);   
    getchar();

    sigprocmask(SIG_SETMASK, &oldset, NULL);
    getchar();

    return 0;
}
