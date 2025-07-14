#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

#if 0
int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
#endif // 0

int main(int argc, char *argv[]) {
	struct sockaddr_in conn_addr;
	conn_addr.sin_family = AF_INET;
	conn_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	conn_addr.sin_port = htons(6666);

	int conn_fd = socket(AF_INET, SOCK_STREAM, 0);
	int on = 1;
	setsockopt(conn_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	if(-1 == bind(conn_fd, (struct sockaddr *)&conn_addr, sizeof(conn_addr))) {
		fprintf(stderr, "bind failed.\n");
		exit(1);
	}

	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	getsockname(conn_fd, (struct sockaddr *)&addr, &len);
	fprintf(stdout, "ip = %s, port = %d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));

	return 0;
}