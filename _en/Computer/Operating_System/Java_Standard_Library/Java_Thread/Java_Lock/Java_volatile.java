/* Java_volatile.java
Author: BSS9395
Update: 2025-08-04T13:13:00+08@China-GuangDong-ZhanJiang+08
*/

public class Java_volatile {
    static public void main(String[] args) {
        _Test_volatile();
    }

    static private volatile boolean _is_locked = false;
    static public void _Critical_Area(String threadName) {
        // 尝试获取锁
        while (_is_locked) {
            // 等待锁释放
        }
        // 获取到锁，设置为锁定状态
        _is_locked = true;
        try {
            System.out.println(threadName + " has entered the critical section.");
            // 模拟临界区的操作
            // 模拟临界区的操作
        } finally {
            // 释放锁
            _is_locked = false;
            System.out.println(threadName + " has left the critical section.");
        }
    }
    static public void _Test_volatile() {
        Thread thread1 = new Thread(() -> _Critical_Area("Thread 1"));
        Thread thread2 = new Thread(() -> _Critical_Area("Thread 2"));
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
