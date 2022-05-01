/* CS_Thread.cs
Author: BSS9395
Update: 2022-05-01T22:14:00+08@China-Shanghai+08
Design: C# Standard Library: Thread
*/

using System;
using System.Threading;

class CS_Thread {
    class Parameter {
        public int _begin = 0;
        public int _end = 0;
        public Parameter(int begin, int end) {
            _begin = begin;
            _end = end;
        }
    }
    public static void Main(string[] args) {
        // _ThreadStart();
        // _ParameterizedThreadStart();
        _ParameterizedThreadStart_Object();
    }
    public static void _ThreadStart() {
        ThreadStart start_even = new ThreadStart(_Print_Even);
        Thread thread_even = new Thread(start_even);
        ThreadStart start_odd = new ThreadStart(_Print_Odd);
        Thread thread_odd = new Thread(start_odd);
        thread_even.Start();
        thread_odd.Start();
    }
    public static void _ParameterizedThreadStart() {
        ParameterizedThreadStart start_even = new ParameterizedThreadStart(_Print_Even);
        Thread thread_even = new Thread(start_even);
        ParameterizedThreadStart start_odd = new ParameterizedThreadStart(_Print_Odd);
        Thread thread_odd = new Thread(start_odd);
        thread_even.Start(12);
        thread_odd.Start(12);
    }
    public static void _ParameterizedThreadStart_Object() {
        ParameterizedThreadStart start_even = new ParameterizedThreadStart(_Print_Even_Object);
        Thread thread_even = new Thread(start_even);
        ParameterizedThreadStart start_odd = new ParameterizedThreadStart(_Print_Odd_Object);
        Thread thread_odd = new Thread(start_odd);
        Parameter parameter = new Parameter(0, 122);
        thread_even.Start(parameter);
        thread_odd.Start(parameter);
    }
    public static void _Print_Even() {
        Console.WriteLine("public static void _Print_Even() {");
        for (int i = 0; i <= 10; i += 2) {
            Console.WriteLine(i);
        }
    }
    public static void _Print_Odd() {
        Console.WriteLine("public static void _Print_Odd() {");
        for (int i = 1; i <= 10; i += 2) {
            Console.WriteLine(i);
        }
    }
    public static void _Print_Even(object max) {
        Console.WriteLine("public static void _Print_Even(object max) {");
        for (int i = 0; i <= (int)max; i += 2) {
            Console.WriteLine(i);
        }
    }
    public static void _Print_Odd(object max) {
        Console.WriteLine("public static void _Print_Odd(object max) {");
        for (int i = 1; i <= (int)max; i += 2) {
            Console.WriteLine(i);
        }
    }
    public static void _Print_Even_Object(object obj) {
        Console.WriteLine("public static void _Print_Even_Object(object obj) {");
        Parameter parameter = (Parameter)obj;
        if (parameter == null) {
            return;
        }
        for (int i = parameter._begin / 2 * 2; i < parameter._end; i += 2) {
            Console.WriteLine(i);
        }
    }
    public static void _Print_Odd_Object(object obj) {
        Console.WriteLine("public static void _Print_Odd_Object(object obj) {");
        Parameter parameter = (Parameter)obj;
        if (parameter == null) {
            return;
        }
        for (int i = parameter._begin / 2 * 2 + 1; i < parameter._end; i += 2) {
            Console.WriteLine(i);
        }
    }
}
