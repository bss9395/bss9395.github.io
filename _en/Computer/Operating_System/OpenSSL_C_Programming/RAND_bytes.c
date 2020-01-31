/*RAND_bytes.c
*/

#if 0
#include <openssl/rand.h>
int RAND_bytes(unsigned char *buf, int num);
int RAND_priv_bytes(unsigned char *buf, int num);

#include <openssl/err.h>
unsigned long ERR_get_error(void);
unsigned long ERR_peek_error(void);
unsigned long ERR_peek_last_error(void);
unsigned long ERR_get_error_line(const char **file, int *line);
unsigned long ERR_peek_error_line(const char **file, int *line);
unsigned long ERR_peek_last_error_line(const char **file, int *line);
unsigned long ERR_get_error_line_data(const char **file, int *line, const char **data, int *flags);
unsigned long ERR_peek_error_line_data(const char **file, int *line, const char **data, int *flags);
unsigned long ERR_peek_last_error_line_data(const char **file, int *line, const char **data, int *flags);
#endif

#include <openssl/rand.h>
#include <openssl/err.h>
#include <stdio.h>

void RandBytes() {
	unsigned char buf[128];
	int err = RAND_bytes(buf, sizeof(buf));
	if (err != 1) {
		unsigned long code = ERR_get_error();
		fprintf(stderr, "error code: %ul", code);
	}

	for (int i = 0; i < sizeof(buf); i += 1) {
		fprintf(stderr, "%0*X", 2 * sizeof(unsigned char), buf[i]);
	}
	fprintf(stderr, "\n\n");

	for (int i = 0; i < sizeof(buf) / sizeof(unsigned short); i += 1) {
		fprintf(stderr, "%0*X", 2 * sizeof(unsigned short), ((unsigned short*)buf)[i]);
	}
	fprintf(stderr, "\n");
}

int main(int argc, char *argv[]) {
	RandBytes();

	return 0;
}
