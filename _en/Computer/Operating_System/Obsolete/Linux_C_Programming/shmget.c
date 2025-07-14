#if 0
#include <sys/ipc.h>
#include <sys/shm.h>
int shmget(key_t key, size_t size, int shmflg);
void *shmat(int shmid, const void *shmaddr, int shmflg);
int shmdt(const void *shmaddr);
#endif

#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void write_shared_memory() {
	char data[128] = "Hello, world.";

	int mid = shmget(0x12, 1024, IPC_CREAT | 0644);
	// int mid = shmget(0x12, 1024, IPC_CREAT | IPC_EXCL | 0644);
	if (mid == -1) {
		perror("shmget");
	}

	void *addr = shmat(mid, NULL, 0);
	if (addr == (void *)-1) {
		perror("shmget");
	}

	memcpy(addr, data, strlen(data) + 1);

	int err = shmdt(addr);
	if (err == -1) {
		perror("shmdt");
	}
}

void read_shared_memory() {
	char buffer[128] = { "\0" };

	int mid = shmget(0x12, 0, 0);
	if (mid == -1) {
		perror("shmget");
	}

	void *addr = shmat(mid, NULL, 0);
	if (addr == (void *)-1) {
		perror("shmat");
	}

	memcpy(buffer, addr, 128);
	fprintf(stderr, "%s\n", buffer);

	int err = shmdt(addr);
	if (err == -1) {
		perror("shmdt");
	}
}

int main(int argc, char *argv[]) {
	int pid = fork();
	if (pid < 0) {
		perror("fork");
	}
	else if (pid == 0) {
		write_shared_memory();
	}
	else if (pid > 0) {
		sleep(1);
		read_shared_memory();
	}

	return 0;
}
