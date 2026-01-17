/* Sketch.java
Author: BSS9395
Update: 2023-05-04T20:59:00+08@China-Guangdong-Zhanjiang+08
Design: Sketch
*/

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.Transferable;
import java.awt.datatransfer.UnsupportedFlavorException;
import java.awt.event.*;
import java.awt.image.*;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class Sketch {
	static class Clipboard_Image implements Transferable {
		public Image        _image  = null;
		public DataFlavor[] _flavor = new DataFlavor[] {
				DataFlavor.imageFlavor
		};
		public Clipboard_Image(Image image) {
			_image = image;
		}

		@Override
		public DataFlavor[] getTransferDataFlavors() {
			return _flavor;
		}
		@Override
		public boolean isDataFlavorSupported(DataFlavor flavor)	{
			for(int i = 0; i < _flavor.length; i += 1) {
				if(flavor.equals(_flavor[i])) {
					return true;
				}
			}
			return false;
		}
		@Override
		public Object getTransferData(DataFlavor flavor) throws UnsupportedFlavorException {
			if(isDataFlavorSupported(flavor)) {
				return _image;
			} else {
				throw new UnsupportedFlavorException(flavor);
			}
		}
	}
	static class Board extends Canvas {
		static public int _width  = 700;
		static public int _height = 500;
		static public int _type   = BufferedImage.TYPE_INT_ARGB;

		public Board               _self        = this;
		public boolean             _inited      = false;
		public PopupMenu           _popup       = new PopupMenu();
		public MenuItem            _menu_make   = new MenuItem("ÐÂ½¨Í¼²ã");
		public MenuItem            _color_red   = new MenuItem("ºìÉ«");
		public MenuItem            _color_green = new MenuItem("ÂÌÉ«");
		public MenuItem            _color_blue  = new MenuItem("À¶É«");
		public MenuItem            _menu_save   = new MenuItem("±£´æÍ¼Ïñ");
		public MenuItem            _menu_copy   = new MenuItem("¸´ÖÆÍ¼Ïñ");
		public MenuItem            _menu_cut    = new MenuItem("¼ôÇÐÍ¼Ïñ");
		public MenuItem            _menu_paste  = new MenuItem("Õ³ÌùÍ¼Ïñ");
		public Color               _color       = new Color(255, 0, 0);
		public Clipboard           _clipboard   = Toolkit.getDefaultToolkit().getSystemClipboard();
		public ArrayList<Image>    _images      = new ArrayList<Image>();
		public ArrayList<Graphics> _graphicses  = new ArrayList<Graphics>();
		public Point               _prev        = new Point();
		public Point               _curr        = new Point();
		public Board() {
			_popup.add(_menu_make);
			_popup.add(_color_red);
			_popup.add(_color_green);
			_popup.add(_color_blue);
			_popup.add(_menu_save);
			_popup.add(_menu_copy);
			_popup.add(_menu_cut);
			_popup.add(_menu_paste);
			_self.add(_popup);

			////////////////////////////////////////////////////////////////////

			_self.addComponentListener(new ComponentAdapter() {
				@Override
				public void componentResized(ComponentEvent event) {
					if(_inited == false) {
						System.out.printf("[%s, %s]%n", _self.getWidth(), _self.getHeight());
						BufferedImage image = new BufferedImage(_self.getWidth(), _self.getHeight(), _type);
						_images.add(image);
						_graphicses.add(image.getGraphics());
						_inited = true;
						_self.repaint();
					}
				}
			});
			_self.setPreferredSize(new Dimension(_width, _height));

			_menu_make.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent event) {
					System.out.printf("[%s, %s]%n", _self.getWidth(), _self.getHeight());
					BufferedImage image = new BufferedImage(_self.getWidth(), _self.getHeight(), _type);
					_images.add(image);
					_graphicses.add(image.getGraphics());
				}
			});
			ActionListener listener_color = new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent event) {
					if (event.getActionCommand().equals("ºìÉ«"))	{
						_color = new Color(255, 0, 0);
					} else if (event.getActionCommand().equals("ÂÌÉ«")) {
						_color = new Color(0, 255, 0);
					} else if (event.getActionCommand().equals("À¶É«")) {
						_color = new Color(0, 0, 255);
					}
				}
			};
			_color_red.addActionListener(listener_color);
			_color_green.addActionListener(listener_color);
			_color_blue.addActionListener(listener_color);
			ActionListener listener_operate = new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent event) {
					if(event.getActionCommand().equals("±£´æÍ¼Ïñ")) {
						_self._Save();
					} else if(event.getActionCommand().equals("¸´ÖÆÍ¼Ïñ")) {
						_self._Clipboard_Copy();
					} else if(event.getActionCommand().equals("¼ôÇÐÍ¼Ïñ")) {
						_self._Clipboard_Cut();
					} else if(event.getActionCommand().equals("Õ³ÌùÍ¼Ïñ")) {
						_self._Clipboard_Paste();
					}
				}
			};
			_menu_save.addActionListener(listener_operate);
			_menu_copy.addActionListener(listener_operate);
			_menu_cut.addActionListener(listener_operate);
			_menu_paste.addActionListener(listener_operate);

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
					_graphicses.get(_graphicses.size() - 1).setColor(_color);
					_graphicses.get(_graphicses.size() - 1).drawLine(_prev.x, _prev.y, _curr.x, _curr.y);
					_prev = _curr;
					_self.repaint();
				}
			});
		}
		@Override
		public void paint(Graphics graphics) {
			for(int i = 0; i < _images.size(); i += 1) {
				graphics.drawImage(_images.get(i), 0, 0, null);
			}
		}
		public void _Save() {
			System.out.println("_Save");
			BufferedImage image    = new BufferedImage(_self.getWidth(), _self.getHeight(), _type);
			Graphics      graphics = image.getGraphics();
			for(int i = 0; i < _images.size(); i += 1) {
				graphics.drawImage(_images.get(i), 0, 0, null);
			}

			try {
				ImageIO.write(image, "png", new File("Sketch.java.png"));
			} catch (IOException exception) {
				exception.printStackTrace();
			}
		}
		public void _Clipboard_Copy() {
			System.out.println("_Clipboard_Copy");
			BufferedImage image    = new BufferedImage(_self.getWidth(), _self.getHeight(), BufferedImage.TYPE_INT_RGB);
			Graphics      graphics = image.getGraphics();
			graphics.fillRect(0, 0, image.getWidth(), image.getHeight());  // note: RGB from ARGB.
			for(int i = 0; i < _images.size(); i += 1) {
				graphics.drawImage(_images.get(i), 0, 0, null);
			}

			Clipboard_Image content = new Clipboard_Image(image);
			_clipboard.setContents(content, null);
		}
		public void _Clipboard_Cut() {
			System.out.println("_Clipboard_Cut");
			_Clipboard_Copy();
			_images.clear();
			_graphicses.clear();
			_self.repaint();
		}
		public void _Clipboard_Paste() {
			System.out.println("_Clipboard_Paste");
			try {
				if (_clipboard.isDataFlavorAvailable(DataFlavor.imageFlavor)) {
					Image image = (Image)_clipboard.getData(DataFlavor.imageFlavor);
					_images.add(image);
					_graphicses.add(image.getGraphics());
					_self.repaint();
				}
			} catch (Exception exception) {
				exception.printStackTrace();
			}
		}
	}

	public Frame _frame = new Frame("»æÍ¼³ÌÐò");
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
