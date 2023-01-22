/* Java_Varargs.java
Author: BSS9395
Update: 2022-12-27T18:18:00+08@China-Shanghai+08
Design: Java Varargs
*/

public class Java_Varargs {
    public static void main(String[] args) {
        _Varargs("a", "b", "c");
        _Array(new String[] {"a", "b", "c"});
    }

    public static void _Varargs(String ...args) {
        for (String arg : args) {
            System.out.print(arg);
        }
        System.out.println();
    }

    public static void _Array(String[] args) {
        for (String arg: args) {
            System.out.print(arg);
        }
        System.out.println();
    }
}
