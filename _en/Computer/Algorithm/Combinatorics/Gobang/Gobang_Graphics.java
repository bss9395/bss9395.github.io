/* Gobang_Graphics.java
Author: BSS9395
Update: 2023-05-10T17:45:00+08@China-Guangdong-Zhanjiang+08
Design: Gobang with Graphics
*/

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.image.*;
import javax.imageio.*;
import java.io.*;

public class Gobang_Graphics extends JDialog {
	static class Popup extends JDialog {
		static public String _stamp_none = "none";
		static public String _stamp_nega = "nega";
		static public String _stamp_posi = "posi";
		public String _result = _stamp_none;

		public Popup     _self    = this;
		public ImageIcon _icon    = new ImageIcon("images/info.svg.png");
		public JLabel    _image   = new JLabel();
		public JTextArea _message = new JTextArea();
		public JButton   _nega    = new JButton("取消");
		public JButton   _posi    = new JButton("确定");
		public Popup(JDialog parent, boolean modal, String title, String message) throws Exception {
			super(parent, modal);

			Box b_center = Box.createVerticalBox();
			JPanel p_message = new JPanel();
			Box b_image = Box.createVerticalBox();
			_icon.setImage(_icon.getImage().getScaledInstance(36, 36, Image.SCALE_SMOOTH));
			_image.setIcon(_icon);
			b_image.add(_image);
			p_message.add(b_image);
			_message.setEditable(false);
			_message.setPreferredSize(new Dimension(200, 48));
			p_message.add(_message);
			p_message.setPreferredSize(new Dimension(250, 48));
			b_center.add(p_message);

			Box b_button = Box.createHorizontalBox();
			b_button.add(Box.createHorizontalGlue());
			b_button.add(_nega);
			b_button.add(_posi);
			b_center.add(b_button);

			_self.add(b_center);
			_self.pack();
			_self.setResizable(false);

			////////////////////////////////////////////////////////////////////

			_self.setTitle(title);
			_message.setText(message);

			_nega.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent event) {
					_self._result = _stamp_nega;
					_self.setVisible(false);
				}
			});
			_posi.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent event) {
					_self._result = _stamp_posi;
					_self.setVisible(false);
				}
			});
		}

		static public String _Popup(JDialog parent, String title, String message) {
			String result = Popup._stamp_none;
			try {
				Popup popup = new Popup(parent, true, title, message);
				popup.setLocationRelativeTo(null);
				popup.setVisible(true);
				System.out.println("popup.setVisible(true);");
				result = popup._result;
				popup.dispose();
			} catch (Exception exception) {
				exception.printStackTrace();
			}
			return result;
		}
	}

	static class Board extends JPanel	{
		static public int  _board_x      = 15;
		static public int  _board_y      = _board_x;
		static public char _chess_cross  = '+';
		static public char _chess_black  = '●';
		// static public char _chess_white  = _chess_black;
		static public char _chess_white  = '○';
		static public int  _consecutive  = 5;

		public Gobang_Graphics _gobang       = null;
		public Board           _self         = this;
		public BufferedImage   _image_board  = ImageIO.read(new File("images/board.544x544.pdf.png"));
		public BufferedImage   _image_cursor = ImageIO.read(new File("images/cursor.34x34.pdf.png"));
		public BufferedImage   _image_black  = ImageIO.read(new File("images/black.34x34.pdf.png"));
		public BufferedImage   _image_white  = ImageIO.read(new File("images/white.34x34.pdf.png"));
		public int             _board_width  = _image_board.getWidth();
		public int             _board_height = _image_board.getHeight();
		public int             _cell_width   = _image_cursor.getWidth();
		public int             _cell_height  = _image_cursor.getHeight();
		public int             _offset_x     = (_board_width  - _cell_width  * _board_x) / 2;
		public int             _offset_y     = (_board_height - _cell_height * _board_y) / 2;
		public char[][]        _board        = new char[_board_x][_board_y];
		public int             _index_x      = -1;
		public int             _index_y      = -1;
		public int             _chess_count  = 0;
		public Board(Gobang_Graphics gobang) throws Exception {
			_gobang = gobang;

			for (int x = 0; x < _board_x; x += 1) {
				for (int y = 0; y < _board_y; y += 1) {
					_board[x][y] = _chess_cross;
				}
			}

			Dimension dimension = new Dimension(_board_width, _board_height);
			_self.setPreferredSize(dimension);

			////////////////////////////////////////////////////////////////////

			_self.addMouseMotionListener(new MouseMotionAdapter() {
				public void mouseMoved(MouseEvent event) {
					System.out.println("mouseMoved");
					int x = event.getX() - _offset_x;
					int y = (_board_height - event.getY()) - _offset_y;
					if(0 <= x && 0 <= y) {
						_index_x = x / _cell_width;
						_index_y = y / _cell_height;
						System.out.printf("[%s, %s, %s, %s]%n", x, y, _index_x, _index_y);
						if(0 <= _index_x && _index_x < _board_x && 0 <= _index_y && _index_y < _board_y) {
							_self.repaint();
						} else {
							_index_x = -1;
							_index_y = -1;
						}
					}
				}
			});
			_self.addMouseListener(new MouseAdapter() {
				public void mouseClicked(MouseEvent event) {
					System.out.println("mouseClicked");
					if(0 <= _index_x && _index_x < _board_x && 0 <= _index_y && _index_y < _board_y) {
						if(_board[_index_x][_index_y] == _chess_cross) {
							_board[_index_x][_index_y] = (_chess_count % 2 == 0) ? _chess_black : _chess_white;
							_chess_count += 1;
							_self.repaint();

							if(true == _Validate(_index_x, _index_y)) {
								String title = "有您的消息.";
								String message = (_board[_index_x][_index_y] == _chess_black) ? "黑棋赢，白棋输！" : "白棋赢，黑棋输！";
								message += "\n再玩一次？";
								String result = Popup._Popup(null, title, message);
								_gobang._Replay(result == Popup._stamp_posi ? true : false);
							}
						}
					}
				}
			});
		}

		@Override
		public void paint(Graphics graphics) {
			graphics.drawImage(_image_board, 0, 0, null);

			if (0 <= _index_x && _index_x < _board_x && 0 <= _index_y && _index_y < _board_y) {
				int x = _offset_x + _cell_width  * _index_x;
				int y = _offset_y + _cell_height * _index_y;
				graphics.drawImage(_image_cursor, x, _board_height - y - _cell_height, null);
			}

			for(int index_x = 0; index_x < _board_x; index_x += 1) {
				for(int index_y = 0; index_y < _board_y; index_y += 1) {
					if(_board[index_x][index_y] != _chess_cross) {
						int x = _offset_x + _cell_width  * index_x;
						int y = _offset_y + _cell_height * index_y;
						if(_board[index_x][index_y] == _chess_black) {
							graphics.drawImage(_image_black, x, _board_height - y - _cell_height, null);
						} else if(_board[index_x][index_y] == _chess_white) {
							graphics.drawImage(_image_white, x, _board_height - y - _cell_height, null);
						}
					}
				}
			}
		}

		public boolean _Validate(int index_x, int index_y) {
			char chess  = _board[index_x][index_y];
			int  head_x = 0;
			int  tail_x = 0;
			int  head_y = 0;
			int  tail_y = 0;

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
	}

	public Gobang_Graphics() {
		try {
			this.setTitle("五子棋游戏");
			this.add(new Board(this));
			this.pack();
			this.setResizable(false);
			this.setLocationRelativeTo(null);
			this.setVisible(true);

			this.addWindowListener(new WindowAdapter() {
				@Override
				public void windowClosing(WindowEvent event) {
					System.exit(0);
				}
			});
		} catch (Exception exception) {
			exception.printStackTrace();
		}
	}
	public void _Replay(boolean result) {
		if(result == true) {
			this.dispose();
			new Gobang_Graphics();
		} else {
			System.exit(0);
		}
	}

	public static void main(String[] args) 	{
		new Gobang_Graphics();
	}
}
