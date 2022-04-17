/* CS_static.cs
Author: BSS9395
Update: 2022-04-14T23:11:00+08@China-Shanghai+08
Design: C# Keyword: static
Encode: UTF-8
*/

using System;
using System.Diagnostics;

class CS_static {
    public static void Main(string[] args) {
        CS_static._id = "20220414";
        Console.WriteLine("ID = {0}", CS_static._id);
    }

    public static string _id = "";
}
