#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
int creat(const char *pathname, mode_t mode);
int openat(int dirfd, const char *pathname, int flags);
int openat(int dirfd, const char *pathname, int flags, mode_t mode);
*/

int main() {
    int fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    char buf[10];
    int n;
    n = read(fd, buf, sizeof(buf));
    if (n < 0) {
        if (errno != EAGAIN) {
            perror("read /dev/tty");
            return -1;
        }
        printf("没有数据可读。\n");
    }
    return 0;
}