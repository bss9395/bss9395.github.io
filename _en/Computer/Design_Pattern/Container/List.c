/* List.c
Author: BSS9395
Update: 2020-05-20T15:21:00+08@China-Guangdong-Zhanjiang+08
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
typedef char *Data;

typedef struct _Node {
	Data _data;
	struct _Node *_next;
} Node;

typedef struct _List {
	iptr(*Attach)(Node *node, iptr index);
	iptr(*Detach)(Node **node, iptr index);
	void(*Traverse)();
} List;

static Node _head;
static iptr _size;
List *CreateList();
Node *NewNode(Data data);

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
	Node *curr = _head._next;
	while (curr != NULL) {
		fprintf(stderr, " => %s", curr->_data);
		curr = curr->_next;
	}
	fprintf(stderr, "\n");
}

List *CreateList() {
	static List list = {
		.Attach = Attach,
		.Detach = Detach,
		.Traverse = Traverse
	};

	_head._data = "Head";
	_head._next = NULL;

	return &list;
}

Node *NewNode(Data data) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	return node;
}

#endif // List_c
