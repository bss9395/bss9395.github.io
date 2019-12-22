#if 0
#include <thread>
class thread;
#endif 

#include <iostream>    
#include <thread>      
#include <mutex>       

using namespace std;

static mutex mtx;

void print(string str) {
	mtx.lock();
	for (int i = 0; i < str.size(); ++i) {
		cout << str[i];
	}
	cout << endl;
	mtx.unlock();
}

int main(int argc, char* argv[]) {
	thread th01(print, "abcdefghijklmnopqrstuvwxyz");
	thread th02(print, "ABCEDFGHIJKLMNOPQRSTUVWXYZ");

	th01.join();
	th02.join();
	return 0;
}