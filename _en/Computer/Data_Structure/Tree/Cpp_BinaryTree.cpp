/* Cpp_BinaryTree.cpp
Author: bss9395
Update: 2025-10-02T20:56:00+08@China-GuangDong-ZhanJiang+08
Keepin: bss9395@yeah.net
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<stack>
#include<queue>
#include<map>
using namespace std;

template<typename Key_, typename Value_>
struct BinaryTree {
	struct Node {
		Key_   _key = Key_();
		Value_ _value = Value_();
		Node* _parent = nullptr;
		Node* _left = nullptr;
		Node* _right = nullptr;
		Node* _prev = nullptr;
		Node* _next = nullptr;

		Node() {

		}
		Node(const Key_ &key) {
			_key = key;
		}
		Node(const Key_ &key, const Value_ &value) {
			_key = key;
			_value = value;
		}
		virtual ~Node() {

		}

		friend ostream &operator<<(ostream &os, const Node &that) {
			os << "{" << that._parent->_key << "|" << that._key << ":" << that._value << "}";
			return os;
		}
	};

	struct PreorderIterator {
		stack<Node *> _stack;
		Node *_curr = nullptr;

		PreorderIterator() {

		}
		PreorderIterator(Node *root) {
			if (root == nullptr) {
				_curr = nullptr;
				return;
			}
			_stack.push(root);
			operator++();
		}

		PreorderIterator &operator++() {
			if (_stack.empty() == true) {
				_curr = nullptr;
				return (*this);
			}
			_curr = _stack.top();
			_stack.pop();
			if (_curr->_right != nullptr) {
				_stack.push(_curr->_right);
			}
			if (_curr->_left != nullptr) {
				_stack.push(_curr->_left);
			}
			return (*this);
		}

		bool operator==(const PreorderIterator& iter) const {
			return (_curr == iter._curr);
		}

		bool operator!=(const PreorderIterator& iter) const {
			return (_curr != iter._curr);
		}

		Node &operator*() {
			return (*_curr);
		}
		Node *operator->() {
			return &(operator*());
		}
	};

	struct InorderIterator {
		stack<Node *> _stack;
		Node *_curr = nullptr;

		InorderIterator() {

		}
		InorderIterator(Node *root) {
			if (root == nullptr) {
				_curr = nullptr;
				return;
			}
			while (root != nullptr) {
				_stack.push(root);
				root = root->_left;
			}
			operator++();
		}

		InorderIterator &operator++() {
			if (_stack.empty() == true) {
				_curr = nullptr;
				return (*this);
			}
			_curr = _stack.top();
			_stack.pop();
			Node *root = _curr->_right;
			while (root != nullptr) {
				_stack.push(root);
				root = root->_left;
			}
			return (*this);
		}

		bool operator==(const InorderIterator &iter) const {
			return (_curr == iter._curr);
		}

		bool operator!=(const InorderIterator &iter) const {
			return (_curr != iter._curr);
		}

		Node &operator*() {
			return (*_curr);
		}
		Node *operator->() {
			return &(operator*());
		}
	};

	struct PostorderIterator {
		stack<Node*> _stack;
		Node *_curr = nullptr;

		PostorderIterator() {

		}
		PostorderIterator(Node* root) {
			if (root == nullptr) {
				_curr = nullptr;
				return;
			}
			stack<Node*> temp;
			temp.push(root);
			while (temp.empty() == false) {
				Node* node = temp.top();
				temp.pop();
				_stack.push(node);
				if (node->_left != nullptr) {
					temp.push(node->_left);
				}
				if (node->_right != nullptr) {
					temp.push(node->_right);
				}
			}
			operator++();
		}

		PostorderIterator& operator++() {
			if (_stack.empty() == true) {
				_curr = nullptr;
				return (*this);
			}
			_curr = _stack.top();
			_stack.pop();
			return (*this);
		}

		bool operator==(const PostorderIterator& iter) const {
			return (_curr == iter._curr);
		}
		bool operator!=(const PostorderIterator& iter) const {
			return (_curr != iter._curr);
		}

		Node &operator*() {
			return (*_curr);
		}
		Node *operator->() {
			return &(operator*());
		}
	};

	struct LevelorderIterator {
		queue<Node*> _queue;
		Node* _curr = nullptr;

		LevelorderIterator() {

		}
		LevelorderIterator(Node* root) {
			if (root == nullptr) {
				return;
			}
			_queue.push(root);
			operator++();
		}

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

		bool operator==(const LevelorderIterator& iter) const {
			return (_curr == iter._curr);
		}
		bool operator!=(const LevelorderIterator& iter) const {
			return (_curr != iter._curr);
		}

		Node &operator*() {
			return (*_curr);
		}
		Node *operator->() {
			return &(operator*());
		}
	};

	struct CircularDoublyLinkedIterator {
		Node* _curr = nullptr;

		CircularDoublyLinkedIterator() {

		}
		CircularDoublyLinkedIterator(Node* curr) {
			_curr = curr;
		}

		CircularDoublyLinkedIterator& operator++() {
			_curr = _curr->_next;
			return (*this);
		}
		CircularDoublyLinkedIterator& operator--() {
			_curr = _curr->_prev;
			return (*this);
		}

		bool operator==(const CircularDoublyLinkedIterator& iter) const {
			return (_curr == iter._curr);
		}
		bool operator!=(const CircularDoublyLinkedIterator& iter) const {
			return (_curr != iter._curr);
		}

		Node &operator*() {
			return (*_curr);
		}
		Node *operator->() {
			return &(operator*());
		}
	};

	static long _Compare(const Key_ &lhs, const Key_ &rhs) {
		if (lhs < rhs) {
			return -1;
		} else if (lhs > rhs) {
			return +1;
		}
		return 0;
	}

public:
	Node _head = Node();
	long _size = 0;
	function<long(const Key_ &, const Key_ &)> _compare = _Compare;

	BinaryTree() {
		_Init();
	}
	BinaryTree(const function<long(const Key_ &, const Key_ &)> compare) {
		_Init();
		_compare = compare;
	}
	BinaryTree(const vector<Key_> &data) {
		_Init();

		vector<Node*> nodes(data.size());
		nodes[0] = &_head;
		for (long i = 1; i < data.size(); i += 1) {
			if (std::is_same<Key_, Value_>::value == true) {
				nodes[i] = new Node(data[i], (Value_)data[i]);
			} else {
				nodes[i] = new Node(data[i]);
			}
		}

		const Key_ null = data[0];
		for (long node = 0, end = (long)nodes.size() / 2; node <= end; node += 1) {
			if (node != 0 && node * 2 < (long)nodes.size() && nodes[node * 2]->_key != null) {
				nodes[node * 2]->_parent = nodes[node];
				nodes[node]->_left = nodes[node * 2];
				_size += 1;  // 头节点的左孩子为空节点
				_head._prev->_next = nodes[node * 2];
				nodes[node * 2]->_prev = _head._prev;
				_head._prev = nodes[node * 2];
				nodes[node * 2]->_next = &_head;
			}
			if (node * 2 + 1 < (long)nodes.size() && nodes[node * 2 + 1]->_key != null) {
				nodes[node * 2 + 1]->_parent = nodes[node];
				nodes[node]->_right = nodes[node * 2 + 1];
				_size += 1;
				_head._prev->_next = nodes[node * 2 + 1];
				nodes[node * 2 + 1]->_prev = _head._prev;
				_head._prev = nodes[node * 2 + 1];
				nodes[node * 2 + 1]->_next = &_head;
			}
		}

		// 删除空节点
		for (long i = 0; i < nodes.size(); i += 1) {
			if (nodes[i]->_key == null) {
				delete nodes[i];
			}
		}
	}
	void _Init() {
		_head._left = nullptr;
		_head._right = nullptr;
		_head._next = &_head;
		_head._prev = &_head;
		_size = 0;
	}

	virtual ~BinaryTree() {
		_Clear();
	}
	void _Clear() {
		for (Node *head = _head._prev; head != &_head; ) {
			Node *node = head;
			head = head->_prev;
			delete node;
		}
		_head._left = nullptr;
		_head._right = nullptr;
		_head._next = &_head;
		_head._prev = &_head;
		_size = 0;
	}

	BinaryTree(const BinaryTree &that) {
		_Init();
		_Copy(that);
	}
	BinaryTree &operator=(const BinaryTree &that) {
		if (this != &that) {
			_Clear(_head._right);
			_Copy(that);
		}
	}
	void _Copy(const BinaryTree &that) {
		queue<pair<const Node *, Node *>> level;
		level.push({ &that._head, &_head });

		while (level.empty() == false) {
			pair<const Node *, Node *> node = level.front();
			level.pop();

			if (node.first->_left != nullptr) {
				node.second->_left = new Node(node.first->_left->_key, node.first->_left->_value);
				node.second->_left->_parent = node.second;
				_size += 1;
				_head._prev->_next = node.second->_left;
				node.second->_left->_prev = _head._prev;
				_head._prev = node.second->_left;
				node.second->_left->_next = &_head;
				level.push({ node.first->_left, node.second->_left });
			}
			if (node.first->_right != nullptr) {
				node.second->_right = new Node(node.first->_right->_key, node.first->_right->_value);
				node.second->_right->_parent = node.second;
				_size += 1;
				_head._prev->_next = node.second->_right;
				node.second->_right->_prev = _head._prev;
				_head._prev = node.second->_right;
				node.second->_right->_next = &_head;
				level.push({ node.first->_right, node.second->_right });
			}
		}
	}

	void _Next(ostream &os) {
		for (Node *iter = _head._next; iter != &_head; iter = iter->_next) {
			os << (*iter);
		}
	}
	void _Prev(ostream &os) {
		for (Node *iter = _head._prev; iter != &_head; iter = iter->_prev) {
			os << (*iter);
		}
	}

	void _Preorder_Recursion(ostream &os) {
		__Preorder_Recursion(os, _head._right);
		os << std::endl;
	}
	void __Preorder_Recursion(ostream &os, Node *root) {
		if (root == nullptr) {
			return;
		}
		os << (*root);
		__Preorder_Recursion(os, root->_left);
		__Preorder_Recursion(os, root->_right);
	}

	void _Inorder_Recursion(ostream &os) {
		__Inorder_Recursion(os, _head._right);
		os << std::endl;
	}
	void __Inorder_Recursion(ostream &os, Node *root) {
		if (root == nullptr) {
			return;
		}
		__Inorder_Recursion(os, root->_left);
		os << (*root);
		__Inorder_Recursion(os, root->_right);
	}

	void _Postorder_Recursion(ostream &os) {
		__Postorder_Recursion(os, _head._right);
		os << std::endl;
	}
	void __Postorder_Recursion(ostream &os, Node *root) {
		if (root == nullptr) {
			return;
		}
		__Postorder_Recursion(os, root->_left);
		__Postorder_Recursion(os, root->_right);
		os << (*root);
	}

	void _Preorder_Nonrecursion(ostream &os) {
		Node *root = _head._right;
		if (root == nullptr) {
			return;
		}
		stack<Node *> stack;
		stack.push(root);
		while (stack.empty() == false) {
			Node *curr = stack.top();
			stack.pop();
			os << (*curr);
			if (curr->_right != nullptr) {
				stack.push(curr->_right);
			}
			if (curr->_left != nullptr) {
				stack.push(curr->_left);
			}
		}
	}

	void _Inorder_Nonrecursion(ostream &os) {
		Node *root = _head._right;
		if (root == nullptr) {
			return;
		}
		stack<Node*> stack;
		while (root != nullptr) {
			stack.push(root);
			root = root->_left;
		}
		while (stack.empty() == false) {
			Node *curr = stack.top();
			stack.pop();
			os << (*curr);
			root = curr->_right;
			while (root != nullptr) {
				stack.push(root);
				root = root->_left;
			}
		}
	}

	void _Postorder_Nonrecursion(ostream &os) {
		Node *root = _head._right;
		if (root == nullptr) {
			return;
		}
		stack<Node *> temp;
		stack<Node *> stack;
		temp.push(root);
		while (temp.empty() == false) {
			root = temp.top();
			temp.pop();
			stack.push(root);
			if (root->_left != nullptr) {
				temp.push(root->_left);
			}
			if (root->_right != nullptr) {
				temp.push(root->_right);
			}
		}
		while (stack.empty() == false) {
			Node *curr = stack.top();
			stack.pop();
			os << (*curr);
		}
	}

	void _Levelorder(ostream &os) {
		Node *root = _head._right;
		if (root == nullptr) {
			return;
		}
		queue<Node *> level;
		level.push(root);
		while (level.empty() == false) {
			Node *curr = level.front();
			level.pop();
			if (curr->_left != nullptr) {
				level.push(curr->_left);
			}
			if (curr->_right != nullptr) {
				level.push(curr->_right);
			}
			os << (*curr);
		}
	}

	long _Height() {
		return __Height(_head._right);
	}
	long __Height(Node *tree) {
		if (tree == nullptr) {
			return 0;
		}
		long height_left = __Height(tree->_left);
		long height_right = __Height(tree->_right);
		return (1 + (height_left < height_right ? height_right : height_left));
	}

	CircularDoublyLinkedIterator _Search(const Key_ &key) {
		Node *rparent = nullptr;
		Node **rtree = nullptr;
		__Search(key, rparent, rtree);
		if ((*tree) == nullptr) {
			return CircularDoublyLinkedIterator(&_head);
		}
		return CircularDoublyLinkedIterator(*rtree);
	}
	void __Search(const Key_ &key, Node *&rparent, Node **&rtree) {
		Node *parent = &_head;
		Node **tree = &_head._right;
		while ((*tree) != nullptr) {
			if (_compare(key, (*tree)->_key) < 0) {
				parent = (*tree);
				tree = &((*tree)->_left);
			} else if (_compare(key, (*tree)->_key) > 0) {
				parent = (*tree);
				tree = &((*tree)->_right);
			} else {
				break;
			}
		}
		rparent = parent;
		rtree = tree;
		return;
	}

	Node **__Insert(const Key_ &key) {
		Node *rparent = nullptr;
		Node **rtree = nullptr;
		__Search(key, rparent, rtree);
		if ((*rtree) == nullptr) {
			Node *node = new Node(key, Value_());
			node->_parent = rparent;
			(*rtree) = node;
			_size += 1;

			if (rparent->_left == node) {
				rparent->_prev->_next = node;
				node->_prev = rparent->_prev;
				rparent->_prev = node;
				node->_next = rparent;
			} else if (rparent->_right == node) {
				rparent->_next->_prev = node;
				node->_next = rparent->_next;
				rparent->_next = node;
				node->_prev = rparent;
			}
		}
		return rtree;
	}
	Value_ &operator[](const Key_ &key) {
		Node **node = __Insert(key);
		return (*node)->_value;
	}

	bool _Put(const Key_ &key, const Value_ &value) {
		long size = _size;
		operator[](key) = value;
		if (size == _size) {
			return true;
		}
		return false;
	}

	Value_ _Get(const Key_ &key, const Value_ &hold) {
		Node *rparent = nullptr;
		Node **rtree = nullptr;
		__Search(key, rparent, rtree);
		if ((*rtree) == nullptr) {
			return hold;
		}
		return (*rtree)->_value;
	}

	bool _Erase(const Key_ &key) {
		Node *rparent = nullptr;
		Node **rtree = nullptr;
		__Search(key, rparent, rtree);
		if ((*rtree) != nullptr) {
			_Wipe(rtree);
			return true;
		}
		return false;
	}
	void _Wipe(Node **tree) {
		Node *wipe = (*tree);
		if ((*tree)->_left == nullptr) {          // 待删除节点的左子树为空
			if ((*tree)->_right != nullptr) {
				(*tree)->_right->_parent = (*tree)->_parent;
			}
			(*tree) = (*tree)->_right;
		} else if ((*tree)->_right == nullptr) {  // 待删除节点的右子树为空
			if ((*tree)->_left != nullptr) {
				(*tree)->_left->_parent = (*tree)->_parent;
			}
			(*tree) = (*tree)->_left;
		} else {                                  // 待删除节点的左右子树不为空
			Node **refer = &(*tree)->_right;
			while ((*refer)->_left != nullptr) {
				refer = &(*refer)->_left;
			}
			Node *take = (*refer);
			if ((*refer)->_right != nullptr) {
				(*refer)->_right->_parent = (*refer)->_parent;
			}
			(*tree)->_left->_parent = take;
			(*tree)->_right->_parent = take;
			take->_parent = (*tree)->_parent;
			(*refer) = (*refer)->_right;
			take->_left = (*tree)->_left;
			take->_right = (*tree)->_right;
			(*tree) = take;
		}
		_size -= 1;
		wipe->_prev->_next = wipe->_next;
		wipe->_next->_prev = wipe->_prev;
		delete wipe;
	}

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
	InorderIterator &_Erase(InorderIterator &iter) {
		if (iter._curr == nullptr) {  // end
			return iter;
		}
		Node *node = iter._curr;
		++iter;

		Node **tree = nullptr;
		if (node->_parent->_left == node) {
			tree = &(node->_parent->_left);
		} else if (node->_parent->_right == node) {
			tree = &(node->_parent->_right);
		}
		_Wipe(tree);
		return iter;
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

	CircularDoublyLinkedIterator _CircularDoublyLinked_Next_Begin() {
		return CircularDoublyLinkedIterator(_head._next);
	}
	CircularDoublyLinkedIterator _CircularDoublyLinked_Next_End() {
		return CircularDoublyLinkedIterator(&_head);
	}
	CircularDoublyLinkedIterator _CircularDoublyLinked_Prev_Begin() {
		return CircularDoublyLinkedIterator(_head._prev);
	}
	CircularDoublyLinkedIterator _CircularDoublyLinked_Prev_End() {
		return CircularDoublyLinkedIterator(&_head);
	}
	CircularDoublyLinkedIterator &_Erase(CircularDoublyLinkedIterator &iter) {
		if (iter._curr == &_head) {  // end
			return iter;
		}
		Node *node = iter._curr;
		++iter;

		Node **tree = nullptr;
		if (node->_parent->_left == node) {
			tree = &(node->_parent->_left);
		} else if (node->_parent->_right == node) {
			tree = &(node->_parent->_right);
		}
		_Wipe(tree);
		return iter;
	}
};

void _Test_Preorder_Recursion() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Preorder_Recursion(std::cout);
	std::cout << std::endl;
}

void _Test_Inorder_Recursion() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Inorder_Recursion(std::cout);
	std::cout << std::endl;
}

void _Test_Postorder_Recursion() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Postorder_Recursion(std::cout);
	std::cout << std::endl;
}

void _Test_Preorder_Nonrecursion() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Preorder_Nonrecursion(std::cout);
	std::cout << std::endl;
}

void _Test_Inorder_Nonrecursion() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Inorder_Nonrecursion(std::cout);
	std::cout << std::endl;
}

void _Test_Postorder_Nonrecursion() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Postorder_Nonrecursion(std::cout);
	std::cout << std::endl;
}

void _Test_Levelorder() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Levelorder(std::cout);
	std::cout << std::endl;
}

void _Test_PreorderIterator() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Inorder_Recursion(std::cout);

	for (BinaryTree<double, double>::PreorderIterator iter = tree._Preorder_Begin(); iter != tree._Preorder_End(); ++iter) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
}

/*
	N
	 \
	  5
	 / \
	2   8
   /\   /\
  N  3 7  N
*/
void _Test_InorderIterator() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Inorder_Recursion(std::cout);

	for (BinaryTree<double, double>::InorderIterator iter = tree._Inorder_Begin(); iter != tree._Inorder_End(); ++iter) {
		std::cout << (*iter);
	}
	std::cout << std::endl;

	long i = 0;
	for (BinaryTree<double, double>::InorderIterator iter = tree._Inorder_Begin(); iter != tree._Inorder_End(); ) {
		if (i == 0) {
			iter = tree._Erase(iter);
		} else {
			std::cout << (*iter);
			++iter;
		}
		i += 1;
	}
	std::cout << std::endl;

	for (BinaryTree<double, double>::Node *iter = tree._head._next; iter != &tree._head; iter = iter->_next) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
	for (BinaryTree<double, double>::Node *iter = tree._head._prev; iter != &tree._head; iter = iter->_prev) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
}

