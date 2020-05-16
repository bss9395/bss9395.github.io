/* DoublyList.cpp
Author: BSS9395
Update: 2020-05-17T00:00:00+08@China-Guangdong-Zhanjiang+08
Design: Doubly Linked List
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::string;

typedef long iptr;


bool Checkout(bool failed, const string &file, const iptr &line, const string &function, const iptr &error, const string &report) {
	if (failed) {
		cerr << "[" << file << ":" << line << ":" << function << "]" << error << "#" << report;
		if (!(errno == 0 && error == 0)) {
			cerr << "#" << strerror(errno);
			throw error;
		}
		cerr << endl;
	}

	errno = 0;
	return failed;
}

template<typename T>
class Node {
	friend bool operator<(const Node &lhs, const Node &rhs) {
		// cerr << __FUNCTION__ << endl;

		return (lhs._data < rhs._data);
	}

	friend bool operator==(const Node &lhs, const Node &rhs) {
		return (lhs._data == rhs._data);
	}

	friend ostream &operator<<(ostream &os, const Node &node) {
		os << node._data;
		return os;
	}

public:
	Node(const T &data = T())
		: _data(data), _next(nullptr), _prev(nullptr) {
		// cerr << __FUNCTION__ << endl;
	}

	~Node() {
		// cerr << __FUNCTION__ << endl;
	}

public:
	T _data;
	Node *_prev;
	Node *_next;
};


template<typename T>
class DoublyList {
	typedef class Node<T> Node;

public:
	DoublyList()
		:_size(0) {
		// cerr << __FUNCTION__ << endl;

		_head._next = &_head;
		_head._prev = &_head;
	}

	~DoublyList() {
		// cerr << __FUNCTION__ << endl;

		iptr size = 0;
		Node *curr = _head._next;
		Node *node = nullptr;
		while (curr != &_head) {
			node = curr;
			curr = curr->_next;

			delete node;
			size += 1;
		}

		Checkout(_size != size, __FILE__, __LINE__, __FUNCTION__, errno, "_size != size");
	}

public:
	void Traverse(ostream &os = cout, Node *node = nullptr) {
		// cerr << __FUNCTION__ << endl;

		if (node == nullptr) {
			node = _head._next;
		}

		iptr size = 0;
		while (node != &_head) {
			os << " => " << *node;
			size += 1;

			node = node->_next;
		}
		os << endl;

		Checkout(_size != size, __FILE__, __LINE__, __FUNCTION__, errno, "_size != size");
	}

public:
	iptr Attach(Node *node, iptr index = 0) {
		// cerr << __FUNCTION__ << endl;

		iptr ret = 0;
		Node *curr = &_head;

		while (index > 0) {
			curr = curr->_next;
			index -= 1;
		}
		while (index < 0) {
			curr = curr->_prev;
			index += 1;
		}

		node->_next = curr->_next;
		curr->_next->_prev = node;
		curr->_next = node;
		node->_prev = curr;

		_size += 1;
		ret += 1;
		return ret;
	}

	iptr Detach(Node **node, iptr index = 0) {
		iptr ret = 0;
		Node *curr = &_head;

		while (index > 0) {
			curr = curr->_next;
			index -= 1;
		}
		while (index < 0) {
			curr = curr->_prev;
			index += 1;
		}

		node = &(curr->_next);
		curr->_next = curr->_next;
		curr->_next->_prev = curr;

		_size -= 1;
		ret += 1;
		return ret;
	}

public:
	Node _head;
	iptr _size;
};


#ifndef Main

int main(int argc, char *argv[]) {
	DoublyList<string> list;

	Node<string> *node1 = new Node<string>("node1");
	Node<string> *node2 = new Node<string>("node2");

	list.Attach(node1);
	list.Attach(node2, -1);

	list.Traverse();

	return 0;
}

#endif // Main
