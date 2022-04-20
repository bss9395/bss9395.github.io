/* CS_string.cs
Author: BSS9395
Update: 2022-04-20T20:40:00+08@China-Shanghai+08
Design: C# Keyword: string
*/

using System;

class CS_string {
    public static void Main(string[] args) {
        //_Reverse();
        //_Replace();
        //_SubString();
        //_Insert();
        //_Split();
        //_Format();
        _Verbatim();
    }

    public static void _Reverse() {
        string line = "bss9395@github.com";
        for (int i = line.Length - 1; 0 <= i; i -= 1) {
            Console.Write(line[i]);
        }
        Console.WriteLine();
    }
    public static void _Replace() {
        string line = "bss9395@github.com";
        string account = line.Replace(".com", ".org");
        Console.WriteLine("{0}", account);
    }
    public static void _SubString() {
        string line = "bss9395@github.com";
        int idx = line.IndexOf("@");
        if (idx != -1) {
            string username = line.Substring(0, idx);
            Console.WriteLine("{0}", username);
        }
    }
    public static void _Insert() {
        string line = "bss9395@github.com";
        int idx = line.IndexOf("@");
        if (idx != -1) {
            string credential = line.Insert(idx, ":none");
            Console.WriteLine("{0}", credential);
        }
    }
    public static void _Split() {
        string line = "bss.9395@GitHub.com";
        string[] sepas = { "." };
        string[] words = line.Split(sepas, StringSplitOptions.None);  // note: just to split, no more operations.
        foreach (string word in words) {
            Console.WriteLine("{0}", word);
        }
    }
    public static void _Format() {
        Console.WriteLine(string.Format("{0:00.00}", 2));   // note: $02.00
        Console.WriteLine(string.Format("{0:##.##}", 2));   // note: 2
        Console.WriteLine(string.Format("{0:C}", 2));       // note: ￥2.00, $2.00
        Console.WriteLine(string.Format("{0:E}", 2.3));     // note: 2.300000E+000
        Console.WriteLine(string.Format("{0:N}", 250000));  // note: 250,000.00
        Console.WriteLine(string.Format("{0:X}", 1234));    // note: 4D2
        Console.WriteLine(string.Format("{0:P}", 0.24583)); // note: 24.58%
    }
    public static void _Verbatim() {
        string verbatim = @"C:\Users\Public\Desktop\";
        Console.WriteLine("{0}", verbatim);
    }

}
