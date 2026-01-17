/* Java_TreeMap.java
Author: BSS9395
Update: 2023-01-28T21:51:00+08@China-Shanghai+08
Design: Java Standard Library: TreeMap
*/

import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

public class Java_TreeMap {
    static class Datum implements Comparable<Datum> {
        String _id = "";
        public Datum(String id) {
            _id = id;
        }

        @Override
        public int hashCode() {
            System.out.println("public int hashCode() {");
            return super.hashCode();
        }

        @Override
        public int compareTo(Datum datum) {
            // System.out.printf("_id=%s, Datum.compareTo(); %n", _id);
            if(this == datum) {
                return 0;
            }
            return _id.compareTo(datum._id);
        }
        @Override
        public boolean equals(Object object) {
            if(this == object) {
                return true;
            }
            if(object != null && object.getClass() == Datum.class) {
                return (compareTo((Datum)object) == 0);
            }
            return false;
        }
        public String toString() {
            return String.format("Java_Tree$Datum@%s", _id);
        }
    }

    static class Derived extends Datum {
        public String _id = "";
        public Derived(String id) {
            super(id);
        }

        @Override
        public int compareTo(Datum datum) {
            // System.out.println("Type.compareTo();");
            return super.compareTo(datum);
        }
    }

    static public void main(String[] args) {
        // _TreeMap();
        // _Iterator();
        _foreach();
    }

    static public void _TreeMap() {
        TreeMap<Datum, String> map = new TreeMap<Datum, String>();
        map.put(new Datum("1156"), "BSS9395");
        map.put(new Datum("1157"), "Maker");
        map.put(new Datum("1158"), "Brilliant");
        map.put(new Datum("1159"), "Emperor");
        map.put(new Derived("1160"), "BSS9395");
        System.out.println(map);

        System.out.println(map.firstEntry());
        System.out.println(map.lastEntry());
        System.out.println(map.higherEntry(new Datum("1157")));
        System.out.println(map.lowerEntry(new Datum("1157")));
        System.out.println(map.subMap(new Datum("1157"), new Datum("1159")));
    }

    static public void _Iterator() {
        TreeMap<Datum, String> map = new TreeMap<Datum, String>();
        map.put(new Datum("1156"), "BSS9395");
        map.put(new Datum("1157"), "Maker");
        map.put(new Datum("1158"), "Brilliant");
        map.put(new Datum("1159"), "Emperor");
        map.put(new Derived("1160"), "BSS9395");
        System.out.println(map);

        Set<Map.Entry<Datum, String>> set = map.entrySet();
        Iterator<Map.Entry<Datum, String>> iterator = set.iterator();
        while(iterator.hasNext()) {
            Map.Entry<Datum, String> entry = iterator.next();
            System.out.println(entry.getKey() + " = " + entry.getValue());
        }
    }

    static public void _foreach() {
        TreeMap<Datum, String> map = new TreeMap<Datum, String>();
        map.put(new Datum("1156"), "BSS9395");
        map.put(new Datum("1157"), "Maker");
        map.put(new Datum("1158"), "Brilliant");
        map.put(new Datum("1159"), "Emperor");
        map.put(new Derived("1160"), "BSS9395");
        System.out.println(map);

        for(Map.Entry<Datum, String> entry: map.entrySet()) {
            System.out.println(entry.getKey() + " = " + entry.getValue());
        }
    }
}
