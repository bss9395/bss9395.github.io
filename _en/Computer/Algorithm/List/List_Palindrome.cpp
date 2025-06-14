/* List_Palindrome.cpp
Author: BSS9395
Update: 2025-05-26T21:24:00+08@China-ShangHai+08
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct List {
	struct Node {
		int _data = -1;
		Node *_next = nullptr;

		Node(int data) {
			_data = data;
			_next = nullptr;
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
	H->1->2->3->4->N
	H->1->2->3<-4
			 N

	H->1->2->3->4->5->N
	H->1->2->3<-4<-5
			 N
	*/
	bool _Is_Palindrome() {
		auto _Reverse = [](Node* head) -> Node* {
			Node* fore = nullptr;
			Node* curr = head;
			Node* back = nullptr;
			while (curr != nullptr) {
				back = curr->_next;
				curr->_next = fore;
				fore = curr;
				curr = back;
			}
			return fore;
		};

		Node* head = _head._next;
		Node* fore = head;
		Node* back = head;
		while (back != nullptr && back->_next != nullptr) {
			fore = fore->_next;
			back = back->_next->_next;
		}
		Node* tail = _Reverse(fore);
		bool flag = true;
		for (fore = head, back = tail; back != nullptr; ) {
			if (fore->_data != back->_data) {
				flag = false;
				break;
			}
			fore = fore->_next;
			back = back->_next;
		}
		_Reverse(tail);
		return flag;
	}
};

void _Test_Is_Palindrome() {
	List list{
		1, 2, 3, 2, 1
	};
	bool is_palindrome = list._Is_Palindrome();
	cout << boolalpha << is_palindrome << endl;
	list._Print();
}

int main() {
	_Test_Is_Palindrome();
	return 0;
}
