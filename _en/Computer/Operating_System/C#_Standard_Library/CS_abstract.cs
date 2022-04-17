/* CS_abstract.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# keyword: abstract
*/

using System;

class CS_abstract {
    public static void Main(string[] args) {
        Data data = new Person();
        data._id = "20220416";
        data._name = "bss9395";
        data._Print();
    }

    abstract class Data {
        public string _id = "";
        public string _name = "";
        public abstract void _Print();
    }

    class Person : Data {
        public override void _Print() {
            Console.WriteLine("id = {0}, name = {1}", _id, _name);
        }
    }
}
