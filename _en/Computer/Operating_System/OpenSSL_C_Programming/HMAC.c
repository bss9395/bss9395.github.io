#if 0
#include <openssl/hmac.h>
unsigned char *HMAC(const EVP_MD *evp_md, const void *key, int key_len, const unsigned char *d, int n, unsigned char *md, unsigned int *md_len);

HMAC_CTX *HMAC_CTX_new(void);
int HMAC_CTX_reset(HMAC_CTX *ctx);

int HMAC_Init_ex(HMAC_CTX *ctx, const void *key, int key_len, const EVP_MD *md, ENGINE *impl);
int HMAC_Update(HMAC_CTX *ctx, const unsigned char *data, int len);
int HMAC_Final(HMAC_CTX *ctx, unsigned char *md, unsigned int *len);

void HMAC_CTX_free(HMAC_CTX *ctx);

int HMAC_CTX_copy(HMAC_CTX *dctx, HMAC_CTX *sctx);
void HMAC_CTX_set_flags(HMAC_CTX *ctx, unsigned long flags);
const EVP_MD *HMAC_CTX_get_md(const HMAC_CTX *ctx);

size_t HMAC_size(const HMAC_CTX *e);
#endif

#include <openssl/hmac.h>
#include <stdlib.h>
#include <string.h>

const int HMAC_LENGTH = 32;

void HMAC_Hash(unsigned char *key, unsigned char *data, unsigned char *digest) {
	unsigned int len = 0;
	HMAC(EVP_sha256(), key, (int)strlen((char *)key), data, (int)strlen((char *)data), digest, &len);
}

void HMAC_Digest(unsigned char *key, unsigned char *data, unsigned char *digest) {
	HMAC_CTX *ctx = HMAC_CTX_new();
	if (ctx == NULL) {
		perror("HMAC_CTX_new");
	}

	int err = HMAC_Init_ex(ctx, key, (int)strlen((char *)key), EVP_sha256(), NULL);
	if (err == 0) {
		perror("HMAC_Init_ex");
	}

	err = HMAC_Update(ctx, data, strlen((char *)data));
	if (err == 0) {
		perror("HMAC_Update");
	}

	unsigned int len = 0;
	err = HMAC_Final(ctx, digest, &len);
	if (err == 0) {
		perror("HMAC_Final");
	}

	HMAC_CTX_free(ctx);
}

int main(int argc, char *argv[]) {
	unsigned char key[] = "0123456789";
	unsigned char data[] = "hello, world.";
	unsigned char digest[HMAC_LENGTH + 1];

	HMAC_Hash(key, data, digest);
	// HMAC_Digest(key, data, digest);

	for (int i = 0; i < HMAC_LENGTH; i += 1) {
		fprintf(stderr, "%02X", (unsigned char)digest[i]);
	}
	fprintf(stderr, "\n");

	return 0;
}
