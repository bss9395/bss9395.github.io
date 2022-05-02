/* CS_lock.cs
Author: BSS9395
Update: 2022-05-02T11:12:00+08@China-Shanghai+08
Design: C# Keyword: lock
*/

using System;
using System.Threading;

class CS_lock {
    public static void Main(string[] args) {
        _lock();
    }
    public static void _lock() {
        CS_lock cs_lock = new CS_lock();
        ThreadStart start_even = new ThreadStart(cs_lock._Print_Even);
        Thread thread_even = new Thread(start_even);
        ThreadStart start_odd = new ThreadStart(cs_lock._Print_Odd);
        Thread thread_odd = new Thread(start_odd);
        thread_even.Name = "_Print_Even";
        thread_odd.Name = "_Print_Odd";
        thread_even.Start();
        thread_odd.Start();
    }
    public void _Print_Even() {
        lock (this) {
            for (int i = 0; i <= 10; i += 2) {
                Console.WriteLine("{0}:{1}", Thread.CurrentThread.Name, i);
            }
        }
    }
    public void _Print_Odd() {
        lock (this) {
            for (int i = 1; i <= 10; i += 2) {
                Console.WriteLine("{0}:{1}", Thread.CurrentThread.Name, i);
            }
        }
    }
}
