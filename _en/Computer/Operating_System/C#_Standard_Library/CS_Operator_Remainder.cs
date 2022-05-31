/* CS_Operator_Remainder.cs
Author: BSS9395
Update: 2022-05-31T12:33:00+08@China-Shanghai+08
Design: C# Language Feature: Operator Remainder
*/

using System;

class CS_Operator_Remainder {
    public static void Main(String[] args) {
        _Remainder_Integer();
        _Remainder_Fractional();
    }
    public static void _Remainder_Integer() {
        Console.WriteLine("{0} % {1} = {2}", 0, 3, 0 % 3);
        Console.WriteLine("{0} % {1} = {2}", 1, 3, 1 % 3);
        Console.WriteLine("{0} % {1} = {2}", 2, 3, 2 % 3);
        Console.WriteLine("{0} % {1} = {2}", 3, 3, 3 % 3);
        Console.WriteLine("{0} % {1} = {2}", 4, 3, 4 % 3);
    }
    public static void _Remainder_Fractional() {
        Console.WriteLine("{0} % {1} = {2}", 0.0, 1.5, 0.0 % 1.5);
        Console.WriteLine("{0} % {1} = {2}", 0.5, 1.5, 0.5 % 1.5);
        Console.WriteLine("{0} % {1} = {2}", 1.0, 1.5, 1.0 % 1.5);
        Console.WriteLine("{0} % {1} = {2}", 1.5, 1.5, 1.5 % 1.5);
        Console.WriteLine("{0} % {1} = {2}", 2.0, 1.5, 2.0 % 1.5);
    }
}
