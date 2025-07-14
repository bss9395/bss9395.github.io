/* CS_Monitor.cs
Author: BSS9395
Update: 2022-05-02T11:12:00+08@China-Shanghai+08
Design: C# Standard Library: Monitor
*/

using System;
using System.Threading;

class CS_Monitor {
    public static void Main(string[] args) {
        _Monitor();
    }
    public static void _Monitor() {
        CS_Monitor cs_monitor = new CS_Monitor();
        ThreadStart start_even = new ThreadStart(cs_monitor._Print_Even);
        Thread thread_even = new Thread(start_even);
        ThreadStart start_odd = new ThreadStart(cs_monitor._Print_Odd);
        Thread thread_odd = new Thread(start_odd);
        thread_even.Name = "_Print_Even";
        thread_odd.Name = "_Print_Odd";
        thread_even.Start();
        thread_odd.Start();
    }
    public void _Print_Even() {
        Monitor.Enter(this);
        try {
            for (int i = 0; i <= 500000; i += 2) {
                Console.WriteLine("{0}:{1}", Thread.CurrentThread.Name, i);
            }
        } finally {
            Monitor.Exit(this);
        }
    }
    public void _Print_Odd() {
        Monitor.TryEnter(this, 1);  // note: this is of no use.
        try {
            for (int i = 1; i <= 50000; i += 2) {
                Console.WriteLine("{0}:{1}", Thread.CurrentThread.Name, i);
            }
        } finally {
            Monitor.Exit(this);
        }
    }
}
