/* Pointer_Inline.cpp
Author: BSS9395
Update: 2023-05-25T16:02:00+08@China-China-Guangdong-Zhanjiang+08
Design: Pointer Inline
*/

#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
#define _Delete(pointer)  (delete pointer, pointer = nullptr)
//////////////////////////////////////////////////////////////////////////////
#define _self  _instance 
#define _Counter(Pointer_, Member_)                                          \
	Member_* _instance = nullptr;                                            \
	int*     _count    = new int{1};                                         \
	Member_* operator->() {                                                  \
		return _instance;                                                    \
	}                                                                        \
//////////////////////////////////////////////////////////////////////////////
#define _Assign_Constructor(Pointer_, Member_)                               \
	Pointer_(const Pointer_& share) {                                        \
		fprintf(stderr, "[%s:%d, %s]\n", __FILE__, __LINE__, __FUNCTION__);  \
		_instance = share._instance;                                         \
		_count    = share._count;                                            \
		(*_count) += 1;                                                      \
	}                                                                        \
//////////////////////////////////////////////////////////////////////////////
#define _Copy_Constructor(Pointer_, Member_)                                 \
	Pointer_& operator=(const Pointer_& share) {                             \
		fprintf(stderr, "[%s:%d, %s]\n", __FILE__, __LINE__, __FUNCTION__);  \
		if (this == &share) {                                                \
			return (*this);                                                  \
		}                                                                    \
		_instance = share._instance;                                         \
		_count    = share._count;                                            \
		(*_count) += 1;                                                      \
	}                                                                        \
//////////////////////////////////////////////////////////////////////////////
#define _Virtual_Destructor(Pointer_, Member_)                               \
	virtual ~Pointer_() {                                                    \
		fprintf(stderr, "[%s:%d, %s]\n", __FILE__, __LINE__, __FUNCTION__);  \
		(*_count) -= 1;                                                      \
		if (false == (1 <= (*_count))) {                                     \
			fprintf(stderr, "delete _instance; delete _count;\n");           \
			delete((Member_ *)_instance), _instance = nullptr;               \
			delete _count, _count = nullptr;                                 \
		}                                                                    \
	}                                                                        \
//////////////////////////////////////////////////////////////////////////////
#define _Inline(Pointer_, Member_)                                           \
	_Counter(Pointer_, Member_)                                              \
	_Assign_Constructor(Pointer_, Member_)                                   \
	_Copy_Constructor(Pointer_, Member_)                                     \
	_Virtual_Destructor(Pointer_, Member_)                                   \
//////////////////////////////////////////////////////////////////////////////

class Type {
public:
	struct Member {
		wstring _key = L"";
		wstring _value = L"";
		Member(const wstring& key, const wstring& value) {
			_key = key;
			_value = value;
		}
	};
                                                                
public:
	Type(const wstring& key, const wstring& value) {
		fprintf(stderr, "[%s:%d, %s]\n", __FILE__, __LINE__, __FUNCTION__);
		_self = new Member(key, value);
	}
	_Inline(Type, Member)
	
public:
	static void _Test_Pointer_Inline() {
		Type share = Type(L"abc", L"ABC");
		fwprintf(stdout, L"share->_count=%d, share->_datum=%ls\n", *(share._count), share->_key.data());
		share->_key   = L"def";
		share->_value = L"DEF";
		Type copy = share;
		fwprintf(stdout, L"share->_count=%d, share->_datum=%ls\n", *(share._count), share->_key.data());
		fwprintf(stdout, L"copy ->_count=%d, copy ->_datum=%ls\n", *(copy._count) , copy->_key.data() );
	}
};

int main(int argc, char* argv[]) {
    Type::_Test_Pointer_Inline();

	return 0;
}
