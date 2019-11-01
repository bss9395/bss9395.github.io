#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <poll.h>
#include <sys/epoll.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#if 0
int epoll_create(int size);
int epoll_create1(int flags);
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
int epoll_pwait(int epfd, struct epoll_event *events, int maxevents, int timeout, const sigset_t *sigmask);
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

    struct epoll_event events[2];
    struct epoll_event epoll_eve[2];
    int epoll_fd = epoll_create(10);

    events[0].events = EPOLLIN;
    events[0].data.fd = STDIN_FILENO;
    events[1].events = EPOLLIN;
    events[1].data.fd = conn_fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, STDIN_FILENO, &events[0]);
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, conn_fd, &events[1]);

    char buf_in[BUFSIZ] = { '\0' };
    char buf_fd[BUFSIZ] = { '\0' };
    while(true) {
        int num = epoll_wait(epoll_fd, epoll_eve, sizeof(epoll_eve)/sizeof(*epoll_eve), 2000);
        printf("num = %d\n", num);
        if(-1 == num) {
            perror("epoll_wait");
        }
        else if(0 == num) {
            printf("----epoll_wait timeout----\n");
        }
        else if(0 < num) {
            for(int i = 0; i < num; ++i) {
                if((uint32_t)(epoll_eve[i].events & EPOLLIN)) {
                    if(epoll_eve[i].data.fd == STDIN_FILENO) {
                        fgets(buf_in, sizeof(buf_in), stdin);
                        int str_len = strlen(buf_in);
                        buf_in[str_len - 1] = '\0';
                        int len = send(conn_fd, buf_in, str_len, 0);
                    }
                    else if(epoll_eve[i].data.fd == conn_fd) {
                        int len = recv(conn_fd, buf_fd, sizeof(buf_fd), 0);
                        fprintf(stdout, "received from client %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));
                        fprintf(stdout, "%s#\n", buf_fd);
                    }
                }
            }
        }
    }
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
