/* Java_Collection.java
Author: BSS9395
Update: 2023-01-18T21:57:00+08@China-Shanghai+08
Design: Java Standard Library: Collection
*/

import java.util.*;
import java.util.stream.Collectors;

public class Java_Collection {
    static public void main(String[] args) {
        // _ArrayList();
        // _HashSet();
        // _forEach();
        // _iterator();
        // _remove();
        // _removeIf();
        _stream();
    }
    static public void _ArrayList() {
        ArrayList<String> langs = new ArrayList<String>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");
        langs.remove("C#");
        System.out.println(langs);
        System.out.println(langs.contains("Python"));
    }
    static public void _HashSet() {
        HashSet<String> langs = new HashSet<>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");
        System.out.print(langs);
    }
    static public void _forEach() {
        HashSet<String> langs = new HashSet<>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");
        langs.forEach((elem) -> {
            System.out.println(elem);
        });
    }
    static public void _iterator() {
        HashSet<String> langs = new HashSet<>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");
        Iterator<String> iter = langs.iterator();
        while(iter.hasNext() == true) {
            String lang = iter.next();
            System.out.println(lang);
            if(lang.equals("C#") == true) {
                iter.remove();
            }
            lang = "Matlab";
        }
        System.out.println(langs);
    }
    static public void _remove() {
        HashSet<String> langs = new HashSet<>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");
        try {
            Iterator<String> iter = langs.iterator();
            while(iter.hasNext() == true) {
                String lang = iter.next();
                System.out.println(lang);
                if(lang.equals("C#") == true) {
                    langs.remove(lang);
                }
            }
        } catch (ConcurrentModificationException exception) {
            exception.printStackTrace();
        }
        System.out.println(langs);
    }
    static public void _removeIf() {
        HashSet<String> langs = new HashSet<>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");
        langs.removeIf((elem) -> {
            return (elem == "C#");
        });
        System.out.println(langs);
    }
    static public void _stream() {
        HashSet<String> langs = new HashSet<>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");
//        System.out.println(langs.stream().filter((elem) -> {
//            return (elem.contains("C"));
//        }).count());
        langs.stream().mapToInt((elem) -> {
            return (elem.length());
        }).forEach(System.out::println);
    }
}
