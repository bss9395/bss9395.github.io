/* Java_newInstance.java
Author: BSS9395
Update: 2023-03-03T23:17:00+08@China-Shanghai+08
Design: Java Standard Library: newInstance()
*/

import javax.swing.*;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;

public class Java_Invoke {
    static public void main(String[] args)
        throws Exception {
        _Invoke();
    }
    static public void _Invoke()
        throws Exception {
        Class<?> clazz = Class.forName("javax.swing.JFrame");
        Constructor constructor = clazz.getConstructor(String.class);
        Object object = constructor.newInstance("Hello");
        Method method = clazz.getMethod("setTitle", String.class);
        method.invoke(object, "World");

        System.out.println(object);
        JFrame frame = (JFrame) object;
        frame.setSize(400, 400);
        frame.setVisible(true);
    }
}
