/* Java_BigInteger.java
Author: bss9395
Update: 2025-08-05T11:48:00+08@China-GuangDong-ZhanJiang+08
*/

import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Arrays;

public class Java_BigInteger {
    public static void main(String[] args) {
        _Test_BigInteger();
        System.out.println("--------------------------------------------------------------------------------");
        // _Test_BigDecimal();
    }
    public static void _Test_BigInteger() {
        BigInteger bigA = new BigInteger("345345345345");
        BigInteger bigB = new BigInteger("123123123123");
        System.out.println("[加法]" + bigA.add(bigB));
        System.out.println("[减法]" + bigA.subtract(bigB));
        System.out.println("[乘法]" + bigA.multiply(bigB));
        System.out.println("[除法]" + bigA.divide(bigB));
        System.out.println("[幂法]" + bigA.pow(234234));
        System.out.println("[模法]" + Arrays.toString(bigA.divideAndRemainder(bigB)));
    }
    public static void _Test_BigDecimal() {
        BigDecimal bigA = new BigDecimal("345345345345.345345345345");
        BigDecimal bigB = new BigDecimal("123123123123.123123123123");
        System.out.println("[加法]" + bigA.add(bigB));
        System.out.println("[减法]" + bigA.subtract(bigB));
        System.out.println("[乘法]" + bigA.multiply(bigB));
        // System.out.println("[除法]" + bigA.divide(bigB));  // 除法运算抛出异常
        System.out.println("[幂法]" + bigA.pow(234234));
        System.out.println("[模法]" + Arrays.toString(bigA.divideAndRemainder(bigB)));
        System.out.println("[舍入]" + round(234234234234.234234234234, 5));
    }

    public static double round(double number, int scale) {
        return new BigDecimal(number).divide(new BigDecimal(1.0), scale, RoundingMode.FLOOR).doubleValue();
    }
}