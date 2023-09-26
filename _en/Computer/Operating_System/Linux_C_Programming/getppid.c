#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/*
pid_t getpid(void);
pid_t getppid(void);
int setpgid(pid_t pid, pid_t pgid);
pid_t getpgid(pid_t pid);
pid_t getpgrp(void);                 /* POSIX.1 version */
pid_t getpgrp(pid_t pid);            /* BSD version */
int setpgrp(void);                   /* System V version */
int setpgrp(pid_t pid, pid_t pgid);  /* BSD version */
*/

int main(int argc, char *argv[]) {
	pid_t pid = getpid();
	printf("pid = %d\n", pid);

	pid_t ppid = getppid();
	printf("ppid = %d\n", ppid);

	pid_t pgid = getpgid(pid);
	printf("pgid = %d\n", pgid);

	return 0;
}
