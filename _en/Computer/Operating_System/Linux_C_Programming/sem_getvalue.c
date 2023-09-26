#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <semaphore.h>

/*
#include <semaphore.h>
int sem_getvalue(sem_t *sem, int *sval);
// Link with -pthread.
*/

int main(int argc, char *argv[]) {
    sem_t sem;
    sem_init(&sem, 0, 3);

    int value = 0;
    sem_getvalue(&sem, &value);
    printf("–≈∫≈¡øval = %d\n", value);

    sem_wait(&sem);
    sem_wait(&sem);
    sem_wait(&sem);
    sem_getvalue(&sem, &value);
    printf("sem_getvalue = %d\n", value);

    sem_post(&sem);
    sem_getvalue(&sem, &value);
    printf("sem_getvalue = %d\n", value);
    
    sem_destroy(&sem);
    return 0;
}
