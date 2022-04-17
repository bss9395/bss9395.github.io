/* CS_struct.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# keyword: struct
*/

using System;

class CS_struct {
    public static void Main(string[] args) {
        Data student = new Data();
        student._name = "abc";
        student._age = -100;
        Console.WriteLine("name = {0}, age = {1}", student._name, student._age);
    }

    struct Data {
        public string _name { get; set; }

        private int __age;
        public int _age {
            get {
                return __age;
            }
            set {
                if (value < 0) {
                    __age = 0;
                } else {
                    __age = value;
                }
            }
        }

        public Data(string name, int age) {
            _name = name;
            __age = age;
        }
    }
}

