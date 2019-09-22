#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
long fpathconf(int fd, int name);
long pathconf(const char *path, int name);
#endif // 0

int main(int argc, char *argv[]) {
	int fd[2] = { 0 };
	int ret = pipe(fd);
	if(-1 == ret) {
		perror("pipe");
		exit(1);
	}

	printf("%ld\n", fpathconf(fd[0], _PC_PIPE_BUF));
	printf("%ld\n", fpathconf(fd[0], _PC_NAME_MAX));

	return 0;
}