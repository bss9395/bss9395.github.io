/*Red-Blue_Tree.cpp
* Author: BSS9395
* Update: 2010-03-13T02:35:00+08@China-Guangdong-Zhanjiang+08
* Structure: Red-Blue_Tree
*/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

/* 5 Properties of Red-Blue Tree:
1. Each node is either Red or Blue;
2. The root node is Blue(strict) or Red(flexible). This rule is sometimes omitted, since the root can always be changed from Red to Blue, but not necessarily vice versa, this has rule little effect on analysis.
3. All leaves(Nil) are Blue;
4. If a node is Red, then both its childen are Blue.
5. Every path from a given node to any of its descendant Nil nodes goes through the same number of black nodes.
*/

/* insert_node: a total of 3 cases, other cases are impossible, all Nil nodes have color Blue.
note that a node to be inserted then to be adjusted must have a Red parent node, and property 5 must be mantained.
--------------------------------------------------------------------------------

case 1: bottom Red is to be inserted, top Blu must be a Blue node or a Root node, bottom Blu must be a Nil node, or a Blue node(case 1, recursively) with child nodes.
	   Blu                          Red                  Blu        (upper Red changes its color to Blue)
	   / \                          / \                  / \
	 Red Blu  right_rotate=>      Red Blu      =>      Red Red      (top Blu changes its color to Red)
	 / \                         / |   | \            / |   | \
   Red Nil                    Nil Nil Nil Blu      Nil Nil Nil Blu
   / \
Nil Nil

  Blu                             Red                  Blu        (upper Red changes its color to Blue)
  / \                             / \                  / \
Blu Red      left_rotate=>      Blu Red      =>      Red Red      (top Blu changes its color to Red)
	/ \                        / |   | \            / |   | \
  Nil Red                   Blu Nil Nil Nil      Blu Nil Nil Nil
	  / \
	Nil Nil

--------------------------------------------------------------------------------

case 2: bottom Red is to be inserted, top Blu must be a Blue node or a Root node, bottom Blu must be a Nil node, or a Blue node(case 1, recursively) with child nodes.
	Blu                         Blu                          Red                  Blu        (upper Red changes its color to Blue)
	/ \                         / \                          / \                  / \
  Red Blu  left_rotate=>      Red Blu  right_rotate=>      Red Blu      =>      Red Red      (top Blu changes its color to Red)
  / \                         / \                         / |   | \            / |   | \
Nil Red                     Red Nil                    Nil Nil Nil Blu      Nil Nil Nil Blu
	/ \                     / \
  Nil Nil                 Nil Nil

  Blu                        Blu                             Red                  Blu        (upper Red changes its color to Blue)
  / \                        / \                             / \                  / \
Blu Red    right_rotate=>  Blu Red      left_rotate=>      Blu Red      =>      Red Red      (top Blu changes its color to Red)
	/ \                        / \                        / |   | \            / |   | \
  Red Nil                    Nil Red                   Blu Nil Nil Nil      Blu Nil Nil Nil
  / \                            / \
Nil Nil                        Nil Nil

--------------------------------------------------------------------------------
[recursively]
case 3£ºbottom Red is to be inserted, Blu must be a Blue node or a Root node, right Red must be a Nil node, or a Red node with Nil child nodes, or a Red node(case 1, recursively) with child nodes.
	   Blu             [Red]   (Blu changes its color to Red, then propagates upwards)
	   / \              / \
	 Red Red  =>      Blu Blu  (left Red and right Red both change their color to Blue)
	 / \              / \
   Red Nil          Red Nil    (property 5 must be maintained after inserting a Red node)
   / \              / \
Nil Nil           Nil Nil

  Blu             [Red]       (Blu changes its color to Red, then propagates upwards)
  / \              / \
Red Red      =>  Blu Blu      (left Red and right Red both change their color to Blue)
	/ \              / \
  Nil Red          Nil Red    (property 5 must be maintained after inserting a Red node)
	  / \              / \
	Nil Nil          Nil Nil

--------------------------------------------------------------------------------
*/

