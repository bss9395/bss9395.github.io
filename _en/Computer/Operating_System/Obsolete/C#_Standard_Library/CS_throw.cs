/* CS_throw.cs
Author: BSS9395
Update: 2022-06-01T20:44:00+08@China-Shanghai+08
Design: C# Keyword: throw
*/

using System;

class CS_throw {
    public static void Main(String[] args) {
        _Print(null);
        Console.WriteLine("========================================");
        _Print("abc");
    }
    public static void _Print(String arg) {
        try {
            try {
                if (arg == null) {
                    throw new ArgumentNullException(arg);
                }
                Console.WriteLine("in inner try");
            } catch (ArgumentNullException) {
                Console.WriteLine("catch in inner try");
                throw;
            }
            Console.WriteLine("in outer try");
        } catch (Exception) {
            Console.WriteLine("catch in outer try");
        }
        Console.WriteLine("in _Print()");
    }
}
