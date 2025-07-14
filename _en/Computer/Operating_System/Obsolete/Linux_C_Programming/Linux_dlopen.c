/* Linux_dlopen.c
Author: BSS9395
Update: 2022-12-10T15:27:00+08@China-Shanghai+08
Design: Linux Standard Library: dlopen(), dlsym(), dlerror(), dlclose()
*/

/* Usage:
brilliant@Ubuntu64:~/×ÀÃæ/Workspace$ gcc -o test test.c -ldl
brilliant@Ubuntu64:~/×ÀÃæ/Workspace$ ./test /usr/lib/x86_64-linux-gnu/libm.so.6 1.000000
*/

#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char* argv[]) {
    void* handle = dlopen(argv[1], RTLD_NOW);
    if (handle == NULL) {
        fprintf(stderr, "Open library %s error: %s \n", argv[1], dlerror());
        return -1;
    }

    double (*func)(double) = NULL;
    func = dlsym(handle, "sin");
    char* error = NULL;
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "SYmbol sin not found: %s\n", error);
        goto Exit;
    }

    fprintf(stderr, "%f\n", func(3.1415926 / 2));

Exit:
    dlclose(handle);
}
