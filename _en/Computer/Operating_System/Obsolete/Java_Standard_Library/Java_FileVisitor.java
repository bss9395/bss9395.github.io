/* Java_FileVisitor.java
Author: BSS9395
Update: 2023-02-12T20:24:00+08@China-Shanghai+08
Design: Java Standard Library: FileVisitor
*/

import java.io.IOException;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;

public class Java_FileVisitor {
    static public void main(String[] args) {
        _FileVisitor();
    }
    static public void _FileVisitor() {
        try {
            Path path = Paths.get(".").toAbsolutePath();
            // System.out.println(path);
            Files.walkFileTree(path, new SimpleFileVisitor<Path>() {
                int _level = 0;
                @Override
                public FileVisitResult preVisitDirectory(Path dire, BasicFileAttributes attrs) {
                    for(int i = 0; i < _level; i += 1) {
                        System.out.print("    ");
                    }
                    System.out.println(dire);
                    _level += 1;
                    return FileVisitResult.CONTINUE;
                }
                @Override
                public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) {
                    for(int i = 0; i < _level; i += 1) {
                        System.out.print("    ");
                    }
                    System.out.println(file);
                    if(file.endsWith("Java_FileVisitor.java") == true) {
                        return FileVisitResult.TERMINATE;
                    }
                    return FileVisitResult.CONTINUE;
                }
                @Override
                public FileVisitResult postVisitDirectory(Path dire, IOException exception) {
                    _level -= 1;
                    return FileVisitResult.CONTINUE;
                }
            });
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
}
