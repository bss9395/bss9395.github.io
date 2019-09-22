#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
int raise(int sig);
#endif // 0

int main(int argc, char *argv[]) {
    while(true) {
        static int i = 0;
        
        printf("getpid = %d, getppid = %d\n", getpid(), getppid());
        sleep(1);

        if(5 == i) {
            raise(SIGINT);
        }
        i++;
    }

    system("ps -o pid,ppid,tty,state,command");

    return 0;
}
