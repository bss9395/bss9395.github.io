/* Java_Class.java
Author: BSS9395
Update: 2023-03-01T22:55:00+08@China-Shanghai+08
Design: Java Standard Library: Class
*/


import java.lang.annotation.Annotation;
import java.lang.annotation.Repeatable;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Arrays;


@Repeatable(Annos.class)
@interface Anno {

}

@Retention(value= RetentionPolicy.RUNTIME)
@interface Annos {
    Anno[] value();
}


@Deprecated
@Anno
@Anno
@SuppressWarnings(value="unchecked")
public class Java_Class {
    static public class Nested {

    }
    static public class Sibling {

    }

    private String _id = "1156";
    private int _age = 1156;
    @Override
    public String toString() {
        return String.format("%s: %s", _id, _age);
    }

    public Java_Class() {
        System.out.println("public Java_Class() {");
    }
    public Java_Class(String text) {
        System.out.println("public Java_Class(String text) {");
    }
    private void _Info() {
        System.out.println("public void _Info() {");
    }
    private void _Info(String text) {
        System.out.println("public void _Info(String text) {");
    }

    static public void main(String[] args)
        throws Exception {
        // _forName();
        // _getClasses();
        // _getConstructors();
        // _getMethods();
        // _getAnnotations();
        // _getFields();
        _getNestHost();
    }
    static public void _forName()
        throws ClassNotFoundException {
        Class clazz = Class.forName("Java_Class$Nested");
        System.out.println(clazz.getDeclaringClass());
        System.out.println(clazz.getPackage());
        System.out.println(clazz.getSuperclass());
    }
    static public void _getClasses() {
        Class<Java_Class> clazz = Java_Class.class;

        Class[] clazzs = clazz.getDeclaredClasses();
        for(int i = 0; i < clazzs.length; i += 1) {
            System.out.println(clazzs[i]);
        }
    }
    static public void _getConstructors() {
        Class<Java_Class> clazz = Java_Class.class;

        Constructor[] constructors = clazz.getDeclaredConstructors();
        for(int i = 0; i < constructors.length; i += 1) {
            System.out.println(constructors[i]);
        }

        System.out.println();
        Constructor[] publics = clazz.getConstructors();
        for(int i = 0; i < constructors.length; i += 1) {
            System.out.println(publics[i]);
        }
    }
    static public void _getMethods()
        throws Exception {
        Class<Java_Class> clazz = Java_Class.class;

        Method[] methods = clazz.getDeclaredMethods();
        for(int i = 0; i < methods.length; i += 1) {
            methods[i].setAccessible(true);
            System.out.println(methods[i]);
        }

        System.out.println();
        Method _info = clazz.getDeclaredMethod("_Info", String.class);
        _info.setAccessible(true);
        System.out.println(_info);
    }
    static public void _getAnnotations() {
        Class<Java_Class> clazz = Java_Class.class;

        Annotation[] annotations = clazz.getAnnotations();
        for(int i = 0; i < annotations.length; i += 1) {
            System.out.println(annotations[i]);
        }

        System.out.println("====");
        Annotation[] suppresss = clazz.getAnnotationsByType(SuppressWarnings.class);
        for(int i = 0; i < suppresss.length; i += 1) {
            System.out.println(suppresss[i]);
        }

        System.out.println("====");
        Annotation[] annos = clazz.getAnnotationsByType(Anno.class);
        for(int i = 0; i < annos.length; i += 1) {
            System.out.println(annos[i]);
        }
    }
    static public void _getFields()
        throws Exception {
        Class<?> clazz = Class.forName("Java_Class");
        Object java_class = clazz.getConstructor().newInstance();

        Field id = clazz.getDeclaredField("_id");
        id.setAccessible(true);
        id.set(java_class, "1157");

        Field age = clazz.getDeclaredField("_age");
        age.setAccessible(true);
        age.setInt(java_class, 1157);
        System.out.println(java_class);
    }
    static public void _getNestHost() {
        Class<?> host = Nested.class.getNestHost();
        System.out.println(host);

        Class<?> outer = Java_Class.class.getNestHost();
        System.out.println(outer);

        Class<?>[] clazzes = Java_Class.class.getNestMembers();
        System.out.println(Arrays.toString(clazzes));

        System.out.println(Nested.class.isNestmateOf(Sibling.class));
    }
}
