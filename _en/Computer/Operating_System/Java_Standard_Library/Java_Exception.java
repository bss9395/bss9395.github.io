/* Java_Exception.java
Author: BSS9395
Update: 2023-02-01T21:58:00+08@China-Shanghai+08
Design: Java Language Feature: Exception
*/

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;

public class Java_Exception {
    static public class CustomException extends Exception {
        public CustomException() {
            super();
        }
        public CustomException(String message) {
            super(message);
        }
        public CustomException(Throwable throwable) {
            super(throwable);
        }
    }
    static public class CustomRunnable implements Runnable {
        @Override
        public void run() {
            int lhs = 5;
            int rhs = 0;
            int res = lhs / rhs;
        }
    }

    static public void main(String[] args) {
        // _finally();
        // _try();
        _Thread();
    }
    static public void _finally() {
        FileInputStream file = null;
        try {
            file = new FileInputStream("none.txt");
        } catch(IOException exception) {
            System.out.println(exception.getMessage());
            exception.printStackTrace();
            return;
            // System.exit(0);
        } finally {
            System.out.println("finally");
            if(file != null) {
                try {
                    file.close();
                } catch(IOException exception) {
                    exception.printStackTrace();
                }
            }
        }
    }
    static public void _try() {
        try(
            BufferedReader reader = new BufferedReader(new FileReader("src/Java_Exception.java"));
        ) {
            System.out.println(reader.readLine());
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _Thread() {
        new Thread(new CustomRunnable()).start();
        try {
            for (int i = 0; i < 10000; i += 1) {
                System.out.println(i);
                Thread.sleep(500);
            }
        } catch (InterruptedException exception) {
            exception.printStackTrace();
        }
    }
}
