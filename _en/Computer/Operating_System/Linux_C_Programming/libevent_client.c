#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#if 0
gcc -o client.out libevent_client.c -levent
#endif

static char *SERVER_ADDR = "127.0.0.1";
static char *SERVER_BIND = "0.0.0.0";
static int   SERVER_PORT = 9395;

void error_cb(struct bufferevent *bufev, short event, void *arg) {
    if (event & BEV_EVENT_EOF) {
        printf("connection closed...\n");
    }
    if (event & BEV_EVENT_ERROR) {
        printf("event error...\n");
    }
    if (event & BEV_EVENT_CONNECTED) {
        printf("connected to server...\n");
        return ;
    }

    bufferevent_free(bufev);
}

void read_ev_cb(int fd, short events, void *arg) {
    struct bufferevent *bufev = (struct bufferevent *)arg;
    char buf[BUFSIZ] = "01234567890";

    long read_len = read(fd, buf, sizeof(buf));
    if(read_len < 0) {
        perror("read");
        exit(1);
    }

    buf[read_len] = '\0';
    bufferevent_write(bufev, buf, read_len);
}

void read_cb(struct bufferevent* bufev, void *arg) {
    char buf[BUFSIZ] = "01234567890";
    long read_len = bufferevent_read(bufev, buf, sizeof(buf));
    buf[read_len] = '\0';

    printf("received from server: \033[32m %s\033[0m", buf);
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in server_in;
    server_in.sin_family = AF_INET;
    server_in.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server_in.sin_port = htons(SERVER_PORT);

    struct event_base *base = event_base_new();
    struct bufferevent *bufev = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE);
    bufferevent_socket_connect(bufev, (struct sockaddr *)&server_in, sizeof(server_in));

    struct event *read_ev = event_new(base, STDIN_FILENO, EV_READ | EV_PERSIST, read_ev_cb, (void *)bufev);
    event_add(read_ev, NULL);
    bufferevent_setcb(bufev, read_cb, NULL, error_cb, NULL);
    bufferevent_enable(bufev, EV_READ | EV_PERSIST);

    event_base_dispatch(base);
    event_base_free(base);
    return 0;
}
