/* Java_PreparedStatement.java
Author: BSS9395
Update: 2023-04-23T22:45:00+08@China-Guangdong-Zhanjiang+08
Design: Java Standard Library: PreparedStatement
*/

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.Statement;
import java.util.Properties;

public class Java_PreparedStatement {
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
                                 "   foreign key(_teacher_id) references Teacher(_id)            " +
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
        _Statement();
        _PreparedStatement();
    }
    static public void _Properties() {
        try {
            Properties properties = new Properties();
            properties.setProperty("driver", "com.mysql.cj.jdbc.Driver");
            properties.setProperty("schema", "jdbc:mysql://");
            // properties.setProperty("address", "127.0.0.1:3306/");
            properties.setProperty("address", "192.168.190.136:3306/");
            properties.setProperty("username", "bss9395");
            properties.setProperty("password", "Password");
            properties.store(new FileOutputStream("Config.ini"), "");
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    static public void _Statement() {
        String sql = "insert into Management.Student values"
                   + "(null, '%s', 1);";
        try {
            Properties properties = new Properties();
            properties.load(new FileInputStream("Config.ini"));
            String driver   = properties.getProperty("driver");
            String schema   = properties.getProperty("schema");
            String address  = properties.getProperty("address");
            String username = properties.getProperty("username");
            String password = properties.getProperty("password");

            Class.forName(driver);
            Connection connection = DriverManager.getConnection(schema + address, username, password);
            Statement statement = connection.createStatement();
            long begin = System.currentTimeMillis();
            for(int i = 0; i < 100; i += 1) {
                statement.executeUpdate(String.format(sql, "姓名" + i));
            }
            System.out.printf("end - begin = %s%n", System.currentTimeMillis() - begin);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
    static public void _PreparedStatement() {
        String sql = "insert into Management.Student values"
                   + "(null, ?, 1);";
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
            PreparedStatement prepared = connection.prepareStatement(sql);
            long begin = System.currentTimeMillis();
            for(int i = 0; i < 100; i += 1) {
                prepared.setString(1, "姓名" + i);
                prepared.executeUpdate();
            }
            System.out.printf("end - begin = %s%n", System.currentTimeMillis() - begin);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
}
