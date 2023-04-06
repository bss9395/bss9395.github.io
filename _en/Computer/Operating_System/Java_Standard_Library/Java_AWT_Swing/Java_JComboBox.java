/* Java_JComboBox.java
Author: BSS9395
Update: 2023-03-29T22:13:00+08@China-Shanghai+08
Design: Java Standard Library: JComboBox
*/

import javax.swing.*;
import javax.swing.border.EtchedBorder;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.util.List;

public class Java_JComboBox {
    String[] langs = new String[] {
            "C", "C++", "C#", "Java", "Python"
    };
    public JFrame _f_frame = new JFrame("Java JList");
    JList<String> _l_books = new JList<String>(langs);
    JComboBox<String> _cb_books = new JComboBox<String>(langs);
    JPanel _p_layout = new JPanel();
    JPanel _p_mode = new JPanel();
    JTextArea _ta_area = new JTextArea(4, 40);
    public Java_JComboBox() {
        _l_books.setVisibleRowCount(3);

        _p_layout.setBorder(new TitledBorder(new EtchedBorder(), "Layout"));
        ButtonGroup bg_layout = new ButtonGroup();
        _Add_Layout(bg_layout, "Vertical", JList.VERTICAL);
        _Add_Layout(bg_layout, "Vertical_Wrap", JList.VERTICAL_WRAP);
        _Add_Layout(bg_layout, "Horizontal_Wrap", JList.HORIZONTAL_WRAP);

        _p_mode.setBorder(new TitledBorder(new EtchedBorder(), "Mode"));
        ButtonGroup bg_mode = new ButtonGroup();
        _Add_Mode(bg_mode, "Single_Selection", ListSelectionModel.SINGLE_SELECTION);
        _Add_Mode(bg_mode, "Single_Interval_Selection", ListSelectionModel.SINGLE_INTERVAL_SELECTION);
        _Add_Mode(bg_mode, "Multiple_Interval_Selection", ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);

        Box b_vertical = new Box(BoxLayout.Y_AXIS);
        _l_books.addListSelectionListener((event) -> {
            List<String> books = _l_books.getSelectedValuesList();
            _ta_area.setText("");
            for(String book : books) {
                _ta_area.append(book + "\n");
            }
        });
        b_vertical.add(new JScrollPane(_l_books));
        b_vertical.add(_p_layout);
        b_vertical.add(_p_mode);

        _cb_books.setEditable(true);
        _cb_books.setMaximumRowCount(4);
        _cb_books.addActionListener((event) -> {
            Object book = _cb_books.getSelectedItem();
            _ta_area.setText(book.toString());
        });

        Box b_horizontal = new Box(BoxLayout.X_AXIS);
        b_horizontal.add(b_vertical);
        JPanel p_panel = new JPanel();
        p_panel.add(_cb_books);
        b_horizontal.add(p_panel);
        _f_frame.add(b_horizontal);

        JPanel p_bottom = new JPanel();
        p_bottom.setLayout(new BorderLayout());
        p_bottom.add(new JLabel("Your favorite: "), BorderLayout.NORTH);
        p_bottom.add(new JScrollPane(_ta_area));
        _f_frame.add(p_bottom, BorderLayout.SOUTH);
        _f_frame.pack();
        _f_frame.setVisible(true);
        _f_frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public void _Add_Layout(ButtonGroup group, String text, int layout) {
        JRadioButton radio = new JRadioButton(text);
        radio.addActionListener((event) -> {
            _l_books.setLayoutOrientation(layout);
        });
        group.add(radio);
        _p_layout.add(radio);
    }
    public void _Add_Mode(ButtonGroup group, String text, int mode) {
        JRadioButton radio = new JRadioButton(text);
        radio.addActionListener((event) -> {
            _l_books.setSelectionMode(mode);
        });
        group.add(radio);
        _p_mode.add(radio);
    }

    static public void main(String[] args) {
        new Java_JComboBox();
    }
}
