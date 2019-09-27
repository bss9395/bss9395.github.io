#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
#endif // 0

static pthread_mutex_t power;
static long count = 0;

void poweron() {
    int ret = pthread_mutex_trylock(&power);
    //fprintf(stdout, "poweron: ret = %d\n", ret);
    if(!ret) {
        fprintf(stdout, "printer power on...\n");
        pthread_mutex_unlock(&power);
    }
}

void printer(const char *content) {
    poweron();

    pthread_mutex_lock(&power);
    while(*content) {
        fputc(*content, stdout);
        fflush(stdout);
        content++;

        count++;
        usleep(100 * 1000);
    }
    pthread_mutex_unlock(&power);
}

void *thread01(void *args) {
    printer("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");

    pthread_exit(NULL);
}

void *thread02(void *args) {
    printer("abcdefghijklmnopqrstuvwxyz\n");

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_mutex_init(&power, NULL);

    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1, NULL, thread01, NULL);
    pthread_create(&tid2, NULL, thread02, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("count = %ld\n", count);
    pthread_mutex_destroy(&power);
    return 0;
}