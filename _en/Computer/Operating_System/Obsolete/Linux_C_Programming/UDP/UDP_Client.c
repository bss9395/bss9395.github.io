/* UDP_Client.c
Author: BSS9395
Update: 2023-10-02T10:40:00+08@China-Guangdong-Zhanjiang+08
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

static const int _buffer_size = 512;
static const char *_server_addr = "127.0.0.1";
static const int _server_port = 9395;

void *_Thread_Send(void *args) {
    struct sockaddr_in addr_peer;
    memset(&addr_peer, 0, sizeof(addr_peer));
    addr_peer.sin_family = AF_INET;
    addr_peer.sin_port = htons(_server_port);
    addr_peer.sin_addr.s_addr = inet_addr(_server_addr);

    int fd_client = *(int *)args;
    char buffer[_buffer_size];
    while(true) {
        fgets(buffer, _buffer_size, stdin);
        if(buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }
        
        int ret = sendto(fd_client, buffer, strlen(buffer), 0, (struct sockaddr *)&addr_peer, sizeof(addr_peer));
        if(ret <= 0) {
            perror("write");
            continue;
        }
    }

    return NULL;
}

void *_Thread_Recv(void *args) {
    int fd_client = *(int *)args;
    char buffer[_buffer_size];
    while(true) {
        struct sockaddr_in addr_peer;
        socklen_t len_peer;
        int len = recvfrom(fd_client, buffer, _buffer_size, 0, (struct sockaddr *)&addr_peer, &len_peer);
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
    int fd_client = socket(AF_INET, SOCK_DGRAM, 0);

    pthread_t tid_send;
    pthread_t tid_recv;
    pthread_create(&tid_send, NULL, _Thread_Send, (void*)&fd_client);
    pthread_create(&tid_recv, NULL, _Thread_Recv, (void*)&fd_client);
    pthread_join(tid_send, NULL);
    pthread_join(tid_recv, NULL);

    close(fd_client);
    return 0;    
}
