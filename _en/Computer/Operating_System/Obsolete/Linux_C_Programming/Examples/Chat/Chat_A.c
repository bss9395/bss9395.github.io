/* Chat_A.c
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
        int fd_a = open("fifo_a", O_RDONLY);
        if(-1 == fd_a) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        char buffer[1024];
        while(true) {
            memset(buffer, 0, 1024);
            int ret = read(fd_a, buffer, 1024);
            if(ret <= 0) {
                break;
            }
            fprintf(stdout, "fifo_a = %s\n", buffer);
        }
        close(fd_a);
    } else if (0 < pid) {
        int fd_b = open("fifo_b", O_WRONLY);
        if(-1 == fd_b) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        char buffer[1024];
        while(true) {
            fgets(buffer, 512, stdin);
            if('\n' == buffer[strlen(buffer) - 1]) {
                buffer[strlen(buffer) - 1] = '\0';
            }
            int ret = write(fd_b, buffer, strlen(buffer));
            if(ret <= 0) {
                break;
            }
        }
        close(fd_b);
    }
    return 0;    
}
