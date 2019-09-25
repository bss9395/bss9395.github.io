#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
void pthread_exit(void *retval);
// Compile and link with -pthread.
#endif // 0

void thread_exit() {
	pthread_exit((void *)0x02);
}

void *routine(void *args) {
	double *num = (double *)args;
	while(true) {
		printf("child thread: args = %lf, gettid = %lu, getpid = %d, getppid = %d, getpgid = %d, getsid = %d\n", *num, pthread_self(), getpid(), getppid(), getpgid(getpid()), getsid(0));
		(*num)++;
		if(17 <= *num) {
			thread_exit();
		}

		sleep(1);
	}

	return (void *)0x03;
}

int main(int argc, char *argv[]) {
	pthread_t tid;
	double args = 12;
	pthread_create(&tid, NULL, routine, (void *)(&args));

	void *ret = (void *)0x01;
	pthread_join(tid, (void **)&ret);
	printf("return value = %p\n", ret);

	while(true) {
		printf("main thread: gettid = %lu, getpid = %d, getppid = %d, getpgid = %d, getsid = %d\n", pthread_self(), getpid(), getppid(), getpgid(getpid()), getsid(0));
		sleep(1);
	}

	return 0;
}