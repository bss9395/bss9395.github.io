/* Java_Panel.java
Author: BSS9395
Update: 2023-03-27T15:38:00+08@China-Shanghai+08
Design: Java Standard Library: Panel
*/

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Java_Panel {
    Frame _f_frame = new Frame("Java AWT Panel");
    public Java_Panel() {
        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        Panel panel = new Panel();
        panel.add(new TextField(20));
        panel.add(new Button("Click"));
        _f_frame.add(panel);
        _f_frame.setBounds(30, 30, 250, 120);
        _f_frame.setVisible(true);
    }

    static public void main(String[] args) {
        new Java_Panel();
    }
}
