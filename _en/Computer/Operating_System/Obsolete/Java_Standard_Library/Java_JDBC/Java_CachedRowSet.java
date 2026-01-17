/* Java_CachedRowSet.java
Author: BSS9395
Update: 2023-04-25T22:08:00+08@China-Guangdong-Zhanjiang+08
Design: Java Standard Library: CachedRowSet
*/

import java.sql.*;
import javax.sql.rowset.*;

public class Java_CachedRowSet {
    static public String _driver   = "com.mysql.cj.jdbc.Driver";
    static public String _schema   = "jdbc:mysql://";
    static public String _address  = "192.168.190.137:3306/?useSSL=false&serverTimezone=UTC";
    static public String _username = "bss9395";
    static public String _password = "Password";

    static public void main(String[] args) throws Exception {
        _CachedRowSet();
    }
    static public void _CachedRowSet() throws Exception {
        Class.forName(_driver);
        CachedRowSet cached = _Query("select * from Management.Student;", 3, 2);
        ResultSetMetaData meta = cached.getMetaData();
        for(int i = 1; i <= meta.getColumnCount(); i += 1) {
            System.out.printf("%15s", meta.getColumnName(i));
        }
        System.out.println();

        cached.afterLast();
        while(cached.previous() == true) {
            for(int i = 1; i <= meta.getColumnCount(); i += 1) {
                System.out.printf("%15s", cached.getString(i));
            }
            System.out.println();

            if(cached.getInt(1) == 4) {
                cached.updateString(2, cached.getString(1) + "bss9395");
                cached.updateRow();
            }
        }

        Connection connection = DriverManager.getConnection(_schema + _address, _username, _password);
        connection.setAutoCommit(false);
        cached.acceptChanges(connection);
    }
    static public CachedRowSet _Query(String sql, int page_size, int page) throws Exception {
        Class.forName(_driver);
        Connection connection = DriverManager.getConnection(_schema + _address, _username, _password);
        Statement statement = connection.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
        ResultSet result = statement.executeQuery(sql);

        RowSetFactory factory = RowSetProvider.newFactory();
        CachedRowSet cached = factory.createCachedRowSet();
        cached.setPageSize(page_size);
        cached.populate(result, 4);
        // cached.previousPage();  // note: useless
        result.close();
        statement.close();
        connection.close();
        return cached;
    }
}