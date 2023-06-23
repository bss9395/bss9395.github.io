/* Line_Counter.cpp
Author: BSS9395
Update: 2023-06-18T16:36:00+08@China-Beijing+08
Design: Line Counter
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Line_Counter {
public:
	static auto _Line_Count_Filenames(const string& filenames) -> int {
		static auto _Line_Count_Filename_fgetc_fputc = [](const string& filename) -> int {
			int count = 0;
			FILE* file = fopen(&filename[0], "rt+");
			if (file == NULL) {
				return count;
			}

			char bina = fgetc(file);                   // note: pre-read a character to set the indicator of file.
			while (feof(file) == 0) {                  // note: count one line by one time.
				if (feof(file) == 0 && bina == '/') {  // note: only support the sign of line comment: //
					bina = fgetc(file);
					if (feof(file) == 0 && bina == '/') {
						bina = fgetc(file);
						while (feof(file) == 0 && bina != '\n') {
							bina = fgetc(file);
						}
						continue;
					}
					else {
						fseek(file, -1, SEEK_CUR);     // note: unknown behaviour when the character is not ASCII.
						bina = '/';
					}
				}
				else if (feof(file) == 0 && bina == '\n') {
					bina = fgetc(file);
					continue;
				}

				while (feof(file) == 0 && bina != '\n') {
					bina = fgetc(file);
				}
				count += 1;
			}
			fclose(file);
			return count;
		};
		static auto _Line_Count_Filename_Buffer = [](const string& filename) -> int {
			int count = 0;
			FILE* file = fopen(&filename[0], "rt");             // note: binary to text
			if (file == NULL) {
				return count;
			}

			fseek(file, 0, SEEK_END);
			int size = ftell(file);
			fseek(file, 0, SEEK_SET);
			string buffer = string{};
			buffer.resize(size), size = 0;
			for (char bina = fgetc(file); feof(file) == 0; ) {  // note: binary to text
				buffer[size] = bina, size += 1;
				bina = fgetc(file);
			}
			buffer.resize(size);
			fclose(file);

			for (int idx = 0; idx < size; ) {
				if (idx < size && buffer[idx] == '/') {
					idx += 1;
					if (idx < size && buffer[idx] == '/') {
						idx += 1;
						while (idx < size && buffer[idx] != '\n') {
							idx += 1;
						}
						continue;
					}
					else {
						idx -= 1;
					}
				}
				else if (idx < size && buffer[idx] == '\n') {
					idx += 1;
					continue;
				}

				while (idx < size && buffer[idx] != '\n') {
					idx += 1;
				}
				count += 1;
			}
			return count;
		};

		int total = 0;
		FILE* file = fopen(&filenames[0], "rt");
		if (file == NULL) {
			return total;
		}

		string filename = string{};
		filename.reserve(1024);
		char bina = fgetc(file);
		while (feof(file) == 0) {
			filename.clear();
			while (feof(file) == 0 && bina == '\n') {
				bina = fgetc(file);
			}
			while (feof(file) == 0 && bina != '\n') {
				filename += bina;
				bina = fgetc(file);
			}
			//  += _Line_Count_Filename_fgetc_fputc(filename);
			total += _Line_Count_Filename_Buffer(filename);
		}
		return total;
	}

public:
	static auto _Test_Line_Count_Filenames() -> void {
		int total = _Line_Count_Filenames("E:/Desktop/temp/filenames.dat");
		fwprintf(stdout, L"total lines = %d\n", total);
	}
};

int main(int argc, char* argv[]) {
	Line_Counter::_Test_Line_Count_Filenames();
	return 0;
}
