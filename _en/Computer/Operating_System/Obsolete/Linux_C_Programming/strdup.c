#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
char *strdup(const char *s);
char *strndup(const char *s, size_t n);
char *strdupa(const char *s);
char *strndupa(const char *s, size_t n);
#endif // 0

int main(int argc, char *argv[]) {
	char *path1 = strdup(argv[0]);
	printf("%s\n", path1);

	char *path2 = strndup(argv[0], 3);
	printf("%s\n", path2);

	free(path1);
	free(path2);
	return 0;
}