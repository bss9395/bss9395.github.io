/* Java_Process.java
Author: BSS9395
Update: 2023-01-08T20:27:00+08@China-Shanghai+08
Design: Java Standard Library: Process
*/

import java.io.IOException;
import java.util.concurrent.CompletableFuture;

public class Java_Process {
    static public void main(String[] args) {
        // _ProcessHandle();
        _ProcessHandle_Info();
    }
    static public void _ProcessHandle() {
        System.out.println("static public void _ProcessHandle() {");
        try {
            Runtime runtime = Runtime.getRuntime();
            Process process = runtime.exec("notepad.exe");
            ProcessHandle handle = process.toHandle();
            System.out.printf("%10s: %s %n", "isAlive()", handle.isAlive());
            System.out.printf("%10s: %s %n", "parent()", handle.parent());
            System.out.printf("%10s: %s %n", "pid()", handle.pid());
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _ProcessHandle_Info() {
        System.out.println("static public void _ProcessHandle_Info() {");
        try {
            Runtime runtime = Runtime.getRuntime();
            Process process = runtime.exec("notepad.exe");
            ProcessHandle handle = process.toHandle();
            System.out.printf("%10s: %s %n", "isAlive()", handle.isAlive());
            System.out.printf("%10s: %s %n", "parent()", handle.parent());
            System.out.printf("%10s: %s %n", "pid()", handle.pid());

            ProcessHandle.Info info = handle.info();
            System.out.printf("%10s: %s %n", "command()", info.command());
            System.out.printf("%10s: %s %n", "arguments()", info.arguments());
            System.out.printf("%10s: %s %n", "startInstant()", info.startInstant());
            System.out.printf("%10s: %s %n", "totalCpuDuration()", info.totalCpuDuration());

            CompletableFuture<ProcessHandle> future = handle.onExit();
            future.thenRunAsync(() -> {
                System.out.println("process exit...");
            });
            Thread.sleep(10000);
        } catch(IOException | InterruptedException exception ) {
            exception.printStackTrace();
        }
    }
}
