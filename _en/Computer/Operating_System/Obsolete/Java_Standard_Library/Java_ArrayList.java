/* Java_ArrayList.java
Author: BSS9395
Update: 2023-01-22T15:50:00+08@China-Shanghai+08
Design: Java Standard Library: ArrayList
*/

import java.util.ArrayList;
import java.util.List;

public class Java_ArrayList {
    static public void main(String[] args) {
        // _ArrayList();
        // _sort();
        _replaceAll();
    }
    static public void _ArrayList() {
        ArrayList<String> langs = new ArrayList<String>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");
        System.out.println(langs);
        System.out.println(langs.indexOf("Java"));

        langs.set(2, "Matlab");
        System.out.println(langs);

        langs.remove("Matlab");
        System.out.println(langs);

        List<String> sub = langs.subList(2, 4);
        System.out.println(sub);
    }
    static public void _sort() {
        ArrayList<String> langs = new ArrayList<String>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");

        langs.sort((lhs, rhs) -> {
            return (((String)lhs).length() - ((String)rhs).length());
        });
        System.out.println(langs);
    }
    static public void _replaceAll() {
        ArrayList<String> langs = new ArrayList<String>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");

        langs.replaceAll((elem) -> {
            return String.valueOf(((String)elem).length());
        });
        System.out.println(langs);
    }
}
