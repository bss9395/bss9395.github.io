/* Java_WindowAdapter.java
Author: BSS9395
Update: 2023-03-28T16:31:00+08@China-Shanghai+08
Design: Java Standard Library: WindowAdapter
*/

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Java_WindowAdapter {
    public Frame    _f_frame = new Frame("Java WindowAdapter");
    public TextArea _ta_area = new TextArea(6, 40);
    public Java_WindowAdapter() {
        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                _f_frame.dispose();
            }
        });
        _f_frame.add(_ta_area);
        _f_frame.pack();
        _f_frame.setVisible(true);
    }

    static public void main(String[] args) {
        new Java_WindowAdapter();
    }
}
