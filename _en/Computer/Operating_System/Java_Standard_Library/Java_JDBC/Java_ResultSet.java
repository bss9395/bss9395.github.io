/* Java_ResultSet.java
Author: BSS9395
Update: 2023-04-23T22:43:00+08@China-Guangdong-Zhanjiang+08
Design: Java Standard Library: ResultSet
*/

import java.sql.*;

public class Java_ResultSet {
    static public String _driver   = "com.mysql.cj.jdbc.Driver";
    static public String _schema   = "jdbc:mysql://";
    static public String _address  = "192.168.190.137:3306/";
    static public String _username = "bss9395";
    static public String _password = "Password";

    static public void main(String[] args) throws Exception {
        _ResultSet();
    }
    static public void _ResultSet() throws Exception {
        Class.forName(_driver);

        String sql = "select *                " +
                     "from Management.Student;";

        Connection connection = DriverManager.getConnection(_schema + _address, _username, _password);
        PreparedStatement prepared = connection.prepareStatement(sql, ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
        ResultSet result = prepared.executeQuery();

        result.first();
        System.out.printf("result.first().getRow() = %s%n", result.getRow());
        result.last();
        System.out.printf("result.last().getRow()  = %s%n", result.getRow());

        ResultSetMetaData metadata = result.getMetaData();
        for(int i = 1; i <= metadata.getColumnCount(); i += 1) {
            System.out.printf("%15s", metadata.getColumnName(i));
        }
        System.out.println();

        result.afterLast();
        while(result.previous() == true) {
            for(int j = 1; j <= metadata.getColumnCount(); j += 1) {
                System.out.printf("%15s", result.getString(j));
            }
            System.out.println();

            result.updateString(2, String.format("id_%s_%s", result.getString(1), result.getString(2)));
            result.updateRow();
        }
    }
}
