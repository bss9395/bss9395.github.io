#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
#include <signal.h>
int raise(int sig);
*/

int main(int argc, char *argv[]) {
    while(true) {
        static int i = 0;
        
        printf("getpid = %d, getppid = %d\n", getpid(), getppid());
        sleep(1);

        if(5 == i) {
            raise(SIGINT);
			// kill(getpid(), SIGINT);
        }
        i++;
    }

    system("ps -o pid,ppid,tty,state,command");

    return 0;
}
