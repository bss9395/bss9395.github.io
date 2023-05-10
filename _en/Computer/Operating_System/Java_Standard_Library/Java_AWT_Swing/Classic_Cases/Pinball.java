/* Pinball.java
Author: BSS9395
Update: 2023-05-04T16:41:00+08@China-Guangdong-Zhanjiang+08
Design: Pinball
*/

import java.awt.font.FontRenderContext;
import java.awt.geom.AffineTransform;
import java.awt.geom.Rectangle2D;
import java.util.Random;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Pinball {
	static class Board extends Canvas {
		final static public Font              _font          = new Font("Consola", Font.BOLD, 30);
		final static public FontRenderContext _context       = new FontRenderContext(new AffineTransform(), true, true);
		final static public int               _board_width   = 250;
		final static public int               _board_height  = 350;
		final static public int               _ball_width    = 16;
		final static public int               _ball_height   = _ball_width;
		final static public int               _racket_width  = _ball_width * 4;
		final static public int               _racket_height = _ball_height;

		public Board   _self          = this;
		public boolean _inited        = false;
		public Random  _random        = new Random();
		public Timer   _timer         = null;
		public boolean _lost          = false;
		public int     _racket_x      = 0;
		public int     _racket_y      = 0;
		public int     _racket_rate_x = 0;
		public int     _ball_x        = 0;
		public int     _ball_y        = 0;
		public double  _rate_ratio    = 0;
		public int     _ball_rate_x   = 0;
		public int     _ball_rate_y   = 0;
		public int     _ball_speed_x  = 0;
		public int     _ball_speed_y  = 0;
		public Board() {
			_self.addComponentListener(new ComponentAdapter() {
				@Override
				public void componentResized(ComponentEvent event) {
					_self.setMinimumSize(_self.getPreferredSize());
					_racket_y = _self.getHeight() - 10 - _racket_height;
					if(_self._inited == false) {
						_racket_x = _random.nextInt(_self.getWidth() - _racket_width);
						_racket_rate_x = 10;
						_ball_x = _random.nextInt(_self.getWidth() - _ball_width);
						_ball_y = _random.nextInt((_self.getHeight() - _racket_y) / 2 - _ball_height);
						_rate_ratio = _random.nextDouble() * 2.0 - 1.0;
						_ball_rate_x = (int) (_racket_rate_x * _rate_ratio);
						_ball_rate_y = 10;
						_ball_speed_x = _ball_rate_x;
						_ball_speed_y = _ball_rate_y;
						_self._inited = true;
					}
				}
			});
			_self.setPreferredSize(new Dimension(_board_width, _board_height));

			_self.addKeyListener(new KeyAdapter() {
				public void keyPressed(KeyEvent event)	{
					if (event.getKeyCode() == KeyEvent.VK_LEFT) {
						_racket_x = _racket_x - _racket_rate_x;
						if (false == (0 <= _racket_x)) {
							_racket_x = 0;
						}
					} else if (event.getKeyCode() == KeyEvent.VK_RIGHT) {
						_racket_x = _racket_x + _racket_rate_x;
						if (false == (_racket_x + _racket_width < _self.getWidth())) {
							_racket_x = _self.getWidth() - _racket_width;
						}
					}
				}
			});

			_timer = new Timer(100, new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent event) {
					_ball_x = _ball_x + _ball_speed_x;
					if(false == (0 <= _ball_x)) {
						_ball_x = 0;
						_ball_speed_x = +_ball_rate_x;
					} else if(false == (_ball_x + _ball_width < _self.getWidth())) {
						_ball_x = _self.getWidth() - _ball_width;
						_ball_speed_x = -_ball_rate_x;
					}

					_ball_y = _ball_y + _ball_speed_y;
					if(false == (0 <= _ball_y)) {
						_ball_y = 0;
						_ball_speed_y = +_ball_rate_y;
					} else if(false == (_ball_y + _ball_height < _racket_y)) {
						if((_racket_x <= _ball_x + _ball_width / 2) && (_ball_x + _ball_width / 2 <= _racket_x + _racket_width)) {
							_ball_y = _racket_y - _ball_height;
							_ball_speed_y = -_ball_rate_y;
						} else {
							_lost = true;
							_timer.stop();
						}
					}
					_self.repaint();
				}
			});
			_timer.start();
		}

		public void paint(Graphics graphics) {
			graphics.drawLine(0, 0, _self.getWidth(), 0);
			if (_lost)	{
				graphics.setColor(new Color(255, 0, 0));
				graphics.setFont(_font);
				String tips = "游戏已结束！";
				Rectangle2D bounds = _font.getStringBounds(tips, _context);
				graphics.drawString(tips, (int)((_self.getWidth() - bounds.getWidth()) / 2), (int)((_self.getHeight() - bounds.getHeight()) / 2));
			}
			else {
				graphics.setColor(new Color(240, 240, 80));
				graphics.fillOval(_ball_x, _ball_y, _ball_width, _ball_height);
				graphics.setColor(new Color(80, 80, 200));
				graphics.fillRect(_racket_x, _racket_y, _racket_width, _racket_height);
			}
		}
	}

	public Frame _f_frame = new Frame("弹球游戏");
	public Board _board   = new Board();
	public Pinball() {
		_f_frame.add(_board);
		_f_frame.pack();
		_f_frame.setVisible(true);

		_f_frame.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent event) {
				System.exit(0);
			}
		});
		_board.requestFocus();
	}

	static public void main(String[] args) {
		new Pinball();
	}
}