#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
pid_t wait(int *wstatus);
pid_t waitpid(pid_t pid, int *wstatus, int options);
int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);
#endif // 0

void wait_child(int signo) {
    pid_t pid;
    int status;
	// while(pid = wait(status), 0 < pid) {
    while(pid = waitpid(-1, &status, WNOHANG), 0 < pid) {
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
    }
}

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if(-1 == pid) {
        perror("fork");
        exit(1);
    }
    else if(0 == pid) {
    	for(int i = 0; i < 20; ++i) {
			printf("child process: pid = %d, getpid = %d, getppid = %d\n", pid, getpid(), getppid());
			usleep(500 * 1000);
		}

		//int tmp = 1 / 0;
        exit(10);
    }
    else if(0 < pid) {
        //signal(SIGCHLD, SIG_IGN);
        //signal(SIGCHLD, SIG_DFL);
    	signal(SIGCHLD, wait_child);
        printf("father process: pid = %d, getpid = %d, getppid = %d\n", pid, getpid(), getppid());

		//int ret = pause();
        int res = sleep(24);
        if(0 < res){
        	printf("res = %d\n", res);
        }

        char buf[BUFSIZ] = { '\0' };
        sprintf(buf, "ps ajx | grep %s", argv[0]);
    	system(buf);
    }

    return 0;
}
