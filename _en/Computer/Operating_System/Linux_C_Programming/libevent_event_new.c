#include <event2/event.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#if 0
struct event *event_new(struct event_base *base, evutil_socket_t fd, short events, event_callback_fn callback, void *callback_arg);
#endif

void read_cb(evutil_socket_t fd, short events, void *arg) {
    printf("read_cb:%ld:%s%s%s%s:%p\n",
           (long)fd,
           (events & EV_TIMEOUT) ? " timeout" : "",
           (events & EV_READ)    ? " read"    : "",
           (events & EV_WRITE)   ? " write"   : "",
           (events & EV_SIGNAL)  ? " signal"  : "",
           arg);

    char buf[BUFSIZ] = "1234567890";
    long read_len = read(fd, buf, sizeof(buf));
    if(0 < read_len) {
        buf[read_len] = '\0';
        printf("\e[32m%s\e[0m\n", buf);
        return ;
    }

    if(read_len == -1) {
        perror("read");
    }
    else if(read_len == 0) {
        printf("connection cloced...\n");
    }
    struct event *ev = (struct event *)arg;
    event_del(ev);
    event_base_loopbreak(event_get_base(ev));
}

void write_cb(evutil_socket_t fd, short events, void *arg) {
    printf("write_cb:%ld:%s%s%s%s:%p\n",
           (long)fd,
           (events & EV_TIMEOUT) ? " timeout" : "",
           (events & EV_READ)    ? " read"    : "",
           (events & EV_WRITE)   ? " write"   : "",
           (events & EV_SIGNAL)  ? " signal"  : "",
           arg);

    int write_fd = *((int *)arg);
    long write_len = write(write_fd, __FILE__, strlen(__FILE__));
    if(write_len != strlen(__FILE__)) {
        perror("write");
    }
}

int main(int argc, char *argv[]) {
    struct itimerval timetick;
    timetick.it_value.tv_sec = 1;
    timetick.it_value.tv_usec = 0;
    timetick.it_interval.tv_sec = 1;
    timetick.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timetick, NULL);

    const char *fifo = "event.fifo";
    unlink(fifo);
    mkfifo(fifo, 0644);
    int read_fd = open(fifo, O_RDONLY | O_NONBLOCK, 0644);
    int write_fd = open(fifo, O_WRONLY | O_NONBLOCK, 0644);

    struct event_base *base = event_base_new();
    struct event *read_ev  = event_new(base, read_fd,   EV_READ  | EV_PERSIST | EV_TIMEOUT, read_cb,  event_self_cbarg());
    struct event *write_ev = event_new(base, SIGALRM, EV_SIGNAL | EV_PERSIST, write_cb, (void *)&write_fd);

    // struct timeval timeout;
    // timeout.tv_sec = 1;
    // timeout.tv_usec = 100;
    //event_add(read_ev, &timeout);
    event_add(read_ev, NULL);
    event_add(write_ev, NULL);

    event_base_dispatch(base);
    event_base_free(base);

    close(write_fd);
    close(read_fd);
    unlink(fifo);
    return 0;
}
