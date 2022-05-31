/* CS_Params.cs
Author: BSS9395
Update: 2022-05-30T14:59:00+08@China-Shanghai+08
Design: C# Keyword: params
*/

using System;

class CS_params {
    public static void Main(String[] args) {
        // _Test_params();
        _Test_Array();
    }
    public static void _Test_params() {
        _params(3, "abc", "def", "ghi");
    }
    public static void _Test_Array() {
        String[] strs = new string[3] {
            "abc", "def", "ghi"
        };
        _params(3, strs);
        for (int i = 0; i < strs.Length; i += 1) {
            Console.WriteLine(strs[i]);
        }
    }
    public static void _params(int numbs, params String[] strs) {
        for (int i = 0; i < strs.Length; i += 1) {
            strs[i] = strs[i] + i;
            Console.WriteLine(strs[i]);
        }
    }
}
