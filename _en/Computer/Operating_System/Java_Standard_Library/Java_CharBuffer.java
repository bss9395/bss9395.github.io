

import java.nio.CharBuffer;

public class Java_CharBuffer {
    static public void main(String[] args) {
        _CharBuffer();
    }
    static public void _CharBuffer() {
        CharBuffer charBuffer = CharBuffer.allocate(8);
        System.out.printf("%25s = %s%n", "charBuffer.capacity()", charBuffer.capacity());
        System.out.printf("%25s = %s%n", "charBuffer.limit()", charBuffer.limit());
        System.out.printf("%25s = %s%n", "charBuffer.position()", charBuffer.position());

        charBuffer.put('a');
        charBuffer.put('b');
        charBuffer.put('c');
        charBuffer.flip();
        System.out.printf("%25s = %s%n", "charBuffer.capacity()", charBuffer.capacity());
        System.out.printf("%25s = %s%n", "charBuffer.limit()", charBuffer.limit());
        System.out.printf("%25s = %s%n", "charBuffer.position()", charBuffer.position());

        System.out.printf("%25s = %s%n", "charBuffer.get()", charBuffer.get());
        System.out.printf("%25s = %s%n", "charBuffer.capacity()", charBuffer.capacity());
        System.out.printf("%25s = %s%n", "charBuffer.limit()", charBuffer.limit());
        System.out.printf("%25s = %s%n", "charBuffer.position()", charBuffer.position());

        charBuffer.clear();
        System.out.printf("%25s = %s%n", "charBuffer.capacity()", charBuffer.capacity());
        System.out.printf("%25s = %s%n", "charBuffer.limit()", charBuffer.limit());
        System.out.printf("%25s = %s%n", "charBuffer.position()", charBuffer.position());

        System.out.printf("%25s = %s%n", "charBuffer.get()", charBuffer.get(2));
        System.out.printf("%25s = %s%n", "charBuffer.capacity()", charBuffer.capacity());
        System.out.printf("%25s = %s%n", "charBuffer.limit()", charBuffer.limit());
        System.out.printf("%25s = %s%n", "charBuffer.position()", charBuffer.position());
    }
}
