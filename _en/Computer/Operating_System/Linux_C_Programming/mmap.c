#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void *addr, size_t length);
#endif // 0

int main(int argc, char *argv[]) {
    int fd = open("tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if(-1 == fd) {
        perror("open");
        exit(1);
    }

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
        lseek(fd, 0, SEEK_SET);
        write(fd, addr, strlen(addr));
    }
    else if(0 < pid) {
        wait(NULL);
        char *ptr = NULL;
        while(ptr = strstr(addr, "hello"), ptr != NULL) {
            memcpy(ptr, "Linux", 5);
            ptr += 5;
        }
        printf("%s\n", (char *)addr);

        lseek(fd, 0, SEEK_SET);
        write(fd, addr, strlen(addr));

    }

    close(fd);

    return 0;
}
