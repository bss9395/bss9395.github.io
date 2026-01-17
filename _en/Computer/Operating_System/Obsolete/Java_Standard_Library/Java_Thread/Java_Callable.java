/* Java_Callable.java
Author: BSS9395
Update: 2023-02-14T20:25:00+08@China-Shanghai+08
Design: Java Standard Library: Callable
*/

import java.util.concurrent.Callable;
import java.util.concurrent.FutureTask;

public class Java_Callable implements Callable<Integer> {
    public int _count = 0;
    @Override
    public Integer call()
        throws Exception {
        while(_count < 100) {
            System.out.printf("%s: %s%n", _count, Thread.currentThread().getName());
            _count += 1;
        }
        return _count;
    }

    static public void main(String[] args) {
        _Callable();
    }
    static public void _Callable() {
        FutureTask<Integer> task = new FutureTask<Integer>(new Java_Callable());
        for(int i = 0; i < 100; i += 1) {
            System.out.printf("%s: %s%n", i, Thread.currentThread().getName());
            if(i == 20) {
                new Thread(task, "Thread-0").start();
            }
        }

        try {
            System.out.printf("task.get() = %02d%n", task.get());
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
}
