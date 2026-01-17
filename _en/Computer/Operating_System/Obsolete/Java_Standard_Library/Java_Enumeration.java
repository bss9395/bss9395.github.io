/* Java_Enumeration.java
Author: BSS9395
Update: 2023-01-29T15:41:00+08@China-Shanghai+08
Design: Java Standard Library: Enumeration
*/

import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Vector;

public class Java_Enumeration {
    static public void main(String[] args) {
        _Enumeration();
    }
    static public void _Enumeration() {
        Vector<String> vector = new Vector<String>();
        vector.add("C");
        vector.add("C++");
        vector.add("C#");
        vector.add("Java");
        vector.add("Python");
        System.out.println(vector);

        Enumeration<String> iter = vector.elements();
        while(iter.hasMoreElements() == true) {
            System.out.println(iter.nextElement());
        }


        Hashtable<String, Integer> table = new Hashtable<String, Integer>();
        table.put("C", 90);
        table.put("C++", 80);
        table.put("C#", 60);
        table.put("Java", 70);
        table.put("Python", 70);
        System.out.println(table);

        Enumeration<String> keys = table.keys();
        while(keys.hasMoreElements() == true) {
            String key = keys.nextElement();
            System.out.printf("%s: %s %n", key, table.get(key));
        }
    }
}
