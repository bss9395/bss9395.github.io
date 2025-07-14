#include <unistd.h>
#include <stdio.h>

/*
int chdir(const char *path);
int fchdir(int fd);
*/

#define PATH_MAX 4096

int main(int argc, char *argv[]) {
	char buf[PATH_MAX] = { '\0' };

	getcwd(buf, PATH_MAX);
	printf("%s\n", buf);

	chdir("/home/");

	getcwd(buf, PATH_MAX);
	printf("%s\n", buf);

	return 0;
}