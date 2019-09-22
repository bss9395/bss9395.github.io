#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	pid_t pid = fork();
	if(-1 == pid) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(0 == pid) {
		for(int i = 0; i < 20; ++i) {
			printf("child process %d: %d\n", getpid(), i);
			usleep(500 * 1000);
		}

		int tmp = 1 / 0;

		exit(10);
	}
	else if(0 < pid) {
		int status;
		do {
			// pid_t cpid = wait(&status);
			pid_t cpid = waitpid(pid, &status, WUNTRACED | WCONTINUED);
			if(pid != cpid) {
				fprintf(stderr, "wait: pid != cpid\n");
			}

			if(WIFEXITED(status)) {
				fprintf(stdout, "exit status: %d\n", WEXITSTATUS(status));
			}

			if(WIFSIGNALED(status)) {
				fprintf(stdout, "termination signal: %d\n", WTERMSIG(status));
			}

			if(WIFSTOPPED(status)) {
				fprintf(stdout, "stop signal: %d\n", WSTOPSIG(status));
			}

			if(WIFCONTINUED(status)) {
				fprintf(stdout, "continue signal \n");
			}
		} while(!(WIFEXITED(status) || WIFSIGNALED(status)));
	}

	fprintf(stdout, "...\n");

	return 0;
}