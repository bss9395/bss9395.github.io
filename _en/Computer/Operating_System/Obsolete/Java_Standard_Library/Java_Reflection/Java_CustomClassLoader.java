/* Java_CustomClassLoader.java
Author: bss9395
Update: 2025/09/27T09:15:00+08@China-GuangDong-ZhanJiang+08
*/

import java.io.*;
import java.lang.reflect.Method;

/*
package cn.mldn.util;

public class Message {
    public void send() {
        System.out.println("www.mldn.cn");
    }
}
*/

class CustomClassLoader extends ClassLoader {
    public Class<?> _DefineClassFromFile(String className) throws Exception {
        FileInputStream input = new FileInputStream(new File("src/Message.class"));
        byte[] data = input.readAllBytes();
        return super.defineClass(className, data, 0, data.length);
    }
    public void _LoadClass(String className) throws Exception {

    }
}

public class Java_CustomClassLoader {
    static public void main(String[] args) throws Exception {
        _Test_defineClass();
    }
    static public void _Test_defineClass() throws Exception {
        CustomClassLoader classLoader = new CustomClassLoader();
        Class<?> clazz = classLoader._DefineClassFromFile("cn.mldn.util.Message");
        System.out.println(clazz);

        Object obj = clazz.getDeclaredConstructor().newInstance();
        Method method = clazz.getDeclaredMethod("send");
        method.invoke(obj);

        System.out.println(clazz.getClassLoader());
        System.out.println(clazz.getClassLoader().getParent());
        System.out.println(clazz.getClassLoader().getParent().getParent());
    }
}