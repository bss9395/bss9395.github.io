///* TclTk_Tcl_EvalFile.cpp
//Author: bss9395
//Update: 2025-07-15T10:29:00+08@China-ShangHai+08
//*/
//
//#include <tcl.h>
//#include <stdio.h>
//#include <fstream>
//
//void _Test_EvalFile() {
//    std::fstream file("script.tcl", std::fstream::out);
//    std::string script = R"(
//set x 10
//set y 20
//expr {$x + $y}  
//)";
//    file.write(script.c_str(), script.length());
//    file.flush();
//    file.close();
//
//    ////////////////////////////////////////////////////////////////////////////
//
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
//    if (Tcl_EvalFile(interp, "script.tcl") != TCL_OK) {
//        fprintf(stderr, "脚本执行失败: %s\n", Tcl_GetStringResult(interp));
//        Tcl_DeleteInterp(interp);
//        return ;
//    }
//
//    const char* result = Tcl_GetStringResult(interp);
//    printf("脚本执行结果: %s\n", result);
//
//    Tcl_DeleteInterp(interp);
//}
//
//int main() {
//    _Test_EvalFile();
//
//    return 0;
//}