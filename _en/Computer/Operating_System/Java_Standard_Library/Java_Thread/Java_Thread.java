/* Java_Thread.java
Author: BSS9395
Update: 2023-02-13T22:26:00+08@China-Shanghai+08
Design: Java Standard Library: Thread
*/

public class Java_Thread extends Thread {
    public int _count = 0;
    @Override
    public void run() {
        while(_count < 100) {
            System.out.printf("%02d: %02d: %s%n", _count, Thread.currentThread().getPriority(), Thread.currentThread().getName());
            _count += 1;
        }
    }

    static public void main(String[] args) {
        // _Thread();
        // _Thread_join();
        // _Thread_daemon();
        _Thread_Priority();
    }
    static public void _Thread() {
        for (int i = 0; i < 100; i += 1) {
            System.out.printf("%s: %s%n", i, Thread.currentThread().getName());
            if (i == 20) {
                new Java_Thread().start();
                new Java_Thread().start();
            }
        }
    }
    static public void _Thread_join() {
        try {
            for (int i = 0; i < 100; i += 1) {
                System.out.printf("%s: %s%n", i, Thread.currentThread().getName());
                if (i == 20) {
                    new Java_Thread().start();
                    Java_Thread thread = new Java_Thread();
                    thread.start();
                    thread.join();
                }
            }
        } catch(InterruptedException exception) {
            exception.printStackTrace();
        }
    }
    static public void _Thread_daemon() {
        for (int i = 0; i < 100; i += 1) {
            System.out.printf("%s: %s%n", i, Thread.currentThread().getName());
            if (i == 2) {
                Java_Thread thread = new Java_Thread();
                thread.setDaemon(true);
                thread.start();
            }
        }
    }
    static public void _Thread_Priority() {
        Thread.currentThread().setPriority(7);
        for(int i = 0; i < 30; i += 1) {
            if(i == 10) {
                Java_Thread thread = new Java_Thread();
                thread.setName("Low");
                thread.start();
                System.out.printf("thread.getPriority() = %02d%n", thread.getPriority());
                thread.setPriority(1);
            } else if(i == 20) {
                Java_Thread thread = new Java_Thread();
                thread.setName("High");
                thread.start();
                System.out.printf("thread.getPriority() = %02d%n", thread.getPriority());
                thread.setPriority(10);
            }
        }
    }
}
