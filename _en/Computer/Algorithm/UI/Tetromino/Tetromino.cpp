/* Tetromino.cpp
Author: BSS9395
Update: 2023-08-15T20:25:00+08@China-Guangdong-Zhanjiang+08
Design: Tetromino
*/

#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <conio.h>

#include <array>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Tetromino {
public:
	struct Shape {
		struct Matrix {
			wchar_t _matrix[4][4];
		};

		short _textback = 0;
		short _textfore = 0;
		Matrix _shapes[4] = {};
	};

	struct Block {
		int _x = 0;
		int _y = 0;
		int _index = 0;
		int _orient = 0;
	};

public:
	static inline const int   _count_shapes = 7;
	static inline const short _text_black_white = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	static inline const int   _board_width = 1 + 12 + 1;
	static inline const int   _board_height = 1 + 18 + 1;

	HANDLE  _handle                             = GetStdHandle(STD_OUTPUT_HANDLE);
	FILE*   _output                             = stdout;
	int     _count                              = 0;
	Shape*  _shapes[_count_shapes]              = {};
	Block   _moving                             = {};
	Block   _project                            = {};
	wchar_t _board[_board_width][_board_height] = {};

	Tetromino() {
		/* I */
		_shapes[0] = new Shape{};
		_shapes[0]->_textback = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_BLUE;  // 179
		_shapes[0]->_textfore = BACKGROUND_GREEN | BACKGROUND_BLUE;                                                              // 48
		_shapes[0]->_shapes[0] = {
			L' ', L'I', L' ', L' ',
			L' ', L'I', L' ', L' ',
			L' ', L'I', L' ', L' ',
			L' ', L'I', L' ', L' '
		};
		_shapes[0]->_shapes[1] = {
			L' ', L' ', L' ', L' ',
			L' ', L' ', L' ', L' ',
			L'I', L'I', L'I', L'I',
			L' ', L' ', L' ', L' '
		};
		_shapes[0]->_shapes[2] = {
			L' ', L' ', L'I', L' ',
			L' ', L' ', L'I', L' ',
			L' ', L' ', L'I', L' ',
			L' ', L' ', L'I', L' '
		};
		_shapes[0]->_shapes[3] = {
			L' ', L' ', L' ', L' ',
			L'I', L'I', L'I', L'I',
			L' ', L' ', L' ', L' ',
			L' ', L' ', L' ', L' '
		};

		/* O */
		_shapes[1] = new Shape{};
		_shapes[1]->_textback = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_GREEN;    // 230
		_shapes[1]->_textfore = BACKGROUND_RED | BACKGROUND_GREEN;                                                               // 96
		_shapes[1]->_shapes[0] = {
			L' ', L' ', L' ', L' ',
			L' ', L'O', L'O', L' ',
			L' ', L'O', L'O', L' ',
			L' ', L' ', L' ', L' '
		};
		_shapes[1]->_shapes[1] = {
			L' ', L' ', L' ', L' ',
			L' ', L'O', L'O', L' ',
			L' ', L'O', L'O', L' ',
			L' ', L' ', L' ', L' '
		};
		_shapes[1]->_shapes[2] = {
			L' ', L' ', L' ', L' ',
			L' ', L'O', L'O', L' ',
			L' ', L'O', L'O', L' ',
			L' ', L' ', L' ', L' '
		};
		_shapes[1]->_shapes[3] = {
			L' ', L' ', L' ', L' ',
			L' ', L'O', L'O', L' ',
			L' ', L'O', L'O', L' ',
			L' ', L' ', L' ', L' '
		};

		/* T */
		_shapes[2] = new Shape{};
		_shapes[2]->_textback = BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_GREEN;                                      // 162
		_shapes[2]->_textfore = BACKGROUND_GREEN;                                                                                // 32
		_shapes[2]->_shapes[0] = {
			L' ', L' ', L' ', L' ',
			L' ', L'T', L' ', L' ',
			L' ', L'T', L'T', L' ',
			L' ', L'T', L' ', L' '
		};
		_shapes[2]->_shapes[1] = {
			L' ', L' ', L' ', L' ',
			L' ', L' ', L'T', L' ',
			L' ', L'T', L'T', L'T',
			L' ', L' ', L' ', L' '
		};
		_shapes[2]->_shapes[2] = {
			L' ', L' ', L'T', L' ',
			L' ', L'T', L'T', L' ',
			L' ', L' ', L'T', L' ',
			L' ', L' ', L' ', L' '
		};
		_shapes[2]->_shapes[3] = {
			L' ', L' ', L' ', L' ',
			L'T', L'T', L'T', L' ',
			L' ', L'T', L' ', L' ',
			L' ', L' ', L' ', L' '
		};

		/* J */
		_shapes[3] = new Shape{};
		_shapes[3]->_textback = BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_BLUE;                                            // 49
		_shapes[3]->_textfore = BACKGROUND_BLUE;                                                                                 // 16
		_shapes[3]->_shapes[0] = {
			L' ', L' ', L' ', L' ',
			L' ', L'J', L'J', L' ',
			L' ', L'J', L' ', L' ',
			L' ', L'J', L' ', L' '
		};
		_shapes[3]->_shapes[1] = {
			L' ', L' ', L' ', L' ',
			L' ', L'J', L' ', L' ',
			L' ', L'J', L'J', L'J',
			L' ', L' ', L' ', L' '
		};
		_shapes[3]->_shapes[2] = {
			L' ', L' ', L'J', L' ',
			L' ', L' ', L'J', L' ',
			L' ', L'J', L'J', L' ',
			L' ', L' ', L' ', L' '
		};
		_shapes[3]->_shapes[3] = {
			L' ', L' ', L' ', L' ',
			L'J', L'J', L'J', L' ',
			L' ', L' ', L'J', L' ',
			L' ', L' ', L' ', L' '
		};

		/* L */
		_shapes[4] = new Shape{};
		_shapes[4]->_textback = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY;                      // 120
		_shapes[4]->_textfore = BACKGROUND_INTENSITY;                                                                            // 128
		_shapes[4]->_shapes[0] = {
			L' ', L' ', L' ', L' ',
			L' ', L'L', L'L', L' ',
			L' ', L' ', L'L', L' ',
			L' ', L' ', L'L', L' '
		};
		_shapes[4]->_shapes[1] = {
			L' ', L' ', L' ', L' ',
			L' ', L'L', L'L', L'L',
			L' ', L'L', L' ', L' ',
			L' ', L' ', L' ', L' '
		};
		_shapes[4]->_shapes[2] = {
			L' ', L'L', L' ', L' ',
			L' ', L'L', L' ', L' ',
			L' ', L'L', L'L', L' ',
			L' ', L' ', L' ', L' '
		};
		_shapes[4]->_shapes[3] = {
			L' ', L' ', L' ', L' ',
			L' ', L' ', L'L', L' ',
			L'L', L'L', L'L', L' ',
			L' ', L' ', L' ', L' '
		};

		/* Z */
		_shapes[5] = new Shape{};
		_shapes[5]->_textback = BACKGROUND_INTENSITY | BACKGROUND_RED | FOREGROUND_RED;                                          // 196
		_shapes[5]->_textfore = BACKGROUND_RED;                                                                                  // 64
		_shapes[5]->_shapes[0] = {
			L' ', L' ', L' ', L' ',
			L' ', L' ', L'Z', L' ',
			L' ', L'Z', L'Z', L' ',
			L' ', L'Z', L' ', L' '
		};
		_shapes[5]->_shapes[1] = {
			L' ', L' ', L' ', L' ',
			L' ', L'Z', L'Z', L' ',
			L' ', L' ', L'Z', L'Z',
			L' ', L' ', L' ', L' '
		};
		_shapes[5]->_shapes[2] = {
			L' ', L' ', L'Z', L' ',
			L' ', L'Z', L'Z', L' ',
			L' ', L'Z', L' ', L' ',
			L' ', L' ', L' ', L' '
		};
		_shapes[5]->_shapes[3] = {
			L' ', L' ', L' ', L' ',
			L'Z', L'Z', L' ', L' ',
			L' ', L'Z', L'Z', L' ',
			L' ', L' ', L' ', L' '
		};

		/* S */
		_shapes[6] = new Shape{};
		_shapes[6]->_textback = BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_GREEN;                                      // 162
		_shapes[6]->_textfore = BACKGROUND_GREEN;                                                                                // 32
		_shapes[6]->_shapes[0] = {
			L' ', L' ', L' ', L' ',
			L' ', L'S', L' ', L' ',
			L' ', L'S', L'S', L' ',
			L' ', L' ', L'S', L' '
		};
		_shapes[6]->_shapes[1] = {
			L' ', L' ', L' ', L' ',
			L' ', L' ', L'S', L'S',
			L' ', L'S', L'S', L' ',
			L' ', L' ', L' ', L' '
		};
		_shapes[6]->_shapes[2] = {
			L' ', L'S', L' ', L' ',
			L' ', L'S', L'S', L' ',
			L' ', L' ', L'S', L' ',
			L' ', L' ', L' ', L' '
		};
		_shapes[6]->_shapes[3] = {
			L' ', L' ', L' ', L' ',
			L' ', L'S', L'S', L' ',
			L'S', L'S', L' ', L' ',
			L' ', L' ', L' ', L' '
		};

		////////////////////////////////////////////////////////////////////////

		//string command = string();
		//command.resize(256);
		//sprintf(&command[0], "mode con cols=%d lines=%d", _board_width * 3, _board_height * 2);
		//system(&command[0]);
		system("clear");
		CONSOLE_CURSOR_INFO console_cursor_info = { 1, 0 };  // note: { size, visible }
		SetConsoleCursorInfo(_handle, &console_cursor_info);

		//////////////////////////////////////////////////////////////////////////////

		for (int begx = 0, endx = _board_width - 1; begx <= endx; begx += 1) {
			for (int begy = 0, endy = _board_height - 1; begy <= endy; begy += 1) {
				if (begx == 0 || begx == endx || begy == 0 || begy == endy) {
					_board[begx][begy] = L'#';
				}
				else {
					_board[begx][begy] = L' ';
				}
			}
		}

		for (int begx = 0, endx = _board_width - 1; begx <= endx; begx += 1) {
			for (int begy = 0, endy = _board_height - 1; begy <= endy; begy += 1) {
				_GotoXY(begx, begy);
				_Set_Color(_text_black_white);
				fwprintf(_output, L"%lc", _board[begx][begy]);
			}
		}

		_Gamming();
	}

	auto _Print_Block_Next() -> void {
		_Set_Color(_text_black_white);
		_GotoXY(0, _board_height);
		fwprintf(stdout, L"=next=");
		_GotoXY(0, _board_height + 1);
		fwprintf(stdout, L"|    |");
		_GotoXY(0, _board_height + 2);
		fwprintf(stdout, L"|    |");
		_GotoXY(0, _board_height + 3);
		fwprintf(stdout, L"|    |");
		_GotoXY(0, _board_height + 4);
		fwprintf(stdout, L"|    |");
		_GotoXY(0, _board_height + 5);
		fwprintf(stdout, L"======");

		for (int row = 0; row < 4; row += 1) {
			for (int col = 0; col < 4; col += 1) {
				_GotoXY(col + 1, _board_height + 1 + row);
				fwprintf(stdout, L"%lc", L' ');
			}
		}

		_Set_Color(_shapes[_moving._index]->_textback);
		for (int row = 0; row < 4; row += 1) {
			for (int col = 0; col < 4; col += 1) {
				if (_shapes[_moving._index]->_shapes[_moving._orient]._matrix[row][col] != L' ') {
					_GotoXY(col + 1, _board_height + 1 + row);
					fwprintf(stdout, L"%lc", _shapes[_moving._index]->_shapes[_moving._orient]._matrix[row][col]);
				}
			}
		}
	}

	auto _Print_Block(Block block, int mode) -> void {
		if (mode == 0) {
			_Set_Color(_shapes[block._index]->_textback);
		}
		else if (mode == 1) {
			_Set_Color(_shapes[block._index]->_textfore);
		}
		else if (mode == 2) {
			_Set_Color(_text_black_white);
		}

		for (int col = 0; col < 4; col += 1) {
			for (int row = 0; row < 4; row += 1) {
				if (0 < block._x + col && block._x + col < _board_width - 1 && 0 < block._y + row && block._y + row < _board_height - 1) {
					if (_shapes[block._index]->_shapes[block._orient]._matrix[row][col] != L' ') {
						_GotoXY(block._x + col, block._y + row);
						if (mode == 2) {
							fwprintf(stdout, L" ");
						}
						else {
							fwprintf(stdout, L"%lc", _shapes[block._index]->_shapes[block._orient]._matrix[row][col]);
						}
					}
				}
			}
		}
	}

	auto _Project_Block() -> void {
		if (0 <= _project._index) {
			_Print_Block(_project, 2);  // note: hide
		}

		_project = _moving;
		while (false == (_Collided(_project._x, _project._y + 1, _project._index, _project._orient))) {
			_project._y += 1;
		}
		_Print_Block(_project, 0);      // note: show
	}

	auto _Collided(int x, int y, int index, int orient) -> bool {
		for (int col = 0; col < 4; col += 1) {
			for (int row = 0; row < 4; row += 1) {
				if (_shapes[index]->_shapes[orient]._matrix[row][col] != L' ' && 0 < y + row) {
					if (false == (0 < x + col && x + col < _board_width - 1 && y + row < _board_height - 1)) {
						return true;
					}
					else if (_board[x + col][y + row] != L' ') {
						return true;
					}
				}
			}
		}
		return false;
	}

	auto _Line_Check() -> void {
		// 填充数据
		for (int col = 0; col < 4; col += 1) {
			for (int row = 0; row < 4; row += 1) {
				wchar_t hold = _shapes[_moving._index]->_shapes[_moving._orient]._matrix[row][col];
				if (hold != L' ') {
					_board[_moving._x + col][_moving._y + row] = hold;
				}
			}
		}

		// 待删除的行
		vector<int> lines;
		for (int line = _moving._y; line < _board_height - 1 && line < _moving._y + 4; line += 1) {
			bool flag = true;
			for (int col = 1; col < _board_width - 1; col += 1) {
				if (_board[col][line] == L' ') {
					flag = false;
					break;
				}
			}
			if (flag == true) {
				lines.push_back(line);
			}
		}
		if (lines.size() <= 0) {
			return;
		}

		// 删除行
		for (int i = 0; i < lines.size(); i += 1) {
			for (int col = 0; col < _board_width / 2; col += 1) {
				_GotoXY(_board_width / 2 - col, lines[i]);
				_Set_Color(_text_black_white);
				fwprintf(stdout, L" ");
				_GotoXY(_board_width / 2 + col - 1, lines[i]);
				_Set_Color(_text_black_white);
				fwprintf(stdout, L" ");
			}
		}

		// 覆盖数据
		for (int i = 0; i < lines.size(); i += 1) {
			for (int row = lines[i]; 1 <= row; row -= 1) {
				for (int col = 1; col < _board_width - 1; col += 1) {
					if (row == 1) {
						_board[col][row] = L' ';
					}
					else {
						_board[col][row] = _board[col][row - 1];
					}
				}
			}
		}

		// 界面打印
		for (int row = 0; row < _moving._y + 4 && row < _board_height - 1; row += 1) {
			for (int col = 1; col < _board_width - 1; col += 1) {
				_GotoXY(col, row);
				if (_board[col][row] == L' ') {
					_Set_Color(_text_black_white);
					fwprintf(stdout, L" ");
				}
				else {
					_Set_Color(48);
					fwprintf(stdout, L"@");
				}
			}
		}
	}

	auto _Gamming() -> void {
		while (true) {
			if (_moving._index == 0) {
				_Shuffle_Shape();
			}
			// _moving._index = (_moving._index + 1) % _count_shapes;
			_moving._index = 2;
			_moving._orient = 0;
			_moving._x = 4;
			_moving._y = 0;
			_Print_Block_Next();

			if (true == _Collided(_moving._x, _moving._y + 1, _moving._index, _moving._orient)) {
				_Print_Block(_moving, 1);
				break;
			}
			// _Project_Block();

			while (true) {
				_Print_Block(_moving, 1);  // note: show
				Sleep(200);
				_Print_Block(_moving, 2);  // note: hide

				if (0 != _kbhit()) {
					int key = _getch();
					if (key == 224) {          // note: Extended, 224=0xE0
						key = _getch();
						if (key == 75) {       // note: LEFT
							if (false == _Collided(_moving._x - 1, _moving._y, _moving._index, _moving._orient)) {
								_moving._x -= 1;
							}
						}
						else if (key == 77) {  // note: RIGHT
							if (false == _Collided(_moving._x + 1, _moving._y, _moving._index, _moving._orient)) {
								_moving._x += 1;
							}
						}
						else if (key == 72) {  // note: UP
							if (false == _Collided(_moving._x, _moving._y, _moving._index, (_moving._orient + 1) % 4)) {
								_moving._orient = (_moving._orient + 1) % 4;
							}
						}
						else if (key == 80) {  // note: DOWN
							// nothing to do.
						}
					}
					else if (key == 32) {       // note: SPACE
						// _moving = _project;  // note: projection
						// break;               // note: projection
					}
					// _Project_Block();
				}
				else if (false == _Collided(_moving._x, _moving._y + 1, _moving._index, _moving._orient)) {
					_moving._y += 1;
				}
				else {
					break;
				}
			}
			_project._index = -1;
			_Print_Block(_moving, 1);
			_Line_Check();
		}
		_GotoXY(0, _board_height + 6);
		_Set_Color(_text_black_white);
	}

public:
	auto _Shuffle_Shape() -> void {
		static auto _Random_Integer = [](int mini, int maxi) -> int {
			return (mini + rand() % (maxi - mini + 1));
		};

		srand((unsigned)time(NULL));
		Shape* temp = nullptr;
		int times = _Random_Integer(0, sizeof(_shapes) / sizeof(_shapes[0]));
		for (int i = 0; i < times; i += 1) {
			int lhs = _Random_Integer(0, _count_shapes - 1);
			int rhs = _Random_Integer(0, _count_shapes - 1);
			temp = _shapes[lhs], _shapes[lhs] = _shapes[rhs], _shapes[rhs] = temp;
		}
	}

	auto _GotoXY(int x, int y) -> void {  
		COORD coord = COORD{};
		coord.X = (short)(x);
		coord.Y = (short)(y);
		SetConsoleCursorPosition(_handle, coord);
	}

	auto _Set_Color(int color) -> void {
		SetConsoleTextAttribute(_handle, color);
	}

};

int main(int argc, char* argv[]) {
	Tetromino tetromino = Tetromino();

	return 0;
}
