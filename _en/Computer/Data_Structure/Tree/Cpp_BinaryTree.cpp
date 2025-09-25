/* Cpp_BinaryTree.cpp
Author: bss9395
Update: 2025/09/23T21:26:00+08@China-GuangDong-ZhanJiang+08
*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Person {
	string _name = "";
	int _age = 0;

	Person() {

	}
	Person(const string& name, int age) {
		_name = name;
		_age = age;
	}

	friend bool operator==(const Person &lhs, const Person &rhs) {
		return (lhs._name == rhs._name && lhs._age == rhs._age);
	}
	friend bool operator!=(const Person &lhs, const Person &rhs) {
		return !(lhs._name == rhs._name && lhs._age == rhs._age);
	}

	friend bool operator <(const Person &lhs, const Person &rhs) {
		return (lhs._age < rhs._age);
	}

	friend ostream &operator<<(ostream &os, const Person &that) {
		os << "Datum{" << that._name << ", " << that._age << "}";
		return os;
	}
};

template<typename Datum>
class BinaryTree {
public:
	struct Node {
		Node *_parent = nullptr;
		Node *_left = nullptr;
		Node *_right = nullptr;
		Datum _datum;

		explicit Node(const Datum &datum) {
			_datum = datum;
		}
	};
	Node _root = Node(Datum("", 0));
	int _size = 0;

	BinaryTree(const vector<Datum> data) {
		vector<Node*> nodes;
		for (int i = 0; i < data.size(); i += 1) {
			nodes.push_back(new Node(data[i]));
		}

		const Datum Null = data[0];
		for (int node = 0, end = (int)data.size() / 2; node <= end; node += 1) {
			if (node * 2 < data.size() && nodes[node * 2]->_datum != Null) {
				nodes[node * 2]->_parent = nodes[node];
				nodes[node]->_left = nodes[node * 2];
				_size += 1;
			} 
			if (node * 2 + 1 < data.size() && nodes[node * 2 + 1]->_datum != Null) {
				nodes[node * 2 + 1]->_parent = nodes[node];
				nodes[node]->_right = nodes[node * 2 + 1];
				_size += 1;
			}
		}
		_root._datum = Null;
		_root._left = nullptr;
		nodes[0]->_right->_parent = &_root;
		_root._right = nodes[0]->_right;
		delete nodes[0];
	}

	BinaryTree(const BinaryTree &that) {
		_Copy(that);
	}
	BinaryTree &operator=(const BinaryTree &that) {
		if (this != &that) {
			_Clear(_root._right);
			_Copy(that);
		}
	}
	void _Copy(const BinaryTree &that) {
		queue<pair<const Node *, Node *>> level;
		level.push({ &that._root, &_root });

		while (level.empty() == false) {
			pair<const Node *, Node *> node = level.front();
			level.pop();

			if (node.first->_left != nullptr) {
				node.second->_left = new Node(node.first->_left->_datum);
				node.second->_left->_parent = node.second;
				level.push({ node.first->_left, node.second->_left });
			}
			if (node.first->_right != nullptr) {
				node.second->_right = new Node(node.first->_right->_datum);
				node.second->_right->_parent = node.second;
				level.push({ node.first->_right, node.second->_right });
			}
		}
		_size = that._size;
	}
	
	virtual ~BinaryTree() {
		_Clear(_root._right);
	}
	void _Clear(Node *tree) {
		queue<Node *> level;
		level.push(tree);
		while (level.empty() == false) {
			Node *node = level.front();
			level.pop();

			if (node->_left != nullptr) {
				level.push(node->_left);
			}
			if (node->_right != nullptr) {
				level.push(node->_right);
			}
			delete node;
		}
	}

public:
	int _Height() {
		return _Height_Node(_root._right);
	}
	int _Height_Node(Node* tree) {
		if (tree == nullptr) {
			return 0;
		}
		int heightLeft = _Height_Node(tree->_left);
		int heightRight = _Height_Node(tree->_right);
		return (1 + (heightLeft < heightRight ? heightRight : heightLeft));
	}

	void _Insert(Datum datum) {
		Node *node = new Node(datum);
		_Insert_Node(&_root, _root._right, node);
	}
	void _Insert_Node(Node *parent, Node *&tree, Node *node) {
		if (tree == nullptr) {
			tree = node;
			node->_parent = parent;
			_size += 1;
		} else if (node->_datum < tree->_datum) {
			_Insert_Node(tree, tree->_left, node);
		} else if (tree->_datum < node->_datum) {
			_Insert_Node(tree, tree->_right, node);
		} else {
			delete node;
		}
	}

	void _Insert_Search(Datum datum) {
		Node *node = new Node(datum);
		Node *parent = &_root;
		Node *tree = _root._right;
		while (tree != nullptr) {
			if (node->_datum < tree->_datum) {
				parent = tree;
				tree = tree->_left;					
			} else if (tree->_datum < node->_datum) {
				parent = tree;
				tree = tree->_right;				
			} else {
				delete node;
				return;
			}
		}
		if (parent == &_root) {
			node->_parent = parent;
			parent->_right = node;	
		} else if (node->_datum < parent->_datum) {
			node->_parent = parent;
			parent->_left = node;
			
		} else if (parent->_datum < node->_datum) {
			node->_parent = parent;
			parent->_right = node;			
		}
		_size += 1;
	}

	void _Erase(Datum datum) {
		Node node = Node(datum);
		Node **tree = &_root._right;
		while (tree != nullptr) {
			if (node._datum < (*tree)->_datum) {
				tree = &(*tree)->_left;
			} else if ((*tree)->_datum < node._datum) {
				tree = &(*tree)->_right;
			} else {
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
				delete wipe;
				_size -= 1;
				return;
			}
		}
	}

	void _Travel_Preorder() {
		_Travel_Preorder_Node(_root._right);
	}
	void _Travel_Preorder_Node(Node *node) {
		if (node != nullptr) {
			cout << node->_parent->_datum << " | " << node->_datum << endl;
			_Travel_Preorder_Node(node->_left);
			_Travel_Preorder_Node(node->_right);
		}
	}

	void _Travel_Inorder() {
		_Travel_Inorder_Node(_root._right);
	}
	void _Travel_Inorder_Node(Node *node) {
		if (node != nullptr) {
			_Travel_Inorder_Node(node->_left);
			cout << node->_parent->_datum << " | " << node->_datum << endl;
			_Travel_Inorder_Node(node->_right);
		}
	}

	void _Travel_Postorder() {
		_Travel_Postorder_Node(_root._right);
	}
	void _Travel_Postorder_Node(Node *node) {
		if (node != nullptr) {			
			_Travel_Postorder_Node(node->_left);
			_Travel_Postorder_Node(node->_right);
			cout << node->_parent->_datum << " | " << node->_datum << endl;
		}
	}

	void _Travel_Levelorder() {
		queue<Node *> level;
		level.push(_root._right);
		Node *node = nullptr;
		while (level.empty() == false) {
			node = level.front();
			level.pop();
			if (node->_left != nullptr) {
				level.push(node->_left);
			}
			if (node->_right != nullptr) {
				level.push(node->_right);
			}
			cout << node->_parent->_datum << " | " << node->_datum << endl;
		}
	}

	Node* _Search(Datum datum) {
		Node node = Node(datum);
		Node *tree = _root._right;
		while (tree != nullptr) {
			if (node._datum < tree->_datum) {
				tree = tree->_left;
			} else if (tree->_datum < node._datum) {
				tree = tree->_right;
			} else {
				return tree;
			}
		}
		return nullptr;
	}
	  
};

void _Test_Insert(BinaryTree<Person>& binaryTree) {
/*
		 40
		/ \
	  20   60
	 / |   | \
   10  30  50 70
       |      /
	   35    65
*/
	binaryTree._Insert(Person("brilliant-40", 40));
	binaryTree._Insert(Person("brilliant-20", 20));
	binaryTree._Insert(Person("brilliant-10", 10));
	binaryTree._Insert(Person("brilliant-30", 30));
	binaryTree._Insert(Person("brilliant-35", 35));
	binaryTree._Insert(Person("brilliant-60", 60));
	binaryTree._Insert(Person("brilliant-50", 50));
	binaryTree._Insert(Person("brilliant-70", 70));
	binaryTree._Insert(Person("brilliant-65", 65));
}

