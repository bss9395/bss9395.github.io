#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
int creat(const char *pathname, mode_t mode);
int openat(int dirfd, const char *pathname, int flags);
int openat(int dirfd, const char *pathname, int flags, mode_t mode);
#endif // 0

int main(int argc, char *argv[]) {
	int fd = open("tmp.txt", O_RDWR | O_CREAT, 0644);
	if(-1 == fd) {
		perror("tmp.txt");
		exit(1);
	}
	printf("%d\n", fd);
	close(fd);

	char buf[BUFSIZ] = { '\0' };

	fd = open("/dev/tty", O_RDWR);
	if(-1 == fd) {
		perror("/dev/tty");
		exit(1);
	}
	read(fd, buf, BUFSIZ);
	write(fd, buf, BUFSIZ);
	close(fd);

	fd = open("/dev/tty", O_RDWR);
	if(-1 == fd) {
		perror("/dev/tty");
		exit(1);
	}
	read(fd, buf, BUFSIZ);
	printf("%s\n", buf);
	close(fd);

	return 0;
}
