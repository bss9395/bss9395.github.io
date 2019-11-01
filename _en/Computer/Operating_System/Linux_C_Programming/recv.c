#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#if 0
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);
ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags);
#endif // 0

static const char *SERVER_ADDR = "127.0.0.1";
static const unsigned SERVER_PORT = 6666;

void *server_thread(void *args) {
	pthread_detach(pthread_self());
	int client_fd = *((int *)args);
	struct sockaddr_in client_addr;
	socklen_t client_len = sizeof(client_addr);

	char buf[BUFSIZ] = { '\0' };
	while(true) {
		ssize_t len = read(client_fd, buf, BUFSIZ);
		//ssize_t len = recv(client_fd, buf, BUFSIZ, 0);
		//ssize_t len = recvfrom(client_fd, buf, BUFSIZ, 0, (struct sockaddr *)&client_addr, &client_len);
		fprintf(stdout, "\e[31mreceive from client: %s:%d\e[0m\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
		fprintf(stdout, "%s\n", buf);

		for(int i = 0; i < len; ++i) {
			buf[i] = toupper(buf[i]);
		}

		write(client_fd, buf, strlen(buf) + 1);
		//send(client_fd, buf, strlen(buf) + 1, 0);
		//sendto(client_fd, buf, strlen(buf) + 1, 0, NULL, 0);
	}

	close(client_fd);
	pthread_exit(NULL);
}

void *client_send(void *args) {
	int conn_fd = *((int *)args);

	char buf[] = "greeting from client...";
	while(true) {
		//ssize_t len = send(conn_fd, buf, strlen(buf) + 1, 0);
		ssize_t len = sendto(conn_fd, buf, strlen(buf) + 1, 0, NULL, 0);

		sleep(1);
	}

	close(conn_fd);
	return NULL;
}

void *client_recv(void *args) {
	int conn_fd = *((int *)args);
	struct sockaddr_in conn_addr;
	socklen_t conn_len = sizeof(conn_addr);

	char buf[BUFSIZ] = { '\0' };
	while(true) {
		// ssize_t len = recv(conn_fd, buf, BUFSIZ, 0);
		ssize_t len = recvfrom(conn_fd, buf, BUFSIZ, 0, (struct sockaddr *)&conn_addr, &conn_len);
		fprintf(stdout, "\e[32mreceive from server: %s:%d\e[0m\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));
		fprintf(stdout, "%s\n", buf);
	}

	close(conn_fd);
	return NULL;
}

int main(int argc, char *argv[]) {
	if(0 == fork()) {
		sleep(1);

		struct sockaddr_in conn_addr;
		conn_addr.sin_family = AF_INET;
		conn_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
		conn_addr.sin_port = htons(SERVER_PORT);

		int conn_fd = socket(AF_INET, SOCK_STREAM, 0);
		connect(conn_fd, (struct sockaddr *)&conn_addr, sizeof(conn_addr));

		pthread_t send_tid;
		pthread_t recv_tid;
		pthread_create(&send_tid, NULL, client_send, (void *)&conn_fd);
		pthread_create(&recv_tid, NULL, client_recv, (void *)&conn_fd);

		pthread_join(send_tid, NULL);
		pthread_join(recv_tid, NULL);
	}
	else {
		struct sockaddr_in server_addr;
		server_addr.sin_family = AF_INET;
		server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
		server_addr.sin_port = htons(SERVER_PORT);

		int server_fd = socket(AF_INET, SOCK_STREAM, 0);
		int on = 1;
		setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
		bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
		listen(server_fd, 20);

		while(true) {
			struct sockaddr_in client_addr;
			socklen_t client_len = sizeof(client_addr);
			int client_fd = accept(server_fd, (void *)&client_addr, &client_len);

			pthread_t tid;
			pthread_create(&tid, NULL, server_thread, (int *)&client_fd);
		}

		close(server_fd);
	}

	return 0;
}