void _Test_PostorderIterator() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Inorder_Recursion(std::cout);

	for (BinaryTree<double, double>::PostorderIterator iter = tree._Postorder_Begin(); iter != tree._Postorder_End(); ++iter) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
}

void _Test_LevelorderIterator() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Inorder_Recursion(std::cout);

	for (BinaryTree<double, double>::LevelorderIterator iter = tree._Levelorder_Begin(); iter != tree._Levelorder_End(); ++iter) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
}

void _Test_CircularDoublyLinkedIterator() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Inorder_Recursion(std::cout);

	long i = 0;
	for (BinaryTree<double, double>::CircularDoublyLinkedIterator iter = tree._CircularDoublyLinked_Next_Begin(); iter != tree._CircularDoublyLinked_Next_End(); ) {
		if (i == 0) {
			iter = tree._Erase(iter);
		} else {
			std::cout << (*iter);
			++iter;
		}
		i += 1;
	}
	std::cout << std::endl;

	for (BinaryTree<double, double>::CircularDoublyLinkedIterator iter = tree._CircularDoublyLinked_Next_Begin(); iter != tree._CircularDoublyLinked_Next_End(); ++iter) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
	for (BinaryTree<double, double>::CircularDoublyLinkedIterator iter = tree._CircularDoublyLinked_Prev_Begin(); iter != tree._CircularDoublyLinked_Prev_End(); --iter) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
}

