/* Java_StringWriter.java
Author: BSS9395
Update: 2023-02-09T22:35:00+08@China-Shanghai+08
Design: Java Standard Library: StringWriter
*/

import java.io.IOException;
import java.io.StringWriter;

public class Java_StringWriter {
    static public void main(String[] args) {
        _StringWriter();
    }
    static public void _StringWriter() {
        try(StringWriter writer = new StringWriter(64);) {
            writer.write("《武陵春·春晚》宋代 李清照\n");
            writer.write("风住尘香花已尽，日晚倦梳头。\n");
            writer.write("物是人非事事休，欲语泪先流。\n");
            writer.write("闻说双溪春尚好，也拟泛轻舟。\n");
            writer.write("只恐双溪蚱蜢舟，载不动许多愁。\n");

            System.out.print(writer.toString());
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
}
