#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int pthread_cond_destroy(pthread_cond_t *cond);
int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
#endif // 0

static pthread_cond_t cond;
static pthread_mutex_t mutex;
static long count = 0;

static pthread_t tid1;
static pthread_t tid2;

void *calculate(void *args) {
    for(int i = 0; i < 10; ++i) {
        pthread_mutex_lock(&mutex);
        count++;
        if(count % 3 == 0) {
            //pthread_cond_signal(&cond);
            pthread_cond_broadcast(&cond);
        }
        pthread_mutex_unlock(&mutex);
        usleep(500 * 1000);
    }

    pthread_cancel(tid2);
    pthread_exit(NULL);
}

void *print(void *args) {
    while(true) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        printf("count = %ld\n", count);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);


    pthread_create(&tid1, NULL, calculate, NULL);
    pthread_create(&tid2, NULL, print, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}