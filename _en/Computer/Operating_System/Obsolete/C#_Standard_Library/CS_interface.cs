/* CS_interface.cs
Author: BSS9395
Update: 2022-06-01T13:38:00+08@China-Shanghai+08
Design: C# Keyword: interface
*/

using System;

class CS_interface {
    public interface IInfo {
        String _Print_Id();
    }
    public interface ISame {
        String _Print_Id();
    }
    class Person : IInfo, ISame {
        public String _id = "";
        public String _Print_Id() {
            Console.WriteLine($"_id = {_id}");
            return _id;
        }
    }
    class Child : IInfo, ISame {
        public String _id = "";
        public String _father = "";
        public String _Print_Id() {
            String id = _father + "-" + _id;
            Console.WriteLine($"id = {id}");
            return id;

        }
        String IInfo._Print_Id() {
            String id = "IInfo-" + _father + "-" + _id;
            Console.WriteLine($"id = {id}");
            return id;
        }
        String ISame._Print_Id() {
            String id = "ISame-" + _father + "-" + _id;
            Console.WriteLine($"id = {id}");
            return id;
        }
    }
    public static void _Print_Info(IInfo info) {
        info._Print_Id();
    }
    public static void Main() {
        Person person = new Person { _id = "20220601" };
        Child child = new Child { _id = "20220602", _father = "bss9395" };
        _Print_Info(person);
        _Print_Info(child);


        IInfo info = (IInfo)child;
        ISame same = (ISame)child;
        child._Print_Id();
        info._Print_Id();
        same._Print_Id();
    }
}
