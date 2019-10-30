#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "openssl/md5.h"

#if 0
unsigned char *MD5(const unsigned char *d, unsigned long n, unsigned char *md);
int MD5_Init(MD5_CTX *c);
int MD5_Update(MD5_CTX *c, const void *data, unsigned long len);
int MD5_Final(unsigned char *md, MD5_CTX *c);
#endif

int main(int argc, char *argv[]) {
    char *data = "hello itcast";
    unsigned char md[MD5_DIGEST_LENGTH + 1] = { '\0' };

    MD5((const unsigned char *)data, strlen(data), md);

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", md[i]);
    }
    putchar('\n');

    return 0;
}
