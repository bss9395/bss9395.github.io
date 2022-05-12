/* CS_const.cs
Author: BSS9395
Update: 2022-04-14T23:11:00+08@China-Shanghai+08
Design: C# Keyword: const
Encode: UTF-8
*/

using static System.Console;
using static System.Math;

class CS_const {
    public static string _id = "20220414";
    public const double _pi = PI;
    public static void Main(string[] args) {
        WriteLine("_id = {0}", CS_const._id);
        const double pi = _pi;
        WriteLine("_pi = {0}", pi);
    }
}
