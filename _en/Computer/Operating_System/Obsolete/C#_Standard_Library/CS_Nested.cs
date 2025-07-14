/* CS_Nested.cs
Author: BSS9395
Update: 2022-05-21T17:53:00+08@China-Shanghai+08
Design: C# Language Feature: Nested Class
*/

using System;

class CS_Nested {
    class Nested {
        public int _count = 0;
        public String _value = "inner_value";
        CS_Nested _cs_nested = null;
        public Nested(CS_Nested cs_nested) {
            _cs_nested = cs_nested;
        }
        public void Print_Outer() {
            Console.WriteLine($"outer._value = {_cs_nested._value}");
        }
    }
    private String _value = "outter_value";
    private static Nested _nested = null;
    public CS_Nested() {
        if (_nested == null) {
            _nested = new Nested(this);
        }
    }
    public void _Print_Inner() {
        Console.WriteLine($"inner._value = {_nested._value}");
    }
    public void _Increment() {
        _nested._count += 1;
    }
    public int _Get_Count() {
        return _nested._count;
    }
    public static void Main() {
        CS_Nested cs_nested = new CS_Nested();
        cs_nested._Increment();
        cs_nested._Increment();
        Console.WriteLine(cs_nested._Get_Count());
    }
}
