/* Java_Menu.java
Author: BSS9395
Update: 2023-03-29T18:34:00+08@China-Shanghai+08
Design: Java Standard Library: Menu
*/

import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Java_Menu {
    public Frame            _f_frame    = new Frame("Java Menu");
    public MenuBar          _mb_menu    = new MenuBar();
    public Menu             _m_file     = new Menu("Files");
    public Menu             _m_edit     = new Menu("Edit");
    public Menu             _m_format   = new Menu("Format");
    public MenuItem         _mi_new     = new MenuItem("New");
    public MenuItem         _mi_save    = new MenuItem("Save");
    public MenuItem         _mi_exit    = new MenuItem("Exit", new MenuShortcut(KeyEvent.VK_X));  // Ctrl+X
    public CheckboxMenuItem _cbmi_wrap  = new CheckboxMenuItem("wrapped");
    public MenuItem         _mi_copy    = new MenuItem("Copy");
    public MenuItem         _mi_paste   = new MenuItem("Paste");
    public MenuItem         _mi_comment = new MenuItem("Comment", new MenuShortcut(KeyEvent.VK_SLASH, true));  // Ctrl+Shift+/
    public MenuItem         _mi_cancel  = new MenuItem("Cancel");
    public TextArea         _ta_area    = new TextArea(6, 40);
    public Java_Menu() {
        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                _f_frame.dispose();
            }
        });

        ActionListener listener = (event) -> {
            String command = event.getActionCommand();
            _ta_area.append(String.format("Clicked %s%n", command));
            if(command.equals("Exit")) {
                System.exit(0);
            }
        };
        _mi_exit.addActionListener(listener);
        _mi_comment.addActionListener(listener);

        _m_file.add(_mi_new);
        _m_file.add(_mi_save);
        _m_file.add(_mi_exit);
        _m_edit.add(_cbmi_wrap);
        _m_edit.addSeparator();
        _m_edit.add(_mi_copy);
        _m_edit.add(_mi_paste);
        _m_edit.add(_mi_comment);
        _m_edit.add(_mi_cancel);
        _m_edit.add(new MenuItem("-"));
        _m_edit.add(_m_format);
        _mb_menu.add(_m_file);
        _mb_menu.add(_m_edit);
        _f_frame.setMenuBar(_mb_menu);
        _f_frame.add(_ta_area);
        _f_frame.pack();
        _f_frame.setVisible(true);
    }

    static public void main(String[] args) {
        new Java_Menu();
    }
}
