/* Java_String.java
Author: BSS9395
Update: 2023-01-10T22:42:00+08@China-Shanghai+08
Design: Java Standard Library: String
*/

public class Java_String {
    static public void main(String[] args) {
        // _charAt();
        // _compareTo();
        // _startsWith_endsWith();
        // _getChars();
        // _indexOf();
        _toLowerCase_toUpperCase();
    }
    static public void _charAt() {
        String str_0 = "bss9395.github.io";
        System.out.println(str_0.charAt(5));
    }
    static public void _compareTo() {
        String str_0 = "bss9395.github.io";
        String str_1 = "bss9395";
        String str_2 = "bss9395/github/io";
        System.out.println(str_0.compareTo(str_1));
        System.out.println(str_0.compareTo(str_2));
    }
    static public void _startsWith_endsWith() {
        String str_0 = "bss9395.github.io";
        String str_1 = "bss";
        String str_2 = ".io";
        System.out.println(str_0.startsWith(str_1));
        System.out.println(str_0.endsWith(str_2));
    }
    static public void _getChars() {
        char[] arr_0 = {
            'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'
        };
        String str_0 = "Java";
        str_0.getChars(0, 4, arr_0, 6);
        System.out.println(arr_0);
    }
    static public void _indexOf() {
        String str_0 = "bss9395.github.io";
        String str_1 = "git";
        System.out.println(str_0.indexOf(str_1));
    }
    static public void _toLowerCase_toUpperCase() {
        String str_0 = "BSS9395.github.io";
        System.out.println(str_0.toLowerCase());
        System.out.println(str_0.toUpperCase());
    }
}
