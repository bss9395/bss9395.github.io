/* Java_null.java
Author: BSS9395
Update: 2023-01-01T19:50:00+08@China-Shanghai+08
Design: Java null pointer
*/

public class Java_null {
    public static void main(String[] args) {
        Java_null._Function_Static();
        Java_null java_null = null;
        java_null._Function_Static();

        java_null._Function();  // raise java.lang.NullPointerException
    }
    public static void _Function_Static() {
        System.out.println("public static void _Function_Static() {");
    }
    public void _Function() {
        System.out.println("public void _Function() {");
    }
}
