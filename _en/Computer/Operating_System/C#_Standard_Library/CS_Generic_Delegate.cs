/* CS_Generic_Delegate.cs
Author: BSS9395
Update: 2022-05-31T21:35:00+08@China-Shanghai+08
Design: C# Language Feature: Generic Delegate
*/

using System;

class CS_Generic_Delegate {
    class Datum {
        public static String _Print(double t1, int t2) {
            return (t1 + t2).ToString();
        }
    }
    delegate TR Dele<T1, T2, TR>(T1 t1, T2 t2);

    public static void Main(String[] args) {
        var dele = new Dele<double, int, String>(Datum._Print);
        Console.WriteLine($"{dele(1.2, 34)}");
    }
}