/* remove_node: a total of 6 cases, other cases are impossible, all Nil nodes have color Blue.
note that a node to be deleted must have one/two Nil child node(s), and property 5 must be mantained.
--------------------------------------------------------------------------------

case 1: Red is to be deleted, ¦Á must be a Nil node, or a Red node with two Nil child nodes.
	Blu         Blu
	/ \         / \
  Red  ¦Á  =>  Nil  ¦Á  (deleting Red has no impact on property 5)
  / \
Nil Nil

 Blu           Blu
 / \           / \
¦Á  Red    =>  ¦Á  Nil  (deleting Red has no impact on property 5)
   / \
 Nil Nil

--------------------------------------------------------------------------------

case 2: left Blu/right Blu is to be deleted, ¦Á has unknown color A, ¦Â must be a Blu node with no/one/two Red child nodes, or a Red with two Blue nodes.
	   ¦Á             ¦Á
	  / \           / \
	Blu  ¦Â  =>    Blu  ¦Â  (Red replaces left Blu, then changes its color to Blue)
	/ \           / \
  Red Nil       Nil Nil
  / \
Nil Nil

  ¦Á               ¦Á
 / \             / \
¦Â  Blu      =>  ¦Â  Blu    (Red replaces right Blu, then changes its color to Blue)
   / \             / \
 Nil Red         Nil Nil
	 / \
   Nil Nil

--------------------------------------------------------------------------------

case 3: left Blu/right Blu is to be deleted, ¦Á has unkown color A, ¦Â must be a Nil node, or a Red node with two Nil child nodes.
	   ¦Á                                Blu                   A         (right Blu changes its color to A)
	  / \                               / \                  / \
	Blu Blu       left_rotate=>        ¦Á  Red      =>      Blu Blu      (¦Á and Red both change their color to Blue)
   / |   | \                         / |   | \            / |   | \
Nil Nil  ¦Â Red                     Blu ¦Â  Nil Nil      Nil  ¦Â  Nil Nil  (left Blu is deleted)
		   / \  				   / \
		 Nil Nil			     Nil Nil

		¦Á                               Blu                    A        (left Blu changes its color to A)
	   / \                              / \                   / \
	 Blu Blu      right_rotate=>      Red  ¦Á        =>      Blu Blu     (Red and ¦Á both change their color to Blue)
	/ |   | \                        / |   | \             / |   | \
  Red ¦Â  Nil Nil                  Nil Nil  ¦Â Blu        Nil Nil  ¦Â Nil  (right Blu is deleted)
  / \                                        / \
Nil Nil                                    Nil Nil

--------------------------------------------------------------------------------

case 4: left Blu/right Blu is to be deleted, ¦Á has unkown color A, ¦Â must be a Nil node, or a Red node with two Nil child nodes.
	   ¦Á                              ¦Á                                 Red                 A       (Red changes its color to A)
	  / \                            / \                                / \                / \
	Blu Blu    right_rotate=>      Blu Red       left_rotate=>         ¦Á  Blu    =>      Blu Blu    (¦Á changes its color to Blue)
   / |   | \                      / |   | \                          / |   | \          / |   | \
Nil Nil Red ¦Â                  Nil Nil Nil Blu                    Blu Nil Nil ¦Â      Nil Nil Nil ¦Â  (left Blu is deleted)
		/ \                                / \                    / \
	  Nil Nil                            Nil  ¦Â                 Nil Nil

	 ¦Á                                ¦Á                             Red                   A         (Red changes its color to A)
	/ \                              / \                            / \                  / \
  Blu Blu      left_rotate=>      Red Blu       right_rotate=>    Blu  ¦Á         =>    Blu Blu      (¦Á changes its color to Blue)
 / |   | \                        / |   | \                      / |   | \            / |   | \
¦Â Red Nil Nil                  Blu Nil Nil Nil                  ¦Â Nil Nil Blu        ¦Â Nil Nil Nil  (right Blu is deleted)
  / \                          / \                                        / \
Nil Nil                       ¦Â  Nil                                    Nil Nil

--------------------------------------------------------------------------------
[recursively]
case 5: left Blu/right Blu is to be deleted, right Blu must have two Nil child nodes(if parent is Red, nonrecursively), or two Blue child nodes(if parent is Blue, recursively).
	  Red              Blu        |        Blu             [Blu]       (now top Blu is like a Blu to be deleted, but with two Nil child nodes, then propagates upwards)
	  / \              / \        |        / \              / \
	Blu Blu      =>  Nil Red      |      Blu Blu      =>  Nil Red      (left Blu is deleted, right Blu changes its color to Red)
   / |   | \              | \     |     / |   | \              | \
Nil Nil Nil Nil          Nil Nil  |  Nil Nil Nil Nil          Nil Nil

	  Red                  Blu    |        Blu                 [Blu]   (now top Blu is like a Blu to be deleted, but with two Nil child nodes, then propagates upwards)
	  / \                  / \    |        / \                  / \
	Blu Blu      =>      Red Nil  |      Blu Blu      =>      Red Nil  (right Blu is deleted, left Blu changes its color to Red)
   / |   | \            / |       |     / |   | \            / |
Nil Nil Nil Nil      Nil Nil      |  Nil Nil Nil Nil      Nil Nil

--------------------------------------------------------------------------------
[recursively]
case 6: left Blu/right Blu is to be deleted, top Blu must be a Blue node, or a Root node, ¦Á/¦Â/¦Ã/¦Ä must be a Nil node, or a Red Node with two Nil child nodes.
	  Blu                                   Red                    Blu      (Red changes its color to Blue)
	  / \                                   / \                    / \
	Blu Red        left_rotate=>          Blu Blu    =>          Red Blu    (top Blu changes its color to Red)
   / |   | \                             / |   | \              / |   | \
Nil Nil Blu Blu                       Blu Blu  ¦Ã  ¦Ä        [Blu] Blu  ¦Ã  ¦Ä  (now left Blu is like a Blu to be deleted)
	   / |   | \                     / |   | \              / |   | \
	  ¦Á  ¦Â   ¦Ã  ¦Ä                 Nil Nil  ¦Á  ¦Â          Nil Nil  ¦Á  ¦Â

		Blu                            Red                    Blu            (Red changes its color to Blue)
		/ \                            / \                    / \
	  Red Blu      right_rotate=>    Blu Blu          =>    Blu Red          (top Blu changes its color to Red)
	 / |   | \                      / |   | \              / |   | \
  Blu Blu Nil Nil                  ¦Ä  ¦Ã  Blu Blu          ¦Ä  ¦Ã  Blu [Blu]    (now right Blu is like a Blu to be deleted)
 / |   | \                              / |   | \              / |   | \
¦Ä  ¦Ã   ¦Â  ¦Á                            ¦Â  ¦Á  Nil Nil          ¦Â  ¦Á  Nil Nil

--------------------------------------------------------------------------------
*/

