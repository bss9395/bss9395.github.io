/* To_Binary_String.java
Author: BSS9395
Update: 2022-12-26T17:28:00+08@China-Shanghai+08
Design: Interger to Binary String
*/

public class To_Binary_String {
    public static void main(String[] args) {
        // int bin = -2;
        int bin = 0b10000000000000000000000000000010;
        System.out.println(Integer.toBinaryString(bin));
        System.out.println(_To_Binary_String(bin));
    }

    public static String _To_Binary_String(int value) {
        StringBuilder str = new StringBuilder();
        for (int i = 31; 0 <= i; i -= 1) {
            str.append(((value >>> i) & 0x01) == 0 ? '0' : '1');
        }
        return str.toString();
    }
}
