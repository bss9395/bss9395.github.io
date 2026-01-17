/* Java_AtomicInteger.java
Author: BSS9395
Update: 2025-08-04T13:13:00+08@China-GuangDong-ZhanJiang+08
*/

import java.util.concurrent.atomic.AtomicInteger;

public class Java_AtomicInteger {
    public static void main(String[] args) {
        _Test_AtomicInteger();
    }

    private static final int UNLOCKED = 0;
    private static final int LOCKED = 1;
    private static final AtomicInteger lock = new AtomicInteger(UNLOCKED);
    public static void accessResource(String threadName) {
        // 尝试获取锁
        while (!lock.compareAndSet(UNLOCKED, LOCKED)) {
            // 等待锁释放
        }
        try {
            System.out.println(threadName + " has entered the critical section.");
            // 模拟临界区的操作
            // 模拟临界区的操作
        } finally {
            // 释放锁
            lock.set(UNLOCKED);
            System.out.println(threadName + " has left the critical section.");
        }
    }
    public static void _Test_AtomicInteger() {
        Thread thread1 = new Thread(() -> accessResource("Thread 1"));
        Thread thread2 = new Thread(() -> accessResource("Thread 2"));

        thread1.start();
        thread2.start();

        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}