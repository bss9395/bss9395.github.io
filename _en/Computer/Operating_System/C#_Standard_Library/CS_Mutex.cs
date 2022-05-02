/* CS_Mutex.cs
Author: BSS9395
Update: 2022-05-02T11:12:00+08@China-Shanghai+08
Design: C# Standard Library: Mutex
*/

using System;
using System.Threading;

class CS_Mutex {
    public Mutex mutex = new Mutex();
    public static void Main(string[] args) {
        _Mutex();
    }
    public static void _Mutex() {
        CS_Mutex cs_mutex = new CS_Mutex();
        ThreadStart start_even = new ThreadStart(cs_mutex._Print_Even);
        Thread thread_even = new Thread(start_even);
        ThreadStart start_odd = new ThreadStart(cs_mutex._Print_Odd);
        Thread thread_odd = new Thread(start_odd);
        thread_even.Name = "_Print_Even";
        thread_odd.Name = "_Print_Odd";
        thread_even.Start();
        thread_odd.Start();
    }
    public void _Print_Even() {
        if (mutex.WaitOne() == true) {
            try {
                for (int i = 0; i <= 10; i += 2) {
                    Console.WriteLine("{0}:{1}", Thread.CurrentThread, i);
                }
            } finally {
                mutex.ReleaseMutex();
            }
        }
    }
    public void _Print_Odd() {
        if (mutex.WaitOne() == true) {
            try {
                for (int i = 1; i <= 10; i += 2) {
                    Console.WriteLine("{0}:{1}", Thread.CurrentThread, i);
                }
            } finally {
                mutex.ReleaseMutex();
            }
        }
    }
}
