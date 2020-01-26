#if 0
#include <sys/types.h>
#include <sys/ipc.h>
key_t ftok(const char *pathname, int proj_id);
#endif

#include <sys/ipc.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char buf[1024] = { '\0' };
	getcwd(buf, sizeof(buf));

	int key = ftok(buf, (int)0x01);
	printf("key = %d\n", key);

	return 0;
}