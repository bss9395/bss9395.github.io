/* Java_Compile.java
Author: BSS9395
Update: 2023-02-26T17:22:00+08@China-Shanghai+08
Design: Compile
*/

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class Java_Compile extends ClassLoader {
    @Override
    protected Class<?> findClass(String name)
        throws ClassNotFoundException {
        String filename = name.replace(".", "/");
        String filename_java = filename + ".java";
        String filename_class = filename + ".class";
        File file_java = new File(filename_java);
        File file_class = new File(filename_class);
        if(file_java.exists() == true && (file_class.exists() == false || file_java.lastModified() > file_class.lastModified())) {
            if(_Compile(filename_java) != 0 || file_class.exists() == false) {
                throw new ClassNotFoundException(String.format("ClassNotFoundException: %s", filename));
            }
        }

        Class<?> clazz = null;
        if(file_class.exists() == true) {
            byte[] buffer = _Get_Bytes(filename_class);
            clazz = this.defineClass(name, buffer, 0, buffer.length);
        }
        return clazz;
    }
    private int _Compile(String name) {
        System.out.printf("_Compile: %s%n", name);
        int code = 0;
        try {
            Process process = Runtime.getRuntime().exec(String.format("javac %s", name));
            process.waitFor();
            code = process.exitValue();
        } catch(InterruptedException exception) {
            exception.printStackTrace();
        } catch(IOException exception) {
            exception.printStackTrace();
        }
        return code;
    }
    private byte[] _Get_Bytes(String name) {
        byte[] buffer = null;
        try {
            FileInputStream stream = new FileInputStream(new File(name));
            buffer = stream.readAllBytes();
        } catch (IOException exception) {
            exception.printStackTrace();
        }
        return buffer;
    }

    static public void main(String[] args)
        throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, IllegalAccessException {
        if(args.length < 1) {
            String usage = String.format("usage: java Java_Compile ClassName%n");
            System.out.println(usage);
        }

        String clazz_name = args[0];
        String[] clazz_args = new String[args.length - 1];
        System.arraycopy(args, 1, clazz_args, 0, clazz_args.length);
        Object[] invoke_args = {
            clazz_args
        };

        Class<?> clazz = new Java_Compile().loadClass(clazz_name);
        Method main = clazz.getMethod("main", (new String[0]).getClass());
        main.invoke(null, invoke_args);
    }
}
