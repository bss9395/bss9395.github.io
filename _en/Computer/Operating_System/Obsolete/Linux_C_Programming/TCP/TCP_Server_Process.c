#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/wait.h>
#include <signal.h>

static const int _buffer_size = 512;
static const int _server_port = 9395;
static const char *_server_addr = "127.0.0.1";

void _Do_Sigchld(int num) {
    while(0 < waitpid(0, NULL, WNOHANG));
}

int main(int argc, char *argv[]) {
    int fd_client = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr_client;
    memset(&addr_client, 0, sizeof(addr_client));
    addr_client.sin_family = AF_INET;
    addr_client.sin_port = htons(_server_port);
    inet_pton(AF_INET, _server_addr, &addr_client.sin_addr);

    int ret = connect(fd_client, (struct sockaddr *)&addr_client, sizeof(addr_client));
    if(ret == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    signal(SIGCHLD, _Do_Sigchld);

    int pid = fork();
    if(pid == 0) {
        char buffer[_buffer_size];
        while(true) {
            int len = read(fd_client, buffer, _buffer_size);
            if(len <= 0) {
                perror("read");
                break;
            }
            buffer[len] = '\0';
            fprintf(stdout, "%s\n", buffer);
        }
    } else if(0 < fork) {
        char buffer[_buffer_size];
        while(true) {
            fgets(buffer, _buffer_size, stdin);
            if(buffer[strlen(buffer) - 1] == '\n') {
                buffer[strlen(buffer) - 1] = '\0';
            }
            write(fd_client, buffer, strlen(buffer));
        }
    }
    close(fd_client);
    return 0;
}