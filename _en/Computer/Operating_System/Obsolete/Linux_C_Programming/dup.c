#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int dup(int oldfd);
int dup2(int oldfd, int newfd);
int dup3(int oldfd, int newfd, int flags);
*/

int main(int argc, char *argv[]) {
	int old_fd = open("tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(-1 == old_fd) {
		perror("open");
		exit(1);
	}

	int new_fd = dup(old_fd);
	if(-1 == new_fd) {
		perror("dup");
		exit(1);
	}

	write(old_fd, "1234467890", 10);
	write(new_fd, "ABCDEFGHIJ", 10);

	close(old_fd);
	close(new_fd);

	return 0;
}
