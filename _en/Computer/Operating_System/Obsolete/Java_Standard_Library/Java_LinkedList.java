/* Java_LinkedList.java
Author: BSS9395
Update: 2023-01-22T19:37:00+08@China-Shanghai+08
Design: Java Standard Library: LinkedList
*/

import java.util.LinkedList;
import java.util.ListIterator;

public class Java_LinkedList {
    static public void main(String[] args) {
        // _LinkedList();
        _ListIterator();
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
    static public void _ListIterator() {
        LinkedList<String> langs = new LinkedList<String>();
        langs.addFirst("C");
        langs.addLast("C++");
        langs.addLast("C#");
        langs.addLast("Java");
        langs.addLast("Python");
        System.out.println(langs);

        ListIterator<String> iterator = langs.listIterator();
        while(iterator.hasNext()) {
            System.out.print(iterator.next() + ", ");
        }
        System.out.println();
        while(iterator.hasPrevious()) {
            System.out.print(iterator.previous() + ", ");
        }
        System.out.println();
    }
}
