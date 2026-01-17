/* Java_ScrollPane.java
Author: BSS9395
Update: 2023-03-27T15:52:00+08@China-Shanghai+08
Design: Java Standard Library: ScrollPane
*/

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Java_ScrollPane {
    Frame _f_frame = new Frame("Java AWT Scroll");
    public Java_ScrollPane() {
        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        ScrollPane sp_scroll = new ScrollPane(ScrollPane.SCROLLBARS_AS_NEEDED);
        TextArea ta_area = new TextArea(8, 40);
        Panel p_panel = new Panel();
        p_panel.add(ta_area);
        sp_scroll.add(p_panel);
        _f_frame.add(sp_scroll);
        _f_frame.setBounds(0, 0, 250, 120);
        _f_frame.pack();
        _f_frame.setVisible(true);
    }

    static public void main(String[] args) {
        new Java_ScrollPane();
    }
}
