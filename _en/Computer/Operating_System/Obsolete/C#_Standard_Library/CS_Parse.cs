/* CS_Parse.cs
Author: BSS9395
Update: 2022-06-04T22:23:00+08@China-Shanghai+08
Design: C# Standard Library: Parse()
*/

using System;

class CS_Parse {
    public static void Main(String[] args) {
        _Parse();
    }
    public static void _Parse() {
        try {
            // String str1 = "abc";
            String str1 = "25.873";
            String str2 = "36.240";
            double dou1 = double.Parse(str1);
            double dou2 = double.Parse(str2);
            Console.WriteLine($"sum == {dou1 + dou2}");
        } catch (Exception exception) {
            Console.WriteLine(exception);
        }
    }
    public static void _TryParse() {
        // string str1 = "abc";
        string str1 = "25.873";
        string str2 = "36.240";
        double dou1 = 0.0;
        double dou2 = 0.0;
        bool ret1 = double.TryParse(str1, out dou1);
        bool ret2 = double.TryParse(str2, out dou2);
        if (ret1 == true && ret2 == true) {
            Console.WriteLine($"sum == {dou1 + dou2}");
        }
    }
}
