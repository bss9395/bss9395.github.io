/* CS_typeof.cs
Author: BSS9395
Update: 2022-05-20T12:10:00+08@China-Shanghai+08
Design: C# Keyword: typeof
*/

using System;
using System.Reflection;

class CS_typeof {
    class Super {
        public int _super = 0;
    }
    class Derived : Super {
        public int _derived = 0;
    }

    public static void Main(String[] args) {
        // _GetType();
        // _typeof();
        // _nameof();
        _MethodBase();
    }
    public static void _GetType() {
        var super = new Super();
        var derived = new Derived();
        Super[] supers = new Super[] { super, derived };
        foreach (var sup in supers) {
            Type type = sup.GetType();
            Console.WriteLine($"type: {type.Name}");
            FieldInfo[] fields = type.GetFields();
            foreach (var field in fields) {
                Console.WriteLine($"field: {field.Name}");
            }
            Console.WriteLine();
        }
    }
    public static void _typeof() {
        Type super = typeof(Super);
        Console.WriteLine($"type: {super.Name}");
        FieldInfo[] super_fields = super.GetFields();
        foreach (var field in super_fields) {
            Console.WriteLine($"field: {field.Name}");
        }
        Console.WriteLine();

        Type derived = typeof(Derived);
        Console.WriteLine($"type: {derived.Name}");
        FieldInfo[] derived_fields = derived.GetFields();
        foreach (var field in derived_fields) {
            Console.WriteLine($"field: {field.Name}");
        }
        Console.WriteLine();
    }
    public static void _nameof() {
        Console.WriteLine($"{nameof(CS_typeof)}.{nameof(_nameof)}, ");
    }
    public static void _MethodBase() {
        Console.WriteLine($"{MethodBase.GetCurrentMethod()}");
    }
}
