/* CS_Generic_Interface.cs
Author: BSS9395
Update: 2022-05-31T21:52:00+08@China-Shanghai+08
Design: C# Language Feature: Generic Interface
*/

using System;

class CS_Generic_Interface {
    interface Inter<T> {
        void _Print(T value);
    }
    class Write<T> : Inter<T> {
        public void _Print(T value) {
            Console.WriteLine(value);
        }
    }

    class Print : Inter<double>, Inter<String> {
        public void _Print(double value) {
            Console.WriteLine(value);
        }
        public void _Print(String value) {
            Console.WriteLine(value);
        }
    }
    public static void Main(String[] args) {
        var write_double = new Write<double>();
        write_double._Print(12.34);

        var print = new Print();
        print._Print(23.45);
        print._Print("abc");
    }
}
