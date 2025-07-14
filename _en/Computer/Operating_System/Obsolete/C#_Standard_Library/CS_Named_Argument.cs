/* CS_Named_Argument.cs
Author: BSS9395
Update: 2022-05-30T16:02:00+08@China-Shanghai+08
Design: C# Language Feature: Named Argument
*/

using System;

class CS_Named_Argument {
    public static void Main(string[] args) {
        _Named_Argument("abc", i: 123, d: 456.123);
    }
    public static void _Named_Argument(String s, double d, int i) {
        Console.WriteLine($"s = {s}, d = {d}, i = {i}");
    }
}
