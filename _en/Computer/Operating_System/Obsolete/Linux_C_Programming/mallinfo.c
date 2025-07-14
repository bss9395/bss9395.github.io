#if 0
#include <malloc.h>
struct mallinfo mallinfo(void);
#endif

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void func() {
    printf("func\n");
    void *p=malloc(sizeof(int));
    //free(p);
}

void displayMallInfo() {
    struct mallinfo info  = mallinfo();
    printf("===========================\n");
    printf("arena    = %d\n", info.arena   );  /* Non-mmapped space allocated (bytes) */
    printf("ordblks  = %d\n", info.ordblks );  /* Number of free chunks */
    printf("smblks   = %d\n", info.smblks  );  /* Number of free fastbin blocks */
    printf("hblks    = %d\n", info.hblks   );  /* Number of mmapped regions */
    printf("hblkhd   = %d\n", info.hblkhd  );  /* Space allocated in mmapped regions (bytes) */
    printf("usmblks  = %d\n", info.usmblks );  /* Maximum total allocated space (bytes) */
    printf("fsmblks  = %d\n", info.fsmblks );  /* Space in freed fastbin blocks (bytes) */
    printf("uordblks = %d\n", info.uordblks);  /* Total allocated space (bytes) */
    printf("fordblks = %d\n", info.fordblks);  /* Total free space (bytes) */
    printf("keepcost = %d\n", info.keepcost);  /* Top-most, releasable space (bytes) */
    printf("===========================\n");
}

int main(int argc, char *argv[]) {
    displayMallInfo();
    func();
    displayMallInfo();

    return 0;
}
