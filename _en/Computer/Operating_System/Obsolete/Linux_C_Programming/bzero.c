#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char buf[] = "hello, world!";
	bzero(buf, sizeof(buf));
	printf("length = %ld\n", strlen(buf));

	return 0;
}