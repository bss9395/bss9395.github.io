/* Java_Division_Operator.java
Author: BSS9395
Update: 2021-10-07T18:20:00+08@China-Guangdong-Shenzhen+08
Design: Java Division Operator
*/

public class Java_Division_Operator {
    public static void main(String[] args) {
        int int_lhs = 5;
        int int_rhs = 3;
        int int_quot = int_lhs / int_rhs;
        int int_mod = int_lhs % int_rhs;
        // int positive_infinity = +2 / 0;  // Exception
        // int negative_infinity = -2 / 0;  // Exception
        // int nan_quot = 0 / 0;            // Exception
        // int nan_mod = 2 % 0;             // Exception
        System.out.printf("%d, %d %n", int_quot, int_mod);

        ////////////////////////////////
        System.out.println("========================================");
        double double_lhs = 5.4;
        double double_rhs = 3.2;
        double double_quot = double_lhs / double_rhs;
        double double_mod = double_lhs % double_rhs;
        double positive_infinity = +2.0 / 0.0;
        double negative_infinity = -2.0 / 0.0;
        double nan_quot = 0.0 / 0.0;
        double nan_mod = 2.0 % 0.0;
        System.out.printf("%f, %f %n", double_quot, double_mod);
        System.out.printf("%f, %f, %f, %f %n", positive_infinity, negative_infinity, nan_quot, nan_mod);
    }
}
