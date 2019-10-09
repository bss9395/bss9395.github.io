#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <stdio.h>

#if 0
int fcntl(int fd, int cmd, ... /* arg */);
#endif // 0

int main(int argc, char *argv[]) {
	int fd = open("tmp.txt", O_RDWR | O_CREAT | O_TRUNC);

	int fl = fcntl(fd, F_GETFL);
	if((int)(fl & O_NONBLOCK)) {
		printf("O_NONBLOCK is set. \n");
	}
	else {
		printf("O_NONBLOCK is not set. \n");
	}

	if((int)(fl & O_ACCMODE) == O_RDONLY) {
		printf("readonly mode. \n");
	} if((int)(fl & O_ACCMODE) == O_WRONLY) {
		printf("writeonly mode. \n");
	} else if((int)(fl & O_ACCMODE) == O_RDWR) {
		printf("readwrite mode. \n");
	}

	if((int)(fl & O_APPEND)) {
		printf("append is set. \n");
	}

	fcntl(fd, F_SETFL, fl | O_NONBLOCK);

	fl = fcntl(fd, F_GETFL);
	if((int)(fl & O_NONBLOCK)) {
		printf("O_NONBLOCK is set. \n");
	}
	else {
		printf("O_NONBLOCK is not set. \n");
	}

	close(fd);

	return 0;
}
