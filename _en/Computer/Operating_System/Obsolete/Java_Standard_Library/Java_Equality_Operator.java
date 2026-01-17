/* Java_Equality_Operator.java
Author: BSS9395
Update: 2021-10-08T17:01:00+08@China-Guangdong-Shenzhen+08
Design: Java Equality Operator
*/

public class Java_Equality_Operator {
    public static void main(String[] args) {
        String str1 = "Hello";
        String str2 = "Hello";
        String str3 = "He" + "llo";
        System.out.printf("%b, %b %n", str1 == str2, str1 == str3);

        ////////////////////////////////
        System.out.println("========================================");
        Java_Equality_Operator cls1 = new Java_Equality_Operator();
        Java_Equality_Operator cls2 = new Java_Equality_Operator();
        Java_Equality_Operator cls3 = cls1;
        System.out.printf("%b, %b %n", cls1 == cls2, cls1 == cls3);
    }
}
