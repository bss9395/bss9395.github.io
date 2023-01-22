/* Java_Runtime.java
Author: BSS9395
Update: 2023-01-08T20:25:00+08@China-Shanghai+08
Design: Ja
*/

import java.io.IOException;

public class Java_Runtime {
    static public void main(String[] args) {
        // _getRuntime();
        _exec();
    }
    static public void _getRuntime() {
        System.out.println("static public void _getRuntime() {");
        Runtime runtime = Runtime.getRuntime();
        System.out.printf("%30s: %s %n", "availableProcessors()", runtime.availableProcessors());
        System.out.printf("%30s: %s %n", "maxMemory()", runtime.maxMemory());
        System.out.printf("%30s: %s %n", "totalMemory()", runtime.totalMemory());
        System.out.printf("%30s: %s %n", "freeMemory()", runtime.freeMemory());
    }
    static public void _exec() {
        System.out.println("static public void _exec() {");
        try {
            Runtime runtime = Runtime.getRuntime();
            runtime.exec("notepad.exe");
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
}
