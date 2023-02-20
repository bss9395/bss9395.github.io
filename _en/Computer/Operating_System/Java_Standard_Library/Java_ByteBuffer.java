/* Java_ByteBuffer.java
Author: BSS9395
Update: 2023-02-12T15:18:00+08@China-Shanghai+08
Design: Java Standard Library: ByteBuffer
*/

import java.io.FileInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.channels.FileChannel;
import java.nio.charset.Charset;

public class Java_ByteBuffer {
    static public void main(String[] args) {
        _ByteBuffer();
    }
    static public void _ByteBuffer() {
        try(FileInputStream stream = new FileInputStream("src/Java_ByteBuffer.java");
            FileChannel channel = stream.getChannel();) {
            ByteBuffer byteBuffer = ByteBuffer.allocate(1024);
            while(channel.read(byteBuffer) != -1) {
                byteBuffer.flip();
                CharBuffer charBuffer = Charset.forName("UTF-8").decode(byteBuffer);
                System.out.println(charBuffer);
                byteBuffer.clear();
            }
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
}
