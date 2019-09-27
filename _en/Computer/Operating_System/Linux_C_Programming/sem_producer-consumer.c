#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	long data;
	struct Node *next;
} Node;
Node head = { .next = NULL };

#define N 5
static sem_t sem_produce;
static sem_t sem_consume;
static pthread_mutex_t mutex;
static long count = 0;

static pthread_t tids[4];

void *producer(void *args) {
	while(true) {
		sem_wait(&sem_produce);
		pthread_mutex_lock(&mutex);

		Node *node = (Node *)malloc(sizeof(Node));
		node->data = ++count % N + 1;
		node->next = head.next;
		head.next = node;

		printf("producer%lu: ", (unsigned long)args);
		Node *it = head.next;
		while(it != NULL) {
			printf("%ld", it->data);
			it = it->next;
		}
		printf("\n");

		pthread_mutex_unlock(&mutex);
		sem_post(&sem_consume);

		usleep(rand() % 500 + 500);
	}

	for(int i = 0; i < sizeof(tids) / sizeof(*tids); ++i) {
		pthread_cancel(tids[i]);
	}
	pthread_exit(NULL);
}

void *consumer(void *args) {
	while(true) {
		sem_wait(&sem_consume);
		pthread_mutex_lock(&mutex);
		Node *node = head.next;
		head.next = node->next;
		free(node);

		printf("consumer%lu: ", (unsigned long)args);
		Node *it = head.next;
		while(it != NULL) {
			printf("%ld", it->data);
			it = it->next;
		}
		printf("\n");

		pthread_mutex_unlock(&mutex);
		sem_post(&sem_produce);

		sleep(1);
	}

	for(int i = 0; i < sizeof(tids) / sizeof(*tids); ++i) {
		pthread_cancel(tids[i]);
	}
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	sem_init(&sem_produce, 0, N - 1);
	sem_init(&sem_consume, 0, 0);
	pthread_mutex_init(&mutex, NULL);

	pthread_create(&tids[0], NULL, producer, (void *)0x01);
	pthread_create(&tids[1], NULL, producer, (void *)0x02);
	pthread_create(&tids[2], NULL, consumer, (void *)0x01);
	//pthread_create(&tids[3], NULL, consumer, (void *)0x02);

	for(int i = 0; i < sizeof(tids) / sizeof(*tids); ++i) {
		pthread_join(tids[i], NULL);
	}

	pthread_mutex_destroy(&mutex);
	sem_destroy(&sem_consume);
	sem_destroy(&sem_produce);
	return 0;
}