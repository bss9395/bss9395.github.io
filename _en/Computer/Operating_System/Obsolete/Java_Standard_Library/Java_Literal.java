/* Java_Literal.java
Author: BSS9395
Update: 2022-12-30T21:48:00+08@China-Shanghai+08
Design: Java Literal
*/

public class Java_Literal {
    public static void main(String[] args) {
        String str_0 = "Hello, World!";
        String str_1 = "Hello, ";
        String str_2 = "World!";
        String str_3 = "Hello, " + "World!";
        String str_4 = str_1 + str_2;
        String str_5 = new String("Hello, World!");

        System.out.println(str_0 == str_3);
        System.out.println(str_0 == str_4);
        System.out.println(str_0 == str_5);
    }
}
