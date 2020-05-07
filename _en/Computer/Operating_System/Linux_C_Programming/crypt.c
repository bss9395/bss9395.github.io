#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <crypt.h>

#if 0
#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <unistd.h>
char *crypt(const char *key, const char *salt);

#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <crypt.h>
char *crypt_r(const char *key, const char *salt, struct crypt_data *data);

Link with -lcrypt.

#endif

int main(int argc, char *argv[]) {
	char *encrypt = crypt("abc", "$6$hiuGK4p0aMTSxM32$");
    printf("encrypt = %s\n", encrypt);

    return 0;
}

/* output:
$6$hiuGK4p0aMTSxM32$.8IEU1ztER5KG.vIfWfUvluDekS6xWSw7ej12hivVchvmIAbjHPl6HaWVfrJCFCcn.veWhU10tsmjF/PapWlJ0
*/
