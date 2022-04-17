/* CS_Convert.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Standary Library: Convert
*/

using System;

class CS_Convert {
    public static void Main(string[] args) {
        _Convert();
    }
    public static void _Convert() {
        float number = 123.456f;
        string text = Convert.ToString(number);
        text = text.Replace(".", ":");
        Console.WriteLine("{0}", text);
    }
}

