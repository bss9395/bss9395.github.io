/* Java_LinkedHashSet.java
Author: BSS9395
Update: 2023-01-21T23:03:00+08@China-Shanghai+08
Design: Java Standard Library: LinkedHashSet
*/

import java.util.LinkedHashSet;

public class Java_LinkedHashSet {
    static public void main(String[] args) {
        _LinkedHashSet();
    }
    static public void _LinkedHashSet() {
        LinkedHashSet<String> set = new LinkedHashSet<String>();
        set.add("C");
        set.add("C++");
        set.add("C#");
        set.add("Java");
        set.add("Python");
        System.out.println(set);

        set.remove("C#");
        System.out.println(set);
    }
}
