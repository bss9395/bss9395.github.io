/* Java_LinkedList.java
Author: BSS9395
Update: 2023-01-22T19:37:00+08@China-Shanghai+08
Design: Java Standard Library: LinkedList
*/

import java.util.LinkedList;

public class Java_LinkedList {
    static public void main(String[] args) {
        _LinkedList();
    }
    static public void _LinkedList() {
        LinkedList<String> langs = new LinkedList<String>();
        langs.addFirst("C");
        langs.addLast("C++");
        langs.addLast("C#");
        langs.addLast("Java");
        langs.addLast("Python");
        System.out.println(langs);

        System.out.println(langs.peekFirst());
        System.out.println(langs.peekLast());
        System.out.println(langs);

        System.out.println(langs.pollFirst());
        System.out.println(langs.pollLast());
        System.out.println(langs);
    }
}
