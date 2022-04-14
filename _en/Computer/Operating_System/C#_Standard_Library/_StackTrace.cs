/* _StackTrace.cs
Author: BSS9395
Update: 2022-04-14T23:11:00+08@China-Shanghai+08
Design: C# Standard Library: StackTrace
Encode: UTF-8
*/

using System;
using System.Diagnostics;

class _StackTrace {
    static void Main(string[] args) {
        Stack();
    }

    static void Stack() {
        StackFrame frame = new StackTrace(true).GetFrame(0);
        Console.WriteLine("Filename: {0}", frame.GetFileName());
        Console.WriteLine("Line: {0}", frame.GetFileLineNumber());
        Console.WriteLine("Function: {0}", frame.GetMethod().Name);
    }
}
