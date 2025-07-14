/* CS_partial.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# keyword: partial
*/

using System;

class CS_partial {
    public static void Main(string[] args) {
        Course course = new Course();
        course._name = "C#";
        course._score = 4.0;
        course._Info();
    }

    partial class Course {
        public string _name { get; set; }
        public double _score { get; set; }
    }
    partial class Course {
        partial void _Print();
        public void _Info() {
            _Print();
        }
    }
    partial class Course {
        partial void _Print() {
            Console.WriteLine("课程名称：{0}", _name);
            Console.WriteLine("课程分数：{0}", _score);
        }
    }
}
