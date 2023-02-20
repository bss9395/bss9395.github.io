/* Java_lock.java
Author: BSS9395
Update: 2023-02-15T21:40:00+08@China-Shanghai+08
Design: Java Language Feature: synchronized()
*/

import java.util.concurrent.locks.ReentrantLock;

public class Java_lock {
    static public class Account {
        private ReentrantLock _lock = new ReentrantLock();
        private String _id = "";
        private double _balance = 0.0;
        public Account(String id, double balance) {
            _id = id;
            _balance = balance;
        }

        public void _Draw(double amount) {
            if(amount <= _balance) {
                try {
                    Thread.sleep(1);
                } catch(InterruptedException exception) {
                    exception.printStackTrace();
                }
                double balance = _balance;
                _balance = _balance - amount;
                System.out.printf("%s: %f - %f = %f%n", Thread.currentThread().getName(), balance, amount, _balance);
            } else {
                System.out.printf("%s: balance = %f%n", Thread.currentThread().getName(), _balance);
            }
        }

        public void _synchronized(double amount) {
            synchronized (this) {
                if(amount <= _balance) {
//                    try {
//                        Thread.sleep(1);
//                    } catch(InterruptedException exception) {
//                        exception.printStackTrace();
//                    }
                    double balance = _balance;
                    _balance = balance - amount;
                    System.out.printf("%s: %f - %f = %f%n", Thread.currentThread().getName(), balance, amount, _balance);
                } else {
                    System.out.printf("%s: balance = %f%n", Thread.currentThread().getName(), _balance);
                }
            }
        }

        synchronized public void _synchronized_this(double amount) {
            if(amount <= _balance) {
                try {
                    Thread.sleep(1);
                } catch(InterruptedException exception) {
                    exception.printStackTrace();
                }
                double balance = _balance;
                _balance = balance - amount;
                System.out.printf("%s: %f - %f = %f%n", Thread.currentThread().getName(), balance, amount, _balance);
            } else {
                System.out.printf("%s: balance = %f%n", Thread.currentThread().getName(), _balance);
            }
        }

        public void _ReentrantLock(double amount) {
            _lock.lock();
            try {
                if(amount <= _balance) {
                    try {
                        Thread.sleep(1);
                    } catch(InterruptedException exception) {
                        exception.printStackTrace();
                    }
                    double balance = _balance;
                    _balance = _balance - amount;
                    System.out.printf("%s: %f - %f = %f%n", Thread.currentThread().getName(), balance, amount, _balance);
                } else {
                    System.out.printf("%s: balance = %f%n", Thread.currentThread().getName(), _balance);
                }
            } finally {
                _lock.unlock();
            }
        }
    }

    static public class Java_Draw extends Thread {
        private Account _account;
        private double _amount;

        public Java_Draw(String name, Account account, double amount) {
            super(name);
            _account = account;
            _amount = amount;
        }

        @Override
        public void run() {
            _account._Draw(_amount);
        }
    }

    static public class Java_synchronized extends Thread {
        private Account _account;
        private double _amount;
        public Java_synchronized(String name, Account account, double amount) {
            super(name);
            _account = account;
            _amount = amount;
        }
        @Override
        public void run() {
            _account._synchronized(_amount);
        }
    }

    static public class Java_synchronized_this extends Thread {
        private Account _account;
        private double _amount;
        public Java_synchronized_this(String name, Account account, double amount) {
            super(name);
            _account = account;
            _amount = amount;
        }
        @Override
        public void run() {
            _account._synchronized(_amount);
        }
    }

    static public class Java_ReentrantLock extends Thread {
        private Account _account;
        private double _amount;
        public Java_ReentrantLock(String name, Account account, double amount) {
            super(name);
            _account = account;
            _amount = amount;
        }
        @Override
        public void run() {
            _account._ReentrantLock(_amount);
        }

    }


    static public void main(String[] args) {
        // _Draw();
        _synchronized();
        // _synchronized_this();
        // _ReentrantLock();
    }
    static public void _Draw() {
        Account account = new Account("1156", 1156);
        new Java_Draw("Thread-0", account, 1000).start();
        new Java_Draw("Thread-1", account, 1000).start();
    }
    static public void _synchronized() {
        Account account = new Account("1156", 1156);
        new Java_synchronized("Thread-0", account, 1000).start();
        new Java_synchronized("Thread-1", account, 1000).start();
        new Java_synchronized("Thread-2", account, 1000).start();
    }
    static public void _synchronized_this() {
        Account account = new Account("1156", 1156);
        new Java_synchronized("Thread-0", account, 1000).start();
        new Java_synchronized("Thread-1", account, 1000).start();
    }
    static public void _ReentrantLock() {
        Account account = new Account("1156", 1156);
        new Java_ReentrantLock("Thread-0", account, 1000).start();
        new Java_ReentrantLock("Thread-1", account, 1000).start();
    }
}
