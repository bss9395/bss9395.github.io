#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
pthread_t pthread_self(void);
//Compile and link with -pthread.
#endif // 0

int main(int argc, char *argv[]) {
	pthread_t tid = pthread_self();
	printf("pthread = %lu\n", tid);

	if(pthread_equal(tid, pthread_self())) {
		printf("equal \n");
	}
	else {
		printf("not equal \n");
	}

	return 0;
}