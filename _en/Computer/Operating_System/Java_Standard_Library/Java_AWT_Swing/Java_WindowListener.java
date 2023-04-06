/* Java_WindowListener.java
Author: BSS9395
Update: 2023-03-29T16:21:00+08@China-Shanghai+08
Design: Java Standard Library: WindowListener
*/

import java.awt.*;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

public class Java_WindowListener {
    public Frame _f_frame = new Frame("Java WindowListener");
    public TextArea _ta_area = new TextArea(6, 40);
    public Java_WindowListener() {
        _f_frame.addWindowListener(new WindowListener() {
            @Override
            public void windowOpened(WindowEvent e) {
                _ta_area.append("windowOpened\n");
            }
            @Override
            public void windowClosing(WindowEvent e) {
                _ta_area.append("windowClosing\n");
                _f_frame.dispose();
            }
            @Override
            public void windowClosed(WindowEvent e) {
                _ta_area.append("windowClosed\n");
            }
            @Override
            public void windowIconified(WindowEvent e) {
                _ta_area.append("windowIconified\n");
            }
            @Override
            public void windowDeiconified(WindowEvent e) {
                _ta_area.append("windowDeiconified\n");
            }
            @Override
            public void windowActivated(WindowEvent e) {
                _ta_area.append("windowActivated\n");
            }
            @Override
            public void windowDeactivated(WindowEvent e) {
                _ta_area.append("windowDeactivated\n");
            }
        });
        _f_frame.add(_ta_area);
        _f_frame.pack();
        _f_frame.setVisible(true);
    }

    static public void main(String[] args) {
        new Java_WindowListener();
    }
}
