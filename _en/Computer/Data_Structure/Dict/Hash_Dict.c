/* Hash_Dict.c
Author: BSS9395
Update: 2020-10-25T23:46:00+08@China-Guangdong-Zhanjiang+08
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

Piece Create_Block(int width, Entry *entry) {
	Piece block = *((Piece *)Zero_Data(sizeof(Piece)));
	block._cross = (Piece *)calloc(width + 1, sizeof(Piece));
	block._width = width;
	block._cross[width]._refs = -9395;

	if (entry != NULL) {
		int index = entry->_hash % block._width;
		block._cross[index]._entry = entry;
	}
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
	int ret = 0;
	for (int i = 0; i < dict->_width; i += 1) {
		if (dict->_cross[i]._cross != NULL) {
			ret += Destroy_Dict(&(dict->_cross[i]));
			Destroy_Block(&(dict->_cross[i]));
		}
		else if (dict->_cross[i]._refs >= 1) {
			Entry *list = dict->_cross[i]._entry;
			Entry *relax = NULL;
			while (list != NULL) {
				relax = list;
				list = list->_link;
				Destroy_Entry(relax);
				ret += 1;
			}
		}
	}
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

	int ret = 0;
	Piece *head = &(dict->_cross[0]);
	while (true) {
		if (head->_refs != -9395) {
			if (head->_cross != NULL) {
				if (size <= top) {
					size *= 2;
					stack = (Piece **)realloc(stack, size * sizeof(Piece *));
				}
				stack[top] = head, top += 1;
				head = &(dict->_cross[0]);
				continue;
			}
			else if (head->_refs >= 1) {
				Entry *list = head->_entry;
				Entry *relax = NULL;
				while (list != NULL) {
					relax = list;
					list = list->_link;
					Destroy_Entry(relax);
					ret += 1;
				}
			}
			head += 1;
		}
		else if (0 <= top) {
			head = (top -= 1, stack[top]);
			Destroy_Block(head);
			head += 1;
		}
		else {
			break;
		}
	}
	Destroy_Block(dict);
	return ret;
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
Entry **Modify_Entry(Piece *dict, char *key, char *value, bool modify) {
	Entry **entry = NULL;
	unsigned hash = Hash(key, Length(key));

	Piece *block = NULL;
	while (true) {
		block = dict;
		int index = hash % dict->_width;
		dict = &(dict->_cross[index]);

		if (dict->_cross == NULL) {
			if (dict->_entry == NULL) {
				entry = &(dict->_entry);
				if (modify) {
					(*entry) = Create_Entry(hash, key, value);
					dict->_refs = 1;
					block->_refs += 1;
				}
			}
			else if (dict->_entry->_hash == hash) {
				for (entry = &(dict->_entry); (*entry) != NULL; entry = &((*entry)->_link)) {
					if (strcmp((*entry)->_key, key) == 0) {
						if (modify) {
							(*entry)->_value = New_Data((*entry)->_value, value, Length(value) + 1);
						}
						break;
					}
				}
				if ((*entry) == NULL) {
					if (modify) {
						(*entry) = Create_Entry(hash, key, value);
						dict->_refs += 1;
					}
				}
			}
			else if (modify) {
				(*dict) = Create_Block(dict->_width + 1, dict->_entry);
				continue;
			}
			break;
		}
	}
	return entry;
}

Entry *Remove_Entry(Piece *dict, char *key, bool erase) {
	static int top = 0;
	static int size = 8;
	static Piece **stack = NULL;
	if (stack == NULL) {
		stack = (Piece **)calloc(size, sizeof(Piece *));
	}
	top = 0;

	Entry *relax = NULL;
	unsigned hash = Hash(key, Length(key));

	while (true) {
		if (size <= top) {
			size *= 2;
			stack = (Piece **)realloc(stack, size * sizeof(Piece *));
		}
		stack[top] = dict, top += 1;
		int index = hash % dict->_width;
		dict = &(dict->_cross[index]);

		if (dict->_cross == NULL) {
			if (dict->_entry != NULL && dict->_entry->_hash == hash) {
				for (Entry **entry = &(dict->_entry); (*entry) != NULL; entry = &((*entry)->_link)) {
					if (strcmp((*entry)->_key, key) == 0) {
						relax = (*entry);
						if (erase) {
							(*entry) = (*entry)->_link;
							Destroy_Entry(relax);
							relax = NULL;
							dict->_refs -= 1;
							if (dict->_refs <= 0) {
								stack[top - 1]->_refs -= 1;
							}
						}
						break;
					}
				}
			}
			break;
		}
	}

	Piece entry = (*dict);
	while (top -= 1, 1 <= top && stack[top]->_refs <= 1) {
		Destroy_Block(stack[top]);
		*(stack[top]) = entry;
	}
	return relax;
}

void Print_Dict(Piece *dict) {
	for (int i = 0; i < dict->_width; i += 1) {
		if (dict->_cross[i]._cross != NULL) {
			Print_Dict(&(dict->_cross[i]));
		}
		else if (dict->_cross[i]._refs >= 1) {
			for (Entry *list = dict->_cross[i]._entry; list != NULL; list = list->_link) {
				fprintf(stdout, "(%lu, %s, %s) ", list->_hash, list->_key, list->_value);
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

	Piece *head = &(dict->_cross[0]);
	while (true) {
		if (head->_refs != -9395) {
			if (head->_cross != NULL) {
				if (size < top) {
					size *= 2;
					stack = (Piece **)realloc(stack, size * sizeof(Piece *));
				}
				stack[top] = head, top += 1;
				head = &(head->_cross[0]);
				continue;
			}
			else if (head->_refs >= 1) {
				for (Entry *list = head->_entry; list != NULL; list = list->_link) {
					fprintf(stdout, "(%lu, %s, %s) ", list->_hash, list->_key, list->_value);
				}
			}
			head += 1;
		}
		else if (0 <= top) {
			head = (top -= 1, stack[top]);
			head += 1;
		}
		else {
			break;
		}
	}

	return;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Dict() {
	Piece dict = Create_Block(8, NULL);
	Modify_Entry(&dict, "key", "value", true);

	Remove_Entry(&dict, "key", true);

	Entry **entry = Modify_Entry(&dict, "key", NULL, false);

	if (entry != NULL && (*entry) != NULL) {
		fprintf(stdout, "%s\n", (*entry)->_value);
	}

	Destroy_Dict(&dict);
	return;
}

void Test_Print_Dict() {
	Piece dict = Create_Block(8, NULL);
	Modify_Entry(&dict, "0", "value", true);

	// Print_Dict(&dict);
	Print_Dict_By_Stack(&dict);
	return;
}

int main(int argc, char *argv[]) {
	Test_Dict();

	//Test_Print_Dict();

	return 0;
}
