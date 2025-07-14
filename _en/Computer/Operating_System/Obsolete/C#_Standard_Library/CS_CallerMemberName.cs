/* CS_CallerMemberName.cs
Author: BSS9395
Update: 2022-05-20T16:47:00+08@China-Shanghai+08
Design: C# Attribute: CallerMemberName
*/

using System;
using System.Runtime.CompilerServices;

class CS_CallerMemberName {
    public static void Main(string[] args) {
        _Trace("in Main()");
    }
    public static void _Trace(string message,
        [CallerFilePath] string filename = "",
        [CallerLineNumber] int line = 0,
        [CallerMemberName] string member = "") {
        Console.WriteLine($"filename = {filename}");
        Console.WriteLine($"line = {line}");
        Console.WriteLine($"member = {member}");
        Console.WriteLine($"message = {message}");
    }
}
