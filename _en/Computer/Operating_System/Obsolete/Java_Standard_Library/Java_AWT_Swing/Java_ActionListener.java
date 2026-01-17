/* Java_ActionListener.java
Author: BSS9395
Update: 2023-03-28T15:28:00+08@China-Shanghai+08
Design: Java Standard Library: ActionListener
*/

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Java_ActionListener {
    public Frame _f_frame = new Frame("Java ActionListener");
    public TextField _tf_field = new TextField(30);
    public Button _b_button = new Button("Click");
    public Java_ActionListener() {
        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                _f_frame.dispose();
            }
        });

        _b_button.addActionListener((event) -> {
            System.out.println("Hello, World!\n");
            _tf_field.setText("Hello, World!\n" + _tf_field.getText());
        });
        _f_frame.add(_tf_field);
        _f_frame.add(_b_button, BorderLayout.SOUTH);

        _f_frame.pack();
        _f_frame.setVisible(true);
    }

    static public void main(String[] args) {
        new Java_ActionListener();
    }
}
