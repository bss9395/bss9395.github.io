/* Java_VarHandle.java
Author: BSS9395
Update: 2023-01-14T19:21:00+08@China-Shanghai+08
Design: Java Standard Library: VarHandle
*/

import java.lang.invoke.MethodHandles;
import java.lang.invoke.VarHandle;
import java.util.Arrays;

public class Java_VarHandle {
    static class Datum {
        static private double _id = 1.0;
        private String _name = "abc";
    }
    static public void main(String[] args)
            throws NoSuchFieldException, IllegalAccessException {
        // _arrayElementVarHandle();
        // _findVarHandle();
        _findStaticVarHandle();
    }
    static public void _arrayElementVarHandle() {
        String[] array = new String[] {
                "C", "C++", "C#", "Java", "Python"
        };
        VarHandle handles = MethodHandles.arrayElementVarHandle(String[].class);
        boolean bool = handles.compareAndSet(array, 2, "C#", "Matlab");
        System.out.println(bool);
        System.out.println(Arrays.toString(array));

        System.out.println(handles.get(array, 1));
        System.out.println(handles.getAndSet(array, 2, "Swift"));
        System.out.println(Arrays.toString(array));
    }
    static public void _findVarHandle()
            throws NoSuchFieldException, IllegalAccessException {
        VarHandle handle = MethodHandles.lookup().findVarHandle(Datum.class, "_name", String.class);
        Datum datum = new Datum();
        System.out.println(handle.get(datum));
        handle.set(datum, "bss9395");
        System.out.println(datum._name);
    }
    static public void _findStaticVarHandle()
            throws NoSuchFieldException, IllegalAccessException {
        VarHandle handle = MethodHandles.lookup().findStaticVarHandle(Datum.class, "_id", double.class);
        System.out.println(handle.get());
        handle.set(123.456);
        System.out.println(Datum._id);
    }
}
