/* Java_TreeSet.java
Author: BSS9395
Update: 2023-01-22T14:32:00+08@China-Shanghai+08
Design: Java Standard Library: TreeSet
*/

import com.sun.source.util.Trees;

import java.util.TreeSet;

public class Java_TreeSet {
    static class Datum implements Comparable<Datum> {
        String _id = "";
        public Datum(String id) {
            _id = id;
        }
        @Override
        public int compareTo(Datum datum) {
            return _id.compareTo(datum._id);
        }
        @Override
        public boolean equals(Object datum) {
            if(this == datum) {
                return true;
            }
            if(datum != null && datum.getClass() == Datum.class) {
                return (0 == compareTo((Datum)datum));
            }
            return false;
        }
        @Override
        public String toString() {
            return String.format("%d@%s", super.hashCode(), _id);
        }
    }
    static public void main(String[] args) {
        // _TreeSet();
        // _compareTo();
        _comparator();
    }
    static public void _TreeSet() {
        TreeSet<String> langs = new TreeSet<String>();
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        langs.add("Java");
        langs.add("Python");
        System.out.println(langs);

        System.out.println(langs.first());
        System.out.println(langs.last());
        System.out.println(langs.headSet("C++"));
        System.out.println(langs.tailSet("C++"));
        System.out.println(langs.subSet("C#", "Java"));
    }
    static public void _compareTo() {
        Datum datum = new Datum("1156");
        TreeSet<Datum> set = new TreeSet<Datum>();
        set.add(datum);
        System.out.println(set.add(datum));
        System.out.println(set);

        System.out.println(set.first()._id);
        System.out.println(set.last()._id);
    }
    static public void _comparator() {
        TreeSet<Datum> langs = new TreeSet<Datum>((lhs, rhs) -> {
            if(lhs == null || rhs == null) {
                throw new NullPointerException();
            }
            if(lhs == rhs) {
                return 0;
            }
            return (((Datum)lhs)._id.compareTo(((Datum)rhs)._id));
        });
        langs.add(new Datum("C"));
        langs.add(new Datum("C++"));
        langs.add(new Datum("C#"));
        langs.add(new Datum("Java"));
        langs.add(new Datum("Python"));
        System.out.println(langs);
    }
}
