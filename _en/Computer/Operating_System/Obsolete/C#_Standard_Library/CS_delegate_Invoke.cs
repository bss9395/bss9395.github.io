/* CS_delegate_Invoke.cs
Author: BSS9395
Update: 2022-06-04T11:53:00+08@China-Shanghai+08
Design: C# Standard Library: delegate.BeginInvoke(), delegate.EndInvoke()
*/

using System;
using System.Runtime.Remoting.Messaging;
using System.Threading;

class CS_delegate_Invoke {
    public static void Main(String[] args) {
        // _Invoke();
        _Invoke_Callback();
    }
    public static void _Invoke() {
        Dele dele = _Prime;
        Console.WriteLine("before BeginInvoke()");
        int number = 109;
        IAsyncResult result = dele.BeginInvoke(number, null, null);
        Console.WriteLine("after  BeginInvole()");
        Console.WriteLine("before EndInvoke()");
        bool is_prime = dele.EndInvoke(result);
        Console.WriteLine("after EndInvoke(): {0} {1} a prime.", number, is_prime ? "is" : "is not");
    }
    public static void _Invoke_Callback() {
        Dele dele = new Dele(_Prime);
        Console.WriteLine("before BeginInvoke()");
        int number = 109;
        dele.BeginInvoke(number, new AsyncCallback(_Callback), null);
        Console.WriteLine("after  BeginInvole()");
        Thread.Sleep(500);      // note: avoid quitting the main thread.
    }
    delegate bool Dele(int number);
    public static bool _Prime(int number) {
        int sqrt = (int)Math.Sqrt(number);
        for (int i = 2; i <= sqrt; i += 1) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
    public static void _Callback(IAsyncResult result) {
        Console.WriteLine("in _Callback()");
        Dele dele = (Dele)((AsyncResult)result).AsyncDelegate;
        bool is_prime = dele.EndInvoke(result);
        Console.WriteLine("after EndInvoke(): {0} a prime", is_prime ? "is" : "is not");
    }
}
