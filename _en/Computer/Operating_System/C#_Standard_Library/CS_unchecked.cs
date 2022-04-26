/* CS_unchecked.cs
Author: BSS9395
Update: 2022-04-21T16:14:00+08@China-Shanghai+08
Design: C# keyword: unchecked
*/

using System;

class CS_unchecked {
    public static void Main(string[] args) {
        //_unchecked();
        //_checked();
        _nested();
    }
    public static void _unchecked() {
        ushort sh = 2000;
        byte by = unchecked((byte)sh);
        Console.WriteLine("by = {0}", by);
    }
    public static void _checked() {
        ushort sh = 2000;
        sbyte by = checked((sbyte)sh);
        Console.WriteLine("by = {0}", by);
    }
    public static void _nested() {
        ushort sh = 2000;
        checked {
            unchecked {
                byte by = (byte)sh;
                Console.WriteLine("by = {0}", by);
            }
            sbyte sb = (sbyte)sh;
            Console.WriteLine("sb = {0}", sb);
        }
    }
}

