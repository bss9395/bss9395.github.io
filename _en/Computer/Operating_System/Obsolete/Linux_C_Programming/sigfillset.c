#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
#endif // 0

void handler(int signo) {
	printf("void handler(int signo);\n");
	sleep(5);
	printf("void handler(int signo);\n");
}

void action(int signo, siginfo_t *info, void *context) {
	printf("void action(int signo, siginfo_t *info, void *context);\n");
	sleep(5);
	printf("void action(int signo, siginfo_t *info, void *context);\n");
}

int main(int argc, char *argv[]) {
	struct sigaction act;
	// act.sa_handler = handler;
	// act.sa_flags = 0;
	act.sa_sigaction = action;
	act.sa_flags = SA_SIGINFO | SA_RESTART;

	sigfillset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);

	while(true) {
		printf("getpid = %d, getppid = %d\n", getpid(), getppid());
		sleep(1);
	}

	return 0;
}