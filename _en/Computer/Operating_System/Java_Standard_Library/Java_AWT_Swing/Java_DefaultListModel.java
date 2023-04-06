/* Java_DefaultListModel.java
Author: BSS9395
Update: 2023-03-30T13:37:00+08@China-Shanghai+08
Design: Java Standard Library: DefaultListModel
*/

import javax.swing.*;
import java.awt.*;

public class Java_DefaultListModel {
    public JFrame _f_frame = new JFrame("Java DefaultListModel");
    public DefaultListModel<String> _dlm_model = new DefaultListModel<String>();
    public JList<String> _l_list = new JList<String>(_dlm_model);
    public JTextField _tf_field = new JTextField(20);
    public JButton _b_add = new JButton("Add");
    public JButton _b_remove = new JButton("Remove");
    public Java_DefaultListModel() {
        _dlm_model.addElement("C");
        _dlm_model.addElement("C++");
        _dlm_model.addElement("C#");
        _dlm_model.addElement("Java");
        _dlm_model.addElement("Python");
        _l_list.setVisibleRowCount(4);
        _l_list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        _b_add.addActionListener((event) -> {
            if(_tf_field.getText().trim().equals("") == false) {
                _dlm_model.addElement(_tf_field.getText());
                _tf_field.setText("");
            }
        });
        _b_remove.addActionListener((event) -> {
            if(0 <= _l_list.getSelectedIndex() && _l_list.getSelectedIndex() < _dlm_model.getSize()) {
                _dlm_model.removeElementAt(_l_list.getSelectedIndex());
            }
        });
        _f_frame.add(new JScrollPane(_l_list));

        JPanel p_panel = new JPanel();
        p_panel.add(_tf_field);
        p_panel.add(_b_add);
        p_panel.add(_b_remove);
        _f_frame.add(p_panel, BorderLayout.SOUTH);
        _f_frame.pack();
        _f_frame.setVisible(true);
        _f_frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    static public void main(String[] args) {
        new Java_DefaultListModel();
    }
}
