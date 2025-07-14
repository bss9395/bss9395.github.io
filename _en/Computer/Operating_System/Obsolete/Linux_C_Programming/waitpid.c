/* waitpid.c
Author: BSS9395
Update: 2023-09-18T15:24:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: waitpid
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

/*
#include <sys/wait.h>
pid_t waitpid(pid_t pid, int *stat_loc, int options);
*/


void sig_child(int signo) {
    pid_t  pid;    
    while (pid = waitpid(-1, NULL, WNOHANG), 0 < pid)  //处理僵尸进程, -1表示等待任意一个子进程, WNOHANG代表不阻塞
    {
        printf("child %d terminated.\n", pid);
    }
}

int main(void) {
    signal(SIGCHLD, sig_child);

    pid_t pid = fork();
    if (-1 == pid) {
        perror("fork"); 
        return 1;
    } else if (0 == pid) {
        for (int i = 0; i < 3; i += 1) {
            printf("getpid() = %d, getppid() = %d\n", getpid(), getppid());
            sleep(1);
        }
        return 0; 
    } else if(0 < pid) {
        for (int i = 0; i < 8; i += 1) {
            printf("getpid() = %d, getppid() = %d\n", getpid(), getppid());
            sleep(1); 
        }
    }

    return 0;
}