void _Test_Copy() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	BinaryTree<double, double> that = tree;
	that._Inorder_Recursion(std::cout);
	std::cout << that._size << std::endl;

	for (BinaryTree<double, double>::CircularDoublyLinkedIterator iter = tree._CircularDoublyLinked_Next_Begin(); iter != tree._CircularDoublyLinked_Next_End(); ++iter) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
	for (BinaryTree<double, double>::CircularDoublyLinkedIterator iter = tree._CircularDoublyLinked_Prev_Begin(); iter != tree._CircularDoublyLinked_Prev_End(); --iter) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
}

void _Test_Height() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Inorder_Recursion(std::cout);

	std::cout << tree._Height() << std::endl;
}

/*
	N
	 \
	  5
	 / \
	2   8
   /\   /\
  N  3 7  N
*/
void _Test_Put() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Inorder_Recursion(std::cout);

	tree._Put(1, 1);
	//tree[4] = 4;
	std::cout << tree._size << std::endl;
	tree._Inorder_Recursion(std::cout);

	for (BinaryTree<double, double>::CircularDoublyLinkedIterator iter = tree._CircularDoublyLinked_Next_Begin(); iter != tree._CircularDoublyLinked_Next_End(); ++iter) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
	for (BinaryTree<double, double>::CircularDoublyLinkedIterator iter = tree._CircularDoublyLinked_Prev_Begin(); iter != tree._CircularDoublyLinked_Prev_End(); --iter) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
}

void _Test_Get() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Inorder_Recursion(std::cout);

	double value1 = tree._Get(4, long());
	std::cout << value1 << std::endl;
	double value2 = tree._Get(8, long());
	std::cout << value2 << std::endl;
}

void _Test_Erase() {
	double null = INT_MAX;
	BinaryTree<double, double> tree = vector<double>{
		null, 5, 2, 8, null, 3, 7, null
	};
	tree._Inorder_Recursion(std::cout);

	tree._Erase(5);
	tree._Inorder_Recursion(std::cout);
}

int main() {
	// _Test_Preorder_Recursion();
	// _Test_Inorder_Recursion();
	// _Test_Postorder_Recursion();

	// _Test_Preorder_Nonrecursion();
	// _Test_Inorder_Nonrecursion();
	// _Test_Postorder_Nonrecursion();
	// _Test_Levelorder();

	// _Test_PreorderIterator();
	// _Test_InorderIterator();
	// _Test_PostorderIterator();
	// _Test_LevelorderIterator();
	// _Test_CircularDoublyLinkedIterator();

	// _Test_Copy();
	// _Test_Height();

	// _Test_Put();
	// _Test_Get();
	_Test_Erase();

	return 0;
}
