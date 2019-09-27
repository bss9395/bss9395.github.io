#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
int pthread_mutex_destroy(pthread_mutex_t *mutex);
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#endif // 0

static pthread_mutex_t mutex;
static long count = 0;

void printer(const char *content) {
	pthread_mutex_lock(&mutex);
	while(*content) {
		fputc(*content, stdout);
		fflush(stdout);
		content++;

		count++;
		usleep(100 * 1000);
	}
	fputc('\n', stdout);
	pthread_mutex_unlock(&mutex);
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
	pthread_mutex_init(&mutex, NULL);

	pthread_t tid1;
	pthread_create(&tid1, NULL, thread01, NULL);
	pthread_t tid2;
	pthread_create(&tid2, NULL, thread02, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("count = %ld\n", count);
	pthread_mutex_destroy(&mutex);
	return 0;
}