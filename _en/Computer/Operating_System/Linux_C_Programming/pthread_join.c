#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int pthread_join(pthread_t thread, void **retval);
// Compile and link with -pthread.
#endif // 0

void *routine(void *args) {
	double *num = (double *)args;
	for(int i = 0; i < 5; ++i) {
		printf("child thread: args = %lf, gettid = %lu, getpid = %d, getppid = %d, getpgid = %d, getsid = %d\n", *num, pthread_self(), getpid(), getppid(), getpgid(getpid()), getsid(0));
		(*num)++;
		sleep(1);
	}

	return (void *)0x02;
}

int main(int argc, char *argv[]) {
	pthread_t tid;
	double args = 12;
	pthread_create(&tid, NULL, routine, (void *)(&args));

	void *retval = NULL;
	pthread_join(tid, (void **)&retval);
	printf("return value = %p\n", retval);

	while(true) {
		printf("main thread: gettid = %lu, getpid = %d, getppid = %d, getpgid = %d, getsid = %d\n", pthread_self(), getpid(), getppid(), getpgid(getpid()), getsid(0));
		sleep(1);
	}

	return 0;
}