/* Java_PrintWriter.java
Author: bss9395
Update: 2025/09/24T22:14:00+08@China-GuangDong-ZhanJiang+08
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;

public class Java_PrintWriter {
    static public void main(String[] args) throws FileNotFoundException {
        File file = new File("abcd.text");
        PrintWriter writer = new PrintWriter(file);
        writer.println("姓名：小强子");
        writer.print("年龄：");
        writer.println(78);
        writer.close();
    }
}
