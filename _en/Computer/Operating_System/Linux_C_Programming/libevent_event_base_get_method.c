#include <event.h>

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// gcc -o Main.out Main.c -levent
int main(int argc, char *argv[]) {
	struct event_base *base = event_base_new();
	const char **methods = event_get_supported_methods();

    printf("supported methods: \n");
	for(int i = 0; methods[i] != NULL; ++i) {
		printf("%s\n", methods[i]);
	}

	const char *method = event_base_get_method(base);
	printf("current selected method: \n%s\n", method);

	//free(method);
    free(methods);
	event_base_free(base);
	return 0;
}
