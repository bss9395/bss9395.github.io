#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
#include <signal.h>
int sigqueue(pid_t pid, int sig, const union sigval value);
*/

void handler(int signo, siginfo_t *info, void *ptr) {
	switch(signo) {
	case SIGINT:
		printf("SIGINT = %d, si_pid = %d, si_value.sival_int = %d\n", signo, info->si_pid, info->si_value.sival_int);
		break;
	case SIGQUIT:
		printf("SIGQUIT = %d, si_pid = %d, si_value.sival_int = %d\n", signo, info->si_pid, info->si_value.sival_int);
		break;
	default:
		printf("signal = %d, si_pid = %d, si_value.sival_int = %d\n", signo, info->si_pid, info->si_value.sival_int);
		break;
	}
}

int main(int argc, char *argv[]) {
	pid_t pid = fork();
	printf("pid = %d\n", pid);
	if(-1 == pid) {
		perror("fork");
		exit(1);
	}
	else if(0 == pid) {
		struct sigaction act;
		act.sa_sigaction = handler;
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGINT, &act, NULL);
		sigaction(SIGQUIT, &act, NULL);

		for(int i = 0; i < 5; ++i) {
			printf("child process: getpid = %d\n", getpid());
			sleep(1);
		}
	}
	else if(0 < pid) {
		sleep(1);

		union sigval val;
		for(int i = 0; i < 10; ++i) {
			val.sival_int = i;
			sigqueue(pid, SIGINT, val);
			sigqueue(pid, SIGQUIT, val);
			printf("parent process: getpid = %d\n", getpid());
			sleep(1);
		}
	}

	return 0;
}
