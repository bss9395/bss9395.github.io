/* CS_Regex.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Standary Library: Regex
*/

using System;
using System.Text.RegularExpressions;

class CS_Regex {
    public static void Main(string[] args) {
        _Regex();
    }
    public static void _Regex() {
        string email = "bss9395@github.com";
        Regex regex = new Regex(@"^(\w)+(\.\w)*@(\w)+((\.(\w)+)+)$");
        if (regex.IsMatch(email)) {
            Console.WriteLine("邮箱格式正确。");
        } else {
            Console.WriteLine("邮箱格式不正确。");
        }
    }
}
