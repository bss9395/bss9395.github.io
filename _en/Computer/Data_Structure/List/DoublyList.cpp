/* DoublyList.cpp
Author: BSS9395
Update: 2020-05-17T17:27:00+08@China-Guangdong-Zhanjiang+08
Design: Doubly Linked List
*/

/*
 0   1   2   3   4   5   6
 +---+---+---+---+---+---+
 | D | o | u | b | l | y |
 +---+---+---+---+---+---+
   1   2   3   4   5   6
  -6  -5  -4  -3  -2  -1


 0   1   2   3   4   5   6
 +---+---+---+---+---+---+
 | P | y | t | h | o | n |
 +---+---+---+---+---+---+
 0   1   2   3   4   5   6
-6  -5  -4  -3  -2  -1   0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::string;

typedef long iptr;
typedef const char *Level;
static const struct {
	Level _Info;
	Level _ToDo;
	Level _Warn;
	Level _Error;
	Level _Fatal;
} ELevel = { "Info", "ToDo", "Warn", "Error", "Fatal" };

bool Checkout(const bool &failed, const string &file, const iptr &line, const string &function, const Level &level, const string &report) {
	// cerr << __FUNCTION__ << endl;
	if (failed) {
		cerr << "[" << file << "==" << line << "==" << function << "]" << endl;
		cerr << "##" << level << "##" << report;
		if (!(errno == 0 && level == ELevel._Info)) {
			cerr << "##" << strerror(errno);
			throw level;
		}
		cerr << endl;
	}

	errno = 0;
	return failed;
}

template<typename Type>
class Node {
	friend bool operator<(const Node &lhs, const Node &rhs) {
		// cerr << __FUNCTION__ << endl;
		return (lhs._data < rhs._data);
	}

	friend bool operator==(const Node &lhs, const Node &rhs) {
		// cerr << __FUNCTION__ << endl;
		return (lhs._data == rhs._data);
	}

	friend ostream &operator<<(ostream &os, const Node &node) {
		// cerr << __FUNCTION__ << endl;
		os << node._data;
		return os;
	}

public:
	Node(const Type &data = Type(), Node *prev = nullptr, Node *next = nullptr)
		: _data(data), _prev(prev), _next(next) {
		// cerr << __FUNCTION__ << endl;
	}

	~Node() {
		// cerr << __FUNCTION__ << endl;
	}

public:
	Type _data;
	Node *_prev;
	Node *_next;
};


template<typename Type>
class DoublyList {
	class DoublyListPtr;

public:
	typedef class Node<Type> Node;
	typedef iptr(*Visit)(Node *node);
	typedef class DoublyListPtr Iterator;

public:
	static iptr Print(Node *node) {
		// cerr << __FUNCTION__ << endl;
		iptr ret = 0;

		cout << " => " << *node;

		ret += 1;
		return ret;
	}

public:
	DoublyList()
		: _size(0) {
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

		Checkout(_size != size, __FILE__, __LINE__, __FUNCTION__, ELevel._Fatal, "_size != size");
	}

public:
	iptr Traverse(const Visit &visit, Node *node = nullptr) {
		// cerr << __FUNCTION__ << endl;
		iptr ret = 0;

		if (node == nullptr) {
			node = _head._next;
		}

		while (node != &_head) {
			ret += visit(node);

			node = node->_next;
		}
		cout << endl;

		Checkout(_size != ret, __FILE__, __LINE__, __FUNCTION__, ELevel._Fatal, "_size != size");
		return ret;
	}

public:
	iptr Attach(Node *node, iptr index = 0) {
		iptr ret = 0;

		Node *edge = &_head;
		index = index % (_size + 1);
		while (index > 0) {
			edge = edge->_next;
			index -= 1;
		}
		while (index < 0) {
			edge = edge->_prev;
			index += 1;
		}

		node->_next = edge->_next;
		edge->_next->_prev = node;
		edge->_next = node;
		node->_prev = edge;
		_size += 1;

		ret += 1;
		return ret;
	}

	iptr Detach(Node **node, iptr index = 1) {
		iptr ret = 0;

		if (!Checkout(_size <= 0 || index == 0, __FILE__, __LINE__, __FUNCTION__, ELevel._Info, "_size <= 0 || index == 0")) {
			Node *knot = &_head;
			index = (index > 0) ? ((index - 1) % _size + 1) : ((index + 1) % _size - 1);
			while (index > 0) {
				knot = knot->_next;
				index -= 1;
			}
			while (index < 0) {
				knot = knot->_prev;
				index += 1;
			}

			*node = knot;
			knot->_prev->_next = knot->_next;
			knot->_next->_prev = knot->_prev;

			_size -= 1;
			ret += 1;
		}
		return ret;
	}


public:
	class DoublyListPtr {
		friend bool operator==(const DoublyListPtr &lhs, const DoublyListPtr &rhs) {
			// cerr << __FUNCTION__ << endl;
			return (lhs._ptr == rhs._ptr);
		}

		friend bool operator!=(const DoublyListPtr &lhs, const DoublyListPtr &rhs) {
			// cerr << __FUNCTION__ << endl;
			return (lhs._ptr != rhs._ptr);
		}

	public:
		DoublyListPtr(Node &head, Node *ptr = nullptr)
			: _head(head), _ptr(ptr) {
			// cerr << __FUNCTION__ << endl;
		}

	public:
		DoublyListPtr &operator+=(int offset) {
			// cerr << __FUNCTION__ << endl;
			while (offset > 0) {
				if (_ptr == &_head) {
					_ptr = _ptr->_next;
				}
				_ptr = _ptr->_next;
				offset -= 1;
			}
			while (offset < 0) {
				if (_ptr == &_head) {
					_ptr = _ptr->_prev;
				}
				_ptr = _ptr->_prev;
				offset += 1;
			}

			return *this;
		}

		DoublyListPtr &operator-=(int offset) {
			// cerr << __FUNCTION__ << endl;
			while (offset > 0) {
				if (_ptr = &_head) {
					_ptr = _ptr->_prev;
				}
				_ptr = _ptr->_prev;
				offset -= 1;
			}
			while (offset < 0) {
				if (_ptr = &_head) {
					_ptr = _ptr->_next;
				}
				_ptr = _ptr->_next;
				offset += 1;
			}

			return *this;
		}

		Type &operator*() {
			// cerr << __FUNCTION__ << endl;

			return _ptr->_data;
		}

		Type *operator->() {
			// cerr << __FUNCTION__ << endl;

			return &(operator*());
		}

	public:
		Node &_head;
		Node *_ptr;
	};

	Iterator Beg() {
		// cerr << __FUNCTION__ << endl;
		return Iterator(_head, _head._next);
	}

	Iterator End() {
		// cerr << __FUNCTION__ << endl;
		return Iterator(_head, &_head);
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
	Node<string> *node3 = new Node<string>("node3");

	list.Attach(node1);
	list.Attach(node2, -1);
	list.Attach(node3, -1);

	Node<string> *node;
	list.Detach(&node, 2);

	list.Traverse(DoublyList<string>::Print);

	////////////////////////////////////////

	DoublyList<string>::Iterator beg = list.Beg();
	DoublyList<string>::Iterator end = list.End();
	while (beg != end) {
		cerr << " => " << *beg;
		beg += 1;
	}

	return 0;
}

#endif // Main
