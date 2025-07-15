///* TclTk_Tcl_FindCommand.cpp
//Author: bss9395
//Update: 2025-07-15T10:35:00+08@China-ShangHai+08
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
//void _Test_FindCommand() {
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
//    Tcl_CreateObjCommand(interp, "mycommand", MyCommand, NULL, NULL);
//    Tcl_Command command = Tcl_FindCommand(interp, "mycommand", NULL, TCL_LEAVE_ERR_MSG);
//    if (command == NULL) {
//        fprintf(stderr, "无法找到命令: %s\n", Tcl_GetStringResult(interp));
//        Tcl_DeleteInterp(interp);
//        return ;
//    }
//
//    printf("命令查找成功\n");
//    Tcl_Eval(interp, "mycommand");
//    const char* result = Tcl_GetStringResult(interp);
//    printf("%s\n", result);
//
//    Tcl_DeleteInterp(interp);
//}
//
//int main() {
//    _Test_FindCommand();
//
//    return 0;
//}