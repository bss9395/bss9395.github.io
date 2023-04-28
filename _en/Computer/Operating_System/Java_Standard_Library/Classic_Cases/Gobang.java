/* Gobang.java
Author: BSS9395
Update: 2023-04-28T17:50:00+08@China-Guangdong-Zhanjiang+08
Design: Gobang
*/

import java.util.Scanner;

public class Gobang {
	static public String  _cls[] = System.getProperty("os.name").toLowerCase().startsWith("windows")
			? new String[] {
				"cmd", "/c", "cls"
			}
			: new String[] {
				"sh", "-c", "clear"
			};
	static public int _square = 10;
	static public int _consecutive = 5;
	static public char _cross = '+';
	static public char _chess = '⊗';

	public char[][] _board  = new char[_square][_square];
	public Gobang() {
		for (int row = 0; row < _square; row += 1) {
			for (int col = 0; col < _square; col += 1) {
				_board[row][col] = _cross;
			}
		}

		////////////////////////////////////////////////////////////////////////

		_Print();
		ProcessBuilder builder = new ProcessBuilder(_cls).inheritIO();
		for(Scanner scanner = new Scanner(System.in); true; ) {
			try {
				System.out.print("请输入坐标[x, y]: ");
				String input = scanner.nextLine();
				if (input == null) {
					break;
				}
				String[] items = input.split(",");
				if(items.length != 2) {
					throw new IndexOutOfBoundsException("items.length != 2");
				}
				int pos_x = Integer.parseInt(items[0]);
				int pos_y = Integer.parseInt(items[1]);
				if (0 <= pos_x && pos_x < _square && 0 <= pos_y && pos_y < _square) {
					if (_board[pos_y][pos_x] != _chess) {
						_board[pos_y][pos_x] = _chess;
						builder.start().waitFor();
						_Print();
					} else {
						System.out.printf("[%s, %s] == %s%n", pos_x, pos_y, _chess);
					}
				} else {
					throw new IndexOutOfBoundsException("!(0 <= pos_x && pos_x < _square && 0 <= pos_y && pos_y < _square)");
				}

				if(true == _Validate()) {
					System.out.println("Congratulation! You win!");
					break;
				}
			} catch (Exception exception) {
				System.err.printf("输入坐标有误！%s%n", exception);
			}
		}
	}

	public void _Print() {
		for (int row = 0; row < _square; row += 1) {
			for (int col = 0; col < _square; col += 1) {
				System.out.print(_board[row][col]);
			}
			System.out.println();
		}
	}

	public boolean _Validate() {
		for(int beg_x = 0, end_x = _square - _consecutive; beg_x < end_x; beg_x += 1) {
			for(int beg_y = 0, end_y = _square - _consecutive; beg_y < end_y; beg_y += 1) {
				int x = 0;
				for(; x < _consecutive; x += 1) {
					if(_board[beg_x + x][beg_y] != _chess) {
						break;
					}
				}
				if(x == _consecutive) {
					return true;
				}

				int y = 0;
				for(; y < _consecutive; y += 1) {
					if(_board[beg_x][beg_y + y] != _chess) {
						break;
					}
				}
				if(y == _consecutive) {
					return true;
				}

				int xy = 0;
				for(; xy < _consecutive; xy += 1) {
					if(_board[beg_x + xy][beg_y + xy] != _chess) {
						break;
					}
				}
				if(xy == _consecutive) {
					return true;
				}

				int yx = 0;
				for(; yx < _consecutive; yx += 1) {
					if(_board[beg_x + yx][beg_y + _consecutive - 1 - yx] != _chess) {
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

	static public void main(String[] args) {
		new Gobang();
	}
}
