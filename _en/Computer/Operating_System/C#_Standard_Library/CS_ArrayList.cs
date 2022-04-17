/* CS_ArrayList.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Standary Library: ArrayList
*/

using System;
using System.Collections;
using System.Diagnostics;

class CS_ArrayList {
    public static void Main(string[] args) {
        // _IndexOf();
        // _Add();
        // _InsertRange();
        // _Sort();
        _IComparer();
    }
    public static void _IndexOf() {
        ArrayList list = new ArrayList() {
            "abc", "def", 123, 456
        };
        int item = 123;  // note: (int)123 found, (long)123 not found.
        long idx = list.IndexOf(item);
        if (idx != -1) {
            Console.WriteLine("{0} found.", item);
        } else {
            Console.WriteLine("{0} not found.", item);
        }
    }
    public static void _Add() {
        ArrayList list = new ArrayList() {
            "abc", "def", 123, 456
        };
        list.Add("ghi");
        list.Add(789);
        foreach (var elem in list) {
            Console.Write("{0} ", elem);
        }
        Console.WriteLine();
    }

    public static void _InsertRange() {
        ArrayList list = new ArrayList() {
            "abc", "def", 123, 456
        };
        ArrayList another = new ArrayList() {
            "ghi", 789
        };
        list.InsertRange(1, another);
        foreach (var elem in list) {
            Console.Write("{0} ", elem);
        }
        Console.WriteLine();
    }
    public static void _Sort() {
        ArrayList list = new ArrayList() {
            "def", "ghi", "abc"
        };
        list.Sort();
        foreach (var elem in list) {
            Console.Write("{0} ", elem);
        }
        Console.WriteLine();
    }
    class Comparer : IComparer {
        public int Compare(object lhs, object rhs) {
            return lhs.ToString().CompareTo(rhs.ToString());
        }
    }
    public static void _IComparer() {
        ArrayList list = new ArrayList() {
            "def", "abc", 456, 123, "ghi", 789
        };
        list.Sort(new Comparer());
        foreach (var elem in list) {
            Console.Write("{0} ", elem);
        }
        Console.WriteLine();
    }
}

