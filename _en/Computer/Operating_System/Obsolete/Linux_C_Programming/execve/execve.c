#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
extern char **environ;
int execl(const char *path, const char *arg, ...  /* (char  *) NULL */);
int execlp(const char *file, const char *arg, ... /* (char  *) NULL */);
int execle(const char *path, const char *arg, ... /*, (char *) NULL, char * const envp[] */);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execve(const char *file, char *const argv[], char *const envp[]);
#endif // 0

int main(int argc, char *argv[]) {
	char *const env[] = { "PATH=/home/bss9395/bin/", NULL };

	// int ret = execl("/bin/ls", "ls", "-l", "/home/", NULL);
	// int ret = execlp("ls", "ls", "-l", "/home/", NULL);
	int ret = execle("/home/bss9395/bin/print", "print", NULL, env);
	if(-1 == ret) {
		perror("exec");
		exit(1);
	}

	char *const arg[] = { "ls", "-l", "/home/", NULL };
	// int ret = execv("/bin/ls", arg);
	// int ret = execvp("ls", arg);
	//int ret = execve("/home/bss9395/bin/print", arg, env);
	// if(-1 == ret) {
	// 	perror("exec");
	// 	exit(1);
	// }

	printf("hello world!\n");
	return 0;
}