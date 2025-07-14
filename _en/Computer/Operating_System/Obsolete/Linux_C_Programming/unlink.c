#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
int unlink(const char *pathname);
int unlinkat(int dirfd, const char *pathname, int flags);
*/

int main(int argc, char *argv[]) {
	int fd = open("tmp.txt", O_WRONLY | O_CREAT, 0664);
	if(-1 == fd) {
		perror("open");
		exit(1);
	}
	unlink("tmp.txt");

	ssize_t len = write(fd, "1234567890", 10);
	if(len <= 0) {
		perror("write");
	}

	off_t off = lseek(fd, 0, SEEK_END);
	printf("off = %ld\n", off);

	return 0;
}
