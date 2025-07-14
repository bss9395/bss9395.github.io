#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

/*
int truncate(const char *path, off_t length);
int ftruncate(int fd, off_t length);
*/

int main(int argc, char *argv[]) {
	int fd = open("tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(fd, "hello, world!\n", 14);
	truncate("tmp.txt", 7);
	ftruncate(fd, 5);

    struct stat st;
    stat("tmp.txt", &st);
    fprintf(stdout, "size = %ld\n", st.st_size);

	return 0;
}