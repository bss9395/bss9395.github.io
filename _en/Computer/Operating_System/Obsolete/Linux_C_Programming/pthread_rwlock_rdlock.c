/* pthread_rwlock_rdlock.c
Author: BSS9395
Update: 2023-09-20T15:15:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: pthread_rwlock_rdlock
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>

/*
#include <pthread.h>
int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
*/

int main(void) {
    pthread_rwlock_t rwlock;
    pthread_rwlock_init(&rwlock, NULL);    

    pthread_rwlock_rdlock(&rwlock);
    printf("��һ����������ɹ�.....\n");
    pthread_rwlock_rdlock(&rwlock);
    printf("�ڶ�����������ɹ�.....\n");
    pthread_rwlock_unlock(&rwlock);
    pthread_rwlock_unlock(&rwlock);

    pthread_rwlock_wrlock(&rwlock);
    printf("����������д���ɹ�....\n");
    pthread_rwlock_unlock(&rwlock);

    pthread_rwlock_destroy(&rwlock);
    return 0;
}
