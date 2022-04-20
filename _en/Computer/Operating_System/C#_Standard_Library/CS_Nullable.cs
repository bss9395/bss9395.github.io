/* CS_Nullable.cs
Author: BSS9395
Update: 2022-04-19T23:44:00+08@China-Shanghai+08
Design: C# Standard Library: Nullable
*/

using System;

class CS_Nullable {
    public static void Main(string[] args) {
        _Nullable();
    }
    public static void _Nullable() {
        Nullable<double> abc = null;
        double? def = 3.1415;                  // note: the same as Nullable<double> def;
        if (def.HasValue) {
            Console.WriteLine("def = {0}", def);
        }
    }
}

