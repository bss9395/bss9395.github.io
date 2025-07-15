///* TclTk_Tcl_CreateCommand.cpp
//Author: bss9395
//Update: 2025-07-15T10:41:00+08@China-ShangHai+08
//*/
//
//#include <tcl.h>
//#include <stdio.h>
//
//int MyCommandArgv(ClientData clientData, Tcl_Interp* interp, int argc, const char* argv[]) {
//    Tcl_SetObjResult(interp, Tcl_NewStringObj("Hello from MyCommandArgv!", -1));
//    return TCL_OK;
//}
//
//void _Test_GetCommandInfo() {
//    Tcl_Interp* interp = Tcl_CreateInterp();
//    if (interp == NULL) {
//        fprintf(stderr, "无法创建 Tcl 解释器\n");
//        return ;
//    }
//
//    if (Tcl_Init(interp) != TCL_OK) {
//        fprintf(stderr, "Tcl 初始化失败: %s\n", Tcl_GetStringResult(interp));
//        Tcl_DeleteInterp(interp);
//        return ;
//    }
//
//    Tcl_CreateCommand(interp, "::mynamespace::mycommand", MyCommandArgv, NULL, NULL);
//    Tcl_CmdInfo cmdInfo;
//    if (Tcl_GetCommandInfo(interp, "::mynamespace::mycommand", &cmdInfo) == 0) {
//        fprintf(stderr, "无法找到命令\n");
//        Tcl_DeleteInterp(interp);
//        return ;
//    }
//
//    printf("命令过程: %p\n", (void*)cmdInfo.proc);
//    printf("客户端数据: %p\n", (void*)cmdInfo.clientData);
//    printf("命名空间：%s\n", cmdInfo.namespacePtr->fullName);
//
//    Tcl_Eval(interp, "::mynamespace::mycommand");
//    const char* result = Tcl_GetStringResult(interp);
//    printf("%s\n", result);
//
//    Tcl_DeleteInterp(interp);
//}
//
//int main() {
//    _Test_GetCommandInfo();
//
//    return 0;
//}