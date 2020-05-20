/* List.c
Author: BSS9395
Update: 2020-05-20T16:34:00+08@China-Guangdong-Zhanjiang+08
Design: Container
*/

#ifndef List_h
#define List_h

#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long iptr;
typedef const char *Type;
static const struct {
	Type _Integer;
	Type _Double;
	Type _String;
} EType = { "Integer", "Double", "String" };

typedef struct _Node {
	void *_data;
	struct _Node *_next;
} Node;

typedef struct _List {
	iptr(*Attach)(Node *node, iptr index);
	iptr(*Detach)(Node **node, iptr index);
	void(*Traverse)();
} List;

static Node _head;
static iptr _size;
static Type _type;
static List *CreateList(Type type);
static Node *NewNode(void *data, iptr size);

#endif // List_h


#ifndef List_c
#define List_c

static iptr Attach(Node *node, iptr index) {
	iptr ret = 0;

	if (0 <= index && index < _size + 1) {
		Node *curr = &_head;
		while (index > 0) {
			curr = curr->_next;
			index -= 1;
		}
		node->_next = curr->_next;
		curr->_next = node;

		_size += 1;
		ret += 1;
	}

	return ret;
}

static iptr Detach(Node **node, iptr index) {
	iptr ret = 0;

	if (0 <= index && index < _size) {
		Node *curr = &_head;
		while (index > 0) {
			curr = curr->_next;
			index -= 1;
		}
		*node = curr->_next;
		curr->_next = curr->_next->_next;

		_size -= 1;
		ret += 1;
	}

	return ret;
}

static void Traverse() {
	fprintf(stderr, "[&_head = %p, _type = %s]", &_head, _type);

	const char *format = "";
	if (_type == EType._Integer) {
		format = " => %d ";

		Node *curr = _head._next;
		while (curr != NULL) {
			fprintf(stderr, format, *(int *)(curr->_data));
			curr = curr->_next;
		}
	}
	else if (_type == EType._Double) {
		format = " => %lf ";

		Node *curr = _head._next;
		while (curr != NULL) {
			fprintf(stderr, format, *(double *)(curr->_data));
			curr = curr->_next;
		}
	}
	else if (_type == EType._String) {
		format = " => %s ";

		Node *curr = _head._next;
		while (curr != NULL) {
			fprintf(stderr, format, (char *)(curr->_data));
			curr = curr->_next;
		}
	}

	fprintf(stderr, "\n");
}

static List *CreateList(Type type) {
	static List list = {
		.Attach = Attach,
		.Detach = Detach,
		.Traverse = Traverse
	};

	_head._data = "Head";
	_head._next = NULL;
	_type = type;

	return &list;
}

static Node *NewNode(void *data, iptr size) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->_data = (void *)malloc(size);
	memcpy(node->_data, data, size);
	node->_next = NULL;
	return node;
}

#endif // List_c
