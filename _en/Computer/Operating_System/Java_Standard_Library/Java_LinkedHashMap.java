/* Java_LinkedHashMap.java
Author: BSS9395
Update: 2023-01-22T21:02:00+08@China-Shanghai+08
Design: Java Standard Library: LinkedHashMap
*/

import java.util.LinkedHashMap;

public class Java_LinkedHashMap {
    static public void main(String[] args) {
        _LinkedHashMap();
    }
    static public void _LinkedHashMap() {
        LinkedHashMap<String, Integer> langs = new LinkedHashMap<String, Integer>();
        langs.put("C", 90);
        langs.put("C++", 80);
        langs.put("C#", 60);
        langs.put("Java", 70);
        langs.put("Python", 70);
        System.out.println(langs);

        langs.forEach((key, value) -> {
            System.out.printf("%s: %s %n", key, value);
            return ;
        });
    }
}
