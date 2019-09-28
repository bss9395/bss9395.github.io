#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	unsigned num = 0x12345678;
	char *ptr = (char *)&num;

	fprintf(stderr, "sizeof(unsigned) = %ld\n", sizeof(unsigned));
	fprintf(stderr, "sizeof(char) = %ld\n", sizeof(char));

	if(*ptr == 0x12) {
		fprintf(stderr, "big endian\n");
	}
	else if(*ptr == 0x78) {
		fprintf(stderr, "little endian\n");
	}

	return 0;
}