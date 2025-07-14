/* CS_out.cs
Author: BSS9395
Update: 2022-04-14T23:11:00+08@China-Shanghai+08
Design: C# Keyword: out
Encode: UTF-8
*/

using System;

class CS_out {
    public static void Main(string[] args) {
        //string ID = "20220414";
        //_ref_Parameter(ref ID);
        //Console.WriteLine("ID = {0}", ID);
        //_out_Parameter(out ID);
        //Console.WriteLine("ID = {0}", ID);

        //_ref_Local();
        ref String ing = ref _ref_Return();
        ing = "def";
        Console.WriteLine($"{_str}");
    }

    public static string _ref_Parameter(ref string ID) {
        ID = "20220422";
        return ID;
    }

    public static void _out_Parameter(out string ID) {
        ID = "20220414";
    }
    public static void _ref_Local() {
        String str = "abc";
        ref String ing = ref str;
        ing = "def";
        Console.WriteLine(str);
        str = "ghi";
        Console.WriteLine(ing);
    }
    static String _str = "abc";
    public static ref String _ref_Return() {
        return ref _str;
    }
}
