/* Dead_Lock.c
Author: BSS9395
Update: 2023-09-20T15:04:00+08@China-Guangdong-Zhanjiang+08
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void *fun1(void *arg) {
    int ret = pthread_mutex_lock(&mutex1);
    if (0 != ret) {
        printf("pthread_mutex_lock failed....\n"); 
        return NULL;
    }
    usleep(10);

    ret = pthread_mutex_lock(&mutex2);
    if (0 != ret) {
        printf("pthread_mutex_lock failed....\n"); 
        return NULL;
    }

    printf("线程1申请资源1和资源2成功....\n");
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
    pthread_exit(NULL);
}

void *fun2(void *arg) {
    int ret = pthread_mutex_lock(&mutex2);
    if (0 != ret) {
        printf("pthread_mutex_lock failed....\n"); 
        return NULL;
    }

    usleep(10);
    ret = pthread_mutex_lock(&mutex1);
    if (0 != ret) {
        printf("pthread_mutex_lock failed....\n"); 
        return NULL;
    }

    printf("线程2申请资源2和资源1成功....\n");
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    pthread_exit(NULL);
}


int main(void) {
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    pthread_t tid1 = -1;
    pthread_t tid2 = -1;
    pthread_create(&tid1, NULL, fun1, NULL);
    pthread_create(&tid2, NULL, fun2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    return 0;
}
