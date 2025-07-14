#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#if 0
int close(int fd);
#endif // 0

int main(int argc, char *argv[]) {
	int fd = open("tmp.txt", O_RDWR | O_CREAT, 0644);
	if(-1 == fd) {
		perror("open");
	}

	printf("%d\n", fd);
	close(fd);

	return 0;
}
