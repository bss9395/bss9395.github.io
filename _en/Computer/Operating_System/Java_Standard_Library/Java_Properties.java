/* Java_Properties.java
Author: BSS9395
Update: 2023-01-28
Design: Java Standard Library: Properties
*/

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Properties;

public class Java_Properties {
    static public void main(String[] args) {
        _Properties();
    }
    static public void _Properties() {
        try {
            Properties dump = new Properties();
            dump.setProperty("ID", "1156");
            dump.setProperty("Gender", "Male");
            dump.store(new FileOutputStream("info.config"), "comments");
        } catch (IOException exception) {
            exception.printStackTrace();
        }

        try {
            Properties load = new Properties();
            load.load(new FileInputStream("info.config"));
            System.out.println(load);
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
}
