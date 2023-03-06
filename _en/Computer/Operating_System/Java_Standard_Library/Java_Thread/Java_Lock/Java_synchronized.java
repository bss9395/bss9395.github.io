/* Java_synchronized.java
Author: BSS9395
Update: 2023-02-22T21:36:00+08@China-Shanghai+08
Design: Java Keyword: synchronized
*/

public class Java_synchronized {
    synchronized public void _Task()
        throws InterruptedException {
        long start = System.currentTimeMillis();
        for(int i = 0; i < 5; i += 1) {
            Thread.sleep(20);
            System.out.printf("%s: %02d%n", Thread.currentThread().getName(), i);
        }
        long end = System.currentTimeMillis();
        System.out.printf("%s: %d - %d == %dms%n", Thread.currentThread().getName(), end, start, end - start);
    }
    static class Exclusive extends Thread {
        private Java_synchronized _invoke = null;
        public Exclusive(String name, Java_synchronized object) {
            super(name);
            _invoke = object;
        }
        @Override
        public void run() {
            try {
                _invoke._Task();
            } catch (InterruptedException exception) {
                exception.printStackTrace();
            }
        }
    }

    static public void main(String[] args)
        throws InterruptedException {
        _synchronized();
    }
    static public void _synchronized()
        throws InterruptedException {
        Java_synchronized invoke = new Java_synchronized();
        Exclusive thread_0 = new Exclusive("Thread-0", invoke);
        Exclusive thread_1 = new Exclusive("Thread-1", invoke);
        Exclusive thread_2 = new Exclusive("Thread-2", invoke);

        long start = System.currentTimeMillis();
        thread_0.start();
        thread_1.start();
        thread_2.start();
        thread_0.join();
        thread_1.join();
        thread_2.join();
        long end = System.currentTimeMillis();
        System.out.printf("%s: %d - %d == %dms%n", Thread.currentThread().getName(), end, start, end - start);
    }
}