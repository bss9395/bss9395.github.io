/* Win_WriteFile.cpp
Author: bss9395
Update: 2024-09-07T23:09:00+08@China-Beijing+08
*/

#include <iostream>
#include <windows.h>

int main(int argc, char *argv[]) {
	HANDLE handle_input = GetStdHandle(STD_INPUT_HANDLE);
	if (handle_input == INVALID_HANDLE_VALUE) {
		std::cerr << "获取控制台输入句柄失败" << std::endl;
	}
	if (FlushFileBuffers(handle_input) == false) {
		std::cerr << "FlushFileBuffers失败" << std::endl;
		return EXIT_FAILURE;
	}

	HANDLE handle_output = GetStdHandle(STD_OUTPUT_HANDLE);
	if (handle_output == INVALID_HANDLE_VALUE) {
		std::cerr << "获取控制台输出句柄失败" << std::endl;
		return EXIT_FAILURE;
	}

	const char* text = "Hello, Windows Console!\n";
	DWORD written;
	BOOL result = WriteFile(handle_output, text, strlen(text), &written, NULL);
	if (result == false) {
		std::cerr << "WriteFile失败" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "成功输出了 " << written << " 个字节" << std::endl;
	return 0;
}
