#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
int symlink(const char *target, const char *linkpath);
int symlinkat(const char *target, int newdirfd, const char *linkpath);
#endif // 0

int main(int argc, char *argv[]) {
	int ret = symlink(__FILE__, "./FILE");
	if (-1 == ret) {
		perror("symlink");
		exit(1);
	}

	return 0;
}