#include <math.h>
using ::pow;
using ::log2;

#include <iostream>
#include <string>
#include <string>
#include <queue>
#include <stack>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

typedef const char *Color;
typedef const char *Flip;
namespace EType {
	Color _Red = "Red";
	Color _Blue = "Blue";

	Flip _Hit = "Hit";
	Flip _Miss = "Miss";
}

template<typename Value>
class Node {
public:
	Node(const Value &value = Value(), const Color &color = EType::_Red, Node *left = nullptr, Node *right = nullptr)
		: _value(value), _color(color), _left(left), _right(right) {
		// cerr << __FUNCTION__ << endl;
	}

	~Node() {
		// cerr << __FUNCTION__ << endl;
	}

public:
	Value _value;
	Color _color;
	Node *_left;
	Node *_right;
};

template<typename Value>
class Tree {
	typedef Node<Value> Node;
	typedef Node **Element;

public:
	Tree(const Node &head = Node())
		: _head(head), _count(0) {
		_level = 5; /* according to property 5: _level < log2(_count + 1) + 2 */
		_power = 8; /* 2^(_level - 2) < (_count + 1) == _power */
		_stack = new Element[_level];
		_top = 0;
		// cerr << __FUNCTION__ << endl;
	}

	~Tree() {
		delete _stack;
		// cerr << __FUNCTION__ << endl;
	}

public:
	void preOrder(Node *tree = nullptr) {
		if (tree == nullptr) {
			tree = _head._right;
		}
		_preOrder(tree);
	}

