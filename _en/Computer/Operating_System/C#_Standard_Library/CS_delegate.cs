/* CS_delegate.cs
Author: BSS9395
Update: 2022-04-27T21:12:00+08@China-Shanghai+08
Design: C# Keyword: delegate
*/

using System;
using System.Reflection;

class CS_delegate {
    class Datum : IComparable<Datum> {
        public string _name { get; set; }
        public double _price { get; set; }
        public static void _Static() {
            Console.WriteLine("{0}.{1}", typeof(Datum).FullName, MethodBase.GetCurrentMethod().Name);
        }
        public void _NonStatic() {
            Console.WriteLine("{0}.{1}", typeof(Datum).FullName, MethodBase.GetCurrentMethod().Name);
        }
        public Datum() {

        }
        public Datum(string name, double price) {
            _name = name;
            _price = price;
        }
        public override string ToString() {
            return string.Format("[{0}:{1}]", _name, _price);
        }
        public int CompareTo(Datum other) {
            return (int)(_price - other._price);
        }
        public static void _Sort(Datum[] data) {
            Array.Sort(data);
        }
        public static void _Buy_Meat() {
            Console.WriteLine("{0}.{1}", typeof(Datum).FullName, MethodBase.GetCurrentMethod().Name);
        }
        public static void _Buy_Vegetable() {
            Console.WriteLine("{0}.{1}", typeof(Datum).FullName, MethodBase.GetCurrentMethod().Name);
        }
        public static void _Buy_Fruit() {
            Console.WriteLine("{0}.{1}", typeof(Datum).FullName, MethodBase.GetCurrentMethod().Name);
        }
    }
    public static void Main(string[] args) {
        // _Delegate();
        // _Delegate_Param();
        // _Delegate_Multi();
        _Delegate_Anonymous();
    }
    delegate void Dele_Void();  // note: resembles std::Functional<> in C++.
    public static void _Delegate_Void() {
        Dele_Void dele_static = new Dele_Void(Datum._Static);
        dele_static();
        Dele_Void dele_nonstatic = new Dele_Void(new Datum()._NonStatic);
        dele_nonstatic();
    }

    delegate void Dele_Param(Datum[] data);
    public static void _Delegate_Param() {
        Dele_Param dele_param = new Dele_Param(Datum._Sort);
        Datum[] data = new Datum[4];
        data[3] = new Datum("Do", 2022.03);
        data[1] = new Datum("C++", 1979.00);
        data[0] = new Datum("C", 1972.11);
        data[2] = new Datum("C#", 2000.06);
        dele_param(data);
        foreach (Datum datum in data) {
            Console.WriteLine("{0}", datum);
        }
    }
    delegate void Dele_Multi();
    public static void _Delegate_Multi() {
        Dele_Multi dele_multi = new Dele_Multi(Datum._Buy_Meat);
        dele_multi += Datum._Buy_Vegetable;
        dele_multi += Datum._Buy_Fruit;
        dele_multi();
        Console.WriteLine("========================================");
        dele_multi -= Datum._Buy_Vegetable;
        dele_multi();
    }
    delegate void Dele_Anony(double width, double height);
    public static void _Delegate_Anonymous() {
        double width = 1.0;
        double height = 2.0;
        Dele_Anony dele_anony = delegate {
            Console.WriteLine("{0}.{1}", typeof(Datum).FullName, MethodBase.GetCurrentMethod().Name);
            Console.WriteLine("area = {0}", width * height);
        };
        dele_anony(3.0, 4.0);  // note: parameters are of no use.
    }
}
