/* DoublyList.c
Author: BSS9395
Update: 2020-05-19T18:58:00+08@China-Guangdong-Zhanjiang+08
Design: Doubly Linked List
*/

/* Right Handed Rotation
[The Count Starts at 0]
 0   1   2   3   4   5   6
-6	-5	-4	-3	-2  -1   0
 +---+---+---+---+---+---+
 | P | y | t | h | o | n |
 +---+---+---+---+---+---+
 0   1   2   3   4   5   6
-6  -5  -4  -3  -2  -1   0

[Another Acceptable Design Pattern]
 0   1   2   3   4   5   6
-6	-5	-4	-3	-2  -1   0
 +---+---+---+---+---+---+
 | D | o | u | b | l | y |
 +---+---+---+---+---+---+
   1   2   3   4   5   6
  -6  -5  -4  -3  -2  -1
*/

#define _CRT_SECURE_NO_WARNINGS
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long iptr;
typedef char *Data;
typedef struct _Node Node;
typedef struct _DoublyList DoublyList;
typedef struct _Function Function;

Function *MakeList(DoublyList *list);
void DestructList(DoublyList *list);

////////////////////////////////////////

struct _Node {
	Data _data;
	Node *_prev;
	Node *_next;
};

struct _DoublyList {
	Node _head;
	iptr _size;
};

typedef iptr(*Visit)(DoublyList *list, Node *node);
struct _Function {
	iptr(*Attach)(DoublyList *list, Node *node, iptr index);
	iptr(*Detach)(DoublyList *list, Node **node, iptr index);
	iptr(*Print)(DoublyList *list, Node *node);
	iptr(*Traverse)(DoublyList *list, Visit visit, Node *node);
};


typedef const char *Level;
static const struct {
	Level _Info;
	Level _ToDo;
	Level _Warn;
	Level _Error;
	Level _Fatal;
} ELevel = { "Info", "ToDo", "Warn", "Error", "Fatal" };

static const char **Extract(const char *lite, const char deli[], iptr *lines) {
	// fprintf(stderr, "%s""\n", __FUNCTION__);

	static const char *split[32];
	*lines = 0;

	iptr i = 0;
	while (lite[0] != '\0') {
		split[*lines] = &lite[0];
		*lines += 1;
		do {
			lite += 1;
			i = 0;
			while (deli[i] != '\0' && lite[0] != deli[i]) {
				i += 1;
			}
			if (lite[0] == deli[i]) {
				break;
			}
		} while (lite[0] != '\0');
	}
	split[*lines] = NULL;

	return split;
}

static bool Check(const bool failed, const char *file, const iptr line, const char *function, const Level level, const char *report) {
	// fprintf(stderr, "%s""\n", __FUNCTION__);

	if (failed) {
		iptr lines = 0;
		fprintf(stderr, "[%s; %d; %s] %s; %s; "
			, (Extract(file, "/\\.", &lines)[lines - 2] + 1), line, (Extract(function, ":", &lines)[lines - 1]), level, report);
		if (errno != 0 && level == ELevel._Info) {
			fprintf(stderr, "%s; ", strerror(errno));
			exit((iptr)level);
		}
		fprintf(stderr, "\n");
	}

	errno = 0;
	return failed;
}

static iptr Attach(DoublyList *list, Node *node, iptr index) {
	// fprintf(stderr, "%s""\n", __FUNCTION__);

	iptr ret = 0;

	Node *edge = &list->_head;
	index = index % (list->_size + 1);
	while (index > 0) {
		edge = edge->_next;
		index -= 1;
	}
	while (index < 0) {
		edge = edge->_prev;
		index += 1;
	}

	node->_next = edge->_next;
	edge->_next->_prev = node;
	edge->_next = node;
	node->_prev = edge;
	list->_size += 1;

	ret += 1;
	return ret;
}

static iptr Detach(DoublyList *list, Node **node, iptr index) {
	// fprintf(stderr, "%s""\n", __FUNCTION__);

	iptr ret = 0;

	if (false == Check(list->_size <= 0, __FILE__, __LINE__, __FUNCTION__, ELevel._Info, "(list->_size <= 0)")) {
		Node *knot = &list->_head;
		index = (index >= 0) ? (index % list->_size) : (index % (list->_size + 1) - 1);
		while (index > 0) {
			knot = knot->_next;
			index -= 1;
		}
		while (index < 0) {
			knot = knot->_prev;
			index += 1;
		}

		*node = knot;
		knot->_next = knot->_next->_next;
		knot->_next->_prev = knot;

		list->_size -= 1;
		ret += 1;
	}

	return ret;
}

static iptr Print(DoublyList *list, Node *node) {
	// fprintf(stderr, "%s""\n", __FUNCTION__);
	iptr ret = 0;

	fprintf(stdout, " => %s""\n", node->_data);

	ret += 1;
	return ret;
}

static iptr Traverse(DoublyList *list, Visit visit, Node *node) {
	// fprintf(stderr, "%s""\n", __FUNCTION__);
	if (node == NULL) {
		node = list->_head._next;
	}

	iptr ret = 0;

	while (node != &list->_head) {
		ret += visit(list, node);
		node = node->_next;
	}
	fprintf(stdout, "\n");

	Check(list->_size != ret, __FILE__, __LINE__, __FUNCTION__, ELevel._Fatal, "(list->_size != ret)");
	return ret;
}

Node *NewNode(Data data) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->_prev = NULL;
	node->_next = NULL;
	node->_data = data;
	return node;
}

void DeleteNode(Node *node) {
	free(node);
	return;
}

Function *MakeList(DoublyList *list) {
	// fprintf(stderr, "%s""\n", __FUNCTION__);

	static DoublyList _list = {
		._head._data = "Head",
		._size = 0
	};

	_list._head._prev = &_list._head;
	_list._head._next = &_list._head;
	_list._size = 0;
	*list = _list;

	static Function function = {
		.Attach = Attach,
		.Detach = Detach,
		.Print = Print,
		.Traverse = Traverse
	};

	return &function;
}

void DestructList(DoublyList *list) {
	// fprintf(stderr, "%s""\n", __FUNCTION__);

	iptr size = 0;
	Node *curr = list->_head._next;
	Node *node = NULL;
	while (curr != &list->_head) {
		node = curr;
		curr = curr->_next;

		DeleteNode(node);
		size += 1;
	}

	Check(list->_size != size, __FILE__, __LINE__, __FUNCTION__, ELevel._Fatal, "(list->_size != size)");
	return;
}

////////////////////////////////////////

#ifndef Main

int main(int argc, char *argv[]) {
	DoublyList list;
	Function *function = MakeList(&list);

	Node *node0 = NewNode("node0");
	Node *node1 = NewNode("node1");
	Node *node2 = NewNode("node2");

	function->Attach(&list, node0, 0);
	function->Attach(&list, node1, -1);
	function->Attach(&list, node2, -1);

	function->Traverse(&list, function->Print, NULL);

	DestructList(&list);
	return 0;
}

#endif // Main
