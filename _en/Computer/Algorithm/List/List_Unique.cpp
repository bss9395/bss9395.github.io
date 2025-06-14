/* List_Unique.cpp
Author: BSS9395
Update: 2025-05-26T21:32:00+08@China-ShangHai+08
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

	// Sort_Selection
	void _Sort_Selection() {
		for (Node* iteri = _head._next; iteri != nullptr; iteri = iteri->_next) {
			Node* minIndex = iteri;
			for (Node* iterj = iteri->_next; iterj != nullptr; iterj = iterj->_next) {
				if ((minIndex->_data <= iterj->_data) == false) {
					minIndex = iterj;
				}
			}
			if (minIndex != iteri) {
				swap(minIndex->_data, iteri->_data);
			}
		}
	}

	void _Unique() {
		Node* curr = _head._next;
		while (curr != nullptr && curr->_next != nullptr) {
			if (curr->_data == curr->_next->_data) {
				Node* node = curr->_next;
				curr->_next = curr->_next->_next;
				delete node;
			} else {
				curr = curr->_next;
			}
		}
	}
};

void _Test_Unique() {
	List list{
		1, 3, 2, 4, 6, 5, 4
	};
	list._Sort_Selection();
	list._Unique();
	list._Print();
}

int main() {
	_Test_Unique();
	return 0;
}