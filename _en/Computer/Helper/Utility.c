/* Utility.c
Author: BSS9395
Update: 2020-10-25T16:28:00+08@China-Guangdong-Zhanjiang+08
Design: String Operation
*/

#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int8_t    in08;
typedef int16_t   in16;
typedef int32_t   in32;
typedef int64_t   in64;
typedef intptr_t  iptr;
typedef uint8_t   ui08;
typedef uint16_t  ui16;
typedef uint32_t  ui32;
typedef uint64_t  ui64;
typedef uintptr_t uptr;

typedef const ui08 *Level;
struct {
	const Level _Info;
	const Level _ToDo;
	const Level _Warn;
	const Level _Error;
	const Level _Fatal;
} ELevel;

bool Check(bool failed, Level level, const ui08 *function, const ui08 *record, const ui08 *extra) {
	if (failed) {
		(extra == NULL) ? extra = (const ui08 *)"" : extra;
		fprintf(stderr, "[%s] %s: %s%s; ""\n", level, function, record, extra);
	}

	errno = 0;
	return failed;
}

void Swap(long *lhs, long *rhs) {
	long temp = (*lhs);
	(*lhs) = (*rhs);
	(*rhs) = temp;
	return;
}

void Swap_Arithmetic(long *lhs, long *rhs) {
	(*lhs) = (*lhs) + (*rhs);
	(*rhs) = (*lhs) - (*rhs);
	(*lhs) = (*lhs) - (*rhs);
	return;
}

void Swap_XOR(long *lhs, long *rhs) {
	(*lhs) = (*lhs) ^ (*rhs);
	(*rhs) = (*lhs) ^ (*rhs);
	(*lhs) = (*lhs) ^ (*rhs);
	return;
}

long Length(char *stri) {
	long len = -1;
	if (stri != NULL) {
		while (len += 1, stri[len] != '\0');
	}
	return len;
}

char *Zero_Data(long size) {
	static char *zero = NULL;
	static long full = 0;
	if (full < size) {
		free(zero);
		zero = (char *)calloc(size, sizeof(char));
		full = size;
	}
	return zero;
}

char *New_Data(char *copy, char *data, long size) {
	if (size < 1) {
		return NULL;
	}

	copy = (copy != NULL) ?
		(char *)realloc(copy, size * sizeof(char)) :
		(char *)calloc(size, sizeof(char));
	for (long i = 0; i < size; copy[i] = data[i], i += 1);
	return copy;
}

unsigned Hash(char *data, long numb) {
	unsigned hash = 9395;
	for (long i = 0; i < numb; i += 1) {
		hash = (hash << 7) | (hash >> 25);
		hash ^= data[i];
	}
	hash += numb;
	return (unsigned)hash;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Swap() {
	long a = 3;
	long b = 4;

	Swap_Int(&a, &b);
	fprintf(stdout, "%ld, %ld\n", a, b);

	Swap_XOR(&a, &b);
	fprintf(stdout, "%ld, %ld\n", a, b);
}

void Test_Length() {
	long len = Length(NULL);
	fprintf(stdout, "%ld\n", len);
}

typedef struct Data {
	long _key;
	long _value;
} Data;
void Test_Zero_Data() {
	Data data = *(Data *)Zero_Data(sizeof(Data));
}

void Test_New_Data() {
	char *copy = New_Data(NULL, NULL, 0);

	fprintf(stdout, "%s\n", copy);
	return;
}

void Test_Hash() {
	unsigned hash = Hash(NULL, 0);
	fprintf(stdout, "%ld\n", hash);

	char strs[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (long i = 0; i < 62; i += 1) {
		long hash = Hash(&strs[i], 1);
		fprintf(stdout, "%lu\n", hash);
	}
	return;
}

int main(int argc, char *argv[]) {
	// Test_Swap();
	// Test_Length();
	Test_New_Data();
	// Test_Hash();

	return 0;
}
