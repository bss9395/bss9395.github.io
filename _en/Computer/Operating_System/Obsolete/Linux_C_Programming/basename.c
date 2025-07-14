#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>

#if 0
char *dirname(char *path);
char *basename(char *path);
#endif // 0

int main(int argc, char *argv[]) {
	char *path[] = {
		"/usr/lib",
		"/usr/",
		"usr",
		"/",
		".",
		".."
	};

	for(int i = 0; i < sizeof(path)/sizeof(*path); ++i) {
		char *tmp1 = strdup(path[i]);
		char *tmp2 = strdup(path[i]);

		printf("%d:%s#%s\n", i, dirname(tmp1), basename(tmp2));

		free(tmp1);
		free(tmp2);
	}

	return 0;
}

/*
path       dirname   basename
/usr/lib   /usr      lib
/usr/      /         usr
usr        .         usr
/          /         /
.          .         .
..         .         ..
*/