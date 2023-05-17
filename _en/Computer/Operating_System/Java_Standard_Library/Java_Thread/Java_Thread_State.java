/* Java_Thread_State.java
Author: BSS9395
Update: 2023-05-16T21:43:00+08@China-Guangdong-Zhanjiang+08
Design: Java Standard Library: Thread
*/

public class Java_Thread_State {
    static public void main(String[] args) throws InterruptedException {
        // _sleep();
        _suspend();
        // _wait();
        // _stop();
    }

    static public void _sleep() throws InterruptedException {
        Object lock = new Object();
        new Thread() {
            @Override
            public void run() {
                synchronized(lock) {
                    System.out.printf("begin %s%n", Thread.currentThread().getName());
                    try {
                        Thread.sleep(3000);  // note: don't release current lock, and idle current thread.
                    } catch (InterruptedException event) {
                        event.printStackTrace();
                    }
                }
                System.out.printf("end %s%n", Thread.currentThread().getName());
            }
        }.start();
        Thread.sleep(1000);
        System.out.printf("begin %s%n", Thread.currentThread().getName());
        synchronized (lock) {
            System.out.printf("end %s%n", Thread.currentThread().getName());
        }
    }

    static public void _suspend() throws InterruptedException {
        Object lock = new Object();
        Thread thread = new Thread() {
            @Override
            public void run() {
                synchronized (lock) {
                    try {
                        System.out.printf("begin %s%n", Thread.currentThread().getName());
                        Thread.currentThread().suspend(); // note: don't release current lock, and transfer current thread to blocked state.
                        Thread.sleep(3000);
                        System.out.printf("end %s%n", Thread.currentThread().getName());
                    } catch (Exception exception) {
                        exception.printStackTrace();
                    }
                }
            }
        };
        thread.start();
        Thread.sleep(1000);
        System.out.printf("getState()=%s, %s%n", thread.getState(), thread.getName());
        thread.resume();
        synchronized (lock) {
            System.out.printf("begin %s%n", Thread.currentThread().getName());
        }
        System.out.printf("end %s%n", Thread.currentThread().getName());
    }

    static public void _wait() throws InterruptedException {
        Object lock = new Object();
        new Thread() {
            @Override
            public void run() {
                synchronized(lock) {
                    System.out.printf("begin %s%n", Thread.currentThread().getName());
                    try {
                        lock.wait(3000);  // note: release current lock, and transfer current thread to the waiting pool of the lock.
                    } catch (InterruptedException event) {
                        event.printStackTrace();
                    }
                }
                System.out.printf("end %s%n", Thread.currentThread().getName());
            }
        }.start();
        Thread.sleep(1000);
        System.out.printf("begin %s%n", Thread.currentThread().getName());
        synchronized (lock) {
            System.out.printf("end %s%n", Thread.currentThread().getName());
        }
    }

    static public void _stop() throws InterruptedException {
        Object lock = new Object();
        new Thread() {
            @Override
            public void run() {
                synchronized (lock) {
                    System.out.printf("begin %s%n", Thread.currentThread().getName());
                    try {
                        lock.wait(3000);
                        System.out.printf("end %s%n", Thread.currentThread().getName());
                    } catch (InterruptedException event) {
                        event.printStackTrace();
                    }
                }
            }
        }.start();
        Thread.sleep(1000);
        System.out.printf("begin %s%n", Thread.currentThread().getName());
        Thread.currentThread().stop();  // note: release current lock, and terminate current thread.
        synchronized (lock) {
            System.out.printf("end %s%n", Thread.currentThread().getName());
        }
    }
}

