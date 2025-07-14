/* CS_finally.cs
Author: BSS9395
Update: 2022-06-01T19:56:00+08@China-Shanghai+08
Design: C# Keyword: finally
*/

using System;

class CS_finally {

    public static void Main(String[] args) {
        try {
            _Level_1();
        } catch (DivideByZeroException) {
            Console.WriteLine("DivideByZeroException in Main()");
        } finally {
            Console.WriteLine("finally in Main()");
        }
        Console.WriteLine("after finally in Main()");
    }
    public static void _Level_1() {
        try {
            _Level_2();
        } catch (NullReferenceException) {
            Console.WriteLine("NullReferenceException in _Level_1()");
        } finally {
            Console.WriteLine("finally in _Level_1()");
        }
        Console.WriteLine("after finally in _Level_1()");
    }
    public static void _Level_2() {
        try {
            int lhs = 10;
            int rhs = 0;
            lhs = lhs / rhs;
        } catch (IndexOutOfRangeException) {
            Console.WriteLine("IndexOutOfRangeException in _Level_2()");
        } finally {
            Console.WriteLine("finally in _Level_2()");
        }
        Console.WriteLine("after finally in _Level_2()");
    }
}
