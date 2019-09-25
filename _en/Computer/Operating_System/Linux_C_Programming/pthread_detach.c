#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int pthread_detach(pthread_t thread);
// Compile and link with -pthread.
#endif // 0

void *routine(void *args) {
    for(int i = 0; i < 5; ++i) {
        printf("child thread: gettid = %lu, getpid = %d, getppid = %d, getpgid = %d, getsid = %d\n", pthread_self(), getpid(), getppid(), getpgid(getpid()), getsid(0));
    }

    return (void *)0x02;
}

int main(int argc, char *argv[]) {
    pthread_t tid;
    pthread_create(&tid, NULL, routine, NULL);

    pthread_detach(tid);
    //pthread_cancel(tid);

    void *retval = (void *)0x01;
    int ret = pthread_join(tid, (void **)&retval);
    printf("ret = %d, retval = %p\n", ret, retval);
    if(ret) {
        printf("error\n");

    }
    else {
        printf("sucess\n");
    }
    if(PTHREAD_CANCELED == retval) {
        printf("canceled\n");
    }

    return 0;
}
