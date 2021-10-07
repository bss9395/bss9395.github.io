/* Equality_Operator.java
Author: BSS9395
Update: 2021-10-08T17:01:00+08@China-Guangdong-Shenzhen+08
Design: Java Equality Operator
*/

public class Equality_Operator {
    public static void main(String[] args) {
        String str1 = "Hello";
        String str2 = "Hello";
        String str3 = "He" + "llo";
        System.out.printf("%b, %b %n", str1 == str2, str1 == str3);

        ////////////////////////////////
        System.out.println("========================================");
        Equality_Operator cls1 = new Equality_Operator();
        Equality_Operator cls2 = new Equality_Operator();
        Equality_Operator cls3 = cls1;
        System.out.printf("%b, %b %n", cls1 == cls2, cls1 == cls3);
    }
}
