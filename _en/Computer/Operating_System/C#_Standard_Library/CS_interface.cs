/* CS_interface.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# keyword: interface
*/

using System;
using System.Diagnostics;

class CS_interface {
    public static void Main(string[] args) {
        Father person = new Child();
        person._Print();
        IPerson iperson = new Child();
        iperson._Print();
    }
    interface IPerson {
        string _id { get; set; }
        string _name { get; set; }
        void _Print();
    }
    class Father {
        public string _wife = "brilliant";
        public virtual void _Print() {
            Console.WriteLine("{0}.{1}", this.GetType(), new StackTrace(true).GetFrame(0).GetMethod());
        }
    }
    class Child : Father, IPerson {
        public string _id { get; set; } = "20220417";
        public string _name { get; set; } = "bss9395";
        public override void _Print() {
            Console.WriteLine("id = {0}, name = {1}", _id, _name);
        }
    }
}

