#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[]) {
	for(int i = 0; i < argc; ++i) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	printf("--------------------\n");

	for(char **it = environ; *it != NULL; ++it) {
		printf("%s\n", *it);
	}

	printf("--------------------\n");

	int ret = execlp("print.sh", "print", NULL);
	if(-1 == ret) {
		perror("exec");
	}
	return 0;
}