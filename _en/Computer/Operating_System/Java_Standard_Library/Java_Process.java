/* Java_Process.java
Author: BSS9395
Update: 2023-01-08T20:27:00+08@China-Shanghai+08
Design: Java Standard Library: Process
*/

import java.io.*;
import java.util.Scanner;
import java.util.concurrent.CompletableFuture;

public class Java_Process {
    static public class Another {
        public static void main(String[] args) {
            try(Scanner scanner = new Scanner(System.in);
                PrintStream stream = new PrintStream(new FileOutputStream("output.text"), true, "UTF-8");) {
                scanner.useDelimiter("\n");
                while(scanner.hasNext() == true) {
                    stream.println(scanner.next());
                    System.out.println(scanner.next());
                }
            } catch (IOException exception) {
                exception.printStackTrace();
            }
        }
    }

    static public void main(String[] args) {
        // _ProcessHandle();
        // _ProcessHandle_Info();
        // _getInputStream();
        _getOutputStream();
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
    static public void _getInputStream() {
        try {
            Process process = Runtime.getRuntime().exec("javac");
            try(BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));) {
                String buff = null;
                while((buff = reader.readLine()) != null) {
                    System.out.println(buff);
                }
            }
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _getOutputStream() {
        try {
            Process process = Runtime.getRuntime().exec("java Java_Process$Another");
            try(PrintStream stream = new PrintStream(process.getOutputStream());) {
                stream.println("《武陵春·春晚》[宋代]李清照");
                stream.println("风住尘香花已尽，日晚倦梳头。");
                stream.println("物是人非事事休，欲语泪先流。");
                stream.println("闻说双溪春尚好，也拟泛轻舟。");
                stream.println("只恐双溪蚱蜢舟，载不动许多愁。");
            }
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
}
