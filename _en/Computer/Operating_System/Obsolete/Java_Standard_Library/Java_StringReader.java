/* Java_StringReader.java
Author: BSS9395
Update: 2023-02-09T22:30:00+08@China-Shanghai+08
Design: Java Standard Library: StringReader
*/

import java.io.IOException;
import java.io.StringReader;

public class Java_StringReader {
    static public void main(String[] args) {
        _StringReader();
    }
    static public void _StringReader() {
        String text = "《武陵春·春晚》宋代 李清照\n"
                    + "风住尘香花已尽，日晚倦梳头。\n"
                    + "物是人非事事休，欲语泪先流。\n"
                    + "闻说双溪春尚好，也拟泛轻舟。\n"
                    + "只恐双溪蚱蜢舟，载不动许多愁。\n";
        char[] buff = new char[1024];
        int count = 0;
        try(StringReader reader = new StringReader(text)) {
            while((count = reader.read(buff)) > 0) {
                System.out.print(new String(buff, 0, count));
            }
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
}
