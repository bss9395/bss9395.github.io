/* CS_Timer.cs
Author: BSS9395
Update: 2022-06-04T17:03:00+08@China-Shanghai+08
Design: C# Standard Library: Timer
*/

using System;
using System.Threading;

class CS_Timer {
    public static void Main(String[] args) {
        _Timer();
    }
    public static void _Timer() {
        CS_Timer cs_timer = new CS_Timer();
        Timer timer = new Timer(cs_timer._Callback, "callback", 2000, 1000);
        Console.WriteLine("timer started");
        Console.ReadLine();                  // note: avoid quitting the main thread.
    }
    public int _count = 0;
    public void _Callback(Object income) {
        _count += 1;
        Console.WriteLine($"{income}: _count == {_count}");
    }
}
