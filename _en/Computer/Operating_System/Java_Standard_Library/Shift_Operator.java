/* Shift_Operator.java
Author: BSS9395
Update: 2021-10-08T17:01:00+08@China-Guangdong-Shenzhen+08
Design: Java Shift Operator
*/

public class Shift_Operator {
    public static void main(String[] args) {
        int int_value = 5;
        int int_right = int_value >> 33;
        int int_right_shift = int_value >> (33 % 32);
        int int_left = int_value << 33;
        int int_left_shift = int_value << (33 % 32);
        System.out.printf("%d, %d %n", int_right, int_right_shift);
        System.out.printf("%d, %d %n", int_left, int_left_shift);

        ////////////////////////////////
        System.out.println("========================================");
        long long_value = 5;
        long long_right = long_value >> 65;
        long long_right_shift = long_value >> (65 % 64);
        long long_left = long_value << 65;
        long long_left_shift = long_value << (65 % 64);
        System.out.printf("%d, %d %n", long_right, long_right_shift);
        System.out.printf("%d, %d %n", long_left, long_left_shift);

        ////////////////////////////////
        System.out.println("========================================");
        int value = -5;
        int right_shift = value >>> 2;
        int right = 0b00111111111111111111111111111110;
        System.out.printf("%d, %d %n", right_shift, right);
    }
}
