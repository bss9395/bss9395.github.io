#include <sys/time.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#if 0
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
#endif // 0

static const char *SERVER_ADDR = "192.168.19.123";
static const unsigned SERVER_PORT = 6666;
static int server_fd = 0;

int setnonblock(int fd, bool flag) {
	int fl = fcntl(fd, F_GETFL);
	if(flag) {
		fcntl(fd, F_SETFL, (int)(fl | O_NONBLOCK));
	}
	else {
		fcntl(fd, F_SETFL, (int)(fl & ~O_NONBLOCK));
	}
	return fl;
}

void handler(int signo) {
	printf("----connect timeout----\n");
	setnonblock(server_fd, true);
}

int main(int argc, char *argv[]) {
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	server_addr.sin_port = htons(SERVER_PORT);

	server_fd = socket(AF_INET, SOCK_STREAM, 0);

	struct timeval tv1;
	gettimeofday(&tv1, NULL);

	signal(SIGALRM, handler);
	alarm(1);
	int ret = connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	signal(SIGALRM, SIG_DFL);
	alarm(0);

	printf("connect code = %d\n", ret);
	if(-1 == ret) {
		struct timeval tv2;
		gettimeofday(&tv2, NULL);
		time_t sec = tv2.tv_sec - tv1.tv_sec;
		suseconds_t usec = tv2.tv_usec - tv1.tv_usec;
		printf("connect failed after time %lfs\n", sec + (double)usec/1000/1000);

		if(errno == EINPROGRESS) {
			printf("nonblock mode\n");
		}
	}
	else if(0 == ret) {
		struct sockaddr_in conn_addr;
		socklen_t conn_len = sizeof(conn_addr);
		getpeername(server_fd, (struct sockaddr *)&conn_addr, &conn_len);
		printf("connected %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));
	}
	setnonblock(server_fd, false);

	close(server_fd);
	return 0;
}