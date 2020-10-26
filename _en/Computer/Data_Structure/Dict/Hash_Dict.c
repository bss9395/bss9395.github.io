/* Hash_Dict.c
Author: BSS9395
Update: 2020-10-26T12:34:00+08@China-Guangdong-Zhanjiang+08
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
	int _refs;
	union {
		int _width;
		struct Entry *_entry;
	};
} Piece;

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
	unsigned hash = 9495;
	for (int i = 0; i < numb; i += 1) {
		hash = (hash << 7) | (hash >> 25);
		hash ^= data[i];
	}
	hash += numb;
	return (unsigned)hash;
}

Entry *Create_Entry(unsigned hash, char *key, char *value) {
	Entry *entry = (Entry *)calloc(1, sizeof(Entry));
	entry->_link = NULL;
	entry->_hash = hash;
	entry->_key = New_Data(NULL, key, Length(key) + 1);
	entry->_value = New_Data(NULL, value, Length(value) + 1);
	return entry;
}

Piece Create_Block(int width) {
	Piece block = *((Piece *)Zero_Data(sizeof(Piece)));
	block._cross = (Piece *)calloc(width + 1, sizeof(Piece));
	block._width = width;
	block._cross[width]._refs = -9395;
	return block;
}

int Destroy_Entry(Entry *entry) {
	int ret = 0;
	free(entry->_key);
	free(entry->_value);
	free(entry);
	ret += 1;
	return ret;
}

int Destroy_Block(Piece *block) {
	int ret = 0;
	free(block->_cross);
	ret += 1;
	return ret;
}

int Destroy_Dict(Piece *dict) {
	if (dict->_cross == NULL) {
		fprintf(stdout, "dict doesn't exist! ");
		exit(EXIT_FAILURE);
	}

	int ret = 0;
	for (int i = 0; i < dict->_width; i += 1) {
		if (dict->_cross[i]._cross != NULL) {
			if (dict->_cross[i]._refs >= 1) {
				ret += Destroy_Dict(&(dict->_cross[i]));
			}
			Destroy_Block(&(dict->_cross[i]));
		}
		else if (dict->_cross[i]._entry != NULL) {
			Entry *list = dict->_cross[i]._entry;
			Entry *erase = NULL;
			do {
				erase = list;
				list = list->_link;
				Destroy_Entry(erase);
				ret += 1;
			} while (list != NULL);
		}
	}
	Destroy_Block(dict);
	(*dict) = *(Piece *)Zero_Data(sizeof(Piece));
	return ret;
}

int Destroy_Dict_By_Stack(Piece *dict) {
	static int top = 0;
	static int size = 8;
	static Piece **stack = NULL;
	if (stack == NULL) {
		stack = (Piece **)calloc(size, sizeof(Piece *));
	}
	top = 0;

	if (dict->_cross == NULL) {
		fprintf(stdout, "dict doesn't exist! ");
		exit(EXIT_FAILURE);
	}

	int ret = 0;
	Piece *head = &(dict->_cross[0]);
	while (true) {
		if (head->_refs != -9395) {
			if (head->_cross != NULL) {
				if (head->_refs >= 1) {
					if (size <= top) {
						size *= 2;
						stack = (Piece **)realloc(stack, size * sizeof(Piece *));
					}
					stack[top] = head, top += 1;
					head = &(dict->_cross[0]);
					continue;
				}
				Destroy_Block(head);
			}
			else if (head->_entry != NULL) {
				Entry *list = head->_entry;
				Entry *erase = NULL;
				do {
					erase = list;
					list = list->_link;
					Destroy_Entry(erase);
					ret += 1;
				} while (list != NULL);
			}
			head += 1;
		}
		else if (1 <= top) {
			head = (top -= 1, stack[top]);
			Destroy_Block(head);
			head += 1;
		}
		else {
			break;
		}
	}
	Destroy_Block(dict);
	(*dict) = *(Piece *)Zero_Data(sizeof(Piece));
	return ret;
}

Entry *Search_Entry(Piece *dict, char *key) {
	if (dict->_cross == NULL) {
		fprintf(stdout, "dict doesn't exist! ");
		exit(EXIT_FAILURE);
	}

	Entry *entry = NULL;
	unsigned hash = Hash(key, Length(key));

	Piece *block = NULL;
	Piece *head = dict;
	while (true) {
		block = head;
		head = &(head->_cross[hash % head->_width]);

		if (head->_cross == NULL) {
			if (head->_entry != NULL && head->_entry->_hash == hash) {
				for (Entry *list = head->_entry; list != NULL; list = list->_link) {
					if (strcmp(list->_key, key) == 0) {
						entry = list;
						break;
					}
				}
			}
			break;
		}
		else if (head->_refs <= 0) {
			Destroy_Block(head);
			(*head) = *(Piece *)Zero_Data(sizeof(Piece));
			block->_refs -= 1;
			break;
		}
	}

	return entry;
}

/*
	  hash_x % Width = hash_y % Width
hash_x % (Width + 1) = hash_y % (Width + 1)

hash_x = Q_x ¡Á Width + R
hash_y = Q_y ¡Á Width + R
hash_x - hash_y = Q0 ¡Á Width
hash_x - hash_y = Q1 ¡Á (Width + 1)

hash_x - hash_y = Q ¡Á Width ¡Á (Width + 1)
*/
Entry *Insert_Entry(Piece *dict, char *key, char *value, bool modify) {
	if (dict->_cross == NULL) {
		fprintf(stdout, "dict doesn't exist! ");
		exit(EXIT_FAILURE);
	}

	Entry *entry = NULL;
	unsigned hash = Hash(key, Length(key));

	Piece *block = NULL;
	Piece *head = dict;
	while (true) {
		block = head;
		head = &(head->_cross[hash % head->_width]);

		if (head->_cross == NULL) {
			if (head->_entry == NULL) {
				head->_entry = Create_Entry(hash, key, value);
				head->_refs = 1;
				block->_refs += 1;
				entry = head->_entry;
			}
			else if (head->_entry->_hash == hash) {
				Entry **list = &(head->_entry);
				for (; (*list) != NULL; list = &((*list)->_link)) {
					if (strcmp((*list)->_key, key) == 0) {
						if (modify) {
							(*list)->_value = New_Data((*list)->_value, value, Length(value) + 1);
						}
						break;
					}
				}
				if ((*list) == NULL) {
					(*list) = Create_Entry(hash, key, value);
					head->_refs += 1;
				}
				entry = (*list);
			}
			else {
				Piece piece = (*head);
				int width = block->_width + 1;
				int index = head->_entry->_hash % width;
				(*head) = Create_Block(width);
				head->_cross[index] = piece;
				head->_refs = 1;
				continue;
			}
			break;
		}
		else if (head->_refs <= 0) {
			Destroy_Block(head);
			(*head) = *(Piece *)Zero_Data(sizeof(Piece));
			head->_entry = Create_Entry(hash, key, value);
			head->_refs = 1;
			break;
		}
	}

	return entry;
}

