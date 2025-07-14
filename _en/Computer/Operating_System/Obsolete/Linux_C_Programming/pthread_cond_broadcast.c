#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

/*
#include <pthread.h>
int pthread_cond_broadcast(pthread_cond_t *cond);
int pthread_cond_signal(pthread_cond_t *cond);
*/

typedef struct node {
    int data;
    struct node* next;
} Node;

Node *head = NULL;
pthread_mutex_t mutex;
pthread_cond_t cond;

void* producer(void* arg) {
    while(true) {
        Node* pnew = (Node*)malloc(sizeof(Node));
        pnew->data = rand() % 1000;
        pthread_mutex_lock(&mutex);
        pnew->next = head;
        head = pnew;
        printf("Producer: %lu, %d\n", pthread_self(), pnew->data);
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 3);
    }
    return NULL;
}

void* customer(void* arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        while (head == NULL) {                 // note: 使用while而不是if
            pthread_cond_wait(&cond, &mutex);  // note: 该函数会对互斥锁解锁。解除阻塞之后，对互斥锁做加锁操作。
        }

        Node* pdel = head;
        head = head->next;
        printf("Customer: %lu, %d\n", pthread_self(), pdel->data);
        free(pdel);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}


int main(int argc, const char* argv[]) {
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_t p1;
    pthread_t p2;
    pthread_t c1;
    pthread_t c2;
    pthread_create(&p1, NULL, producer, NULL);
    pthread_create(&p2, NULL, producer, NULL);
    pthread_create(&c1, NULL, customer, NULL);
    pthread_create(&c2, NULL, customer, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(c1, NULL);
    pthread_join(c2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}
