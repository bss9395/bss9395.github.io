/* Java_FileInputStream.java
Author: BSS9395
Update: 2023-02-08T23:07:00+08@China-Shanghai+08
Desing: Java Standard Library: FileInputStream
*/

import java.io.FileInputStream;
import java.io.IOException;

public class Java_FileInputStream {
    static public void main(String[] args) {
        _FileInputStream();
    }
    static public void _FileInputStream() {
        FileInputStream stream = null;
        try {
            stream = new FileInputStream("src/Java_FileInputStream.java");
            byte[] buff = new byte[1024];
            int count = 0;
            while((count = stream.read(buff)) > 0) {
                System.out.println(new String(buff, 0, count));
            }
        } catch(IOException exception) {
            exception.printStackTrace();
        } finally {
            try {
                stream.close();
            } catch(IOException exception) {
                exception.printStackTrace();
            }
        }
    }
}
