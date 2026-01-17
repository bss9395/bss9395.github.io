/* Java_Parameter.java
Author: BSS9395
Update: 2023-03-02T23:28:00+08@China-Shanghai+08
Design: Java Standard Library: Parameter
*/

import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.util.List;

/*
java -parameters Java_Parameter
*/
public class Java_Parameter {
    public void _Func(String str, List<String> list) {
        System.out.println("public void _Func(String str, List<String> list) {");
    }

    static public void main(String[] args)
        throws NoSuchMethodException {
        _Parameter();
    }
    static public void _Parameter()
        throws NoSuchMethodException {
        Class<Java_Parameter> clazz = Java_Parameter.class;
        Method method = clazz.getMethod("_Func", String.class, List.class);
        System.out.println(method.getParameterCount());

        Parameter[] parameters = method.getParameters();
        for(int i = 0; i < parameters.length; i += 1) {
            System.out.println(parameters[i].getName());
            System.out.println(parameters[i].getType());
            System.out.println(parameters[i].getParameterizedType());
        }
    }
}
