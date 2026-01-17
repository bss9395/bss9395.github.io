/* Java_ThreadGroup.java
Author: BSS9395
Update: 2023-02-19T16:38:00+08@China-Shanghai+08
Design: Java Standard Library: ThreadGroup
*/

public class Java_ThreadGroup {
    static public class Java_Thread extends Thread {
        public Java_Thread(String name) {
            super(name);
        }
        public Java_Thread(ThreadGroup group, String name) {
            super(group, name);
        }

        @Override
        public void run() {
            for(int i = 0; i < 20; i += 1) {
                System.out.printf("%7s: %s: %02d%n", Thread.currentThread().getThreadGroup().getName(), Thread.currentThread().getName(), i);
            }
        }
    }

    static public class ExceptionHandler implements Thread.UncaughtExceptionHandler {
        @Override
        public void uncaughtException(Thread thread, Throwable throwable) {
            System.err.printf("%s: %s%n", thread.getName(), throwable);
        }
    }

    static public void main(String[] args) {
        // _ThreadGroup();
        _UncaughtExceptionHandler();
    }
    static public void _ThreadGroup() {
        new Java_Thread("thread-0").start();
        ThreadGroup group = new ThreadGroup("group-0");
        new Java_Thread(group, "thread-1").start();
        new Java_Thread(group, "thread-2").start();
    }
    static public void _UncaughtExceptionHandler() {
        Thread.currentThread().setUncaughtExceptionHandler(new ExceptionHandler());
        double res = 5 / 0;
        System.out.printf("At the end.%n");
    }
}
