#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
#endif // 0

void signal_handler(int sig) {
	switch(sig) {
	case SIGINT:  // CTRL+C
		printf("SIGINT == %d\n", sig);
		break;
	case SIGQUIT: // CTRL+BACKSLASH
		printf("SIGQUIT == %d\n", sig);
		break;
	default:
		printf("unknown signal %d\n", sig);
	}
}

int main(int argc, char *argv[]) {
	// signal(SIGINT, SIG_DFL);
	// signal(SIGQUIT, SIG_IGN);

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);

	while(true) {
		printf("getpid = %d, getppid = %d\n", getpid(), getppid());
		sleep(1);
	}

	return 0;
}