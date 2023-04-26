/* SQL_Injection.java
Author: BSS9395
Update: 2023-04-23T19:59:00+08@China-Guangdong-Zhanjiang+08
Design: SQL Injection
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.*;

public class SQL_Injection {
    String _driver = "com.mysql.cj.jdbc.Driver";
    String _schema = "jdbc:mysql://";
    // String _address = "127.0.0.1:3306/";
    String _address = "192.168.190.137:3306/";
    String _username = "bss9395";
    String _password = "Password";

    JFrame            _f_frame       = new JFrame("登录");
    JLabel            _l_validation  = new JLabel("方法: ");
    JComboBox<String> _cb_validation = new JComboBox<String>(new String[]{
            "Statement", "PreparedStatement"
    });
    JLabel            _l_id          = new JLabel("ID: ");
    JTextField        _tf_id         = new JTextField(30);
    JLabel            _l_name        = new JLabel("昵称: ");
    JTextField        _tf_name       = new JTextField(30);
    JButton           _b_button      = new JButton("登录");
    public SQL_Injection() throws Exception {
        Class.forName(_driver);

        _f_frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                System.exit(0);
            }
        });

        /*
        _id _name
        1	Yeeku
        2	Leegang
        3	Martine
        */
        _b_button.addActionListener((event) -> {
            boolean validated = false;
            if(_cb_validation.getSelectedItem().toString().equals("Statement")) {
                validated = _Validate_Statement(_tf_id.getText(), _tf_name.getText());
            }
            else if(_cb_validation.getSelectedItem().toString().equals("PreparedStatement")) {
                validated = _Validate_PrepareStatement(_tf_id.getText(), _tf_name.getText());
            }

            if(validated == true) {
                JOptionPane.showMessageDialog(_f_frame, "登录成功！");
            } else {
                JOptionPane.showMessageDialog(_f_frame, "登录失败！");
            }
        });

        Box b_center = new Box(BoxLayout.Y_AXIS);
        Box b_validation = new Box(BoxLayout.X_AXIS);
        _l_validation.setPreferredSize(new Dimension(40, 24));
        b_validation.add(_l_validation);
        b_validation.add(_cb_validation);
        b_center.add(b_validation);

        Box b_id = new Box(BoxLayout.X_AXIS);
        _l_id.setPreferredSize(new Dimension(40, 24));
        _tf_id.setText("' or true or '");
        _tf_id.setToolTipText("1");
        b_id.add(_l_id);
        b_id.add(_tf_id);
        b_center.add(b_id);

        Box b_name = new Box(BoxLayout.X_AXIS);
        _l_name.setPreferredSize(new Dimension(40, 24));
        _tf_name.setToolTipText("YeeKu");
        b_name.add(_l_name);
        b_name.add(_tf_name);
        b_center.add(b_name);

        JPanel p_button = new JPanel();
        p_button.add(_b_button);
        b_center.add(p_button);

        _f_frame.add(b_center);
        _f_frame.pack();
        _f_frame.setVisible(true);
    }

    public boolean _Validate_Statement(String id, String name) {
        String sql = "select *                      " +
                     "from Management.Teacher       " +
                     "where _id='%s' and _name='%s';";
        try {
            Connection connection = DriverManager.getConnection(_schema + _address, _username, _password);
            Statement statement = connection.createStatement();
            String query = String.format(sql, id, name);
            System.out.println(query);
            ResultSet result = statement.executeQuery(query);
            if(result.next() == true) {
                return true;
            }
        } catch (Exception exception) {
            exception.printStackTrace();
        }
        return false;
    }
    public boolean _Validate_PrepareStatement(String id, String name) {
        String sql = "select *                " +
                     "from Management.Teacher " +
                     "where _id=? and _name=?;";
        try {
            Connection connection = DriverManager.getConnection(_schema + _address, _username, _password);
            PreparedStatement prepared = connection.prepareStatement(sql);
            prepared.setString(1, id);
            prepared.setString(2, name);
            System.out.println(prepared);
            ResultSet result = prepared.executeQuery();
            if(result.next() == true) {
                return true;
            }
        } catch (Exception exception) {
            exception.printStackTrace();
        }
        return false;
    }

    static public void main(String[] args) throws Exception {
        new SQL_Injection();
    }
}
