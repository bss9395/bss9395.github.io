#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#if 0
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
int inet_pton(int af, const char *src, void *dst);
#endif // 0

static const char *SERVER_ADDR = "127.0.0.1";
static const unsigned SERVER_PORT = 6666;

int main(int argc, char *argv[]) {
	struct sockaddr_in server;

	server.sin_family = AF_INET;
	//server.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	inet_pton(AF_INET, SERVER_ADDR, &server.sin_addr);
	server.sin_port = htons(SERVER_PORT);

	char tmp[BUFSIZ] = { '\0' };
	//fprintf(stdout, "server %s:%d\n", inet_ntoa(server.sin_addr), ntohs(server.sin_port));
	fprintf(stdout, "server %s:%d\n", inet_ntop(AF_INET, &server.sin_addr, tmp, sizeof(server)), ntohs(server.sin_port));

	return 0;
}
