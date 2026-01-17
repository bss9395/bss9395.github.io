/* Java_PrintStream.java
Author: BSS9395
Update: 2023-02-09T22:11:00+08@China-Shanghai+08
Design: Java Standard Library: PrintStream
*/

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;

public class Java_PrintStream {
    static public void main(String[] args) {
        _PrintStream();
    }
    static public void _PrintStream() {
        try(FileOutputStream file = new FileOutputStream("output.text");
            PrintStream stream = new PrintStream(file);) {
            stream.println("《武陵春·春晚》宋代 李清照");
            stream.println("风住尘香花已尽，日晚倦梳头。");
            stream.println("物是人非事事休，欲语泪先流。");
            stream.println("闻说双溪春尚好，也拟泛轻舟。");
            stream.println("只恐双溪蚱蜢舟，载不动许多愁。");
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
}
