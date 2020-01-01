/*Main.cpp
* Author: BSS9395
* Update: 2020-01-01T18:27:00+08@ShenZhen+08
* Design: Multiplexing_with_Turning
*/

#include "IOHandler.hpp"
#include "TCPHandler.hpp"

#define Main
#ifdef Main

int main(int argc, char *argv[]) {
	// IOHandler io;
	// Kernel::Run(Param());

	TCPServer server;
	Kernel::Update();

	return 0;
}

#endif // Main
