#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int unlink(const char *pathname);
int unlinkat(int dirfd, const char *pathname, int flags);
#endif // 0

int main(int argc, char *argv[]) {
	int fd = open("tmpfile", O_WRONLY | O_CREAT, 0664);
	if(-1 == fd) {
		perror("open");
		exit(1);
	}

	unlink("tmpfile");
	unlinkat(AT_FDCWD, "tmpfile", 0);

	ssize_t len = write(fd, "1234567890", 10);
	if(len <= 0) {
		perror("write");
	}

	off_t off = lseek(fd, 0, SEEK_END);
	printf("off = %ld\n", off);

	return 0;
}
