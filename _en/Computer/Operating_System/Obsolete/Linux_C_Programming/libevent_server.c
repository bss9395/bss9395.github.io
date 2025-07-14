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
gcc -o server.out libevent_server.c -levent
#endif

static char *SERVER_ADDR = "127.0.0.1";
static char *SERVER_BIND = "0.0.0.0";
static int   SERVER_PORT = 9395;

void error_cb(struct bufferevent *bufev, short events, void *arg) {
    if(events & BEV_EVENT_EOF) {
        printf("connection closed...\n");
    }
    if(events & BEV_EVENT_ERROR) {
        printf("event error...\n");
    }
    if (events & BEV_EVENT_CONNECTED) {
        printf("connected to client...\n");
        return ;
    }

    bufferevent_free(bufev);
}

void read_cb(struct bufferevent *bufev, void *arg) {
    char buf[BUFSIZ] = "01234567890";
    long read_len = bufferevent_read(bufev, buf, sizeof(buf));
    buf[read_len] = '\0';

    printf("read from client: \e[32m%s\e[0m", buf);
    for(int i = 0; i < read_len; ++i) {
        buf[i] = toupper(buf[i]);
    }
    bufferevent_write(bufev, buf, read_len);
}

void listener_cb(struct evconnlistener *listener, evutil_socket_t fd, struct sockaddr *sock, int socklen, void *arg) {
    struct event_base *base = (struct event_base *)arg;
    struct bufferevent *bufev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
    bufferevent_setcb(bufev, read_cb, NULL, error_cb, NULL);
    bufferevent_enable(bufev, EV_READ | EV_PERSIST);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in server_in;
    server_in.sin_family = AF_INET;
    server_in.sin_addr.s_addr = inet_addr(SERVER_BIND);
    server_in.sin_port = htons(SERVER_PORT);

    struct event_base *base = event_base_new();
    struct evconnlistener *listener = evconnlistener_new_bind(base, listener_cb, base, LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE, 10, (struct sockaddr *)&server_in, sizeof(server_in));
    event_base_dispatch(base);

    evconnlistener_free(listener);
    event_base_free(base);
    return 0;
}
