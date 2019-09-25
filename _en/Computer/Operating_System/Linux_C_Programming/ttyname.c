#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
char *ttyname(int fd);
int ttyname_r(int fd, char *buf, size_t buflen);
#endif // 0

int main(int argc, char *argv[]) {
	for(int i = 0; i < 10; ++i) {
		printf("fd %d: %s\n", i, ttyname(i));
	}

	return 0;
}