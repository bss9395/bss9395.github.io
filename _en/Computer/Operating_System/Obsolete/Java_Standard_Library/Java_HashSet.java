/* Java_HashSet.java
Author: BSS9395
Update: 2023-01-20T13:34:00+08@China-Shanghai+08
Design: Java Standard Library: HashSet
*/

import java.util.HashSet;

public class Java_HashSet {
    static class A {
        public int hashCode() {
            return 1;
        }
    }
    static class B {
        public boolean equals(Object object) {
            return true;
        }
    }
    static class C {
        public int hashCode() {
            return 2;
        }
        public boolean equals(Object object) {
            return true;
        }
    }
    static class Datum {
        int _count = 0;
        public Datum(int count) {
            _count = count;
        }
        public int hashCode() {
            return _count;
        }
        public boolean equals(Object datum) {
            if(this == datum) {
                return true;
            }
            if(null != datum && datum.getClass() == Datum.class) {
                return _count == ((Datum)datum)._count;
            }
            return false;
        }
        public String toString() {
            return String.format("@%s#%d", Integer.toHexString(super.hashCode()), _count);
        }
    }
    static public void main(String[] args) {
        // _HashSet();
        _hashCode();
    }
    static public void _HashSet() {
        HashSet set = new HashSet();
        set.add(new A());
        set.add(new A());
        set.add(new B());
        set.add(new B());
        set.add(new C());
        set.add(new C());
        System.out.println(set);
    }
    static public void _hashCode() {
        HashSet<Datum> set = new HashSet<Datum>();
        set.add(new Datum(5));
        set.add(new Datum(-3));
        set.add(new Datum(9));
        set.add(new Datum(-2));
        System.out.println(set);

        Datum first = set.iterator().next();
        first._count = -3;
        System.out.println(set);

        set.remove(new Datum(-3));
        System.out.println(set);
    }
}
