/* CS_IComparer.cs
Author: BSS9395
Update: 2022-04-20T21:26:00+08@China-Shanghai+08
Design: C# Standard Library: IComparer
*/

using System;
using System.Collections.Generic;

class CS_IComparer {
    public static void Main(string[] args) {
        _IComparer();
    }
    public static void _IComparer() {
        List<Student> list = new List<Student>();
        list.Add(new Student("2", "小李"));
        list.Add(new Student("1", "小明"));
        list.Add(new Student("3", "小赵"));
        list.Sort(new Compare_Student());
        foreach (Student student in list) {
            Console.WriteLine("{0}", student);
        }
    }
    class Student {
        public string _id { get; set; }
        public string _name { get; set; }
        public Student(string id, string name) {
            _id = id;
            _name = name;
        }
        public override string ToString() {
            return string.Format("[id = {0}, name = {1}]", _id, _name);
        }
    }
    class Compare_Student : IComparer<Student> {
        public int Compare(Student lhs, Student rhs) {
            return lhs._id.CompareTo(rhs._id);
        }
    }
}

