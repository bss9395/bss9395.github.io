#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int sem_wait(sem_t *sem);
int sem_trywait(sem_t *sem);
int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);
//Link with -pthread.
#endif // 0

static sem_t power;
static long count = 0;

void poweron() {
	int ret = sem_trywait(&power);
	// fprintf(stdout, "poweron: ret = %d\n", ret);
	if(!ret) {
		fprintf(stdout, "printer power on\n");
		sem_post(&power);
	}
}

void printer(const char *content) {
	poweron();

	sem_wait(&power);
	while(*content) {
		fputc(*content, stdout);
		fflush(stdout);
		content++;

		count++;
		usleep(100 * 1000);
	}
	sem_post(&power);
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
	sem_init(&power, 0, 1);

	pthread_t tid1;
	pthread_t tid2;
	pthread_create(&tid1, NULL, thread01, NULL);
	pthread_create(&tid2, NULL, thread02, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("count = %ld\n", count);

	sem_destroy(&power);
	return 0;
}