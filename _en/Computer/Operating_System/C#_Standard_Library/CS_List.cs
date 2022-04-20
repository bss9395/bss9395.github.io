/* CS_List.cs
Author: BSS9395
Update: 2022-04-20T20:49:00+08@China-Shanghai+08
Design: C# Standard Library: List
*/

using System;
using System.Collections.Generic;

class CS_List {
    public static void Main(string[] args) {
        _List();
    }
    public static void _List() {
        List<Student> list = new List<Student>();
        list.Add(new Student("1", "小明"));
        list.Add(new Student("2", "小李"));
        list.Add(new Student("3", "小赵"));
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
}

