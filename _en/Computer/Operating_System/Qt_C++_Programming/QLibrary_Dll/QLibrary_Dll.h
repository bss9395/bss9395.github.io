/* QLibrary_Dll.h
Author: BSS9395
Update: 2022-07-25T01:45:00+08@China-Shanghai+08
Design: QLibrary_Dll
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef QLibrary_Dll_h
#define QLibrary_Dll_h

extern "C" {
    __declspec(dllexport) double _Addition(double lhs, double rhs) {
        return (lhs + rhs);
    }
}

#endif // QLibrary_Dll_h
