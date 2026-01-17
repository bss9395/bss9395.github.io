/* Java_Path.java
Author: BSS9395
Update: 2023-02-12T18:34:00+08@China-Shanghai+08
Design: Java Standard Library: Path
*/

import java.nio.file.Path;
import java.nio.file.Paths;

public class Java_Paths {
    static public void main(String[] args) {
        _Paths();
    }
    static public void _Paths() {
        Path relative = Paths.get(".");
        System.out.println(relative);
        System.out.println(relative.getRoot());
        System.out.println(relative.getNameCount());
        System.out.println(relative.getName(0));

        Path absolute = relative.toAbsolutePath();
        System.out.println(absolute);
        System.out.println(absolute.getRoot());
        System.out.println(absolute.getNameCount());
        System.out.println(absolute.getName(0));
    }
}
