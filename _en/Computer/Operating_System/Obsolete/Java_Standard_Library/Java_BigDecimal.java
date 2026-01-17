/* Java_BigDecimal.java
Author: BSS9395
Update: 2023-01-12T21:06:00+08@China-Shanghai+08
Design: Java Standard Library: BigDecimal
*/

import java.math.BigDecimal;
import java.math.RoundingMode;

class Arithmetic {
    static private final int _precision = 10;
    static public double _Add(double lhs, double rhs) {
        return BigDecimal.valueOf(lhs).add(BigDecimal.valueOf(rhs)).doubleValue();
    }
    static public double _Subtract(double lhs, double rhs) {
        return BigDecimal.valueOf(lhs).subtract(BigDecimal.valueOf(rhs)).doubleValue();
    }
    static public double _Multiply(double lhs, double rhs) {
        return BigDecimal.valueOf(lhs).multiply(BigDecimal.valueOf(rhs)).doubleValue();
    }
    static public double _Divide(double lhs, double rhs) {
        return BigDecimal.valueOf(lhs).divide(BigDecimal.valueOf(rhs), _precision, RoundingMode.HALF_UP).doubleValue();
    }
    private Arithmetic() {}
}

public class Java_BigDecimal {
    static public void main(String[] args) {
        // _Double();
        // _BigDecimal();
        _Arithmetic();
    }
    static public void _Double() {
        System.out.println("0.05 + 0.01 = " + (0.05 + 0.01));
        System.out.println("1.0 - 0.42  = " + (1.0 - 0.42));
        System.out.println("4.015 * 100 = " + (4.015 * 100));
        System.out.println("123.3 / 100 = " + (123.3 / 100));
    }
    static public void _BigDecimal() {
        BigDecimal decimal_0 = new BigDecimal("0.05");
        BigDecimal decimal_1 = BigDecimal.valueOf(0.01);
        BigDecimal decimal_2 = new BigDecimal(0.05);

        System.out.println("0.05 + 0.01 = " + decimal_0.add(decimal_1));
        System.out.println("0.05 - 0.01 = " + decimal_0.subtract(decimal_1));
        System.out.println("0.05 * 0.01 = " + decimal_0.multiply(decimal_1));
        System.out.println("0.05 / 0.01 = " + decimal_0.divide(decimal_1));

        System.out.println("0.05 + 0.01 = " + decimal_2.add(decimal_1));
        System.out.println("0.05 - 0.01 = " + decimal_2.subtract(decimal_1));
        System.out.println("0.05 * 0.01 = " + decimal_2.multiply(decimal_1));
        System.out.println("0.05 / 0.01 = " + decimal_2.divide(decimal_1));
    }
    static public void _Arithmetic() {
        System.out.println("0.05 + 0.01 = " + Arithmetic._Add(0.05, 0.01));
        System.out.println("1.0 - 0.42  = " + Arithmetic._Subtract(1.0, 0.42));
        System.out.println("4.015 * 100 = " + Arithmetic._Multiply(4.015, 100));
        System.out.println("123.3 / 100 = " + Arithmetic._Divide(123.3, 100));
    }
}
