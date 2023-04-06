/* Java_AbstractListModel.java
Author: BSS9395
Update: 2023-03-30T14:13:00+08@China-Shanghai+08
Design: Java Standard Library: AbstractListModel
*/

import javax.swing.*;
import java.awt.*;
import java.math.BigDecimal;
import java.util.List;

public class Java_AbstractListModel {
    static class ListModel_Number extends AbstractListModel<BigDecimal> {
        public BigDecimal _beg = BigDecimal.valueOf(0.0);
        public BigDecimal _end = BigDecimal.valueOf(0.0);
        public BigDecimal _step = BigDecimal.valueOf(2.0);
        public ListModel_Number(double beg, double end, double step) {
            _beg = BigDecimal.valueOf(beg);
            _end = BigDecimal.valueOf(end);
            _step = BigDecimal.valueOf(step);
        }
        @Override
        public int getSize() {
            return 1 + (int) (_end.subtract(_beg).divide(_step).doubleValue());
        }
        @Override
        public BigDecimal getElementAt(int index) {
            return _beg.add(BigDecimal.valueOf(index).multiply(_beg));
        }
    }
    static class ComboBoxModel_Number extends ListModel_Number implements ComboBoxModel<BigDecimal> {
        public BigDecimal _decimal = _beg;
        public ComboBoxModel_Number(double beg, double end, double step) {
            super(beg, end, step);
        }
        @Override
        public void setSelectedItem(Object item) {
            if(item instanceof BigDecimal) {
                _decimal = (BigDecimal) item;
            }
        }
        @Override
        public Object getSelectedItem() {
            return _decimal;
        }
    }

    public JFrame _f_frame = new JFrame();
    public JList<BigDecimal> _l_decimal = new JList<BigDecimal>(new ListModel_Number(1.0, 21.0, 2.0));
    public JComboBox<BigDecimal> _cb_decimal = new JComboBox<BigDecimal>(new ComboBoxModel_Number(0.1, 1.2, 0.1));
    public JTextField _tf_field = new JTextField(10);
    public Java_AbstractListModel() {
        _l_decimal.setVisibleRowCount(4);
        _l_decimal.setFixedCellWidth(90);
        _l_decimal.setFixedCellHeight(30);
        _l_decimal.addListSelectionListener((event) -> {
            List<BigDecimal> decimals = _l_decimal.getSelectedValuesList();
            _tf_field.setText("");
            for(BigDecimal decimal : decimals) {
                _tf_field.setText(_tf_field.getText() + decimal.doubleValue() + ", ");
            }
        });
        _cb_decimal.setMaximumRowCount(5);
        _cb_decimal.addItemListener((event) -> {
            BigDecimal decimal = (BigDecimal) _cb_decimal.getSelectedItem();
            _tf_field.setText(String.valueOf(decimal.doubleValue()));
        });
        Box horizontal = new Box(BoxLayout.X_AXIS);
        horizontal.add(new JScrollPane(_l_decimal));
        JPanel p_panel = new JPanel();
        p_panel.add(_cb_decimal);
        horizontal.add(p_panel);
        _f_frame.add(horizontal);
        _f_frame.add(_tf_field, BorderLayout.SOUTH);
        _f_frame.pack();
        _f_frame.setVisible(true);
        _f_frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    static public void main(String[] args) {
        new Java_AbstractListModel();
    }
}
