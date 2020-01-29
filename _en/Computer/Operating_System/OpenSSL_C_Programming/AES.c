/*AES.c
* gcc -lssl -lcrypto AES.c
*/

#if 0
int AES_set_encrypt_key(const unsigned char *userKey, const int bits, AES_KEY *key);
int AES_set_decrypt_key(const unsigned char *userKey, const int bits, AES_KEY *key);

void AES_encrypt(const unsigned char *in, unsigned char *out, const AES_KEY *key);
void AES_decrypt(const unsigned char *in, unsigned char *out, const AES_KEY *key);
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/aes.h>

unsigned char *AES_Encode(const unsigned char key[], const unsigned char data[], int length) {
	length = ((length - 1) / AES_BLOCK_SIZE + 1) * AES_BLOCK_SIZE;

	AES_KEY aes;
	AES_set_encrypt_key(key, 128, &aes);

	unsigned char initial[AES_BLOCK_SIZE];
	memcpy(initial, "0123456789abcdef", AES_BLOCK_SIZE);

	unsigned char *ret = (unsigned char *)malloc(length);
	AES_cbc_encrypt(data, ret, length, &aes, initial, AES_ENCRYPT);

	for (int i = 0; i < length; i += 1) {
		fprintf(stderr, "%02X", ret[i]);
	}
	fprintf(stderr, "\n");
	return ret;
}

unsigned char *AES_Decode(const unsigned char key[], const unsigned char data[], int length) {
	length = ((length - 1) / AES_BLOCK_SIZE + 1) * AES_BLOCK_SIZE;

	AES_KEY aes;
	AES_set_decrypt_key(key, 128, &aes);

	unsigned char initial[AES_BLOCK_SIZE];
	memcpy(initial, "0123456789abcdef", AES_BLOCK_SIZE);

	unsigned char *ret = (unsigned char *)malloc(length);
	AES_cbc_encrypt(data, ret, length, &aes, initial, AES_DECRYPT);

	fprintf(stderr, "%s\n", ret);
	return ret;
}

int main(int argc, char *argv[]) {
	unsigned char secKey[16];
	memcpy(secKey, "1234567890abcdef", 16);

	unsigned char data[] = "The EVP library provides a high-level interface to cryptographic functions.";
	unsigned char *encode = AES_Encode(secKey, data, strlen((char *)data));
	unsigned char *decode = AES_Decode(secKey, encode, strlen((char *)data));

	fprintf(stderr, "strlen(data) = %d, strlen(decode) = %d\n", strlen((char *)data), strlen((char *)decode));
	free(encode);
	free(decode);
	return 0;
}
