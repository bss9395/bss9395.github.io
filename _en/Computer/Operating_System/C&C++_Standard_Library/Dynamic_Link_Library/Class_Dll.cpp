/* Class_Dll.cpp
Author: BSS9395
Update: 2022-11-01T22:04:00+08@China-Shanghai+08
Design: C/C++ Dynamic Link Library
*/

#include "Class_Dll.h"

DECL_DLL Class_Dll::Class_Dll() {

}

DECL_DLL Class_Dll::~Class_Dll() {

}

DECL_DLL void Class_Dll::_Hello(const std::string& message) {
	fprintf(stdout, "DECL_DLL void Class_Dll::Hello(const std::string& str) {""\n");
	fprintf(stdout, "%s""\n", message.c_str());
}