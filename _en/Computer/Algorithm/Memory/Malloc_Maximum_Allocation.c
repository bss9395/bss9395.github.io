/* Malloc_Maximum_Allocation.c
Author: BSS9395
Update: 2022-12-09T17:06:00+08@China-Shanghai+08
Design: Malloc Maximum Allocation
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	size_t block_size[] = { 1024 * 1024, 1024, 1 };
	size_t maximum = 0;
	for (int i = 0; i < 3; i += 1) {
		for (int count = 1;; count += 1) {
			void* block = malloc(maximum + block_size[i] * count);
			if (block != NULL) {
				maximum = maximum + block_size[i] * count;
				free(block);
			}
			else {
				break;
			}
		}
	}
	printf("maximum malloc size = %lld bytes\n", maximum);  // maximum malloc size = 10202665984 bytes
	
	return 0;
}
