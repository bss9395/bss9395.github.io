

#ifndef WIN_DLL_H_
#define WIN_DLL_H_



#ifdef LIBRARY_EXPORT   
#define WIN_DLL __declspec(dllexport)
#else
#define WIN_DLL __declspec(dllimport) 
#endif

class WIN_DLL Library {
public:
	Library();
	int _Add(int a, int b);
	int _Sub(int a, int b);
};

#endif


