/* Java_Clipboard.java
Author: BSS9395
Update: 2023-05-10T21:45:00+08@China-Guangdong-Zhanjiang+08
Design: Java Standard Library: Clipboard
*/

import javax.swing.*;
import java.awt.*;
import java.awt.datatransfer.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.io.Serializable;

class Datum {
    public int    _id   = 0;
    public String _name = "";
    public Datum(int id, String name) {
        _id = id;
        _name = name;
    }
    @Override
    public String toString() {
        return String.format("%s[%s, %s]", Datum.class.getName(), _id, _name);
    }
};

class Sequencial implements Serializable {
    public int    _id   = 0;
    public String _name = "";
    public Sequencial(int id, String name) {
        _id = id;
        _name = name;
    }
    @Override
    public String toString() {
        return String.format("%s[%s, %s]", Sequencial.class.getName(), _id, _name);
    }
}

public class Java_Clipboard {
    static class Clipboard_Object implements Transferable {
        public Object _object = null;
        public Clipboard_Object(Object object) {
            _object = object;
        }
        @Override
        public DataFlavor[] getTransferDataFlavors() {
            try {
                DataFlavor[] flavors = new DataFlavor[3];
                flavors[0] = new DataFlavor(String.format("%s;class=%s", DataFlavor.javaJVMLocalObjectMimeType, _object.getClass().getName()));
                flavors[1] = new DataFlavor(String.format("%s;class=%s", DataFlavor.javaSerializedObjectMimeType, Sequencial.class.getName()));
                flavors[2] = DataFlavor.stringFlavor;
                System.out.printf("flavors[0]=%s, flavors[1]=%s%n", flavors[0], flavors[1]);
                return flavors;
            } catch (Exception exception) {
                exception.printStackTrace();
            }
            return null;
        }
        @Override
        public boolean isDataFlavorSupported(DataFlavor flavor) {
            DataFlavor[] flavors = getTransferDataFlavors();
            for(int i = 0; i < flavors.length; i += 1) {
                if(flavor.equals(flavors[i])) {
                    return true;
                }
            }
            return false;
        }
        @Override
        public Object getTransferData(DataFlavor flavor) throws UnsupportedFlavorException, IOException {
            if(false == isDataFlavorSupported(flavor)) {
                throw new UnsupportedFlavorException(flavor);
            }
            if(true == flavor.equals(DataFlavor.stringFlavor)) {
                return _object.toString();
            }
            return _object;
        }
    }

