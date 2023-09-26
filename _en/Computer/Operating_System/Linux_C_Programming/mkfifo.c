#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
#include <sys/types.h>
#include <sys/stat.h>
int mkfifo(const char *pathname, mode_t mode);

#include <fcntl.h>          
#include <sys/stat.h>
int mkfifoat(int dirfd, const char *pathname, mode_t mode);
*/

int main(int argc, char *argv[]) {
    int fifo = mkfifo("fifo", 0644);
    if(-1 == fifo) {
        perror("mkfifo");
        exit(1);
    }
    system("ls -l fifo");

    pid_t pid = fork();
    if(-1 == pid) {
        perror("fork");
        exit(1);
    }
    else if(0 == pid) {
        int fd = open("fifo", O_WRONLY);
        if(-1 == fd) {
            perror("child open");
            exit(1);
        }

        char buf[BUFSIZ] = { '\0' };
        int len = 0;
        int i = 0;
        do {
            sprintf(buf, "i = %d, getpid = %d, getppid = %d", i, getpid(), getppid());
            i += 1;
            sleep(1);
        } while(len = write(fd, buf, strlen(buf)), 0 < len && i < 10);

        close(fd);
    }
    else if(0 < pid) {
        int fd = open("fifo", O_RDONLY);
        if(-1 == fd) {
            perror("parent open");
            exit(1);
        }

        char buf[BUFSIZ] = { '\0' };
        int len = 0;
        while(len = read(fd, buf, BUFSIZ), 0 < len) {
            fprintf(stdout, "%s\n", buf);
        }

        close(fd);
        remove("fifo");
    }

    return 0;
}
