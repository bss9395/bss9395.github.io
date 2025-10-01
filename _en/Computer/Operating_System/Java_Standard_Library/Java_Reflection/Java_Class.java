/* Java_Class.java
Author: BSS9395
Update: 2023-03-01T22:55:00+08@China-Shanghai+08
Design: Java Standard Library: Class
*/


import java.lang.annotation.Annotation;
import java.lang.annotation.Repeatable;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.reflect.*;
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
    public void setAge(int age) {
        _age = age;
    }
    public int getAge() {
        return _age;
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
        _getFields();
        // _getNestHost();
        // _newInstance();
        // _Invoke();
    }
    static public void _forName()
            throws ClassNotFoundException {
        Class<?> clazz = Class.forName("Java_Class$Nested");
        System.out.println(clazz.getDeclaringClass());
        System.out.println(clazz.getPackage());
        System.out.println(clazz.getSuperclass());
    }
    static public void _getClasses() {
        Class<?> clazz = Java_Class.class;

        Class<?>[] clazzs = clazz.getDeclaredClasses();
        for(int i = 0; i < clazzs.length; i += 1) {
            System.out.println(clazzs[i]);
        }
    }
    static public void _getConstructors() {
        Class<Java_Class> clazz = Java_Class.class;

        Constructor<?>[] constructors = clazz.getDeclaredConstructors();
        for(int i = 0; i < constructors.length; i += 1) {
            System.out.println(constructors[i]);
        }

        System.out.println();
        Constructor<?>[] publics = clazz.getConstructors();
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
            StringBuilder builder = new StringBuilder();
            int modifier = methods[i].getModifiers();
            builder.append(Modifier.toString(modifier) + " ");
            builder.append(methods[i].getReturnType() + " ");
            builder.append(methods[i].getName() + "(");
            Class<?>[] params = methods[i].getParameterTypes();
            for(int x = 0; x < params.length; x += 1) {
                if(x != 0) {
                    builder.append(", ");
                }
                builder.append(params[x].getName());
            }
            builder.append(")");
            Class<?>[] excepts = methods[i].getExceptionTypes();
            if(excepts.length > 0) {
                builder.append(" throws ");
            }
            for(int x = 0; x < excepts.length; x += 1) {
                if(x != 0) {
                    builder.append(", ");
                }
                builder.append(excepts[x].getName());
            }
            System.out.println(builder.toString());
            // System.out.println(methods[i]);
        }

        System.out.println("--------------------------------");
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
        Object obj = clazz.getConstructor().newInstance();

        Field id = clazz.getDeclaredField("_id");
        System.out.println(id.getType().getName());
        System.out.println(id.getType().getSimpleName());

        id.setAccessible(true);
        id.set(obj, "1157");
        System.out.println(id.get(obj));

        Field age = clazz.getDeclaredField("_age");
        age.setAccessible(true);
        age.setInt(obj, 1157);
        System.out.println(obj);
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
    static public void _newInstance() throws Exception {
        Class<?> clazz = Class.forName("Java_Class");
        Object instance = clazz.getDeclaredConstructor(String.class).newInstance("hello");
        System.out.println(instance);
    }
    static public void _Invoke() throws Exception {
        Class<?> clazz = Class.forName("Java_Class");
        String setAge = "setAge";
        String getAge = "getAge";
        String attribute = "age";
        int value = 1157;
        Object obj = clazz.getDeclaredConstructor().newInstance();
        Method setMethod = clazz.getDeclaredMethod(setAge, int.class);
        setMethod.invoke(obj, value);
        Method getMothed = clazz.getDeclaredMethod(getAge);
        System.out.println(getMothed.invoke(obj));
    }
}
