/* Java_StringBuilder.java
Author: BSS9395
Update: 2023-01-10T22:48:00+08@China-Shanghai+08
Design: Java Standard Library: StringBuilder
*/

public class Java_StringBuilder {
    static public void main(String[] args) {
        StringBuilder str = new StringBuilder();

        str.append("Java");
        System.out.println(str);

        str.insert(0, "Hello ");
        System.out.println(str);

        str.replace(5, 6, ",");
        System.out.println(str);

        str.delete(5, 6);
        System.out.println(str);

        str.reverse();
        System.out.println(str);
        System.out.println(str.length());
        System.out.println(str.capacity());

        str.setLength(4);
        System.out.println(str);
    }

}
