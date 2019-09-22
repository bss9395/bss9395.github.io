#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    unsigned int seconds;

    seconds = alarm(5);
    printf("seconds = %d\n", seconds);

    sleep(3);
    seconds = alarm(7);
    printf("seconds = %d\n", seconds);

    int ch = '\0';
    if(ch = getchar()) {
        seconds = alarm(0);
        printf("seconds = %d\n", seconds);
    }

    while(true) {
    	statis int i = 0;

    	printf("getpid = %d, getppid = %d\n", getpid(), getppid());
    	sleep(1);

    	if(5 == i) {
    		break;
    	}
    	i++;
    }

	return 0;
}
