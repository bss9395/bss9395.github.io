/* Check_Loop.c
Author: BSS9395
Update: 2020-11-04T05:39:00+08@China-Guangdong-Zhanjiang+08
Design: Data Traversal
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *_next;
	double _value;
} Node;

Node *Make_Node(double value) {
	Node *node = (Node *)calloc(1, sizeof(Node));
	node->_next = NULL;
	node->_value = value;
	return node;
}

Node *Make_List(int numb, int into) {
	Node *list = Make_Node(-9395);
	Node *head = list;
	Node *loop = NULL;
	for (int i = 0; i < numb; i += 1) {
		if (i == into) {
			loop = head;
			// fprintf(stdout, "%f""\n", head->_value);
		}
		head->_next = Make_Node(i);
		head = head->_next;
	}
	head->_next = loop;
	return list;
}

bool Check_Loop(Node *list) {
	Node *slow = list;
	Node *fast = slow->_next;
	while (fast != NULL && slow != fast) {
		slow = slow->_next;
		fast = fast->_next->_next;
	}

	return (slow == fast);
}


void Test_Check_Loop() {
	Node *list = Make_List(7, 4);
	bool loop = Check_Loop(list);
	fprintf(stdout, "%s""\n", loop ? "true" : "false");
}


int main(int argc, char *argv[]) {
	Test_Check_Loop();

	return 0;
}
