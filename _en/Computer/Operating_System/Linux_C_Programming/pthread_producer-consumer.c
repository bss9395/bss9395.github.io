#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5
static long buffer[N] = { 0 };
static int w = 0;
static int r = 0;
static pthread_cond_t not_empty;
static pthread_cond_t not_full;
static pthread_mutex_t mutex;

static pthread_t tids[4];

void *producer(void *args) {
    while(true) {
        pthread_mutex_lock(&mutex);

        while(w == N) {
            printf("producer%lu: wait not_full\n", (unsigned long)args);
            int ret = pthread_cond_wait(&not_full, &mutex);
            printf("producer%lu: ret = %d\n", (unsigned long)args, ret);
        }

        buffer[(r + w) % N] = w + 1;

        printf("producer%lu: ", (unsigned long)args);
        for(int i = 0; i < N; ++i) {
        	printf("%ld", buffer[i]);
        }
        printf("\n");

        w++;

        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&not_empty);
        sleep(rand() % 3 + 2);
    }

    for(int i = 0; i < sizeof(tids) / sizeof(*tids); ++i) {
        pthread_cancel(tids[i]);
    }
    pthread_exit(NULL);
}

void *consumer(void *args) {
    while(true){
        pthread_mutex_lock(&mutex);

        while(w == 0) {
            printf("consumer%lu: wait not_empty\n", (unsigned long)args);
            int ret = pthread_cond_wait(&not_empty, &mutex);
            printf("consumer%lu: ret = %d\n", (unsigned long)args, ret);
        }

        buffer[r] = 0;

        printf("consumer%lu: ", (unsigned long)args);
        for(int i = 0; i < N; ++i) {
        	printf("%ld", buffer[i]);
        }
        printf("\n");

        if(++r, r == N) {
        	r = 0;
        }
        w--;

        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&not_full);
		sleep(rand() % 3 + 2);
    }

    for(int i = 0; i < sizeof(tids) / sizeof(*tids); ++i) {
        pthread_cancel(tids[i]);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
    pthread_cond_init(&not_empty, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&tids[0], NULL, producer, (void *)0x01);
    pthread_create(&tids[1], NULL, producer, (void *)0x02);
    pthread_create(&tids[2], NULL, consumer, (void *)0x01);
    //pthread_create(&tids[3], NULL, consumer, (void *)0x02);

    for(int i = 0; i < sizeof(tids) / sizeof(*tids); ++i) {
		pthread_join(tids[i], NULL);
	}

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);
    return 0;
}
