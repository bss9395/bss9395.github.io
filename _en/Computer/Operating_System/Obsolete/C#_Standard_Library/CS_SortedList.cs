/* CS_SortedList.cs
Author: BSS9395
Update: 2022-04-17T20:33:00+08@China-Shanghai+08
Design: C# Standard Library: SortedList
*/

using System;
using System.Collections;
using System.Reflection;

class CS_SortedList {
    public static void Main(string[] args) {
        _SortedList();
        //_IDictionaryEnumerator();
    }
    class Value {
        public void _Print() {
            Console.WriteLine("{0}.{1}", typeof(Value).FullName, MethodBase.GetCurrentMethod().Name);
        }
        public override string ToString() {
            string function = typeof(Value).FullName + MethodBase.GetCurrentMethod().Name;
            return function;
        }
    }
    public static void _SortedList() {
        SortedList list = new SortedList();
        list.Add("34", new Value());
        list.Add("12", "def");
        list.Add("56", 12.34);
        foreach (DictionaryEntry entry in list) {
            Console.WriteLine("{0}:{1} ", entry.Key, entry.Value);
        }
        Console.WriteLine();
    }
    public static void _IDictionaryEnumerator() {
        SortedList list = new SortedList();
        list.Add("34", 1234);
        list.Add("12", "def");
        list.Add("56", 12.34);
        IDictionaryEnumerator enumerator = list.GetEnumerator();
        while (enumerator.MoveNext() == true) {
            Console.WriteLine("{0}:{1}", enumerator.Key, enumerator.Value);
        }
    }
}
