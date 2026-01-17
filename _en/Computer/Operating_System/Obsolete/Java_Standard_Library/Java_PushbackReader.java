/* Java_PushbackReader.java
Author: BSS9395
Update: 2023-02-11T14:10:00+08@China-Shanghai+08
Design: Java Standard Library: PushbackReader
*/

import java.io.FileReader;
import java.io.IOException;
import java.io.PushbackReader;

public class Java_PushbackReader {
    static public void main(String[] args) {
        _PushbackReader();
    }
    static public void _PushbackReader() {
        String text = "new PushbackReader";
        try(PushbackReader reader = new PushbackReader(new FileReader("src/Java_PushbackReader.java"), text.length() * 2);) {
            char[] buff = new char[text.length() * 2];
            int count = reader.read(buff, 0, text.length());
            if(count == text.length() && text.equals(String.valueOf(buff, 0, text.length()))) {
                System.out.print(text);
                System.exit(0);
            }
            while((count = reader.read(buff, text.length(), text.length())) > 0) {
                int index = String.valueOf(buff).indexOf(text);
                if(index > 0) {
                    reader.unread(buff);
                    reader.read(buff, 0, index + text.length());
                    System.out.print(String.valueOf(buff, 0, index + text.length()));
                    System.exit(0);
                }
                System.out.print(String.valueOf(buff, 0, text.length()));

                System.arraycopy(buff, text.length(), buff, 0, text.length());
            }
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
}
