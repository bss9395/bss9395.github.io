/* Java_finally.java
Author: bss9395
Update: 2025-07-29T22:43:00+08@China-GuangDong-ZhanJiang+08
*/

public class Java_finally {
    public static void _Function() throws Throwable {
        System.out.println("begin function.");
        if(true) {
            throw new Throwable("error occurred.");
        }
        System.out.println("end function.");
    }

    public static void main(String[] args) {
        try {
            try {
                _Function();
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
}
