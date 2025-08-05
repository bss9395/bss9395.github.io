/* Java_Condition.java
Author: BSS9395
Update: 2023-02-18T21:18:00+08@China-Shanghai+08
Design: Java Standard Library: Condition
*/

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Java_Condition {
    static public class Account {
        private Lock _lock = new ReentrantLock();
        private Condition _condition = _lock.newCondition();

        private String _id = "";
        private double _balance = 0.0;
        public Account(String id, double balance) {
            _id = id;
            _balance = balance;
        }

        public void _Deposit(double amount)
                throws InterruptedException {
            _lock.lock();
            try {
                double balance = _balance;
                _balance = _balance + amount;
                System.out.printf("%s: %f + %f = %f%n", Thread.currentThread().getName(), balance, amount, _balance);
                _condition.signalAll();
            } finally {
                _lock.unlock();
            }
        }

        public void _Draw(double amount)
                throws InterruptedException {
            _lock.lock();
            try {
                while((amount <= _balance) == false) {
                    _condition.await();
                }
                double balance = _balance;
                _balance = _balance - amount;
                System.out.printf("%s: %f - %f = %f%n", Thread.currentThread().getName(), balance, amount, _balance);
            } finally {
                _lock.unlock();
            }
        }
    }

    static public class Java_Deposit extends Thread {
        private Account _account;
        private double _amount;
        public Java_Deposit(String name, Account account, double amount) {
            super(name);
            _account = account;
            _amount = amount;
        }
        @Override
        public void run() {
            try {
                for(int i = 0; i < 100; i += 1) {
                    _account._Deposit(_amount);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
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
            try {
                for(int i = 0; i < 100; i += 1) {
                    _account._Draw(_amount);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    static public void main(String[] args) {
        _Draw_Deposit();
    }
    static public void _Draw_Deposit() {
        Account account = new Account("1156", 0);
        new Java_Draw   ("Draw-0   ", account, 800).start();
        new Java_Deposit("Deposit-0", account, 800).start();
        new Java_Draw   ("Draw-1   ", account, 800).start();
        new Java_Deposit("Deposit-1", account, 800).start();
    }
}
