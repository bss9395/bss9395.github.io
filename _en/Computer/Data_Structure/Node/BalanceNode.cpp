/* BalanceNode.cpp
Author: BSS9395
Update: 2018-07-02T19:16:00 +08
*/

#ifndef BalanceNode_h
#define BalanceNode_h

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <string>
using std::string;

template <typename T>
class BalanceNode {
	friend auto operator<<(ostream &os, const BalanceNode &node) -> ostream & {
		os << node._element;
		return os;
	}
	friend auto operator<(const BalanceNode &lhs, const BalanceNode &rhs) {
		return (lhs._element < rhs._element);
	}
	friend auto operator==(const BalanceNode &lhs, const BalanceNode &rhs) {
		return (lhs._element == rhs._element);
	}
	friend auto operator!=(const BalanceNode &lhs, const BalanceNode &rhs) {
		return !operator==(lhs, rhs);
	}
	friend auto operator>(const BalanceNode &lhs, const BalanceNode &rhs) {
		return (lhs._element > rhs._element);
	}
public:
	BalanceNode(const T &element = T(), long balance = 0, BalanceNode *left = nullptr, BalanceNode *right = nullptr)
		: _element(element), _balance(balance), _left(left), _right(right) {

	}
	BalanceNode(const BalanceNode &node)
		: _element(node._element), _balance(node._balance), _left(node._left), _right(node._right) {

	}
	auto operator=(const BalanceNode &node) {
		if (this != &node) {
			_clear();
			_element = node._element;
			_balance = node._balance;
			_left = node._left;
			_right = node._right;
		}
		return *this;
	}
	~BalanceNode() {
		_clear();
	}
protected:
	auto _clear() -> void {
		_element.~T();
	}
public:
	T _element;
	long _balance;
	BalanceNode *_left;
	BalanceNode *_right;
};

template class BalanceNode<string>;

#endif // BalanceNode_h
