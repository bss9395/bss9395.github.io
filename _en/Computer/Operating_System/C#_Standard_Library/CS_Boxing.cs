/* CS_Boxing.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Language Feature: Boxing
*/

using System;

class CS_Boxing {
    public static void Main(string[] args) {
        _Boxing();
        _UnBoxing();
    }
    public static void _Boxing() {
        double num = 123.456;
        Double box = num;
        Console.WriteLine("type = {0}, hash = {1}", box.GetType(), box.GetHashCode());

        object val = num;
        Object obj = val;
        Console.WriteLine("type = {0}, hash = {1}", obj.GetType().ToString(), obj.GetHashCode());

        num = 456.789;
        Console.WriteLine("num = {0}, box = {1}", num, box);  // note: boxing operation copies value into box.
    }
    public static void _UnBoxing() {
        int num = 123;
        object box = num;
        try {
            int val = (short)box;  // note: incorrect boxing, may raise exception.
            // int val = (int)box;    // note: correct unboxing.
            Console.WriteLine("Unboxing OK.");
        } catch (InvalidCastException e) {
            Console.WriteLine("Error: {0}.", e.Message);
        }
    }
}

