/* Java_Bank.java
Author: bss9395
Update: 2023-02-23T22:44:00+08@China-Shanghai+08
Design: Bank
*/

import java.util.Arrays;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Java_Bank {
    private Lock _lock = new ReentrantLock();
    private Condition _condition = _lock.newCondition();
    private double[] _accounts;
    public Java_Bank(int count, double balance) {
        _accounts = new double[count];
        Arrays.fill(_accounts, balance);
    }

    public void _Transfer(int to, int from, double amount) {
        try {
            _lock.lock();
            while(_accounts[from] < amount) {
                _condition.await();
            }
            System.out.printf("_account[%02d] == %07.2f, _account[%02d] == %07.2f, %s%n", to, _accounts[to], from, _accounts[from], Thread.currentThread().getName());
            _accounts[from] -= amount;
            _accounts[to] += amount;
            System.out.printf("_account[%02d] == %07.2f, _account[%02d] == %07.2f, amount == %07.2f, total == %f%n", to, _accounts[to], from, _accounts[from], amount, _Total());
            _condition.signalAll();
        } catch (InterruptedException exception) {
            exception.printStackTrace();
        } finally {
            _lock.unlock();
        }
    }
    public double _Total() {
        try {
            _lock.lock();
            double sum = 0.0;
            for(int i = 0; i < _accounts.length; i += 1) {
                sum += _accounts[i];
            }
            return sum;
        } finally {
            _lock.unlock();
        }
    }

    static public void main(String[] args) {
        int count = 100;
        int balance = 1000;
        Java_Bank bank = new Java_Bank(count, balance);
        for(int i = 0; i < count; i += 1) {
            final int from = i;
            new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        while(true) {
                            int to = (int) (count * Math.random());
                            double amount = balance * 3 * Math.random();
                            bank._Transfer(to, from, amount);
                            Thread.sleep((int)(10 * Math.random()));
                        }
                    } catch (InterruptedException exception) {
                        exception.printStackTrace();
                    }
                }
            }).start();
        }
    }
}
