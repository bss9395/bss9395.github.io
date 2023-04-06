/* Java_AWT.java
Author: BSS9395
Update: 2023-03-29T14:06:00+08@China-Shanghai+08
Design: Java Standard Library: AWT
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Java_AWT {
    Frame _f_frame = new Frame("Java AWT");
    TextArea _ta_area = new TextArea(5, 20);
    Choice _c_colors = new Choice();
    CheckboxGroup _cbg_gender = new CheckboxGroup();
    Checkbox _cb_male = new Checkbox("Male", _cbg_gender, true);
    Checkbox _cb_female = new Checkbox("Female", _cbg_gender, false);
    Checkbox _cb_married = new Checkbox("Married", false);
    List _l_colors = new List(6, true);
    TextField _tf_field = new TextField(50);
    Button _b_button = new Button("Ok");
    public Java_AWT() {
        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        Box horizontal = Box.createHorizontalBox();
        Box vertical = Box.createVerticalBox();
        vertical.add(_ta_area);
        Panel p_check = new Panel();
        _c_colors.add("Red");
        _c_colors.add("Green");
        _c_colors.add("Blue");
        p_check.add(_c_colors);
        p_check.add(_cb_male);
        p_check.add(_cb_female);
        p_check.add(_cb_married);
        vertical.add(p_check);
        horizontal.add(vertical);
        _l_colors.add("Red");
        _l_colors.add("Green");
        _l_colors.add("Blue");
        horizontal.add(_l_colors);
        _f_frame.add(horizontal, BorderLayout.CENTER);

        Panel p_panel = new Panel();
        p_panel.add(_tf_field);
        p_panel.add(_b_button);
        _f_frame.add(p_panel, BorderLayout.SOUTH);

        _f_frame.pack();
        _f_frame.setVisible(true);
    }

    static public void main(String[] args) {
        new Java_AWT();
    }
}
