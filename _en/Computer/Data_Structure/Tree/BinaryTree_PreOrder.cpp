/* BinaryTree_PreOrder.cpp
Author: BSS9395
Update: 2023-06-05T15:07:00+08@China-Guangdong-Zhanjiang+08
Design: BinaryTree made by PreOrder
*/

#include <iostream>
#include <string>
using namespace std;

class BinaryTree_PreOrder {
public:
	struct Node {
		Node*   _pref  = nullptr;
		Node*   _suff  = nullptr;
		wchar_t _datum = L'#';
		Node(wchar_t datum = L'#') {
			_datum = datum;
		}
	};
	Node _head = Node{};

public:
	BinaryTree_PreOrder(const wstring& preorder) {
		const wchar_t* data = &preorder[0];
		_Make_PreOrder(_head._suff, data);
	}
	auto _Make_PreOrder(Node*& node, const wchar_t *& data) -> void {
		if (data[0] == L'\0') {
			return;
		}
		if (data[0] == L'#') {
			data += 1;
			node = nullptr;
			return;
		}
		node = new Node(data[0]);
		data += 1;
		_Make_PreOrder(node->_pref, data);
		_Make_PreOrder(node->_suff, data);
	}

	~BinaryTree_PreOrder() {
		_Free(_head._suff);
	}
	auto _Free(Node *&node) -> void {
		if (node == nullptr) {
			return;
		}
		_Free(node->_pref);
		_Free(node->_suff);
		delete(node), node = nullptr;
	}

public:
	auto _Traverse_PreOrder() -> void {
		_Traverse_PreOrder(_head._suff);
		fwprintf(stdout, L"%ls", L"\n");
	}
	auto _Traverse_PreOrder(Node *node) -> void {
		if (node == nullptr) {
			fwprintf(stdout, L"%lc", L'#');
			return;
		}
		fwprintf(stdout, L"%lc", node->_datum);
		_Traverse_PreOrder(node->_pref);
		_Traverse_PreOrder(node->_suff);
	}

public:
	static auto _Test_BinaryTree_PreOrder() -> void {
		// wstring data = L"124###3##";
		wstring data = L"ABDH#K###E##CFI###G#J##";
		BinaryTree_PreOrder tree = BinaryTree_PreOrder(data);
		tree._Traverse_PreOrder();
	}
};

int main(int argc, char* argv[]) {
	BinaryTree_PreOrder::_Test_BinaryTree_PreOrder();

	return 0;
}
