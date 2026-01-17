/* Java_MethodHandle.java
Author: BSS9395
Update: 2023-01-14T19:22:00+08
Design: Java Standard Library: MethodHandle
*/

import java.lang.invoke.MethodHandle;
import java.lang.invoke.MethodHandles;
import java.lang.invoke.MethodType;
import java.lang.reflect.Method;

public class Java_MethodHandle {
    static public void main(String[] args)
            throws Throwable {
        MethodHandle lookup = MethodHandles.lookup().findStatic(Java_MethodHandle.class, "_Hello", MethodType.methodType(void.class));
        lookup.invoke();

        lookup = MethodHandles.lookup().findVirtual(Java_MethodHandle.class, "_Hello", MethodType.methodType(String.class, String.class));
        String string = (String)lookup.invoke(new Java_MethodHandle(), "World");
        System.out.println(string);
    }
    static private void _Hello() {
        System.out.println("Hello World!");
    }
    private String _Hello(String name) {
        String string = "Hello " + name + "!";
        System.out.println(string);
        return string;
    }
}
