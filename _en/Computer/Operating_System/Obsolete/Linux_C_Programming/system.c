#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
int system(const char *command);
#endif

int main(int argc, char *argv[]) {
	int fd = open("tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(-1 == fd) {
		perror("open");
		exit(1);
	}
	write(fd, "ABCDEFGHIJ", 10);

	struct stat st;

	stat("tmp.txt", &st);
	chmod("tmp.txt", st.st_mode | S_IWGRP | S_IWOTH);
	system("ls -l tmp.txt");

	fstat(fd, &st);
	fchmod(fd, st.st_mode & ~S_IWOTH);
	system("ls -l tmp.txt");

	close(fd);
	return 0;
}