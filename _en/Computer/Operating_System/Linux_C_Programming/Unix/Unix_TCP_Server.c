/* Unix_TCP_Server.c
Author: BSS9395
Update: 2023-10-02T16:52:00+08@China-Guangdong-Zhanjiang+08
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <stdbool.h>
#include <pthread.h>

static const int _buffer_size = 512;

void *_Thread_Client(void *args) {
    int fd_client = *(int *)args;

    char buffer[_buffer_size];
    while(true) {
        int len = read(fd_client, buffer, _buffer_size);
        if(len <= 0) {
            perror("read");
            break;
        }
        buffer[len] = '\0';
        fprintf(stdout, "%s\n", buffer);
        write(fd_client, buffer, strlen(buffer));
    }
    close(fd_client);
}

int main(int argc, char *argv[]) {
    int fd_socket = socket(AF_UNIX, SOCK_STREAM, 0);

    struct sockaddr_un addr_server;
    memset(&addr_server, 0, sizeof(addr_server));
    addr_server.sun_family = AF_UNIX;
    strcpy(addr_server.sun_path, "server.sock");

    unlink("server.sock");
    int ret = bind(fd_socket, (struct sockaddr *)&addr_server, sizeof(addr_server));
    if(ret == -1) {
        perror("bind");
    }
    listen(fd_socket, 10);

    while(true) {
        struct sockaddr_un addr_client;
        socklen_t len_client;
        int fd_client = accept(fd_socket, (struct sockaddr *)&addr_client, &len_client);

        pthread_t tid;
        pthread_create(&tid, NULL, _Thread_Client, (void *)&fd_client);
    }
    close(fd_socket);
    return 0;
}
