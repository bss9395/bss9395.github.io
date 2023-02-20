/* Java_System.java
Author: BSS9395
Update: 2023-01-08T17:37:00+08@China-Shanghai+08
Design: Java Standard Library: System
*/

import java.io.*;
import java.util.Map;
import java.util.Properties;
import java.util.Scanner;

public class Java_System {
    static public void main(String[] args) {
        // _getenv();
        // _getProperties();
        // _identityHashCode();
        // _setOut();
        _setIn();
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
    static public void _setOut() {
        try(PrintStream stream = new PrintStream(new FileOutputStream("output.text"));) {
            System.setOut(stream);
            System.out.println("《武陵春·春晚》[宋代]李清照");
            System.out.println("风住尘香花已尽，日晚倦梳头。");
            System.out.println("物是人非事事休，欲语泪先流。");
            System.out.println("闻说双溪春尚好，也拟泛轻舟。");
            System.out.println("只恐双溪蚱蜢舟，载不动许多愁。");
        } catch (FileNotFoundException exception) {
            exception.printStackTrace();
        }
    }
    static public void _setIn() {
        try(FileInputStream stream = new FileInputStream("src/Java_System.java");) {
            System.setIn(stream);
            Scanner scanner = new Scanner(System.in);
            scanner.useDelimiter("\n");
            while(scanner.hasNext() == true) {
                System.out.println(scanner.next());
            }
        } catch (IOException exception) {
            exception.printStackTrace();
        }

    }
}
