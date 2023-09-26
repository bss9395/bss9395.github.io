/* Chat_B.c
Author: BSS9395
Update: 2023-09-17T15:38:00+08@China-Guangdong-Zhanjiang+08
Design: Chat
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
    system("mkfifo fifo_a");
    system("mkfifo fifo_b");

    pid_t pid = fork();
    if(pid == 0) {
        int fd_a = open("fifo_a", O_WRONLY);
        if(fd_a == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        char buffer[1024];
        while(true) {
            fgets(buffer, 1024, stdin);
            if('\n' == buffer[strlen(buffer) - 1]) {
                buffer[strlen(buffer) - 1] = '\0';
            }
            write(fd_a, buffer, strlen(buffer));
        }
        close(fd_a);
    } else if(0 < pid) {
        int fd_b = open("fifo_b", O_RDONLY);
        if(fd_b == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        char buffer[1024];
        while(true) {
            memset(buffer, 0, 1024);
            int ret = read(fd_b, buffer, 1024);
            if(ret <= 0) {
                break;
            }
            fprintf(stdout, "fifo_b = %s\n", buffer);
        }
        close(fd_b);
    }    
    return 0;
}
