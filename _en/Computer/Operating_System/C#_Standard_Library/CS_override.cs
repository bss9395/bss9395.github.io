/* CS_override.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# keyword: override
*/

using System;
using System.Diagnostics;

class CS_override {
    public static void Main(string[] args) {
        Student student = new Student();
        Teacher teacher = new Teacher();
        student._Print();
        teacher._Print();

        ////////////////////////////////
        Console.WriteLine("========================================");

        Person ride = new Student();
        Person load = new Teacher();
        ride._Print();
        load._Print();
    }
    class Person {
        public string _id { get; set; }
        public string _name { get; set; }
        public Person(string id = "20220416", string name = "bss") {
            _id = id;
            _name = name;
        }
        public virtual void _Print() {
            Console.WriteLine("{0}.{1}", this.GetType(), new StackTrace(true).GetFrame(0).GetMethod());
            Console.WriteLine("编号：" + _id);
            Console.WriteLine("姓名：" + _name);
        }
    }

    class Student : Person {
        public string _major { get; set; }
        public Student()
            : base() {
            _major = "C#";
        }
        public override void _Print() {
            Console.WriteLine("{0}.{1}", this.GetType(), new StackTrace(true).GetFrame(0).GetMethod());
            base._Print();
            Console.WriteLine("专业：" + _major);
        }
    }

    class Teacher : Person {
        public string _title { get; set; }
        public Teacher()
            : base() {
            _title = "Engineer";
        }
        public new void _Print() {
            Console.WriteLine("{0}.{1}", this.GetType(), new StackTrace(true).GetFrame(0).GetMethod());
            base._Print();
            Console.WriteLine("职称：" + _title);
        }
    }
}
