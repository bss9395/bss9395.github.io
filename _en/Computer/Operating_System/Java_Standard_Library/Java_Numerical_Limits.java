/* Java_Numerical_Limits.java
Author: BSS9395
Update: 2021-10-07T15:23:00+08@China-Guangdong-ShenZhen+08
Design: Java Type Numerical Limits
*/

public class Java_Numerical_Limits {
    public static void main(String[] args) {
        double double_min = Double.MIN_VALUE;
        double double_max = Double.MAX_VALUE;
        double negative_infinity = Double.NEGATIVE_INFINITY;
        double positive_infinity = Double.POSITIVE_INFINITY;
        double nan = Double.NaN;
        System.out.printf("%f, %e %n", double_min, double_max);
        System.out.printf("%f, %f, %f %n", negative_infinity, positive_infinity, nan);
        System.out.printf("%b, %b, %b %n", double_max < positive_infinity, positive_infinity == Float.POSITIVE_INFINITY, nan == nan);
    }
}
