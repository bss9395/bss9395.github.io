/* Java_Dead_Lock.java
Author: BSS9395
Update: 2023-02-17T22:47:00+08@China-Shanghai+08
Design: Java Dead Lock
*/

public class Java_Dead_Lock {
    static class A {
        synchronized public void _Lock_A_0(B b)
            throws InterruptedException {
            System.out.printf("Enter %s%n", "_Lock_A_0");
            Thread.sleep(200);
            System.out.printf("To Enter %s%n", "_Lock_B_1");
            b._Lock_B_1();
        }
        synchronized public void _Lock_A_1() {
            System.out.printf("Enter %s%n", "_Lock_A_1");
        }
    }
    static class B {
        synchronized public void _Lock_B_0(A a)
            throws InterruptedException {
            System.out.printf("Enter %s%n", "_Lock_B_0");
            Thread.sleep(200);
            System.out.printf("To Enter %s%n", "_Lock_A_1");
            a._Lock_A_1();
        }
        synchronized public void _Lock_B_1() {
            System.out.printf("Enter %s%n", "_Lock_B_1");
        }
    }

    static class Thread_A extends Thread {
        private A _a = null;
        private B _b = null;
        public Thread_A(A a, B b) {
            _a = a;
            _b = b;
        }
        @Override
        public void run() {
            try {
                _a._Lock_A_0(_b);
            } catch (InterruptedException exception) {
                exception.printStackTrace();
            }
        }
    }

    static class Thread_B extends Thread {
        private A _a = null;
        private B _b = null;
        public Thread_B(A a, B b) {
            _a = a;
            _b = b;
        }
        @Override
        public void run() {
            try {
                _b._Lock_B_0(_a);
            } catch (InterruptedException exception) {
                exception.printStackTrace();
            }
        }
    }

    static public void main(String[] args) {
        _Dead_Lock();
    }
    static public void _Dead_Lock() {
        A a = new A();
        B b = new B();
        new Thread_A(a, b).start();
        new Thread_B(a, b).start();
    }
}
