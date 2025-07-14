/* pthread_mutex_lock.c
Author: BSS9395
Update: 2023-09-20T11:55:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: pthread_mutex_lock
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/*
#include <pthread.h>
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
*/

pthread_mutex_t mutex;

void _Printer(const char *str) {
    while(str[0] != '\0') {
        putchar(str[0]);
        fflush(stdout);
        str += 1;
        usleep(100000);
    }
    putchar('\n');
}

void *_Printer_A(void *arg) {
    pthread_mutex_lock(&mutex);
    _Printer("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    pthread_mutex_unlock(&mutex);
}

void *_Printer_a(void *arg) {
    pthread_mutex_lock(&mutex);
    _Printer("abcdefghijklmnopqrstuvwxyz");
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char *argv[]) {
    pthread_t tid_A;
    pthread_t tid_a;

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&tid_A, NULL, _Printer_A, NULL);
    pthread_create(&tid_a, NULL, _Printer_a, NULL);
    pthread_join(tid_A, NULL);
    pthread_join(tid_a, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}