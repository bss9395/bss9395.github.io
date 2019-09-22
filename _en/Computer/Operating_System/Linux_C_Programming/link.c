#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
int link(const char *oldpath, const char *newpath);
int linkat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, int flags);
#endif // 0

int main(int argc, char *argv[]) {
	int ret = link(__FILE__, "./FILE");
	if (-1 == ret) {
		perror("link");
		exit(1);
	}

	return 0;
}
