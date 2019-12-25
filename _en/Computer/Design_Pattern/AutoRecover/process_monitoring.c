/* process_monitoring.c
* Author: BSS9395
* Update: 2019-12-25T17:23:00+08@ShenZhen
* Design: AutoRecover
*/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void checkError(bool failed, const char *file, long line, const char *func, const char *msg) {
	if (failed) {
		fprintf(stderr, "\e[33m""%s==%ld==%s==[%d]%s""\e[0m", file, line, func, errno, msg);
		if (errno) {
			exit(errno);
		}
	}
}

void monitoring(pid_t pids[], int num, bool daemon) {
	int log_fd = open("log.txt", O_WRONLY | O_CREAT, 0664);
	checkError(log_fd < 0, __FILE__, __LINE__, __FUNCTION__, "open");

	int stdout_fd = dup2(log_fd, STDOUT_FILENO);
	checkError(stdout_fd < 0, __FILE__, __LINE__, __FUNCTION__, "dup2");

	if (daemon) {
		pid_t pid = fork();
		checkError(pid < 0, __FILE__, __LINE__, __FUNCTION__, "fork");
		if (pid == 0) {
			pid_t sid = setsid();
			checkError(sid < 0, __FILE__, __LINE__, __FUNCTION__, "setsid");
		}
		else if (pid > 0) {
			exit(EXIT_SUCCESS);
		}
	}

	pids[0] = getpid();
	int idx = 1;
	int cnt = 0;

	pid_t fds[2];
	pipe(fds);
	while (true) {
		pid_t pid = fork();
		checkError(pid < 0, __FILE__, __LINE__, __FUNCTION__, "fork");

		if (pid == 0) {
			pid_t child = getpid();
			write(fds[1], &child, sizeof(child));

			if (cnt >= num) {
				fprintf(stderr, "child%d: getpid == %d => %d\n", idx, pids[idx], child);
			}
			break;
		}
		else if (pid > 0) {
			pid_t child = 0;
			read(fds[0], &child, sizeof(child));
			pids[idx] = child;
			idx += 1;

			for (int i = 1; i <= num; i += 1) {
				fprintf(stderr, "child%d: getpid == %d, getppid == %d\n", i, pids[i], pids[0]);
			}

			cnt += 1;
			if (cnt < num) {
				continue;
			}

			fprintf(stderr, "\e[33m""parent: getpid == %d, getppid == %d""\e[0m\n", getpid(), getppid());

			int status = 0;
			pid_t dead = waitpid(-1, &status, 0);
			for (int i = 1; i <= num; ++i) {
				if (pids[i] == dead) {
					idx = i;
				}
			}

			if (WEXITSTATUS(status) == 0) {
				exit(EXIT_SUCCESS);
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int num = 0;
	bool daemon = false;
	for (int i = 1; i < argc; i += 1) {
		if (0 == strcmp(argv[i - 1], "--threads")) {
			num = (int)strtol(argv[i], NULL, 10);
		}
		if (0 == strcmp(argv[i], "--daemon")) {
			daemon = true;
		}
	}

	if (num < 1) {
		num = 3;
	}
	pid_t pids[num + 1];
	monitoring(pids, num, daemon);

	static int i = 2;
	while (true) {
		sleep(1);
		fprintf(stderr, "%s: getpid == %d, getppid == %d\n", __FUNCTION__, getpid(), getppid());
		i += 1;
		if (getpid() % i == 0) {
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}
