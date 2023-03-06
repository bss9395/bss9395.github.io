/* Java_ClassLoader.java
Author: BSS9395
Update: 2023-02-26T13:15:00+08@China-Shanghai+08
Design: Java Standard Library: ClassLoader
*/

import java.io.IOException;
import java.net.URL;
import java.util.Enumeration;

public class Java_ClassLoader {
    static public class Datum {
        static {
            System.out.println("static");
        }
    }

    static public void main(String[] args)
        throws ClassNotFoundException, IOException {
        // _loadClass();
        // _Class();
        _ClassLoader();
    }
    static public void _loadClass()
            throws ClassNotFoundException {
        ClassLoader loader = ClassLoader.getSystemClassLoader();
        loader.loadClass("Java_ClassLoader$Datum");
    }
    static public void _Class()
            throws ClassNotFoundException {
        Class.forName("Java_ClassLoader$Datum");
    }
    static public void _ClassLoader()
        throws IOException {
        ClassLoader app = ClassLoader.getSystemClassLoader();
        ClassLoader platform = app.getParent();
        ClassLoader root = platform.getParent();
        System.out.println(app);
        System.out.println(platform);
        System.out.println(root);

        Enumeration<URL> urls = app.getResources("");
        while(urls.hasMoreElements() == true) {
            System.out.println(urls.nextElement());
        }
        System.out.println(System.getProperty("java.ext.dirs"));
    }
}
