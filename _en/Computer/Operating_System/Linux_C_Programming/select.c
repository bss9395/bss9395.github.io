#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#if 0
int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
void FD_CLR(int fd, fd_set *set);
int  FD_ISSET(int fd, fd_set *set);
void FD_SET(int fd, fd_set *set);
void FD_ZERO(fd_set *set);
int pselect(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, const struct timespec *timeout, const sigset_t *sigmask);
#endif // 0

static const char *SERVER_ADDR = "127.0.0.1";
static const unsigned SERVER_PORT = 9395;

void *server_thread(void *args) {
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

void *client_thread(void *args) {
    int conn_fd = *((int *)args);

    struct sockaddr_in conn_addr;
    socklen_t conn_len = sizeof(conn_addr);
    getpeername(conn_fd, (struct sockaddr *)&conn_addr, &conn_len);

    struct timeval time_val_, time_val;
    time_val_.tv_sec = 2;
    time_val_.tv_usec = 0;

    fd_set read_fds_, read_fds;
    fd_set write_fds_, write_fds;
    FD_ZERO(&read_fds_);
    FD_ZERO(&write_fds_);
    FD_SET(STDIN_FILENO, &read_fds_);
    FD_SET(conn_fd, &read_fds_);

    char buf_in[BUFSIZ] = { '\0' };
    char buf_fd[BUFSIZ] = { '\0' };
    while(true) {
        read_fds = read_fds_;
        write_fds = write_fds_;
        time_val = time_val_;
        int ret = select(conn_fd + 1, &read_fds, &write_fds, NULL, &time_val);
        printf("ret = %d\n", ret);
        if(-1 == ret) {
            perror("select");
        }
        else if(0 == ret) {
            printf("----select timeout----\n");
        }
        else if(0 < ret) {
            if(FD_ISSET(STDIN_FILENO, &read_fds)) {
                fgets(buf_in, BUFSIZ, stdin);
                int str_len = strlen(buf_in);
                buf_in[str_len - 1] = '\0';
                int len = send(conn_fd, buf_in, str_len, 0);
            }
            if(FD_ISSET(conn_fd, &read_fds)) {
                int len = recv(conn_fd, buf_fd, sizeof(buf_fd), 0);
                printf("receive from server %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));
                printf("%s#\n", buf_fd);
            }
        }
    }

    close(conn_fd);
}

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if(0 == pid) {
        struct sockaddr_in conn_addr;
        conn_addr.sin_family = AF_INET;
        conn_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
        conn_addr.sin_port = htons(SERVER_PORT);

        int conn_fd = socket(AF_INET, SOCK_STREAM, 0);
        connect(conn_fd, (struct sockaddr *)&conn_addr, sizeof(conn_addr));

        pthread_t tid;
        pthread_create(&tid, NULL, client_thread, (void *)&conn_fd);
        pthread_join(tid, NULL);

        while(true) {
            printf("client: client close....\n");
            sleep(1);
        }

        close(conn_fd);
    }
    else if(0 < pid) {
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        server_addr.sin_port = htons(SERVER_PORT);
        int on = 1;

        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
        bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
        listen(server_fd, 20);

        while(true) {
            struct sockaddr_in client_addr;
            socklen_t client_len = sizeof(client_addr);
            int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);

            pthread_t tid;
            pthread_create(&tid, NULL, server_thread, (int *)&client_fd);
            pthread_join(tid, NULL);
        }

        while(true) {
            printf("server: server close...\n");
            sleep(1);
        }

        close(server_fd);
    }

    return 0;
}