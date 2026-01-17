/* Java_FileChannel.java
Author: BSS9395
Update: 2023-02-12T14:53:00+08@China-Shanghai+08
Design: Java Standard Library: FileChannel
*/

import java.io.*;
import java.nio.CharBuffer;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.charset.Charset;

public class Java_FileChannel {
    static public void main(String[] args) {
        _FileChannel();
    }
    static public void _FileChannel() {
        File file = new File("src/Java_FileChannel.java");
        try(FileChannel input = new FileInputStream(file).getChannel();
            FileChannel output = new FileOutputStream("output.text").getChannel();) {
            MappedByteBuffer byteBuffer = input.map(FileChannel.MapMode.READ_ONLY, 0, file.length());
            output.write(byteBuffer);

            byteBuffer.clear();
            CharBuffer charBuffer = Charset.forName("UTF-8").decode(byteBuffer);
            System.out.println(charBuffer);
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
}
