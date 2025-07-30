/* Java_length.java
Author: bss9395
Update: 2025-07-24T11:04:00+08@China-GuangDong-ZhanJiang+08
*/

import java.lang.String;

public class Java_length {
    public static void main(String[] args) {
        // _Test_Array_length();
        _Test_String_length();
    }

    public static void _Test_Array_length() {
        String str = "abcdefg";
        for(int i = 0; i < str.length(); i += 1) {
            System.out.printf("%c", str.charAt(i));
        }
        System.out.println();
    }

    public static void _Test_String_length() {
        char[] arr = new char[] {
            'a', 'b', 'c', 'd'
        };
        for(int i = 0; i < arr.length; i += 1) {
            System.out.printf("%c", arr[i]);
        }
        System.out.println();
    }
}
