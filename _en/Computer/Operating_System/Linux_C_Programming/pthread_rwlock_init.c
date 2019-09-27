#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);
int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock, const pthread_rwlockattr_t *restrict attr);
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;
#endif // 0

static pthread_rwlock_t rwlock;
static long count = 0;

void *reader(void *args) {
	for(int i = 0; i < 10; ++i) {
		pthread_rwlock_rdlock(&rwlock);
		printf("reader%lu: count = %ld\n", (unsigned long)args, count);
		pthread_rwlock_unlock(&rwlock);
		usleep((rand() % 500 + 500) * 1000);
	}

	pthread_exit(NULL);
}

void *writer(void *args) {
	for(int i = 1; i <= 5; ++i) {
		pthread_rwlock_wrlock(&rwlock);
		count++;
		printf("writer%lu: count = %ld\n", (unsigned long)args, count);
		pthread_rwlock_unlock(&rwlock);
		usleep((rand() % 500 + 500) * 1000);
	}

	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	pthread_rwlock_init(&rwlock, NULL);

	pthread_t tid1;
	pthread_t tid2;
	pthread_t tid3;
	pthread_t tid4;
	pthread_create(&tid1, NULL, reader, (void *)0x01);
	pthread_create(&tid2, NULL, reader, (void *)0x02);
	pthread_create(&tid3, NULL, writer, (void *)0x01);
	pthread_create(&tid4, NULL, writer, (void *)0x02);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);

	pthread_rwlock_destroy(&rwlock);
	return 0;
}