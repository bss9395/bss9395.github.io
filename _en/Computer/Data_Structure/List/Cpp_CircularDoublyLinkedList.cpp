/* Cpp_CircularDoublyLinkedList.cpp
Author: bss9395
Update: 2025/10/03T16:06:00+08@China-GuangDong-ZhanJiang+08
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

template<typename Datum_>
struct CircularDoublyLinkedList {
	struct Node {
		Datum_ _datum = Datum_();
		Node *_prev = nullptr;
		Node *_next = nullptr;

		Node() {

		}
		Node(const Datum_ &datum) {
			_datum = datum;
		}
		virtual ~Node() {

		}

		friend ostream &operator<<(ostream &os, const Node &that) {
			os << "{" << that._datum << "}";
			return os;
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

	static long _Compare(const Datum_ &lhs, const Datum_ &rhs) {
		if (lhs < rhs) {
			return -1;
		} else if (lhs > rhs) {
			return +1;
		}
		return 0;
	}

public:
	function<long(const Datum_ &, const Datum_ &)> _compare = _Compare;
	Node _head = Node();
	long _size = 0;

	CircularDoublyLinkedList() {
		_Init();
	}
	CircularDoublyLinkedList(const function<long(const Datum_ &, const Datum_ &)> &compare) {
		_Init();
		_compare = compare;
	}
	CircularDoublyLinkedList(const vector<Datum_> &data) {
		_Init();

		for (long i = 0; i < data.size(); i += 1) {
			Node *node = new Node(data[i]);
			_head._prev->_next = node;
			node->_prev = _head._prev;
			_head._prev = node;
			node->_next = &_head;
			_size += 1;
		}
	}
	void _Init() {
		_head._next = &_head;
		_head._prev = &_head;
		_size = 0;
	}

	virtual ~CircularDoublyLinkedList() {
		_Clear();
	}
	void _Clear() {
		for (Node *head = _head._prev; head != &_head; ) {
			Node *node = head;
			head = head->_prev;
			delete node;
		}
		_head._next = nullptr;
		_head._prev = nullptr;
		_size = 0;
	}

	CircularDoublyLinkedList(const CircularDoublyLinkedList &that) {
		_Init();
		_Copy(that);
	}
	CircularDoublyLinkedList &operator=(const CircularDoublyLinkedList &that) {
		if (this != &that) {
			_Clear();
			_Copy(that);
		}
	}
	void _Copy(const CircularDoublyLinkedList &that) {
		for (Node *iter = that._head._next; iter != &that._head; iter = iter->_next) {
			Node *node = new Node(iter->_datum);
			_head._prev->_next = node;
			node->_prev = _head._prev;
			_head._prev = node;
			node->_next = &_head;
			_size += 1;
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

	CircularDoublyLinkedIterator _Search(const Datum_ &datum) {
		Node *head = _head._next;
		for (; head != &_head && _compare(head->_datum, datum) != 0; head = head->_next);
		return CircularDoublyLinkedIterator(head);
	}
	CircularDoublyLinkedIterator _Search_Lower(const Datum_ &datum) {
		Node *head = _head._next;
		for (; head != &_head && _compare(head->_datum, datum) < 0; head = head->_next);
		return CircularDoublyLinkedIterator(head);
	}
	CircularDoublyLinkedIterator _Search_Upper(const Datum_ &datum) {
		Node *head = _head._next;
		for (; head != &_head && _compare(head->_datum, datum) <= 0; head = head->_next);
		return CircularDoublyLinkedIterator(head);
	}

	/*
	 0   1   2   3   4   5   6
	-6	-5	-4	-3	-2  -1   0
	 +---+---+---+---+---+---+
	 | P | y | t | h | o | n |
	 +---+---+---+---+---+---+
	*/
	CircularDoublyLinkedIterator _Insert_Index(long index, const Datum_ &datum) {
		Node *head = _head._next;
		if (_head._next != &_head) {
			long idx = (index + _size) % _size;
			for (int i = 0; i < idx; i += 1) {
				head = head->_next;
			}
		}
		Node *node = new Node(datum);
		head->_prev->_next = node;
		node->_prev = head->_prev;
		node->_next = head;
		head->_prev = node;
		_size += 1;
		return CircularDoublyLinkedIterator(node);
	}
	CircularDoublyLinkedIterator _Insert_Lower(const Datum_ &datum) {
		CircularDoublyLinkedIterator iter = _Search_Lower(datum);
		Node *head = iter._curr;
		Node *node = new Node(datum);
		head->_prev->_next = node;
		node->_prev = head->_prev;
		node->_next = head;
		head->_prev = node;
		_size += 1;
		return CircularDoublyLinkedIterator(node);
	}
	CircularDoublyLinkedIterator _Insert_Upper(const Datum_ &datum) {
		CircularDoublyLinkedIterator iter = _Search_Upper(datum);
		Node *head = iter._curr;
		Node *node = new Node(datum);
		head->_prev->_next = node;
		node->_prev = head->_prev;
		node->_next = head;
		head->_prev = node;
		_size += 1;
		return CircularDoublyLinkedIterator(node);
	}

	void _Attach_Fore(const Datum_ &datum) {
		Node *node = new Node(datum);
		_head._next->_prev = node;
		node->_next = _head._next;
		_head._next = node;
		node->_prev = &_head;
		_size += 1;
	}
	void _Attach_Back(const Datum_ &datum) {
		Node *node = new Node(datum);
		_head._prev->_next = node;
		node->_prev = _head._prev;
		_head._prev = node;
		node->_next = &_head;
		_size += 1;
	}

	Datum_ _Peek_Fore(const Datum_ &hold) {
		if (_head._next != &_head) {
			return _head._next->_datum;
		}
		return hold;
	}
	Datum_ _Peek_Back(const Datum_ &hold) {
		if (_head._next != &_head) {
			return _head._prev->_datum;
		}
		return hold;
	}
	Datum_ _Peek_Index(long index, const Datum_ &hold) {
		Node *head = _head._next;
		if (_head._next != &_head) {
			long idx = (index + _size) % _size;
			for (int i = 0; i < idx; i += 1) {
				head = head->_next;
			}
			return head->_datum;
		}
		return hold;
	}

	void _Detach_Fore() {
		if (_head._next != &_head) {
			Node *node = _head._next;
			_head._next = node->_next;
			node->_next->_prev = &_head;
			_size -= 1;
			delete node;
		}
	}
	void _Detach_Back() {
		if (_head._next != &_head) {
			Node *node = _head._prev;
			_head._prev = node->_prev;
			node->_prev->_next = &_head;
			_size -= 1;
			delete node;
		}
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

		_size -= 1;
		node->_prev->_next = node->_next;
		node->_next->_prev = node->_prev;
		delete node;
		return iter;
	}

	void _Merge_Ordered(CircularDoublyLinkedList &that) {
		if (that._head._next == &that._head) {
			return;
		}
		_head._prev->_next = nullptr;
		that._head._prev->_next = nullptr;
		Node *curr = &_head;
		Node *iter_this = _head._next;
		Node *iter_that = that._head._next;
		while (iter_this != nullptr && iter_that != nullptr) {
			if (_compare(iter_this->_datum, iter_that->_datum) <= 0) {
				curr->_next = iter_this;
				iter_this->_prev = curr;
				iter_this = iter_this->_next;
			} else {
				curr->_next = iter_that;
				iter_that->_prev = curr;
				iter_that = iter_that->_next;
			}
			curr = curr->_next;
		}
		if (iter_this != nullptr) {
			curr->_next = iter_this;
			iter_this->_prev = curr;
			for (; curr->_next != nullptr; curr = curr->_next);
		} else if (iter_that != nullptr) {
			curr->_next = iter_that;
			iter_that->_prev = curr;
			for (; curr->_next != nullptr; curr = curr->_next);
		}
		curr->_next = &_head;
		_head._prev = curr;
		_size += that._size;
		that._Init();
	}

	void _Merge_Multiple_Ordered(const vector<CircularDoublyLinkedList *> &lists) {
		typedef function<bool(const Node *, const Node *)> Compare;
		auto compare = [this](const Node *lhs, const Node *rhs) -> bool {
			if (_compare(lhs->_datum, rhs->_datum) > 0) {  // priority_queue为大根堆
				return true;
			}
			return false;
		};
		priority_queue<Node *, vector<Node *>, Compare> heap{ compare };

		// 入堆头节点
		if (_head._next != &_head) {
			_head._prev->_next = nullptr;
			heap.push(_head._next);
		}
		for (int i = 0; i < lists.size(); i += 1) {
			CircularDoublyLinkedList *list = lists[i];
			if (list->_head._next != &list->_head) {
				list->_head._prev->_next = nullptr;
				heap.push(list->_head._next);
			}
		}

		// 出堆头节点
		Node *curr = &_head;
		while (heap.empty() == false) {
			Node *node = heap.top();
			heap.pop();
			curr->_next = node;
			node->_prev = curr;
			curr = curr->_next;
			if (node->_next != nullptr) {
				heap.push(node->_next);
			}
		}
		curr->_next = &_head;
		_head._prev = curr;
		// 重置
		for (int i = 0; i < lists.size(); i += 1) {
			CircularDoublyLinkedList *list = lists[i];
			_size += list->_size;
			list->_Init();
		}
	}

	void _Merge_Multiple_Unordered(const vector<CircularDoublyLinkedList *> &lists) {
		typedef function<bool(const Node *, const Node *)> Compare;
		auto compare = [this](const Node *lhs, const Node *rhs) -> bool {
			if (_compare(lhs->_datum, rhs->_datum) > 0) {  // priority_queue为大根堆
				return true;
			}
			return false;
		};
		priority_queue<Node *, vector<Node *>, Compare> heap{ compare };

		// 入堆
		for (Node *iter = _head._next; iter != &_head; iter = iter->_next) {
			heap.push(iter);
		}
		for (int i = 0; i < lists.size(); i += 1) {
			CircularDoublyLinkedList *list = lists[i];
			for (Node *iter = list->_head._next; iter != &list->_head; iter = iter->_next) {
				heap.push(iter);
			}
		}

		// 出堆
		_head._prev = &_head;
		_head._next = &_head;
		while (heap.empty() == false) {
			Node *node = heap.top();
			heap.pop();
			_head._prev->_next = node;
			node->_prev = _head._prev;
			_head._prev = node;
			node->_next = &_head;
		}
		// 重置
		for (int i = 0; i < lists.size(); i += 1) {
			CircularDoublyLinkedList *list = lists[i];
			_size += list->_size;
			list->_Init();
		}
	}

	void _Sort_Selection_Swap_Unstable() {
		for (Node *head = _head._next; head != &_head; ) {
			Node *mini = head;
			for (Node *iter = head->_next; iter != &_head; iter = iter->_next) {
				if ((_compare(mini->_datum, iter->_datum) <= 0) == false) {  // 选择首个
					mini = iter;
				}
			}
			if (head != mini) {
				Datum_ temp = head->_datum;
				head->_datum = mini->_datum;
				mini->_datum = temp;
			}
			for (mini = head, head = head->_next; head != &_head && _compare(mini->_datum, head->_datum) == 0; head = head->_next);
		}
	}
	void _Sort_Selection_Stable() {
		Node *head = _head._next;
		while (head != &_head) {
			Node *mini = head;
			for (Node *iter = head->_next; iter != &_head; iter = iter->_next) {
				if ((_compare(mini->_datum, iter->_datum) <= 0) == false) {  // 选择首个
					mini = iter;
				}
			}
			Node *tail = mini->_next;
			for (; tail != &_head && _compare(mini->_datum, tail->_datum) == 0; tail = tail->_next);  // 跳过等值
			if (head == mini) {
				head = tail;
			} else {
				tail = tail->_prev;
				mini->_prev->_next = tail->_next;
				tail->_next->_prev = mini->_prev;
				head->_prev->_next = mini;
				mini->_prev = head->_prev;
				tail->_next = head;
				head->_prev = tail;
			}
		}
	}

	void _Sort_Partition_Swap_Unstable() {
		__Sort_Partition_Swap_Unstable(_head._next, &_head);
	}
	void __Sort_Partition_Swap_Unstable(Node *fore, Node *back) {
		if (fore == back || fore->_next == back) {
			return;
		}
		Node *midd = fore;                 // head为哨兵
		for (Node *iter = fore->_next; iter != back; iter = iter->_next) {
			if (_compare(iter->_datum, fore->_datum) < 0) {
				midd = midd->_next;
				swap(midd->_datum, iter->_datum);
			}
		}
		swap(fore->_datum, midd->_datum);  // 交换哨兵与中轴
		midd = midd->_next;

		__Sort_Partition_Swap_Unstable(fore, midd);
		__Sort_Partition_Swap_Unstable(midd, back);
	}

	void _Sort_Merge_Stable() {
		if (_size == 0 || _size == 1) {
			return;
		}
		Node *list = __Sort_Merge_Stable(_head._next, _size);
		Node *tail = list;
		for (int i = 1; i < _size; tail = tail->_next, i += 1);
		_head._next = list;
		list->_prev = &_head;
		tail->_next = &_head;
		_head._prev = tail;
	}
	Node *__Sort_Merge_Stable(Node *head, long size) {
		if (size == 0 || size == 1) {
			return head;
		}
		// 分割链表
		long pivot = (size + 1) / 2;
		Node *midd = head;
		for (long i = 0; i < pivot; midd = midd->_next, i += 1);
		head = __Sort_Merge_Stable(head, pivot);
		midd = __Sort_Merge_Stable(midd, size - pivot);

		// 合并链表
		Node list;
		Node *curr = &list;
		int head_size = pivot, midd_size = size - pivot;
		while (head_size != 0 && midd_size != 0) {
			if (_compare(head->_datum, midd->_datum) <= 0) {
				curr->_next = head;
				head->_prev = curr;
				head = head->_next;
				head_size -= 1;
			} else {
				curr->_next = midd;
				midd->_prev = curr;
				midd = midd->_next;
				midd_size -= 1;
			}
			curr = curr->_next;
		}
		if (head_size != 0) {
			curr->_next = head;
			head->_prev = curr;
		} else if (midd_size != 0) {
			curr->_next = midd;
			midd->_prev = curr;
		}
		return list._next;
	}
};

