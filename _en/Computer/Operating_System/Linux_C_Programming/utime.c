
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <utime.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stdout, "usage: copy source destination");
        exit(EXIT_FAILURE);
    }

    if(strcmp(argv[1], argv[2]) == 0) {
        fprintf(stdout, "源文件与目的文件同名！");
        exit(EXIT_FAILURE);
    }

    int fd_read = open(argv[1], O_RDONLY);
    if(-1 == fd_read) {
        perror("open source error");
        exit(EXIT_FAILURE);
    }

    int fd_write = open(argv[2], O_WRONLY | O_CREAT, 0666);
    if(-1 == fd_write) {
        perror("open destination error");
        exit(EXIT_FAILURE);
    }

    char buffer[512] = {0};
    int len = 0;
    while(len = read(fd_read, buffer, sizeof(buffer)), 0 < len) {
        write(fd_write, buffer, len);
    }
    close(fd_read);
    close(fd_write);


    struct stat stat_read;
    stat(argv[1], &stat_read);

    struct utimbuf time_write;
    time_write.actime = stat_read.st_atime;
    time_write.modtime = stat_read.st_mtime;
    utime(argv[2], &time_write);
    int ret = chmod(argv[2], stat_read.st_mode);
    if(ret < 0) {
        perror("chmod");
    }
    ret = chown(argv[2], stat_read.st_uid, stat_read.st_gid);
    if(ret < 0) {
        perror("chown");
    }

    return 0;
}
