/* Java_Runtime.java
Author: bss9395
Update: 2025-08-04T19:47:00+08@China-GuangDong-ZhanJiang+08
*/

import java.io.IOException;

public class Java_Runtime {
    static public void main(String[] args) {
        // _Test_getRuntime();
        _Test_exec();
    }
    static public void _Test_getRuntime() {
        Runtime run = Runtime.getRuntime();
        System.out.println("availableProcessors = " + run.availableProcessors());
        System.out.println("maxMemory = " + run.maxMemory());
        System.out.println("totalMemory = " + run.totalMemory());
        System.out.println("freeMemory = " + run.freeMemory());

        System.out.println("----------------------------------------");
        String str = "";
        for(int i = 0; i < 30000; i += 1) {
            str += i;
        }
        System.out.println("availableProcessors = " + run.availableProcessors());
        System.out.println("maxMemory = " + run.maxMemory());
        System.out.println("totalMemory = " + run.totalMemory());
        System.out.println("freeMemory = " + run.freeMemory());

        System.out.println("----------------------------------------");
        run.gc();
        System.out.println("availableProcessors = " + run.availableProcessors());
        System.out.println("maxMemory = " + run.maxMemory());
        System.out.println("totalMemory = " + run.totalMemory());
        System.out.println("freeMemory = " + run.freeMemory());
    }
    static public void _Test_exec() {
        try {
            Runtime runtime = Runtime.getRuntime();
            runtime.exec("notepad.exe");
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
}
