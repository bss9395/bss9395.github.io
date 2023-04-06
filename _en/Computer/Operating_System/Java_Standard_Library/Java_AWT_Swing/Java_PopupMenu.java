/* Java_PopupMenu.java
Author: BSS9395
Update: 2023-03-28T18:57:00+08@China-Shanghai+08
Design: Java Standard Library: PopupMenu
*/

import java.awt.*;
import java.awt.event.*;

public class Java_PopupMenu {
    public Frame            _f_frame      = new Frame("Java PopupMenu");
    public TextArea         _ta_area      = new TextArea(5, 40);
    public Panel            _p_panel      = new Panel();
    public PopupMenu        _pm_menu      = new PopupMenu();
    public Menu             _m_format     = new Menu("Format");
    public CheckboxMenuItem _cbmi_wrap    = new CheckboxMenuItem("wrapped");
    public MenuItem         _mi_copy      = new MenuItem("Copy");
    public MenuItem         _mi_paste     = new MenuItem("Paste");
    public MenuItem         _mi_comment   = new MenuItem("Comment");
    public MenuItem         _mi_uncomment = new MenuItem("Uncomment");
    public Java_PopupMenu() {
        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                _f_frame.dispose();
            }
        });
        ActionListener listener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                String command = event.getActionCommand();
                _ta_area.append(String.format("Click %s%n", command));
                if(command.equals("Exit")) {
                    _f_frame.dispose();
                }
            }
        };
        _mi_comment.addActionListener(listener);

        _pm_menu.add(_cbmi_wrap);
        _pm_menu.addSeparator();
        _pm_menu.add(_mi_copy);
        _pm_menu.add(_mi_paste);
        _pm_menu.add(new MenuItem("-"));
        _m_format.add(_mi_comment);
        _m_format.add(_mi_uncomment);
        _pm_menu.add(_m_format);

        _f_frame.add(_ta_area, BorderLayout.NORTH);
        _p_panel.setPreferredSize(new Dimension(300, 200));
        _p_panel.setBackground(Color.red);
        _p_panel.add(_pm_menu);
        _p_panel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseReleased(MouseEvent event) {
                if(event.isPopupTrigger() == true) {
                    _pm_menu.show(_p_panel, event.getX(), event.getY());
                }
            }
        });
        _f_frame.add(_p_panel);
        _f_frame.pack();
        _f_frame.setVisible(true);
    }

    static public void main(String[] args) {
        new Java_PopupMenu();
    }
}
