/* Pointer_Inline.cpp
Author: BSS9395
Update: 2023-05-25T16:02:00+08@China-China-Guangdong-Zhanjiang+08
Design: Pointer Inline
*/

#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
struct Instance {
	int *_count = new int(1);
	virtual ~Instance() = 0 {

	}
};
//////////////////////////////////////////////////////////////////////////////
#define _Delete(pointer)  (delete pointer, pointer = nullptr)
//////////////////////////////////////////////////////////////////////////////
#define _Member_Access_Operator(Pointer_, Member_, instance_)                \
	Member* operator->() {                                                   \
		return instance_;                                                    \
	}                                                                        \
//////////////////////////////////////////////////////////////////////////////
#define _Assign_Constructor(Pointer_, Member_, instance_)                    \
	Pointer_(const Pointer_& share) {                                        \
		fprintf(stderr, "[%s:%d, %s]\n", __FILE__, __LINE__, __FUNCTION__);  \
		instance_ = share.instance_;                                         \
		_count    = share._count;                                            \
		(*_count) += 1;                                                      \
	}                                                                        \
//////////////////////////////////////////////////////////////////////////////
#define _Copy_Constructor(Pointer_, Member_, instance_)                      \
	Pointer_& operator=(const Pointer_& share) {                             \
		fprintf(stderr, "[%s:%d, %s]\n", __FILE__, __LINE__, __FUNCTION__);  \
		if (this == &share) {                                                \
			return *this;                                                    \
		}                                                                    \
		instance_ = share.instance_;                                         \
		_count    = share._count;                                            \
		(*_count) += 1;                                                      \
	}                                                                        \
//////////////////////////////////////////////////////////////////////////////
#define _Virtual_Destructor(Pointer_, Member_, instance_)                    \
	virtual ~Pointer_() {                                                    \
		fprintf(stderr, "[%s:%d, %s]\n", __FILE__, __LINE__, __FUNCTION__);  \
		(*_count) -= 1;                                                      \
		if (false == (1 <= (*_count))) {                                     \
			fprintf(stderr, "delete _instance;\n");                          \
			delete((Member_ *)instance_), instance_ = nullptr;               \
			delete _count, _count = nullptr;                                 \
		}                                                                    \
	}                                                                        \
//////////////////////////////////////////////////////////////////////////////
#define _Inline(Pointer_, Member_, instance_)                                \
	_Member_Access_Operator(Pointer_, Member_, instance_)                    \
	_Assign_Constructor(Pointer_, Member_, instance_)                        \
	_Copy_Constructor(Pointer_, Member_, instance_)                          \
	_Virtual_Destructor(Pointer_, Member_, instance_)                        \
//////////////////////////////////////////////////////////////////////////////

class Type : Instance {
public:
	struct Member {
		wstring _key = L"";
		wstring _value = L"";
	};
	Member* _instance = nullptr;                                                                    

public:
	Type(const wstring& key, const wstring& value) {
		fprintf(stderr, "[%s:%d, %s]\n", __FILE__, __LINE__, __FUNCTION__);
		_instance = new Member{};
		_instance->_key   = key;
		_instance->_value = value;
	}
	_Inline(Type, Member, _instance)

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
