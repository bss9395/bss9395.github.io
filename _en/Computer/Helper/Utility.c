/* Utility.c
Author: BSS9395
Update: 2020-10-25T16:28:00+08@China-Guangdong-Zhanjiang+08
Design: String Operation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap_Int(int *x, int *y) {
	(*x) = (*x) + (*y);
	(*y) = (*x) - (*y);
	(*x) = (*x) - (*y);
	return;
}

void Swap_XOR(int *x, int *y) {
	(*x) = (*x) ^ (*y);
	(*y) = (*x) ^ (*y);
	(*x) = (*x) ^ (*y);
	return;
}

int Length(char *data) {
	int len = -1;
	if (data != NULL) {
		while (len += 1, data[len] != '\0');
	}
	return len;
}

char *Zero_Data(int size) {
	static char *zero = NULL;
	static int full = 0;
	if (full < size) {
		free(zero);
		zero = (char *)calloc(size, sizeof(char));
		full = size;
	}
	return zero;
}

char *New_Data(char *copy, char *data, int size) {
	if (size < 1) {
		return NULL;
	}

	copy = (copy != NULL) ?
		(char *)realloc(copy, size * sizeof(char)) :
		(char *)calloc(size, sizeof(char));
	for (int i = 0; i < size; copy[i] = data[i], i += 1);
	return copy;
}

unsigned Hash(char *data, int numb) {
	unsigned hash = 9395;
	for (int i = 0; i < numb; i += 1) {
		hash = (hash << 7) | (hash >> 25);
		hash ^= data[i];
	}
	hash += numb;
	return (unsigned)hash;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Swap() {
	int a = 3;
	int b = 4;

	Swap_Int(&a, &b);
	fprintf(stdout, "%ld, %ld\n", a, b);

	Swap_XOR(&a, &b);
	fprintf(stdout, "%ld, %ld\n", a, b);
}

void Test_Length() {
	int len = Length(NULL);
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
	for (int i = 0; i < 62; i += 1) {
		int hash = Hash(&strs[i], 1);
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
