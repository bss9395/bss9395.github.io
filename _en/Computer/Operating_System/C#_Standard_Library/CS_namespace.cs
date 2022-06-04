/* CS_namespace.cs
Author: BSS9395
Update: 2022-06-01T21:23:00+08@China-Shanghai+08
Design: C# Keyword: namespace
*/

using System;

namespace Level_0 {
    namespace Level_1 {
        class Datum {
            public double _value = 0.0;
            public Datum(double value) {
                _value = value;
            }
        }
    }
}

namespace Level_0.Level_1 {
    class Program {
        public static void Main(String[] args) {
            Datum datum = new Datum(123.456);
            Console.WriteLine($"datum._value = {datum._value}");
        }
    }
}
