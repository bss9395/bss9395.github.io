/* JDBC_DataSource.java
Author: BSS9395
Update: 2023-04-26T21:55:00+08@China-Guangdong-Zhanjiang+08
Design: JDBC DataSource
*/

import com.mchange.v2.c3p0.ComboPooledDataSource;
import org.apache.commons.dbcp2.BasicDataSource;


import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.beans.PropertyVetoException;
import java.sql.*;
import java.util.Vector;

public class JDBC_DataSource extends JDialog {
    static public String                _driver                = "com.mysql.cj.jdbc.Driver";
    static public String                _schema                = "jdbc:mysql://";
    static public String                _address               = "192.168.190.137:3306/";
    static public String                _username              = "bss9395";
    static public String                _password              = "Password";
    static public int                   _connection_init       = 5;
    static public int                   _connection_max        = 20;
    static public int                   _connection_min        = 2;
    static public int                   _datasource_count      = 0;
    static public BasicDataSource       _basicdatasource       = new BasicDataSource();        // note: DBCP Data Source
    static public ComboPooledDataSource _combopooleddatasource = new ComboPooledDataSource();  // note: C3P0 Data Source
    static public String[]              _datasources           = new String[] {
         "DriverManager", "BasicDataSource", "ComboPooledDataSource"
    };

    public JDBC_DataSource   _self          = this;
    public JComboBox<String> _cb_datasource = new JComboBox<String>(_datasources);
    public JTextField        _tf_sql        = new JTextField();
    public JButton           _b_query       = new JButton("查询");
    public JPanel            _p_data        = new JPanel();
    public JDBC_DataSource() throws Exception {
        _Setup_Data_Source();

        JPanel b_center = new JPanel();
        b_center.add(_cb_datasource);
        JPanel p_query = new JPanel();
        _tf_sql.setText("select * from Management.Images;");
        p_query.add(_tf_sql);
        p_query.add(_b_query);
        b_center.add(p_query);
        b_center.add(_p_data);
        _self.add(b_center, BorderLayout.CENTER);

        _b_query.setPreferredSize(new Dimension(60, 24));
        _tf_sql.setPreferredSize(new Dimension(600, 24));
        _self.setPreferredSize(new Dimension(700, 500));
        _self.pack();
        _self.setVisible(true);

        _self.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                _Cleanup_Data_Source();
                _self.dispose();
            }
        });
        _cb_datasource.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent event) {
                if (event.getStateChange() == ItemEvent.DESELECTED) {
                    _p_data.removeAll();
                    _self.validate();
                }
            }
        });
        _b_query.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                Connection connection = null;
                boolean    manager    = false;
                try {
                    if(_cb_datasource.getSelectedItem().toString().equals("DriverManager")) {
                        connection = DriverManager.getConnection(_schema + _address, _username, _password);
                        manager = true;
                    }
                    else if(_cb_datasource.getSelectedItem().toString().equals("BasicDataSource")) {
                        connection = _basicdatasource.getConnection();
                    } else if (_cb_datasource.getSelectedItem().toString().equals("ComboPooledDataSource")) {
                        connection = _combopooleddatasource.getConnection();
                    }
                    ResultSet              result = connection.createStatement().executeQuery(_tf_sql.getText());
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
                } finally {
                    if(manager == true && connection != null) {
                        try {
                            connection.close();
                        } catch (Exception exception) {
                            exception.printStackTrace();
                        }
                    }
                }
            }
        });
    }
    public void _Setup_Data_Source() throws PropertyVetoException {
        if(1 <= _datasource_count) {
            return ;
        }
        _datasource_count += 1;

        _basicdatasource.setDriverClassName(_driver);
        _basicdatasource.setUrl(_schema + _address);
        _basicdatasource.setUsername(_username);
        _basicdatasource.setPassword(_password);
        _basicdatasource.setInitialSize(_connection_init);
        _basicdatasource.setMaxTotal(_connection_max);
        _basicdatasource.setMinIdle(_connection_min);

        ////////////////////////////////////////////////////////////////////

        _combopooleddatasource.setDriverClass(_driver);
        _combopooleddatasource.setJdbcUrl(_schema + _address);
        _combopooleddatasource.setUser(_username);
        _combopooleddatasource.setPassword(_password);
        _combopooleddatasource.setMaxPoolSize(_connection_max);
        _combopooleddatasource.setMinPoolSize(_connection_min);
        _combopooleddatasource.setInitialPoolSize(_connection_init);
        _combopooleddatasource.setMaxStatements(_connection_max);
    }
    public void _Cleanup_Data_Source() {
        _datasource_count -= 1;
        if(1 <= _datasource_count) {
            return ;
        }

        try {
            _basicdatasource.close();
            _combopooleddatasource.close();
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    static public void main(String[] args) throws Exception {
        new JDBC_DataSource();
    }
}
