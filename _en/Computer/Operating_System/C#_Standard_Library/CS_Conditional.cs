/* CS_Conditional.cs
Author: BSS9395
Update: 2022-05-20T16:33:00+08@China-Shanghai+08
Design: C# Attribute: Conditional
*/

//#define Debug

using System;
using System.Diagnostics;

class CS_Conditional {
    public static void Main(string[] args) {
        _Conditional("before");
        Console.WriteLine("in Main()");
        _Conditional("after");
    }

    [Conditional("Debug")]
    public static void _Conditional(String record) {
        Console.WriteLine($"{record}");
    }
}
