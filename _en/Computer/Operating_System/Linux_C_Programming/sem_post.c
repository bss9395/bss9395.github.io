#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
#include <semaphore.h>
int sem_post(sem_t *sem);
// Link with -pthread.
*/

static sem_t power;
static long count = 0;

void printer(const char *content) {
	sem_wait(&power);
	while(content[0] != '\0') {
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