void _Test_Next() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};
	list._Next(std::cout);
	std::cout << std::endl;
}

void _Test_Prev() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};
	list._Prev(std::cout);
	std::cout << std::endl;
}

void _Test_Copy() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};
	list._Next(std::cout);
	std::cout << std::endl;

	CircularDoublyLinkedList<double> copy = list;
	std::cout << copy._size << std::endl;
	copy._Next(std::cout);
	std::cout << std::endl;
	copy._Prev(std::cout);
	std::cout << std::endl;
}

void _Test_Search() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};
	CircularDoublyLinkedList<double>::CircularDoublyLinkedIterator iter = list._Search(3);
	for (; iter != list._CircularDoublyLinked_Next_End(); iter = iter->_next) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
}

void _Test_Search_Lower() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};
	CircularDoublyLinkedList<double>::CircularDoublyLinkedIterator iter = list._Search_Lower(3);
	for (; iter != list._CircularDoublyLinked_Next_End(); iter = iter->_next) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
}

void _Test_Search_Upper() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};
	CircularDoublyLinkedList<double>::CircularDoublyLinkedIterator iter = list._Search_Upper(3);
	for (; iter != list._CircularDoublyLinked_Next_End(); iter = iter->_next) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
}

void _Test_Insert_Index() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};

	CircularDoublyLinkedList<double>::CircularDoublyLinkedIterator iter = list._Insert_Index(4, 4);
	std::cout << list._size << std::endl;

	//for (; iter != list._CircularDoublyLinked_Next_End(); iter = iter->_next) {
	//	std::cout << (*iter);
	//}
	//std::cout << std::endl;

	for (; iter != list._CircularDoublyLinked_Prev_End(); iter = iter->_prev) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
}