void _Test_Insert_Search(BinaryTree<Person>& binaryTree) {
/*
		 40
		/ \
	  20   60
	 / |   | \
   10  30  50 70
	   |      /
	   35    65
*/
	binaryTree._Insert_Search(Person("brilliant-40", 40));
	binaryTree._Insert_Search(Person("brilliant-20", 20));
	binaryTree._Insert_Search(Person("brilliant-10", 10));
	binaryTree._Insert_Search(Person("brilliant-30", 30));
	binaryTree._Insert_Search(Person("brilliant-35", 35));
	binaryTree._Insert_Search(Person("brilliant-60", 60));
	binaryTree._Insert_Search(Person("brilliant-50", 50));
	binaryTree._Insert_Search(Person("brilliant-70", 70));
	binaryTree._Insert_Search(Person("brilliant-65", 65));
}

void _Test_Erase(BinaryTree<Person>& binaryTree) {
	binaryTree._Erase(Person("brilliant-40", 40));
}

void _Test_Travel_Preorder(BinaryTree<Person>& binaryTree) {
	binaryTree._Travel_Preorder();
}

void _Test_Travel_Inorder(BinaryTree<Person>& binaryTree) {
	binaryTree._Travel_Inorder();
}

void _Test_Travel_Postorder(BinaryTree<Person>& binaryTree) {
	binaryTree._Travel_Postorder();
}

