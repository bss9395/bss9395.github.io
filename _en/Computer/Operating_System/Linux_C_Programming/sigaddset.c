/* sigaddset.c
Author: BSS9395
Update: 2023-09-18T09:50:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: sigaddset
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <sys/time.h>
#include <signal.h>

/*
#include <signal.h>
int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);
int sigaddset(sigset_t *set, int signum);
int sigdelset(sigset_t *set, int signum);
int sigismember(const sigset_t *set, int signum);
*/

int main() {
    sigset_t set; 
    sigemptyset(&set);
    int ret = sigismember(&set, SIGINT);
    if (ret == 0) {
        printf("SIGINT is not a member of set.\n");
    }

    sigaddset(&set, SIGINT); 
    sigaddset(&set, SIGQUIT);
    ret = sigismember(&set, SIGINT);
    if (ret == 1) {
        printf("SIGINT is a member of set.");
    }

    sigdelset(&set, SIGQUIT); 
    ret = sigismember(&set, SIGQUIT);
    if (ret == 0) {
        printf("SIGQUIT is not a member of set.");
    }

    return 0;

}