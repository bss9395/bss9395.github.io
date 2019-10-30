#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static const char    *SERVER_ADDR = "192.168.248.128";
static const char    *SERVER_NET  = "192.168.248.255";
static const char    *SERVER_BIND = "0.0.0.0";
static const unsigned SERVER_PORT = 9395;

void *client_process(void *args) {
	long id = (long)args;

	struct sockaddr_in conn_in;
	conn_in.sin_family = AF_INET;
	if(id){
		printf("client id: %ld\n", id);
		conn_in.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	}
	else{
		printf("client id: %ld\n", id);
		conn_in.sin_addr.s_addr = inet_addr(SERVER_NET);
	}
	conn_in.sin_port = htons(SERVER_PORT);

	int conn_fd = socket(AF_INET, SOCK_DGRAM, 0);
	int on = 1;
	setsockopt(conn_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	setsockopt(conn_fd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));

	char buf[BUFSIZ] = { '\0' };
	for(int i = 0; i < 2; ++i) {
		sleep(1);

		sprintf(buf, "client %ld:%s", id, __FILE__);
		sendto(conn_fd, buf, strlen(buf), 0, (struct sockaddr *)&conn_in, sizeof(conn_in));

		struct sockaddr_in peer_in;
		socklen_t peer_len = sizeof(peer_in);
		ssize_t recv_len = recvfrom(conn_fd, buf, sizeof(buf), 0, (struct sockaddr *)&peer_in, &peer_len);
		buf[recv_len] = '\0';
		if(recv_len <= 0) {
			fprintf(stdout, "server closed...\n");
			break;
		}

		fprintf(stdout, "received from server %s:%d\n", inet_ntoa(peer_in.sin_addr), ntohs(peer_in.sin_port));
		fprintf(stdout, "%s\n", buf);
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
		struct sockaddr_in server_in;
		server_in.sin_family = AF_INET;
		server_in.sin_addr.s_addr = inet_addr(SERVER_BIND);
		server_in.sin_port = htons(SERVER_PORT);

		int server_fd = socket(AF_INET, SOCK_DGRAM, 0);
		int on = 1;
		setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
		bind(server_fd, (struct sockaddr *)&server_in, sizeof(server_in));

		char buf[BUFSIZ] = "12345678901234567890";
		while(true) {
			fprintf(stdout, "----------------------------------------\n");
			fprintf(stdout, "%s\n", "waiting for connection...");
			struct sockaddr_in client_in;
			socklen_t client_len = sizeof(client_in);

			ssize_t recv_len = recvfrom(server_fd, buf, sizeof(buf), 0, (struct sockaddr *)&client_in, &client_len);
			buf[recv_len] = '\0';
			if(recv_len <= 0) {
				fprintf(stdout, "server: client close...\n");
				break;
			}

			fprintf(stdout, "received from client %s:%d\n", inet_ntoa(client_in.sin_addr), ntohs(client_in.sin_port));
			fprintf(stdout, "%s\n", buf);

			for(int i = 0; i < recv_len; ++i) {
				buf[i] = toupper(buf[i]);
			}
			sendto(server_fd, buf, recv_len, 0, (struct sockaddr *)&client_in, sizeof(client_in));
		}

		close(server_fd);
	}

	return 0;
}
