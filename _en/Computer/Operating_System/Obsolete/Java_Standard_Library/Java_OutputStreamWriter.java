/* Java_FileWriter.java
Author: BSS9395
Update: 2025/09/24T17:41:00+08@China-GuangDong-ZhanJiang+08
*/

import java.io.*;

public class Java_OutputStreamWriter {
    static public void main(String[] args) throws IOException {
        File file = new File("abcd.text");
        if(file.getParentFile() != null && file.getParentFile().exists() == false) {
            file.getParentFile().mkdirs();
        }
        OutputStream output = new FileOutputStream(file);
        Writer writer = new OutputStreamWriter(output);
        writer.write("bss9395@github.com");
        writer.close();
    }
}
