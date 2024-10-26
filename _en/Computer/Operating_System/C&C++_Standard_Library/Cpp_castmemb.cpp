/* Cpp_castmemb.cpp
Author: BSS9395
Update: 2024-10-21T17:18:00+08@China-Guangdong-Zhanjiang+08
*/

#include <iostream>
#include <string>

template <typename Memb_>
void* castmemb(Memb_ memb) {
	union Func {
		void* _func;
		Memb_ _memb;
	};

	Func func;
	func._memb = memb;
	return func._func;
}

template <typename Base_, typename Memb_>
Base_ castbase(Memb_ memb) {
	union BaseMemb {
		Base_ _base;
		Memb_ _memb;
	};
	BaseMemb basememb;
	basememb._memb = memb;
	return basememb._base;
}

class Type {
public:
	void _Func() {
		fprintf(stdout, "[%s] Hello, World!\n", __FUNCTION__);
	}

	void _What(std::string para) {
		fprintf(stdout, "[%s] para=%s\n", __FUNCTION__, para.data());
	}
};

class Other {
public:
	void _Func() {
		fprintf(stdout, "[%s] Hello, World!\n", __FUNCTION__);
	}

	void _What(std::string para) {
		fprintf(stdout, "[%s] para=%s\n", __FUNCTION__, para.data());
	}
};

static void _Test_castmemb() {
	void(Type::*func)(std::string) = &Type::_What;
	void(Other::*memb)(std::string) = &Other::_What;
	fprintf(stdout, "func=%p, (void*)func=%p\n", func, castmemb(func));	
	fprintf(stdout, "memb=%p, (void*)memb=%p\n", memb, castmemb(memb));

	Type type;
	(type.*func)("Hello, World!");
}

static void _Test_castbase() {
	Type type;

	typedef void(*FuncPtr)(Type*);
	FuncPtr funcptr = castbase<FuncPtr>(&Type::_Func);
	funcptr(&type);

	typedef void(*FuncRef)(Type&);
	FuncRef funcref = castbase<FuncRef>(&Type::_Func);
	funcref(type);
}

static void _Test_castbase_Para() {
	Type type;

	typedef void(*FuncPtr)(Type*, std::string);
	FuncPtr funcptr = castbase<FuncPtr>(&Type::_What);  // 转换无效
	funcptr(&type, "Hello, World!");

	typedef void(*FuncRef)(Type&, std::string);
	FuncRef funcref = castbase<FuncRef>(&Type::_What);  // 转换无效
	funcref(type, "Hello, World!");
}

int main(int argc, char *argv[]) {
	_Test_castmemb();
	// _Test_castbase();
	// _Test_castbase_Para();

	return 0;
}