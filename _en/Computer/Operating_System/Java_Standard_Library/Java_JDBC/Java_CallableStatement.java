/* Java_CallableStatement.java
Author: BSS9395
Update: 2023-04-23T21:30:00+08@China-Guangdong-Zhanjiang+08
Design: Java Standard Library: CallableStatement
*/

import java.sql.*;

public class Java_CallableStatement {
    static public String _driver   = "com.mysql.cj.jdbc.Driver";
    static public String _schema   = "jdbc:mysql://";
    static public String _address  = "192.168.190.137:3306/";
    static public String _username = "bss9395";
    static public String _password = "Password";

    static public void main(String[] args) throws Exception {
        _CallableStatement();
    }
    static public void _CallableStatement() throws Exception {
        Class.forName(_driver);
        Connection connection = DriverManager.getConnection(_schema + _address, _username, _password);
        String sql = "{call Management.P_Add(?, ?, ?)};";
        CallableStatement callable = connection.prepareCall(sql);
        callable.setDouble(1, 4.5);
        callable.setDouble(2, 5.6);
        callable.registerOutParameter(3, Types.DOUBLE);
        callable.execute();
        System.out.println(callable.getDouble(3));
        callable.close();
        connection.close();
    }
}
