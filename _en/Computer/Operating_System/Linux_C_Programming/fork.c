#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

double d = 0;

int main(void) {
	fprintf(stdout, "hello, \n");

	char *buf = (char *)malloc(BUFSIZ * sizeof(char));
	int fd = open("tmp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	pid_t pid = fork();
	if (pid < 0) {
		perror("fork");
		return 1;
	}
	else if (pid == 0) {
		fprintf(stdout, "pid = %d, getpid = %d, getppid = %d\n", pid, getpid(), getppid());

		char *it = buf;
		for (int i = 0; i < 10; ++i) {
			usleep(500000);
			sprintf(it, "%d", i);
			it++;
		}
		write(fd, buf, 10);
		sync();

		fprintf(stdout, "child process: &d = %p, d = %lf\n", &d, d);
		d = 12;
		fprintf(stdout, "child process: &d = %p, d = %lf\n", &d, d);
		free(buf);
	}
	else if (0 < pid) {
		fprintf(stdout, "pid = %d, getpid = %d, getppid = %d\n", pid, getpid(), getppid());

		char *it = buf;
		for (char c = 'A'; c <= 'Z'; ++c) {
			usleep(500000);
			sprintf(it, "%c", c);
			it++;
		}
		write(fd, buf, 26);
		fsync(fd);

		fprintf(stdout, "parent process: &d = %p, d = %lf\n", &d, d);
		d = 11;
		fprintf(stdout, "parent process: &d = %p, d = %lf\n", &d, d);
		free(buf);
	}

	fprintf(stdout, "world!\n");
	fflush(stdout);
	return 0;
}
