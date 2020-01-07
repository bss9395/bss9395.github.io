#if 0
#include <openssl/md5.h>
unsigned char *MD5(const unsigned char *d, unsigned long n, unsigned char *md);

int MD5_Init(MD5_CTX *c);
int MD5_Update(MD5_CTX *c, const void *data, unsigned long len);
int MD5_Final(unsigned char *md, MD5_CTX *c);
#endif

#include <openssl/md5.h>

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MD5_Hash(void *data, void *digest) {
    MD5(data, strlen(data), digest);
}

void MD5_Digest(void *data, void *digest) {
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, data, strlen(data));
    MD5_Final(digest, &ctx);
}

int main(int argc, char *argv[]) {
    unsigned char data[] = "hello, world!";
    unsigned char digest[1024] = "0123456789";
    unsigned char buffer[1024] = "0123456789";

    MD5_Hash(data, digest);
    // MD5_Digest(data, digest);
    for(long i = 0; i < MD5_DIGEST_LENGTH; i += 1) {
        snprintf((char *)&buffer[i * 2], 2 + 1, "%02x", digest[i]);
    }

    fprintf(stdout, "MD5 digest: \n");
    fprintf(stdout, "\t%s\n", digest);
	fprintf(stdout, "\t%s\n", buffer);

	return 0;
}
