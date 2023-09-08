
#ifndef WIN_DLL_H_
#define WIN_DLL_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LIBRARY_EXPORT   
#define WIN_DLL __declspec(dllexport)
#else
#define WIN_DLL __declspec(dllimport) 
#endif

WIN_DLL int add(int a, int b);
WIN_DLL int sub(int a, int b);

#ifdef __cplusplus
}
#endif

#endif
