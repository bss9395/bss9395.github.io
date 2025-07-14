#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	pid_t pid = fork();
	if(-1 == pid) {
		perror("fork");
		exit(1);
	}
	else if(0 == pid) {
		printf("child process: pid = %d, getpid = %d, getppid = %d\n", pid, getpid(), getppid());
		exit(0);
	}
	else if(0 < pid) {
		do {
			printf("parent process: pid = %d, getpid = %d, getppid = %d\n", pid, getpid(), getppid());
			sleep(1);
		} while(true);
	}

	return 0;
}
