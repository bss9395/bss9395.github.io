/* Java_ByteArrayOutputStream.java
Author: bss9395
Update: 2025/09/24T19:39:00+08TChina-GuangDong-ZhanJiang+08
*/

import java.io.*;

public class Java_ByteArrayOutputStream {
    static public void main(String[] args) throws IOException {
        String str = "bss9395@github.com";
        ByteArrayInputStream input = new ByteArrayInputStream(str.getBytes());
        ByteArrayOutputStream output = new ByteArrayOutputStream();
        int data = 0;
        while(0 < (data = input.read())) {
            output.write(Character.toUpperCase((char)data));
        }
        System.out.println(new String(output.toByteArray()));
        input.close();
        output.close();
    }
}
