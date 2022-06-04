/* CS_define.cs
Author: BSS9395
Update: 2022-06-02T12:04:00+08@China-Shanghai+08
Design: C# Directive: #define
*/

#define Debug
#undef Debug
#define Release

using System;

class CS_define {
    public static void Main(String[] args) {
#if Debug
        Console.WriteLine($"Debug: {nameof(CS_define)}.{nameof(Main)}");
#elif Release
        Console.WriteLine($"Release: {nameof(CS_define)}.{nameof(Main)}");
#else
        Console.WriteLine($"{nameof(CS_define)}.{nameof(Main)}");
#endif
    }
}
