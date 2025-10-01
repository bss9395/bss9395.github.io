/* Java_HashMap.java
Author: BSS9395
Update: 2022-01-22T20:06:00+08@China-Shanghai+08
Design: Java Standard Library: HashMap
*/

import java.util.HashMap;

public class Java_HashMap {
    static class Datum {

    }
    static public void main(String[] args) {
        // _HashMap();
        // _merge_computeIfAbsent_computeIfPresent();
        _null();
    }
    static public void _HashMap() {
        HashMap<String, Integer> langs = new HashMap<String, Integer>();
        langs.put("C", 90);
        langs.put("C++", 80);
        langs.put("C#", 60);
        langs.put("Java", 70);
        langs.put("Python", 70);
        System.out.println(langs);

        System.out.println(langs.containsKey("C#"));
        System.out.println(langs.containsValue(60));

        System.out.println(langs.entrySet());
        System.out.println(langs.keySet());
        System.out.println(langs.values());

        System.out.println(langs.put("C#", 50));
        System.out.println(langs);
    }
    static public void _merge_computeIfAbsent_computeIfPresent() {
        HashMap<String, Integer> langs = new HashMap<String, Integer>();
        langs.put("C", 90);
        langs.put("C++", 80);
        langs.put("C#", 60);
        langs.put("Java", 70);
        langs.put("Python", 70);
        System.out.println(langs);

        langs.merge("C#", -10, (value, param) -> {
            return value + param;
        });
        System.out.println(langs);

        langs.computeIfAbsent("Matlab", (key) -> {
            return ((String)key).length();
        });
        System.out.println(langs);

        langs.computeIfPresent("Matlab", (key, value) -> {
            return (value * 2);
        });
        System.out.println(langs);
    }
    static public void _null() {
        HashMap<String, Integer> langs = new HashMap<String, Integer>();
        langs.put("C", 90);
        langs.put("C++", 80);
        langs.put("C#", 60);
        langs.put("Java", 70);
        langs.put("Python", 70);
        System.out.println(langs);

        langs.put(null, null);  // 不存储
        langs.put(null, 100);
        langs.put("Matlab", null);
        System.out.println(langs);
    }

}
