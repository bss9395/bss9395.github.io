///* TclTk_Tcl_DoOneEvent.cpp
//Author: bss9395
//Update: 2025-07-15T10:27:00@China-ShangHai+08
//*/
//
//#include <tcl.h>
//#include <stdio.h>
//
//void TimerProc(ClientData clientData) {
//	static int count = 0;
//	count += 1;
//	printf("Timer triggered! Count: %d\n", count);
//	Tcl_CreateTimerHandler(1000, TimerProc, clientData);
//}
//
//void _Test_DoOneEvent() {
//	Tcl_Interp* interp = Tcl_CreateInterp();
//	if (Tcl_Init(interp) != TCL_OK) {
//		fprintf(stderr, "Tcl_Init failed: %s\n", Tcl_GetStringResult(interp));
//		return;
//	}
//
//	Tcl_CreateTimerHandler(1000, TimerProc, nullptr);
//
//	while (true) {
//		int ret = Tcl_DoOneEvent(TCL_ALL_EVENTS);
//		if (ret == 0) {
//			// 没有事件时执行一些其它操作
//			printf("No events, doing some other work...\n");
//			Tcl_Sleep(100);
//		}
//		else {
//			printf("Continue...\n");
//		}
//	}
//	Tcl_DeleteInterp(interp);
//}
//
//int main() {
//	_Test_DoOneEvent();
//
//	return 0;
//}
