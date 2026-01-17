/* Java_Objects.java
Author: BSS9395
Update: 2023-01-09T22:42:00+08@China-Shanghai+08
Design: Java Standard Library: Objects
*/

import java.util.Objects;

public class Java_Objects {
    static public void main(String[] args) {
        double value = 123.456;
        System.out.println(Objects.hashCode(value));
        System.out.println(Objects.toString(value));

        Java_Objects java = new Java_Objects();
        System.out.println(Objects.hashCode(java));
        System.out.println(Objects.toString(java));

        java = null;
        System.out.println(Objects.hashCode(java));
        System.out.println(Objects.toString(java));
    }
}
