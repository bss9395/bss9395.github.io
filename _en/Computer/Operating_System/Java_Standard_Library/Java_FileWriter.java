/* Java_FileWriter.java
Author: BSS9395
Update: 2023-02-09T22:24:00+08@China-Shanghai+08
Design: Java Standard Library: FileWriter
*/


import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

public class Java_FileWriter {
    static public void main(String[] args) {
        _FileWriter();
    }
    static public void _FileWriter() {
        try(FileWriter writer = new FileWriter("writer.text", StandardCharsets.UTF_8)) {
            writer.write("《武陵春·春晚》宋代 李清照\n");
            writer.write("风住尘香花已尽，日晚倦梳头。\n");
            writer.write("物是人非事事休，欲语泪先流。\n");
            writer.write("闻说双溪春尚好，也拟泛轻舟。\n");
            writer.write("只恐双溪蚱蜢舟，载不动许多愁。\n");
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
}
