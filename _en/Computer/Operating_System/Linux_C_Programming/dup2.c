/* dup2.c
Author: BSS9395
Update: 2023-09-18T15:42:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: dup2
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

/*
#include <unistd.h>
int dup(int fildes);
int dup2(int fildes, int fildes2);
*/

// note: ps aux | grep bash
int main(void) {
    int fd[2] = {0};
    int ret = pipe(fd);
    if (-1 == ret) {
        perror("pipe"); 
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (-1 == pid) {
        perror("fork"); 
        exit(EXIT_FAILURE);
    } else if (0 == pid) {
        close(fd[0]); 
        dup2(fd[1], STDOUT_FILENO);
        execlp("ps", "ps", "aux", NULL);
        exit(0); 
    } else {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        wait(NULL);
        execl("/bin/grep", "grep", "bash", "--color=auto", NULL);
    }
    return 0;
}
