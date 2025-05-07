/* Cpp_ReverseBetween.cpp
Author: BSS9395
Update: 2025-04-29T11:15:00+08@China-Guangdong-Zhanjiang+08
*/

#include <iostream>
#include <string>

struct Solution {
	struct ListNode {
		int _data = -1;
		ListNode *_next = nullptr;

		ListNode(int data) {
			_data = data;
		}
	};
	ListNode _head = ListNode(0);

	void _Create() {
		ListNode *a = new ListNode(0);
		ListNode *b = new ListNode(1);
		ListNode *c = new ListNode(2);
		ListNode *d = new ListNode(3);
		ListNode *e = new ListNode(4);
		_head._next = a;
		a->_next = b;
		b->_next = c;
		c->_next = d;
		d->_next = e;
	}

	void _Print() {
		for (ListNode *iter = _head._next; iter != nullptr; iter = iter->_next) {
			std::cout << iter->_data << ", ";
		}
	}

	void _Reverse() {
		ListNode *fore = nullptr;
		ListNode *curr = _head._next;
		ListNode *back = nullptr;
		while (curr != nullptr) {
			back = curr->_next;
			curr->_next = fore;
			fore = curr;
			curr = back;
		}
		_head._next = fore;
	}

	/*
	|0|1|2|3|4|, 1,2
	|0|2|1|3|4|
	*/
	void _ReverseBetween(int m, int n) {
		ListNode *head = &_head;
		for (int i = 0; i < m; i += 1) {
			head = head->_next;
		}
		ListNode *tail = &_head;
		for (int i = 0; i <= n; i += 1) {
			tail = tail->_next;
		}

		ListNode *fore = tail->_next;
		ListNode *curr = head->_next;
		ListNode *back = nullptr;
		head->_next = tail;
		while (curr != tail) {
			back = curr->_next;
			curr->_next = fore;
			fore = curr;
			curr = back;
		}
		curr->_next = fore;
	}
};

int main(int argc, char *argv[]) {
	Solution solution;
	solution._Create();
	//solution._Reverse();
	solution._ReverseBetween(1,3);
	solution._Print();
	return 0;
}