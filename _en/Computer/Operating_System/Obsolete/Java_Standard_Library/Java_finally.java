/* Java_finally.java
Author: bss9395
Update: 2025-07-29T22:43:00+08@China-GuangDong-ZhanJiang+08
*/

public class Java_finally {
    public static void _Test_finally() {
        try {
            try {
                if(true) {
                    throw new Throwable("error occurred.");
                }
            } catch (Throwable except) {
                System.out.println("exception caught: " + except.getMessage());
                throw except;
            } finally {
                System.out.println("finally executed.");
            }
            System.out.println("after try.");
        } catch (Throwable except) {
            System.out.println("outer try: " + except.getMessage());
        }
    }

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
        // _Test_finally();
        System.out.printf("main: x=%s%n", new Java_finally()._finally());
        System.out.printf("main: x=%s%n", new Java_finally()._finally_return());
    }
}
