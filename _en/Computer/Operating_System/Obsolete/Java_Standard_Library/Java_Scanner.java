/* Java_Scanner.java
Author: BSS9395
Update: 2023-01-07T22:47:00+08@China-Shanghai+08
Design: Java Standard Library: Scanner
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.text.SimpleDateFormat;
import java.util.Scanner;

public class Java_Scanner {
    static public void main(String[] args) {
        // _System_in();
        // _nextInt();
        // _Pattern();
        _File();
    }
    static public void _System_in() {
        Scanner scanner = new Scanner(System.in);
        scanner.useDelimiter("\n");
        while(scanner.hasNext() == true) {
            System.out.println(scanner.next());
        }
    }
    static public void _nextInt() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入年龄：");
        while(scanner.hasNextInt() == true) {
            int age = scanner.nextInt();
            System.out.println("您的年龄：" + age);
        }
    }
    static public void _Pattern() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入生日：");
        if(scanner.hasNext("[0-9]{4}-[0-9]{2}-[0-9]{2}") == true) {
            String birthday = scanner.next("[0-9]{4}-[0-9]{2}-[0-9]{2}");
            try {
                System.out.println("输入信息为：" + new SimpleDateFormat("yyyy-MM-dd").parse(birthday));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
    static public void _File() {
        try {
            Scanner scanner = new Scanner(new File("src/Java_Scanner.java"));
            while(scanner.hasNextLine() == true) {
                System.out.println(scanner.nextLine());
            }
        } catch (FileNotFoundException exception) {
            exception.printStackTrace();
        }
    }
}
