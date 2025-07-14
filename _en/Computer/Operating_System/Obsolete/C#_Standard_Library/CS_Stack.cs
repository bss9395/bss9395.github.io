/* CS_Stack.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Standary Library: Stack
*/

using System;
using System.Collections;
using System.Diagnostics;

class CS_Stack {
    public static void Main(string[] args) {
        // _Push();
        _Pop();
    }
    public static void _Push() {
        Stack stack = new Stack();
        stack.Push("abc");
        stack.Push("def");
        stack.Push("ghi");
        while (0 < stack.Count) {
            Console.Write("{0} ", stack.Pop());
        }
        Console.WriteLine();
    }
    public static void _Pop() {
        Stack stack = new Stack();
        stack.Push("abc");
        stack.Push("def");
        stack.Push("ghi");
        while (0 < stack.Count) {
            Console.Write("{0} ", stack.Pop());
        }
        Console.WriteLine();
    }
}

