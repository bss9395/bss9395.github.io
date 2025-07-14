/* TCP_Server.c
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
#include <vector>
#include <list>

static const int   _buffer_size = 512;
static const char *_server_addr = "127.0.0.1";
static const int   _server_port = 9395;
static std::list<int> _fd_clients;

void *_Thread_Server(void *args) {
    pthread_detach(pthread_self());

    int fd_client = *(int *)args;
    _fd_clients.push_back(fd_client);

    struct sockaddr_in addr_client;
    socklen_t len_client = sizeof(addr_client);
    getpeername(fd_client, (struct sockaddr *)&addr_client, &len_client);

    char buffer[_buffer_size] = { 0 };
    while(true) {
        ssize_t len = read(fd_client, buffer, _buffer_size);
        if(len <= 0) {
            fprintf(stdout, "server: client closed...\n");
            break;
        }
        buffer[len] = '\0';

        fprintf(stdout, "client %s:%d: %s\n", inet_ntoa(addr_client.sin_addr), ntohs(addr_client.sin_port), buffer);
        for(auto beg = _fd_clients.begin(), end = _fd_clients.end(); beg != end; ++beg) {
            write(*beg, buffer, len);            
        }
    }   
    close(fd_client);
    return NULL; 
}

int main(void) {
    int fd_server = socket(AF_INET, SOCK_STREAM, 0);
    int on = 1;
    setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    struct sockaddr_in addr_server;
    memset(&addr_server, 0, sizeof(addr_server));
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(_server_port);
    addr_server.sin_addr.s_addr = INADDR_ANY;

    int ret = bind(fd_server, (struct sockaddr *)&addr_server, sizeof(addr_server)); 
    if (-1 == ret) {
        perror("bind"); 
        return 1;
    }
    listen(fd_server, 10);
 
    while(true) {
        struct sockaddr_in addr_client;
        socklen_t len_client = sizeof(addr_client);
        int fd_client = accept(fd_server, (struct sockaddr *)&addr_client, &len_client);

        fprintf(stdout, "fd_client = %d\n", fd_client);
        pthread_t tid;
        pthread_create(&tid, NULL, _Thread_Server, (void *)&fd_client);
    }
    
    close(fd_server);
    return 0;
}
