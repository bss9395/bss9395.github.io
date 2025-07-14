/* CS_static.cs
Author: BSS9395
Update: 2022-04-14T23:11:00+08@China-Shanghai+08
Design: C# Keyword: static
Encode: UTF-8
*/

using static System.Console;
using static System.Math;

class CS_const {
    static class Compile {
        public static String _class_name = "CS_const";
        static Compile() {
            _class_name = "class CS_const";
        }
    }

    public static string _id = "20220414";
    public const double _pi = PI;
    static CS_const() {
        _id = "20220512";
    }

    public static void Main(string[] args) {
        WriteLine("_id = {0}", CS_const._id);
        const double pi = _pi;
        WriteLine("_pi = {0}", pi);
        WriteLine(Compile._class_name);
    }
}
