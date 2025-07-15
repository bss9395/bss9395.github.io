///* TclTk_Tcl_SetVar.cpp
//Author: bss9395
//Update: 2025-07-15T10:16:00+08@China-ShangHai+08
//*/
//
//#include <tcl.h>
//#include <iostream>
//
//void _Test_Tcl_SetVar() {
//	Tcl_Interp* interp = Tcl_CreateInterp();
//	if (interp == nullptr) {
//		fprintf(stderr, "无法创建Tcl解释器\n");
//		return;
//	}
//
//	if (Tcl_Init(interp) != TCL_OK) {
//		fprintf(stderr, "Tcl初始化失败：%s\n", Tcl_GetStringResult(interp));
//		Tcl_DeleteInterp(interp);
//		return;
//	}
//
//	/*
//	控制变量设置行为的标志。常用的标志包括：
//		TCL_GLOBAL_ONLY：将变量设置为全局变量。
//		TCL_LEAVE_ERR_MSG：如果出错，将错误信息存储在解释器中。
//		TCL_APPEND_VALUE：将新值追加到现有值的末尾。
//	*/
//	Tcl_SetVar(interp, "macro_tcl", "true", TCL_GLOBAL_ONLY);
//
//	std::string script = R"!(
//puts {Hello, Tcl!}
//proc func {} {
//	# global macro_tcl
//	if {[info exists macro_tcl] && $macro_tcl == "true"} {
//		puts {Hello, macro_tcl!}
//	}
//}
//func
//	)!";
//
//	if (Tcl_Eval(interp, script.c_str()) != TCL_OK) {
//		fprintf(stderr, "脚本执行失败：%s\n", Tcl_GetStringResult(interp));
//		Tcl_DeleteInterp(interp);
//		return;
//	}
//
//	Tcl_DeleteInterp(interp);
//}
//
//int main() {
//	_Test_Tcl_SetVar();
//
//	return 0;
//}
