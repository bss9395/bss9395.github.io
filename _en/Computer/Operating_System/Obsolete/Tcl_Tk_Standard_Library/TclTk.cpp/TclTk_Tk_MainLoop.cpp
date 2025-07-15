///* TclTk_Tk_MainLoop.cpp
//Author: bss9395
//Update: 2025-07-15T11:38:00+08@China-ShangHai+08
//*/
//
//#include <tcl.h>
//#include <tk.h>
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
//	if (Tk_Init(interp) != TCL_OK) {
//		fprintf(stderr, "Tk初始化失败: %s", Tcl_GetStringResult(interp));
//		return;
//	}
//
//	std::string script = R"!(
//package require Tk
//
//wm title . "Hello"
//
//ttk::progressbar .progressbar -orient horizontal -length 200 -mode indeterminate -maximum 40 -value 50 
//pack .progressbar
//
//button .startBtn -text "Start" -command {
//	.progressbar start
//}
//button .stopBtn -text "Stop" -command {
//	.progressbar stop
//}
//pack .startBtn .stopBtn
//	)!";
//
//	if (Tcl_Eval(interp, script.c_str()) != TCL_OK) {
//		fprintf(stderr, "脚本执行失败：%s\n", Tcl_GetStringResult(interp));
//		Tcl_DeleteInterp(interp);
//		return;
//	}
//
//	static bool flag_loop = true;
//	if (flag_loop == true) {
//		// 启动无限循环，阻塞
//		Tk_MainLoop();    
//	}
//	else {
//		// 自定义循环，不阻塞
//		while (0 < Tk_GetNumMainWindows()) {
//			int ret = Tcl_DoOneEvent(TCL_ALL_EVENTS);
//			if (ret == 0) {
//				// 没有事件时执行一些其它操作
//				printf("No events, doing some other work...\n");
//				Tcl_Sleep(100);
//			}
//			else {
//				printf("Continue...\n");
//			}
//		}
//	}
//
//	Tcl_DeleteInterp(interp);
//}
//
//
//#include <thread>
//int main() {
//	_Test_Tcl_SetVar();
//
//	return 0;
//}
