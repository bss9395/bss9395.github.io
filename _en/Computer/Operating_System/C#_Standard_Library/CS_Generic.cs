/* CS_Generics.cs
Author: BSS9395
Update: 2022-04-20T10:42:00+08@China-Shanghai+08
Design: C# Language Feature: Generics
*/

using System;

class CS_Generic {
    public static void Main(string[] args) {
        Console.WriteLine("{0}", _Add<double>(3, 4));
        Console.WriteLine("{0}", _Sub<double, int>(3.3, 4));

        ////////////////////////////////

        Appending<double> appending = new Appending<double>();
        appending._Append(10);
        appending._Append(20);
        appending._Append(30);
        appending._Append(40);
        appending._Print();
    }
    public static string _Add<T>(T lhs, T rhs) {
        double sum = double.Parse(lhs.ToString()) + double.Parse(rhs.ToString());
        return sum.ToString();
    }
    public static string _Sub<T, U>(T lhs, U rhs) {
        double dif = double.Parse(lhs.ToString()) - double.Parse(rhs.ToString());
        return dif.ToString();
    }
    class Appending<T> {
        public T[] _items = new T[3];
        public int _index = 0;
        public void _Append(T item) {
            if (_index < 3) {
                _items[_index] = item;
                _index += 1;
            } else {
                Console.WriteLine("缓存区已满！");
            }
        }
        public void _Print() {
            Console.Write("[");
            for (long i = 0; i < _items.Length; i += 1) {
                if (1 <= i) {
                    Console.Write(", ");
                }
                Console.Write("{0}", _items[i]);
            }
            Console.WriteLine("]");
        }
    }
}
