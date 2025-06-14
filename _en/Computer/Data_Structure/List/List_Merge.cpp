/* List_Merge.cpp
Author: BSS9395
Update: 2025-05-26T09:28:00+08@China-ShangHai+08
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<initializer_list>
#include<queue>
using namespace std;

class List {
public:
	struct Node {
		int _value = 0;
		Node* _next = nullptr;

		Node() {

		}

		Node(int value) {
			_value = value;
			_next = nullptr;
		}
	};

private:
	Node _head;

public:
	List() {

	}

	List(const initializer_list<int>& init) {
		Node* curr = &_head;
		for (auto value : init) {
			Node* node = new Node(value);
			curr->_next = node;
			curr = curr->_next;
		}
	}

public:
	void _Print() {
		for (Node* iter = _head._next; iter != nullptr; iter = iter->_next) {
			if (iter->_next != nullptr) {
				cout << iter->_value << ", ";
			} else {
				cout << iter->_value;
			}
		}
		cout << endl;
	}

public:
	void _Merge(List& other) {
		Node* curr = &_head;
		Node* iter1 = _head._next;
		Node* iter2 = other._head._next;
		while (iter1 != nullptr && iter2 != nullptr) {
			if (iter1->_value <= iter2->_value) {
				curr->_next = iter1;
				iter1 = iter1->_next;
			} else {
				curr->_next = iter2;
				iter2 = iter2->_next;
			}
			curr = curr->_next;
		}
		if (iter1 != nullptr) {
			curr->_next = iter1;
		} else if (iter2 != nullptr) {
			curr->_next = iter2;
		}
		other._head._next = nullptr;
	}

public:
	static void _Merge(List& list, List& list1, List& list2) {
		Node* curr = &list._head;
		Node* iter1 = list1._head._next;
		Node* iter2 = list2._head._next;
		while (iter1 != nullptr && iter2 != nullptr) {
			if (iter1->_value <= iter2->_value) {
				curr->_next = iter1;
				iter1 = iter1->_next;
			} else {
				curr->_next = iter2;
				iter2 = iter2->_next;
			}
			curr = curr->_next;
		}
		if (iter1 != nullptr) {
			curr->_next = iter1;
		} else if (iter2 != nullptr) {
			curr->_next = iter2;
		}
		list1._head._next = nullptr;
		list2._head._next = nullptr;
	}

	static void _Merge_Multiple(List& list, vector<List*>& lists) {
		struct Compare {
			bool operator()(Node* lhs, Node* rhs) {
				return (lhs->_value > rhs->_value);
			}
		};

		priority_queue<Node*, vector<Node*>, Compare> pq;
		for (int i = 0; i < lists.size(); i += 1) {
			List* listi = lists[i];
			Node* node = (*listi)._head._next;
			if (node != nullptr) {
				pq.push(node);
			}
		}

		Node* curr = &list._head;
		while (pq.empty() == false) {
			Node* node = pq.top();
			pq.pop();
			curr->_next = node;
			curr = curr->_next;
			if (node->_next != nullptr) {
				pq.push(node->_next);
			}
		}

		for (int i = 0; i < lists.size(); i += 1) {
			List* listi = lists[i];
			(*listi)._head._next = nullptr;
		}
	}
};

void _Test_Merge() {
	List list1{ 1, 3, 5, 7 };
	List list2{ 2, 4, 6, 8 };

	list1._Merge(list2);
	list1._Print();
}

void _Test_Merge_static() {
	List list1{ 1, 3, 5, 7 };
	List list2{ 2, 4, 6, 8 };
	List list;
	List::_Merge(list, list1, list2);
	list._Print();
}

void _Test_Merge_Multiple() {
	List list1{ 1, 3, 5, 7 };
	List list2{ 2, 4, 6, 8 };
	vector<List*> lists;
	lists.push_back(&list1);
	lists.push_back(&list2);
	List list;
	List::_Merge_Multiple(list, lists);
	list._Print();
}

int main() {
	// _Test_Merge();
	// _Test_Merge_static();
	_Test_Merge_Multiple();

	return 0;
}
