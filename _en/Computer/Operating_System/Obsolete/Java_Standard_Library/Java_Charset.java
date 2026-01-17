/* Java_Charset.java
Author: BSS9395
Update: 2023-02-12T16:19:00+08@China-Shanghai+08
Design: Java Standard Library: Charset
*/

import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.charset.Charset;
import java.util.SortedMap;

public class Java_Charset {
    static public void main(String[] args) {
        // _availableCharsets();
        _Charset();
    }
    static public void _availableCharsets() {
        SortedMap<String, Charset> map = Charset.availableCharsets();
        for(String key: map.keySet()) {
            System.out.printf("%s%n", key);
        }
    }
    static public void _Charset() {
        /* file-encoding: UTF-8; console-encoding: GBK
        javac Java_Charset.java -encoding UTF-8
        java  Java_Charset      -Dfile.encoding=UTF-8
        */
        try {
            Charset charset = Charset.forName("GBK");
            CharBuffer charBuffer = CharBuffer.allocate(128);
            charBuffer.put('璀');
            charBuffer.put('璨');
            charBuffer.put('星');
            charBuffer.put('辰');
            charBuffer.flip();

            ByteBuffer byteBuffer = charset.encode(charBuffer);
            for (int i = 0; i < byteBuffer.limit(); i += 1) {
                System.out.print(byteBuffer.get(i));
            }
            System.out.println();

            CharBuffer buffer = charset.decode(byteBuffer);
            System.out.println(buffer);
        } catch(Exception exception) {
            exception.printStackTrace();
        }
    }
}
