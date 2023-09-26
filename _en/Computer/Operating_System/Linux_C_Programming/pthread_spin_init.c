#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

pthread_spinlock_t spinlock;
int data;

void *thread_work_func(void *dev) {
    while(true) {
        pthread_spin_lock(&spinlock);
        printf("data=%d\n",data);
        pthread_spin_unlock(&spinlock);
        sleep(1);
    }
}

void *thread_work_func2(void *dev) {
    while(true) {
        pthread_spin_lock(&spinlock); 
        data++;
        pthread_spin_unlock(&spinlock); 
        sleep(1);
    }
}

int main(int argc,char **argv) {  
    pthread_spin_init(&spinlock,PTHREAD_PROCESS_PRIVATE);

    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1, NULL, thread_work_func, NULL);
    pthread_create(&tid2, NULL, thread_work_func2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_spin_destroy(&spinlock);
    return 0;
}
