/* CS_Anonymous.cs
Author: BSS9395
Update: 2022-05-13T15:22:00+08@China-Shanghai+08
Design: C# Language Feature: Anonymous class
*/

class CS_Anonymous {
    class Datum {
        public static string _id = "20220513";
    }
    public static void Main(String[] args) {
        _Test_Anonymous();
    }
    public static void _Test_Anonymous() {
        var anonymous = new {
            _id = "20220513",
            _name = "Brilliant"
        };
        Console.WriteLine($"id = {anonymous._id}, name = {anonymous._name}");

        string name = "Brilliant";
        var datum = new {
            _id = Datum._id,
            _name = name
        };
        Console.WriteLine($"id = {datum._id}, name = {datum._name}");
    }
}
