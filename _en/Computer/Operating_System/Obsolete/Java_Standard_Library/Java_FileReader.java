/* Java_FileReader.java
Author: BSS9395
Update: 2023-02-09T20:13:00+08@China-Shanghai+08
Design: Java Standard Library: FileReader
*/

import java.io.FileReader;
import java.io.IOException;

public class Java_FileReader {
    static public void main(String[] args) {
        _FileReader();
    }
    static public void _FileReader() {
        try (FileReader reader = new FileReader("src/Java_FileReader.java")){
            char[] buff = new char[1024];
            int count = 0;
            while((count = reader.read(buff)) > 0) {
                System.out.println(new String(buff, 0, count));
            }
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
}
