/* Java_Mutex.java
Author: BSS9395
Update: 2025-08-04T13:13:00+08@China-GuangDong-ZhanJiang+08
*/

class Mutex {
    @FunctionalInterface
    interface ILambda<Type_> {
        public void _Call();
    }

    volatile public boolean _state = false;
    public void _Lock(ILambda lambda) {
        while(_state) {
            ;
        }
        _state = true;

        try {
            System.out.println("beg lambda");
            lambda._Call();
        } finally {
            _state = false;
            System.out.println("end lambda");
        }
    }
}

public class Java_Mutex {
    static public class Account {
        Mutex _mutex = new Mutex();
        private double _balance = 0.0;
        public Account(double balance) {
            _balance = balance;
        }

        public void _Draw(double amount) {
            _mutex._Lock(() -> {
                if((amount <= _balance) == false) {
                    return;
                }
                double balance = _balance;
                _balance = _balance - amount;
                System.out.printf("%s: %f - %f = %f%n", Thread.currentThread().getName(), balance, amount, _balance);
            });
        }

        public void _Deposit(double amount) {
            _mutex._Lock(() -> {
                double balance = _balance;
                _balance = _balance + amount;
                System.out.printf("%s: %f + %f = %f%n", Thread.currentThread().getName(), balance, amount, _balance);
            });
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
                    Thread.sleep(1);  // synchronized性能逊于ReentrantLock
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
                    Thread.sleep(1);  // synchronized性能逊于ReentrantLock
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    static public void main(String[] args) throws InterruptedException {
        Account account = new Account(0);
        new Java_Deposit("Deposit-0", account, 800).start();
        // Thread.sleep(1000);
        new Java_Draw   ("Draw-0   ", account, 800).start();
        //new Java_Deposit("Deposit-1", account, 800).start();
        //new Java_Draw   ("Draw-1   ", account, 800).start();
    }
}
