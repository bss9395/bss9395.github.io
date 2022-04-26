/* CS_is.cs
Author: BSS9395
Update: 2022-04-21T16:28:00+08@China-Shanghai+08
Design: C# keyword: is
*/

using System;

class CS_is {
    public static void Main() {
        // _explicit();
        //_Multistep();
        // _is();
        _as();
    }
    public static void _as() {
        Employee employee = new Employee();
        Person person = employee as Person;
        if (person != null) {
            Console.WriteLine(person);
        }
    }
    public static void _is() {
        Employee employee = new Employee();
        if (employee is Person) {
            Person person = employee;
            Console.WriteLine(person);
        }
    }
    public static void _Multistep() {
        Employee employee = new Employee();
        Console.WriteLine(employee);
        double id = (double)employee;
        Console.WriteLine($"id = {id}");
    }
    public static void _explicit() {
        Person bss9395 = new Person();
        Console.WriteLine(bss9395);
        Console.WriteLine((int)bss9395);
        Person none = (Person)28;
        Console.WriteLine(none);
        Console.WriteLine((int)none);
    }
    class Person {
        public string _id = "20220421";
        public string _name = "bss9395";
        public Person() {

        }
        public Person(string id, string name) {
            _id = id;
            _name = name;
        }
        public override string ToString() {
            return string.Format($"[id = {_id}, name = {_name}]");
        }
        public static explicit operator int(Person person) {
            return int.Parse(person._id);
        }

        public static explicit operator Person(int id) {  // note: this is an operator, not a constructor.
            return new Person(id.ToString(), "none");
        }
    }
    class Employee : Person {

    }
}