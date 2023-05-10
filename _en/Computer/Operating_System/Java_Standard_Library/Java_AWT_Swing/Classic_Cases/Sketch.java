/* Sketch.java
Author: BSS9395
Update: 2023-05-04T20:59:00+08@China-Guangdong-Zhanjiang+08
Design: Sketch
*/

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class Sketch {
	static class Board extends Canvas {
		static public int _width  = 500;
		static public int _height = 400;

		public Board                    _self        = this;
		public boolean                  _inited      = false;
		public PopupMenu                _popup       = new PopupMenu();
		public MenuItem                 _make        = new MenuItem("新建图层");
		public MenuItem                 _color_red   = new MenuItem("红色");
		public MenuItem                 _color_green = new MenuItem("绿色");
		public MenuItem                 _color_blue  = new MenuItem("蓝色");
		public Color                    _color       = new Color(255, 0, 0);
		public ArrayList<BufferedImage> _images      = new ArrayList<BufferedImage>();
		public ArrayList<Graphics>      _graphicses  = new ArrayList<Graphics>();
		public Graphics                 _graphics    = null;
		public Point _prev = new Point();
		public Point _curr = new Point();
		public Board() {
			_self.addComponentListener(new ComponentAdapter() {
				@Override
				public void componentResized(ComponentEvent event) {
					if(_inited == false) {
						System.out.printf("[%s, %s]%n", _self.getWidth(), _self.getHeight());
						BufferedImage image = new BufferedImage(_self.getWidth(), _self.getHeight(), BufferedImage.TYPE_INT_ARGB);
						_images.add(image);
						_graphics = image.getGraphics();
						_graphicses.add(_graphics);
						_inited = true;
					}
				}
			});
			_self.setPreferredSize(new Dimension(_width, _height));

			_make.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent event) {
					System.out.printf("[%s, %s]%n", _self.getWidth(), _self.getHeight());
					BufferedImage image = new BufferedImage(_self.getWidth(), _self.getHeight(), BufferedImage.TYPE_INT_ARGB);
					_images.add(image);
					_graphics = image.getGraphics();
					_graphicses.add(_graphics);
				}
			});
			ActionListener listener = new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent event) {
					if (event.getActionCommand().equals("红色"))	{
						_color = new Color(255, 0, 0);
					} else if (event.getActionCommand().equals("绿色")) {
						_color = new Color(0, 255, 0);
					} else if (event.getActionCommand().equals("蓝色")) {
						_color = new Color(0, 0, 255);
					}
				}
			};
			_color_red.addActionListener(listener);
			_color_green.addActionListener(listener);
			_color_blue.addActionListener(listener);
			_popup.add(_make);
			_popup.add(_color_red);
			_popup.add(_color_green);
			_popup.add(_color_blue);
			_self.add(_popup);
			_self.addMouseListener(new MouseAdapter() {
				@Override
				public void mousePressed(MouseEvent event) {
					_prev = event.getPoint();
				}
				@Override
				public void mouseReleased(MouseEvent event)	{
					if (event.isPopupTrigger())	{
						_popup.show(_self, event.getX(), event.getY());
					}
				}
			});
			_self.addMouseMotionListener(new MouseMotionAdapter() {
				@Override
				public void mouseDragged(MouseEvent event) {
					_curr = event.getPoint();
					_graphics.setColor(_color);
					_graphics.drawLine(_prev.x, _prev.y, _curr.x, _curr.y);
					_self.repaint();
					_prev = _curr;
				}
			});
		}
		@Override
		public void paint(Graphics graphics) {
			BufferedImage image = new BufferedImage(_self.getWidth(), _self.getHeight(), BufferedImage.TYPE_INT_ARGB);
			Graphics      graph = image.getGraphics();
			for(int i = 0; i < _images.size(); i += 1) {
				graphics.drawImage(_images.get(i), 0, 0, null);
				graph.drawImage(_images.get(i), 0, 0, null);
			}

			try {
				ImageIO.write(image, "png", new File("Sketch.java.png"));
			} catch (IOException exception) {
				exception.printStackTrace();
			}
		}
	}

	public Frame _frame = new Frame("简单手绘程序");
	public Board _board = new Board();
	public Sketch()	{
		_frame.add(_board);
		_frame.pack();
		_frame.setVisible(true);

		_frame.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent event) {
				System.exit(0);
			}
		});
	}
	public static void main(String[] args) {
		new Sketch();
	}

}
