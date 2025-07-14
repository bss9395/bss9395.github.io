/* CS_Hashtable.cs
Author: BSS9395
Update: 2022-04-14T23:11:00+08@China-Shanghai+08
Design: C# Standard Library: Hashtable
Encode: UTF-8
*/

using System;
using System.Collections;
using System.Diagnostics;
using System.Reflection;

class CS_Hashtable {
    public static void Main(string[] args) {
        // _Hashtable();
        _ContainsValue();
        // _DictionaryEntry();
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
    public static void _Hashtable() {
        Hashtable table = new Hashtable();
        table[12.34] = 1234;
        table["abc"] = "def";
        Value value = new Value();
        table[value] = value;
        Console.WriteLine("{0}", table[12.34]);
        Console.WriteLine("{0}", table["abc"]);
        Console.WriteLine("{0}", table[value]);
        if (table[12] == null) {
            Console.WriteLine("table[12] == null");
        } else {
            Console.WriteLine("table[12] != null");
        }
    }
    public static void _ContainsValue() {
        Hashtable table = new Hashtable();
        table[12.34] = 1234;
        table["abc"] = "def";
        Value value = new Value();
        table[value] = value;
        if (table.ContainsValue(1234) == true) {
            Console.WriteLine("table.ContainsValue(1234) == true");
        } else {
            Console.WriteLine("table.ContainsValue(1234) != true");
        }
    }
    public static void _DictionaryEntry() {
        Hashtable table = new Hashtable();
        table[12.34] = 1234;
        table["abc"] = "def";
        Value value = new Value();
        table[value] = value;
        foreach (DictionaryEntry entry in table) {
            Console.WriteLine("{0}:{1}", entry.Key, entry.Value);
        }
        Console.WriteLine();
    }
}
