/* Java_Producer_Consumer.java
Author: BSS9395
Update: 2023-02-18T19:30:00+08@China-Shanghai+08
Design: Producer-Consumer
*/

public class Java_Producer_Consumer {
    static public class Account {
        private String _id = "";
        private double _balance = 0.0;
        public Account(String id, double balance) {
            _id = id;
            _balance = balance;
        }

        synchronized public void _Draw(double amount)
            throws InterruptedException {
            if (amount <= _balance) {
                double balance = _balance;
                _balance = _balance - amount;
                System.out.printf("%s: %f - %f = %f%n", Thread.currentThread().getName(), balance, amount, _balance);
                notifyAll();
            } else {
                wait();
            }
        }

        synchronized public void _Deposit(double amount)
            throws InterruptedException {
            if(_balance < amount) {
                double balance = _balance;
                _balance = _balance + amount;
                System.out.printf("%s: %f + %f = %f%n", Thread.currentThread().getName(), balance, amount, _balance);
                notifyAll();
            } else {
                wait();
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

    static public void main(String[] args) {
        _Draw_Deposit();
    }
    static public void _Draw_Deposit() {
        Account account = new Account("1156", 0);
        new Java_Draw   ("Draw-0   ", account, 800).start();
        new Java_Draw   ("Draw-1   ", account, 800).start();
        new Java_Deposit("Deposit-0", account, 800).start();
        new Java_Deposit("Deposit-1", account, 800).start();
        new Java_Deposit("Deposit-2", account, 800).start();
    }
}
