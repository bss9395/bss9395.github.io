/* CS_Dictionary.cs
Author: BSS9395
Update: 2022-04-20T21:05:00+08@China-Shanghai+08
Design: C# Standard Library: Dictionary
*/

using System;
using System.Collections.Generic;

class CS_Dictionary {
    public static void Main(string[] args) {
        _Dictionary();
    }
    public static void _Dictionary() {
        Dictionary<string, Student> dictionary = new Dictionary<string, Student>();
        Student student1 = new Student("1", "小明");
        Student student2 = new Student("2", "小李");
        Student student3 = new Student("3", "小赵");
        dictionary[student1._id] = student1;
        dictionary[student2._id] = student2;
        dictionary[student3._id] = student3;
        foreach (KeyValuePair<string, Student> entry in dictionary) {
            Console.WriteLine("{0}:{1}", entry.Key, entry.Value);
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

