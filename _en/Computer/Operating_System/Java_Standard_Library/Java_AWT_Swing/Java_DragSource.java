/* Java_DragSource.java
Author: BSS9395
Update: 2023-05-11T22:39:00+08@China-Guangdong-Zhanjiang+08
Design: Java Standard Library: DragSource
*/

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.List;
import java.io.*;
import java.awt.dnd.*;
import javax.imageio.*;
import java.awt.datatransfer.*;
import java.util.ListIterator;
import javax.swing.*;

public class Java_DragSource {
	public JFrame    _f_frame = new JFrame("Swing的拖放支持");
	public JTextArea _ta_text = new JTextArea("From: Java DragSource.\nTo: Java DropTarget.\n");
	public Java_DragSource() {
		_f_frame.add(new JScrollPane(_ta_text));
		_f_frame.pack();
		_f_frame.setVisible(true);

		////////////////////////////////////////////////////////////////////////

		_f_frame.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent event) {
				_f_frame.dispose();
			}
		});

		DragSource source = DragSource.getDefaultDragSource();
		source.createDefaultDragGestureRecognizer(_ta_text, DnDConstants.ACTION_COPY_OR_MOVE, new DragGestureListener() {
			@Override
			public void dragGestureRecognized(DragGestureEvent event) {
				System.out.println("dragGestureRecognized");
				String          content      = _ta_text.getText();
				StringSelection transferable = new StringSelection(content);
				event.startDrag(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR), transferable);
			}
		});
	}

	public static void main(String[] args) {
		new Java_DropTarget();
		new Java_DragSource();
		System.out.println("at the end.");
	}
}

class Java_DropTarget {
	static class Drop_Image extends DropTargetAdapter	{
		public Java_DropTarget _drop_target = null;
		public Drop_Image(Java_DropTarget drop_target) {
			_drop_target = drop_target;
		}
		@Override
		public void drop(DropTargetDropEvent event)	{
			System.out.println("drop");
			event.acceptDrop(DnDConstants.ACTION_COPY);

			Transferable transferable = event.getTransferable();
			DataFlavor[] flavors      = transferable.getTransferDataFlavors();
			for (int i = 0; i < flavors.length; i += 1) {
				System.out.printf("flavors[%s]=%s%n", i, flavors[i]);
				try	{
					if (flavors[i].equals(DataFlavor.javaFileListFlavor)) {
						List files = (List) transferable.getTransferData(flavors[i]);
						ListIterator<File> iter = files.listIterator();
						while(iter.hasNext()) {
							_drop_target._Show_Image(iter.next());
						}
						break;
					} else if ((flavors[i].isMimeTypeEqual("text/html") || flavors[i].isMimeTypeEqual("text/plain")) && flavors[i].getRepresentationClass() == InputStream.class) {
						String charset = flavors[i].getParameter("charset");
						if(charset.toLowerCase().equals("utf-8")) {
							InputStream stream = (InputStream) transferable.getTransferData(flavors[i]);
							String content = new String(stream.readAllBytes(), charset);
							_drop_target._Show_String(content);
							break;
						} else if(charset.toLowerCase().equals("unicode")) {
							BufferedReader reader = new BufferedReader((StringReader) transferable.getTransferData(flavors[i]));
							StringBuilder builder = new StringBuilder();
							for(String line = null; (line = reader.readLine()) != null; ) {
								builder.append(line);
								builder.append("\n");
							}
							_drop_target._Show_String(builder.toString());
							break;
						}
					}
				} catch (Exception exception)	{
					exception.printStackTrace(System.out);
					JOptionPane.showInternalMessageDialog(_drop_target._dp_desktop,"系统不支持这种类型的文件！");
				}
			}
			event.dropComplete(true);
		}
	}

	static public int _width  = 700;
	static public int _height = 500;
	static public int _offset = 40;

	public JFrame       _f_frame    = new JFrame("测试拖放目标——把图片文件拖入该窗口");
	public JDesktopPane _dp_desktop = new JDesktopPane();
	public int          _curr_x     = 0;
	public int          _curr_y     = 0;
	public Java_DropTarget() {
		_f_frame.add(_dp_desktop);
		_dp_desktop.setPreferredSize(new Dimension(_width, _height));
		_f_frame.pack();
		_f_frame.setVisible(true);

		////////////////////////////////////////////////////////////////////////

		_f_frame.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent event) {
				_f_frame.dispose();
			}
		});
		new DropTarget(_f_frame, DnDConstants.ACTION_COPY, new Drop_Image(this));
	}
	public void _Show_Image(File file) throws IOException {
		Image image = ImageIO.read(file);
		if (image == null) {
			return;
		}

		JInternalFrame if_frame = new JInternalFrame(file.getName(), true, true, true, true);
		if_frame.add(new JScrollPane(new JLabel(new ImageIcon(image))));
		_dp_desktop.add(if_frame);

		if (false == (_curr_x + _dp_desktop.getWidth() / 2 < _dp_desktop.getWidth())) {
			_curr_x = 0;
		}
		if (false == (_curr_y + _dp_desktop.getHeight() / 2 < _dp_desktop.getHeight())) {
			_curr_y = 0;
		}
		if_frame.reshape(_curr_x, _curr_y, _dp_desktop.getWidth() / 2, _dp_desktop.getHeight() / 2);
		if_frame.show();
		_curr_x += _offset;
		_curr_y += _offset;
	}
	public void _Show_String(String content) throws IOException {
		JInternalFrame if_frame = new JInternalFrame("文本字符串", true, true, true, true);
		JTextArea ta_area = new JTextArea(content);
		if_frame.add(ta_area);
		_dp_desktop.add(if_frame);
		ta_area.setLineWrap(true);

		if (false == (_curr_x + _dp_desktop.getWidth() / 2 < _dp_desktop.getWidth())) {
			_curr_x = 0;
		}
		if (false == (_curr_y + _dp_desktop.getHeight() / 2 < _dp_desktop.getHeight())) {
			_curr_y = 0;
		}
		if_frame.reshape(_curr_x, _curr_y, _dp_desktop.getWidth() / 2, _dp_desktop.getHeight() / 2);
		if_frame.show();
		_curr_x += _offset;
		_curr_y += _offset;
	}
}
