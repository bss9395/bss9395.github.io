/* Java_Savepoint.java
Author: BSS9395
Update: 2023-04-26T15:27:00+08@China-Guangdong-Zhanjiang+08
Design: Java Standard Library
*/

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Savepoint;
import java.sql.Statement;

public class Java_Savepoint {
    static public String _driver   = "com.mysql.cj.jdbc.Driver";
    static public String _schema   = "jdbc:mysql://";
    static public String _address  = "192.168.190.137:3306/?useSSL=false&serverTimezone=UTC";
    static public String _username = "bss9395";
    static public String _password = "Password";

    static public void main(String[] args) {
        // _Savepoint();
        _executeLargeBatch();
    }
    static public void _Savepoint() {
        String[] sqls = new String[] {
            "insert into Management.Student values(null, 'aaa', 1);",
            "insert into Management.Student values(null, 'bbb', 1);",
            "insert into Management.Student values(null, 'ccc', 1);",
            "insert into Management.Student values(null, 'ddd', 5);"  // note: failed.
        };

        Connection connection = null;
        Statement  statement  = null;
        Savepoint  savepoint  = null;
        try {
            Class.forName(_driver);
            connection = DriverManager.getConnection(_schema + _address, _username, _password);
            connection.setAutoCommit(false);
            statement = connection.createStatement();
            for(int i = 0; i < sqls.length; i += 1) {
                if(i == 1) {
                    savepoint = connection.setSavepoint();
                }
                statement.executeUpdate(sqls[i]);
            }
            connection.commit();
        } catch (Exception exception) {
            exception.printStackTrace();

            try {
                connection.rollback(savepoint);
                connection.commit();
            } catch (Exception except) {
                except.printStackTrace();
            }
        } finally {
            try {
                if (statement != null) {
                    statement.close();
                }
                if (connection != null) {
                    connection.close();
                }
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
    }
    static public void _executeLargeBatch() {
        String[] sqls = new String[] {
            "insert into Management.Student values(null, 'aaa', 1);",
            "insert into Management.Student values(null, 'bbb', 1);",
            "insert into Management.Student values(null, 'ccc', 1);",
            // "insert into Management.Student values(null, 'ddd', 5);"  // note: failed.
        };

        try {
            Class.forName(_driver);
            try (Connection connection = DriverManager.getConnection(_schema + _address, _username, _password)) {
                boolean auto_commit = connection.getAutoCommit();
                connection.setAutoCommit(false);
                try(Statement statement = connection.createStatement()) {
                    for (int i = 0; i < sqls.length; i += 1) {
                        statement.addBatch(sqls[i]);
                    }
                    statement.executeLargeBatch();
                    connection.commit();
                    connection.setAutoCommit(auto_commit);
                }
            }
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
}
