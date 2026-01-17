/* Java_Collections.java
Author: BSS9395
Update: 2023-01-29T14:54:00+08@China-Shanghai+08
Design: Java Standard Library: Collections
*/

import java.util.*;

public class Java_Collections {
    static public void main(String[] args) {
        // _reverse_sort_shuffle();
        // _max_min_frequency_replaceAll();
        _synchronized();
    }
    static public void _reverse_sort_shuffle() {
        ArrayList<String> langs = new ArrayList<String>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");
        System.out.println(langs);

        Collections.reverse(langs);
        System.out.println(langs);

        Collections.sort(langs);
        System.out.println(langs);

        System.out.println(Collections.binarySearch(langs, "C#"));

        Collections.shuffle(langs);
        System.out.println(langs);
    }
    static public void _max_min_frequency_replaceAll() {
        ArrayList<String> langs = new ArrayList<String>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");
        System.out.println(langs);

        System.out.println(Collections.max(langs));
        System.out.println(Collections.min(langs));
        System.out.println(Collections.frequency(langs, "C#"));

        Collections.replaceAll(langs, "C#", "Matlab");
        System.out.println(langs);
    }
    static public void _synchronized() {
        Collection<String> collection = Collections.synchronizedCollection(new ArrayList<String>());
        List<String> list = Collections.synchronizedList(new ArrayList<String>());
        Set<String> set = Collections.synchronizedSet(new HashSet<String>());
        Map<String, String> map = Collections.synchronizedMap(new HashMap<String, String>());
    }
}
