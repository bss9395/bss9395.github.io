#include <stdio.h>
#include <errno.h>

#if 0
void perror(const char *s);
#endif // 0

int main(int argc, char *argv[]) {
	errno = 1;
	perror("errno = 1");

	errno = EAGAIN;
	perror("errno = EAGAIN");
	return 0;
}
