/* CS_base.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# keyword: base
*/

using System;
using System.Diagnostics;

class CS_base {
    public static void Main(string[] args) {
        Derived derived = new Derived();
        Derived derived_base = new Derived("abc");
    }

    class Super {
        public Super() {
            Console.WriteLine("{0}.{1}", this.GetType(), new StackTrace(true).GetFrame(0).GetMethod());
        }
        public Super(string arg) {
            Console.WriteLine("{0}.{1}", this.GetType(), new StackTrace(true).GetFrame(0).GetMethod());
        }
    }
    class Derived : Super {
        public Derived() {
            Console.WriteLine("{0}.{1}", this.GetType(), new StackTrace(true).GetFrame(0).GetMethod());
        }
        public Derived(string arg)
            : base(arg) {
            Console.WriteLine("{0}.{1}", this.GetType(), new StackTrace(true).GetFrame(0).GetMethod());
        }
    }
}
