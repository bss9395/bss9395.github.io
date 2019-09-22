#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
int access(const char *pathname, int mode);
int faccessat(int dirfd, const char *pathname, int mode, int flags);
#endif // 0

int main(int argc, char *argv[]) {
	if(argc != 2) {
		fprintf(stderr, "usage: %s filename \n", argv[0]);
		exit(1);
	}

	int ret = 0;
	
	ret = access(argv[1], F_OK);
	if(0 == ret) {
		fprintf(stdout, "file exits. \n");
	}

	ret = access(argv[1], R_OK);
	if(0 == ret) {
		fprintf(stdout, "file readable. \n");
	}

	ret = access(argv[1], W_OK);
	if(0 == ret) {
		fprintf(stdout, "file writable. \n");
	}

	ret = access(argv[1], X_OK);
	if(0 == ret) {
		fprintf(stdout, "file executable. \n");
	}

	return 0;
}