void _Test_Travel_Levelorder(BinaryTree<Person>& binaryTree) {
	binaryTree._Travel_Levelorder();
}

void _Test_Search(BinaryTree<Person> &binaryTree) {
	BinaryTree<Person>::Node *node = binaryTree._Search(Person("brilliant-35", 35));
	if (node != nullptr) {
		cout << node->_parent->_datum << " | " << node->_datum << endl;
	} else {
		cout << "nullptr" << endl;
	}
}

void _Test_Size(BinaryTree<Person> &binaryTree) {
	cout << binaryTree._size << endl;
}

void _Test_Height(BinaryTree<Person> &binaryTree) {
	cout << binaryTree._Height() << endl;
}

int main(int argc, char *argv[]) {
/*
	     40
		/ \
	  20   60
	 / |   | \
   10  30  50 70
	   |      /
	  35    65
*/
	BinaryTree<Person> binaryTree({
		{"null", 0},         
		{"brilliant-40", 40},
		{"brilliant-20", 20}, 
		{"brilliant-60", 60}, 
		{"brilliant-10", 10}, 
		{"brilliant-30", 30}, 
		{"brilliant-50", 50}, 
		{"brilliant-70", 70}, 
		{"null", 0},
		{"brilliant-35", 35},
		{"null", 0},
		{"brilliant-65", 65},
	});
	// BinaryTree<Person> another(binaryTree);
	// _Test_Insert(binaryTree);
	// _Test_Insert_Search(binaryTree);
	_Test_Erase(binaryTree);
	// _Test_Search(binaryTree);
	// _Test_Travel_Preorder(binaryTree);
	// _Test_Travel_Inorder(binaryTree);
	_Test_Travel_Levelorder(binaryTree);
	// _Test_Travel_Postorder(binaryTree);
	// _Test_Size(binaryTree);
	// _Test_Height(binaryTree);

	return 0;
}