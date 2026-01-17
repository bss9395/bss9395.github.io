/* Java_File.java
Author: BSS9395
Update: 2023-02-08T21:50:00+08@China-Shanghai+08
Design: Java Standard Library: File
*/

import java.io.File;
import java.io.IOException;

public class Java_File {
    static public void main(String[] args) {
        _File();
        // _mkdirs();
        // _TempFile();
        // _exists();
        // _list();
        // _listRoots();
    }
    static public void _File() {
        File file = new File("abcd.text");
        System.out.println(file.getName());
        System.out.println(file.getParent());
        System.out.println(file.getAbsoluteFile());
        System.out.println(file.getAbsoluteFile().getParent());
        System.out.println(file.canRead());
        System.out.println(file.canWrite());
        System.out.println(file.canExecute());
        System.out.println(file.isDirectory());
        System.out.println(file.isFile());
    }
    static public void _mkdirs() {
        File file = new File("directory/abc.text");
        File parent = file.getParentFile();
        if(parent.exists() == false) {
            parent.mkdirs();
        }
        try {
            file.createNewFile();
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
    static public void _TempFile() {
        try {
            File tempFile = File.createTempFile("temp", ".text");
            tempFile.deleteOnExit();
            System.out.println(tempFile.getAbsolutePath());
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _exists() {
        try {
            File file = new File(System.currentTimeMillis() + "");
            System.out.println(file.exists());
            System.out.println(file.mkdir());
            System.out.println(file.createNewFile());
            System.out.println(file.mkdir());
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _list() {
        File file = new File(".");
        String[] files = file.list();
        for(int i = 0; i < files.length; i += 1) {
            System.out.println(files[i]);
        }
    }
    static public void _listRoots() {
        File[] files = File.listRoots();
        for(int i = 0; i < files.length; i += 1) {
            System.out.println(files[i].getAbsolutePath());
        }
    }
}
