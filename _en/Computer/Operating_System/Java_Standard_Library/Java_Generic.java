/* Java_Generic.java
Author: BSS9395
Update: 2023-01-29T16:14:00+08@China-Shanghai+08
Design: Java Language Feature: Generic
*/

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;

public class Java_Generic<T> {
    interface Datum<Type> {
        void _Info(Type type);
    }
    static public <Type> void _Copy(Collection<Type> collection, Type[] array) {
        for(int i = 0; i < array.length; i += 1) {
            collection.add(array[i]);
        }
    }

    static public void main(String[] args) {
        // _Generic();
        // _getClass();
        // _Generic_Method();
        // _Generic_Constructor();
        _Generic_Static();
    }

    static public void _Generic() {
        Datum<String> datum_0 = new Datum<>() {
            @Override
            public void _Info(String text) {
                System.out.println(text);
            }
        };

        Datum<?> datum_1 = new Datum<>() {
            @Override
            public void _Info(Object object) {
                System.out.println(object);
            }
        };

        Datum<? extends Number> datum_2 = new Datum<>() {
            @Override
            public void _Info(Number number) {
                System.out.println(number);
            }
        };
    }
    static public void _getClass() {
        List<Integer> inte = new ArrayList<Integer>();
        List<String> stri = new ArrayList<String>();

        System.out.println(inte.getClass());
        System.out.println(stri.getClass());
        System.out.println(inte.getClass() == stri.getClass());
    }
    static public void _Generic_Method() {
        Object[] objects = new Object[100];
        String[] strings = new String[100];
        Collection<Object> collection_objects = new ArrayList<Object>();
        Collection<String> collection_strings = new ArrayList<String>();

        _Copy(collection_objects, objects);
        _Copy(collection_strings, strings);
        _Copy(collection_objects, strings);
    }
    static public void _Generic_Constructor() {
        Java_Generic<Integer> generic = new <String> Java_Generic<Integer>("Hello, World!");
    }
    static public void _Generic_Static() {
        Java_Generic<String> generic = Java_Generic.<String>_Func(Java_Generic.<String>_Null());
    }

    public <U> Java_Generic(U u) {
        System.out.println(u);
    }
    static public <U> Java_Generic<U> _Func(Java_Generic<U> para) {
        return null;
    }
    static public <U> Java_Generic<U> _Null() {
        return null;
    }
}
