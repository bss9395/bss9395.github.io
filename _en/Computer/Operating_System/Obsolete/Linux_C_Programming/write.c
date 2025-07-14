#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#if 0
ssize_t write(int fd, const void *buf, size_t count);
#endif // 0

int main(int argc, char *argv[]) {
	int in = open(__FILE__, O_RDONLY, 0644);
	if(-1 == in) {
		perror("in");
	}

	int out = open("tmp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(-1 == out) {
		perror("out");
	}

	char buf[BUFSIZ] = { '\0' };
	ssize_t len = 0;
	while(len = read(in, buf, BUFSIZ), 0 < len) {
		write(out, buf, len);
	}

	close(in);
	close(out);
	return 0;
}
