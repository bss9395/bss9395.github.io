/* chown.c
Author: BDD9395
Update: 2023-09-15T11:52:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: chown
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
#include <unistd.h>
int chown(const char *path, uid_t owner, gid_t group);

#include <fcntl.h>
int fchownat(int fd, const char *path, uid_t owner, gid_t group, int flag);
*/

int main(int argc, char *argv[]) {
    int fd = open("tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if(-1 == fd) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    write(fd, "ABCDEFGHIJ", 10);

    system("ls -l tmp.txt");
    int ret = chown("tmp.txt", 0, 0);  // chown root:root
    if(ret != 0) {
        perror("chown");
        exit(EXIT_FAILURE);
    }
    system("ls -l tmp.txt");

    return 0;
}