	Node *minimum(Node *tree = nullptr) {
		if (tree == nullptr) {
			tree = _head._right;
		}
		if (tree != nullptr) {
			while (tree->_left != nullptr) {
				tree = tree->_left;
			}
		}

		return tree;
	}

	Node *maximum(Node *tree = nullptr) {
		if (tree == nullptr) {
			tree = _head._right;
		}
		if (tree != nullptr) {
			while (tree->_right != nullptr) {
				tree = tree->_right;
			}
		}

		return tree;
	}

	Node *search(const Value &value = Value()) {
		Node node = Node(value);
		Node *tree = _head._right;
		while (tree != nullptr) {
			if (node._value < tree->_value) {
				tree = tree->_left;
			}
			else if (tree->_value < node._value) {
				tree = tree->_right;
			}
			else {
				break;
			}
		}

		return tree;
	}

	/* for testing */
	Flip attach(const Value &value = Value(), Color color = EType::_Red) {
		Flip flip = EType::_Miss;
		Node *node = new Node(value, color);
		Node **tree = &_head._right;
		while ((*tree) != nullptr) {
			if (node->_value < (*tree)->_value) {
				tree = &(*tree)->_left;
			}
			else if ((*tree)->_value < node->_value) {
				tree = &(*tree)->_right;
			}
			else {
				flip = EType::_Hit;
				delete node;
				break;
			}
		}

		if (flip == EType::_Miss) {
			(*tree) = node;
			_count += 1;
			flip = EType::_Deal;
		}

		return flip;
	}

	/* for testing */
	Flip detach(const Value &value = Value()) {
		Flip flip = EType::_Miss;
		Node node = Node(value);
		Node **tree = &_head._right;
		while ((*tree) != nullptr) {
			if (node._value < (*tree)->_value) {
				tree = &(*tree)->_left;
			}
			else if ((*tree)->_value < node._value) {
				tree = &(*tree)->_right;
			}
			else {
				flip = EType::_Hit;
				break;
			}
		}

		if (flip == EType::_Hit) {
			Node *wipe = (*tree);
			if ((*tree)->_right != nullptr) {
				Node **refer = &(*tree)->_right;
				while ((*refer)->_left != nullptr) {
					refer = &(*refer)->_left;
				}

				if ((*tree)->_right == (*refer)) {
					(*tree) = (*refer);
				}
				else {
					Node *take = (*refer);
					(*refer) = (*refer)->_right;
					take->_left = (*tree)->_left;
					take->_right = (*tree)->_right;
					(*tree) = take;
				}
			}
			else {
				(*tree) = (*tree)->_left;
			}

			delete wipe;
			_count -= 1;
			flip = EType::_Deal;
		}

		return flip;
	}

