/* Image_Viewer.java
Author: BSS9395
Update: 2023-04-25T15:34:00+08@China-Guangdong-Zhanjiang+08
Design: Image Viewer.java
*/

import javax.swing.*;
import javax.swing.filechooser.FileFilter;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.FileInputStream;
import java.sql.*;
import java.util.ArrayList;
import java.util.ListIterator;
import java.util.Vector;

public class Image_Viewer extends JDialog {
    static class Datum {
        public int    _id   = 0;
        public String _name = "";
        public Datum(int id, String name) {
            System.err.println("Datum");
            _id = id;
            _name = name;
        }
        @Override
        public String toString() {
            // System.err.println("toString");
            return String.format("%s.%s", _id, _name);
        }
    }
    static class ImageFilter extends FileFilter {
        public ArrayList<String> _extensions = new ArrayList<String>();
        public ImageFilter(String[] extensions) {
            for(int i = 0; i < extensions.length; i += 1) {
                _extensions.add(extensions[i].startsWith(".") == true ? extensions[i] : "." + extensions[i]);
            }
        }
        @Override
        public String getDescription() {
            StringBuilder description = new StringBuilder();
            description.append("图片文件(");
            ListIterator<String> iter = _extensions.listIterator();
            while(iter.hasNext() == true) {
                description.append("*" + iter.next());
            }
            description.append(")");
            return description.toString();
        }
        @Override
        public boolean accept(File file) {
            if(file.isDirectory() == true) {
                return true;
            }
            String filename = file.getName().toLowerCase();
            ListIterator<String> iter = _extensions.listIterator();
            while(iter.hasNext() == true) {
                if(filename.endsWith(iter.next()) == true) {
                    return true;
                }
            }
            return false;
        }
    }
    static class Popup extends JDialog {
        public Popup        _self        = this;
        public Image_Viewer _viewer      = null;
        public JTextField   _tf_filepath = new JTextField();
        public JButton      _b_browse    = new JButton("浏览");
        public JButton      _b_upload    = new JButton("上传");
        public JFileChooser _fc_chooser  = new JFileChooser(".");
        public Popup(Image_Viewer viewer) {
            super((JDialog) null, "上传图片", true);
            _viewer = viewer;

            Box b_center = new Box(BoxLayout.X_AXIS);
            _tf_filepath.setPreferredSize(new Dimension(300, 24));
            b_center.add(_tf_filepath);
            b_center.add(_b_browse);
            b_center.add(_b_upload);
            this.add(b_center);
            this.pack();

            this.addWindowListener(new WindowAdapter() {
                @Override
                public void windowClosing(WindowEvent event) {
                    setVisible(false);
                }
            });

            _tf_filepath.setEditable(false);
            _fc_chooser.addChoosableFileFilter(new ImageFilter(_image_extensions));
            _fc_chooser.setAcceptAllFileFilterUsed(false);
            _b_browse.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    int result = _fc_chooser.showDialog(_self, "浏览图片");
                    if(result == JFileChooser.APPROVE_OPTION) {
                        _tf_filepath.setText(_fc_chooser.getSelectedFile().getPath());
                    }
                }
            });

            _b_upload.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent event) {
                    String filepath = _tf_filepath.getText().trim();
                    if(0 < filepath.length()) {
                        _viewer._Insert_Datum(filepath);
                        _tf_filepath.setText("");
                        _self.setVisible(false);
                    }
                }
            });
        }
    }

    static public String _driver   = "com.mysql.cj.jdbc.Driver";
    static public String _schema   = "jdbc:mysql://";
    static public String _address  = "192.168.190.137:3306/";
    static public String _username = "bss9395";
    static public String _password = "Password";
    static public String[] _image_extensions = new String[] {
        ".png", ".jpg", ".jpeg", ".gif"
    };
    public Connection _connection = DriverManager.getConnection(_schema + _address, _username, _password);

    public Vector<Datum> _v_images  = new Vector<Datum>();
    public JList<Datum>  _l_images  = new JList<Datum>();
    public PopupMenu     _pm_menu   = new PopupMenu();
    public MenuItem      _mi_insert = new MenuItem("Add");
    public MenuItem      _mi_delete = new MenuItem("Delete");
    public JLabel        _l_image   = new JLabel();
    public Popup         _d_popup   = new Popup(this);
    public Image_Viewer() throws Exception {
        super((JDialog) null, "图片查看器", false);
        System.err.println("Image_Viewer");
        Class.forName(_driver);

        Box b_center = new Box(BoxLayout.X_AXIS);
        _l_images.setFixedCellWidth(200);
        _l_images.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        b_center.add(new JScrollPane(_l_images));

        _l_image.setPreferredSize(new Dimension(500, 500));
        b_center.add(new JScrollPane(_l_image));
        this.add(b_center);
        this.pack();
        _Select_Indexes();
        this.setVisible(true);
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                System.exit(0);
            }
        });

        _mi_delete.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                Datum datum = _l_images.getSelectedValue();
                if(datum != null) {
                    _Delete_Datum(datum._id);
                    _Select_Indexes();
                }
            }
        });
        _pm_menu.add(_mi_delete);
        _mi_insert.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                _d_popup.setVisible(true);
                _Select_Indexes();
            }
        });
        _pm_menu.add(_mi_insert);
        _l_images.add(_pm_menu);
        _l_images.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseReleased(MouseEvent event) {
                if(event.isPopupTrigger() == true) {
                    _pm_menu.show(_l_images, event.getX(), event.getY());
                }
            }
            @Override
            public void mouseClicked(MouseEvent event) {
                if(2 <= event.getClickCount()) {
                    Datum datum = _l_images.getSelectedValue();
                    _Select_Data(datum._id);
                }
            }
        });

    }
    public void _Select_Indexes() {
        System.err.println("_Fetch_Indexes");
        try {
            PreparedStatement select_indexes = _connection.prepareStatement(
                "select _id, _name from Management.Images;"
            );

            _v_images.clear();
            ResultSet result = select_indexes.executeQuery();
            while(result.next() == true) {
                _v_images.add(new Datum(result.getInt(1), result.getString(2)));
            }
            _l_images.setListData(_v_images);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
    public void _Select_Data(int id) {
        System.err.println("_Fetch_Data");
        try {
            PreparedStatement select_image = _connection.prepareStatement(
                "select _data from Management.Images where _id = ?;"
            );
            select_image.setInt(1, id);
            ResultSet result = select_image.executeQuery();
            if(result.next() == true) {
                Blob blob = result.getBlob(1);
                ImageIcon icon = new ImageIcon(blob.getBytes(1, (int) blob.length()));
                double ratio = 1.0 * icon.getIconHeight() / icon.getIconWidth();
                if(ratio < 1 && _l_image.getWidth() < icon.getIconWidth()) {
                    icon.setImage(icon.getImage().getScaledInstance(_l_image.getWidth(), (int)(_l_image.getWidth() * ratio), Image.SCALE_SMOOTH));
                } else if(1 <= ratio && _l_image.getHeight() < icon.getIconHeight()) {
                    icon.setImage(icon.getImage().getScaledInstance((int)(_l_image.getHeight() / ratio), _l_image.getHeight(), Image.SCALE_SMOOTH));
                }
                _l_image.setIcon(icon);
            }
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
    public int  _Insert_Datum(String filepath) {
        System.err.println("_Push_Datum");
        int result = 0;
        try {
            PreparedStatement insert_datum = _connection.prepareStatement(
                "insert into Management.Images values (null, ?, ?);"
            );

            String filename = filepath.substring(filepath.lastIndexOf('\\') + 1);
            File file = new File(filepath);
            FileInputStream stream = new FileInputStream(file);
            insert_datum.setString(1, filename);
            insert_datum.setBlob(2, stream, (int) file.length());
            result = insert_datum.executeUpdate();
        } catch (Exception exception) {
            exception.printStackTrace();
        }
        return result;
    }
    public int  _Delete_Datum(int id) {
        int result = 0;
        try {
            PreparedStatement _remove_datum  = _connection.prepareStatement(
                "delete from Management.Images where _id = ?;"
            );

            _remove_datum.setInt(1, id);
            result = _remove_datum.executeUpdate();
        } catch (Exception exception) {
            exception.printStackTrace();
        }
        return result;
    }

    static public void main(String[] args) throws Exception {
        System.err.println("main");
        new Image_Viewer();
    }
}
