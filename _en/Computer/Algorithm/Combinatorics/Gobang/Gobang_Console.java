/* Gobang_Console.java
Author: BSS9395
Update: 2023-04-28T17:50:00+08@China-Guangdong-Zhanjiang+08
Design: Gobang with Console
*/

import java.util.Scanner;

public class Gobang_Console {
	static public String _clear[] = System.getProperty("os.name").toLowerCase().startsWith("windows")
			? new String[] {
				"cmd", "/c", "cls"
			}
			: new String[] {
				"sh", "-c", "clear"
			};
	static public int  _board_x     = 12;
	static public int  _board_y     = 10;
	static public char _chess_cross = '+';
	static public char _chess_black = 'X';
	static public char _chess_white = _chess_black;
	// static public char _chess_white = 'O';
	static public int  _consecutive = 5;

	public char[][] _board       = new char[_board_x][_board_y];
	public int      _chess_count = 0;
	public Gobang_Console() {
		for (int x = 0; x < _board_x; x += 1) {
			for (int y = 0; y < _board_y; y += 1) {
				_board[x][y] = _chess_cross;
			}
		}

		////////////////////////////////////////////////////////////////////////

		_Print_Board();
		for(Scanner scanner = new Scanner(System.in); true; ) {
			try {
				System.out.print("Input Chess Coordination [x, y]: ");
				String input = scanner.nextLine();
				if (input == null) {
					break;
				}
				String[] items = input.split(",");
				if(items.length != 2) {
					throw new IndexOutOfBoundsException("items.length != 2");
				}
				int index_x = Integer.parseInt(items[0]);
				int index_y = Integer.parseInt(items[1]);
				if (0 <= index_x && index_x < _board_x && 0 <= index_y && index_y < _board_y) {
					if (_board[index_x][index_y] == _chess_cross) {
						_board[index_x][index_y] = (_chess_count % 2 == 0) ? _chess_black : _chess_white;
						_chess_count += 1;
						_Print_Board();

						// if(true == _Validate(_board[index_x][index_y])) {
						if(true == _Validate(index_x, index_y)) {
							String message = (_board[index_x][index_y] == _chess_black) ? "BLACK win, WHITE lose!" : "WHITE win, BLACK lose!";
							message += "\nPlay again? (Y or N): ";
							System.out.printf(message);
							String result = scanner.nextLine();
							_Replay(result.toUpperCase().equals("Y") ? true : false);
						}
					} else {
						System.out.printf("[%s, %s]%s%n", index_x, index_y, _board[index_x][index_y]);
					}
				} else {
					throw new IndexOutOfBoundsException(String.format("[%s, %s] out of [%s, %s]", index_x, index_y, _board_x, _board_y));
				}
			} catch (Exception exception) {
				System.err.printf("Incorrect input: %s%n", exception);
			}
		}
	}
	public void _Replay(boolean result) {
		try {
			if (result == true) {
				this.finalize();
				new Gobang_Console();
			} else {
				System.exit(0);
			}
		} catch (Throwable throwable) {
			throwable.printStackTrace();
		}
	}

	public void _Print_Board() {
		try {
			ProcessBuilder builder = new ProcessBuilder(_clear).inheritIO();
			builder.start().waitFor();

			for (int row = _board_y - 1; 0 <= row; row -= 1) {
				for (int col = 0; col < _board_x; col += 1) {
					System.out.print(_board[col][row]);
				}
				System.out.println();
			}
		} catch (Exception exception) {
			exception.printStackTrace();
		}
	}

