

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

public class Java_Frame {
    Frame _f_frame = new Frame("Java AWT Frame");
    public Java_Frame() {
        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        _f_frame.setBounds(30, 30, 250, 200);
        _f_frame.setVisible(true);
    }

    static public void main(String[] args) {
        new Java_Frame();
    }
}
