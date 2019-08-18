/* ListNode.cpp
Author: BSS9395
Update: 2018-06-24T22:09:00 +08
*/

#ifndef ListNode_h
#define ListNode_h

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <string>
using std::string;

template<typename T>
class ListNode {
	friend auto operator<<(ostream &os, const ListNode &node) -> ostream & {
		os << node._element;
		return os;
	}
public:
	ListNode(const T &element = T(), ListNode *next = nullptr)
		:_element(element), _next(next) {

	}
	ListNode(const ListNode &node)
		:_element(node._element), _next(node._next) {

	}
	auto operator=(const ListNode &node) -> ListNode & {
		if (this != &node) {
			_clear();
			_element = node._element;
			_next = node._next;
		}
		return *this;
	}
	virtual ~ListNode() {
		_clear();
	}
protected:
	auto _clear()->void {
		_element.~T();
	}
public:
	T _element;
	ListNode *_next;
};

template class ListNode<string>;
#endif //ListNode_h
