#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

/*
#include <unistd.h>
unsigned alarm(unsigned seconds);
*/

int main(int argc, char *argv[]) {
    unsigned int seconds;

    seconds = alarm(7);
    printf("seconds = %d\n", seconds);

    sleep(3);
    seconds = alarm(5);
    printf("seconds = %d\n", seconds);

    getchar();
    seconds = alarm(0);
    printf("seconds = %d\n", seconds);

    while(true) {
    	printf("getpid = %d, getppid = %d\n", getpid(), getppid());
    	sleep(1);
    }

	return 0;
}
