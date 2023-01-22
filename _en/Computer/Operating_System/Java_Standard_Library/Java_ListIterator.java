/* Java_ListIterator.java
Author: BSS9395
Update: 2023-01-22T16:03:00+08@China-Shanghai+08
Design: Java Standard Library: ListIterator
*/

import java.util.ArrayList;
import java.util.ListIterator;

public class Java_ListIterator {
    static public void main(String[] args) {
        _ListIterator();
    }
    static public void _ListIterator() {
        ArrayList<String> langs = new ArrayList<String>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");

        ListIterator<String> iter = langs.listIterator();
        while(iter.hasNext() == true) {
            iter.add("----------------------------------------");
            System.out.println(iter.next());
        }
        System.out.println();
        while(iter.hasPrevious() == true) {
            System.out.println(iter.previous());
        }
    }
}
