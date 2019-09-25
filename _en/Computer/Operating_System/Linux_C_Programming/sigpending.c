#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int sigpending(sigset_t *set);
#endif // 0

void handler(int signo) {
	switch(signo) {
	case SIGINT:
		printf("SIGINT = %d\n", signo);
		break;
	case SIGQUIT:
		printf("SIGQUIT = %d\n", signo);
		break;
	default:
		printf("signal = %d\n", signo);
		break;
	}
}

int main(int argc, char *argv[]) {
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGQUIT);

	sigset_t old;
	sigprocmask(SIG_BLOCK, &set, &old);

	sigset_t pend;
	while(true) {
		sigpending(&pend);
		if(sigismember(&pend, SIGINT)) {
			printf("SIGINT pending. \n");
		}
		if(sigismember(&pend, SIGQUIT)) {
			printf("SIGQUIT pending. \n");
		}
		sleep(1);

		static int i = 0;
		i++;
		if(10 < i) {
			sigprocmask(SIG_SETMASK, &old, NULL);
		}
	}

	return 0;
}