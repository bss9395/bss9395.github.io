/* Java_ProcessBuilder.java
Author: BSS9395
Update: 2023-04-28T17:50:00+08@China-Guangdong-Zhanjiang+08
Design: Java Standard Library: ProcessBuilder
*/

import java.util.Scanner;

public class Java_ProcessBuilder {
	static public String  _cls[] = System.getProperty("os.name").toLowerCase().startsWith("windows")
			? new String[] {
				"cmd", "/c", "cls"
			}
			: new String[] {
				"sh", "-c", "clear"
			};
	static public int _side_x = 12;
	static public int _side_y = 10;
	static public int _consecutive = 5;
	static public char _cross = '+';
	static public char _chess = '⊗';

	public char[][] _board  = new char[_side_x][_side_y];
	public Java_ProcessBuilder() {
		for (int x = 0; x < _side_x; x += 1) {
			for (int y = 0; y < _side_y; y += 1) {
				_board[x][y] = _cross;
			}
		}

		////////////////////////////////////////////////////////////////////////

		_Print_Board();
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
				if (0 <= pos_x && pos_x < _side_x && 0 <= pos_y && pos_y < _side_y) {
					if (_board[pos_x][pos_y] != _chess) {
						_board[pos_x][pos_y] = _chess;
						builder.start().waitFor();
						_Print_Board();
					} else {
						System.out.printf("[%s, %s] == %s%n", pos_x, pos_y, _chess);
					}
				} else {
					throw new IndexOutOfBoundsException(String.format("[%s, %s] out of [%s, %s]", pos_x, pos_y, _side_x, _side_y));
				}

				// if(true == _Validate()) {
				if(true == _Validate(pos_x, pos_y)) {
					System.out.println("Congratulation! You win!");
					break;
				}
			} catch (Exception exception) {
				System.err.printf("输入坐标有误！%s%n", exception);
			}
		}
	}

	public void _Print_Board() {
		for(int row = _side_y - 1; 0 <= row; row -= 1) {
			for(int col = 0; col < _side_x; col += 1) {
				System.out.print(_board[col][row]);
			}
			System.out.println();
		}
	}

	public boolean _Validate() {
		for(int head_x = 0, tail_x = (_side_x - 1) - _consecutive + 1; head_x <= tail_x; head_x += 1) {
			for(int head_y = 0, tail_y = (_side_y - 1) - _consecutive + 1; head_y <= tail_y; head_y += 1) {
				int x = 0;
				for(; x < _consecutive; x += 1) {
					if(_board[head_x + x][head_y] != _chess) {
						break;
					}
				}
				if(x == _consecutive) {
					return true;
				}

				int y = 0;
				for(; y < _consecutive; y += 1) {
					if(_board[head_x][head_y + y] != _chess) {
						break;
					}
				}
				if(y == _consecutive) {
					return true;
				}

				int xy = 0;
				for(; xy < _consecutive; xy += 1) {
					if(_board[head_x + xy][head_y + xy] != _chess) {
						break;
					}
				}
				if(xy == _consecutive) {
					return true;
				}

				int yx = 0;
				for(; yx < _consecutive; yx += 1) {
					if(_board[head_x + yx][head_y + _consecutive - 1 - yx] != _chess) {
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
	public boolean _Validate(int posi_x, int posi_y) {
		int head_x = 0;
		int tail_x = 0;
		int head_y = 0;
		int tail_y = 0;

		////////////////////////////////////////////////////////////////////////

		head_x = posi_x - _consecutive + 1;
		tail_x = posi_x;
		if(false == (0 <= head_x)) {
			head_x = 0;
		}
		if(false == (tail_x + _consecutive - 1 < _side_x)) {
			tail_x = _side_x - 1 + 1 - _consecutive;
		}
		for( ; head_x <= tail_x; head_x += 1) {
			int x = 0;
			for( ; x < _consecutive; x += 1) {
				if(_board[head_x + x][posi_y] != _chess) {
					System.out.printf("[%s, %s]%s%n", head_x + x, posi_y, _board[head_x + x][posi_y]);
					head_x = head_x + x;
					break;
				}
			}
			if(x == _consecutive) {
				return true;
			}
		}

		////////////////////////////////////////////////////////////////////////

		head_y = posi_y - _consecutive + 1;
		tail_y = posi_y;
		if(false == (0 <= head_y)) {
			head_y = 0;
		}
		if(false == (tail_y + _consecutive - 1 < _side_y)) {
			tail_y = _side_y - 1 + 1 - _consecutive;
		}
		for( ; head_y <= tail_y; head_y += 1) {
			int y = 0;
			for( ; y < _consecutive; y += 1) {
				if(_board[posi_x][head_y + y] != _chess) {
					System.out.printf("[%s, %s]%s%n", posi_x, head_y + y, _board[posi_x][head_y + y]);
					head_y = head_y + y;
					break;
				}
			}
			if(y == _consecutive) {
				return true;
			}
		}

		////////////////////////////////////////////////////////////////////////

		// y = x + y_0;
		int posi_xy = posi_y - posi_x;
		head_x = posi_x - _consecutive + 1;
		tail_x = posi_x;
		if(false == (0 <= head_x)) {
			head_x = 0;
		}
		if(false == (head_x + posi_xy) < _side_y) {
			head_x = _side_y - 1 - posi_xy;
		}
		if(false == (tail_x + _consecutive - 1 < _side_x)) {
			tail_x = _side_x - 1 + 1 - _consecutive;
		}
		if(false == (tail_x + _consecutive - 1 + posi_xy < _side_y)) {
			tail_x = _side_y - 1 - posi_xy + 1 - _consecutive;
		}
		for( ; head_x <= tail_x; head_x += 1) {
			int xy = 0;
			for( ; xy < _consecutive; xy += 1) {
				if(_board[head_x + xy][head_x + xy + posi_xy] != _chess) {
					System.out.printf("[%s, %s]%s%n", head_x + xy, head_x + xy + posi_xy, _board[head_x + xy][head_x + xy + posi_xy]);
					head_x = head_x + xy;
					break;
				}
			}
			if(xy == _consecutive) {
				return true;
			}
		}

		////////////////////////////////////////////////////////////////////////

		// y = -x + y_0;
		int posi_yx = posi_y + posi_x;
		head_x = posi_x - _consecutive + 1;
		tail_x = posi_x;
		if(false == (0 <= head_x)) {
			head_x = 0;
		}
		if(false == (-head_x + posi_yx < _side_y)) {
			head_x = -(_side_y - 1 - posi_yx);
		}
		if(false == (tail_x + _consecutive - 1 < _side_x)) {
			tail_x = _side_x - 1 + 1 - _consecutive;
		}
		if(false == (-(tail_x + _consecutive - 1) + posi_yx < _side_y)) {
			tail_x = -(_side_y - 1 - posi_yx) + 1 - _consecutive;
		}
		for( ; head_x <= tail_x; head_x += 1) {
			int yx = 0;
			for( ; yx < _consecutive; yx += 1) {
				if(_board[head_x + yx][-(head_x + yx) + posi_yx] != _chess) {
					System.out.printf("[%s, %s]%s%n", head_x + yx, -(head_x + yx) + posi_yx, _board[head_x + yx][-(head_x + yx) + posi_yx]);
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
		new Java_ProcessBuilder();
	}
}
