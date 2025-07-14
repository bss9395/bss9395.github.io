/* Unix_TCP_Client.c
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

void *_Thread_Recv(void *args) {
    int fd_socket = *(int *)args;

    char buffer[_buffer_size];
    while(true) {
        int len = read(fd_socket, buffer, _buffer_size);
        if(len <= 0) {
            perror("read");
            break;
        }
        buffer[len] = '\0';
        fprintf(stdout, "%s\n", buffer);
    }
}

void *_Thread_Send(void *args) {
    int fd_socket = *(int *)args;

    char buffer[_buffer_size];
    while(true) {
        fgets(buffer, _buffer_size, stdin);
        if(buffer[strlen(buffer) - 1] = '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }

        write(fd_socket, buffer, strlen(buffer));
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    int fd_socket = socket(AF_UNIX, SOCK_STREAM, 0);

    struct sockaddr_un addr_server;
    memset(&addr_server, 0, sizeof(addr_server));
    addr_server.sun_family = AF_UNIX;
    strcpy(addr_server.sun_path, "server.sock");

    int ret = connect(fd_socket, (struct sockaddr *)&addr_server, sizeof(addr_server));
    if(ret == -1) {
        perror("connect");
    }

    pthread_t tid_send;
    pthread_t tid_recv;
    pthread_create(&tid_send, NULL, _Thread_Send, (void *)&fd_socket);
    pthread_create(&tid_recv, NULL, _Thread_Recv, (void *)&fd_socket);
    pthread_join(tid_recv, NULL);
    pthread_join(tid_send, NULL);

    close(fd_socket);
    return 0;
}
