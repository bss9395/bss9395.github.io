/* CS_Nullable.cs
Author: BSS9395
Update: 2022-06-04T22:42:00+08@China-Shanghai+08
Design: C# Language Feature: Nullable
*/

using System;

class CS_Nullable {
    public static void Main(String[] args) {
        _Nullable();
        // _Transform();
    }
    public static void _Nullable() {
        // Nullable<int> inte = 15;
        int? inte = 15;     // note: the same as Nullable<int> inte = 15;
        if (inte != null) {
            Console.WriteLine($"inte == {inte}");
        }
        if (inte.HasValue == true) {
            Console.WriteLine($"inte == {inte}");
        }
    }
    public static void _Transform() {
        try {
            //int? inte = null;
            int? inte = 15;
            int tran = (int)inte;
            Console.WriteLine($"tran == {tran}");
        } catch (Exception exception) {
            Console.WriteLine(exception);
        }
    }
}
