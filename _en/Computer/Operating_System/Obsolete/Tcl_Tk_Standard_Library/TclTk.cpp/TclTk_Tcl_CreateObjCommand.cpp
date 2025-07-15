///* TclTk_Tcl_CreateObjCommand.cpp
//Author: bss9395
//Update: 2025-07-15T10:24:00+08@China-ShangHai+08
//*/
//
///*
//Tcl_Command Tcl_CreateObjCommand(
//    Tcl_Interp *interp,           // Tcl 解释器
//    const char *cmdName,          // 命令名称
//    Tcl_ObjCmdProc *proc,         // 命令处理函数
//    ClientData clientData,        // 传递给命令处理函数的客户端数据
//    Tcl_CmdDeleteProc *deleteProc // 命令删除时的回调函数
//);
//*/
//
//#include <tcl.h>
//
//int MyCommand(ClientData clientData, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[]) {
//    Tcl_SetObjResult(interp, Tcl_NewStringObj("Hello, world!", -1));
//    return TCL_OK;
//}
//
//int MyCommandArgv(ClientData clientData, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[]) {
//    if (objc != 3) {
//        Tcl_WrongNumArgs(interp, 1, objv, "arg1 arg2");
//        return TCL_ERROR;
//    }
//
//    int arg1;
//    int arg2;
//    if (Tcl_GetIntFromObj(interp, objv[1], &arg1) != TCL_OK ||
//        Tcl_GetIntFromObj(interp, objv[2], &arg2) != TCL_OK) {
//        return TCL_ERROR;
//    }
//
//    int result = arg1 + arg2;
//    Tcl_SetObjResult(interp, Tcl_NewIntObj(result));
//    return TCL_OK;
//}
//
//void _Test_CreateObjCommand() {
//    Tcl_Interp* interp = Tcl_CreateInterp();
//    Tcl_CreateObjCommand(interp, "mycommand", MyCommand, NULL, NULL);
//    int ok = Tcl_Eval(interp, "mycommand");
//    if (ok != TCL_OK) {
//        printf("ok != TCL_OK\n");
//    }
//    const char* result = Tcl_GetStringResult(interp);
//    printf("%s\n", result);
//    Tcl_DeleteInterp(interp);
//}
//
//void _Test_CreateObjCommand_objv() {
//    Tcl_Interp* interp = Tcl_CreateInterp();
//    Tcl_CreateObjCommand(interp, "mycommand", MyCommandArgv, NULL, NULL);
//    int ok = Tcl_Eval(interp, "mycommand 10 20");
//    if (ok != TCL_OK) {
//        printf("ok != TCL_OK\n");
//    }
//    const char* result = Tcl_GetStringResult(interp);
//    printf("%s\n", result);
//    Tcl_DeleteInterp(interp);
//}
//
//void _Test_CreateObjCommand_overlap() {
//    Tcl_Interp* interp = Tcl_CreateInterp();
//    Tcl_CreateObjCommand(interp, "mycommand", MyCommand, NULL, NULL);
//    Tcl_CreateObjCommand(interp, "mycommand", MyCommandArgv, NULL, NULL);
//    int ok = Tcl_Eval(interp, "mycommand");
//    if (ok != TCL_OK) {
//        printf("ok != TCL_OK\n");
//    }
//    ok = Tcl_Eval(interp, "mycommand 10 20");
//    if (ok != TCL_OK) {
//        printf("ok != TCL_OK\n");
//    }
//    const char* result = Tcl_GetStringResult(interp);
//    printf("%s\n", result);
//    Tcl_DeleteInterp(interp);
//}
//
//int main() {
//    _Test_CreateObjCommand();
//    // _Test_CreateObjCommand_objv();
//    // _Test_CreateObjCommand_overlap();
//
//    return 0;
//}
