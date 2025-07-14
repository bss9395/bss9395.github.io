/* CS_StringBuilder.cs
Author: BSS9395
Update: 2022-06-04T22:13:00+08@China-Shanghai+08
Design: C# Standard Library: StringBuilder
*/

using System;
using System.Text;

class CS_StringBuilder {
    public static void Main(String[] args) {
        _StringBuilder();
    }
    public static void _StringBuilder() {
        StringBuilder builder = new StringBuilder("Hello, World!");
        Console.WriteLine($"{builder}");

        builder.Replace("Hello", "Hi");
        Console.WriteLine($"{builder}");
    }
}
