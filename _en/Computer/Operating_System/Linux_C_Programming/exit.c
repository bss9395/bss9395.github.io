#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
void exit(int status);
#endif // 0

int main(int argc, char *argv[]) {
	int fd = open("tmp.txt", O_WRONLY | O_CREAT, 0644);
	if(-1 == fd) {
		perror("open");
		exit(1);
	}
	remove("tmp.txt");

	write(fd, "1234567890", 10);
	ssize_t off = lseek(fd, 0, SEEK_END);
	printf("off = %ld\n", off);

	close(fd);
	return 0;
}