	Flip insert(const Value &value = Value()) {
		Flip flip = EType::_Miss;
		Node *node = new Node(value);
		Node **tree = _search_node(*node);
		Node **parent = nullptr;
		Node **grand = nullptr;

		if ((*tree) == nullptr) {
			(*tree) = node;
			flip = EType::_Hit;

			while (_top > 1) {
				_top -= 1;
				parent = _stack[_top];
				if ((*parent)->_color == EType::_Red) {
					_top -= 1;
					grand = _stack[_top];
					if ((*parent)->_left == (*tree)) {
						if ((*grand)->_left == (*parent)) {
							if ((*grand)->_right == nullptr || (*grand)->_right->_color == EType::_Blue) {
								/* case 1: side rotate */
								_right_rotate(*grand);
								(*grand)->_color = EType::_Blue;
								(*grand)->_right->_color = EType::_Red;
								break;
							}
						}
						else {
							/* (*grand)->_right == (*parent) */
							if ((*grand)->_left == nullptr || (*grand)->_left->_color == EType::_Blue) {
								/* case 2: zigzag rotate */
								_right_left_rotate(*grand);
								(*grand)->_color = EType::_Blue;
								(*grand)->_left->_color = EType::_Red;
								break;
							}
						}
					}
					else {
						/* (*parent)->_right == (*tree) */
						if ((*grand)->_right == (*parent)) {
							if ((*grand)->_left == nullptr || (*grand)->_left->_color == EType::_Blue) {
								/* case 1: side rotate */
								_left_rotate(*grand);
								(*grand)->_color = EType::_Blue;
								(*grand)->_left->_color = EType::_Red;
								break;
							}
						}
						else {
							/* (*grand)->_left == (*parent) */
							if ((*grand)->_right == nullptr || (*grand)->_right->_color == EType::_Blue) {
								/* case 2: zigzag rotate */
								_left_right_rotate(*grand);
								(*grand)->_color = EType::_Blue;
								(*grand)->_right->_color = EType::_Red;
								break;
							}
						}
					}
					/* (*grand)->_left->_color == EType::_Red && (*grand)->_right->_color == EType::_Red */
					/* case 3: flip color */
					(*grand)->_color = EType::_Red;
					(*grand)->_left->_color = (*grand)->_right->_color = EType::_Blue;
					tree = grand;
				}
				else {
					break;
				}
			}
		}
		else {
			delete node;
			flip = EType::_Miss;
		}

		return flip;
	}

	Flip remove(const Value &value = Value()) {
		Flip flip = EType::_Miss;
		Node node = Node(value);
		Node **tree = _search_node(node);

		if ((*tree) != nullptr) {
			flip = EType::_Hit;

			Node *wipe = (*tree);
			if ((*tree)->_left == nullptr) {
				Color color = (*tree)->_color;
				(*tree) = (*tree)->_right;
				_removed_node(color, *tree);
			}
			else if ((*tree)->_right == nullptr) {
				Color color = (*tree)->_color;
				(*tree) = (*tree)->_left;
				_removed_node(color, *tree);
			}
			else {
				/* replace with succesor node */
				Node **refer = &(*tree)->_right;
				while ((*refer)->_left != nullptr) {
					_stack[_top] = refer;
					_top += 1;
					refer = &(*refer)->_left;
				}

				Node *take = (*refer);
				Color color = take->_color;
				(*refer) = (*refer)->_right;
				take->_color = (*tree)->_color;
				take->_left = (*tree)->_left;
				take->_right = (*tree)->_right;
				(*tree) = take;
				_removed_node(color, *refer);
			}

			delete wipe;
			_count -= 1;
		}

		return flip;
	}

public:
	void _visit(Node *node) {
		cerr << "[" << node->_value << ", " << node->_color << "] ";
	}

	void _preOrder(Node *tree) {
		if (tree != nullptr) {
			_visit(tree);
			_preOrder(tree->_left);
			_preOrder(tree->_right);
		}
	}

	void _left_rotate(Node *&tree) {
		Node *node = tree->_right;
		tree->_right = node->_left;
		node->_left = tree;
		tree = node;
	}

	void _right_rotate(Node *&tree) {
		Node *node = tree->_left;
		tree->_left = node->_right;
		node->_right = tree;
		tree = node;
	}

	void _left_right_rotate(Node *&tree) {
		Node *node = tree->_left;
		tree->_left = node->_right->_right;
		node->_right->_right = tree;
		tree = node->_right;
		node->_right = tree->_left;
		tree->_left = node;
	}

