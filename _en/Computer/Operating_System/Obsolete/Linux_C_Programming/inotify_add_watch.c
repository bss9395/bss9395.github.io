/* inotify_add_watch.c
Author: BSS9395
Update: 2023-10-03T11:43:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: inotify_add_watch
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/inotify.h>

/*
#include <sys/inotify.h>
int inotify_add_watch(int fd, const char *pathname, uint32_t mask);
*/

static const int   _event_num = 12; 
static const char *_event_str[12] = {
	"IN_ACCESS",
	"IN_MODIFY",
	"IN_ATTRIB",
	"IN_CLOSE_WRITE",
	"IN_CLOSE_NOWRITE",
	"IN_OPEN",
	"IN_MOVED_FROM",
	"IN_MOVED_TO",
	"IN_CREATE",
	"IN_DELETE",
	"IN_DELETE_SELF",
	"IN_MOVE_SELF"
};

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s path\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = inotify_init();

INOTIFY_AGAIN:
    int wd = inotify_add_watch(fd, argv[1], IN_ALL_EVENTS);
    if(wd < 0) {
        perror("inotify_add_watch");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int length = read(fd, buffer, 1024);
    int count = 0;
    while(count < length) {
        struct inotify_event *event = (struct inotify_event *)&buffer[count];
        for(int i = 0; i < _event_num; i += 1) {
            if((event->mask >> i) & 0x01){
                if(event->len == 0) {        // ¼à¿ØÎÄ¼þ
                    if(event->wd == wd) {
                        fprintf(stdout, "[%s] %s\n", argv[1], _event_str[i]);
                    }
                } else if(event->len > 0) {  // ¼à¿ØÄ¿Â¼
                    fprintf(stdout, "[%s] %s\n", argv[1], _event_str[i]);
                }
            }
        } 
        count  = count  + sizeof(struct inotify_event) + event->len;
    }
    goto INOTIFY_AGAIN;

    close(fd);
}
