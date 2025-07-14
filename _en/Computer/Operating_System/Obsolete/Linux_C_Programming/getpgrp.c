#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
int setpgid(pid_t pid, pid_t pgid);
pid_t getpgid(pid_t pid);
pid_t getpgrp(void);                 /* POSIX.1 version */
pid_t getpgrp(pid_t pid);            /* BSD version */
int setpgrp(void);                   /* System V version */
int setpgrp(pid_t pid, pid_t pgid);  /* BSD version */
*/

int main(int argc, char *argv[]) {
	printf("getppid = %d, getpid = %d\n", getppid(), getpid());
	printf("getpgrp = %d, getpgid = %d\n", getpgrp(), getpgid(getpid()));

	char buf[BUFSIZ] = { '\0' };
	sprintf(buf, "\nps ajx | grep %s\n", argv[0]);
	system(buf);

	return 0;
}
