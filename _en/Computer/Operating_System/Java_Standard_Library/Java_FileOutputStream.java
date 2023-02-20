/* Java_FileOutputStream.java
Author: BSS9395
Update: 2023-02-09T20:27:00+08@China-Shanghai+08
Design: Java Standard Library: OutputStream
*/

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Java_OutputStream {
    static public void main(String[] args) {
        _OutputStream();
    }
    static public void _OutputStream() {
        try(FileInputStream input = new FileInputStream("src/Java_OutputStream.java");
            FileOutputStream output = new FileOutputStream("output.text");) {
            byte[] buff = new byte[1024];
            int count = 0;
            while((count = input.read(buff)) > 0) {
                output.write(buff, 0, count);
            }
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
}
