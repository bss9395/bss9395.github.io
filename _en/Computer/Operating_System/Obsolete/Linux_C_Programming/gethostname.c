#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int gethostname(char *name, size_t len);
int sethostname(const char *name, size_t len);
#endif // 0

int main(int argc, char *argv[]) {
	char hostname[BUFSIZ] = "Ubuntu";
	if(-1 == sethostname(hostname, strlen(hostname))) {
		// perror("sethostname");

		char action[BUFSIZ] = { '\0' };
		sprintf(action, "gcc -o a.out %s && sudo ./a.out && rm a.out ", __FILE__);
		system(action);
	} else {
		gethostname(hostname, sizeof(hostname));
		printf("hostname = %s\n", hostname);
	}

	return 0;
}