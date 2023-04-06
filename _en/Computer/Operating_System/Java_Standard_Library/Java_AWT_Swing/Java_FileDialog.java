/* Java_FileDialog.java
Author: BSS9395
Update: 2023-03-28T14:54:00+08@China-Shanghai+08
Design: Java Standard Library: FileDialog
*/

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Java_FileDialog {
    Frame _f_frame = new Frame("");
    Button _b_load = new Button("Load files");
    Button _b_save = new Button("save files");
    public Java_FileDialog() {
        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                _f_frame.dispose();
            }
        });
        _b_load.addActionListener((event) -> {
            FileDialog fd_load = new FileDialog(_f_frame, "Load Files", FileDialog.LOAD);
            fd_load.addWindowListener(new WindowAdapter() {
                @Override
                public void windowClosing(WindowEvent e) {
                    fd_load.dispose();
                }
            });
            fd_load.setVisible(true);
        });
        _b_save.addActionListener((event) -> {
            FileDialog fd_save = new FileDialog(_f_frame, "Save Files", FileDialog.SAVE);
            fd_save.addWindowListener(new WindowAdapter() {
                @Override
                public void windowClosing(WindowEvent e) {
                    fd_save.dispose();
                }
            });
            fd_save.setVisible(true);
        });
        _f_frame.add(_b_load);
        _f_frame.add(_b_save, BorderLayout.SOUTH);
        _f_frame.pack();
        _f_frame.setVisible(true);
    }

    static public void main(String[] args) {
        new Java_FileDialog();
    }
}
