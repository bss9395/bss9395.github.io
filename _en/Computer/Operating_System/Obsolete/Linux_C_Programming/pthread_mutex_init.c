/* pthread_mutex_init.c
Author: BSS9395
Update: 2023-09-20T12:00:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: pthread_mutex_init
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

/*
#include <pthread.h>
int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
*/

int main(int argc, char *argv[]) {
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);
    // pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    pthread_mutex_destroy(&mutex);

    return 0;
}