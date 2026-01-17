/* Java_FilenameFilter.java
Author: BSS9395
Update: 2023-02-08T22:03:00+08@China-Shanghai+08
Design: Java Standard Library: FilenameFilter
*/

import java.io.File;

public class Java_FilenameFilter {
    static public void main(String[] args) {
        _FilenameFilter();
    }
    static public void _FilenameFilter() {
        File file = new File(".");
        String[] names = file.list((dir, name) -> {
            return (name.endsWith(".java") || new File(name).isDirectory());
        });

        for(int i = 0; i < names.length; i += 1) {
            System.out.println(names[i]);
        }
    }
}
