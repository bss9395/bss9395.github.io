#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static const char    *SERVER_ADDR = "127.0.0.1";
static const char    *SERVER_BIND = "0.0.0.0";
static const unsigned SERVER_PORT = 9395;

void *client_process(void *args) {
	long id = (long)args;

	struct sockaddr_in conn_in;
	conn_in.sin_family = AF_INET;
	conn_in.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	conn_in.sin_port = htons(SERVER_PORT);

	int conn_fd = socket(AF_INET, SOCK_DGRAM, 0);

	char buffer_send[BUFSIZ] = { '\0' };
    char buffer_recv[BUFSIZ] = { '\0' };
	for(int i = 0; i < 2; ++i) {
		sleep(1);

		sprintf(buffer_send, "client %ld:%s", id, __FILE__);
		sendto(conn_fd, buffer_send, strlen(buffer_send), 0, (struct sockaddr *)&conn_in, sizeof(conn_in));

		struct sockaddr_in addr_peer;
		socklen_t len_peer = sizeof(addr_peer);
		ssize_t len_recv = recvfrom(conn_fd, buffer_recv, sizeof(buffer_recv), 0, (struct sockaddr *)&addr_peer, &len_peer);
		if(len_recv <= 0) {
			perror("recvfrom");
			break;
		}
        buffer_recv[len_recv] = '\0';

		fprintf(stdout, "client[%s:%d]%s\n", inet_ntoa(addr_peer.sin_addr), ntohs(addr_peer.sin_port), buffer_recv);
	}

	return NULL;
}

int main(int argc, char *argv[]) {
	pid_t pid_main = fork();
	if (0 == pid_main) {
		sleep(1);

		pid_t pid = fork();
		if(0 == pid){
			client_process((void *)0x00);
		}
		else if (0 < pid) {
			client_process((void *)0x01);
		}
	}
	else if (0 < pid_main) {
		struct sockaddr_in addr_server;
		addr_server.sin_family = AF_INET;
		addr_server.sin_addr.s_addr = inet_addr(SERVER_BIND);
		addr_server.sin_port = htons(SERVER_PORT);

		int fd_server = socket(AF_INET, SOCK_DGRAM, 0);
		int on = 1;
		setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
		bind(fd_server, (struct sockaddr *)&addr_server, sizeof(addr_server));

		char buffer[BUFSIZ] = "12345678901234567890";
		while(true) {
			struct sockaddr_in client_in;
			socklen_t client_len = sizeof(client_in);

			ssize_t recv_len = recvfrom(fd_server, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_in, &client_len);
			if(recv_len <= 0) {
				perror("recvfrom");
				break;
			}
            buffer[recv_len] = '\0';

			fprintf(stdout, "server[%s:%d]%s\n", inet_ntoa(client_in.sin_addr), ntohs(client_in.sin_port), buffer);
			for(int i = 0; i < recv_len; ++i) {
				buffer[i] = toupper(buffer[i]);
			}
			sendto(fd_server, buffer, strlen(buffer), 0, (struct sockaddr *)&client_in, sizeof(client_in));
		}

        while(true);
		close(fd_server);
	}

	return 0;
}
