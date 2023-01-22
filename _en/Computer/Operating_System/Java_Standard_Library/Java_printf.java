/* Java_printf.java
Author: BSS9395
Update: 2021-10-07T17:12:00+08@China-Guangdong-Shenzhen+08
Design: Java Standard Library printf
*/

public class Java_printf {
    public static void main(String[] args) {
        boolean b1 = true;
        boolean b2 = false;
        System.out.printf("%b, %b %n", b1, b2);

        ////////////////////////////////
        System.out.println("========================================");
        char c1 = '香';
        char c2 = '\u9999';
        char c3 = 0x9999;
        System.out.printf("%c, %c, %c %n", c1, (int) c2, c3);

        ////////////////////////////////
        System.out.println("========================================");
        byte b = (byte) 0b11110000;
        short s = (short) 020;
        int i = 0x10;
        long l = 922_3372_0368_5477_5807L;
        System.out.printf("%d, %d, %d, %d %n", b, s, i, l);

        ////////////////////////////////
        System.out.println("========================================");
        float f = 123.456F;
        double d = 123.456E3; // 123.456 × 10^3
        double pi = 3.14_15_92_65_36;
        System.out.printf("%f, %f, %.8f %n", f, d, pi);
    }
}
