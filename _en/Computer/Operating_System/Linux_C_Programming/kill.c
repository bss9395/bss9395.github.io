#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
#include <signal.h>
int kill(pid_t pid, int sig);
*/

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if(0 == pid){
        for(int i = 0; i < 10; ++i) {
            printf("child process: pid = %d, getpid = %d, getppid = %d\n", pid, getpid(), getppid());
            sleep(1);
        }
    }
    else if(0 < pid) {
        printf("parent process: pid = %d, getpid = %d, getppid = %d\n", pid, getpid(), getppid());
        system("ps -o pid,ppid,tty,state,command");
        
        kill(pid, SIGINT);
        
        system("ps -o pid,ppid,tty,state,command");
    }

    return 0;
}