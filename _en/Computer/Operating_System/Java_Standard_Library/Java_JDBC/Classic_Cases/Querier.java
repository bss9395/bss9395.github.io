/* Querier.java
Author: BSS9395
Update: 2023-04-25T18:04:00+08@China-Guangdong-Zhanjiang+08
Design: Querier
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.*;
import java.util.Vector;

public class Querier extends JDialog {
    static public String _driver   = "com.mysql.cj.jdbc.Driver";
    static public String _schema   = "jdbc:mysql://";
    static public String _address  = "192.168.190.137:3306/";
    static public String _username = "bss9395";
    static public String _password = "Password";

    public Connection _connection = DriverManager.getConnection(_schema + _address, _username, _password);
    public Statement  _statement  = _connection.createStatement();

    public Querier    _self       = this;
    public JTextField _tf_sql     = new JTextField();
    public JButton    _b_query    = new JButton("查询");
    public JPanel     _p_data     = new JPanel();
    public Querier() throws Exception {
        // Class.forName(_driver);

        JPanel b_center = new JPanel();
        JPanel p_query = new JPanel();
        _tf_sql.setText("select * from Management.Images;");
        p_query.add(_tf_sql);
        p_query.add(_b_query);
        b_center.add(p_query);
        b_center.add(_p_data);
        this.add(b_center);

        _b_query.setPreferredSize(new Dimension(60, 24));
        _tf_sql.setPreferredSize(new Dimension(600, 24));
        this.setPreferredSize(new Dimension(700, 500));
        this.pack();
        this.setVisible(true);

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                try {
                    _self._connection.close();
                } catch (Exception exception) {
                    exception.printStackTrace();
                }
                System.exit(0);
            }
        });
        _b_query.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    ResultSet              result = _statement.executeQuery(_tf_sql.getText());
                    ResultSetMetaData      meta   = result.getMetaData();
                    Vector<String>         header = new Vector<String>();
                    Vector<Vector<String>> body   = new Vector<Vector<String>>();
                    for(int i = 1; i <= meta.getColumnCount(); i += 1) {
                        header.add(meta.getColumnName(i));
                    }
                    while(result.next() == true) {
                        Vector<String> row = new Vector<String>();
                        for(int i = 1; i <= meta.getColumnCount(); i += 1) {
                            int type = meta.getColumnType(i);
                            if(type == Types.INTEGER || type == Types.VARCHAR) {
                                row.add(result.getString(i));
                            } else if (type == Types.LONGVARBINARY) {
                                row.add("Types.LONGVARBINARY");
                            }
                        }
                        body.add(row);
                    }

                    _p_data.removeAll();
                    _p_data.add(new JScrollPane(new JTable(body, header)));
                    _self.validate();
                } catch (Exception exception) {
                    exception.printStackTrace();
                }
            }
        });
    }
    static public void main(String[] args) throws Exception {
        new Querier();
    }
}
