/* CS_Generics.cs
Author: BSS9395
Update: 2022-04-20T10:42:00+08@China-Shanghai+08
Design: C# Language Feature: Generics
*/

using System;

class CS_Generic {
    class Stack<T> {
        public T[] _items = null;
        public int _index = 0;
        public int _capacity = 20;
        public Stack() {
            _items = new T[_capacity];
        }
        public void _Push(T item) {
            if (_index < _capacity) {
                _items[_index] = item;
                _index += 1;
                return;
            }
            throw new IndexOutOfRangeException();
        }
        public T _Pop() {
            if (0 < _index) {
                _index -= 1;
                return _items[_index];
            }
            return default(T);
        }
        public bool _Empty() {
            return (_index <= 0);
        }
        public bool _Full() {
            return (_index >= _capacity);
        }
        public void _Print() {
            for (int i = _index - 1; 0 <= i; i -= 1) {
                Console.WriteLine($"_items[{i}]: {_items[i]}");
            }
        }
    }
    class Datum {
        public double _value = 0.0;
        public Datum(double value) {
            _value = value;
        }
        public override String ToString() {
            return _value.ToString();
        }
    }
    public static void Main(string[] args) {
        Stack<double> stack_double = new Stack<double>();
        double default_double = stack_double._Pop();
        Console.WriteLine(default_double == 0.0 ? "default_double == 0" : "default_string != 0");
        stack_double._Push(3);
        stack_double._Push(5);
        stack_double._Push(7);
        stack_double._Print();

        Stack<String> stack_string = new Stack<String>();
        String default_string = stack_string._Pop();
        Console.WriteLine(default_string == "" ? "default_string == \"\"" : "default_string != \"\"");
        stack_string._Push("Hello!");
        stack_string._Push("World!");
        stack_string._Print();

        Stack<Datum> stack_datum = new Stack<Datum>();
        Datum default_datum = stack_datum._Pop();
        Console.WriteLine(default_datum == null ? "default_datum == null" : "default_datum != null");
        stack_datum._Push(new Datum(1.0));
        stack_datum._Push(new Datum(2.0));
        stack_datum._Print();

        ////////////////////////////////

        Console.WriteLine("{0}", _Add<double>(3, 4));
        Console.WriteLine("{0}", _Sub(3.3, 4));
    }
    public static string _Add<T>(T lhs, T rhs) {
        double sum = double.Parse(lhs.ToString()) + double.Parse(rhs.ToString());
        return sum.ToString();
    }
    public static string _Sub<T, U>(T lhs, U rhs) {
        double dif = double.Parse(lhs.ToString()) - double.Parse(rhs.ToString());
        return dif.ToString();
    }
}
