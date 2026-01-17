/* Java_ThreadPool.java
Author: BSS9395
Update: 2023-02-19T17:44:00+08@China-Shanghai+08
Design: Java Standard Library: ThreadPool
*/

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Java_ThreadPool {
    static public void main(String[] args) {
        _ThreadPool();
    }
    static public void _ThreadPool() {
        ExecutorService pool = Executors.newFixedThreadPool(4);
        Runnable target = () -> {
            for(int i = 0; i < 100; i += 1) {
                System.out.printf("%s: %02d%n", Thread.currentThread().getName(), i);
            }
        };

        pool.submit(target);
        pool.submit(target);
        pool.submit(target);
        pool.shutdown();
    }
}
