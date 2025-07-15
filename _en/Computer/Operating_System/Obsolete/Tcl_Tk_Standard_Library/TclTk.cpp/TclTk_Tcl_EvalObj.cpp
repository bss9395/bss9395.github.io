///* TclTk_Tcl_EvalObj.cpp
//Author: bss9395
//Update: 2025-07-15T10:31:00+08@China-ShangHai+08
//*/
//
//#include <tcl.h>
//#include <stdio.h>
//
//void _Test_EvalObj() {
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
//    const char* script = "set x 10; set y 20; expr {$x + $y}";
//    Tcl_Obj* objPtr = Tcl_NewStringObj(script, -1);
//    if (Tcl_EvalObj(interp, objPtr) != TCL_OK) {
//        fprintf(stderr, "脚本执行失败: %s\n", Tcl_GetStringResult(interp));
//        Tcl_DeleteInterp(interp);
//        return ;
//    }
//
//    const char* result = Tcl_GetStringResult(interp);
//    printf("脚本执行结果: %s\n", result);
//
//    Tcl_DecrRefCount(objPtr);
//    Tcl_DeleteInterp(interp);
//}
//
//int main() {
//    _Test_EvalObj();
//    
//    return 0;
//}
