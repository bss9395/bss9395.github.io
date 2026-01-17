/* Java_Thread_Daemon.java
Author: bss9395
Update: 2025-08-04T09:52:00+08@China-GuangDong-ZhanJiang+08
*/

public class Java_Thread_Daemon {
    public static void main(String[] args) throws InterruptedException {
        Thread userThread = new Thread(() -> {
            for(int x = 0; x < 10; x += 1) {
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println(Thread.currentThread().getName() + "正在运行，x = " + x);
            }
        }, "用户线程");
        Thread damonThread = new Thread(() -> {
            for(int x = 0; x < Integer.MAX_VALUE; x += 1) {
                try {
                    Thread.sleep(100);
                } catch(InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println(Thread.currentThread().getName() + "正在运行，x = " + x);
            }
        }, "守护线程");
        damonThread.setDaemon(true);
        userThread.start();
        damonThread.start();
    }
}
