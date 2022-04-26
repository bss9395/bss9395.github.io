/* CS_Path.cs
Author: BSS9395
Update: 2022-04-25T20:07:00+08@China-Shanghai+08
Design: C# Standard Library: Path
*/

using System;
using System.IO;

class CS_Path {
    public static void Main(string[] args) {
        const string path = "E:/temp/code.txt";
        _Path(path);
        _ChangeExtension(path);
        _GetInvalid_();
    }
    public static void _Path(string path) {
        Console.WriteLine("========================================");
        Console.WriteLine("InvalidPathChars = {0}", Path.GetInvalidPathChars());
        Console.WriteLine("FileNameWithoutExtension = {0}", Path.GetFileNameWithoutExtension(path));
        Console.WriteLine("Extension = {0}", Path.GetExtension(path));
        Console.WriteLine("FileName = {0}", Path.GetFileName(path));
        Console.WriteLine("DirectoryName = {0}", Path.GetDirectoryName(path));
    }
    public static void _ChangeExtension(string path) {
        string change = Path.ChangeExtension(path, "md");
        _Path(change);
    }
    public static void _GetInvalid_() {
        Console.WriteLine("\n========================================");
        foreach (char ch in Path.GetInvalidFileNameChars()) {
            Console.Write("{0}={1} ", ch, (int)ch);
        }
        Console.WriteLine("\n========================================");
        foreach (char ch in Path.GetInvalidPathChars()) {
            Console.Write("{0}={1} ", ch, (int)ch);
        }
    }
}
