/* Main.c
Author: BSS9395
Update: 2020-05-20T16:34:00+08@China-Guangdong-Zhanjiang+08
Design: Container
*/

#include "List.c"

List *Another();


int main(int argc, char *argv[]) {

	List *list1 = CreateList(EType._String);
	char *str = "Str";
	Node *node1 = NewNode(str, 4);
	list1->Attach(node1, 0);
	list1->Traverse();
	DestructList(list1);


	List *list2 = CreateList(EType._Integer);
	int in = 2;
	Node *node2 = NewNode(&in, sizeof(int));
	list2->Attach(node2, 0);
	list2->Traverse();
	DestructList(list2);


	List *another = Another();
	double dou = 4.0;
	Node *node4 = NewNode(&dou, sizeof(double));
	another->Attach(node4, 1);
	another->Traverse();
	DestructList(another);

	return 0;
}

