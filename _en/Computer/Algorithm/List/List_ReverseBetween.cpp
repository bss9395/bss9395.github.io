/* List_ReverseBetween.cpp
Author: BSS9395
Update: 2025-05-25T21:06:00+08@China-ShangHai+08
*/

#include<iostream>
#include<string>
#include<initializer_list>
using namespace std;

struct List {
	struct Node {
		int _data = -1;
		Node *_next = nullptr;

		Node(int data) {
			_data = data;
		}
	};
	Node _head = Node(-1);

	List(const initializer_list<int>& data) {
		Node* curr = &_head;
		for (auto datum : data) {
			Node* node = new Node(datum);
			curr->_next = node;
			curr = curr->_next;
		}
	}

	void _Print() {
		for (Node *iter = _head._next; iter != nullptr; iter = iter->_next) {
			if (iter->_next != nullptr) {
				cout << iter->_data << ", ";
			} else {
				cout << iter->_data;
			}
		}
		cout << endl;
	}

	/*
	H->0->1->2->3->4->N
	N<-0<-1<-2<-3<-4<-H
	*/
	void _Reverse() {
		Node *fore = nullptr;
		Node *curr = _head._next;
		Node *back = nullptr;
		while (curr != nullptr) {
			back = curr->_next;
			curr->_next = fore;
			fore = curr;
			curr = back;
		}
		_head._next = fore;
	}

	/*
	H->0->1->2->3->4->N  [1,2]
	H->0->2->1->3->4->N  [1,2]

	H->0---->
		 1<-2
		 ----->3->4->N   [1,2]
	*/
	void _ReverseBetween(int m, int n) {
		Node* head = &_head;
		for (int i = 0; i < m; i += 1) {
			head = head->_next;
		}
		Node* tail = &_head;
		for (int i = 0; i <= n; i += 1) {
			tail = tail->_next;
		}
		tail = tail->_next;

		Node* fore = tail;
		Node* curr = head->_next;
		Node* back = nullptr;
		while (curr != tail) {
			back = curr->_next;
			curr->_next = fore;
			fore = curr;
			curr = back;
		}
		head->_next = fore;
	}
};

int main() {
	List list{
		0, 1, 2, 3, 4, 5
	};
	// list._Reverse();
	list._ReverseBetween(1, 3);
	list._Print();
	return 0;
}
