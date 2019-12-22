#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    unsigned num = 0x80000000;
    char *ptr = (char *)&num;

    fprintf(stderr, "sizeof(unsigned) = %ld\n", sizeof(unsigned));
    fprintf(stderr, "sizeof(char) = %ld\n", sizeof(char));

    if(ptr[0] == 0x21) {
        fprintf(stderr, "little endian\n");
    }
    else if(ptr[sizeof(unsigned) - 1] == 0x21) {
        fprintf(stderr, "big endian\n");
    }

	printf("ptr[%d] = %#x\n", 0, ptr[0]);
	printf("ptr[%d] = %#x\n", sizeof(unsigned) - 1, (unsigned char)ptr[sizeof(unsigned) - 1]);

    return 0;
}