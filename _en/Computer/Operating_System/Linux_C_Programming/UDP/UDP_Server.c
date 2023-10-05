/* UDP_Server.c
Author: BSS9395
Update: 2023-10-02T10:40:00+08@China-Guangdong-Zhanjiang+08
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

static const int _server_port = 9395;
static const char *_server_addr = "127.0.0.1";
static const int _buffer_size = 512;

int main(void) {
    int fd_server = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in addr_server;
    memset(&addr_server, 0, sizeof(addr_server));
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(_server_port);
    addr_server.sin_addr.s_addr = INADDR_ANY;

    int ret = bind(fd_server, (void*)&addr_server, sizeof(addr_server));
    if (-1 == ret) {
        perror("bind"); 
        exit(EXIT_FAILURE);
    }
    
    while(true) {
        char buffer[_buffer_size];
        struct sockaddr_in addr_peer;
        socklen_t len = sizeof(addr_peer);
        ret = recvfrom(fd_server, buffer, _buffer_size, 0, (void*)&addr_peer, &len);
        if(ret <= 0) {
            perror("recvfrom");
            continue;
        }
        buffer[ret] = 0;
        printf("[%s:%d] %s\n", inet_ntoa(addr_peer.sin_addr), ntohs(addr_peer.sin_port), buffer);
        sendto(fd_server, buffer, strlen(buffer), 0, (struct sockaddr*)&addr_peer, sizeof(addr_peer));
    }

    close(fd_server);
    return 0;
}
