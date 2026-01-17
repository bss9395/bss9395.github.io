/* Java_FileDialog.java
Author: BSS9395
Update: 2023-03-28T14:54:00+08@China-Shanghai+08
Design: Java Standard Library: FileDialog
*/

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Java_FileDialog {
    public Frame  _f_frame = new Frame("");
    public Button _b_load  = new Button("Load files");
    public Button _b_save  = new Button("save files");
    public Java_FileDialog() {
        _f_frame.add(_b_load, BorderLayout.CENTER);
        _f_frame.add(_b_save, BorderLayout.SOUTH);
        _f_frame.pack();
        _f_frame.setVisible(true);

        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                _f_frame.dispose();
            }
        });
        _b_load.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                FileDialog fd_load = new FileDialog(_f_frame, "Load Files", FileDialog.LOAD);
                fd_load.setVisible(true);
                System.out.printf("%s%s%n", fd_load.getDirectory(), fd_load.getFile());
            }
        });
        _b_save.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                FileDialog fd_save = new FileDialog(_f_frame, "Save Files", FileDialog.SAVE);
                fd_save.setVisible(true);
                System.out.printf("%s%s%n", fd_save.getDirectory(), fd_save.getFile());
            }
        });
    }

    static public void main(String[] args) {
        new Java_FileDialog();
    }
}