    public Clipboard _clipboard_system = Toolkit.getDefaultToolkit().getSystemClipboard();
    public Clipboard _clipboard_jvm    = new Clipboard("clipboard");
    public Frame     _f_frame          = new Frame("剪贴板");
    public Label     _l_id             = new Label("身份号: ");
    public TextField _tf_id            = new TextField();
    public Label     _l_name           = new Label("姓名: ");
    public TextField _tf_name          = new TextField();
    public TextArea  _ta_clip          = new TextArea(1, 1);
    public TextArea  _ta_paste         = new TextArea(1, 1);
    public Button    _b_copy_system    = new Button("复制系统对象");
    public Button    _b_paste_system   = new Button("粘贴系统对象");
    public Button    _b_copy_jvm       = new Button("复制JVM对象");
    public Button    _b_paste_jvm      = new Button("粘贴JVM对象");
    public Button    _b_copy_text      = new Button("复制文本");
    public Button    _b_paste_text     = new Button("粘贴文本");
    public Java_Clipboard() {
        Panel p_north = new Panel();
        p_north.add(_l_id);
        Box b_id = Box.createHorizontalBox();
        b_id.add(_tf_id);
        p_north.add(b_id);
        p_north.add(_l_name);
        Box b_name = Box.createHorizontalBox();
        b_name.add(_tf_name);
        p_north.add(b_name);
        _f_frame.add(p_north, BorderLayout.NORTH);

        Box b_center = Box.createHorizontalBox();
        b_center.add(_ta_clip);
        b_center.add(_ta_paste);
        _f_frame.add(b_center, BorderLayout.CENTER);
        Panel p_south = new Panel();
        p_south.add(_b_copy_system);
        p_south.add(_b_paste_system);
        p_south.add(_b_copy_jvm);
        p_south.add(_b_paste_jvm);
        p_south.add(_b_copy_text);
        p_south.add(_b_paste_text);
        _f_frame.add(p_south, BorderLayout.SOUTH);

        _tf_id.setText("9395");
        _tf_name.setText("bss9395");
        _ta_clip.setText("纯文本，无修饰。");
        b_id.setPreferredSize(new Dimension(280, 24));
        b_name.setPreferredSize(new Dimension(280, 24));
        _f_frame.setPreferredSize(new Dimension(700, 500));
        _f_frame.pack();
        _f_frame.setVisible(true);

        ////////////////////////////////////////////////////////////////////////

        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                System.exit(0);
            }
        });
        _b_copy_system.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                try {
                    Sequencial sequencial = new Sequencial(Integer.parseInt(_tf_id.getText()), _tf_name.getText());
                    Clipboard_Object content = new Clipboard_Object(sequencial);
                    _clipboard_system.setContents(content, null);
                } catch (Exception exception) {
                    _tf_id.setText("解析整数异常！请重新输入一个整数。");
                }
            }
        });
        _b_paste_system.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                try {
                    DataFlavor flavor = new DataFlavor(String.format("%s;class=%s", DataFlavor.javaSerializedObjectMimeType, Sequencial.class.getName()));
                    System.out.printf("flavor = %s%n", flavor);
                    if(_clipboard_system.isDataFlavorAvailable(flavor)) {
                        Sequencial sequencial = (Sequencial) _clipboard_system.getData(flavor);
                        System.out.printf("sequential=%s%n", sequencial);
                        _ta_paste.append(sequencial.toString());
                        _ta_paste.append("\n");
                    } else {
                        System.out.println("if(_clipboard_system.isDataFlavorAvailable(flavor)) {");
                    }
                } catch (Exception exception) {
                    exception.printStackTrace();
                }
            }
        });
        _b_copy_jvm.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                Datum datum = new Datum(Integer.parseInt(_tf_id.getText()), _tf_name.getText());
                Clipboard_Object content = new Clipboard_Object(datum);
                _clipboard_jvm.setContents(content, null);
            }
        });
        _b_paste_jvm.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                try {
                    DataFlavor flavor = new DataFlavor(String.format("%s;class=%s", DataFlavor.javaJVMLocalObjectMimeType, Datum.class.getName()));
                    System.out.printf("flavor = %s%n", flavor);
                    if(_clipboard_jvm.isDataFlavorAvailable(flavor)) {
                        Datum datum = (Datum) _clipboard_jvm.getData(flavor);
                        System.out.printf("datum = %s%n", datum);
                        _ta_paste.append(datum.toString());
                        _ta_paste.append("\n");
                    } else {
                        System.out.println("if(_clipboard_jvm.isDataFlavorAvailable(flavor)) {");
                    }
                } catch (Exception exception) {
                    exception.printStackTrace();
                }
            }
        });
        _b_copy_text.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                StringSelection content = new StringSelection(_ta_clip.getText());
                _clipboard_system.setContents(content, null);
            }
        });
        _b_paste_text.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                try {
                    if(_clipboard_system.isDataFlavorAvailable(DataFlavor.stringFlavor)) {
                        String content = (String) _clipboard_system.getData(DataFlavor.stringFlavor);
                        _ta_paste.append(content);
                        _ta_paste.append("\n");
                    }
                } catch (Exception exception) {
                    exception.printStackTrace();
                }
            }
        });
    }
    static public void main(String[] args) {
        new Java_Clipboard();
    }
}
