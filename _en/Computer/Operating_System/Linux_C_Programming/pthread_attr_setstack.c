/* pthread_attr_setstack.c
Author: BSS9395
Update: 2023-09-19T16:20:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: pthread_attr_setstack
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

/*
#include <pthread.h>
int pthread_attr_setstack(pthread_attr_t *attr, void *stackaddr, size_t stacksize);
int pthread_attr_getstack(const pthread_attr_t *attr, void **stackaddr, size_t *stacksize);
// Compile and link with -pthread.
*/

void *thread_func(void *arg) {
    while(true) {
        fprintf(stdout, "child thread: getpid() = %d, getppid() = %d\n", getpid(), getppid());
        sleep(1);
    }
}

int main(int argc, char *argv[]) {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    const int size = 0x100000;
    void *address = malloc(size);
    if(address == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    pthread_attr_setstack(&attr, address, size);
    pthread_t tid;
    int err = pthread_create(&tid, &attr, thread_func, NULL);
    if(err != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }
    pthread_detach(tid);

    while(true) {
        fprintf(stdout, "main thread: getpid() = %d, getppid() = %d\n", getpid(), getppid());
        sleep(1);
    }

    return 0;
}
