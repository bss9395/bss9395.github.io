/* Java_DriverManager.java
Author: BSS9395
Update: 2023-04-11T16:53:00+08@China-Guangdong-Zhanjiang+08
Design: Java Standard Library: DriverManager
*/

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.sql.*;
import java.util.Properties;

public class Java_Statement {
    static public String _sql0 = "drop database if exists Management;                            ";
    static public String _sql1 = "create database Management;                                    ";
    static public String _sql2 = "create table Management.Teacher (                              " +
                                 "   _id     int             not null    auto_increment,         " +
                                 "   _name   varchar(256)    null,                               " +
                                 "   primary key(_id)                                            " +
                                 ");                                                             ";
    static public String _sql3 = "create table Management.Student (                              " +
                                 "   _id             int             not null    auto_increment, " +
                                 "   _name           varchar(255)    null,                       " +
                                 "   _teacher_id     int             null,                       " +
                                 "   primary key(_id),                                           " +
                                 "   foreign key(_teacher_id) references Management.Teacher(_id) " +
                                 ");                                                             ";
    static public String _sql4 = "insert into Management.Teacher values                          " +
                                 "(null, 'Yeeku'),                                               " +
                                 "(null, 'Leegang'),                                             " +
                                 "(null, 'Martine');                                             ";
    static public String _sql5 = "insert into Management.Student values                          " +
                                 "(null, '张三', 1),                                              " +
                                 "(null, '张三', 1),                                              " +
                                 "(null, '李四', 1),                                              " +
                                 "(null, '王五', 2),                                              " +
                                 "(null, '_王五', 2),                                             " +
                                 "(null, null, 2),                                               " +
                                 "(null, '赵六', null);                                           ";
    static public String _sql6 = "select Management.Student.*, Management.Teacher._name          " +
                                 "from Management.Student, Management.Teacher                    " +
                                 "where Management.Student._teacher_id = Management.Teacher._id; ";
    static public String[] _sqls = new String[] {
            _sql0, _sql1, _sql2, _sql3, _sql4, _sql5, _sql6
    };

    static public void main(String[] args) {
        _Properties();
        _execute();
        // _executeUpdate();
        // _executeQuery();
    }
    static public void _Properties() {
        try {
            Properties properties = new Properties();
            properties.setProperty("driver", "com.mysql.cj.jdbc.Driver");
            properties.setProperty("schema", "jdbc:mysql://");
            // properties.setProperty("address", "127.0.0.1:3306/");
            properties.setProperty("address", "192.168.190.137:3306/");
            properties.setProperty("username", "bss9395");
            properties.setProperty("password", "Password");
            properties.store(new FileOutputStream("Config.ini"), "");
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    static public void _execute() {
        try {
            Properties properties = new Properties();
            properties.load(new FileInputStream("Config.ini"));
            String driver = properties.getProperty("driver");
            String schema = properties.getProperty("schema");
            String address = properties.getProperty("address");
            String username = properties.getProperty("username");
            String password = properties.getProperty("password");

            Class.forName(driver);
            Connection connection = DriverManager.getConnection(schema + address, username, password);
            Statement statement = connection.createStatement();

            for(String sql : _sqls) {
                boolean result = statement.execute(sql);
                if(result == true) {
                    ResultSet resultset = statement.getResultSet();
                    ResultSetMetaData metadata = resultset.getMetaData();
                    for(int i = 1; i <= metadata.getColumnCount(); i += 1) {
                        System.out.printf("%15s", metadata.getColumnName(i));
                    }
                    System.out.println();

                    while(resultset.next() == true) {
                        for(int i = 1; i <= metadata.getColumnCount(); i += 1) {
                            System.out.printf("%15s", resultset.getString(i));
                        }
                        System.out.println();
                    }
                } else {
                    System.out.printf("%s rows affected.%n", statement.getUpdateCount());
                }
            }
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
    static public void _executeUpdate() {
        try {
            Properties properties = new Properties();
            properties.load(new FileInputStream("Config.ini"));
            String driver = properties.getProperty("driver");
            String schema = properties.getProperty("schema");
            String address = properties.getProperty("address");
            String username = properties.getProperty("username");
            String password = properties.getProperty("password");

            Class.forName(driver);
            Connection connection = DriverManager.getConnection(schema + address, username, password);
            Statement statement = connection.createStatement();
            int result = 0;
            result = statement.executeUpdate(_sql0);
            result = statement.executeUpdate(_sql1);
            result = statement.executeUpdate(_sql2);
            result = statement.executeUpdate(_sql3);
            result = statement.executeUpdate(_sql4);
            result = statement.executeUpdate(_sql5);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
    static public void _executeQuery() {
        try {
            Properties properties = new Properties();
            properties.load(new FileInputStream("Config.ini"));
            String driver = properties.getProperty("driver");
            String schema = properties.getProperty("schema");
            String address = properties.getProperty("address");
            String username = properties.getProperty("username");
            String password = properties.getProperty("password");

            Class.forName(driver);
            Connection connection = DriverManager.getConnection(schema + address, username, password);
            Statement statement = connection.createStatement();
            ResultSet resultset = statement.executeQuery(_sql6);
            while(resultset.next() == true) {
                System.out.printf("%3s,%10s,%3s,%10s%n", resultset.getString(1), resultset.getString(2), resultset.getString(3), resultset.getString(4));
            }
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
}