void _Test_Insert_Lower() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};

	CircularDoublyLinkedList<double>::CircularDoublyLinkedIterator iter = list._Insert_Lower(3);
	std::cout << list._size << std::endl;

	for (; iter != list._CircularDoublyLinked_Next_End(); iter = iter->_next) {
		std::cout << (*iter);
	}
	std::cout << std::endl;

	for (; iter != list._CircularDoublyLinked_Prev_End(); iter = iter->_prev) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
}

void _Test_Insert_Upper() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};

	CircularDoublyLinkedList<double>::CircularDoublyLinkedIterator iter = list._Insert_Upper(3);
	std::cout << list._size << std::endl;

	//for (; iter != list._CircularDoublyLinked_Next_End(); iter = iter->_next) {
	//	std::cout << (*iter);
	//}
	//std::cout << std::endl;

	for (; iter != list._CircularDoublyLinked_Prev_End(); iter = iter->_prev) {
		std::cout << (*iter);
	}
	std::cout << std::endl;
}

void _Test_Attach_Fore() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};
	list._Attach_Fore(3);
	std::cout << list._size << std::endl;

	list._Next(std::cout);
	std::cout << std::endl;
	list._Prev(std::cout);
	std::cout << std::endl;
}

void _Test_Attach_Back() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};
	list._Attach_Back(3);
	std::cout << list._size << std::endl;

	list._Next(std::cout);
	std::cout << std::endl;
	list._Prev(std::cout);
	std::cout << std::endl;
}

