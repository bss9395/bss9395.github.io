/* Java_URLClassLoader.java
Author: BSS9395
Update: 2023-02-26T20:41:00+08@China-Shanghai+08
Design: Java Standard Library: URLClassLoader
*/

import java.lang.reflect.InvocationTargetException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.sql.Connection;
import java.sql.Driver;
import java.sql.SQLException;
import java.util.Properties;

public class Java_URLClassLoader {
    public Connection _connection = null;
    public Connection _Connect(String url, String user, String password)
            throws MalformedURLException, ClassNotFoundException, SQLException, NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException {
        if(_connection == null) {
            URL[] urls = {
                new URL("file:mysql-connector-j-8.0.31.jar")
            };
            URLClassLoader loader = new URLClassLoader(urls);
            Driver driver = (Driver)loader.loadClass("com.mysql.cj.jdbc.Driver").getConstructor().newInstance();

            Properties properties = new Properties();
            properties.setProperty("user", user);
            properties.setProperty("password", password);
            _connection = driver.connect(url, properties);
        }
        return _connection;
    }

    static public void main(String[] args) {
        _URLClassLoader();
    }
    static public void _URLClassLoader() {
        try {
            Java_URLClassLoader connect = new Java_URLClassLoader();
            Connection connection = connect._Connect("jdbc:mysql://localhost:3306/world", "bss9395", "Password");
            System.out.println(connection);
        } catch(Exception exception) {
            exception.printStackTrace();
        }
    }
}
