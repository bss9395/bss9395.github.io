/* CS_File.cs
Author: BSS9395
Update: 2022-04-26T20:42:00+08@China-Shanghai+08
Design: C# Standard Library: File
*/
using System;
using System.IO;

class CS_File {
    public static void Main(string[] args) {
        const string path = "E:/temp/code.txt";
        const string move = "E:/tmp/code.txt";
        _File(path, move);
    }
    public static void _File(string path, string move) {
        if (File.Exists(path) == false) {
            new FileInfo(path).Directory.Create();
            File.Create(path).Flush();
        }

        Console.WriteLine("CreationTime = {0}", File.GetCreationTime(path));
        Console.WriteLine("LastWriteTime = {0}", File.GetLastWriteTime(path));
        Console.WriteLine("LastAccessTime = {0}", File.GetLastAccessTime(path));

        if (File.Exists(move) == true) {
            File.Delete(move);
        } else {
            new FileInfo(move).Directory.Create();
        }
        File.Move(path, move);

        //System.GC.Collect();  // note: this is of no use.
    }
}