void _Test_Peek_Fore() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};
	double peek = list._Peek_Fore(3.5);
	std::cout << peek << std::endl;
}

void _Test_Peek_Back() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};
	double peek = list._Peek_Back(3.5);
	std::cout << peek << std::endl;
}

void _Test_Detach_Fore() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};
	list._Detach_Fore();
	std::cout << list._size << std::endl;

	list._Next(std::cout);
	std::cout << std::endl;
	list._Prev(std::cout);
	std::cout << std::endl;
}

void _Test_Detach_Back() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};
	list._Detach_Back();
	std::cout << list._size << std::endl;

	list._Next(std::cout);
	std::cout << std::endl;
	list._Prev(std::cout);
	std::cout << std::endl;
}

void _Test_CircularDoublyLinkedIterator() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 1, 2, 3, 3, 3, 6
	};

	long i = 0;
	for (CircularDoublyLinkedList<double>::CircularDoublyLinkedIterator iter = list._CircularDoublyLinked_Next_Begin(); iter != list._CircularDoublyLinked_Next_End(); ) {
		if (i == 0) {
			iter = list._Erase(iter);
		} else {
			std::cout << (*iter);
			++iter;
		}
		i += 1;
	}
	std::cout << std::endl;
	std::cout << list._size << std::endl;

	list._Next(std::cout);
	std::cout << std::endl;
	list._Prev(std::cout);
	std::cout << std::endl;
}

