/* Class_Dll.h
Author: BSS9395
Update: 2022-11-01T22:04:00+08@China-Shanghai+08
Design: C/C++ Dynamic Link Library
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#if defined(_WIN32) || defined(_WIN64)
#	ifdef API_DLL 
#		define DECL_DLL __declspec(dllexport)
#	else
#		define DECL_DLL __declspec(dllimport)
#	endif
#else
#	define MY_DLL 
#endif

#ifdef __cplusplus
extern "C"
#endif

class Class_Dll {
public:
	DECL_DLL Class_Dll();
	DECL_DLL ~Class_Dll();
	DECL_DLL void _Hello(const std::string &message);
	DECL_DLL void _World(const std::string &message) {
		fprintf(stdout, "DECL_DLL void _World(const std::string& message) {""\n");
		fprintf(stdout, "%s""\n", message.c_str());
	}
};

#ifdef __cplusplus
extern "C"
#endif