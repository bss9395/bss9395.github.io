#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static pthread_mutex_t mutex1;
static pthread_mutex_t mutex2;

void *thread01(void *args) {
	int ret1 = pthread_mutex_lock(&mutex1);
	if(ret1) {
		printf("failed.\n");
		pthread_exit(NULL);
	}
	usleep(10);

	printf("thread01 mutex1\n");

	int ret2 = pthread_mutex_lock(&mutex2);
	if(ret2) {
		printf("failed.\n");
		pthread_exit(NULL);
	}
	usleep(10);

	printf("thread01 mutex2\n");

	pthread_mutex_unlock(&mutex2);
	pthread_mutex_unlock(&mutex1);
	pthread_exit(NULL);
}

void *thread02(void *args) {
	int ret2 = pthread_mutex_lock(&mutex2);
	if(ret2) {
		printf("failed.\n");
		pthread_exit(NULL);
	}
	usleep(10);

	printf("thread02 mutex2\n");

	int ret1 = pthread_mutex_lock(&mutex1);
	if(ret1) {
		printf("failed.\n");
		pthread_exit(NULL);
	}
	usleep(10);

	printf("thread02 mutex1\n");

	pthread_mutex_unlock(&mutex1);
	pthread_mutex_unlock(&mutex2);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);

	pthread_t tid1;
	pthread_t tid2;
	pthread_create(&tid1, NULL, thread01, NULL);
	pthread_create(&tid2, NULL, thread02, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);
	return 0;
}
