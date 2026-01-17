/* Java_Contravariance.java
Author: BSS9395
Update: 2023-01-29T20:38:00+08@China-Shanghai+08
Design: Java Language Feature: Contravariance
*/

import com.sun.source.util.Trees;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.TreeSet;

public class Java_Contravariance {
    static public <Type> Type _Copy(List<? super Type> dest, List<Type> sour) {
        Type last = null;
        for(var elem : sour) {
            last = elem;
            dest.add(elem);
        }
        return last;
    }
    static public void main(String[] args) {
        // _Contravariance();
        _Comparator();
    }
    static public void _Contravariance() {
        ArrayList<Number> numbers = new ArrayList<Number>();
        ArrayList<Integer> integers = new ArrayList<Integer>();
        integers.add(2);
        integers.add(3);
        integers.add(5);
        integers.add(7);

        Integer last = _Copy(numbers, integers);
        System.out.println(last);
        System.out.println(numbers);
    }
    static public void _Comparator() {
        TreeSet<String> tree_0 = new TreeSet<String>(new Comparator<Object>() {
            @Override
            public int compare(Object lhs, Object rhs) {
                return (lhs.hashCode() - rhs.hashCode());
            }
        });
        tree_0.add("C");
        tree_0.add("C++");
        tree_0.add("C#");
        tree_0.add("Java");
        tree_0.add("Python");
        System.out.println(tree_0);


        TreeSet<String> tree_1 = new TreeSet<String>(new Comparator<String>() {
            @Override
            public int compare(String lhs, String rhs) {
                return (lhs.length() - rhs.length());
            }
        });
        tree_1.add("C");
        tree_1.add("C++");
        tree_1.add("C#");
        tree_1.add("Java");
        tree_1.add("Python");
        System.out.println(tree_1);
    }
}
