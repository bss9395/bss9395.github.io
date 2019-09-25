#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int pthread_attr_init(pthread_attr_t *attr);
int pthread_attr_destroy(pthread_attr_t *attr);
// Compile and link with -pthread.
#endif // 0

void *routine(void *args) {
	for(int i = 0; i < 10; ++i) {
		printf("gettid = %lu, getpid = %d, getppid = %d, getpgid = %d, getsid = %d\n", pthread_self(), getpid(), getppid(), getpgid(getpid()), getsid(0));
		sleep(1);
	}

	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	pthread_attr_t attr;
	int ret = 0;

	ret = pthread_attr_init(&attr);
	if(ret) {
		printf("failed: pthread_attr_init\n");
		exit(1);
	}

	ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(ret) {
		printf("failed: pthread_attr_setdetachstate\n");
		exit(1);
	}

	pthread_t tid;
	ret = pthread_create(&tid, &attr, routine, NULL);
	if(ret) {
		printf("failed: pthread_create\n");
		exit(1);
	}

	ret = pthread_join(tid, NULL);
	if(ret) {
		printf("failed: pthread_join\n");
		exit(1);
	}

	ret = pthread_attr_destroy(&attr);
	if(ret) {
		printf("failed: pthread_attr_destroy\n");
		exit(1);
	}

	return 0;
}