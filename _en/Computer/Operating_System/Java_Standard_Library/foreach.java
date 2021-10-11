/* foreach.java
Author: BSS9395
Update: 2021-10-10T21:31:00+08@China-Guangdong-Shenzhen+08
Design: Java foreach Loop
*/

public class foreach {
    public static void main(String[] args) {
        String[] strings = new String[]{
                "Java SE",
                "Java EE",
                "Java ME"
        };

        for (String string : strings) {
            string = "Java";                 // Original value will not change.
            System.out.println(string);
        }

        System.out.println("========================================");
        for (int i = 0; i < strings.length; i += 1) {
            System.out.println(strings[i]);
            strings[i] = "Java";            // Original value will change.
        }

        System.out.println("========================================");
        for (var string : strings) {
            System.out.println(string);
        }
    }
}
