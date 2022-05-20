/* CS_using.cs
Author: BSS9395
Update: 2022-05-19T21:40:00+08@China-Shanghai+08
Design: C# keyword: using
*/

using System;
using System.IO;

class CS_using {
    public static void Main(String[] args) {
        _using();
    }
    public static void _using() {
        using (TextWriter writer1 = File.CreateText("tmp1.txt"), writer2 = File.CreateText("tmp2.txt")) {
            writer1.WriteLine("1 Hello World!");
            writer2.WriteLine("2 Hello World!");
        }

        using (TextReader reader1 = File.OpenText("tmp1.txt")) {
            String input = "";
            while ((input = reader1.ReadLine()) != null) {
                Console.WriteLine(input);
            }

            using (TextReader reader2 = File.OpenText("tmp2.txt")) {
                while ((input = reader2.ReadLine()) != null) {
                    Console.WriteLine(input);
                }
            }
        }
    }
}
