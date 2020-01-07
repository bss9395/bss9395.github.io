#if 0
#include <openssl/sha.h>
unsigned char *SHA512(const unsigned char *d, size_t n, unsigned char *md);

int SHA512_Init(SHA512_CTX *c);
int SHA512_Update(SHA512_CTX *c, const void *data, size_t len);
int SHA512_Final(unsigned char *md, SHA512_CTX *c);
#endif

#include <openssl/sha.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void SHA512_Hash(void *data, void *digest) {
    SHA512(data, strlen(data), digest);
}

void SHA512_Digest(void *data, void *digest) {
	SHA512_CTX ctx;
	SHA512_Init(&ctx);
	SHA512_Update(&ctx, data, strlen(data));
	SHA512_Final(digest, &ctx);
}

int main() {
	unsigned char data[] = "hello, world!";
    unsigned char digest[1024] = "0123456789";
    unsigned char buffer[1024] = "0123456789";

    SHA512_Hash(data, digest);
    // SHA512_Digest(data, digest);
    for(long i = 0; i < SHA512_DIGEST_LENGTH; i += 1) {
        snprintf((char *)&buffer[i * 2], 2 + 1, "%02x", digest[i]);
    }

    fprintf(stdout, "SHA512 digest: \n");
    fprintf(stdout, "\t%s\n", digest);
	fprintf(stdout, "\t%s\n", buffer);

	return 0;
}
