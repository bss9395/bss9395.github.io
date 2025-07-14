#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#if 0
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen);
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
#endif // 0

static const char *SERVER_ADDR = "127.0.0.1";
static const unsigned SERVER_PORT = 6666;

void *server_thread(void *args) {
    pthread_detach(pthread_self());
    int client_fd = *((int *)args);

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    getpeername(client_fd, (struct sockaddr *)&client_addr, &client_len);

    char buf[BUFSIZ] = { '\0' };
    while(true) {
        ssize_t len = read(client_fd, buf, BUFSIZ);
        if(len <= 0) {
            fprintf(stdout, "server: client close...\n");
            break;
        }

        fprintf(stdout, "received from client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        fprintf(stdout, "%s\n", buf);

        for(int i = 0; i < len; ++i) {
            buf[i] = toupper(buf[i]);
        }

        len = write(client_fd, buf, len);
    }

    close(client_fd);
}

void *client_process(void *args) {
    struct sockaddr_in conn_addr;
    conn_addr.sin_family = AF_INET;
    conn_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    //inet_pton(AF_INET, SERVER_ADDR, &conn_addr.sin_addr);
    conn_addr.sin_port = htons(SERVER_PORT);

    int conn_fd = socket(AF_INET, SOCK_STREAM, 0);
    connect(conn_fd, (struct sockaddr *)&conn_addr, sizeof(conn_addr));

    char buf[BUFSIZ] = { '\0' };
    char tmp[BUFSIZ] = { '\0' };

    for(int i = 0; i < 2; ++i) {
        write(conn_fd, __FILE__, strlen(__FILE__));
        ssize_t len = read(conn_fd, buf, BUFSIZ);
        if(len <= 0) {
            break;
        }

        fprintf(stdout, "received from server %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));
        // fprintf(stdout, "received from server %s:%d\n", inet_ntop(AF_INET, &conn_addr.sin_addr, tmp, sizeof(conn_addr)), ntohs(conn_addr.sin_port));
        fprintf(stdout, "%s\n", buf);
    }

    write(conn_fd, "", 0);
    fprintf(stdout, "client: client close...\n");
    close(conn_fd);
}

int main(int argc, char *argv[]) {
    if(0 == fork()) {
        sleep(1);

        fprintf(stdout, "child: getpid = %d, getppid = %d\n", getpid(), getppid());
        pid_t pid = fork();
        if(0 == pid) {
            sleep(1);

            fprintf(stdout, "----------------------------------------\n");
            fprintf(stdout, "client 1: pid = %d, getpid = %d, getppid = %d\n", pid, getpid(), getppid());
            client_process((void *)0x01);
        }
        else if(0 < pid) {
            fprintf(stdout, "----------------------------------------\n");
            fprintf(stdout, "client 2: pid = %d, getpid = %d, getppid = %d\n", pid, getpid(), getppid());
            client_process((void *)0x02);
        }
    }
    else {
        fprintf(stdout, "parent: getpid = %d, getppid = %d\n", getpid(), getppid());

        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = htonl(INADDR_ANY);
        server.sin_port = htons(SERVER_PORT);

        fprintf(stdout, "sizeof(sockaqddr_in.sin_addr.s_addr) = %ld\n", sizeof(server.sin_addr.s_addr));
        fprintf(stdout, "sizeof(sockaddr.sin_port) = %ld\n", sizeof(server.sin_port));
        fprintf(stdout, "server.sin_addr.s_addr = %d\n", ntohl(server.sin_addr.s_addr));
        fprintf(stdout, "server.sin_port = %d\n", ntohs(server.sin_port));

        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        int on = 1;
        setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
        bind(server_fd, (struct sockaddr *)&server, sizeof(server));
        listen(server_fd, 20);

        while(true) {
            struct sockaddr_in client_addr;
            socklen_t client_len = sizeof(client_addr);
            int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);

            pthread_t tid;
            pthread_create(&tid, NULL, server_thread, (void *)&client_fd);
        }

        close(server_fd);
    }

    return 0;
}
