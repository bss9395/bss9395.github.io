#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
ssize_t read(int fd, void *buf, size_t count);
#endif // 0

int main(int argc, char *argv[]) {
	int fd = open(__FILE__, O_RDONLY);
	if(-1 == fd) {
		perror("open");
		exit(1);
	}

	char buf[BUFSIZ] = { '\0' };
	ssize_t len = 0;
	while(len = read(fd, buf, BUFSIZ), 0 < len) {
		printf("%s\n", buf);
	}

	close(fd);
	return 0;
}
