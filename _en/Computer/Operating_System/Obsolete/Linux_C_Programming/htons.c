#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#if 0
uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort);
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);
#endif // 0

static const char *SERVER_ADDR = "127.0.0.1";
static const unsigned SERVER_PORT = 6666;

int main(int argc, char *argv[]) {
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(SERVER_PORT);

	fprintf(stdout, "sizeof(sockaddr_in.sin_addr.s_addr) = %ld\n", sizeof(server.sin_addr.s_addr));
	fprintf(stdout, "sizeof(sockaddr.sin_port) = %ld\n", sizeof(server.sin_port));
	fprintf(stdout, "server.sin_addr.s_addr = %d\n", ntohl(server.sin_addr.s_addr));
	fprintf(stdout, "server.sin_port = %d\n", ntohs(server.sin_port));

	return 0;
}
