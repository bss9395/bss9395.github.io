/* lseek.c
Author: BSS9395
Update: 2023-09-14T18:53:00+08@China-Guangdong-Zhanjiang+08
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
#include <unistd.h>
off_t lseek(int fildes, off_t offset, int whence);
*/

int main(int argc, char *argv[]) {
    int fd = open("tmp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(-1 == fd) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    write(fd, "0123456789", 10);
    int ret = lseek(fd, 0, SEEK_CUR);
    fprintf(stdout, "lseek = %d\n", ret);

    close(fd);
    return 0;
}

