#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
int pipe(int pipefd[2]);
int pipe2(int pipefd[2], int flags);
#endif // 0

int main(int argc, char *argv[]) {
    int fd[2] = { 0 };
    int ret = pipe(fd);
    if(-1 == ret) {
        perror("pipe");
        exit(1);
    }

    printf("fd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);

    int pid = fork();
    if(-1 == pid) {
        perror("fork");
        exit(1);
    }
    else if(0 == pid) {
        write(fd[1], "1234567890", 10);
        close(fd[0]);
        close(fd[1]);
    }
    else {
        wait(NULL);

        char buf[BUFSIZ] = { '\0' };
        read(fd[0], buf, BUFSIZ);
        close(fd[0]);
        close(fd[1]);

        printf("%s\n", buf);
    }

    return 0;
}
