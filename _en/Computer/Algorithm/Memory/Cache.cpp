/* Cache.cpp
Author: BSS9395
Update: 2023-05-22T18:00:00+08@China-Guangdong-Zhanjiang+08
Design: Cache Least Frequently Used, Cache Least Recently Used
Credit: https://leetcode.cn/problems/lfu-cache/solution/lfuhuan-cun-by-leetcode-solution/
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Cache_LRU_Array {
public:
	struct Node {
		wstring _key   = L"";
		wstring _value = L"";
	};

public:
	vector<Node*> _cache = vector<Node*>{};
	int           _size = 0;
	int           _head = 0;
	Cache_LRU_Array(int capacity = 4) {
		(4 <= capacity) ? capacity : (capacity = 4);
		_cache.resize(capacity);
		_size = 0;
	}
	~Cache_LRU_Array() {
		for (int i = 0; i < _size; i += 1) {
			delete _cache[i], _cache[i] = nullptr;
		}
	}

public:
	auto _Search(const wstring& key) -> Node* {
		if (0 < _size) {
			auto hitted = false;
			auto iter = _head;
			do {
				if (key == _cache[iter]->_key) {
					hitted = true;
					break;
				}
				iter = (iter + 1) % _size;
			} while (iter != _head);
			if (hitted == true) {
				auto cell = _cache[iter];
				// cell->_value = value;
				for (auto rter = (int)0; iter != _head; iter = rter) {
					rter = (iter - 1 + _size) % _size;
					_cache[iter] = _cache[rter];
				}
				_cache[iter] = cell;
				return cell;
			}
		}
		return nullptr;
	}
	auto _Set(const wstring& key, const wstring& value) -> void {
		auto cell = _Search(key);
		if (cell != nullptr) {
			cell->_value = value;
		} 
		else if (_size < _cache.size()) {
			auto cell = new Node{};
			cell->_key = key;
			cell->_value = value;
			for (auto rter = _size; _head < rter; rter -= 1) {
				_cache[rter] = _cache[rter - 1];
			}
			_cache[_head] = cell;
			_size += 1;
		}
		else {
			_head = (_head - 1 + _size) % _size;
			auto cell = _cache[_head];
			cell->_key = key;
			cell->_value = value;
		}
	}
	auto _Get(const wstring& key) -> wstring {
		auto cell = _Search(key);
		if (cell != nullptr) {
			return cell->_value;
		}
		return L"";
	}

public:
	auto _Print() -> void {
		fwprintf(stdout, L"[_head=%d, _size=%d, _capacity=%d]\n", _head, _size, (int)_cache.size());
		if (0 < _size) {
			auto head = _head;
			do {
				fwprintf(stdout, L"[%d, %ls, %ls]\n", head, _cache[head]->_key.data(), _cache[head]->_value.data());
				head = (head + 1) % _size;
			} while (head != _head);
		}
	}

	static auto _Test_Cache_LRU_Array() {
		Cache_LRU_Array cache = Cache_LRU_Array();
		cache._Set(L"abc", L"abc");
		cache._Set(L"def", L"def");
		cache._Set(L"ghi", L"aghi");
		cache._Set(L"jkl", L"jkl");
		cache._Set(L"ghi", L"bghi");
		cache._Set(L"ggg", L"ggg");
		cache._Print();
	}
};

////////////////////////////////////////////////////////////////////////////////

class Cache_LRU_HashMap_BiList {
public:
	struct BiNode {
		BiNode* _prev = nullptr;
		BiNode* _next = nullptr;
		wstring _key = L"";
		wstring _value = L"";
		BiNode(const wstring& key = L"", const wstring& value = L"") {
			_key = key;
			_value = value;
		}
	};

public:
	int _capacity = 0;
	unordered_map<wstring, BiNode*> _cache = unordered_map<wstring, BiNode*>{};
	BiNode* _fore = new BiNode{};
	BiNode* _back = new BiNode{};
	Cache_LRU_HashMap_BiList(int capacity = 4) {
		(4 <= capacity) ? capacity : (capacity = 4);
		_capacity = capacity;
		_fore->_next = _back;
		_back->_prev = _fore;
	}
	~Cache_LRU_HashMap_BiList() {
		auto iter = _fore->_next;
		auto node = (BiNode*)nullptr;
		while (iter != _back) {
			node = iter;
			iter = iter->_next;
			delete node, node = nullptr;
		}
		delete _fore, _fore = nullptr;
		delete _back, _back = nullptr;
	}

public:
	auto _Search(const wstring& key) -> BiNode* {
		auto iter = _cache.find(key);
		if (iter != _cache.end()) {
			auto binode = iter->second;
			_Spin_Head(binode);
			return binode;
		}
		return nullptr;
	}
	auto _Set(const wstring& key, const wstring& value) -> void {
		auto binode = _Search(key);
		if (binode != nullptr) {
			binode->_value = value;
		}
		else {
			auto node = (BiNode*)nullptr;
			if (_cache.size() < _capacity) {
				node = new BiNode{};
			} else {				
				node = _Take_Tail();
				_cache.erase(node->_key);
			}
			node->_key   = key;
			node->_value = value;
			_cache[node->_key] = node;  // note: _cache[key] = node, type Node*&
			_Push_Head(node);
		}
	}

	auto _Get(const wstring& key) -> wstring {
		auto binode = _Search(key);
		if (binode != nullptr) {
			return binode->_value;
		}
		return L"";
	}

public:
	auto _Spin_Head(BiNode* node) -> void {
		_Take_Node(node);
		_Push_Head(node);
	}

	auto _Take_Node(BiNode* node) -> void {
		node->_prev->_next = node->_next;
		node->_next->_prev = node->_prev;
	}

	auto _Push_Head(BiNode* node) -> void {
		node->_next = _fore->_next;
		_fore->_next->_prev = node;
		_fore->_next = node;
		node->_prev = _fore;
	}

	auto _Take_Tail() -> BiNode* {
		BiNode* node = _back->_prev;
		_Take_Node(node);
		return node;
	}

public:
	auto _Print() -> void {
		fwprintf(stdout, L"[_size=%d, _capacity=%d]\n", (int)_cache.size(), _capacity);
		for (auto iter = _fore->_next; iter != _back; iter = iter->_next) {
			fwprintf(stdout, L"[%ls, %ls]\n", iter->_key.data(), iter->_value.data());
		}
	}

	static auto _Test_Cache_LRU_HashMap_BiList() -> void {
		Cache_LRU_HashMap_BiList cache = Cache_LRU_HashMap_BiList();
		cache._Set(L"abc", L"abc");
		cache._Set(L"def", L"def");
		cache._Set(L"ghi", L"aghi");
		cache._Set(L"jkl", L"jkl");
		cache._Set(L"ghi", L"bghi");
		cache._Set(L"ggg", L"ggg");
		cache._Print();
	}
};

////////////////////////////////////////////////////////////////////////////////

class Cache_LFU_Array {
public:
	struct Node {
		int     _count = 0;
		wstring _key = L"";
		wstring _value = L"";
		Node(int count) {
			_count = count;
		}
	};

public:
	vector<Node*> _cache = vector<Node*>{};
	int           _size = 0;
	Cache_LFU_Array(int capacity = 4) {
		(4 <= capacity) ? capacity : (capacity = 4);
		_cache.resize(capacity);
		_size = 0;
	}
	~Cache_LFU_Array() {
		for (auto i = 0; i < _size; i += 1) {
			delete _cache[i], _cache[i] = nullptr;
		}
	}

public:
	auto _Search(const wstring& key) -> Node* {
		if (0 < _size) {
			auto idx = (int)0;
			while (idx < _size && key != _cache[idx]->_key) {
				_cache[idx]->_count -= 1;
				idx += 1;
			}
			if (idx < _size) {
				auto cell = _cache[idx];
				cell->_count += 1;
				// cell->_value = value;
				for (auto i = idx + 1; i < _size && cell->_count == _cache[i]->_count; i += 1) {
					_cache[i]->_count -= 1;  // note: for maintaining the descending order.
				}

				auto rdx = idx;
				while (0 < rdx && cell->_count >= _cache[rdx - 1]->_count) {
					_cache[rdx] = _cache[rdx - 1];
					rdx -= 1;
				}
				_cache[rdx] = cell;
				return cell;
			}
		}
		return nullptr;
	}
	auto _Set(const wstring& key, const wstring& value) -> void {
		auto cell = _Search(key);
		if (cell != nullptr) {
			cell->_value = value;
		}
		else {
			auto rdx = (_size < (int)_cache.size()) ? (cell = new Node(0), _size) : (cell = _cache[_size - 1], cell->_count = 0, _size - 1);
			cell->_count += 1;
			cell->_key = key;
			cell->_value = value;

			while (0 < rdx && cell->_count >= _cache[rdx - 1]->_count) {
				_cache[rdx] = _cache[rdx - 1];
				rdx -= 1;
			}
			_cache[rdx] = cell;
			(_size < (int)_cache.size()) ? (_size += 1) : _size;
		}
	}
	auto _Get(const wstring& key) -> wstring {
		auto cell = _Search(key);
		if (cell != nullptr) {
			return cell->_value;
		}
		return L"";
	}

public:
	auto _Print() -> void {
		fwprintf(stdout, L"[_size=%d, _capacity=%d]\n", _size, (int)_cache.size());
		for (int i = 0; i < _size; i += 1) {
			fwprintf(stdout, L"[%d, %s, %s]\n", _cache[i]->_count, _cache[i]->_key.data(), _cache[i]->_value.data());
		}
	}

public:
	static auto _Test_Cache_LFU_Array() -> void {
		Cache_LFU_Array cache = Cache_LFU_Array();
		cache._Set(L"abc", L"abc");
		cache._Set(L"def", L"def");
		cache._Set(L"ghi", L"aghi");
		cache._Set(L"jkl", L"jkl");
		cache._Set(L"ghi", L"bghi");
		cache._Set(L"ggg", L"ggg");
		cache._Print();
	}
};

////////////////////////////////////////////////////////////////////////////////

class Cache_LFU_HashMap_TreeMap_None {
public:
	struct Node {
		struct Index {
			int _count = 0;
			int _time = 0;
			bool operator < (const Index& rhs) const {
				return (_count == rhs._count) ? (_time < rhs._time) : (_count < rhs._count);
			}
		};
		Index   _index = Index{};
		wstring _key = L"";
		wstring _value = L"";
		Node(int count = 0, int time = 0, wstring key = L"", wstring value = L"") {
			_index._count = count;
			_index._time = time;
			_key = key;
			_value = value;
		}
	};

public:
	int _capacity = 0;
	int _time     = 0;
	unordered_map<wstring, Node*> _cache  = unordered_map<wstring, Node*>{};
	map<Node::Index, Node*>       _sorted = map<Node::Index, Node*>{};
	Cache_LFU_HashMap_TreeMap_None(int capacity = 4) {
		(4 <= capacity) ? capacity : (capacity = 4);
		_capacity = capacity;
		_time     = 0;
	}
	~Cache_LFU_HashMap_TreeMap_None() {
		auto iter = _cache.begin();
		auto iend = _cache.end();
		while (iter != iend) {
			delete (iter->second);
			++iter;
		}
	}

public:
	auto _Search(const wstring& key) -> Node* {
		auto iter = _cache.find(key);
		if (iter != _cache.end()) {
			auto node = iter->second;
			_sorted.erase(node->_index);
			node->_index._count += 1;
			node->_index._time = (_time += 1);
			// node->_value = value;
			_sorted[node->_index] = node;
			return node;
		}
		return nullptr;
	}
	auto _Set(const wstring& key, const wstring& value) -> void {
		auto node = _Search(key);
		if (node != nullptr) {
			node->_value = value;
		}
		else {
			auto node = (Node*)nullptr;
			if ((int)_cache.size() < _capacity) {
				node = new Node{};
			}
			else {
				node = _sorted.begin()->second;
				_cache.erase(node->_key);
				_sorted.erase(node->_index);
			}			 
			node->_index._count = 1;
			node->_index._time  = (_time += 1);
			node->_key = key;
			node->_value = value;
			_cache[key] = node;
			_sorted[node->_index] = node;
		}
	}

	auto _Get(const wstring& key) -> wstring {
		auto node = _Search(key);
		if (node != nullptr) {
			return node->_value;
		}
		return L"";
	}

public:
	auto _Print() -> void {
		fwprintf(stdout, L"[_cache._size()=%d, _sorted.size()=%d, _capacity=%d]\n", (int)_cache.size(), (int)_sorted.size(), _capacity);
		for (auto iter = _cache.begin(), iend = _cache.end(); iter != iend; ++iter) {
			fwprintf(stdout, L"[%d, %d, %ls, %ls]\n", iter->second->_index._count, iter->second->_index._time, iter->second->_key.data(), iter->second->_value.data());
		}
	}

	static auto _Test_Cache_LFU_HashMap_TreeMap_None() -> void {
		Cache_LFU_HashMap_TreeMap_None cache = Cache_LFU_HashMap_TreeMap_None();
		cache._Set(L"abc", L"abc");
		cache._Set(L"def", L"def");
		cache._Set(L"ghi", L"aghi");
		cache._Set(L"jkl", L"jkl");
		cache._Set(L"ghi", L"bghi");
		cache._Set(L"ggg", L"ggg");
		cache._Print();
	}
};

////////////////////////////////////////////////////////////////////////////////

class Cache_LFU_HashMap_HashMapBiList_None {
public:
	struct BiNode {
		BiNode* _prev = nullptr;
		BiNode* _next = nullptr;
		int     _count = 0;
		wstring _key = L"";
		wstring _value = L"";
		BiNode(int count = 0, wstring key = L"", wstring value = L"") {
			_count = count;
			_key = key;
			_value = value;
		}
	};

	struct BiList {
		int     _size = 0;
		BiNode* _fore = new BiNode{};
		BiNode* _back = new BiNode{};
		BiList() {
			_size = 0;
			_fore->_next = _back;
			_back->_prev = _fore;
		}
		~BiList() {
			auto head = _fore->_next;
			auto node = (BiNode*)nullptr;
			while (head != _back) {
				node = head;
				head = head->_next;
				delete node, node = nullptr;
			}
		}

	public:
		auto _Peek_Head() -> BiNode* {
			return (0 < _size) ? _fore->_next : nullptr;
		}
		auto _Peek_Tail() -> BiNode* {
			return (0 < _size) ? _back->_prev : nullptr;
		}
		auto _Take(BiNode* node) -> BiNode* {
			if (0 < _size) {
				node->_prev->_next = node->_next;
				node->_next->_prev = node->_prev;
				_size -= 1;
				return node;
			}
			return nullptr;
		}
		auto _Take_Head() -> BiNode* {
			return _Take(_fore->_next);
		}
		auto _Take_Tail() -> BiNode* {
			return _Take(_back->_prev);
		}
		auto _Pull(BiNode* node) -> void {
			if (0 < _size) {
				node->_prev->_next = node->_next;
				node->_next->_prev = node->_prev;
				_size -= 1;
				delete node, node = nullptr;
			}
		}
		auto _Pull_Head() -> void {
			_Pull(_fore->_next);
		}
		auto _Pull_Tail() -> void {
			_Pull(_back->_prev);
		}
		auto _Push(BiNode* iter, BiNode* node) -> void {
			iter->_prev->_next = node;
			node->_prev = iter->_prev;
			node->_next = iter;
			iter->_prev = node;
			_size += 1;
		}
		auto _Push_Head(BiNode* node) -> void {
			_Push(_fore->_next, node);
		}
		auto _Push_Tail(BiNode* node) -> void {
			_Push(_back, node);
		}
		auto _Spin_Head(BiNode* node) -> void {
			_Take(node);
			_Push(_fore->_next, node);
		}
		auto _Spin_Tail(BiNode* node) -> void {
			_Take(node);
			_Push(_back, node);
		}
	};

public:
	int _capacity = 0;
	int _count_min = 0;
	unordered_map<wstring, BiNode*> _cache  = unordered_map<wstring, BiNode*>{};
	unordered_map<int, BiList*>     _sorted = unordered_map<int, BiList*>{};
	Cache_LFU_HashMap_HashMapBiList_None(int capacity = 4) {
		(4 <= capacity) ? capacity : (capacity = 4);
		_capacity = capacity;
		_count_min = 0;
	}
	~Cache_LFU_HashMap_HashMapBiList_None() {
		auto iter = _sorted.begin();
		auto iend = _sorted.end();
		while (iter != iend) {
			delete iter->second;
			++iter;
		}
	}

public:
	auto _Search(const wstring& key) -> BiNode* {
		auto iter = _cache.find(key);
		if (iter != _cache.end()) {
			auto binode = iter->second;
			auto count = binode->_count;
			auto bilist = _sorted[count];
			bilist->_Take(binode);
			if (false == (0 < bilist->_size)) {
				delete bilist, bilist = nullptr;
				_sorted.erase(count);
				if (_count_min == count) {
					_count_min = count + 1;
				}
			}
			binode->_count = count + 1;
			// binode->_value = value;
			if (_sorted[binode->_count] == nullptr) {
				_sorted[binode->_count] = new BiList{};
			}
			_sorted[binode->_count]->_Push_Head(binode);
			return binode;
		}
		return nullptr;
	}

	auto _Set(const wstring& key, const wstring& value) -> void {
		auto binode = _Search(key);
		if (binode != nullptr) {
			binode->_value = value;
		}
		else {
			auto binode = (BiNode*)nullptr;
			if ((int)_cache.size() < _capacity) {
				binode = new BiNode{};
			}
			else {
				auto bilist = _sorted[_count_min];
				binode = bilist->_Take_Tail();
				if (false == (0 < bilist->_size)) {
					delete bilist, bilist = nullptr;
					_sorted.erase(binode->_count);
				}
				_cache.erase(binode->_key);
			}
			binode->_count = 1;
			binode->_key = key;
			binode->_value = value;
			_cache[binode->_key] = binode;
			if (_sorted[binode->_count] == nullptr) {
				_sorted[binode->_count] = new BiList{};
			}
			_sorted[binode->_count]->_Push_Head(binode);
			_count_min = 1;
			fwprintf(stdout, L"[bilist._size=%d]\n", (int)_sorted[binode->_count]->_size);
		}
	}

	auto _Get(const wstring& key) -> wstring {
		auto binode = _Search(key);
		if (binode != nullptr) {
			return binode->_value;
		}
		return L"";
	}

public:
	auto _Print() -> void {
		fwprintf(stdout, L"[_cache._size()=%d, _capacity=%d]\n", (int)_cache.size(), _capacity);
		for (auto iter = _sorted.begin(), iend = _sorted.end(); iter != iend; ++iter) {
			auto bilist = iter->second;
			fwprintf(stdout, L"[_sorted._size()=%d]\n", (int)bilist->_size);
			for (auto head = bilist->_fore->_next, back = bilist->_back; head != back; head = head->_next) {
				fwprintf(stdout, L"[%d, %ls, %ls]\n", head->_count, head->_key.data(), head->_value.data());
			}
		}
	}

	static auto _Test_Cache_LFU_HashMap_HashMapBiList_None() -> void {
		Cache_LFU_HashMap_HashMapBiList_None cache = Cache_LFU_HashMap_HashMapBiList_None();
		cache._Set(L"abc", L"abc");
		cache._Set(L"def", L"def");
		cache._Set(L"ghi", L"aghi");
		cache._Set(L"jkl", L"jkl");
		cache._Set(L"ghi", L"bghi");
		// cache._Set(L"ggg", L"ggg");
		cache._Print();
	}
};

int main(int argc, char* argv[]) {
	// Cache_LRU_Array::_Test_Cache_LRU_Array();
	// Cache_LRU_HashMap_BiList::_Test_Cache_LRU_HashMap_BiList();
	// Cache_LFU_Array::_Test_Cache_LFU_Array();
	// Cache_LFU_HashMap_TreeMap_None::_Test_Cache_LFU_HashMap_TreeMap_None();
	Cache_LFU_HashMap_HashMapBiList_None::_Test_Cache_LFU_HashMap_HashMapBiList_None();

	return 0;
}
