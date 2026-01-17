/* Java_Runnable.java
Author: BSS9395
Update: 2023-02-14T19:51:00+08@China-Shanghai+08
Design: Java Standard Library: Runnable
*/

public class Java_Runnable implements Runnable {
    public int _count = 0;
    @Override
    public void run() {
        while(_count < 100) {
            System.out.printf("%s: %s%n", _count, Thread.currentThread().getName());
            _count += 1;
        }
    }
    static public void main(String[] args) {
        for(int i = 0; i < 100; i += 1) {
            System.out.printf("%s: %s\n", i, Thread.currentThread().getName());
            if(i == 20) {
                Java_Runnable runnable = new Java_Runnable();
                new Thread(runnable, "Thread_0").start();
                new Thread(runnable, "Thread_1").start();
            }
        }
    }
}
