/* CS_out.cs
Author: BSS9395
Update: 2022-04-14T23:11:00+08@China-Shanghai+08
Design: C# Keyword: out
Encode: UTF-8
*/

using System;
using System.Diagnostics;

class CS_out {
    public static void Main(string[] args) {
        string ID = "20220414";
        _Refer(ref ID);
        Console.WriteLine("ID = {0}", ID);
        _Return(out ID);
        Console.WriteLine("ID = {0}", ID);
    }

    public static string _Refer(ref string ID) {
        ID = "20220422";
        return ID;
    }

    public static void _Return(out string ID) {
        ID = "20220414";
    }
}
