#include <unistd.h>
#include <stdio.h>

/*
char *getcwd(char *buf, size_t size);
char *getwd(char *buf);
char *get_current_dir_name(void);
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