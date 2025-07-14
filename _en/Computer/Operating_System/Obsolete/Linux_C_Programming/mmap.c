#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
#include <sys/mman.h>
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void *addr, size_t length);
*/

int main(int argc, char *argv[]) {
	system("echo abcdefg > tmp.txt");
    int fd = open("tmp.txt", O_RDWR, 0644);
    if(-1 == fd) {
        perror("open");
        exit(1);
    }
    close(fd);

    // void *addr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    void *addr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if(addr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
	

    pid_t pid = fork();
    if(-1 == pid) {
        perror("fork");
        exit(1);
    }
    else if(0 == pid) {
        memcpy(addr, "hello, world!", 13);
    }
    else if(0 < pid) {
        wait(NULL);
        printf("%s\n", (char *)addr);
    }

    munmap(addr, 1024);	

    return 0;
}
