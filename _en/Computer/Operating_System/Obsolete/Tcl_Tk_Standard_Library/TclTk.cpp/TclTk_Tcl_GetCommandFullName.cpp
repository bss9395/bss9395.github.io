///* TclTk_Tcl_GetCommandFullName.cpp
//Author: bss9395
//Update: 2025-07-15T10:39:00+08@China-ShangHai+08
//*/
//
//#include <tcl.h>
//#include <stdio.h>
//
//int MyCommand(ClientData clientData, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[]) {
//    Tcl_SetObjResult(interp, Tcl_NewStringObj("Hello, world!", -1));
//    return TCL_OK;
//}
//
//void _Test_GetCommandFullName() {
//    Tcl_Interp* interp = Tcl_CreateInterp();
//    if (interp == nullptr) {
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
//    Tcl_CreateObjCommand(interp, "::mynamespace::mycommand", MyCommand, nullptr, nullptr);
//    Tcl_Command command = Tcl_FindCommand(interp, "::mynamespace::mycommand", nullptr, TCL_LEAVE_ERR_MSG);
//    if (command == nullptr) {
//        fprintf(stderr, "无法找到命令: %s\n", Tcl_GetStringResult(interp));
//        Tcl_DeleteInterp(interp);
//        return ;
//    }
//
//    Tcl_Obj* fullNameObj = Tcl_NewObj();
//    Tcl_GetCommandFullName(interp, command, fullNameObj);
//    if (fullNameObj == nullptr) {
//        fprintf(stderr, "获取命令完整名称失败: %s\n", Tcl_GetStringResult(interp));
//        Tcl_DeleteInterp(interp);
//        return ;
//    }
//
//    const char* fullName = Tcl_GetString(fullNameObj);
//    printf("命令的完整名称: %s\n", fullName);
//    Tcl_DecrRefCount(fullNameObj); // 减少引用计数
//
//    Tcl_Eval(interp, "::mynamespace::mycommand");
//    const char* result = Tcl_GetStringResult(interp);
//    printf("%s\n", result);
//
//    Tcl_DeleteInterp(interp);
//}
//
//int main() {
//    _Test_GetCommandFullName();
//
//    return 0;
//}