	void _right_left_rotate(Node *&tree) {
		Node *node = tree->_right;
		tree->_right = node->_left->_left;
		node->_left->_left = tree;
		tree = node->_left;
		node->_left = tree->_right;
		tree->_right = node;
	}

	Node **_search_node(const Node &node) {
		if (_power < (_count + 1)) {
			_level += 5;
			_power = (int)pow(2, _level - 2);
			delete _stack;
			_stack = new Element[_level];
		}
		_top = 0;

		Node **tree = &_head._right;
		while ((*tree) != nullptr) {
			_stack[_top] = tree;
			_top += 1;
			if (node._value < (*tree)->_value) {
				tree = &(*tree)->_left;
			}
			else if ((*tree)->_value < node._value) {
				tree = &(*tree)->_right;
			}
			else {
				break;
			}
		}

		return tree;
	}

	// obsolete function, only for teaching.
	enum Hint {
		_Miss = 1U << 1,
		_Hit = 1U << 2,
		_Left = 1U << 3,
		_Right = 1U << 4,
		_Deal = 1U << 5,
		_Recur = _Left | _Right,

		_Red = 1U << 6,
		_Blue = 1U << 7
	};
	Hint _insert_node_recursion(Node *&tree, Node *node) {
		Hint flip = Hint::_Miss;
		if (tree == nullptr) {
			tree = node;
			_count += 1;
			flip = Hint::_Hit;
		}
		else if (node->_value < tree->_value) {
			flip = _insert_node(tree->_left, node);
			if (flip == Hint::_Hit) {
				if (tree->_color == Hint::_Red) {
					flip = Hint::_Left;
				}
				else {
					flip = Hint::_Deal;
				}
			}
			else if (flip & Hint::_Recur) {
				if (tree->_right == nullptr || tree->_right->_color == Hint::_Blue) {
					if (flip == Hint::_Left) {
						_right_rotate(tree);
					}
					else {
						/* if (flip == Hint::_Right) */
						_left_right_rotate(tree);
					}
					tree->_color = Hint::_Blue;
					tree->_left->_color = tree->_right->_color = Hint::_Red;
					flip = ET::_Deal;
				}
				else {
					/* if (tree->_right != nullptr && tree->_right ->_color == Hint::_Red) */
					tree->_color = Hint::_Red;
					tree->_left->_color = tree->_right->_color = Hint::_Blue;
					flip = ET::_Hit;
				}
			}
		}
		else if (tree->_value < node->_value) {
			flip = _insert_node(tree->_right, node);
			if (flip == Hint::_Hit) {
				if (tree->_color == Hint::_Red) {
					flip = Hint::_Right;
				}
				else {
					flip = Hint::_Deal;
				}
			}
			else if (flip & Hint::_Recur) {
				if (tree->_left == nullptr || tree->_left->_color == Hint::_Blue) {
					if (flip == Hint::_Right) {
						_left_rotate(tree);
					}
					else {
						/* if (flip == Hint::_Left) */
						_right_left_rotate(tree);
					}
					tree->_color = Hint::_Blue;
					tree->_left->_color = tree->_right->_color = Hint::_Red;
					flip = ET::_Deal;
				}
				else {
					/* (*tree)->_right != nullptr && (*tree)->_right->_color == Hint::_Red) */
					tree->_color = Hint::_Red;
					tree->_left->_color = tree->_right->_color = Hint::_Blue;
					flip = Hint::_Hit;
				}
			}
		}
		else {
			delete node;
			flip = Hint::_Miss;
		}

		return flip;
	}

