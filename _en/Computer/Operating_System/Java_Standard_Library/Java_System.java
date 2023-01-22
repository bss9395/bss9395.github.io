/* Java_System.java
Author: BSS9395
Update: 2023-01-08T17:37:00+08@China-Shanghai+08
Design: Java Standard Library: System
*/

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Map;
import java.util.Properties;

public class Java_System {
    static public void main(String[] args) {
        // _getenv();
        // _getProperties();
        _identityHashCode();
    }
    static public void _getenv() {
        System.out.println("static public void _getenv() {");
        Map<String, String> env = System.getenv();
        for (var name : env.keySet()) {
            System.out.printf("%40s -> %s %n", name, env.get(name));
        }
    }
    static public void _getProperties() {
        System.out.println("static public void _getProperties() {");
        try {
            Properties properties = System.getProperties();
            System.out.println(properties.getProperty("os.name"));
            properties.store(new FileOutputStream("dump.txt"), "System Properties");
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _identityHashCode() {
        System.out.println("static public void _identityHashCode() {");
        String hello_0 = "Hello";
        String hello_1 = "Hello";
        System.out.println(hello_0.hashCode() == hello_1.hashCode());
        System.out.println(System.identityHashCode(hello_0) == System.identityHashCode(hello_1));

        String world_0 = new String("World");
        String world_1 = new String("World");
        System.out.println(world_0.hashCode() == world_1.hashCode());
        System.out.println(System.identityHashCode(world_0) == System.identityHashCode(world_1));
    }
}
