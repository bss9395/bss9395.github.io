#include <stdio.h>
#include <errno.h>
#include <string.h>

#if 0
char *strerror(int errnum);
int strerror_r(int errnum, char *buf, size_t buflen);
/* XSI-compliant */
char *strerror_r(int errnum, char *buf, size_t buflen);
/* GNU-specific */
char *strerror_l(int errnum, locale_t locale);
#endif // 0

int main(int argc, char *argv[]) {
	errno = 1;
	printf("%d, %s\n", errno, strerror(errno));

	errno = EAGAIN;	
	printf("%d, %s\n", errno, strerror(errno));

	return 0;
}
