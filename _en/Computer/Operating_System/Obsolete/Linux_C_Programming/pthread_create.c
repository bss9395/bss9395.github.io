#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
#include <pthread.h>
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
// Compile and link with -lpthread.
*/

void *routine(void *args) {
    double *num = (double *)args;
    while(true) {
        printf("child thread: args = %lf, gettid = %lu, getpid = %d, getppid = %d, getpgid = %d, getsid = %d\n", *num, pthread_self(), getpid(), getppid(), getpgid(getpid()), getsid(0));
        sleep(1);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t tid;
    double args = 12;
    int ret = pthread_create(&tid, NULL, routine, (void *)(&args));
    if(0 != ret) {
        strerror(ret);
        exit(1);
    }

    while(true) {
        printf("main thread: gettid = %lu, getpid = %d, getppid = %d, getpgid = %d, getsid = %d\n", pthread_self(), getpid(), getppid(), getpgid(getpid()), getsid(0));
        sleep(1);
    }

    return 0;
}
