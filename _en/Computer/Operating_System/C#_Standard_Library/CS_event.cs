/* CS_event.cs
Author: BSS9395
Update: 2022-04-27T22:12:00+08@China-Shanghai+08
Design: C# keyword: event
*/

using System;
using System.Reflection;

class CS_event {
    class Datum {
        public delegate void Dele_Event();
        public event Dele_Event _event_buy;
        public Dele_Event _dele_buy;
        public static void _Buy_Meat() {
            Console.WriteLine("{0}.{1}", typeof(Datum).FullName, MethodBase.GetCurrentMethod().Name);
        }
        public static void _Buy_Vegetable() {
            Console.WriteLine("{0}.{1}", typeof(Datum).FullName, MethodBase.GetCurrentMethod().Name);
        }
        public static void _Buy_Fruit() {
            Console.WriteLine("{0}.{1}", typeof(Datum).FullName, MethodBase.GetCurrentMethod().Name);
        }
        public void _Invoke_Event() {
            _event_buy();
        }
    }
    static void Main(string[] args) {
        _Event();
    }
    public static void _Event() {
        Datum datum = new Datum();
        datum._event_buy += new Datum.Dele_Event(Datum._Buy_Meat);
        datum._event_buy += new Datum.Dele_Event(Datum._Buy_Vegetable);
        datum._event_buy += new Datum.Dele_Event(Datum._Buy_Fruit);
        datum._Invoke_Event();
        // datum._event_buy();     // note: used from within Datum.
        Console.WriteLine("========================================");
        datum._dele_buy += Datum._Buy_Meat;
        datum._dele_buy += Datum._Buy_Vegetable;
        datum._dele_buy += Datum._Buy_Fruit;
        datum._dele_buy();
    }
}
