#if 0
pid_t getsid(pid_t pid);
pid_t setsid(void);
#endif

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	pid_t sid = getsid(0);
	printf("getsid = %d\n", sid);

	sid = setsid();
	printf("setsid = %d\n", sid);
	if (-1 == sid) {
		perror("setsid");
		exit(1);
	}

	return 0;
}