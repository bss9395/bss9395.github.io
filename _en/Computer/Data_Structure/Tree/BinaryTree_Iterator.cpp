/* BinaryTree.cpp
Author: BSS9395
Update: 2025-05-28T17:08:00+08@China-ShangHai+08
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<initializer_list>
#include<map>
using namespace std;

template<typename T_>
struct Tree {
	struct Node {
	public:
		T_ _datum = 0;
		Node* _parent = nullptr;
		Node* _left = nullptr;
		Node* _right = nullptr;
		Node* _prev = nullptr;
		Node* _next = nullptr;

	public:
		Node() {

		}
		Node(T_ data) {
			_datum = data;
			_left = nullptr;
			_right = nullptr;
		}
	};

	struct PreorderIterator {
	public:
		stack<Node*> _stack;
		Node* _curr = nullptr;

	public:
		PreorderIterator() {

		}
		PreorderIterator(Node* root) {
			if (root == nullptr) {
				return;
			}
			_stack.push(root);
			operator++();
		}

		PreorderIterator& operator++() {
			if (_stack.empty() == true) {
				_curr = nullptr;
			} else {
				_curr = _stack.top();
				_stack.pop();
				if (_curr->_right != nullptr) {
					_stack.push(_curr->_right);
				}
				if (_curr->_left != nullptr) {
					_stack.push(_curr->_left);
				}
			}
			return (*this);
		}
		PreorderIterator operator++(int) {
			PreorderIterator temp = (*this);
			++(*this);
			return temp;
		}

		bool operator==(const PreorderIterator& iter) const {
			return (_curr == iter._curr);
		}

		bool operator!=(const PreorderIterator& iter) const {
			return (_curr != iter._curr);
		}

		T_& operator*() {
			return _curr->_datum;
		}
		T_* operator->() {
			return &(operator*());
		}
	};

	struct InorderIterator {
	public:
		stack<Node*> _stack;
		Node* _curr = nullptr;
		Node* _root = nullptr;
		
	public:
		InorderIterator() {

		}
		InorderIterator(Node* root) {
			_root = root;
			operator++();
		}

	public:
		InorderIterator& operator++() {
			while (_root != nullptr) {
				_stack.push(_root);
				_root = _root->_left;
			}
			if (_stack.empty() == true) {
				_curr = nullptr;
			} else {
				_curr = _stack.top();
				_stack.pop();
				_root = _curr->_right;
			}
			return (*this);
		}
		InorderIterator operator++(int) {
			InorderIterator temp = (*this);
			++(*this);
			return temp;
		}

		bool operator==(const InorderIterator& iter) const {
			return (_curr == iter._curr);
		}

		bool operator!=(const InorderIterator& iter) const {
			return (_curr != iter._curr);
		}

		T_& operator*() {
			return _curr->_datum;
		}
		T_* operator->() {
			return &(operator*());
		}
	};

	struct PostorderIterator {
	public:
		stack<Node*> _stack1;
		stack<Node*> _stack2;
		Node *_curr = nullptr;

	public:
		PostorderIterator() {

		}
		PostorderIterator(Node* root) {
			if (root == nullptr) {
				return;
			}
			_stack1.push(root);
			while (_stack1.empty() == false) {
				Node* node = _stack1.top();
				_stack1.pop();
				_stack2.push(node);
				if (node->_left != nullptr) {
					_stack1.push(node->_left);
				}
				if (node->_right != nullptr) {
					_stack1.push(node->_right);
				}
			}
			operator++();
		}

	public:
		PostorderIterator& operator++() {
			if (_stack2.empty() == true) {
				_curr = nullptr;
			} else {
				_curr = _stack2.top();
				_stack2.pop();
			}
			return (*this);
		}
		PostorderIterator operator++(int) {
			PostorderIterator temp = (*this);
			++(*this);
			return temp;
		}

		bool operator==(const PostorderIterator& iter) const {
			return (_curr == iter._curr);
		}
		bool operator!=(const PostorderIterator& iter) const {
			return (_curr != iter._curr);
		}

		T_& operator*() {
			return _curr->_datum;
		}
		T_* operator->() {
			return &(operator*());
		}
	};

	struct LevelorderIterator {
	public:
		queue<Node*> _queue;
		Node* _curr = nullptr;

	public:
		LevelorderIterator() {

		}
		LevelorderIterator(Node* root) {
			if (root == nullptr) {
				return;
			}
			_queue.push(root);
			operator++();
		}

	public:
		LevelorderIterator& operator++() {
			if (_queue.empty() == true) {
				_curr = nullptr;
			} else {
				_curr = _queue.front(); 
				_queue.pop();
				if (_curr->_left != nullptr) {
					_queue.push(_curr->_left);
				}
				if (_curr->_right != nullptr) {
					_queue.push(_curr->_right);
				}
			}
			return (*this);
		}
		LevelorderIterator operator++(int) {
			LevelorderIterator temp = (*this);
			++(*this);
			return temp;
		}
	
		bool operator==(const LevelorderIterator& iter) const {
			return (_curr == iter._curr);
		}
		bool operator!=(const LevelorderIterator& iter) const {
			return (_curr != iter._curr);
		}

		T_& operator*() {
			return _curr->_datum;
		}
		T_* operator->() {
			return &(operator*());
		}
	};

	struct DoublyLinkedIterator {
	public:
		Tree* _tree = nullptr;
		Node* _prev = nullptr;
		Node* _curr = nullptr;

	public:
		DoublyLinkedIterator() {
		
		}
		DoublyLinkedIterator(Tree* tree) {
			_tree = tree;
			tree->_DoublyLinkedList_Inorder_Nonrecursion();
			_prev = nullptr;
			_curr = &tree->_list;
			operator++();
		}

	public:
		DoublyLinkedIterator& operator++() {
			if (_curr != nullptr) {
				_prev = _curr;
				_curr = _curr->_next;
			}
			return (*this);
		}
		DoublyLinkedIterator operator++(int) {
			DoublyLinkedIterator temp = (*this);
			++(*this);
			return temp;
		}
		DoublyLinkedIterator& operator--() {
			if (_curr != &_tree->_list) {
				_curr = _prev;
				_prev = _curr->_prev;
			}
			return (*this);
		}
		DoublyLinkedIterator operator--(int) {
			DoublyLinkedIterator temp = (*this);
			--(*this);
			return temp;
		}

		bool operator==(const DoublyLinkedIterator& iter) const {
			return (_curr == iter._curr);
		}
		bool operator!=(const DoublyLinkedIterator& iter) const {
			return (_curr != iter._curr);
		}

		T_& operator*() {
			return _curr->_datum;
		}
		T_* operator->() {
			return &(operator*());
		}
	};

public:
	Node _head;
	Node _list;

public:
	Tree() {

	}
	Tree(const initializer_list<T_>& data) {
		if (data.size() <= 1) {
			return;
		}
		vector<Node*> tree;
		for (auto datum : data) {
			tree.push_back(new Node(datum));
		}
		int null = *data.begin();
		for (int node = 0, end = tree.size() / 2; node <= end;  node += 1) {
			if (node * 2 < (int)tree.size() && tree[node * 2]->_datum != null) {
				tree[node]->_left = tree[node * 2];
				tree[node * 2]->_parent = tree[node];
			}
			if (node * 2 + 1 < (int)tree.size() && tree[node * 2 + 1]->_datum != null) {
				tree[node]->_right = tree[node * 2 + 1];
				tree[node * 2 + 1]->_parent = tree[node];
			}
		}
		_head._right = tree[0]->_right;
		delete tree[0];
	}

public:
	void _Preorder_Travel_Recursion(ostream& os) {
		_Preorder_Recursion(os, _head._right);
		os << endl;
	}
	void _Preorder_Recursion(ostream& os, Node* root) {
		if (root == nullptr) {
			return;
		}
		os << root->_datum;
		_Preorder_Recursion(os, root->_left);
		_Preorder_Recursion(os, root->_right);
	}

	void _Inorder_Travel_Recursion(ostream& os) {
		_Inorder_Recursion(os, _head._right);
		os << endl;
	}
	void _Inorder_Recursion(ostream& os, Node* root) {
		if (root == nullptr) {
			return;
		}
		_Inorder_Recursion(os, root->_left);
		os << root->_datum;
		_Inorder_Recursion(os, root->_right);
	}

	void _Postorder_Travel_Recursion(ostream& os) {
		_Postorder_Recursion(os, _head._right);
		os << endl;
	}
	void _Postorder_Recursion(ostream& os, Node* root) {
		if (root == nullptr) {
			return;
		}
		_Postorder_Recursion(os, root->_left);
		_Postorder_Recursion(os, root->_right);
		os << root->_datum;
	}

	void _Preorder_Travel_Nonrecursion(ostream& os) {
		Node *root = _head._right;
		if (root == nullptr) {
			return;
		}
		stack<Node*> stack;
		stack.push(root);
		while (stack.empty() == false) {
			Node *curr = stack.top();
			stack.pop();
			os << curr->_datum;
			if (curr->_right != nullptr) {
				stack.push(curr->_right);
			}
			if (curr->_left != nullptr) {
				stack.push(curr->_left);
			}
		}
	}

	void _Inorder_Travel_Nonrecursion(ostream& os) {
		Node *root = _head._right;
		if (root == nullptr) {
			return;
		}
		stack<Node*> stack;
		while (root != nullptr || stack.empty() == false) {
			while (root != nullptr) {
				stack.push(root);
				root = root->_left;
			}
			if (stack.empty() == false) {
				Node* curr = stack.top();
				stack.pop();
				os << curr->_datum;
				root = curr->_right;
			}
		}
	}

	void _Postorder_Travel_Nonrecursion(ostream& os) {
		Node* root = _head._right;
		if (root == nullptr) {
			return;
		}		
		stack<Node*> stack1;
		stack<Node*> stack2;
		stack1.push(root);
		while (stack1.empty() == false) {
			root = stack1.top();
			stack1.pop();
			stack2.push(root);
			if (root->_left != nullptr) {
				stack1.push(root->_left);
			}
			if (root->_right != nullptr) {
				stack1.push(root->_right);
			}
		}
		while (stack2.empty() == false) {
			Node *curr = stack2.top();
			stack2.pop();
			os << curr->_datum;
		}
	}

	void _Levelorder_Travel(ostream& os) {
		Node* root = _head._right;
		if (root == nullptr) {
			return;
		}
		queue<Node*> level;
		level.push(root);
		while (level.empty() == false) {
			Node* curr = level.front();
			level.pop();
			if (curr->_left != nullptr) {
				level.push(curr->_left);
			}
			if (curr->_right != nullptr) {
				level.push(curr->_right);
			}
			os << curr->_datum;
		}
	}

public:
	PreorderIterator _Preorder_Begin() {
		return PreorderIterator(_head._right);
	}
	PreorderIterator _Preorder_End() {
		return PreorderIterator();
	}
	InorderIterator _Inorder_Begin() {
		return InorderIterator(_head._right);
	}
	InorderIterator _Inorder_End() {
		return InorderIterator();
	}
	PostorderIterator _Postorder_Begin() {
		return PostorderIterator(_head._right);
	}
	PostorderIterator _Postorder_End() {
		return PostorderIterator();
	}
	LevelorderIterator _Levelorder_Begin() {
		return LevelorderIterator(_head._right);
	}
	LevelorderIterator _Levelorder_End() {
		return LevelorderIterator();
	}

	DoublyLinkedIterator _DoublyLinked_Begin() {
		return DoublyLinkedIterator(this);
	}
	DoublyLinkedIterator _DoublyLinked_End() {
		return DoublyLinkedIterator();
	}

public:
	void _DoublyLinkedList_Inorder_Recursion() {
		_list._next = nullptr;
		Node* curr = nullptr;
		_DoublyLinkedList_Inorder(curr, _head._right);
	}
	void _DoublyLinkedList_Inorder(Node*& curr, Node* root) {
		if (root == nullptr) {
			return;
		}
		_DoublyLinkedList_Inorder(curr, root->_left);
		if (_list._next == nullptr) {
			_list._next = root;
			root->_prev = &_list;
			curr = _list._next;
		} else {
			curr->_next = root;
			root->_prev = curr;
			curr = root;
		}
		_DoublyLinkedList_Inorder(curr, root->_right);
	}

	void _DoublyLinkedList_Inorder_Nonrecursion() {
		_list._next = nullptr;
		Node* curr = nullptr;
		Node* root = _head._right;
		if (root == nullptr) {
			return;
		}
		stack<Node*> stack;
		while (root != nullptr || stack.empty() == false) {
			while (root != nullptr) {
				stack.push(root);
				root = root->_left;
			}
			if (stack.empty() == false) {
				Node* node = stack.top();
				stack.pop();
				if (_list._next == nullptr) {
					_list._next = node;
					node->_prev = &_list;
					curr = _list._next;
				} else {
					curr->_next = node;
					node->_prev = curr;
					curr = node;
				}
				root = node->_right;
			}
		}
	}
};

void _Test_Preorder_Travel_Recursion() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Preorder_Travel_Recursion(cout);
	cout << endl;
}

void _Test_Inorder_Travel_Recursion() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Inorder_Travel_Recursion(cout);
	cout << endl;
}

void _Test_Postorder_Travel_Recursion() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Postorder_Travel_Recursion(cout);
	cout << endl;
}

void _Test_Preorder_Travel_Nonrecursion() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Preorder_Travel_Nonrecursion(cout);
	cout << endl;
}

void _Test_Inorder_Travel_Nonrecursion() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Inorder_Travel_Nonrecursion(cout);
	cout << endl;
}

void _Test_Postorder_Travel_Nonrecursion() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Postorder_Travel_Nonrecursion(cout);
	cout << endl;
}

void _Test_Levelorder_Travel() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Levelorder_Travel(cout);
	cout << endl;
}

void _Test_PreorderIterator() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Inorder_Travel_Recursion(cout);

	for (Tree<int>::PreorderIterator iter = tree._Preorder_Begin(); iter != tree._Preorder_End(); iter++) {
		cout << (*iter);
	}
	cout << endl;
}

void _Test_InorderIterator() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Inorder_Travel_Recursion(cout);

	for (Tree<int>::InorderIterator iter = tree._Inorder_Begin(); iter != tree._Inorder_End(); iter++) {
		cout << (*iter);
	}
	cout << endl;
}

void _Test_PostorderIterator() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Inorder_Travel_Recursion(cout);

	for (Tree<int>::PostorderIterator iter = tree._Postorder_Begin(); iter != tree._Postorder_End(); iter++) {
		cout << (*iter);
	}
	cout << endl;
}

void _Test_LevelorderIterator() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Inorder_Travel_Recursion(cout);

	for (Tree<int>::LevelorderIterator iter = tree._Levelorder_Begin(); iter != tree._Levelorder_End(); iter++) {
		cout << (*iter);
	}
	cout << endl;
}

void _Test_DoublyLinkedList_Inorder_Recursion() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Inorder_Travel_Recursion(cout);

	tree._DoublyLinkedList_Inorder_Recursion();
	for (auto iter = tree._list._next; iter != nullptr; iter = iter->_next) {
		cout << iter->_datum;
	}
	cout << endl;
}

void _Test_DoublyLinkedList_Inorder_Nonrecursion() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Inorder_Travel_Recursion(cout);

	tree._DoublyLinkedList_Inorder_Nonrecursion();
	for (auto iter = tree._list._next; iter != nullptr; iter = iter->_next) {
		cout << iter->_datum;
	}
	cout << endl;
}

void _Test_DoublyLinkedIterator() {
	int null = -100;
	Tree<int> tree{
		null, 1, 2, 3, null, 5, 6, null
	};
	tree._Inorder_Travel_Recursion(cout);

	Tree<int>::DoublyLinkedIterator iter = tree._DoublyLinked_Begin();
	for (; iter != tree._DoublyLinked_End(); iter++) {
		cout << (*iter);
	}
	cout << endl;

	iter--;
	cout << (*iter) << endl;
}

void _Test_map_erase() {
	// 25163
	map<int, int> tree;
	tree[1] = 2;
	tree[2] = 5;
	tree[3] = 1;
	tree[4] = 6;
	tree[5] = 3;
	for (auto iter = tree.begin(); iter != tree.end(); iter++) {
		cout << iter->second;
	}
	cout << endl;

	map<int, int>::iterator iter = tree.begin();
	iter++;
	iter++;
	iter++;
	iter++;
	cout << iter->second << endl;
	iter = tree.erase(iter);
	if (iter == tree.end()) {
		cout << "true" << endl;
	}	
	cout << endl;
}

/*
	N
	 \
	  1
	 / \
	2   3
   /\   /\
  N  5 6  N
*/
int main() {
	// _Test_Preorder_Travel_Recursion();
	// _Test_Inorder_Travel_Recursion();
	// _Test_Postorder_Travel_Recursion();

	// _Test_Preorder_Travel_Nonrecursion();
	// _Test_Inorder_Travel_Nonrecursion();
	// _Test_Postorder_Travel_Nonrecursion();
	// _Test_Levelorder_Travel();

	// _Test_PreorderIterator();
	// _Test_InorderIterator();
	// _Test_PostorderIterator();
	_Test_LevelorderIterator();

	// _Test_DoublyLinkedList_Inorder_Recursion();
	// _Test_DoublyLinkedList_Inorder_Nonrecursion();

	// _Test_DoublyLinkedIterator();

	// _Test_map_erase();

	return 0;
}