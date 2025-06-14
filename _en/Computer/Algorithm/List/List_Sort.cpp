/* List_Sort.cpp
Author: BSS9395
Update: 2025-05-26T17:56:00+08@China-Shanghai+08
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<initializer_list>
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

	// Sort_Merge
	Node* _Sort_Merge_Merge(Node* head1, Node* head2) {
		if (head1 == nullptr) {
			return head2;
		}
		if (head2 == nullptr) {
			return head1;
		}
		Node _head = Node(-1);
		Node* curr = &_head;
		while (head1 != nullptr && head2 != nullptr) {
			if (head1->_data <= head2->_data) {
				curr->_next = head1;
				head1 = head1->_next;
			} else {
				curr->_next = head2;
				head2 = head2->_next;
			}
			curr = curr->_next;
		}
		if (head1 != nullptr) {
			curr->_next = head1;
		}
		if (head2 != nullptr) {
			curr->_next = head2;
		}
		return _head._next;
	}
	Node* _Sort_Merge_Sort(Node* head) {
		if (head == nullptr || head->_next == nullptr) {
			return head;
		}
		Node* fore = head;
		Node* back = head->_next->_next;
		while (back != nullptr && back->_next != nullptr) {
			fore = fore->_next;
			back = back->_next->_next;
		}
		Node* midd = fore->_next;
		fore->_next = nullptr;
		return _Sort_Merge_Merge(_Sort_Merge_Sort(head), _Sort_Merge_Sort(midd));
	};
	void _Sort_Merge() {
		_head._next = _Sort_Merge_Sort(_head._next);
	}

	// Sort_QuickSort
	Node* _Sort_QuickSort_Partition(Node* head, Node* tail) {
		if (head == nullptr || head->_next == tail) {
			return head;
		}
		Node* midd = head;
		for (Node* iter = head->_next; iter != tail; iter = iter->_next) {
			if (iter->_data < head->_data) {
				midd = midd->_next;
				swap(midd->_data, iter->_data);
			}
		}
		swap(head->_data, midd->_data);
		return midd;
	}
	void _Sort_QuickSort_Quick(Node* head, Node* tail) {
		if (head == tail) {
			return;
		}
		Node* midd = _Sort_QuickSort_Partition(head, tail);
		_Sort_QuickSort_Quick(head, midd);
		_Sort_QuickSort_Quick(midd->_next, tail);
	}
	void _Sort_QuickSort() {
		_Sort_QuickSort_Quick(_head._next, nullptr);
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
};

void _Test_Sort_Merge() {
	List list{
		1, 3, 2, 4, 5
	};
	list._Sort_Merge();
	list._Print();
}

void _Test_Sort_QuickSort() {
	List list{
		1, 3, 2, 4, 5
	};
	list._Sort_QuickSort();
	list._Print();
}

void _Test_Sort_Selection() {
	List list{
		1, 3, 2, 4, 5
	};
	list._Sort_Selection();
	list._Print();
}

int main() {
	// _Test_Sort_Merge();
	// _Test_Sort_QuickSort();
	_Test_Sort_Selection();

	return 0;
}