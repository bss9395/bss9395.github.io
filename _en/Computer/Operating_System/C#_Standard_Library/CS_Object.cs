/* CS_Object.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Standary Library: Object
*/

using System;

class CS_Object {
    public static void Main(string[] args) {
        //_Equals();
        //_GetHashCode();
        _GetType();
        _ToString();
    }
    public static void _Equals() {
        CS_Object object1 = new CS_Object();
        CS_Object object2 = new CS_Object();
        CS_Object object3 = object1;
        Console.WriteLine("object1 {0} object2", object1.Equals(object2) ? "==" : "!=");
        Console.WriteLine("object1 {0} object3", object1.Equals(object3) ? "==" : "!=");
    }
    public static void _GetHashCode() {
        CS_Object object1 = new CS_Object();
        CS_Object object2 = new CS_Object();
        Console.WriteLine("object1.GetHashCode() = {0}", object1.GetHashCode());
        Console.WriteLine("object2.GetHashCode() = {0}", object2.GetHashCode());
    }
    public static void _GetType() {
        double val = 123.456;
        Double num = val;
        string str = "abc";
        CS_Object cs = new CS_Object();
        Console.WriteLine("val.GetType() = {0}", val.GetType().ToString());
        Console.WriteLine("num.GetType() = {0}", num.GetType().ToString());
        Console.WriteLine("str.GetType() = {0}", str.GetType().ToString());
        Console.WriteLine(" cs.GetType() = {0}", cs.GetType().ToString());
    }
    public static void _ToString() {
        double val = 123.456;
        Double num = val;
        string str = "abc";
        CS_Object cs = new CS_Object();
        Console.WriteLine("val.GetType() = {0}", val.ToString());
        Console.WriteLine("num.GetType() = {0}", num.ToString());
        Console.WriteLine("str.GetType() = {0}", str.ToString());
        Console.WriteLine(" cs.GetType() = {0}", cs.ToString());
    }
}

