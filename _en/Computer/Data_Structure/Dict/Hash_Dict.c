/* Hash_Dict.c
Author: BSS9395
Update: 2020-10-25T00:01:00+08@China-Guangdong-Zhanjiang+08
Design: Hash Dict
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry {
	struct Entry *_link;
	unsigned _hash;
	char *_key;
	char *_value;
} Entry;

typedef struct Piece {
	struct Piece *_cross;
	union {
		int _width;
		struct Entry *_entry;
	};
} Piece;


Piece Create_Block(int width, Entry *entry) {
	Piece block;
	block._cross = (Piece *)calloc(width, sizeof(Piece));
	block._width = width;

	if (entry != NULL) {
		int index = entry->_hash % block._width;
		block._cross[index]._entry = entry;
	}
	return block;
}

unsigned Hash(char *data, int numb) {
	unsigned hash = 9395;
	for (int i = 0; i < numb; i += 1) {
		hash = (hash << 8) | (hash >> 24);
		hash ^= data[i];
	}
	hash += numb;
	return (unsigned)hash;
}

Entry *Create_Entry(unsigned hash, char *key, char *value) {
	int size_key = strlen(key) + 1;
	int size_value = strlen(value) + 1;

	Entry *entry = (Entry *)calloc(1, sizeof(Entry));
	entry->_key = (char *)calloc(size_key, sizeof(char));
	entry->_value = (char *)calloc(size_value, sizeof(char));

	entry->_link = NULL;
	entry->_hash = hash;
	for (int i = 0; entry->_key[i] = key[i], i < size_key; i += 1);
	for (int i = 0; entry->_value[i] = value[i], i < size_value; i += 1);
	return entry;
}

int Detroy_Entry(Entry *entry) {
	int ret = 0;
	free(entry->_key);
	free(entry->_value);
	free(entry);
	ret += 1;
	return ret;
}

char *Copy_Data(char *copy, char *data, int size) {
	if (copy != NULL) {
		copy = (char *)realloc(copy, size * sizeof(char));
	}
	else {
		copy = (char *)calloc(size, sizeof(char));
	}
	for (int i = 0; copy[i] = data[i], i < size; i += 1);
	return copy;
}

/*
	  hash_x % Width = hash_y % Width
hash_x % (Width + 1) = hash_y % (Width + 1)

hash_x = Q_x ¡Á Width + R_x
hash_y = Q_y ¡Á Width + R_y
hash_x - hash_y = Q0 ¡Á Width
hash_x - hash_y = Q1 ¡Á (Width + 1)

hash_x - hash_y = Q ¡Á Width ¡Á (Width + 1)
*/
Entry **Insert_Entry(Piece *dict, char *key, char *value) {
	Entry **entry = NULL;
	unsigned hash = Hash(key, strlen(key));

	while (true) {
		int index = hash % dict->_width;
		dict = &dict->_cross[index];

		if (dict->_cross == NULL) {
			if (dict->_entry == NULL || dict->_entry->_hash == hash) {
				for (entry = &(dict->_entry); (*entry) != NULL; entry = &((*entry)->_link)) {
					if (strcmp((*entry)->_key, key) == 0) {
						if (value != NULL) {
							(*entry)->_value = Copy_Data((*entry)->_value, value, strlen(value) + 1);
						}
						break;
					}
				}
				if ((*entry) == NULL) {
					if (value != NULL) {
						(*entry) = Create_Entry(hash, key, value);
					}
				}
				break;
			}
			else if (value != NULL) {
				(*dict) = Create_Block(dict->_width + 1, dict->_entry);
			}
			else {
				break;
			}
		}
	}

	return entry;
}

Entry **Remove_Entry(Piece *dict, char *key, bool erase) {
	Entry **list = Insert_Entry(dict, key, NULL);
	Entry **entry = list;

	if (list != NULL && (*list) != NULL) {
		(*list) = (*list)->_link;

		if (erase) {
			Detroy_Entry(*entry);
			(*entry) = NULL;
		}
	}

	return entry;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Hash() {
	char strs[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 62; i += 1) {
		int hash = Hash(&strs[i], 1);
		fprintf(stdout, "%lu\n", hash);
	}
	return;
}

void Test_Dict() {
	Piece dict = Create_Block(8, NULL);
	Insert_Entry(&dict, "key", "value");

	Entry **entry = Insert_Entry(&dict, "key", NULL);
	fprintf(stdout, "%s\n", (*entry)->_value);

	return;
}

int main(int argc, char *argv[]) {
	// Test_Hash();
	Test_Dict();

	return 0;
}
