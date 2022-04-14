/* _ref.cs
Author: BSS9395
Update: 2022-04-14T23:11:00+08@China-Shanghai+08
Design: C# Keyword: ref
Encode: UTF-8
*/

using System;
using System.Diagnostics;

class _ref_out {
    static void Main(string [] args) {
        string ID = "20220414";
        Refer(ref ID);
        Console.WriteLine("ID = {0}", ID);
        Return(out ID);
        Console.WriteLine("ID = {0}", ID);
    }

    static string Refer(ref string ID) {
        ID = "20220422";
        return ID;
    }

    static void Return(out string ID) {
        ID = "20220414";
    }
}
