/* CS_Console.cs
Author: BSS9395
Update: 2022-04-14T23:11:00+08@China-Shanghai+08
Design: C# Standard Library: Console
Encode: UTF-8
*/

using System;
using System.Diagnostics;

class CS_Console {
    public static void Main(string[] args) {
        _Login();
    }

    public static void _Login() {
        for (long count = 3; true;) {
            count -= 1;
            Console.Write("请输入用户名：");
            string username = Console.ReadLine();
            Console.Write("请输入密码：");
            string password = Console.ReadLine();
            if (username == "abc" && long.Parse(password) == 123) {
                Console.WriteLine("登录成功");
                break;
            } else if (count <= 0) {
                Console.WriteLine("用户名或密码错误超限！");
                break;
            } else {
                Console.WriteLine("用户名或密码错误！");
            }
        }
    }
}
