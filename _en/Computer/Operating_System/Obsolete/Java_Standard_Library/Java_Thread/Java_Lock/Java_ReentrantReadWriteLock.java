/* Java_ReentrantReadWriteLock.java
Author: BSS9395
Update: 2023-02-21T23:21:00+08@China-Shanghai+08
Design: Java Standard Library: ReentrantReadWriteLock
*/

import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class Java_ReentrantReadWriteLock {
    public ReadWriteLock _lock = new ReentrantReadWriteLock();
    public void _Task()
        throws InterruptedException {
        _lock.readLock().lock();
        long start = System.currentTimeMillis();
        for(int i = 0; i < 5; i += 1) {
            Thread.sleep(20);
            System.out.printf("%s: %02d%n", Thread.currentThread().getName(), i);
        }
        long end = System.currentTimeMillis();
        System.out.printf("%s: %d - %d == %dms%n", Thread.currentThread().getName(), end, start, end - start);
        _lock.readLock().unlock();
    }
    static class Read_Lock extends Thread {
        Java_ReentrantReadWriteLock _invoke = null;
        public Read_Lock(String name, Java_ReentrantReadWriteLock invoke) {
            super(name);
            _invoke = invoke;
        }

        @Override
        public void run() {
            try {
                _invoke._Task();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    static class Write_Lock extends Thread {
        ReadWriteLock _lock = null;
        public Write_Lock(ReadWriteLock lock) {
            _lock = lock;
        }
        @Override
        public void run() {
            _lock.writeLock().lock();
            System.out.printf("%s: %s%n", Thread.currentThread().getName(), "public void run() {");
            _lock.writeLock().unlock();
        }
    }

    static public void main(String[] args)
        throws InterruptedException {
        // _ReentrantReadWriteLock();
        // _Read_Write();
        // _Write_Read();
        _Read();
    }
    static public void _ReentrantReadWriteLock() {
        ReadWriteLock lock = new ReentrantReadWriteLock();
        Thread thread = new Write_Lock(lock);

        lock.writeLock().lock();
        lock.writeLock().lock();
        thread.start();
        System.out.println("thread.start();");
        lock.writeLock().unlock();
        lock.writeLock().unlock();
    }
    static public void _Read_Write() {
        ReadWriteLock lock = new ReentrantReadWriteLock();

        lock.readLock().lock();
        System.out.println("lock.readLock().lock();");
        lock.writeLock().lock();    // Dead Lock
        System.out.println("lock.writeLock().lock();");
        lock.writeLock().unlock();
        System.out.println("lock.writeLock().unlock();");
        lock.readLock().unlock();
        System.out.println("lock.readLock().unlock();");
    }
    static public void _Write_Read() {
        ReadWriteLock lock = new ReentrantReadWriteLock();

        lock.writeLock().lock();
        System.out.println("lock.writeLock().lock();");
        lock.readLock().lock();
        System.out.println("lock.readLock().lock();");
        lock.readLock().unlock();
        System.out.println("lock.readLock().unlock();");
        lock.writeLock().unlock();
        System.out.println("lock.writeLock().unlock();");
    }
    static public void _Read()
        throws InterruptedException {
        Java_ReentrantReadWriteLock invoke = new Java_ReentrantReadWriteLock();
        Thread thread_0 = new Read_Lock("Thread-0", invoke);
        Thread thread_1 = new Read_Lock("Thread-1", invoke);
        Thread thread_2 = new Read_Lock("Thread-2", invoke);

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