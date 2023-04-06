/* Java_JComponent.java
Author: BSS9395
Update: 2023-03-27T14:05:00+08@China-Shanghai+08
Design: Java Standard Library: JComponent
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.InputEvent;

public class Java_JComponent {
    public JFrame     _f_frame  = new JFrame("JComponent: getInputMap(), getActionMap()");
    public JTextArea  _ta_area  = new JTextArea(5, 40);
    public JTextField _tf_field = new JTextField(30);
    public JButton    _b_button = new JButton("Send");
    public Java_JComponent() {
        _f_frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        _f_frame.add(_ta_area);

        JPanel p_panel = new JPanel();
        p_panel.add(_tf_field);
        p_panel.add(_b_button);
        _f_frame.add(p_panel, BorderLayout.SOUTH);

        // ActionListener <- Action <- AbstractAction
        Action listener = new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent event) {
                _ta_area.append(_tf_field.getText() + "\n");
                _tf_field.setText("");
            }
        };
        _b_button.addActionListener(listener);
        _tf_field.getInputMap().put(KeyStroke.getKeyStroke('\n', InputEvent.CTRL_DOWN_MASK), "send");
        _tf_field.getActionMap().put("send", listener);

        _f_frame.pack();
        _f_frame.setVisible(true);
    }

    static public void main(String[] args) {
        _getInputMap_getActionMap();
    }
    static public void _getInputMap_getActionMap() {
        new Java_JComponent();
    }
}