	void _removed_node(Color color, Node *node) {
		/* [node] is the child of [take], [take] is already replaced by [node] */
		if (color == EType::_Red) {
			/* case 01: take->_color == EType::_Red */
			// no operations
		}
		else if (node != nullptr) {
			/* case 02: take->_color == EType::_Blue && node->_color == EType::_Red */
			node->_color = EType::_Blue;
		}
		else {
			/* 4 cases: take->_color == EType::_Blue && node == nullptr */
			_top -= 1;
			while (_top >= 1) {
				_top -= 1;
				Node *&parent = *_stack[_top];
				if (parent->_left == node) {
					Node *sibling = parent->_right;
					if (sibling->_color == EType::_Blue) {
						if (sibling->_right != nullptr && sibling->_right->_color == EType::_Red) {
							/* case 03: sibling->_right->_color == EType::_Red */
							_left_rotate(parent);
							parent->_color = parent->_left->_color;
							parent->_left->_color = parent->_right->_color = EType::_Blue;
							break;
						}
						else if (sibling->_left != nullptr && sibling->_left->_color == EType::_Red) {
							/* case 04: sibling->_left->_color == EType::_Red */
							_right_left_rotate(parent);
							parent->_color = parent->_left->_color;
							parent->_left->_color = EType::_Blue;
							break;
						}
						else {
							/* case 05: (sibling->_left == nullptr && sibling->_right == nullptr) */
							/*       || (sibling->_left->_color == EType::_Blue && sibling->_right->_color == EType::_Blue) */
							sibling->_color = EType::_Red;
							if (parent->_color == EType::_Red) {
								parent->_color = EType::_Blue;
								break;
							}
						}
					}
					else {
						/* case 06: sibling->_color == EType::_Red */
						_left_rotate(parent);
						parent->_color = parent->_left->_color;
						parent->_left->_color = EType::_Red;
						_stack[_top + 0] = &parent;
						_stack[_top + 1] = &parent->_left;
						_top += 2;
					}
				}
				else {
					/* parent->_right == node */
					Node *sibling = parent->_left;
					if (sibling->_color == EType::_Blue) {
						if (sibling->_left != nullptr && sibling->_left->_color == EType::_Red) {
							/* case 03: sibling->_right->_color == EType::_Red */
							_right_rotate(parent);
							parent->_color = parent->_right->_color;
							parent->_left->_color = parent->_right->_color = EType::_Blue;
							break;
						}
						else if (sibling->_right != nullptr && sibling->_right->_color == EType::_Red) {
							/* case 04: sibling->_left->_color == EType::_Red */
							_left_right_rotate(parent);
							parent->_color = parent->_right->_color;
							parent->_right->_color = EType::_Blue;
							break;
						}
						else {
							/* case 05: (sibling->_left == nullptr && sibling->_right == nullptr) */
							/*       || (sibling->_left->_color == EType::_Blue && sibling->_right->_color == EType::_Blue) */
							sibling->_color = EType::_Red;
							if (parent->_color == EType::_Red) {
								parent->_color = EType::_Blue;
								break;
							}
						}
					}
					else {
						/* case 06: sibling->_color == EType::_Red */
						_right_rotate(parent);
						parent->_color = parent->_right->_color;
						parent->_right->_color = EType::_Red;
						_stack[_top + 0] = &parent;
						_stack[_top + 1] = &parent->_right;
						_top += 2;
					}
				}
			}
		}
	}

public:
	Node _head;
	int _count;

	int _level;
	int _power;
	Element *_stack;
	int _top;
};

#define Main
#ifdef Main
int main(int argc, char *argv[]) {
	Tree<string> tree;
	tree.insert("9");
	tree.insert("4");
	tree.insert("1");
	tree.insert("5");
	tree.insert("3");
	tree.insert("2");
	tree.insert("7");
	tree.insert("6");
	tree.insert("8");
	tree.insert("0");

	tree.remove("0");
	tree.remove("6");
	tree.remove("8");
	tree.remove("1");
	tree.remove("2");
	tree.remove("3");
	tree.remove("9");
	tree.remove("4");
	tree.remove("5");
	tree.remove("7");

	tree.preOrder();

	return 0;
}
#endif // Main
