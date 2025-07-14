#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const char *SERVER_FILE = "server.socket";

int checkError(char *msg, bool failed) {
	if(failed) {
		perror(msg);
		exit(1);
	}

	return 0;
}

void *server_thread(void *args) {
	int client_fd = *((int *)args);
	char buf[BUFSIZ] = "12345678901234567890";

	struct sockaddr_un client_un;
	socklen_t client_len = sizeof(client_un);
	getpeername(client_fd, (struct sockaddr *)&client_un, &client_len);

	while(true) {
		long recv_len = read(client_fd, buf, sizeof(buf));
		buf[recv_len] = '\0';
		if(recv_len <= 0) {
			fprintf(stdout, "server: client closed...\n");
			break;
		}

		fprintf(stdout, "received from %s\n", client_un.sun_path);
		fprintf(stdout, "%s\n", buf);

		for(int i = 0; i < recv_len; ++i) {
			buf[i] = toupper(buf[i]);
		}

		write(client_fd, buf, recv_len);
	}

	close(client_fd);
	return NULL;
}

void *client_process(void *args) {
	int conn_fd = socket(AF_LOCAL, SOCK_STREAM, 0);
	checkError("socket", conn_fd == -1);

	struct sockaddr_un conn_un;
	conn_un.sun_family = AF_LOCAL;
	strcpy(conn_un.sun_path, SERVER_FILE);

	int err = connect(conn_fd, (struct sockaddr *)&conn_un, sizeof(conn_un));
	checkError("connect", err == -1);

	char buf[BUFSIZ] = { '\0' };
	for(int i = 0; i < 3; ++i) {
		sleep(1);

		write(conn_fd, __FILE__, strlen(__FILE__));
		long recv_len = read(conn_fd, buf, sizeof(buf));
		buf[recv_len] = '\0';

		if(recv_len <= 0) {
			fprintf(stdout, "server closed....\n");
			break;
		}

		fprintf(stdout, "received from %s\n", conn_un.sun_path);
		fprintf(stdout, "%s\n", buf);
	}

	write(conn_fd, "", 0);
	fprintf(stdout, "client: client close...\n");
	close(conn_fd);
	return NULL;
}

int main(int argc, const char* argv[]) {
	pid_t pid_main = fork();
	if(0 == pid_main){
		sleep(1);

		pid_t pid = fork();
		if(0 == pid) {
			sleep(1);

			fprintf(stdout, "----------------------------------------\n");
			fprintf(stdout, "client 1: pid = %d, getpid = %d, getppid = %d\n", pid, getpid(), getppid());
			client_process((void *)0x01);
		}
		else if(0 < pid) {
			fprintf(stdout, "----------------------------------------\n");
			fprintf(stdout, "client 2: pid = %d, getpid = %d, getppid = %d\n", pid, getpid(), getppid());
			client_process((void *)0x02);
		}
	}
	else if (0 < pid_main) {
		int server_fd = socket(AF_LOCAL, SOCK_STREAM, 0);
		checkError("socket", server_fd == -1);

		struct sockaddr_un server_un;
		server_un.sun_family = AF_LOCAL;
		strcpy(server_un.sun_path, SERVER_FILE);
		unlink(SERVER_FILE);

		int err = bind(server_fd, (struct sockaddr *)&server_un, sizeof(server_un));
		checkError("bind", err == -1);

		err = listen(server_fd, 36);
		checkError("listen", err == -1);

		while(true) {
			struct sockaddr_un client_un;
			socklen_t client_len = sizeof(client_un);
			int client_fd = accept(server_fd, (struct sockaddr *)&client_un, &client_len);

			pthread_t tid;
			pthread_create(&tid, NULL, server_thread, (void *)&client_fd);
			pthread_detach(tid);
		}

		close(server_fd);
	}

	return 0;
}
