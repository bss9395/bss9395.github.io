/* Mininum_Step.c
Author: BSS9395
Update: 2021-08-29T18:07:00+08@China-Guangdong-Zhanjiang+08
Design: Mininum Step for Distance
Original: https://blog.csdn.net/qq_43325061/article/details/119117946
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Type {
    int _path;
    char _dire[64];
} Type;
typedef struct _Queue {
    Type _queue[1024];
    int _fore;
    int _back;
} Queue;

/* Breadth First Search
*/
int Minimum_Step(int dist) {
    Queue queue = { queue._fore = 0, queue._back = queue._fore };
    int step = 0;
    Type base = { ._path = 0 ,._dire[0] = '@' ,._dire[1] = '\0' };
    Type path = base;
    if (dist == 0) {
        fprintf(stdout, "%d, %s""\n", path._path, path._dire);
        return step;
    }

    queue._queue[queue._back] = base;
    queue._back += 1;
    while (queue._fore < queue._back) {
        step += 1;
        for (int size = queue._back - queue._fore; 0 < size; size -= 1) {
            base = queue._queue[queue._fore];
            queue._fore += 1;
            for (int dire = -1; dire <= +1; dire += 2) {
                path = base;
                path._path += dire * step;
                path._dire[step] = (dire < 0) ? '-' : '+', path._dire[step + 1] = '\0';
                if (path._path == dist) {
                    goto Break;
                }
                queue._queue[queue._back] = path;
                queue._back += 1;
            }
        }
    }
Break:
    fprintf(stdout, "%d, %s""\n", path._path, path._dire);
    return step;
}

/*
7 == 0 - 1 + 2 - 3 + 4 + 5
25 + 0 - 1 + 2 - 3 + 4 + 5 == 32
*/
int main(int argc, char *argv[]) {
    int origin = 25;
    int destin = 32;
    // int step = Min_Step(0);
    int step = Minimum_Step(destin - origin);
    fprintf(stdout, "%d""\n", step);

    return 0;
}
