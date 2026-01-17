/* Java_Files.java
Author: BSS9395
Update: 2023-02-12T19:23:00+08@China-Shanghai+08
Design: Java Standard Library: Files
*/

import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.FileStore;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class Java_Files {
    static public void main(String[] args) {
        // _copy();
        // _write();
        // _isHidden();
        // _readAllLines();
        // _size();
        // _list();
        // _lines();
        _getFileStore();
    }
    static public void _copy() {
        try {
            Files.copy(Paths.get("src/Java_Files.java"), new FileOutputStream("copy.text"));
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _write() {
        /*
        Brilliant@DESKTOP-899PO6R MINGW64 /e/IdeaProjects/untitled/src
        $ Javac Java_Files.java -encoding UTF-8
        Brilliant@DESKTOP-899PO6R MINGW64 /e/IdeaProjects/untitled/src
        $ java Java_Files -Dfile.encoding=UTF-8
        */
        try {
            List<String> poem = new ArrayList<>();
            poem.add("《武陵春·春晚》[宋代]李清照");
            poem.add("风住尘香花已尽，日晚倦梳头。\n");
            poem.add("物是人非事事休，欲语泪先流。\n");
            poem.add("闻说双溪春尚好，也拟泛轻舟。\n");
            poem.add("只恐双溪蚱蜢舟，载不动许多愁。\n");

            Files.write(Paths.get("poem.text"), poem, Charset.forName("UTF-8"));
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _isHidden() {
        try {
            boolean hidden = Files.isHidden(Paths.get("src/Java_Files.java"));
            System.out.println(hidden);
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _readAllLines() {
        try {
            List<String> lines = Files.readAllLines(Paths.get("src/Java_Files.java"), Charset.forName("GBK"));
            System.out.println(lines);
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _size() {
        try {
            long size = Files.size(Paths.get("src/Java_Files.java"));
            System.out.println(size);
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _list() {
        try {
            Files.list(Paths.get(".")).forEach((path) -> {
                System.out.println(path);
            });
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _lines() {
        try {
            Files.lines(Paths.get("src/Java_Files.java"), Charset.forName("UTF-8")).forEach((line) -> {
                System.out.println(line);
            });
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _getFileStore() {
        try {
            FileStore store = Files.getFileStore(Paths.get("C:/"));
            System.out.println(store.getTotalSpace() / 1024 / 1024 / 1024);
            System.out.println(store.getUsableSpace() / 1024 / 1024 / 1024);
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
}
