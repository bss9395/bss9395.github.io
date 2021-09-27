/* VLA.c
Author: BSS9395
Update: 2021-09-27T16:41:00+08@China-Guangdong-Shenzhen+08
Design: C99 Variable Length Array
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _VLA {
    int _len;
    char _data[];  // char _data[0];
} VLA;

int main(int argc, char *argv[]) {
    char *data = (char *)"123456789";
    VLA *vla = (VLA *)malloc(sizeof(VLA) + strlen(data) + 1);
    memcpy(vla->_data, data, strlen(data) + 1);

    fprintf(stdout, "sizeof(VLA) = %i""\n", sizeof(VLA));
    fprintf(stdout, "vla->_data = %s""\n", vla->_data);
    free(vla);
    return 0;
}
