/* Java_Meta_Annotation.java
Author: BSS9395
Update: 2023-01-04T15:56:00+08@China-Shanghai+08
Design: Java Language Feature: Meta Annotation
*/

import java.lang.annotation.*;

public class Java_Meta_Annotation {
    @Retention(RetentionPolicy.RUNTIME)
    @Target(ElementType.METHOD)
    @Documented
    public @interface IMethod {

    }

    @Retention(RetentionPolicy.RUNTIME)
    @Target(ElementType.TYPE)
    @Inherited
    public @interface IType {

    }

    @IMethod
    public void _Function() {

    }
    @IType
    static public class Base {

    }
    static public class Derived extends Base {

    }


    static public void main(String[] args) {
        System.out.printf("Derived.class.isAnnotationPresent(IType.class) = %s %n", Derived.class.isAnnotationPresent(IType.class));
    }
}