void _Test_Merge_Ordered() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 3, 6, 9, 12
	};
	CircularDoublyLinkedList<double> that = vector<double>{
		1, 4, 7, 10, 13
	};
	list._Merge_Ordered(that);
	std::cout << list._size << std::endl;
	list._Next(std::cout);
	std::cout << std::endl;
	list._Prev(std::cout);
	std::cout << std::endl;

	std::cout << that._size << std::endl;
	that._Next(std::cout);
	std::cout << std::endl;
	that._Prev(std::cout);
	std::cout << std::endl;
}

void _Test_Merge_Multiple_Ordered() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 3, 6, 9, 12
	};
	CircularDoublyLinkedList<double> list1 = vector<double>{
		1, 4, 7, 10, 13
	};
	CircularDoublyLinkedList<double> list2 = vector<double>{
		2, 5, 8, 11, 14
	};
	CircularDoublyLinkedList<double> list3 = vector<double>{
		3, 6, 9, 12, 16
	};

	list._Merge_Multiple_Ordered(vector<CircularDoublyLinkedList<double> *>{
		&list1, &list2, &list3
	});
	std::cout << list._size << std::endl;
	list._Next(std::cout);
	std::cout << std::endl;
	list._Prev(std::cout);
	std::cout << std::endl;

	std::cout << list1._size << std::endl;
	list1._Next(std::cout);
	std::cout << std::endl;
	list1._Prev(std::cout);
	std::cout << std::endl;
}