Entry *Remove_Entry(Piece *dict, char *key, bool erase) {
	if (dict->_cross == NULL) {
		fprintf(stdout, "dict doesn't exist! ");
		exit(EXIT_FAILURE);
	}

	Entry *entry = NULL;
	unsigned hash = Hash(key, Length(key));

	Piece *block = NULL;
	Piece *head = dict;
	while (true) {
		block = head;
		head = &(head->_cross[hash % head->_width]);

		if (head->_cross == NULL) {
			if (head->_entry != NULL && head->_entry->_hash == hash) {
				for (Entry **list = &(head->_entry); (*list) != NULL; list = &((*list)->_link)) {
					if (strcmp((*list)->_key, key) == 0) {
						entry = (*list);
						if (erase) {
							(*list) = (*list)->_link;
							Destroy_Entry(entry);
							entry = NULL;
							head->_refs -= 1;
							if (head->_refs <= 0) {
								block->_refs -= 1;
							}
						}
						break;
					}
				}
			}
			break;
		}
		else if (head->_refs <= 0) {
			Destroy_Block(head);
			(*head) = *(Piece *)Zero_Data(sizeof(Piece));
			block->_refs -= 1;
			break;
		}
	}

	return entry;
}

void Print_Dict(Piece *dict) {
	if (dict->_cross == NULL) {
		fprintf(stdout, "dict doesn't exist! ");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < dict->_width; i += 1) {
		if (dict->_cross[i]._cross != NULL) {
			if (dict->_cross[i]._refs >= 1) {
				fprintf(stdout, "(");
				Print_Dict(&(dict->_cross[i]));
				fprintf(stdout, "); ");
			}
		}
		else if (dict->_cross[i]._entry != NULL) {
			for (Entry *list = dict->_cross[i]._entry; list != NULL; list = list->_link) {
				fprintf(stdout, "(%lu: %s: %s), ", list->_hash, list->_key, list->_value);
			}
		}
	}
	return;
}

void Print_Dict_By_Stack(Piece *dict) {
	static int top = 0;
	static int size = 8;
	static Piece **stack = NULL;
	if (stack == NULL) {
		stack = (Piece **)calloc(size, sizeof(Piece *));
	}
	top = 0;

	if (dict->_cross == NULL) {
		fprintf(stdout, "dict doesn't exist! ");
		exit(EXIT_FAILURE);
	}

	Piece *head = &(dict->_cross[0]);
	while (true) {
		if (head->_refs != -9395) {
			if (head->_cross != NULL) {
				if (head->_refs >= 1) {
					if (size <= top) {
						size *= 2;
						stack = (Piece **)realloc(stack, size * sizeof(Piece *));
					}
					stack[top] = head, top += 1;
					head = &(dict->_cross[0]);
					fprintf(stdout, "(");
					continue;
				}
			}
			else if (head->_entry != NULL) {
				for (Entry *list = head->_entry; list != NULL; list = list->_link) {
					fprintf(stdout, "(%lu: %s: %s), ", list->_hash, list->_key, list->_value);
				}
			}
			head += 1;
		}
		else if (1 <= top) {
			head = (top -= 1, stack[top]);
			head += 1;
			fprintf(stdout, "); ");
		}
		else {
			break;
		}
	}

	return;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Dict() {
	Piece dict = Create_Block(8);
	Insert_Entry(&dict, "key", "value", true);

	Entry *entry = Search_Entry(&dict, "key");
	if (entry != NULL) {
		fprintf(stdout, "(%lu, %s, %s)\n", entry->_hash, entry->_key, entry->_value);
	}

	Remove_Entry(&dict, "key", true);

	entry = Search_Entry(&dict, "key");
	if (entry != NULL) {
		fprintf(stdout, "(%lu, %s, %s)\n", entry->_hash, entry->_key, entry->_value);
	}

	Destroy_Dict(&dict);
	return;
}

void Test_Print_Dict() {
	Piece dict = Create_Block(8);
	Insert_Entry(&dict, "0", "value", true);

	// Print_Dict(&dict);
	Print_Dict_By_Stack(&dict);
	return;
}

int main(int argc, char *argv[]) {
	Test_Dict();

	Test_Print_Dict();

	return 0;
}
