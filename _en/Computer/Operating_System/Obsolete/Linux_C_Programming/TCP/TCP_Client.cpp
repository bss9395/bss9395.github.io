/* TCP_Client.c
Author: BSS9395
Update: 2023-09-27T15:21:00+08@China-Guangdong-Zhanjiang+08
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <pthread.h>

static const int   _buffer_size = 512;
static const char *_server_addr = "127.0.0.1";
static const int   _server_port = 9395;

void *_Thread_Send(void *args) {
    int fd_client = *(int *)args;
    char buffer[_buffer_size];
    while(true) {
        fgets(buffer, _buffer_size, stdin);
        if(buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }
        int ret = write(fd_client, buffer, strlen(buffer));
        if(ret <= 0) {
            perror("write");
            break;
        }
    }

    return NULL;
}

void *_Thread_Recv(void *args) {
    int fd_client = *(int *)args;
    char buffer[_buffer_size];
    while(true) {
        ssize_t len = read(fd_client, buffer, _buffer_size);
        if(len <= 0) {
            perror("read");
            break;
        }
        buffer[len] = '\0';

        fprintf(stdout, "%s\n", buffer);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int fd_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr_socket;
    memset(&addr_socket, 0, sizeof(addr_socket));
    addr_socket.sin_family = AF_INET;
    addr_socket.sin_port = htons(_server_port);
    inet_pton(AF_INET, _server_addr, &addr_socket.sin_addr);

    int ret = connect(fd_socket, (struct sockaddr *)&addr_socket, sizeof(addr_socket));
    if(ret == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    pthread_t tid_send;
    pthread_create(&tid_send, NULL, _Thread_Send, (void *)&fd_socket);
    pthread_t tid_recv;
    pthread_create(&tid_recv, NULL, _Thread_Recv, (void *)&fd_socket);
    pthread_join(tid_send, NULL);
    pthread_join(tid_recv, NULL);
    close(fd_socket);
    return 0;
}
