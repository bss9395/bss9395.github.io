/* Java_RandomAccessFile.java
Author: BSS9395
Update: 2023-02-11T16:05:00+08@China-Shanghai+08
Design: Java Standard Library: RandomAccessFile
*/

import java.io.*;
import java.nio.charset.StandardCharsets;

public class Java_RandomAccessFile {
    static public void main(String[] args) {
        // _RandomAccessFile_r();
        // _RandomAccessFile_rw();
        _RandomAccessFile();
    }
    static public void _RandomAccessFile_r() {
        try(RandomAccessFile file = new RandomAccessFile("src/Java_RandomAccessFile.java", "r");) {
            System.out.printf("file.getFilePointer() = %s %n", file.getFilePointer());
            file.seek(256);
            byte[] buff = new byte[1024];
            int count = 0;
            while((count = file.read(buff)) > 0) {
                System.out.println(new String(buff, 0, count));
            }
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _RandomAccessFile_rw() {
        try(RandomAccessFile file = new RandomAccessFile("output.text", "rw");) {
            file.seek(file.length());
            file.write("At the end of the file. ".getBytes(StandardCharsets.UTF_8));
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _RandomAccessFile() {
        _Insert("output.text", 3, "Added content. ");
    }

    static void _Insert(String filename, long position, String content) {
        try {
            File temp = File.createTempFile("temp", null);
            temp.deleteOnExit();
            try(RandomAccessFile file = new RandomAccessFile(filename, "rw");
                FileOutputStream output = new FileOutputStream(temp);
                FileInputStream input = new FileInputStream(temp);) {
                byte[] buff = new byte[1024];
                int count = 0;

                file.seek(position);
                while((count = file.read(buff)) > 0) {
                    output.write(buff, 0, count);
                }

                file.seek(position);
                file.write(content.getBytes(StandardCharsets.UTF_8));

                while((count = input.read(buff)) > 0) {
                    file.write(buff, 0, count);
                }
            }
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
}
