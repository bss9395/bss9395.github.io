/* Main.c
Author: BSS9395
Update: 2020-05-20T15:21:00+08@China-Guangdong-Zhanjiang+08
Design: Container
*/

#define List_c
#include "List.c"

List *Another();


int main(int argc, char *argv[]) {

	List *list = CreateList();
	Node *node1 = NewNode("node1_in_main");
	list->Attach(node1, 0);
	list->Traverse();


	List *another = Another();
	Node *node3 = NewNode("node3_in_Another");
	another->Attach(node3, 1);
	list->Traverse();

	return 0;
}

