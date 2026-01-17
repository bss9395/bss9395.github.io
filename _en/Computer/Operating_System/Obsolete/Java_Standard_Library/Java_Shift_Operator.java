/* Java_Shift_Operator.java
Author: bss9395
Update: 2025-07-16T17:50:00+08@China-ShangHai+08
Design: Java Shift Operator
*/

public class Java_Shift_Operator {
    public static void _Test_ToBinaryString() {
        int shift = -1;
        System.out.println(shift + ", " + Integer.toBinaryString(shift));
        int shiftL = (shift << 2);      // shift * 4
        System.out.println(shiftL + ", " + _ToBinaryString(shiftL));
        int shiftR = (shift >> 2);      // wrong result
        System.out.println(shiftR + ", " + _ToBinaryString(shiftR));
        int shiftUR = (shift >>> 2);    // wrong result
        System.out.println(shiftUR + ", " + _ToBinaryString(shiftUR));
    }

    public static void _Test_ToHexadecimalString() {
        int shift = -1;
        System.out.println(shift + ", " + Integer.toHexString(shift));
        int shiftL = (shift << 2);      // shift * 4
        System.out.println(shiftL + ", " + _ToHexadecimalString(shiftL));
        int shiftR = (shift >> 2);      // wrong result
        System.out.println(shiftR + ", " + _ToHexadecimalString(shiftR));
        int shiftUR = (shift >>> 2);    // wrong result
        System.out.println(shiftUR + ", " + _ToHexadecimalString(shiftUR));
    }

    public static void main(String[] args) {
        _Test_ToBinaryString();
        // _Test_ToHexadecimalString();
    }

    public static String _ToBinaryString(int value) {
        String characters = "01";
        StringBuilder binary = new StringBuilder();
        int bits = Integer.BYTES * 8;
        for (int bit = 0; bit < bits; bit += 1) {
            binary.append(characters.charAt((value >> bit) & 0x01));
        }
        binary.reverse();
        return binary.toString();
    }

    public static String _ToHexadecimalString(int value) {
        String characters = "0123456789ABCDEF";
        StringBuilder hexadecimal = new StringBuilder();
        int bits = Integer.BYTES * 8;
        for(int nibble = 0; nibble < (bits / 4); nibble += 1) {
            hexadecimal.append(characters.charAt((value >> (nibble * 4)) & 0x0F));
        }
        hexadecimal.reverse();
        return hexadecimal.toString();
    }
}
