#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#if 0
int pthread_attr_setstack(pthread_attr_t *attr, void *stackaddr, size_t stacksize);
int pthread_attr_getstack(const pthread_attr_t *attr, void **stackaddr, size_t *stacksize);
// Compile and link with -pthread.
int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize);
int pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *stacksize);
// Compile and link with -pthread.
#endif // 0

void *routine(void *args) {
    for(int i = 0; i < 3; ++i) {
        printf("child thread: gettid = %lu, getpid = %d, getppid = %d, getpgid = %d, getsid = %d\n", pthread_self(), getpid(), getppid(), getpgid(getpid()), getsid(0));
        sleep(1);
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_attr_t attr;
    int state = 0;
    size_t size = 0;

    pthread_attr_init(&attr);
    pthread_attr_getdetachstate(&attr, &state);
    pthread_attr_getstacksize(&attr, &size);
    if(PTHREAD_CREATE_JOINABLE == state) {
        printf("PTHREAD_CREATE_JOINABLE = %d\n", state);
    }
    else if(PTHREAD_CREATE_DETACHED == state) {
        printf("PTHREAD_CREATE_DETACHED = %d\n", state);
    }
    else {
        printf("state = %d\n", state);
    }
    printf("stack size = %lu\n", size);

    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    // pthread_attr_setstacksize(&attr, size);
    void *addr = malloc(size);
    pthread_attr_setstack(&attr, addr, size);

    pthread_t tid;
    int ret = pthread_create(&tid, &attr, routine, NULL);
    if(ret) {
        printf("failed: pthread_create\n");
        exit(1);
    }

    pthread_attr_destroy(&attr);
    for(int i = 0; i < 5; ++i) {
    	printf("main thread: gettid = %lu, getpid = %d, getppid = %d, getpgid = %d, getsid = %d\n", pthread_self(), getpid(), getppid(), getpgid(getpid()), getsid(0));
        sleep(1);
    }

    return 0;
}
