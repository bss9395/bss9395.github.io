#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5
static pthread_mutex_t mutex[N];
static pthread_t tids[N];
static long count = 0;

void *dine(void *args) {
	int left = (int)(size_t)args;
	int right = (left + 1) % N;

	while(true) {
		pthread_mutex_lock(&mutex[left]);
		if(!pthread_mutex_trylock(&mutex[right])) {
			printf("%ld: philosopher %c is eating...\n", ++count, left + 'A');
			pthread_mutex_unlock(&mutex[right]);
		}
		pthread_mutex_unlock(&mutex[left]);
		sleep(rand() % N + 1);
	}

	for(int i = 0; i < N; ++i) {
		pthread_cancel(tids[i]);
	}
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	for(int i = 0; i < N; ++i) {
		pthread_mutex_init(&mutex[i], NULL);
	}

	for(int i = 0; i < N; ++i) {
		pthread_create(&tids[i], NULL, dine, (void *)(size_t)i);
	}

	for(int i = 0; i < N; ++i) {
		pthread_join(tids[i], NULL);
	}

	for(int i = 0; i < N; ++i) {
		pthread_mutex_destroy(&mutex[i]);
	}
	return 0;
}