void _Test_Merge_Multiple_Unordered() {
	CircularDoublyLinkedList<double> list = vector<double>{
		0, 3, 6, 9, 12
	};
	CircularDoublyLinkedList<double> list1 = vector<double>{
		1, 4, 7, 10, 13
	};
	CircularDoublyLinkedList<double> list2 = vector<double>{
		2, 5, 8, 11, 14
	};
	CircularDoublyLinkedList<double> list3 = vector<double>{
		3, 6, 9, 12, 16
	};

	list._Merge_Multiple_Unordered(vector<CircularDoublyLinkedList<double> *>{
		&list1, &list2, &list3
	});
	std::cout << list._size << std::endl;
	list._Next(std::cout);
	std::cout << std::endl;
	list._Prev(std::cout);
	std::cout << std::endl;

	std::cout << list1._size << std::endl;
	list1._Next(std::cout);
	std::cout << std::endl;
	list1._Prev(std::cout);
	std::cout << std::endl;
}

void _Test_Sort_Selection_Swap_Unstable() {
	CircularDoublyLinkedList<double> list = vector<double>{
		7, 3, 6, 6, 6, 5, 9, 12
	};
	list._Sort_Selection_Swap_Unstable();
	list._Next(std::cout);
	std::cout << std::endl;
	list._Prev(std::cout);
	std::cout << std::endl;
}

void _Test_Sort_Selection_Stable() {
	CircularDoublyLinkedList<double> list = vector<double>{
		7, 3, 6, 6, 6, 5, 9, 12
	};
	list._Sort_Selection_Stable();
	list._Next(std::cout);
	std::cout << std::endl;
	list._Prev(std::cout);
	std::cout << std::endl;
}

void _Test_Sort_Partition_Swap_Unstable() {
	CircularDoublyLinkedList<double> list = vector<double>{
		7, 3, 6, 6, 6, 5, 9, 12
	};
	list._Sort_Partition_Swap_Unstable();
	list._Next(std::cout);
	std::cout << std::endl;
	list._Prev(std::cout);
	std::cout << std::endl;
}

int main() {
	// _Test_Next();
	// _Test_Prev();
	// _Test_Copy();

	// _Test_Search();
	// _Test_Search_Lower();
	// _Test_Search_Upper();

	// _Test_Insert_Index();
	// _Test_Insert_Lower();
	// _Test_Insert_Upper();

	// _Test_Attach_Fore();
	// _Test_Attach_Back();

	// _Test_Peek_Fore();
	// _Test_Peek_Back();

	// _Test_Detach_Fore();
	// _Test_Detach_Back();

	// _Test_CircularDoublyLinkedIterator();

	// _Test_Merge_Ordered();
	// _Test_Merge_Multiple_Ordered();
	// _Test_Merge_Multiple_Unordered();

	// _Test_Sort_Selection_Swap_Unstable();
	// _Test_Sort_Selection_Stable();

	_Test_Sort_Partition_Swap_Unstable();

	return 0;
}
