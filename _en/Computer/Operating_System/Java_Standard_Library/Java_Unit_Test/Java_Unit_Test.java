/* Java_Unit_Test.java
Author: BSS9395
Update: 2023-02-05T17:01:00+08@China-Shanghai+08
Design: Java Unit Test
*/

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import java.lang.reflect.Method;

public class Java_Unit_Test {
    @Retention(RetentionPolicy.RUNTIME)
    @Target(ElementType.METHOD)
    public @interface Testable {

    }

    static public class Unit_Test {
        static public void _Func_0() {

        }
        static public void _Func_1() {
            throw new RuntimeException("static public void _Func_1() {");
        }
        @Testable
        static public void _Func_2() {

        }
        @Testable
        static public void _Func_3() {
            throw new RuntimeException("static public void _Func_3() {");
        }
    }

    static public void main(String[] args)
        throws ClassNotFoundException {
        _Unit_Test();
    }
    static public void _Unit_Test()
        throws ClassNotFoundException {
        int passed = 0;
        int failed = 0;
        for(Method method : Class.forName("Java_Unit_Test$Unit_Test").getMethods()) {
            if(method.isAnnotationPresent(Testable.class) == true) {
                try {
                    method.invoke(null);
                    passed += 1;
                } catch (Exception exception) {
                    failed += 1;
                    System.out.printf("%s %n", exception.getCause());
                }
            }
        }

        System.out.printf("passed + failed = %s, passed = %s, failed = %s %n", passed + failed, passed, failed);
    }
}