	public boolean _Validate(char chess) {
		for(int head_x = 0, tail_x = (_board_x - 1) - _consecutive + 1; head_x <= tail_x; head_x += 1) {
			for(int head_y = 0, tail_y = (_board_y - 1) - _consecutive + 1; head_y <= tail_y; head_y += 1) {
				int x = 0;
				for(; x < _consecutive; x += 1) {
					if(_board[head_x + x][head_y] != chess) {
						break;
					}
				}
				if(x == _consecutive) {
					return true;
				}

				////////////////////////////////////////////////////////////////

				int y = 0;
				for(; y < _consecutive; y += 1) {
					if(_board[head_x][head_y + y] != chess) {
						break;
					}
				}
				if(y == _consecutive) {
					return true;
				}

				////////////////////////////////////////////////////////////////

				int xy = 0;
				for(; xy < _consecutive; xy += 1) {
					if(_board[head_x + xy][head_y + xy] != chess) {
						break;
					}
				}
				if(xy == _consecutive) {
					return true;
				}

				////////////////////////////////////////////////////////////////

				int yx = 0;
				for(; yx < _consecutive; yx += 1) {
					if(_board[head_x + yx][head_y + _consecutive - 1 - yx] != chess) {
						break;
					}
				}
				if(yx == _consecutive) {
					return true;
				}
			}
		}
		return false;
	}
	public boolean _Validate(int index_x, int index_y) {
		char chess = _board[index_x][index_y];
		int head_x = 0;
		int tail_x = 0;
		int head_y = 0;
		int tail_y = 0;

		////////////////////////////////////////////////////////////////////////

		head_x = index_x - _consecutive + 1;
		tail_x = index_x;
		if(false == (0 <= head_x)) {
			head_x = 0;
		}
		if(false == (tail_x + _consecutive - 1 < _board_x)) {
			tail_x = _board_x - 1 + 1 - _consecutive;
		}
		for( ; head_x <= tail_x; head_x += 1) {
			int x = 0;
			for( ; x < _consecutive; x += 1) {
				if(_board[head_x + x][index_y] != chess) {
					System.out.printf("[%s, %s]%s, %s%n", head_x + x, index_y, chess, _board[head_x + x][index_y]);
					head_x = head_x + x;
					break;
				}
			}
			if(x == _consecutive) {
				return true;
			}
		}

		////////////////////////////////////////////////////////////////////////

		head_y = index_y - _consecutive + 1;
		tail_y = index_y;
		if(false == (0 <= head_y)) {
			head_y = 0;
		}
		if(false == (tail_y + _consecutive - 1 < _board_y)) {
			tail_y = _board_y - 1 + 1 - _consecutive;
		}
		for( ; head_y <= tail_y; head_y += 1) {
			int y = 0;
			for( ; y < _consecutive; y += 1) {
				if(_board[index_x][head_y + y] != chess) {
					System.out.printf("[%s, %s]%s, %s%n", index_x, head_y + y, chess, _board[index_x][head_y + y]);
					head_y = head_y + y;
					break;
				}
			}
			if(y == _consecutive) {
				return true;
			}
		}

		////////////////////////////////////////////////////////////////////////

		/* y = x + y_0; */
		int index_xy = index_y - index_x;
		head_x = index_x - _consecutive + 1;
		tail_x = index_x;
		if(false == (0 <= head_x)) {
			head_x = 0;
		}
		if(false == (head_x + index_xy) < _board_y) {
			head_x = _board_y - 1 - index_xy;
		}
		if(false == (tail_x + _consecutive - 1 < _board_x)) {
			tail_x = _board_x - 1 + 1 - _consecutive;
		}
		if(false == (tail_x + _consecutive - 1 + index_xy < _board_y)) {
			tail_x = _board_y - 1 - index_xy + 1 - _consecutive;
		}
		for( ; head_x <= tail_x; head_x += 1) {
			int xy = 0;
			for( ; xy < _consecutive; xy += 1) {
				if(_board[head_x + xy][head_x + xy + index_xy] != chess) {
					System.out.printf("[%s, %s]%s, %s%n", head_x + xy, head_x + xy + index_xy, chess, _board[head_x + xy][head_x + xy + index_xy]);
					head_x = head_x + xy;
					break;
				}
			}
			if(xy == _consecutive) {
				return true;
			}
		}

		////////////////////////////////////////////////////////////////////////

		/* y = -x + y_0; */
		int index_yx = index_y + index_x;
		head_x = index_x - _consecutive + 1;
		tail_x = index_x;
		if(false == (0 <= head_x)) {
			head_x = 0;
		}
		if(false == (-head_x + index_yx < _board_y)) {
			head_x = -(_board_y - 1 - index_yx);
		}
		if(false == (tail_x + _consecutive - 1 < _board_x)) {
			tail_x = _board_x - 1 + 1 - _consecutive;
		}
		if(false == (-(tail_x + _consecutive - 1) + index_yx < _board_y)) {
			tail_x = -(_board_y - 1 - index_yx) + 1 - _consecutive;
		}
		for( ; head_x <= tail_x; head_x += 1) {
			int yx = 0;
			for( ; yx < _consecutive; yx += 1) {
				if(_board[head_x + yx][-(head_x + yx) + index_yx] != chess) {
					System.out.printf("[%s, %s]%s, %s%n", head_x + yx, -(head_x + yx) + index_yx, chess, _board[head_x + yx][-(head_x + yx) + index_yx]);
					head_x = head_x + yx;
					break;
				}
			}
			if(yx == _consecutive) {
				return true;
			}
		}

		return false;
	}

	static public void main(String[] args) {
		new Gobang_Console();
	}
}
