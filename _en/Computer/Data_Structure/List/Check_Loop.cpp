/*Check_Loop.cpp
*/

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iomanip>
#include <iostream>
using std::boolalpha;
using std::cout;
using std::cerr;
using std::endl;

struct Node {
public:
	bool checkLoop() {
		bool ret = false;

		Node *slow = this;
		Node *fast = slow;
		while (slow != nullptr && fast != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				ret = true;
				break;
			}
		}

		return ret;
	}

public:
	double value;
	Node * next;
};


int main(int argc, char *argv[]) {
	Node node1;
	Node node2;
	Node node3;
	Node node4;
	Node node5;
	Node node6;
	Node node7;


	node1.value = 1;
	node2.value = 2;
	node3.value = 3;
	node4.value = 4;
	node5.value = 5;
	node6.value = 6;
	node7.value = 7;


	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;
	node6.next = &node7;
	node7.next = &node4;


	cerr << boolalpha << node1.checkLoop() << endl;
	return 0;
}
