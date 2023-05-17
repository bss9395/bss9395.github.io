/* Java_finally.java
Author: BSS9395
Update: 2023-05-16T19:47:00+08@China-Guangdong-Zhanjiang+08
Design: Java Keyword: finally
*/

public class Java_finally {
    public int _finally() {
        int x = 1;
        try {
            return x++;
        } finally {
            System.out.printf("finally: x=%s%n", ++x);
        }
    }
    public int _finally_return() {
        int x = 1;
        try {
            return x++;
        } finally {
            System.out.printf("finally: x=%s%n", ++x);
            return x;
        }
    }

    public static void main(String[] args) {
        System.out.printf("main: x=%s%n", new Java_finally()._finally());
        System.out.printf("main: x=%s%n", new Java_finally()._finally_return());
    }
}
