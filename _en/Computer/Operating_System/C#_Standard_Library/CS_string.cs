/* CS_string.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Keyword: string
*/

using System;

class CS_string {
    public static void Main(string[] args) {
        //_Reverse();
        //_Replace();
        //_SubString();
        //_Insert();
        _Split();
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
}
